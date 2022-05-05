
#ifndef HTTP_CONNECTION_H
#define HTTP_CONNECTION_H

#include <QObject>
#include <QTimer>
#include <QHash>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QJsonDocument>

#include "http_parser.h"
struct ReplyJson
{
    QString keyId="";               //唯一识别号 由Lims 创建并绑定
    QString taskType="";            //任务类型

    int status=-1;                  //任务状态  status=0-成功    其他失败
    QString errorMsg="非法值错误";   //异常原因拦截详细信息
    QStringList datalist;
    QJsonObject ReplyJson;         //数据包

};

class QTcpSocket;
class HttpRequest;
class HttpResponse;

typedef QHash<QString, QString> HeaderHash;

class HttpConnection : public QObject
{
    Q_OBJECT

public:
    HttpConnection(QTcpSocket *socket, QObject *parent = 0);
    virtual ~HttpConnection();

    void write(const QByteArray &data);
    void flush();

    QTimer *StTimer;
    int stTimercount=-1;
    ReplyJson ReplyJsonI;
    QByteArray ReplyData_POST;
    ReplyJson ReplyJson_action(QByteArray ReplyData,QString taskType);

signals:
    void newRequest(HttpRequest*, HttpResponse*);
    void newReplyData_task(QString ClientIP,ReplyJson ReplyJsonI,QJsonObject ReplyJson);    //任务监听接口

private slots:
    void parseRequest();
    void responseDone();

    void ON_HttpConnectionTimer();

public:
    static int MessageBegin(http_parser *parser);
    static int Path(http_parser *parser, const char *at, size_t length);
    static int QueryString(http_parser *parser, const char *at, size_t length);
    static int Url(http_parser *parser, const char *at, size_t length);
    static int Fragment(http_parser *parser, const char *at, size_t length);
    static int HeaderField(http_parser *parser, const char *at, size_t length);
    static int HeaderValue(http_parser *parser, const char *at, size_t length);
    static int HeadersComplete(http_parser *parser);
    static int Body(http_parser *parser, const char *at, size_t length);
    static int MessageComplete(http_parser *parser);

public:
    QTcpSocket *m_socket;
    http_parser_settings m_parserSettings;
    http_parser *m_parser;

    //以为每次都只有一个连接，即使是通道连接
    HttpRequest *m_request;

    // 我们将从parser中读出这些信息
    HeaderHash m_currentHeaders;
    QString m_currentHeaderField;
    QString m_currentHeaderValue;
};

#endif
