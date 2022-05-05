#ifndef DEVICEMANAGE_H
#define DEVICEMANAGE_H

#include <QWidget>
#include "deviceitem.h"
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
    LiftTask LiftTaskI;              //当前电梯任务状态

    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

    QMap<QString,DeviceItem*>DeviceItemMap_S;//站点接驳台
    QMap<QString,DeviceItem*>DeviceItemMap_D;//自动门控制

    void DeviceManageInit();

    void newDeviceItem_S();       //创建 新的站点接驳台 Item

    void newDeviceItem_D();       //创建 新的设备 Item

    void setLiftTaskInfo();       //创建 电梯 Item

    void setLayout_show(QWidget *LayoutWidget,QWidget *LayoutWidget_,QString deviceType,QMap<QString,DeviceItem*>DeviceItemMap);        //设置初始化布局

    void UPLayout_show(QMap<QString,DeviceItem*>DeviceItemMap,int page);        //更新显示

    void TableWidget_show();                                        //显示当前电梯各个接驳台任务状态线信息
    QList<RW_Excel>TableWidget(QMap<QString,LiftCode>LiftCodeMap);  //显示当前电梯各个接驳台任务状态线信息



public slots:

    void ON_DeviceTimer();

signals:
    //实时更新升降机状态信息  plc
    void sig_LiftTaskStatus(LiftTask LiftTaskI);

    //更新各设备状态信息  控制盒-接驳台类型
    void sigDeviceStatus_station(QString DeviceIP,int online,int DeviceStatus,controlbox controlboxI);

    //更新各设备状态信息  控制盒-自动门类型
    void sigDeviceStatus_door(QString DeviceIP,int online,int DeviceStatus,controlbox controlboxI);

    //更新各设备状态信息  控制盒-电梯类型
    void sigDeviceStatus_Lift(QString DeviceIP,int online,int DeviceStatus,controlbox controlboxI);

    //更新各设备状态信息  控制盒-充电桩类型
    void sigDeviceStatus_charge(QString DeviceIP,int online,int DeviceStatus,controlbox controlboxI);

public slots:

    void ON_Pressed();

    void ON_Released();

    void ON_ClickProcess();

    //设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void ON_DeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);

    //获取升降机的动作及查询指令---单个
    void ON_setLiftactionArray(LiftTask LiftTaskI,int startFloor,int destFloor);


    void ON_LiftStatuschage(QString DeviceIP,QByteArray ActionArray);           //实时检测 升降机状态信息

    void ON_DeviceStatuschage(QString DeviceIP,QByteArray ActionArray);         //实时检测 设备状态信息


private slots:

    void on_Sure_Button_Lift_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::DeviceManage *ui;
    QList<QPushButton *>Actionbtns;

    Udp_Device *Udp_DeviceI;
    QThread *threadUdpItem;

    TcpServer *TcpServerI;
    QThread *threadTcpServertem;

    TcpClient *TcpClientI;
    QThread *threadTcpClientItem;



};

#endif // DEVICEMANAGE_H
