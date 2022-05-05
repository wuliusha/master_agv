
#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <QObject>
#include <QHash>
#include <QJsonObject>
#include <QJsonDocument>

//该类只能由HttpConnection创建
class QTcpSocket;
class HttpConnection;

typedef QHash<QString, QString> HeaderHash;


class HttpResponse : public QObject
{
    Q_OBJECT

public:
    virtual ~HttpResponse();

public slots:
    void write(const QByteArray &data);
    void write(const QString &data);
    void end(const QString &data = QString());
	void end(const QByteArray& data);

    void jswrite(const QJsonArray &data);
    void jsend(const QJsonArray& data);

    void jswrite_(QJsonObject postJson);
    void jsend_(QJsonObject postJson);

    void setHeader(const QString &field, const QString &value);
	bool setHeaderContentType(const QString& fileSuffix);
	void setStatus(int status);
signals:
    void done();

private:
    HttpResponse(HttpConnection *connection);

    void writeHead();
    void writeHeaders();
    void writeHeader(const char *field, const QString &value);
	void initContentType();
private:
    HttpConnection *m_connection;
	HeaderHash m_headers;
	HeaderHash m_contentTypes;
	int status;
    bool m_headerWritten;
    bool m_sentConnectionHeader;
    bool m_sentContentLengthHeader;
    bool m_sentTransferEncodingHeader;
    bool m_sentDate;
    bool m_keepAlive;
    bool m_last;
    bool m_useChunkedEncoding;

	friend class HttpConnection;
};

#endif
