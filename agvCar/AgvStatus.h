#ifndef AGVSTATUS_H
#define AGVSTATUS_H

#include <QWidget>
#include "agvcarpool.h"
#include <QTimer>
#include <QColor>
#include <QTableWidgetItem>

class QTimer;
namespace Ui {
class AgvStatus;
}
typedef enum
{
    ERROR_NULL                =0,      //无错误
    ERROR_GYROTIMEOUT         =1,      //陀螺仪通信超时
    ERROR_GYROINITERROR       =2,      //陀螺仪初始化故障
    ERROR_MOTOR1_TIMEOUT      =3,      //马达1通信超时
    ERROR_MOTOR2_TIMEOUT      =4,      //马达2通信超时
    ERROR_MOTOR3_TIMEOUT      =5,      //马达3通信超时
    ERROR_MOTOR4_TIMEOUT      =6,      //马达4通信超时
    ERROR_MOTOR5_TIMEOUT      =7,      //马达5通信超时
    ERROR_MOTOR1_ALARM        =8,      //马达1故障报警
    ERROR_MOTOR2_ALARM        =9,      //马达2故障报警
    ERROR_MOTOR3_ALARM        =10,     //马达3故障报警
    ERROR_MOTOR4_ALARM        =11,     //马达4故障报警
    ERROR_MOTOR5_ALARM        =12,     //马达5故障报警
    ERROR_MOTOR1_CONTROL      =13,     //马达1控制故障
    ERROR_MOTOR2_CONTROL      =14,     //马达2控制故障
    ERROR_MOTOR3_CONTROL      =15,     //马达3控制故障
    ERROR_MOTOR4_CONTROL      =16,     //马达4控制故障
    ERROR_MOTOR5_CONTROL      =17,     //马达5控制故障
    ERROR_CONTROL_ANGLE_FRONT =18,     //前转角度控制故障
    ERROR_CONTROL_ANGLE_BACK  =19,     //后转角度控制故障
    ERROR_MOTOR_ZERO_INIT     =20,     //旋转马达位置初始化
    ERROR_DRIVER_UPDOWN       =21,     //驱动升降故障
    ERROR_EMSTOP              =22,     //急停按下报警
    ERROR_OFFSET_LINE         =23,     //路径偏移过大
    ERROR_QRCODE_LOST         =24,     //丢失二维码故障
    ERROR_ROTATION_OFFSETMAX  =25,     //原地旋转偏差二维码过大
    ERROR_POBLIFT_OUTHEIGHT   =26,     //頂盘参数在行程允许范围外
    ERROR_POBLIFT_NOTINIT     =27,     //頂盘未原点初始化
    ERROR_LASER_FAR           =29,     //前远激光障碍感应感应
}ERROR_CODE;

class AgvStatus : public QWidget
{
    Q_OBJECT

    /************** 基础信息链表 ***********/
    QMap<int,QString >moveTaskStateMap;                 //返回指令接收状态


public:
    explicit AgvStatus(QWidget *parent = nullptr);
    ~AgvStatus();
    QString getErrorCodeText(ERROR_CODE code);
    QString getWarningCodeText(int code);
    void closeEvent(QCloseEvent *);

private slots:
    void timerTimeOut();

private:
    Ui::AgvStatus *ui;
    QTimer *timer;
    int autoOpenCount;


};

#endif // AGVSTATUS_H
