#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QJsonObject>

class DataManager
{
public:
    static bool saveDataToJson(const QJsonObject &data, const QString &filePath);
    static QJsonObject loadDataFromJson(const QString &filePath);
};

#endif // DATAMANAGER_H
