#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QWidget>
class TcpSocket : public QTcpSocket
{
public:
    TcpSocket();
    ~TcpSocket();
};

#endif // TCPSOCKET_H
