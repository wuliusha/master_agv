#ifndef AGVSERVER_H
#define AGVSERVER_H


#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include "tcpsocket.h"
#include "iconhelper/iconhelper.h"
#include "sqlConnect/sqlconnectionpool.h"

struct ClientSocket{
    QString ClientIP="";
    QTcpSocket *_tcpSocket = Q_NULLPTR;
};

struct ClientSend{
    QString ClientIP="";
    QList<QByteArray>SendArrayList;//当前需要发送
};

class AGVServer : public QTcpServer
{
    Q_OBJECT
public:
    AGVServer();
    ~AGVServer();
public:
    QTimer *SendTimer;
    QByteArray Box_ByteArray;
    QList<ClientSocket> ClientSocketList;//客户端连接链表

    QList<ClientSend>ClientSendList;//当前需要发送
    QList<AgvState>AgvStateList;    //AGV 信息链表

    bool SetClientSend(QString DeviceIP,QByteArray SendArray);
    bool SetWrite(QString DeviceIP,QByteArray SendArray);

public slots:
    void ON_DeviceTimer();

public slots:
    void ReceiveData();              //处理readyRead信号读取数据
    void _Disconnected();       //客户端断开连接触发disconnected信号，这个槽函数用来处理这个信号

signals:
    void ReDeviceArray(QString DeviceIP, QByteArray Array);

protected:    //函数重载    //获取新的Socket连接
    void incomingConnection(int socketDescriptor);
    QByteArray JsonToArray(AgvState agvState0);//把AGV 状态信息 转化为 QByteArray


};

#endif // AGVSERVER_H
