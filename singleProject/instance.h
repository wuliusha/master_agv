#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

typedef enum
{
    storage = 1,
    delivery = 2,
}taskTypeEnum;

typedef enum
{
    taskType_0ut= 1,
    taskType_in= 2,
    taskType_check= 3,
    taskType_stro= 4,
    taskType_chage= 5,
    taskType_cstro= 6,

}taskTypeId;//任务类型  1出库  2入库 3盘点 4查仓 5改位入库

typedef enum
{
    taskStatus_arrive=4,        // 到达操作台  墨绿色
    taskStatus_checkmmax=-2,    // -2<=taskStatus<=-50 属于任务异常项 不可勾选
    taskStatus_checkmin=-50,    // 小于-50 数据拦截项  可勾选
    taskStatus_checkbase=-60,   // 大于-60 数据拦截项  可勾选

}taskStatusId;//根据任务状态 显示颜色


struct email_message{
    int taskId=0;
    QString message="";
    QDateTime creatTime;
    int status=0;
};

//SAP 上载任务 Excel 对应关系
struct Variant{
    QVariantList SAPTaskIndex;   //任务索引 唯一值
    QVariantList Picture;
    QVariantList status;   //是否获取成功 1 成功 0 失败
    QVariantList Priority;     //出库任务 优先级 0-100 由高到低
    QVariantList IssueType;   //发料类型
    QVariantList LabelType;   //贴纸类型
    QVariantList LabelNo;     //贴纸凭证号  （LabelNo+LabelItem    生产唯一凭证 ==打印的条形码）
    QVariantList LabelItem;   //贴纸项目   （当LabelItem>基数上浮%20，分为两个工作，并分给不同工作台）
    QVariantList Order_PO;    //生产或采购订单
    QVariantList Order_POItem;//生产或采购订单项目
    QVariantList Material;    //物料号
    QVariantList Quantity;    //数量
    QVariantList Unit;        //单位
    QVariantList Batch;       //批次
    QVariantList Rev;         //版次
    QVariantList IssueStore;  //发料仓号
    QVariantList IssueBin;    //发料货位号
    QVariantList To;          //收货单位
    QVariantList ToBin;       //收货单位地址
    QVariantList Describe;    //物料描述
    QVariantList SO;          //销售订单
    QVariantList SOItem;      //销售订单项目
    QVariantList ProductCode; //产品代码
    QVariantList Ex_ImGroup;  //进出口群组
    QVariantList PackingNote; //包装注解
    QVariantList Route;       //运输线路
    QVariantList BillOfLading;//提货单
    QVariantList HeaderText;  //标题文本
    QVariantList LM_SL;       //订单状态
    QVariantList Reservatio;  //预约编码
    QVariantList Date;        //日期
    QVariantList Time;        //时间
    QVariantList AssembleNo;  //成品物料号
    QVariantList Text;        //文本
    QVariantList Remark;      //备注
    QVariantList unitOfWeigh;    //物料净重
    QVariantList weighUnit;      //重量单位
    QVariantList customsType;    //报关类型 Local国内 Tax保税 Import征

    QVariantList plant;              //工厂
    QVariantList shelfBinIndex;         //架位Bin的索引
    QVariantList podId;                //货架号
    QVariantList taskType;              //任务类型 1入库 2出库 3盘点 4查仓 5改位入库
    QVariantList taskStatus;        //任务状态
    QVariantList creatTime;        //创建时间
    QVariantList pickStation;

    QVariantList taskError;            //任务错误代码
    QVariantList restStatus;          //重启次数标志

};


//POST 接口返回
struct ReplyMsg
{
    QString keyId="";               //唯一识别号 由Lims 创建并绑定
    int status=-1;                  //任务状态  status=0-成功    其他失败
    QString errorMsg="非法值错误";   //异常原因拦截详细信息
    QStringList datalist;

    QJsonObject ReplyJson;         //数据包
};

//ESS-P 事件回调
struct eventCode
{
    QString eventCode="";        //回调类型
    QString eventCodeDesc="";
    QString taskType_IN="";
    QString taskType_OUT="";
    QString taskType_Empty="";
};


//获取标签信息返回WS01
struct  labelMsgStruct{
    QString labelNo="";
    QString replylabelNo;   //"labelNo":"5011112221/0001/0000", //标签号
    QString material="";       //"material":"00-00020",            //物料号
    QString plant;          //"plant":"H100",                   //工厂
    QString base_unit;      //基础单位
    double  base_qty;       //基础数量
    double  qty=0.00;            //23.5,   贴纸数量
    QString unit;           //"GM"    贴纸 单位
    QString describe;       //描述
    QString batch;          //批次
    QString unitOfWeigh;    //物料净重
    QString weighUnit;      //重量单位
    QString IssueType;      //发料类型
    QString result="";      //结果, S为成功, E为错误
    QString message;        //系统讯息

    /*********** 新接口变化************/
    QString IssueStore="";     //发料仓号     当发料任务时 把此值赋值给 SAPExcelInfo-->store
    QString IssueBin="";       //发料货位号   当发料任务时 把此值赋值给 SAPExcelInfo-->bin

    QString rv_Store="";       //当上架任务时   把此值赋值给 -->store
    QString rv_Bin="";         //当上架任务时   把此值赋值给 -->bin

    QString store="";        //store == SAPExcelInfo-->store
    QString bin="";          //store == SAPExcelInfo-->bin

    QString customsType="";    //报关类型 Local国内 Tax保税 Import征
    QString rv_customs_type="";//上架时 采用此报关类型  并赋值给--customsType
    QString sp_customs_type="";//发料时 采用此报关类型  并赋值给--customsType

    QString errortextEdit="";//异常原因拦截详细信息
    int taskStatus=-107;     //默认存在拦截项

};


//ESS 海柔夹包机器人背篓状态信息
struct  ESStrays{
    int trayLevel=0;            //背篓序号
    QString containerCode="";   //货箱编码
    QStringList taskCodes;      //业务任务
    QString positionCode="";    //位置编码
};

//ESS 海柔夹包机器人状态信息
struct  ESSRobot{
    QString iKey="";
    QString robotCode="";           //机器人编码
    QString robotTypeCode="";       //型号
    QString pointCode="";           //节点编码
    int positionX=0;                //坐标x
    int positionY=0;                //坐标y
    int theta=0;                    //角度
    int forkHeight=0;               //货叉高度
    int forkLength=0;               //货叉长度
    int forkTheta=0;                //货叉相对机器人角度
    int stationCode=0;              //工作站编码
    QString locationCode="";        //工作位编码

    QMap<int,ESStrays>ESStraysMap;  //背篓列表

};

struct User_Info//用户个人信息
{
    QString UserNuber="";      //工号
    QString UserName="";       //姓名
    QString PassWord="";       //密码
    QString Jurisdiction="";   //权限
    QString UserGrage="";      // 等级
    QString Status="0";        //编辑状态 -1删除

    int corlor=0;       //-1 红色(异常)  0 默认颜色  1 绿色（到达且已扫描）  2 黄色()  100 浅灰(完成)
    int checked=-1;     //-1默认状态   0 默认不勾选   1勾选状态
};

struct RW_Excel{//导出excel
    int corlor=0;       //-1 红色(异常)  0 默认颜色  1 绿色（到达且已扫描）  2 黄色()  100 浅灰(完成)
    int errorStatus=0;  //0 无错误  1拦截错误(可勾选) 2 异常错误(不可勾选)
    int checked=-1;     //-1默认状态   0 默认不勾选   1勾选状态
    int fontclrlor=0;   //字体颜色 默认 0白色   1红色  (离线)
    int fontclrlor1=0;   //字体颜色 默认 0白色   1红色 (操作超时)
    int corlor_=0;
    int taskRow=0;       //显示排行 row

    QString ExcelA;
    QString ExcelB;
    QString ExcelC;
    QString ExcelD;
    QString ExcelE;
    QString ExcelF;
    QString ExcelG;
    QString ExcelH;
    QString ExcelI;
    QString ExcelJ;
    QString ExcelK;
    QString ExcelL;
    QString ExcelM;
    QString ExcelN;
    QString ExcelO;
    QString ExcelP;
    QString ExcelQ;
    QString ExcelR;
    QString ExcelS;
    QString ExcelT;
    QString ExcelU;
    QString ExcelV;
    QString ExcelW;
    QString ExcelX;
    QString ExcelY;
    QString ExcelZ;

    QString ExcelAA;
    QString ExcelAB;
    QString ExcelAC;
    QString ExcelAD;
    QString ExcelAE;
    QString ExcelAF;
    QString ExcelAG;

};

//SAP 上载任务 Excel 对应关系
struct SAPExcelInfo{

    int SAPTaskIndex;           //任务索引 唯一值
    QString taskType="";        //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
    QString taskTypeDesc="";

    QString taskId="";          //任务编码 唯一性
    QString taskId_ess="";      //夹抱机器人 任务编码 唯一性
    QString taskId_agv="";      //举升机器人 任务编码 唯一性
    QString AGVIP="";           //当前搬运小车IP

    QString floorId="";         //楼层走向  2F-3F 3F-2F
    QString obligate1="";       //预留
    QString obligate2="";       //预留

    //(备注: 任务执行过程中,取箱与放箱操作可重复执行,用于任务异常时，人工纠正后可继续执行)

    //IN-入库  OUT-出库  MOVE-移库  Empty-返空箱
    //入库:-1 默认值  0等待配送  1开始下发到ESS  2ESS下发成功  3容器到位  4容器到位下发成功  5到达工作站   6取箱成功   7离开工作站  8放箱成功  100任务完成

    //出库:-1 默认值  0等待配送  1开始下发到ESS  2ESS下发成功  3开始取箱  4取箱成功  5到达对接码头 6等待放箱
    //7开始放箱  8放箱成功     9判断升降机码头是否空闲   10等待AGV执行   11AGV开始取箱  12AGV前往取箱  13 离开取货点
    //13 给ESS下发容器离场    14判断起始楼层AGV是否到达电梯接驳台  15到达电梯接驳台  16读取目标楼层电梯状态，判断是否可以取货
    //17 等待目标楼层AGV执行  18离开目标电梯取货点   100出库完成

    //返回空箱: -1 默认值  0等待配送  1开始运输  2到达起始楼层  3开始前往目标楼层  4到达目标楼层  5开始运输  100任务完成

    //移库:-1 默认值  0开始执行   1取箱中   3取箱成功  4等待放箱  5放箱成功  7任务完成
    int taskStatus=-1;          //任务状态
    QString taskStatusDesc="";  //任务状态注释

    QString sourcestation="";   //来源 入库为NULL，出库为库位
    QString pickDesc_s="";      //起始站点的对接码头

    QString pickDesc_e="";      //目标站点的对接码头
    QString destination="";     //目的地。入库为库位，出库为线体

    QString podIdDesc="";       //所属架位注释 -- MES
    QString shelfBindesc="";    //所属架位注释 -- ESS
    QString containerCode="";   //容器编码 (即胶箱编码) ->唯一
    QString obligate3="";       //预留
    QString obligate4="";       //预留
    QString batch="";           //批次


    QString oldIdDesc="";       //所属架位注释 -- MES
    QString oldBinDesc;         //改架前的 Bin   (用于AGV内部移库) -- ESS

    QString newIdDesc="";       //所属架位注释 -- MES
    QString newBinDesc;         //改架后的 Bin   (用于AGV内部移库) -- ESS

    int checked=0;             //-1默认状态   0 默认不勾选   1勾选状态
    int cancelTask=0;          //大于0  取消
    double Priority=100;       //出库任务 优先级 1-100 由高到低  默认值不变100
    int taskError=0;           //任务错误代码
    QString errortextEdit="";  //异常原因详细信息

    QString lastuser;          //操作员
    QDateTime taskTimer;       //更新时间
    QDateTime creatTimer;      //创建时间
    QDateTime finishTimer;     //完成时间

/********************* MES 的订单物料信息 *********************/

    QString LabelNo="";        //贴纸凭证号
    QString Material="";       //物料编码
    QString customsType="";    //类型属性
    QString storeCode="";      //仓号属性
    double  taskQty=0.00;      //数量
    QStringList MaterialList;  //物料编码 集合
    QString MaterialListdesc;  //物料编码 集合

};

struct door_acion
{
    int Point=0;                      //起始点  用于开门
    int NextPoint=0;                  //下一点  用于开门
    QList<int>NextPointList;          //保持开门信号二维码链表
};

struct doorSubTask
{
    int doorId=0;
    QString doorIP="";              //自动门IP地址
    QString doorDesc="";            //自动门名称
    int Point=0;                    //起始点  用于开门
    int NextPoint=0;                //下一点  用于开门
    QString NextPointdesc;          //保持开门信号二维码链表
    QList<int>NextPointList;        //保持开门信号二维码链表

    QString obligate1="";           //预留
    QString obligate2="";           //预留
    QString obligate3="";           //预留

    int page=0;                     //当前页面索引
    int enable=0;                   //使用禁用使能

    int door_Line=0;                //是否在线  0离线 1在线
    int door_status=0;              //0 关  1开
    int sensor_1=0;                 //1号光电感应 状态  0无  1有
    int sensor_2=0;                 //2号光电感应 状态  0无  1有

    QString AGVIP="";
    int orderAction=0;              //1开门 2关门
    int checked=0;                  //1选择 0取消
    int row=0;                      //显示在第几行

    door_acion door_acionI;
    QDateTime updateTimer;          //最新更新时间
};

struct TcpServer_device
{
    int Infocount=0;
    QString deviceIP="";                            //设备客户端 IP
    QByteArray deviceQueryArray;
    QMap<QString,QByteArray>AnalysisArrayMap;       //设备客户端返回 数据 待处理缓存链表
    QMap<QByteArray,QByteArray>deviceActionArray;   //设备动作指令 缓存链表
    QMap<QString,QByteArray>deviceActionArray_;     //设备动作指令 缓存链表
};

struct slecetSAP_Log{//按照条件查询 数据库的 SAP任务、或者 操作日志

    int taskStatus_s=0;
    int taskStatus_e=0;

    int taskType=0;//任务类型  1出库  2入库 3盘点 4查仓 5改位入库
    int operaterIndex=0;
    QString ShelfBindesc="";

    QMap<QString,QString>labelNoMap;
    QMap<QString,QString>materialMap;

    QDateTime QDateTimeS;
    QDateTime QDateTimeE;
};

struct missionInfo{//任务信息
    int missionId;          //自动生成
    QString orderId;        //订单ID
    taskTypeEnum taskType;  //任务类型 出入库
    int manual=0;           //默认为0    手动下架 1
    QString materialNumber; //物料件号
    int pickStation;        //操作台ID
    double qty;             //订单里数量
    int shelfBinIndex;      //架位Bin
    int side;               //  A/B面
    QString operatorNumber; //操作员
    QString LabelNo;        //贴纸凭证号  （LabelNo+LabelItem    生产唯一凭证 ==打印的条形码）
    QString LabelItem;      //贴纸项目   （当LabelItem>基数上浮%20，分为两个工作，并分给不同工作台）
    QString labelType;      //贴纸类型
    QDateTime  createTime;  //创建时间
    int status;             //状态  -1读不到货架号
    int agvId;              //AGVID
    int errorType;          //错误类型
    double updateQty;       //errorType 不为空， 更新数量
    int updateShelfBin;     //更新 新的架位 Bin
    double priority;        //优先级
    int ikey;               //唯一标识

    QString user; // 此次操作员
    int markType=0;            //盘点类型  1当前Bin只盘点上传部分   2当前Bin 全部盘点 3AGV内部发起
    QString lastuser;//上次盘点操作员
};

struct helperInfo{
    int Iconstatus=0;//0 水平紧靠  1上下紧靠

    double font=40;
    double iconSize=50;
    double iconWidth=90;
    double iconHeight=70;
    double sizeScale=0.81;     //(水平紧靠: 1.1--1.0--0.81--0.73--0.66--0.60--0.58)--(上下紧靠: 0.81)
    double fontScale=0.95;     //(水平紧靠: 1.1--1.0--0.95--0.90--0.80--0.75--0.70)--(上下紧靠: 0.70)
    QList<QString> listColorBg;
    QList<QString> listColorBg1;
    QList<QString> listColorText;
    QList<QString> listText;
    QList<QChar>   listChar;
    QList<QToolButton *> btns;

};

//夹抱 AGV 动作基本任务
struct agvORderTask
{
    quint16 postureAngle=0x00;        //AGV基本任务 姿态角度
    quint16 AGVMoveAnage=0x0;         //AGV基本任务 移动角度
    quint16 AGVRotaryAngle=0x00;      //AGV基本任务 转盘角度
    quint16 comparePosition=0x00;     //精准定位 1  不精准定位0


    int AGVRack_Type=0;               //0 默认是从货架取放   1从小精灵上进行取放

    quint16 AGVRack=0x00;             //小车层数
    quint16 storageRack=0x00;         //货架层数
    quint16 actionORder=0x00;         //0x01 从货架上取   0x02从车上取
    quint16 actionDirection=0x00;     //货架在左边 0x01   在右边 0x02

};

struct LiftCode//电梯 类任务
{
    QString codeDesc="";         //升降机接驳台命名 2F-IN
    int Liftstatus=0;            //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
    QString codeType="";         //(IN- D100 D103 D105:1可放料,2-3去X楼)  ( OUT- D101 D102 D104: 1可取料,2取料完成)

    int status=0;                //任务锁定状态:0空闲  1 锁定  2到达 0空闲
    int SAPTaskIndex=0;          //任务索引 唯一值
    QString containerCode="";    //容器编码 (即胶箱编码) ->唯一

};

struct LiftTask//电梯任务
{
    int LiftID=0;                //电梯Id
    QString LiftIP="";           //电梯IP

    //        (1可放料)---(1可取料)    (1可取料)---(1可放料)    (1可取料)---(1可放料)
    //          D100       D101        D102       D103        D104       D105

    //        2F-3F-:2                          3F-2F-:2               4F-2F-:2
    //        2F-3F-:3                          3F-4F-:3               4F-3F-:3

    int LiftD100=0;         //2F-->IN
    int LiftD101=0;         //2F-->OUT

    int LiftD102=0;         //3F-->OUT
    int LiftD103=0;         //3F-->IN

    int LiftD104=0;         //4F-->OUT
    int LiftD105=0;         //4F-->IN

};

struct AGVTWaitTask//等待处理任务
{
     int SAPTaskIndex=0;            //任务索引 唯一值
     int floornum=0;                //任务楼层
     QString containerCode="";      //容器编码 (即胶箱编码) ->唯一
     int destpoint=0;
     int Nextdestpoint=0;

     QString EmptycageID="";
     int EmptyCagePoint=0;
     int FullCagePoint=0;

     int taskStatus=0;
     QString complete="";   //完成只做历史纪录
};

struct AGVMoveTask_sig         //AGV任务动作
{
    QString AGVIP="";
    quint32 StartQRPoint=0;
    quint32 EndQRPoint=0;
    int AGVAction=0;
    int tye=0;
    agvORderTask agvORderTaskI;
};

struct AGVCurrentTask          //AGV任务动作
{
    int AGVId=0;                //小车编号
    QString AGVIP="";           //小车 ip
    int enable=0;               //1使用  0禁用
    int AGVType=0;              //AGV类型    0默认小精灵   1夹抱AGV
    int floornum=0;             //AGV所在楼层
    int waitPoint=0;            //待机点二维码

    bool taskisok=false;        //AGV 初始化完成 且 无任务错误代码
    int Currentpointcount=0;    //计数
    int waitpointcount=0;       //等待计数
    int resetpointcount=0;      //动作重新执行计数

    int Currentpoint=0;         //当前所在二维码
    int VoltageState=0;         //当前电压或电量
    int RunStatus=2;            //当前运行状态  1 运行 2 停止
    int RotaryState=0;          //当前转盘高度 mm

    int Currentdestpoint=0;     //当前目标二维码
    int destpoint=0;            //第一个目标二维码
    int Nextdestpoint=0;        //下一个目标二维码
    int waitdestpoint=0;        //目标点等待点二维码

    int Action_agv=0;           //二维码带举升动作
    int Action_ess=0;           //夹包机器人
    int Action_all=0;           //总动作计数

    int actionType=0;           //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
    int actionTimerCount=15;    //倒计时 计数
    QDateTime actionTimer;      //倒计时 默认15秒

    QString taskId="";          //唯一识别号
    QString lastTaskId="";      //上一个任务--唯一识别号
    QString taskType="";        //任务类型 IN入库  OUT出库
    int SAPTaskIndex=0;         //任务索引 唯一值
    QString containerCode="";   //容器编码 (即胶箱编码) ->唯一

    QString obligate1="";       //预留
    QString obligate2="";       //预留
    QString obligate3="";       //预留
    QString obligate4="";       //预留
    QString obligate5="";       //预留

    SAPExcelInfo SAPExcelInfoI;         //绑定SAP任务
    AGVMoveTask_sig AGVMoveTask_sigI;   //上一个动作指令

    //是否执行充电任务(0无充电任务，1锁定充电,2完成任务后前往充电桩等待点, 3前往充电点，
    //4到达充电点并打开充电回路以及伸出充电桩,5充电进行中,并开始计时, 6 计时时间到结束充电 ,7前往充电等待点，8到达充电等待点 释放充电状态
    //10充电异常,收回充电桩, 11 前往充电等待点, 重新执行3操作

    QString chargeIP="";        //充电桩IP
    int ChargePoint=0;          //充电点二维码
    int ChargeWait=0;           //充电点前一个二维码
    int MoveAnage=0;            //小车进出充电位置 姿态以及移动角度

    int ChargeAction=0;         //充电动作指令
    int ChargeTimer=0;          //充电计时 还剩余多少 分钟  60 *60 =3600秒
    QDateTime ChargeTimer_;      //倒计时 默认15秒

    int ChargeAction_all=0;     //总的充电动作逻辑

    int checked=0;              //1选择 0取消
    int row=0;                  //显示在第几行
};

struct sapPath{
   int  Id;
   QString Path;
   QString funcation;
   QString para1;
   QString para2;
   QString para3;

   QString Type;        //路径类型 发料时根据类型 选择路径
   QString PathName;
};


//AGVInfo
struct AgvState//AGV状态
{

};


class Instance : public QObject
{
    Q_OBJECT

public:
    static Instance *GetInstance();

    explicit Instance(QObject *parent = 0);

    void SetButtonList(QList<QPushButton *>btns,QString Buttontext);    //设置按钮点击时样式变化
    void SetButton_pressed(QPushButton *Button,QString Style);          //设置按钮按下设置
    void SetButton_released(QPushButton *Button,QString Style);         //设置按钮松开设置

    bool SetMessagebox(QString Messagetext);

    void LblMovieStatusInit();                                    //gif 动图显示提示框

    void setLblMovieStatus(int status);                           //0 隐藏后台正在处理中 1 显示后台正在处理中

    bool getLblMovieStatus();                                     //0 隐藏后台正在处理中 1 显示后台正在处理中
public:
    QString currentlogtext="";
    void setqDebug_log(QString logtext);
    QString getqDebug_log();

public:
    static QMutex mutex;
    static Instance* instanceItiem;

    QLabel *lbl_gif;
    QLabel *lbl_gif1;
    QWidget *lbl_Widget;
};

#endif // INSTANCE_H
