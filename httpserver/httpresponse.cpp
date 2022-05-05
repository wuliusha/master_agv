

#include "httpserver.h"
#include "httpresponse.h"
#include "httpconnection.h"

#include <QDateTime>

HttpResponse::HttpResponse(HttpConnection *connection)
    // TODO: parent child relation
    : QObject(0)
    , m_connection(connection)
    , m_headerWritten(false)
    , m_sentConnectionHeader(false)
    , m_sentContentLengthHeader(false)
    , m_sentTransferEncodingHeader(false)
    , m_sentDate(false)
    , m_keepAlive(true)
    , m_last(false)
    , m_useChunkedEncoding(false)
	, status(500)
{
	initContentType();
}

HttpResponse::~HttpResponse()
{
}

void HttpResponse::setHeader(const QString &field, const QString &value)
{
    m_headers[field] = value;
}

bool HttpResponse::setHeaderContentType(const QString& fileSufix)
{
	QString strType = m_contentTypes.value(fileSufix, "");

	if (strType.isNull() || strType.isEmpty())
	{
		return false;
	}

	m_headers["Content-Type"] = strType;

	return true;
}


void HttpResponse::initContentType()
{
	#define CONTENT_TYPE(fileSufix, contentType) m_contentTypes.insert(fileSufix, contentType);

	CONTENT_TYPE("."    , "text/plain")
	CONTENT_TYPE(".txt" , "text/plain")
	CONTENT_TYPE(".html", "text/html; charset=utf-8")
	CONTENT_TYPE(".htm" , "text/html; charset=utf-8")
	CONTENT_TYPE(".css" , "text/css; charset=utf-8")
	CONTENT_TYPE(".js"  , "application/x-javascript; charset=utf-8")
	CONTENT_TYPE(".xml" , "text/xml")
	CONTENT_TYPE(".xsl" , "text/xml")
	CONTENT_TYPE(".jpg" , "image/jpeg")
	CONTENT_TYPE(".png" , "image/png")
	CONTENT_TYPE(".jpeg", "image/jpeg")
	CONTENT_TYPE(".bmp" , "image/bmp")
	CONTENT_TYPE(".gif" , "image/gif")
	CONTENT_TYPE(".tiff", "image/tiff")
	CONTENT_TYPE(".zip" , "application/zip") 
	CONTENT_TYPE(".pdf" , "application/pdf")
	CONTENT_TYPE(".doc" , "application/msword")
	CONTENT_TYPE(".xls" , "application/vnd.ms-excel")
	CONTENT_TYPE(".ppt" , "application/vnd.ms-powerpoint")
	CONTENT_TYPE(".swf" , "application/x-shockwave-flash");
	CONTENT_TYPE(".wav" , "audio/x-wav")
	CONTENT_TYPE(".avi" , "video/x-msvideo")
}

void HttpResponse::writeHeader(const char *field, const QString &value)
{
    m_connection->write(field);
    m_connection->write(": ");
    m_connection->write(value.toUtf8());
    m_connection->write("\r\n");
}

void HttpResponse::writeHeaders()
{
    foreach(QString name, m_headers.keys())
    {
        QString value = m_headers[name];
        if( name.compare("connection", Qt::CaseInsensitive) == 0 ) 
        {
            m_sentConnectionHeader = true;
            if( value == "close" )
                m_last = true;
            else
                m_keepAlive = true;
        }
        else if( name.compare("transfer-encoding", Qt::CaseInsensitive) == 0 )
        {
            m_sentTransferEncodingHeader = true;
            if( value == "chunked" )
                m_useChunkedEncoding = true;
        }
        else if( name.compare("content-length", Qt::CaseInsensitive) == 0 )
        {
            m_sentContentLengthHeader = true;
        }
        else if( name.compare("date", Qt::CaseInsensitive) == 0 )
        {
            m_sentDate = true;
        }
        //TODO:处理异常情况

        writeHeader(name.toLatin1(), value.toLatin1());
    }

    if( !m_sentConnectionHeader )
    {
        if( m_keepAlive &&
                ( m_sentContentLengthHeader || m_useChunkedEncoding ) )
        {
            writeHeader("Connection", "keep-alive");
        }
        else
        {
            m_last = true;
            writeHeader("Connection", "close");
        }
    }

    if( !m_sentContentLengthHeader && !m_sentTransferEncodingHeader )
    {
        if( m_useChunkedEncoding )
            writeHeader("Transfer-Encoding", "chunked");
        else
            m_last = true;
    }

    if( !m_sentDate )
    {
		QString strFormat = "ddd, dd MMM yyyy hh:mm:ss G'M'T";
		QLocale loc = QLocale(QLocale::English, QLocale::UnitedStates);
		QDateTime curTime = QDateTime::currentDateTimeUtc();
		strFormat = loc.toString(curTime, strFormat);
		writeHeader("Date", strFormat);
    }
}

void HttpResponse::setStatus(int status)
{
	this->status = status;
}

void HttpResponse::writeHead()
{
    if( m_headerWritten ) return;

    m_connection->write(QString("HTTP/1.1 %1 %2\r\n").arg(status).arg(STATUS_CODES[status]).toLatin1());
    
    writeHeaders();

    m_connection->write("\r\n");
    m_headerWritten = true;
}

void HttpResponse::write(const QByteArray &data)
{
    if( !m_headerWritten )
    {
        qDebug() << "在写正文的之前，你必须先调用writeHead() ";
        return;
    }

    m_connection->write(data);
}

void HttpResponse::write(const QString &data)
{
	if( !m_headerWritten )
	{
		qDebug() << "在写正文的之前，你必须先调用writeHead() ";
		return;
	}
    m_connection->write(data.toLocal8Bit());
}

void HttpResponse::end(const QString &data)
{
    /*write(data);
    emit done();
    deleteLater();*/
    end(data.toLatin1());
}

void HttpResponse::end(const QByteArray& data)
{
	if (!data.isEmpty())
	{
		setHeader("Content-Length", QString("%1").arg(data.length()));
	}
	writeHead();
	if (!data.isEmpty())
	{
		write(data);
	}
	emit done();
    deleteLater();
}

void HttpResponse::jswrite(const QJsonArray &data)
{
    if( !m_headerWritten )
    {
        qDebug() << "在写正文的之前，你必须先调用writeHead() ";
        return;
    }
    // QJsonArray转换成QByteArray
    QJsonDocument document=QJsonDocument(data);
    QByteArray byte_array = document.toJson();

    m_connection->write(byte_array);
}

void HttpResponse::jsend(const QJsonArray &data)
{
    QJsonDocument document=QJsonDocument(data);
    QByteArray byte_array = document.toJson();
    if (!data.isEmpty())
    {
        setHeader("Content-Length", QString("%1").arg(byte_array.length()));
    }
    writeHead();
    if (!data.isEmpty())
    {
        jswrite(data);
    }
    emit done();
    deleteLater();
}

void HttpResponse::jswrite_(QJsonObject postJson)
{
    if(!m_headerWritten ){
        qDebug() << "在写正文的之前，你必须先调用writeHead() ";
        return;
    }
    QJsonDocument document;
    document.setObject(postJson);
    QByteArray byte_array = document.toJson();

    m_connection->write(byte_array);
}

void HttpResponse::jsend_(QJsonObject postJson)
{
    QJsonDocument document;
    document.setObject(postJson);
    QByteArray byte_array = document.toJson();
    if (!byte_array.isEmpty()){
        setHeader("Content-Length", QString("%1").arg(byte_array.length()));
    }
    writeHead();
    if (!byte_array.isEmpty()){
        jswrite_(postJson);
    }
    emit done();
    deleteLater();
}
