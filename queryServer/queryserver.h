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
    int podId=0;               //货架编号
    QString podIdDesc="";      //货架注释

    int containerIndex=0;      //容器编码索引 ->唯一
    QString containerCode="";  //容器编码 (即胶箱编码) ->唯一
    QString LabelNo="";        //工单凭证号
    materialShelfbin materialShelfbinI;
    QMap<QString, materialShelfbin> materialShelfbinMap;

    QString storeCode="";      //仓号属性
    QString customsType="";    //类型属性

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

struct countpick{
    double allcount=0.00;       //今天的数量
    double finishcount=0.00;    //已完成数量
    double unfinishcount=0.00;  //未完成数量
    double DN_count=0.00;       //待发DN
    double SL_count=0.00;       //待发SL
    double LM_count=0.00;       //待发LM
    double Other_count=0.00;    //待发Other
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
};

struct StationInfo{            //站点基础信息
    int StationId=0;           //站点Id
    QString StationDesc="";    //站点名称
    QString StationIP="";      //站点IP地址
    int floor=0;               //站点所在楼层

    int online=0;              //0离线  1在线
    int status=0;              //状态 0无料框  1有料框
    int sensor_1=0;            //1号光电感应 状态  0无  1有
    int sensor_2=0;            //2号光电感应 状态  0无  1有

    int action=0;              //当前动作指令
    QString StationType="";    //站点类型  IN二楼入库  OUT二楼出库   2F_L二楼升降机 3F_L三楼升降机  3F_S 三楼产线
    int page=0;                //当前页面索引


    int taskStatus=0;           //任务状态  0空闲  1占用  2正在执行  3执行完成  0空闲
    int currentpoint=0;         //站点所在二维码
    int liftpoint=0;            //对应升降机的二维码

    QString containerCode="";   //容器编码 (即胶箱编码) ->唯一
    QStringList TaskIndexList;  //用于二楼出库时 判断接驳台任务分配
    QString TaskIndexListdesc;  //用于二楼出库时 判断接驳台任务分配

    QString obligate1="";        //预留1
    QString obligate3="";        //预留3
    QString obligate4="";        //预留4
    int enable=0;                //使用禁用使能

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

    QMap<QString,int>AGVIPInitMap;                  //AGVIP 与 待机点
    QMap<QString,int>StationPointMap;               //工作站名称 与 二维码绑定

};

struct ServerItem //需要实时更信息 链表表 整合
{
    QMap<QString,QString>PoidAndDesc;                   //架位绑定转换
    QMap<QString,shelfBinInfo>shelfBinInfoMap;          //实时更新 Bin 的状态信息

    QMap<QString,StationInfo>StationInfoMap;            //实时更新站点的状态信息

    QMap<QString,LiftCode>LiftCodeMap;                  //升降机各个接驳台任务状态信息
    QMap<QString,AGVCurrentTask>AGVCurrentTaskMap;      //AGV状态信息

    QMap<int, SAPExcelInfo>currentSAPExcelInfoTask;    //SAP 正在执行或未完成的任务

};

class queryServer : public QObject
{
    Q_OBJECT
public:
    explicit queryServer(QObject *parent = nullptr);

    REGISTERGETINSTANCE(queryServer)//获取单例模式


    ServerInit ServerInitItem;
    void setCurrentServerInitItem(ServerInit CServerInit);

    ServerInit getCurrentServerInitItem();

    QList<User_Info>getUserInfoList();

    bool setcurrentSAPExcelInfoTask();


    QMap<int,email_message> getsyserror_message();              //获取 未处理的系统异常信息
    bool setsyserror_message(email_message email_messageI);     //设置 已处理的系统异常信息状态

    QMap<int,email_message> getemail_message();                 //获取 满足条件的 邮件信息

    //物料件号-仓号-批次 作为唯一键值
    QMap<QString ,materialInfo >querymaterialInfoMap();

    //ikey -架位  多对一 物料件号-仓号-批次作为唯一键值
    QMap<QString ,materialShelfbin >querymaterialshelfBinMap(shelfBinInfo shelfBinInfoItem);

    shelfBinInfo querymaterialshelfBinMap_(shelfBinInfo shelfBinInfoItem);


    //////////////////////////////////////////////////
    /// \brief queryrecord_IntOut  查询操作台出入库操作记录
    /// \return
    ///
    QMap<int, record_log> queryRecord_log_nowDate();

    //设置弹出窗口提示
    bool SetMessagebox(QString Messagetext);


};

#endif // QUERYSERVER_H
