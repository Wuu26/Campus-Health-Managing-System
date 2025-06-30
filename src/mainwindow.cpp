#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include "ui_mainwindow.h"
#include "AIService.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 清除输入框中的提示文本（如果有）
    ui->ageInput->setPlaceholderText("请输入年龄");
    ui->heightInput->setPlaceholderText("请输入身高(cm)");
    ui->weightInput->setPlaceholderText("请输入体重(kg)");
    ui->ageInput->clear();
    ui->heightInput->clear();
    ui->weightInput->clear();

    // 初始化 AI 服务
    aiService = new AIService(this);

    // 连接 AI 服务信号槽
    connect(aiService, &AIService::planGenerated, this, &MainWindow::onWorkoutPlanGenerated);
    connect(aiService, &AIService::errorOccurred, this, &MainWindow::onErrorOccurred);

    // 默认显示欢迎页（第一页）
    ui->stackedWidget->setCurrentIndex(0);

    // 连接按钮
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::on_submitButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{

    QString name = ui->nameInput->text();
    QString id = ui->idInput->text();

    if (name.isEmpty() || id.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入姓名和学号！");
        return;
    }

    currentUser.name = name;
    currentUser.studentId = id;

    // 试图从 data/ 文件夹加载之前保存的记录
    if (loadUserProfileFromJson(currentUser, "data")) {
        QMessageBox::information(this, "提示", "已载入上次保存的信息！");
        ui->ageInput->setText(QString::number(currentUser.age));
        ui->heightInput->setText(QString::number(currentUser.height));
        ui->weightInput->setText(QString::number(currentUser.weight));
        ui->goalCombo->setCurrentText(currentUser.goal);
        ui->dietCombo->setCurrentText(currentUser.dietType);

        // 设置 freeTimes
        for (int i = 0; i < ui->freeTimeList->count(); ++i) {
            QListWidgetItem *item = ui->freeTimeList->item(i);
            item->setSelected(currentUser.freeTimes.contains(item->text()));
        }
    } else {
        // 新用户，清除输入框内容
        ui->ageInput->clear();
        ui->heightInput->clear();
        ui->weightInput->clear();
        ui->goalCombo->setCurrentIndex(0);
        ui->dietCombo->setCurrentIndex(0);

        // 清除空闲时间选择
        for (int i = 0; i < ui->freeTimeList->count(); ++i) {
            ui->freeTimeList->item(i)->setSelected(false);
        }
    }

    ui->stackedWidget->setCurrentIndex(1); // 跳转到信息填写页
}

void MainWindow::on_submitButton_clicked()
{
    // 获取并清理年龄输入
    QString ageText = ui->ageInput->text().trimmed();
    // 移除所有非数字字符（如果有标签文本混入）
    ageText.remove(QRegularExpression("[^0-9]"));

    if (ageText.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "年龄不能为空");
        return;
    }

    bool ageOk;
    int age = ageText.toInt(&ageOk);
    if (!ageOk || age < 1 || age > 120) {
        QMessageBox::warning(this, "输入错误", "请输入有效的年龄（1-120岁）");
        return;
    }
    currentUser.age = age;

    // 获取并清理身高输入
    QString heightText = ui->heightInput->text().trimmed();
    // 移除非数字和小数点字符
    heightText.remove(QRegularExpression("[^0-9.,]"));
    heightText = heightText.replace(",", ".");

    if (heightText.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "身高不能为空");
        return;
    }

    // 处理可能的小数点格式问题
    heightText = heightText.replace(",", ".");
    bool heightOk;
    float height = heightText.toFloat(&heightOk);
    if (!heightOk || height < 30 || height > 250) {
        QMessageBox::warning(this, "输入错误", "请输入有效的身高（30-250厘米）");
        return;
    }
    currentUser.height = height;


    // 获取并清理体重输入
    QString weightText = ui->weightInput->text().trimmed();
    // 移除非数字和小数点字符
    weightText.remove(QRegularExpression("[^0-9.,]"));
    weightText = weightText.replace(",", ".");
    if (weightText.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "体重不能为空");
        return;
    }


    bool weightOk;
    float weight = weightText.toFloat(&weightOk);
    if (!weightOk || weight < 10 || weight > 300) {
        QMessageBox::warning(this, "输入错误", "请输入有效的体重（10-300公斤）");
        return;
    }
    currentUser.weight = weight;

    currentUser.goal = ui->goalCombo->currentText();
    currentUser.dietType = ui->dietCombo->currentText();

    currentUser.freeTimes.clear();
    for (int i = 0; i < ui->freeTimeList->count(); ++i) {
        if (ui->freeTimeList->item(i)->isSelected()) {
            currentUser.freeTimes.append(ui->freeTimeList->item(i)->text());
        }
    }

    // 保存用户数据到 JSON
    if (!saveUserProfileToJson(currentUser, "data")) {
        QMessageBox::warning(this, "保存失败", "无法保存用户信息！");
    }

    // 计算BMI和运动时间
    float bmi = currentUser.calculateBMI();
    int exerciseTime = calculateTotalExerciseTime(currentUser.freeTimes);

    // 构建 AI 请求的用户信息
    QString userInfo = QString(
                           "年龄: %1岁, 健身目标: %2, 饮食偏好: %3, 空闲时间: %4")
                           .arg(currentUser.age)
                           .arg(currentUser.goal)
                           .arg(currentUser.dietType)
                           .arg(currentUser.freeTimes.join("、"));

    // 调用 AI 生成计划（异步）
    aiService->generatePlan(bmi, exerciseTime, userInfo);

    // 显示加载状态
    ui->workoutResult->setText("正在生成个性化运动计划...");
    ui->mealResult->setText("正在生成个性化饮食计划...");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::onWorkoutPlanGenerated(const QStringList &plan)
{
    // 尝试解析运动计划和饮食计划
    QStringList workoutPlan;
    QStringList mealPlan;
    bool isWorkoutSection = true;

    // 改进的解析逻辑：根据关键词识别部分
    for (const QString &line : plan) {
        if (line.contains("饮食建议") || line.contains("营养计划") ||
            line.contains("饮食计划") || line.contains("餐食安排")) {
            isWorkoutSection = false;
        }

        if (isWorkoutSection) {
            workoutPlan.append(line);
        } else {
            mealPlan.append(line);
        }
    }

    // 如果解析失败，尝试按行数分割（前60%为运动，后40%为饮食）
    if (workoutPlan.isEmpty() || mealPlan.isEmpty()) {
        int splitIndex = plan.size() * 0.6;
        for (int i = 0; i < plan.size(); i++) {
            if (i < splitIndex) {
                workoutPlan.append(plan[i]);
            } else {
                mealPlan.append(plan[i]);
            }
        }
    }

    // 显示结果
    ui->workoutResult->setText(workoutPlan.join("\n"));
    ui->mealResult->setText(mealPlan.join("\n"));
}

void MainWindow::onErrorOccurred(const QString &errorMsg)
{
    // 处理 AI 调用错误
    QMessageBox::critical(this, "AI 服务错误", errorMsg);

    // 回退到本地算法
    auto workout = generateWorkoutPlan(currentUser);
    auto meals = generateMealPlan(currentUser);
    ui->workoutResult->setText(workout.join("\n"));
    ui->mealResult->setText(meals.join("\n"));
}

int MainWindow::calculateTotalExerciseTime(const QStringList &freeTimes)
{
    // 根据用户选择的空闲时间计算总锻炼时间（分钟）
    // 示例：假设每个时间段为30分钟
    return freeTimes.size() * 30;
}

QStringList MainWindow::generateWorkoutPlan(const UserProfile &user) {
    QStringList plan;
    plan << "本地生成的运动计划:";
    plan << "- 每周进行3次有氧运动（每次30分钟）";
    plan << "- 2次力量训练（针对大肌群）";
    plan << QString("- BMI=%1，建议适当控制饮食").arg(user.calculateBMI());
    return plan;
}

QStringList MainWindow::generateMealPlan(const UserProfile &user) {
    QStringList plan;
    plan << "本地生成的饮食建议:";
    plan << "- 早餐：鸡蛋、全麦面包、牛奶";
    plan << "- 午餐：鸡胸肉/鱼肉 + 蔬菜 + 糙米饭";
    plan << "- 晚餐：豆腐/瘦肉 + 绿叶蔬菜";
    return plan;
}
