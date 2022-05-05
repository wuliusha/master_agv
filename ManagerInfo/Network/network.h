#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonObject>
#include<QJsonArray>
#include<QUrl>
#include<QJsonDocument>
#include<QMap>
#include <QMutex>

struct WebServiceI
{
    QString UserBadge="";//员工工号
    QString ActionType="";//ActionType:动作类型
    QJsonObject RequestJson;//请求数据
    QNetworkReply *NetworkRepItiem;

};

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);

public:
    static Network* getInstance();

signals:
    void ReplyWebService(QJsonObject RequestJson, QJsonObject ReplyJson,QString UserBadge,QString ActionType);
    void ReplyError(QString Errorinfo);

public slots:
    //读取服务器回复
    void ReadResponse(QNetworkReply *Reply);

    //UrlPath :地址信息   JsonGet:以json格式提交数据   UserBadge:员工工号   ActionType:动作类型
    void ON_WebService_get(QString UrlPath,QJsonObject JsonGet,QString UserBadge,QString ActionType);

    //UrlPath :地址信息   JsonPost:以json格式提交数据   UserBadge:员工工号   ActionType:动作类型
    void ON_WebService_post(QString UrlPath,QJsonObject JsonPost,QString UserBadge,QString ActionType);

private:
    QNetworkAccessManager NetworkMgr;
    QList<WebServiceI> WebServiceItiemList;

    static QMutex mutex;
    static Network* instance;

};

#endif // NETWORK_H
