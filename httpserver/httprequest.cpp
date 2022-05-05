
#include "httprequest.h"

#include "httpconnection.h"

HttpRequest::HttpRequest(HttpConnection *connection, QObject *parent)
    : QObject(parent)
    , m_connection(connection)
    , m_url("http://localhost/")
{
}

HttpRequest::~HttpRequest()
{
}

