#include "agvcarpool.h"
#include <QDebug>
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)


agvCarPool *agvCarPool::pThis = nullptr;
QMutex *agvCarPool::getInstanceMutex = new QMutex(QMutex::Recursive);

agvCarPool::agvCarPool()
{
    pThis = this;
    addAGVTaskTimer.start(800);
    sendAGVTaskTimer.start(500);
    readAGVTaskTimer.start(300);
    initAgvFloorMap();
    connect(this,&agvCarPool::AGVMoveTask,this,&agvCarPool::onAGVMoveTask);

}

agvCarPool::~agvCarPool()
{

}

//获取agvCarPool实例
agvCarPool *agvCarPool::getInstance()
{
    QMutexLocker locker(getInstanceMutex);
    if(pThis == nullptr)
    {
        pThis = new agvCarPool();
    }
    return pThis;
}

//读取每个楼层的AGV并创建
void agvCarPool::initAgvFloorMap()
{ 
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from AGVCurrentTask;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            if(sqlQuery.value("enable").toInt() == 1)
            {
                agvCar *agvCarItem = new agvCar;
                QThread *threadItem = new QThread();
                agvCarItem->moveToThread(threadItem);
                connect(threadItem,SIGNAL(finished()),agvCarItem,SLOT(deleteLater()));
                threadItem->start();

                connect(&addAGVTaskTimer,SIGNAL(timeout()),agvCarItem,SLOT(onAddAGVTaskTimerOut()));
                connect(&sendAGVTaskTimer,SIGNAL(timeout()),agvCarItem,SLOT(onSendAGVTaskTimerOut()));
                connect(&readAGVTaskTimer,SIGNAL(timeout()),agvCarItem,SLOT(onReadAGVTaskTimerOut()));

                connect(agvCarItem,&agvCar::AgvStateWidget,this,&agvCarPool::AgvStateWidget);
                connect(agvCarItem,&agvCar::sigDoorSubTaskAction,this,&agvCarPool::sigDoorSubTaskAction);
                connect(agvCarItem,&agvCar::TaskmoveListProcess,this,&agvCarPool::ON_TaskmoveListProcess);

                agvCarItem->pathMapInit();
                agvCarItem->sendInitializeCommand(1004);       //发送AGV初始化命令 槽函数

                agvCarMap.insert(agvCarItem,sqlQuery.value("AGVIP").toString());
                agvThreadMap.insert(threadItem,sqlQuery.value("AGVIP").toString());
                agvCarItem->agvIp = sqlQuery.value("AGVIP").toString();
                agvCarItem->agvStateItem.AGVWaitQRPoint = sqlQuery.value("waitPoint").toUInt();

                qDebug()<<agvCarItem->agvIp<<agvCarItem->agvStateItem.AGVWaitQRPoint<<"读取每个楼层的AGV并创建"
                      <<" commandNo:" <<agvCarItem->commandNo;
            }
        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from doorSubTask;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            doorSubTask doorSubTaskI;
            doorSubTaskI.doorId=sqlQuery.value("Id").toInt();
            doorSubTaskI.doorIP=sqlQuery.value("doorIP").toString();            //自动门IP
            doorSubTaskI.doorDesc=sqlQuery.value("doorDesc").toString();
            doorSubTaskI.Point=sqlQuery.value("Point").toInt();         //起始点  用于开门
            doorSubTaskI.NextPoint=sqlQuery.value("NextPoint").toInt(); //下一点  用于开门
            doorSubTaskI.door_acionI.Point=doorSubTaskI.Point;
            doorSubTaskI.door_acionI.NextPoint=doorSubTaskI.NextPoint;

            doorSubTaskI.NextPointdesc=sqlQuery.value("NextPointdesc").toString();  //保持开门信号二维码链表
            QStringList NextPointList=doorSubTaskI.NextPointdesc.split("&");       //保持开门信号二维码链表
            for(int i=0;i<NextPointList.size();i++){
                doorSubTaskI.NextPointList.append(NextPointList[i].toInt());
                doorSubTaskI.door_acionI.NextPointList.append(NextPointList[i].toInt());
            }

            doorSubTaskI.enable=sqlQuery.value("enable").toInt();
            doorSubTaskI.page=sqlQuery.value("page").toInt();

            //doorSubTaskI.NextPointdesc= doorSubTaskI.NextPointList.join("&");
            if(!doorSubTaskMap.contains(doorSubTaskI.doorId) && doorSubTaskI.doorIP!=""){
                doorSubTaskMap.insert(doorSubTaskI.doorId,doorSubTaskI);
//                qDebug()<<" doorSubTaskI:"<<doorSubTaskI.deviceIP<<" Point:"<<doorSubTaskI.door_acionI.Point<<" NextPoint:"<<doorSubTaskI.door_acionI.NextPoint
//                       <<doorSubTaskI.door_acionI.NextPointList.size();
            }

        }
    }

}

//释放已掉线的AGV通信Socket
void agvCarPool::onAgvCarSocketDeleteLater()
{
    agvCarSocket *agvCarSocketTemp = (agvCarSocket *)this->sender();
    if(agvCarSocketTemp != nullptr)
    {
        disconnect(agvCarSocketTemp,SIGNAL(disconnected()),this,SLOT(onAgvCarSocketDeleteLater()));
        agvCarSocketMap.value(agvCarSocketTemp)->agvCarSocketItemMap.remove(agvCarSocketTemp);
        agvCarSocketMap.remove(agvCarSocketTemp);
        agvCarSocketTemp->deleteLater();
    }
}

//发布AGV任务
void agvCarPool::onAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int tye,agvORderTask agvORderTaskI)
{
    qDebug()<<"onAGVMoveTask:"<<AGVIP<<" StartQRPoint:"<<StartQRPoint<<" EndQRPoint:"<<EndQRPoint<<" AGVAction:"<<AGVAction;
    if(!agvCarMap.isEmpty()){
        agvCar *agvCarTemp = agvCarMap.key(AGVIP);
        if(agvCarTemp != nullptr){
            agvCarTemp->AGVMoveTask(StartQRPoint,EndQRPoint,AGVAction,tye,agvORderTaskI);
        }
    }

}

void agvCarPool::ON_AGVChargeTask(QString AGVIP, quint16 opendcharge)
{
    if(!agvCarMap.isEmpty()){
        agvCar *agvCarTemp = agvCarMap.key(AGVIP);
        if(agvCarTemp != nullptr){
            agvCarTemp->AGVChargeTask(AGVIP,opendcharge);
        }
    }
}

//实时触发 移动任务指令  判断当前二维码移动指令是否可以执行
void agvCarPool::ON_TaskmoveListProcess(QString AGVIP, QMap<int,agvSubTask> TaskmoveList, agvState agvStateItem,int Initaction)
{
    agvCar *agvCarTemp = agvCarMap.key(AGVIP);
    if(agvCarTemp != nullptr){

        //AGV子任务列表 当前 未执行 的二维码任务链表
        int passPointState=agvStateItem.passPointState.toInt();               //AGV上次读到的二维码点
        if(!doorSubTaskMap.isEmpty() && doorSubTaskbool){
            doorSubTaskbool=false;
            QMap <int,doorSubTask>::iterator iter_= doorSubTaskMap.begin();//自动门开门信号
            while (iter_!=doorSubTaskMap.end()){

                if(agvStateItem.agvFinishInit && (agvStateItem.CurrentDestpoint==0 || Initaction==0)){
                    if(agvStateItem.agvIp==iter_.value().AGVIP && iter_.value().AGVIP !=""){
                        iter_.value().Point=0;
                        iter_.value().AGVIP="";
                        iter_.value().orderAction=0;
                        iter_.value().NextPointList.clear();
                        doorSubTaskbool=true;
                        agvCarTemp->Taskmove_Processbool=true;

                        emit sigDoorSubTaskAction(iter_.value().doorIP,2,iter_.value().AGVIP);
                        qDebug()<<iter_.value().doorIP<<"AGV 数据清除 自动门空闲";
                    }
                }

                if(agvStateItem.agvIp==iter_.value().AGVIP && iter_.value().AGVIP !=""){
//                    qDebug()<<iter_.value().AGVIP<<agvStateItem.agvIp<<" 当前二维码:"<<passPointState<<" 开门点:"<<iter_.value().Point<<" doorPoint:"<<agvStateItem.doorPoint
//                           <<" action:"<<iter_.value().action<<" DeviceStatus:"<<iter_.value().DeviceStatus
//                          <<" device_Line:"<<iter_.value().device_Line;

                    if(passPointState==iter_.value().Point
                         && (iter_.value().orderAction==0 || iter_.value().orderAction==1)){
                        if(iter_.value().door_status==1 && iter_.value().door_Line==1){
                            doorSubTaskbool=false;
                            iter_.value().orderAction=1;
                            emit sigDoorSubTaskAction(iter_.value().doorIP,1,iter_.value().AGVIP);
                            qDebug()<<iter_.value().doorIP<<passPointState<<"提交开门信号 0-->AGVIP"<<AGVIP;
                        }else{
                            doorSubTaskbool=true;
                            emit sigDoorSubTaskAction(iter_.value().doorIP,1,iter_.value().AGVIP);
                            qDebug()<<iter_.value().doorIP<<passPointState<<"提交开门信号 1-->AGVIP"<<AGVIP;
                        }
                    }

                    //开门到位前往目标二维码
                    if(passPointState==iter_.value().Point  && iter_.value().door_status==1
                            && iter_.value().door_Line==1 && iter_.value().orderAction==1){
                        iter_.value().orderAction=2;
                        agvCarTemp->Device_door_Action(iter_.value().doorIP,1,0);
                        emit sigDoorSubTaskAction(iter_.value().doorIP,1,iter_.value().AGVIP);
                        qDebug()<<iter_.value().doorIP<<"开门到位";
                        //doorSubTaskbool=true;
                    }

                    if(!iter_.value().NextPointList.contains(int(passPointState))
                             && iter_.value().door_status==1 && passPointState!=0
                            && iter_.value().orderAction==2){
                        emit sigDoorSubTaskAction(iter_.value().doorIP,2,iter_.value().AGVIP);
                        qDebug()<<iter_.value().doorIP<<"提交关门信号"<<passPointState<<" taskType:"<<agvStateItem.taskType
                               <<"size:"<<iter_.value().NextPointList.size();

                    }if(!iter_.value().NextPointList.contains(int(passPointState))
                            && (iter_.value().door_Line==0 || iter_.value().door_status==0)
                            && passPointState!=0  && iter_.value().orderAction==2){  //起始点
                        iter_.value().orderAction=0;
                        iter_.value().Point=0;
                        iter_.value().AGVIP="";
                        iter_.value().NextPointList.clear();
                        emit sigDoorSubTaskAction(iter_.value().doorIP,2,iter_.value().AGVIP);
                        qDebug()<<iter_.value().doorIP<<"关门到位 自动门空闲";
                        doorSubTaskbool=true;
                        agvCarTemp->Taskmove_Processbool=true;
                        return;
                    }

                }

                iter_++;
            }

            doorSubTaskbool=true;
        }

        doorSubTask doorSubTaskI=getdoorSubTask(AGVIP,TaskmoveList,agvStateItem);
        if(doorSubTaskI.AGVIP!=""){//判断是否存在开门点
            TaskmoveList.clear();
            agvCarTemp->Device_door_Action(doorSubTaskI.doorIP,0,doorSubTaskI.Point);
            qDebug()<<doorSubTaskI.doorIP<<"确认开门点-->AGVIP"<<AGVIP<<" 开门点:"<<doorSubTaskI.Point;
            return;
        }

        if(!TaskmoveList.isEmpty()){
            qDebug()<<AGVIP<<"TaskmoveList:"<<TaskmoveList.size();
            agvCarTemp->TaskmoveList_Process_(TaskmoveList);
        }else{
            TaskmoveList.clear();
            agvCarTemp->TaskmoveList_Process_(TaskmoveList);
        }
    }else {
        qDebug()<<AGVIP<<"异常";
    }

}

void agvCarPool::ON_Device_door_Status(QString DeviceIP, int online, int DeviceStatus)
{
    if(!doorSubTaskMap.isEmpty() && doorSubTaskbool){
        QMap <int,doorSubTask>::iterator iter= doorSubTaskMap.begin();                 //自动门开门信号
        while (iter!=doorSubTaskMap.end()){
            if(iter.value().doorIP==DeviceIP){
                iter.value().door_Line=online;            //是否在线
                if(iter.value().door_status!=DeviceStatus){
                    iter.value().door_status=DeviceStatus;    //0关门  1开门
                    if(iter.value().AGVIP!=""){
                        qDebug()<<DeviceIP<<" Status:"<<DeviceStatus<<" 自动门状态变化 AGV小车:"<<iter.value().AGVIP;
                    }
                }
            }
            iter++;
        }
    }
}

doorSubTask agvCarPool::getdoorSubTask(QString AGVIP, QMap<int, agvSubTask> TaskmoveList,agvState agvStateItem)
{
    doorSubTask doorSubTaskI;
    QMap<int,agvSubTask>::const_iterator iter1 =TaskmoveList.begin();
    while (iter1!=TaskmoveList.end()){
        QMap <int,doorSubTask>::iterator iter_= doorSubTaskMap.begin();//自动门开门信号
        while (iter_!=doorSubTaskMap.end()){
             if(iter_.value().AGVIP==""  || (iter_.value().AGVIP== agvStateItem.agvIp && agvStateItem.doorPoint!=0)){
                if(iter_.value().door_acionI.Point==int(iter1.value().Point)
                        && iter_.value().door_acionI.NextPoint == int(iter1.value().NextPoint)){
                    iter_.value().AGVIP=AGVIP;
                    iter_.value().Point=iter_.value().door_acionI.Point;                //起始点  用于开门
                    iter_.value().NextPointList=iter_.value().door_acionI.NextPointList;//保持开门信号二维码链表
                    qDebug()<<iter_.value().doorIP<<"确认开门点-->AGVIP"<<AGVIP<<" 开门点:"<<iter_.value().Point;
                    return iter_.value();
                }
            }

            iter_++;
        }
        iter1++;
    }
    return doorSubTaskI;
}

//获取新的Socket连接
void agvCarPool::incomingConnection(qintptr newAgvCar)
{
    agvCarSocket *agvCarSocketItem = new agvCarSocket();
    agvCarSocketItem->setSocketDescriptor(newAgvCar);
    QHostAddress peerAddress(agvCarSocketItem->peerAddress().toIPv4Address());

    agvCar *agvCarItem = agvCarMap.key(peerAddress.toString());
    if(agvCarItem==nullptr){
        qDebug()<<"agvCarSocket 连接异常 "<<peerAddress.toString();return;
    }
    QThread *threadItem = agvThreadMap.key(peerAddress.toString());
    qDebug()<<agvCarItem->agvIp<<" 获取新的 Socket连接 AGV";
    if((agvCarItem != nullptr) && (threadItem != nullptr))
    {
        for(int i=0;i<agvCarItem->agvCarSocketItemMap.keys(true).size();i++)
        {
            disconnect(agvCarItem->agvCarSocketItemMap.keys(true).at(i),SIGNAL(readyRead()),agvCarItem,SLOT(onReadyRead()));
            agvCarItem->agvCarSocketItemMap.insert(agvCarItem->agvCarSocketItemMap.keys(true).at(i),false);
        }

        agvCarItem->agvCarSocketItemMap.insert(agvCarSocketItem,true);
        agvCarSocketMap.insert(agvCarSocketItem,agvCarItem);
        qDebug()<<agvCarItem->agvIp<<"agvCarSocketMap.insert";

        agvCarSocketItem->moveToThread(threadItem);
        connect(agvCarSocketItem,SIGNAL(readyRead()),agvCarItem,SLOT(onReadyRead()));
        connect(agvCarSocketItem,SIGNAL(disconnected()),this,SLOT(onAgvCarSocketDeleteLater()));
        connect(threadItem,SIGNAL(finished()),agvCarSocketItem,SLOT(deleteLater()));

    }

}
