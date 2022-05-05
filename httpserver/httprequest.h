
#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <QObject>
#include <QHash>
#include <QMetaType>
#include <QUrl>

class QTcpSocket;

class HttpConnection;

typedef QHash<QString, QString> HeaderHash;

class HttpRequest : public QObject
{
    Q_OBJECT

    Q_PROPERTY(HeaderHash headers    READ headers);
    Q_PROPERTY(QString remoteAddress READ remoteAddress);
    Q_PROPERTY(quint16 remotePort    READ remotePort);
    Q_PROPERTY(QString method        READ method);
    Q_PROPERTY(QUrl    url           READ url);
    Q_PROPERTY(QString path          READ path);
    Q_PROPERTY(QString httpVersion   READ httpVersion);

public:
    virtual ~HttpRequest();

	//客户端请求的命令
    const QString& method() const { return m_method; };

	//请求完整的URL的，包括查询语句
    const QUrl& url() const { return m_url; };

   //请求的路径，url的一部分
    const QString path() const { return m_url.path(); };

   //客户端http的版本
    const QString& httpVersion() const { return m_version; };

    // 查询字符串，通常用于Get 请求中的数据.
    const QString& queryString() const;

    const HeaderHash& headers() const { return m_headers; };

    QString header(const QString &field) { return m_headers[field]; };
	//客户端IP
    const QString& remoteAddress() const { return m_remoteAddress; };

   //客户端端口
    quint16 remotePort() const { return m_remotePort; };

signals:
	//正文数据  
    void data(const QByteArray &);
	//http请求结束
    void end();

private:
    HttpRequest(HttpConnection *connection, QObject *parent = 0);

    void setMethod(const QString &method) { m_method = method; }
    void setVersion(const QString &version) { m_version = version; }
    void setUrl(const QUrl &url) { m_url = url; }
    void setHeaders(const HeaderHash headers) { m_headers = headers; }

    HttpConnection *m_connection;
    HeaderHash m_headers;
    QString m_method;
    QUrl m_url;
    QString m_version;
    QString m_remoteAddress;
    quint16 m_remotePort;

    friend class HttpConnection;
};

#endif
