#ifndef STATIONITEM_H
#define STATIONITEM_H

#include <QWidget>
#include "array_single.h"
#include "taskmanager/ess_single.h"
#include "queryServer/thread/threadinsert.h"
#include "queryServer/thread/threadquery.h"
#include "wrexcelprocess/wrexcelprocess.h"
#include "TcpServer/udp_device.h"
#include "TcpServer/tcpserver.h"
#include "TcpServer/tcpclient.h"


namespace Ui {
class stationItem;
}

class stationItem : public QWidget
{
    Q_OBJECT

public:
    explicit stationItem(QWidget *parent = nullptr);
    ~stationItem();
    QTimer *stationTimer;
    bool TableWidgetbool=true;
    int TableWidgetcount=0;

    void stationItemInit();                 //接驳台站点初始化

    void stationSqlInit(QString type);      //接驳台站点数据库初始化

signals:


public slots:

    void ON_stationTimer();

    void SlotsetCurrentItem(int row, int column);

    void ON_stationItemStatus(QString DeviceIP,QByteArray ActionArray);         //实时检测 设备状态信息

    //DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void ON_DeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

    void ON_DeviceStatus(QString deviceDesc,SAPExcelInfo SAPExcelInfoI);

public:
    void TableWidget_show();                //显示当前电梯各个接驳台任务状态线信息
    QList<RW_Excel>TableWidget();           //显示当前电梯各个接驳台任务状态线信息

private slots:

    void on_load_clicked();

    void on_unload_clicked();

    void on_reset_clicked();

    void on_clearButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::stationItem *ui;

    QString deviceI_Ikey="";
    int deviceI_Ikeycount=0;

    deviceI currentStation;
    QMap<QString,QString>deviceIP_desc;

    bool stationbool=true;
    QMap<QString,deviceI>stationInfoMap;  //desc - deviceI

    Udp_Device *Udp_DeviceI;
    QThread *threadUdpItem;

    TcpServer *TcpServerI;
    QThread *threadTcpServertem;

    void UP_DeviceStatus(QMap<int,deviceI>StationInfoMap_);

    void UP_DeviceStatus_Timer(QMap<QString,deviceI>StationInfoMap_);    //实时更新接驳台 任务状态

    void UP_DeviceStatus_clear(deviceI deviceItem);

};

#endif // STATIONITEM_H
