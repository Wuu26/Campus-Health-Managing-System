#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "interfaces.h"
#include "AIService.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();
    void on_submitButton_clicked();
    void onWorkoutPlanGenerated(const QStringList &plan); // 新增：AI 返回计划的槽函数
    void onErrorOccurred(const QString &errorMsg);       // 新增：AI 错误处理槽函数

private:
    Ui::MainWindow *ui;
    UserProfile currentUser;
    AIService *aiService; // 新增：AI 服务对象

    // 声明辅助函数
    int calculateTotalExerciseTime(const QStringList &freeTimes); // 新增声明
    QStringList generateWorkoutPlan(const UserProfile &user);
    QStringList generateMealPlan(const UserProfile &user);
};

#endif // MAINWINDOW_H
