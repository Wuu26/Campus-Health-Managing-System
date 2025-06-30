#ifndef AISERVICE_H
#define AISERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStringList>
#include <QJsonObject>

class AIService : public QObject {
    Q_OBJECT
public:
    explicit AIService(QObject *parent = nullptr);
    void generatePlan(float bmi, int exerciseTime, const QString &userInfo);

signals:
    void planGenerated(const QStringList &plan);
    void errorOccurred(const QString &msg);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    const QString apiUrl = "https://api.deepseek.com/v1/chat/completions";
    const QString apiKey = "sk-5de803813ecd478595557085dd2c7cf6"; // 直接硬编码API密钥
};

#endif // AISERVICE_H
