#ifndef DEVICEITEM_H
#define DEVICEITEM_H

#include <QWidget>
#include<QPalette>
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"


struct deviceI
{
    int deviceId=0;                 //设备Id
    QString deviceIP="";            //设备IP
    QString deviceDesc="";          //设备名称
    QString deviceType="";          //设备类型  自动门 door  站点接驳台 Station

    int onLine=0;                   //是否在线
    int onLinecount=0;                   //是否在线
    int status=0;                   //station 0无料框  1有料框      door 0关门   1开门
    int sensor_1=0;                 //1号光电感应 状态  0无  1有
    int sensor_2=0;                 //2号光电感应 状态  0无  1有
    int currentEnable=0;            //使能
};

namespace Ui {
class DeviceItem;
}

class DeviceItem : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceItem(QWidget *parent = nullptr);
    ~DeviceItem();

    int deviceId=0;                 //设备Id
    QString deviceIP="";            //设备IP
    QString deviceDesc="";          //设备名称
    QString deviceType="";          //设备类型  自动门 door  站点接驳台 Station
    int page=0;                     //显示页码

    deviceI currentDeviceI;

    QMap<QString,QString>cageIdMap; //deviceType- DeviceStatus  不同类型 不同状态下显示 不同图片
    QMap<QString,QString>StatusMap; //  不同类型 不同状态显示

    void DeviceItemInit();

    void DeviceItem_widget_Show();      //实时更新工作站点 状态信息

signals:
    //设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
    void sigDeviceStatusAction(QString DeviceIP,QString deviceType, QString orderType, int Action);


private slots:
    void ON_DeviceTimer();

    void on_action_Button1_clicked();

    void on_action_Button2_clicked();

    void on_enable_Button_clicked();

    void on_reset_Button_clicked();

    void ON_Pressed();

    void ON_Released();

private:
    void paintEvent(QPaintEvent *);

private:
    Ui::DeviceItem *ui;

    QTimer *viceTimer;

    QList<QPushButton *>Actionbtns;

};

#endif // DEVICEITEM_H
