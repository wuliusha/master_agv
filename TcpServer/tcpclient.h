#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QNetworkProxy>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTime>
#include<QJsonObject>
#include<QJsonArray>
#include<QUrl>
#include<QJsonDocument>

#include "Device/array_single.h"
#include "TcpServer/transformarray.h"

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
    ~TcpClient();

    quint16 Serverport=10000;
    QString TcpServerIP="";

    QByteArray deviceQueryArray;
    QMap<QString,QByteArray>AnalysisArrayMap;       //设备客户端返回 数据 待处理缓存链表
    QMap<QByteArray,QByteArray>deviceActionArray;   //设备动作指令 缓存链表

    QByteArray getActionArray(QString taskType);
    void setTcpServer_deviceAction(QString deviceIP,QByteArray ActionArray);   //设置客户端动作指令信息

    /** 连接
     * @brief connectHost - 与主机建立连接
     * @param ip - IP地址
     * @param port - API对应的端口号
     * @return
     */
    int connectHost(const QString &ip, quint16 port);
    QTcpSocket *tcpSocket() const;  //@brief tcpSocket - 获取tcpSocket   @return

    /**
     * @brief releaseTcpSocket - 释放tcpSocket
     */
    void releaseTcpSocket();

signals:
    void sigLiftStatuschage(QString DeviceIP,QByteArray ActionArray);      //实时更新电梯状态信息

public slots:

    /**
     * @brief SCTcpToolWidget::stateChanged - tcp槽，实时监测tcp状态
     * @param state - socket的当前状态
     */
    void stateChanged(QAbstractSocket::SocketState state);

    /**
     * @brief receiveTcpReadyRead - 读取所有接受到的数据
     */
    void receiveTcpReadyRead();

public:
    /**
     * @brief 处理TCP返回数据
     * @param descriptor -套接字描述符
     */
    void TcpServerProcessing(QByteArray AnalysisArray,qintptr descriptor); //


    QString getCurrentDateTime() const;       //获取当前时间

signals:
    void sigclose();

    void sigonline(int online);

public slots:
   void ON_SendTimer();

private:

    QTimer *ClientTimer;
    int tcpSocketcount=0;
    int tcpSocketcount_Init=0;
    bool tcpSocket_bool=false;
    int ClosingStatecount=0;    //重连 n 次，退出系统


    QTcpSocket *_tcpSocket = Q_NULLPTR;
    QString _lastError;
    QString _ip;                //ip
    quint16 _port;              //端口号
    uint16_t _number;           //序号

    QTime _time;                //用来监测时间
    int _timeOut = -1;          //_timeOut = 0表示不监听超时
};

#endif // TCPCLIENT_H
