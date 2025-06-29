#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "interfaces.h"

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

private:
    Ui::MainWindow *ui;
    UserProfile currentUser;
};

#endif // MAINWINDOW_H
