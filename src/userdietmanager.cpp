//用户饮食管理类的实现文件，用于实现具体的用户信息保存、读取和饮食推荐逻辑。
#include "userdietmanager.h"
#include "datamanager.h"
#include <QStringList>

bool UserDietManager::saveUserInfo(const QString &studentId, const QJsonObject &userInfo)
{
    QString filePath = "user_info/" + studentId + ".json";
    return DataManager::saveDataToJson(userInfo, filePath);
}

QJsonObject UserDietManager::loadUserInfo(const QString &studentId)
{
    QString filePath = "user_info/" + studentId + ".json";
    return DataManager::loadDataFromJson(filePath);
}

QStringList UserDietManager::generateDietRecommendation(const QJsonObject &userInfo)
{
    QStringList recommendations;
    // 根据用户信息生成饮食推荐
    // 这里只是示例，你可以根据实际需求修改
    if (userInfo["dietType"] == "素食") {
        recommendations << "豆腐炒青菜 + 粗粮饭"
                        << "水果沙拉 + 杂粮粥";
    } else {
        recommendations << "鸡胸肉 + 西兰花 + 藜麦"
                        << "牛肉炖土豆 + 青菜";
    }
    return recommendations;
}
