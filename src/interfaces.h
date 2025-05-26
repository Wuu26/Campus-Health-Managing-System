#ifndef INTERFACES_H
#define INTERFACES_H

#include <QString>
#include <QStringList>

struct UserProfile {
    QString name;
    QString studentId;
    int age;
    float height;
    float weight;
    QString goal;
    QStringList freeTimes;
    QString dietType;

    float calculateBMI() const {
        if (height <= 0) return 0;
        float hMeters = height / 100.0f;
        return weight / (hMeters * hMeters);
    }
};

QStringList generateWorkoutPlan(const UserProfile &user);
QStringList generateMealPlan(const UserProfile &user);

bool saveUserProfileToJson(const UserProfile &user, const QString &directory);
bool loadUserProfileFromJson(UserProfile &user, const QString &directory);

#endif // INTERFACES_H