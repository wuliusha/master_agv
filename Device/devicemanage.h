#ifndef DEVICEMANAGE_H
#define DEVICEMANAGE_H

#include <QWidget>
#include <QObject>
#include "stationitem.h"
#include "array_single.h"
#include "taskmanager/ess_single.h"
#include "queryServer/thread/threadinsert.h"
#include "queryServer/thread/threadquery.h"
#include "wrexcelprocess/wrexcelprocess.h"
#include "TcpServer/udp_device.h"
#include "TcpServer/tcpserver.h"
#include "TcpServer/tcpclient.h"


namespace Ui {
class DeviceManage;
}

class DeviceManage : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceManage(QWidget *parent = nullptr);
    ~DeviceManage();
    QTimer *DeviceTimer;
    stationItem *stationItemI;

    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

    void DeviceManageInit();

    void TableWidget_show();                                        //显示当前电梯各个接驳台任务状态线信息
    QList<RW_Excel>TableWidget(QMap<QString,LiftCode>LiftCodeMap);  //显示当前电梯各个接驳台任务状态线信息

    void setActionbtns(QString deviceType, int Action,QString Type,QString deviceDesc);

    bool LiftCodeStatus_clear(LiftCode LiftCodeItem);

    bool setLiftCodeMap_Status(QMap<QString,LiftCode>LiftCodeMap);                  //更新接升降机状态信息

public slots:

    void ON_DeviceTimer();

signals:
    //实时更新升降机状态信息  plc
    void sig_LiftTaskStatus(LiftTask LiftTaskI);

    void sig_LiftCodeStatus_clear(LiftCode LiftCodeItem);

public slots:

    void SlotsetCurrentItem(int row, int column);

    //设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void ON_DeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

    //获取升降机的动作及查询指令---单个
    void ON_setLiftactionArray(LiftTask LiftTaskI,int startFloor,int destFloor);

    void ON_LiftStatuschage(QString DeviceIP,QByteArray ActionArray);           //实时检测 升降机状态信息


    void ON_LiftCodeMap(QMap<QString,LiftCode>LiftCodeMap_);            //更新升降机各个接驳台状态信息

private slots:

    void on_Sure_Button_Lift_clicked();

    void on_clearButton_clicked();

private:
    Ui::DeviceManage *ui;
    LiftTask LiftTaskI;              //当前电梯任务状态
    QMap<QString,QString>LiftCodedesc;
    QList<QPushButton *>Actionbtns;

    int LiftCodeMapconut=0;
    LiftCode slectLiftCode;
    QMap<QString,LiftCode>LiftCodeMap;

    TcpClient *TcpClientI;
    QThread *threadTcpClientItem;

};

#endif // DEVICEMANAGE_H
