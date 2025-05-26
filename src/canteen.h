// canteen.h
#ifndef CANTEEN_H
#define CANTEEN_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QMap>

struct Dish {
    QString name;
    QString canteen;
};

QVector<Dish> loadDishesFromCSV(const QString &filePath, const QString &canteenName);

#endif // CANTEEN_H
