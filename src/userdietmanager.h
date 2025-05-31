#ifndef USERDIETMANAGER_H
#define USERDIETMANAGER_H

#include <QString>
#include <QJsonObject>

class UserDietManager
{
public:
    static bool saveUserInfo(const QString &studentId, const QJsonObject &userInfo);
    static QJsonObject loadUserInfo(const QString &studentId);
    static QStringList generateDietRecommendation(const QJsonObject &userInfo);
};

#endif // USERDIETMANAGER_H
