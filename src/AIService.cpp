#include "AIService.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

AIService::AIService(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
}

void AIService::generatePlan(float bmi, int exerciseTime, const QString &userInfo) {
    // 构建提示词 - 明确要求分两部分输出
    QString prompt = QString(
                         "用户BMI: %1，每周锻炼时间: %2分钟，额外信息: %3\n\n"
                         "请生成个性化健康计划，包含以下两部分内容：\n"
                         "1. 【运动计划】根据用户BMI和空闲时间，设计合理的运动方案（包含运动类型、频率、时长）\n"
                         "2. 【饮食建议】根据用户目标和饮食偏好，提供营养建议（包含三餐示例）\n\n"
                         "输出格式要求：\n"
                         "首先明确标注'【运动计划】'，然后是运动内容\n"
                         "然后明确标注'【饮食建议】'，然后是饮食内容\n"
                         "每部分内容请分点说明，使用中文。")
                         .arg(bmi).arg(exerciseTime).arg(userInfo);

    // ... 其余代码保持不变 ...

    // 构建请求体
    QJsonObject requestBody;
    requestBody["model"] = "deepseek-chat";
    requestBody["messages"] = QJsonArray{
        QJsonObject{{"role", "user"}, {"content", prompt}}
    };
    requestBody["max_tokens"] = 1000;
    requestBody["temperature"] = 0.7;

    // 准备网络请求
    QNetworkRequest request{QUrl(apiUrl)};
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    // 发送请求
    QNetworkReply *reply = manager->post(request, QJsonDocument(requestBody).toJson());

    // 连接信号
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        this->onReplyFinished(reply);
    });
}

void AIService::onReplyFinished(QNetworkReply *reply) {
    // 确保reply被正确清理
    reply->deleteLater();

    // 处理网络错误
    if (reply->error() != QNetworkReply::NoError) {
        emit errorOccurred("网络错误: " + reply->errorString());
        return;
    }

    // 获取响应数据
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray responseData = reply->readAll();

    // 调试输出
    qDebug() << "HTTP状态码:" << statusCode;
    qDebug() << "API响应:" << responseData;

    // 解析JSON
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (doc.isNull()) {
        emit errorOccurred("响应解析失败: 无效的JSON格式");
        return;
    }

    QJsonObject json = doc.object();

    // 处理API错误
    if (statusCode >= 400) {
        QString errorMsg = QString("API错误 [%1]: ").arg(statusCode);
        if (json.contains("error") && json["error"].isObject()) {
            QJsonObject errorObj = json["error"].toObject();
            errorMsg += errorObj["message"].toString("未知错误");
        } else {
            errorMsg += QString::fromUtf8(responseData);
        }
        emit errorOccurred(errorMsg);
        return;
    }

    // 提取成功响应
    if (json.contains("choices") && json["choices"].isArray()) {
        QJsonArray choices = json["choices"].toArray();
        if (!choices.isEmpty()) {
            QJsonObject choice = choices.first().toObject();
            if (choice.contains("message") && choice["message"].isObject()) {
                QJsonObject message = choice["message"].toObject();
                QString content = message["content"].toString();
                emit planGenerated(content.split('\n', Qt::SkipEmptyParts));
                return;
            }
        }
    }

    // 未知响应格式
    emit errorOccurred("无法解析API响应: " + QString::fromUtf8(responseData));
}
