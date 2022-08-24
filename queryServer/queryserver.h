#ifndef QUERYSERVER_H
#define QUERYSERVER_H

#include <QObject>
#include "getinstancedefine.h"
#include "sapmsginterface.h"
#include "comm/config/cfgsetting.h"
#include "singleProject/instance.h"
#include "sqlConnect/ConnectionPool.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"

struct materialInfo             //物料件号信息
{
    QString materialNumber="";  //物料件号
    QString base_unit;          //基础单位   base_qty: 5 ---> base_unit: M/EA(米) ---> weighUnit: kg  代表的是5(米/个) / kg
    double  base_qty;           //基础数量
    QString unit="";            //单位
    QString batch="";           //批次
    QString store="";           //仓号
    QString plant;              //工厂
    QString describe;           //描述
    QString unitOfWeigh;        //物料净重
    QString weighUnit;          //重量单位
    QString customsType;        //报关类型 Local国内 Tax保税 Import征税
    double density=0.00;        //密度
    double base_Ratio;          //base_qty/qty的换算比例（基础数量除以贴纸数量）
    double weightChange=1.00;   //  --kg 的换算系数
};

struct materialShelfbin        //物料件号 与架位对应表
{
    int containerIndex=0;      //容器编码索引 ->唯一
    QString containerCode="";  //容器编码 (即胶箱编码) ->唯一

    int shelfBinIndex=0;       //所属架位索引 ->唯一
    QString shelfBindesc="";   //所属架位注释 ->唯一

    QString materialNumber=""; //物料件号
    QStringList pcbList;       //PCB 集合
    QString pcbListdesc;       //PCB 集合

    QString plant="";          //工厂
    int status=0;              //0 空闲  1任务占用中

    QString storeCode="";      //仓号
    QString base_unit="";      //基础单位
    QString customsType="";    //报关类型

    double realqty=0.00;            //订单里数量
    double checkqty=0.00;      //盘点数量

    QDateTime creatTimer;      //上次盘点时间

    QString lastuser;          //上次盘点操作员
    QDateTime lastCheckTimer;  //上次盘点时间

};

struct shelfBinInfo {

    int shelfBinIndex=0;       //所属架位索引
    QString shelfBindesc="";   //所属架位注释
    QString podId="";          //货架编号
    QString podIdDesc="";      //库位编码

    int containerIndex=0;      //容器编码索引 ->唯一
    QString containerCode="";  //容器编码 (即胶箱编码) ->唯一
    int SAPTaskIndex=0;        //
    QString LabelNo="";        //工单凭证号
    materialShelfbin materialShelfbinI;
    QMap<QString, materialShelfbin> materialShelfbinMap;

    int binEnable=0;           //使用/禁用
    int showEnable=0;          //是否显示
    int setFull=0;             //0未满  1已满
    int status=0;              //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲

    int layer=0;               //第几层
    int side=0;                //第几列

    double volume=0.00;        //Bin的体积 14升
    double allvolume=0.00;     //总体积

    double percent=0.00;       //占用 %
    double realqty=0.00;       //实际存放数量

    double weight=0.00;        //实际存放重量
    double maxweight=0.00;     //最大存放重量

};



struct deviceServer
{
    int Infocount=0;
    QString deviceIP="";                            //设备客户端 IP
    QByteArray queryArray;
    QMap<QString,QByteArray>AnalysisArrayMap;       //设备客户端返回 数据 待处理缓存链表
    QMap<QByteArray,QByteArray>deviceActionArray;   //设备动作指令 缓存链表
};

//周边控制板
struct controlbox {
    int boxID=0;           //控制盒拨号编码编号
    QString boxIP="";      //控制板 IP地址

    int X17=0;             //1表示有信号  0表示无信号
    int X16=0;             //1表示有信号  0表示无信号
    int X15=0;             //1表示有信号  0表示无信号
    int X14=0;             //1表示有信号  0表示无信号
    int X13=0;             //1表示有信号  0表示无信号
    int X12=0;             //1表示有信号  0表示无信号
    int X11=0;             //1表示有信号  0表示无信号
    int X10=0;             //1表示有信号  0表示无信号

    int Y17=0;             //1表示有信号  0表示无信号
    int Y16=0;             //1表示有信号  0表示无信号
    int Y15=0;             //1表示有信号  0表示无信号
    int Y14=0;             //1表示有信号  0表示无信号
    int Y13=0;             //1表示有信号  0表示无信号
    int Y12=0;             //1表示有信号  0表示无信号
    int Y11=0;             //1表示有信号  0表示无信号
    int Y10=0;             //1表示有信号  0表示无信号

    QDateTime datetimer;
};

struct deviceI
{
    /******************* 设备基础定义 **************/
    int deviceId=0;                 //设备Id
    QString deviceIP="";            //设备IP
    QString deviceDesc="";          //设备名称
    QString deviceType="";          //设备类型

    int onLine=0;                   //是否在线
    int onLinecount=0;              //是否在线
    int status=0;                   //station 0无料框  1有料框      door 0关门   1开门
    QString statusDesc="";          //station 0无料框  1有料框      door 0关门   1开门
    int sensor_1=0;                 //1号光电感应 状态  0无  1有
    int sensor_2=0;                 //2号光电感应 状态  0无  1有
    int sensor_3=0;                 //2号光电感应 状态  0无  1有
    int enable=0;                   //使能
    int checked=0;                  //是否选中
    controlbox controlboxItem;      //所有 IO 信息

    /******************* 接驳台类型 **************/
    QString StationType="";         //站点类型
    QString stationDesc="";         //站点名称
    int Currentpoint=0;             //当前所在二维码
    QString waitDesc="";            //站点等待点名称
    int waitPoint=0;                //站点等待点二维码

    int SAPTaskIndex=0;             //任务索引 唯一值
    int taskStatus=0;               //任务状态
    QString taskStatusDesc="";      //任务状态注释
    int agvNum=0;                   //小车编号
};


struct record_log{          //出入库，查仓，记录
    int logId=0;
    QString LabelNo="";       //标签
    QString Material="";      //物料件号
    int shelfBinIndex=0;      //架位 Bin index
    QString shelfBindesc="";   //架位号   desc
    QString store="";          //仓号
    QString batch="";          //批次
    QString Unit="";           //单位

    double sapQty=0.00;         //贴纸数量
    double readlQty=0.00;       //实际数量
    QString UserNumber="";      //操作员
    QString taskType="";        //任务类型  1出库  2入库 3盘点 4查仓 5改位入库
    int TypeId=0;               //1出库 2 入库 4查仓
    int errorTypeId=0;          //错误类型.
    QString errormassega="";    //错误注释

    QDateTime Time;             //时间
    QString nowDate="";         //日期
    double  base_weigh=0.00000; //SAP单个数量 的重量 kg
    QString WeighType="";       //称重类型   称重  计数
    double allWeigh=-0.00;      //称出总重   (kg)
    double weigh_base=-0.00;    //称出单个重量
    double weigh_pcs=-0.00;     //计数的数量
    QString IssueType="";//发料类型  344 LM DN SL
    QString IssueDesc="";
    QString LabelType="";//贴纸类型 N KT
    int operaterIndex=0;//操作台编号

    QString pickType="";
    QString creatTime="";
    QString orderId="";

};

struct ServerInit //基础信息
{
    QMap<int,sapPath>sapPathMap;                    //接口路径信息
    QList<User_Info>UserInfoList;                   //获取登录用户信息
    QMap<int,QString>errorTypeMap;                  //操作时 错误类型 错误码与译文
    QMap<QString,QString> taskStatusMap;            //任务状态的错误码与译文
    QMap<QString,doorSubTask>doorSubTaskMap;        //所有自动门的基础信息
    QMap<QString,eventCode>eventCodeMap;            //ESS-P 事件 回调类型
    QMap<QString,QString>StationCodeMap;            //工作站与 ESS-P坐标点
    QMap<QString,QString>BindescPodIdMap;           //架位绑定转换 库位翻译
    QMap<QString,int>AGVIPInitMap;                  //AGVIP 与 待机点
    QMap<QString,int>StationPointMap;               //工作站名称 与 二维码绑定

};

struct ServerItem //需要实时更信息 链表表 整合
{
    QMap<QString,LiftCode>LiftCodeMap;                  //升降机各个接驳台任务状态信息
    QMap<QString,AGVCurrentTask*>AGVCurrentTaskMap;     //AGV状态信息
    QMap<int, SAPExcelInfo>currentSAPExcelInfoTask;     //SAP 正在执行或未完成的任务
};

struct allServerInit
{
    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合
};

class queryServer : public QObject
{
    Q_OBJECT
public:
    explicit queryServer(QObject *parent = nullptr);

    REGISTERGETINSTANCE(queryServer)//获取单例模式

    allServerInit ALLServerInitItem;
    void setCurrentServerInitItem(ServerItem CServerItem, ServerInit CServerInit);

    allServerInit getCurrentServerInitItem();

    QList<User_Info>getUserInfoList();
    //**********************************任务查询********************************//

    QMap<int, SAPExcelInfo>querySAPExcelInfoList(slecetSAP_Log slecetSAP_LogI);

    QMap<int,email_message> getsyserror_message();              //获取 未处理的系统异常信息
    bool setsyserror_message(email_message email_messageI);     //设置 已处理的系统异常信息状态

    QMap<int,email_message> getemail_message();                 //获取 满足条件的 邮件信息

    //物料件号-仓号-批次 作为唯一键值
    QMap<QString ,materialInfo >querymaterialInfoMap();

    //////////////////////////////////////////////////
    /// \brief queryrecord_IntOut  查询操作台出入库操作记录
    /// \return
    ///
    QMap<int, record_log> queryRecord_log_nowDate();

    //设置弹出窗口提示
    bool SetMessagebox(QString Messagetext);


};

#endif // QUERYSERVER_H
