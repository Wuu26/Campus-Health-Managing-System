#include "interfaces.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QStringList generateWorkoutPlan(const UserProfile &user)
{
    float bmi = user.calculateBMI();
    int exerciseTime = user.calculateExerciseTime();
    QStringList plans;

    if (bmi < 18.5) {
        if (exerciseTime < 120) {
            plans << "建议进行20分钟力量训练（如哑铃、俯卧撑）"
                  << "每天摄入高蛋白食物（如鸡蛋、豆腐）";
        } else if (exerciseTime < 240) {
            plans << "建议进行30分钟力量训练（如哑铃、俯卧撑）和10分钟有氧运动"
                  << "每天摄入高蛋白食物（如鸡蛋、豆腐）";
        } else {
            plans << "建议进行40分钟力量训练（如哑铃、俯卧撑）和20分钟有氧运动"
                  << "每天摄入高蛋白食物（如鸡蛋、豆腐）";
        }
    } else if (bmi < 24) {
        if (exerciseTime < 120) {
            plans << "建议快走20分钟"
                  << "保持良好的作息和营养均衡";
        } else if (exerciseTime < 240) {
            plans << "建议快走30分钟和骑行10分钟"
                  << "保持良好的作息和营养均衡";
        } else {
            plans << "建议快走40分钟和骑行20分钟"
                  << "保持良好的作息和营养均衡";
        }
    } else if (bmi < 28) {
        if (exerciseTime < 120) {
            plans << "建议慢跑20分钟，控制饮食"
                  << "减少高热量、高糖分食物摄入";
        } else if (exerciseTime < 240) {
            plans << "建议慢跑30分钟和有氧操10分钟，控制饮食"
                  << "减少高热量、高糖分食物摄入";
        } else {
            plans << "建议慢跑40分钟和有氧操20分钟，控制饮食"
                  << "减少高热量、高糖分食物摄入";
        }
    } else {
        if (exerciseTime < 120) {
            plans << "建议快走20分钟/天"
                  << "避免高脂食物，多饮水";
        } else if (exerciseTime < 240) {
            plans << "建议快走30分钟/天和简单拉伸10分钟"
                  << "避免高脂食物，多饮水";
        } else {
            plans << "建议快走40分钟/天和简单拉伸20分钟"
                  << "避免高脂食物，多饮水";
        }
    }

    return plans;
}

QStringList generateMealPlan(const UserProfile &user)
{
    float bmi = user.calculateBMI();
    int exerciseTime = user.calculateExerciseTime();
    QStringList meals;

    if (user.dietType == "素食") {
        if (exerciseTime < 120) {
            meals << "豆腐炒青菜 + 粗粮饭"
                  << "水果沙拉 + 杂粮粥";
        } else if (exerciseTime < 240) {
            meals << "豆腐炒青菜 + 粗粮饭，增加坚果摄入"
                  << "水果沙拉 + 杂粮粥，增加豆类摄入";
        } else {
            meals << "豆腐炒青菜 + 粗粮饭，增加坚果和豆类摄入"
                  << "水果沙拉 + 杂粮粥，增加蛋白质粉摄入";
        }
    } else {
        if (exerciseTime < 120) {
            meals << "鸡胸肉 + 西兰花 + 藜麦"
                  << "牛肉炖土豆 + 青菜";
        } else if (exerciseTime < 240) {
            meals << "鸡胸肉 + 西兰花 + 藜麦，增加鱼类摄入"
                  << "牛肉炖土豆 + 青菜，增加蛋类摄入";
        } else {
            meals << "鸡胸肉 + 西兰花 + 藜麦，增加鱼类和蛋类摄入"
                  << "牛肉炖土豆 + 青菜，增加蛋白质粉摄入";
        }
    }

    return meals;
}

bool saveUserProfileToJson(const UserProfile &user, const QString &directory)
{
    QString fullPath = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/" + directory
                                       + "/" + user.studentId + ".json");
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

bool loadUserProfileFromJson(UserProfile &user, const QString &directory)
{
    QFile file(directory + "/" + user.studentId + ".json");
    if (!file.exists())
        return false;
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isObject())
        return false;
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
