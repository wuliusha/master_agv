#ifndef ROBOTSTATUSTCP_H
#define ROBOTSTATUSTCP_H

#include <QTcpSocket>
#include <QObject>
#include <QTime>
#include "SCHeadData.h"
#include "sqlConnect/sqlconnectionpool.h"


class RobotStatusTcp : public QObject
{
    Q_OBJECT
        ~RobotStatusTcp();
public:
    explicit RobotStatusTcp(QObject *parent = nullptr);
    QByteArray Recv_AllData;
    RoboshopState RoboshopStateItem;    //Roboshop 当前状态信息

    /**
     * @brief releaseTcpSocket - 释放tcpSocket
     */
    void releaseTcpSocket();

    /**
     * @brief writeTcpData - 发送TCP请求
     * @param sendCommand - 报文类型
     * @param sendData - 数据区数据
     * @param number - 序号
     * @return
     */
    bool writeTcpData(uint16_t sendCommand,
                      const QByteArray &sendData,
                      uint16_t &number);

    /**
     * @brief tcpSocket - 获取tcpSocket
     * @return
     */
    QTcpSocket *tcpSocket() const;


    /** 连接
     * @brief connectHost - 与主机建立连接
     * @param ip - IP地址
     * @param port - API对应的端口号
     * @return
     */
    int connectHost(const QString &ip, quint16 port);

    /**
     * @brief RobotStatusTcp::getCurrentDateTime - 获取当前时间
     * @return
     */
    QString getCurrentDateTime() const;

    /**
     * @brief RobotStatusTcp::hexToQString - 16进制转字符串，16进制全部显示大写
     * @param b
     * @return
     */
    QString hexToQString(const QByteArray &b);


public slots:
    /**
     * @brief receiveTcpReadyRead - 读取所有接受到的数据
     */
    void receiveTcpReadyRead();

signals:

    /**
     * @brief sigPrintInfo - 以信号的方式输出要打印的信息
     */
    void sigPrintInfo(QString);

    /**
     * @brief sigChangedText - 以信号的方式输出返回信息
     */
    void sigChangedText(bool ,int ,QByteArray ,QByteArray ,int ,int );

    void returnwriteTcpData(QByteArray writeData);
    void Roboshop_ret_code(QByteArray RecvData);//控制指令数据返回

public:
    QString _ip; //ip
    quint16 _port; //端口号
private:
    QTcpSocket *_tcpSocket = Q_NULLPTR;

};

#endif // ROBOTSTATUSTCP_H
