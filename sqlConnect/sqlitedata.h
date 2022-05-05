#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QObject>
#include <QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDateTime>
#include<qdebug.h>
#include "Singleton.h"
#include "ConnectionPool.h"

//Roboshop 状态信息
struct RoboshopState
{
    QString Roboshop_IP="";                        //RoboshopIP
    double controller_temp;//控制器温度, 单位 ℃
    double controller_humi;//控制器湿度, 单位 %
    double controller_voltage;//控制器电压, 单位 V
    double x;              //	机器人的 x 坐标, 单位 m
    double y;//机器人的 y 坐标, 单位 m
    double angle;      //机器人的 angle 坐标, 单位 rad
    double confidence=0.00; //机器人的定位置信度, 范围 [0, 1]
    QString current_station;//机器人当前所在站点的 ID（该判断比较严格，机器人必须很靠近某一个站点(<50cm)，否则为空字符，即不处于任何站点）
    QString last_station;//机器人上一个所在站点的 ID
    double vx;//机器人在机器人坐标系的 x 方向速度, 单位 m/s
    double vy;//机器人在机器人坐标系的 y 方向速度, 单位 m/s

    /*
     *减速的原因 / 被阻挡的原因, 0 = Ultrasonic (超声), 1 = Laser (激光), 2 = Fallingdown (防跌落传感器),
     * 3 = Collision (碰撞传感器), 4 = Infrared (红外传感器),
     * 5 = Lock（锁车开关），6 = 动态障碍物，
     * 7 = 虚拟激光点，8 = 3D 相机
    */
    bool blocked;//机器人是否被阻挡
    double block_reason;//******被阻挡的原因,
    double block_x;//最近障碍物位置的 x 坐标, 单位 m
    double block_y;//最近障碍物位置的 y 坐标, 单位 m

    bool slowed;//机器人是否减速
    double slow_reason;//********
    double slow_x;//最近的导致减速的障碍物位置的 x 坐标, 单位 m
    double slow_y;//最近的导致减速的障碍物位置的 y 坐标, 单位 m

    bool charging;//电池是否正在充电
    double voltage;//电压, 单位 V
    double current;//电流, 单位 A
    bool emergency=false;//true 表示急停按钮处于激活状态(按下), false 表示急停按钮处于非激活状态(拔起)
    bool driver_emc=false;//true 表示驱动器发生急停, false 驱动器发生未急停

    double task_status; //0 = NONE, 1 = WAITING, 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
    double task_type;//导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 5 = 钻货架, 6 = 跟随, 7 = 平动转动, 8 = 磁条导航, 100 = 其他
    QString target_id;//	当前导航要去的站点, 仅当 task_type 为 2 或 3 时该字段有效, task_status 为 RUNNING 时说明正在去这个站点, task_status 为 COMPLETED 时说明已经到达这个站点, task_status 为 FAILED 时说明去这个站点失败, task_status 为 SUSPENDED 说明去这个站点的导航暂停
    QString roboroute_target;//	调度系统 RoboRoute 让机器人去的最终目标站点 ID
    int reloc_status;//0 = FAILED(定位失败), 1 = SUCCESS(定位正确), 2 = RELOCING(正在重定位), 3=COMPLETED(定位完成)


    QList<QList<double> > path;//机器人所在区域 id 的数组(由于地图上的区域是可以重叠的, 所以机器人可能同时在多个区域)，数组可能为空
    QList<QString> finished_path;//当前导航路径上已经经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效点。如果是路径导航， 这里会列出所有已经经过的中间点
    QList<QString> unfinished_path;//当前导航路径上尚未经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效。如果是路径导航， 这里会列出所有尚未经过的中间点;

    QJsonObject warnings;//报警码 Warning 的数组, 所有出现的 Warning 报警都会出现在数据中
    QJsonObject errors;//报警码 Error 的数组, 所有出现的 Error 报警都会出现在数据中
    int ret_code;//API 错误码
    QString err_msg;//错误信息


//自定义
    bool isOnline = false;                     //Roboshop是否掉线
    bool RunState=true;                       //是否停止状态
    bool Roboshop_FinishInit = false;         //Roboshop已完成  重定位 初始化
    int  RoboshopFinishInitcount=0;
//
    QString Roboshop_ChargeAction;            //充电任务锁定(0.充电任务无锁定，1.充电任务锁定)

    QString relocation = "-1";//0 断开当前连接, 1开始建立新连接, 2 等待连接成功 并_发送数据, 3 数据发送成功

};

//协议 端口类型协议
struct RobotProtocol
{
   QString robotEnum;//类型名
   QString type;
   quint16 port;
};

struct SCProtocol
{
    QString req;
    quint16 reqValue;
    QString type;
    quint16 isDelelte;
    QString reqDescription;
    quint16 res;
    quint16 resValue;
    QString resDescription;
};

struct description//
{
    QString Type;               //类型
    QString resDescription;    //动作命令解析
    quint16 port;              //TCP端口
    quint16 reqValue;          //报文类型
};

struct lmstation//
{
    int taskId;
    QString LM_Name="";     //地图站点
    QString navigation="";  //导航
    QString relocation="";  //重定位
    QDateTime time;
};

struct moveTask
{
    int taskId=0;
    int action=-1;           //  0  暂停   1继续
    QString navigation="";  //导航
    QList<QString> LMNamelist;
    int type;
    QDateTime time;
};

struct RoboshopAction//
{
    QByteArray writeData;

    QString SocketState="";
    QString sendDataStr = "";
    QString descrip="";        //动作类型解析
    int relocation = -1; //0 断开当前连接  1开始建立新连接 2 等待连接成功 并 发送数据  3 数据发送成功
    quint16 port=19206;        //TCP端口
    int count=-1;
};

struct ActionBtn{//点击控件的命名 及解析
    QString objectName="";
    QString descrip="";
    QString Action="";
    QString status="";
    QString image="";
    QString image1="";
};
struct motion{
    bool motionbool=false;
    double vx;  //机器人在机器人坐标系中的 x 轴方向速度, 若缺省则认为是 0, 单位 m/s
    double vy;  //机器人在机器人坐标系中的 y 轴方向速度, 若缺省则认为是 0, 单位 m/s
    double vw;//机器人在机器人坐标系中的角速度(即顺时针转为负, 逆时针转为正), 若缺省则认为是 0, 单位 rad/s
    double steer;//-2= 一键回零，1=15° 递增，-1=15° 递减（机器人坐标系），仅当单舵轮机器人时该值有效，该字段存在时，不响应 vy 和 w，此时 vx 含义变为舵轮线速度
    double real_steer;//目标舵角值（机器人坐标系）, 单位 rad, 仅当单舵轮机器人时该值有效，该字段存在时，不响应 vy 和 w，此时 vx 含义变为舵轮线速度，优先级大于 steer
    double duration=500;//机器人使用开环速度运动的持续时间, 单位 ms, 0= 一直保持当前开环速度运动, 该参数缺省时，使用参数配置中 ControlMotionDuration 的数值
};



class SqliteData
{
    SINGLETON(SqliteData)
public:
    QString RobotIP="";

public:
    QString getRobotIP();


    bool insertLmstation(lmstation lmstationI);
    bool deleteLmstation(lmstation lmstationI);
    bool updataLmstation(lmstation lmstationI);
    QMap<QString,lmstation> getLmstation();
    bool insertLmstationMap(QMap<QString, lmstation> lmstationMap);

    bool insertmoveTask(moveTask moveTaskI);
    bool deletemoveTask(moveTask moveTaskI);
    bool updatamoveTask(moveTask moveTaskI);
    QMap<int,moveTask> getmoveTaskMap();
    QList<QString> getLMNamelist(moveTask moveTaskI);

    // ikey=resDescription
    QMap<QString,description> getdescription();

    QMap<QString,ActionBtn> getActionBtn();

    bool setRobotIp(QString robotIP);
    QString getRobotIp();

public:


signals:

public slots:
};

#endif // SQLITEDATA_H
