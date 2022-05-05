#ifndef AGVCARSOCKET_H
#define AGVCARSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class agvCarSocket : public QTcpSocket
{
    Q_OBJECT
public:
    agvCarSocket();

    ~agvCarSocket();
};

#endif // AGVCARSOCKET_H
