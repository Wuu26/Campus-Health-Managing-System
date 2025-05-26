#include "interfaces.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QCoreApplication>

QStringList generateWorkoutPlan(const UserProfile &user) {
    float bmi = user.calculateBMI();
    QStringList plans;

    if (bmi < 18.5) {
        plans << "建议进行力量训练（如哑铃、俯卧撑）"
               << "每天摄入高蛋白食物（如鸡蛋、豆腐）";
    } else if (bmi < 24) {
        plans << "建议快走、骑行等中等强度有氧运动"
               << "保持良好的作息和营养均衡";
    } else if (bmi < 28) {
        plans << "建议慢跑、有氧操，控制饮食"
               << "减少高热量、高糖分食物摄入";
    } else {
        plans << "建议快走 30 分钟/天"
               << "避免高脂食物，多饮水";
    }

    return plans;
}

QStringList generateMealPlan(const UserProfile &user) {
    QStringList meals;

    if (user.dietType == "素食") {
        meals << "豆腐炒青菜 + 粗粮饭"
               << "水果沙拉 + 杂粮粥";
    } else {
        meals << "鸡胸肉 + 西兰花 + 藜麦"
               << "牛肉炖土豆 + 青菜";
    }

    return meals;
}

bool saveUserProfileToJson(const UserProfile &user, const QString &directory) {
    QString fullPath = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/" + directory + "/" + user.studentId + ".json");
    QDir().mkpath(QFileInfo(fullPath).absolutePath());

    QFile file(fullPath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "保存失败，文件无法打开：" << file.errorString();
        return false;
    }

    QJsonObject obj;
    obj["name"] = user.name;
    obj["studentId"] = user.studentId;
    obj["age"] = user.age;
    obj["height"] = user.height;
    obj["weight"] = user.weight;
    obj["goal"] = user.goal;
    obj["dietType"] = user.dietType;

    QJsonArray freeTimes;
    for (const QString &time : user.freeTimes)
        freeTimes.append(time);
    obj["freeTimes"] = freeTimes;

    QJsonDocument doc(obj);
    file.write(doc.toJson());
    file.close();
    return true;
}

bool loadUserProfileFromJson(UserProfile &user, const QString &directory) {
    QFile file(directory + "/" + user.studentId + ".json");
    if (!file.exists()) return false;
    if (!file.open(QIODevice::ReadOnly)) return false;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject()) return false;
    QJsonObject obj = doc.object();

    user.name = obj["name"].toString();
    user.studentId = obj["studentId"].toString();
    user.age = obj["age"].toInt();
    user.height = obj["height"].toDouble();
    user.weight = obj["weight"].toDouble();
    user.goal = obj["goal"].toString();
    user.dietType = obj["dietType"].toString();

    user.freeTimes.clear();
    QJsonArray times = obj["freeTimes"].toArray();
    for (const auto &val : times)
        user.freeTimes.append(val.toString());

    return true;
}