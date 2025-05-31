#include "datamanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

bool DataManager::saveDataToJson(const QJsonObject &data, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QJsonDocument doc(data);
    file.write(doc.toJson());
    file.close();
    return true;
}

QJsonObject DataManager::loadDataFromJson(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonObject();
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    return doc.object();
}
