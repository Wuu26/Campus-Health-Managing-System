#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("智能校园健康管理系统");
    w.resize(800, 600);  // 可根据你的窗口调整
    w.show();

    return app.exec();
}