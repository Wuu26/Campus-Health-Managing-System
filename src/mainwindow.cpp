#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interfaces.h"
#include <QMessageBox>
#include <QDebug>              // 可选，用于调试

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 默认显示欢迎页（第一页）
    ui->stackedWidget->setCurrentIndex(0);

    // 连接按钮
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::on_submitButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_generateButton_clicked() {
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
    }

    ui->stackedWidget->setCurrentIndex(1); // 跳转到信息填写页
}

void MainWindow::on_submitButton_clicked() {
    currentUser.age = ui->ageInput->text().toInt();
    currentUser.height = ui->heightInput->text().toFloat();
    currentUser.weight = ui->weightInput->text().toFloat();
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

    auto workout = generateWorkoutPlan(currentUser);
    auto meals = generateMealPlan(currentUser);

    ui->workoutResult->setText(workout.join("\n"));
    ui->mealResult->setText(meals.join("\n"));

    ui->stackedWidget->setCurrentIndex(2); // 切换到结果页
}