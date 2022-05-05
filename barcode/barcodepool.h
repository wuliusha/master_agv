#ifndef barcodePOOL_H
#define barcodePOOL_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QTimer>
#include "tcpsocket.h"
#include "tcpsocket.h"
#include "sqlConnect/sqlconnectionpool.h"

//struct DeviceArray
//{
//    QString DeviceIP;//设备IP
//    QByteArray Query_ByteArray;
//    QList<QByteArray>Send_ByteArrayList;//当前需要发送
//};


class barcodePool : public QTcpServer
{
    Q_OBJECT

public:
    barcodePool();

    ~barcodePool();
public:
    QTimer *SendTimer;
    QByteArray Box_ByteArray;
    QList<QTcpSocket *> TcpSocketList;

    QList<DeviceArray>DeviceArrayList;//当前需要发送

    void ON_SendTimer();
    void DeviceInit(QString DeviceIP);
    QByteArray Box_ByteArrayInit();
    QByteArray Get_CurrentArray(QString DeviceIP);
    QByteArray Get_JsonByteArray(QByteArray AnalysisArray);


protected:    //函数重载    //获取新的Socket连接
    void incomingConnection(qintptr Descriptor);

protected slots:
    void Scoket_Data_Processing(QByteArray AnalysisArray,int descriptor);            //处理数据
    void Socket_Disconnected(int descriptor);                                //断开连接处理

public slots:
    void ReceiveData_slot();            //处理readyRead信号读取数据
    void ClientDisconnected_slot();     //客户端断开连接触发disconnected信号，这个槽函数用来处理这个信号
    void ON_ChargeIP_TCP(QString ChargeIP,  QByteArray Query_ByteArray);//发送 TCP 数据

signals:
    void barcodeTask(QString StartTP,QString StartCP, QString EndTP,QString EndCP,QString CageID,QString ActionID,QString DeviceId);
    void controlBox(QString IP,QByteArray BoxByteArray);
    void AGVChargeStatus(QString IP,QByteArray BoxByteArray);//实时更新 充电桩 状态

};

#endif // barcodePOOL_H
