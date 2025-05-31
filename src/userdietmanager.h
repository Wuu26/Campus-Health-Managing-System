//用户饮食管理类的头文件，用于声明用户信息保存、读取和饮食推荐的函数。
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
