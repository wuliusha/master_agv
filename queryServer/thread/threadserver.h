#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QObject>
#include "taskmanager/ess_single.h"
#include "queryServer/queryserver.h"
#include "comm/datebaseConnectPool/connectpoolfactory.h"


class threadServer : public QObject
{
    Q_OBJECT
public:
    explicit threadServer(QObject *parent = nullptr);
public:
    int threadServercount=0;
    QTimer *threadTimer;bool Servercountbool=true;

public slots:
    void threadServerTimer();

public:

    //以 status 定时查询未完成的任务
    QMap<int, SAPExcelInfo> readSAPExcelInfoTask(int taskstatus,QString taskType);

    bool allSeverInit();             //所有基础信息  均初始化完成
    void setSapPathMap();            //读取数据库的路径配置信息
    void UserInfoListInit();         //获取登录用户信息
    void shelfBinInfoMapInit();      //实时获取 Bin 的基础信息
    void StationInfoMapMapInit();    //所有站点的基础信息
    void automaticDoorMapInit();     //所有自动门的基础信息
    void AGVTCurrentTask_Init();     //AGV任务动作

    void LiftTaskInit();            //获取升降机的任务信息

    void taskStatusMapInit();        //任务状态的错误码与译文
    void errorTypeMapInit();         //任务状态的错误码与译文
    void StationCodeMapInit();       //工作站与 ESS-P坐标点
    void eventCodeMapInit();         //ESS-P 事件 回调类型


signals:

public slots:

private:

    ServerInit ServerInitItem;      //基础信息

    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

};

#endif // THREADSERVER_H
