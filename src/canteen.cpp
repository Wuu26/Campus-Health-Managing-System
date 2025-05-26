// canteen.cpp
#include "canteen.h"
#include <QFile>
#include <QTextStream>

QVector<Dish> loadDishesFromCSV(const QString &filePath, const QString &canteenName) {
    QVector<Dish> dishes;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("无法打开文件：%s", qPrintable(file.errorString()));
        return dishes;
    }

    QTextStream in(&file);
    QString header = in.readLine(); // 跳过标题行
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            Dish dish;
            dish.name = line; // CSV中只有菜名
            dish.canteen = canteenName;
            dishes.append(dish);
        }
    }

    file.close();
    return dishes;
}
