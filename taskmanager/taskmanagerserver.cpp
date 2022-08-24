#include "taskmanagerserver.h"

taskManagerServer::taskManagerServer(QObject *parent) : QObject(parent)
{

    qRegisterMetaType<QMap<QString,LiftCode>>("QMap<QString,LiftCode>");
    qRegisterMetaType<QMap<QString,AGVCurrentTask*>>("QMap<QString,AGVCurrentTask*>");

    taskManagerServerInit();

    StTimer = new QTimer(this);
    connect(StTimer,&QTimer::timeout,this,&taskManagerServer::taskManagerServerTimer);
    StTimer->start(800);

}

void taskManagerServer::taskManagerServerInit()
{

    ThreadInsertI=new ThreadInsert;
    ThreadInsertItiem=new QThread();
    ThreadInsertI->moveToThread(ThreadInsertItiem);
    ThreadInsertItiem->start();

    threadQueryI=new threadQuery;
    threadQueryItem=new QThread();
    threadQueryI->moveToThread(threadQueryItem);
    threadQueryItem->start();

    server=new HttpServer;
    if(!server->listen(QHostAddress::Any,20001)){
        qDebug()<<"启动服务器失败 taskManager 20001";
        exit(-1);
    }
    connect(server,&HttpServer::sig_SAPExcelInfo_new,this,&taskManagerServer::ON_SAPExcelInfo_new);
    connect(server,&HttpServer::sig_SAPExcelInfoList_new,this,&taskManagerServer::ON_SAPExcelInfoList_new);

    server_=new HttpServer;//ESS 专用
    if(!server_->listen(QHostAddress::Any,58898)){
        qDebug()<<"启动服务器失败 taskManager 58898";
        exit(-1);
    }

    //ESS 任务状态对应 SAP任务状态
    taskCodeInfoMap.insert("PENDING",0);
    taskCodeInfoMap.insert("PROCESSING",1);
    taskCodeInfoMap.insert("SUSPEND",2);
    taskCodeInfoMap.insert("FINISHED",100);
    taskCodeInfoMap.insert("CANCELLED",101);
    taskCodeInfoMap.insert("FAILED",102);

}

bool taskManagerServer::taskProcessTimer()
{
    ESS_Request ESS_RequestI;
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {
        if(iter.value().taskId!=nullptr){
            int startfloor=0;
            int destfloor=0;
            if(iter.value().floorId.size()>=2){
                startfloor=iter.value().floorId.left(1).toInt();
                destfloor=iter.value().floorId.right(1).toInt();
            }

            if(iter.value().taskType!="Empty"){//任务类型: OUT MOVE  IN
                if(iter.value().taskStatus==0){//开始创建 ESS 任务
                    bool Request=true;
                    if(iter.value().taskType=="OUT"){
                        ESS_RequestI.actionId="action2";
                        deviceI deviceItem= getStationInfo_Empty("OUT"); //获取 空闲的接驳台 状态信息
                        if(deviceItem.deviceDesc!=""){
                            iter.value().pickDesc_s=deviceItem.deviceDesc;
                        }else{
                            Request=false;
                        }
                    }if(iter.value().taskType=="MOVE"){
                        ESS_RequestI.actionId="action3";
                    }if(iter.value().taskType=="IN"){
                        ESS_RequestI.actionId="action4";      
                    }

                    if(Request){//允许下发给 ESS
                        iter.value().taskStatus++;
                        iter.value().taskStatusbool=false;//状态变化时， false不需要保存到数据库
                        iter.value().taskId_ess="taskCode-"+QString::number(iter.value().SAPTaskIndex)+"-"+QDateTime::currentDateTime().toString("zzz");
                        ESS_RequestI.containerCode=iter.value().containerCode;
                        ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                        if(ESS_RequestI.pathId!=0){
                            sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,ESS_RequestI.actionId,ESS_RequestI.pathId);
                            qDebug()<<"-->开始创建 ESS 任务  actionId:"<<ESS_RequestI.actionId<<"taskType:"<<iter.value().taskType<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                        }
                        return true;
                    }
                }

                if(iter.value().taskStatus==taskStatus_delete_){
                    iter.value().taskStatus++;
                    iter.value().taskStatusbool=false;//状态变化时， false不需要保存到数据库

                    ESS_Request ESS_RequestI;
                    ESS_RequestI.actionId="action7";
                    ESS_RequestI.positionCode=iter.value().pickDesc_s;
                    ESS_RequestI.containerCode=iter.value().containerCode;
                    iter.value().taskId_ess=iter.value().taskId_ess+"_d";
                    ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                    if(ESS_RequestI.pathId!=0){
                        sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action7",ESS_RequestI.pathId);
                        qDebug()<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex<<" 删除任务,解绑对接码头:"<<iter.value().pickDesc_s<<"containerCode"<<iter.value().containerCode;
                    }
                    return true;
                }

            }

            /**************** 入库部分部分 **************/
            if(iter.value().taskType=="IN"){
                 //实时检查入库端 容器是否到位
                 //status状态 0无料框  1有料框; taskStatus 任务状态  0空闲  1占用  2正在执行  3执行完成  0空闲
                 if(iter.value().taskStatus==2){
                     deviceI deviceItem= getStationInfo_Empty(iter.value().sourcestation);
                     if(deviceItem.status==1 && deviceItem.SAPTaskIndex==iter.value().SAPTaskIndex){
                         iter.value().taskStatus=3;//容器到位
                         qDebug()<<"实时检查入库端 容器是否到位:"<<iter.value().sourcestation<<deviceItem.deviceDesc;
                     }
                 }

                 //给ESS 下发 容器到位信号
                 if(iter.value().taskStatus==3){
                     iter.value().taskStatus=4;
                     ESS_RequestI.actionId="action6";
                     ESS_RequestI.positionCode=iter.value().pickDesc_s;
                     ESS_RequestI.containerCode=iter.value().containerCode;
                     ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                     if(ESS_RequestI.pathId!=0){
                         sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action6",ESS_RequestI.pathId);
                         qDebug()<<"-->给ESS 下发 容器到位信号 actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                     }
                     return true;
                 }

                 //给ESS 下发 容器到位信号
                 if(iter.value().taskStatus==taskTake_ess){
                    iter.value().taskStatus=7;
                    iter.value().taskStatusDesc="等待入库";
                    deviceI deviceItem= getStationInfo_Empty(iter.value().sourcestation);
                    if(iter.value().SAPTaskIndex!=deviceItem.SAPTaskIndex){
                        SAPTaskIndex_send=deviceItem.SAPTaskIndex;          //入库码头错位取货时  需先发容器离场，再发容器入场
                        qDebug()<<"入库码头错位取货时  需先发容器离场，再发容器入场 device -->SAPTaskIndex:"<<SAPTaskIndex_send
                               <<" task-->SAPTaskIndex:"<<iter.value().SAPTaskIndex;
                    }
                 }

                 if(SAPTaskIndex_send>0 && iter.value().SAPTaskIndex==SAPTaskIndex_send){
                     SAPTaskIndex_send=0;
                     iter.value().taskStatus=taskTake_send;

                 }if(iter.value().taskStatus==taskTake_send){
                     iter.value().taskStatus++;
                     iter.value().taskStatusbool=false;//状态变化时， false不需要保存到数据库

                     ESS_Request ESS_RequestI;
                     ESS_RequestI.actionId="action7";
                     ESS_RequestI.positionCode=iter.value().pickDesc_s;
                     ESS_RequestI.containerCode=iter.value().containerCode;
                     iter.value().taskId_ess=iter.value().taskId_ess+"_s";
                     ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                     if(ESS_RequestI.pathId!=0){
                         sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action7",ESS_RequestI.pathId);
                         qDebug()<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex<<"入库码头错位取货时 解绑对接码头:"<<iter.value().pickDesc_s<<"containerCode"<<iter.value().containerCode;
                     }
                     return true;

                 }if(iter.value().taskStatus==taskTake_send_){
                    iter.value().taskStatus=2;//
                    qDebug()<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex<<"再次等待容器入场 :"<<iter.value().pickDesc_s<<"containerCode"<<iter.value().containerCode;
                 }

            }

            /**************** 出库任务/返空料框 电梯流程部分 **************/
            //判断升降机 进料口 是否允许放料
            if((iter.value().taskType=="OUT" && iter.value().taskStatus==taskFnish_ess)
                    || (iter.value().taskType=="Empty" && iter.value().taskStatus==0)){
                if(getLiftCodeMap(QString::number(startfloor)+"F-IN",1,iter.value())){ //判断 2F-IN 是否允许放料
                    iter.value().taskStatus=10;             //进入电梯流程
                    qDebug()<<"进入电梯流程"<<iter.value().SAPTaskIndex<<iter.value().taskStatusDesc;
                }
            }

            //等待起始楼层AGV执行
            if(iter.value().taskType!="IN" && iter.value().taskStatus==10){
                SAPExcelInfo SAPExcelInfoI=iter.value();
                SAPExcelInfoI.taskId_agv="agv"+QDateTime::currentDateTime().toString("ddhhmmss");
                QString AGVIP=setAGVTCurrentTask(SAPExcelInfoI,startfloor,SAPExcelInfoI.pickDesc_s,"");        //出库时 创建AGV配送任务
                qDebug()<<"获取起始楼层AGV--->AGVIP"<<AGVIP<<iter.value().SAPTaskIndex<<startfloor<<SAPExcelInfoI.pickDesc_s;
                if(AGVIP!=""){
                    iter.value().AGVIP=AGVIP;
                    iter.value().taskStatus=11;
                    iter.value().taskId_agv=SAPExcelInfoI.taskId_agv;
                }
            }

            //判断起始楼层 AGV  是否完成取货
            if(iter.value().taskType!="IN" && iter.value().taskStatus==11){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()>3){
                        if(iter.value().taskType=="OUT"){
                            iter.value().taskStatus=12;//容器离场
                        }else{
                            iter.value().taskStatus=14;
                        }
                    }
                }
            }

            //给ESS 下发容器离场
            if(iter.value().taskType=="OUT" && iter.value().taskStatus==12){
                iter.value().taskStatus=13;                                 //13 给ESS 下发容器离场

                //设置并更新接驳台状态信息
                if(iter.value().taskType=="OUT"){
                    ESS_RequestI.actionId="action7";//出库时  给ESS 发容器离场
                    ESS_RequestI.positionCode=iter.value().pickDesc_s;
                    ESS_RequestI.containerCode=iter.value().containerCode;
                    ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                    if(ESS_RequestI.pathId!=0){
                        sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action7",ESS_RequestI.pathId);
                        qDebug()<<"-->容器离场 actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                    }
                    return true;
                }
            }

            //判断起始楼层 AGV 是否到达电梯接驳台
            if(iter.value().taskType!="IN" && iter.value().taskStatus==14){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    qDebug()<<"AGV 到达起始电梯接驳台  --->taskId_agv:"<<iter.value().taskId_agv<<" taskStatus:"<<iter.value().taskStatus<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()==taskFnish){//状态==taskFnish 则此次运输任务完成
                        taskId_AGVStatusMap.remove(iter.value().taskId_agv);//SAP与AGV 任务状态绑定
                        iter.value().taskStatus=15;//到达电梯接驳台
                        getLiftCodeMap(QString::number(startfloor)+"F-IN",2,iter.value());//料框到达: 2F-IN
                        return true;
                    }
                }
            }

            //判断 目标楼层 F-OUT 是否允许放料
            if(iter.value().taskType!="IN" && iter.value().taskStatus==15
                    && (LiftOccupy==0 || LiftOccupy==iter.value().SAPTaskIndex)){
                if(getLiftCodeMap(QString::number(destfloor)+"F-OUT",1,iter.value())){
                    iter.value().taskStatus=16;             //前往目标楼层
                    LiftOccupy=iter.value().SAPTaskIndex;

                    //升降机的动作指令---单个
                    emit sigsetLiftactionArray(LiftTaskI,startfloor,destfloor);
                    qDebug()<<" 前往目标楼层 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                          <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    return true;
                }
            }

            //任务已到达目标楼层 释放占用标识
            if(iter.value().taskStatus>=17 && LiftOccupy==iter.value().SAPTaskIndex){
                LiftOccupy=0;
            }

            //读取目标楼层电梯状态，判断是否可以取货
            if(iter.value().taskType!="IN" && iter.value().taskStatus==16){
                if(getLiftCodeMap(QString::number(destfloor)+"F-OUT",2,iter.value())){
                    iter.value().taskStatus=17;//等待目标楼层AGV执行
                    qDebug()<<" 等待目标楼层AGV执行 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                          <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    return true;
                }
            }

            //等待目标楼层AGV执行
            if(iter.value().taskType!="IN" && iter.value().taskStatus==17){
                deviceI deviceItem= getStationInfo_Empty(iter.value().destination); //获取接驳台状态信息
                qDebug()<<" 判断目标站点状态信息 destination:"<<iter.value().destination<<deviceItem.deviceDesc <<deviceItem.onLine<<deviceItem.status;
                if(deviceItem.deviceDesc!="" && deviceItem.onLine==1 && deviceItem.status==0){     //状态 0无料框  1有料框
                    SAPExcelInfo SAPExcelInfoI=iter.value();
                    SAPExcelInfoI.taskId_agv="agv"+QDateTime::currentDateTime().toString("ddhhmmss");
                    QString AGVIP=setAGVTCurrentTask(SAPExcelInfoI,destfloor,"",SAPExcelInfoI.destination);        //出库时 创建AGV配送任务
                    qDebug()<<"获取目标楼层AGV--->AGVIP"<<AGVIP<<iter.value().SAPTaskIndex<<destfloor<<SAPExcelInfoI.pickDesc_e;
                    if(AGVIP!=""){
                        iter.value().AGVIP=AGVIP;
                        iter.value().taskStatus=18;
                        iter.value().taskId_agv=SAPExcelInfoI.taskId_agv;
                        qDebug()<<" 目标楼层AGV执行 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                               <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                        return true;
                    }
                }else{
                    //qDebug()<<"目标站点异常无法前往:--->"<<iter.value().destination<<" online:"<<StationInfoI.online<<" status:"<<StationInfoI.status;
                }
            }

            if(iter.value().taskType!="IN" && iter.value().taskStatus==18){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()>3){        //离开目标电梯 取货点
                        iter.value().taskStatus=19;                                         //离开目标电梯 取货点
                        getLiftCodeMap(QString::number(destfloor)+"F-OUT",3,iter.value());  //料框离开电梯
                        qDebug()<<" 离开目标电梯前往目标站点--> SAPTaskIndex:"<<iter.value().SAPTaskIndex
                              <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    }
                }
            }

            //判断目标楼层AGV 执行 状态
            if(iter.value().taskType!="IN" && iter.value().taskStatus==19){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()==taskFnish){//状态==100 则此次运输任务完成
                        taskId_AGVStatusMap.remove(iter.value().taskId_agv);//SAP与AGV 任务状态绑定
                        iter.value().taskStatus=taskFnish;//任务完成
                        //清除当前升降机任务信息
                        LiftCodeStatus_clear(iter.value().SAPTaskIndex);
                        qDebug()<<" 目标楼层AGV任务完成  SAPTaskIndex:"<<iter.value().SAPTaskIndex
                              <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    }
                }
            }
        }else {
            qDebug()<<"QMap_ 数组指针越界，执行失败--taskProcessTimer"<<iter.value().containerCode;
           return true;
        }
        ++iter;
    }

    return true;
}

bool taskManagerServer::ProcessMsgRecv()
{
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {
        if(iter.value().taskId!=nullptr){
            ReplyMsg ReplyMsgI=sapMsgInterface::getInstance()->GetMsgRecv_Msg(iter.value().taskId_ess);
            if(ReplyMsgI.keyId!=""){
                if(ReplyMsgI.status==0){
                    if(iter.value().taskStatus>taskStatus_delete_){
                        iter.value().taskStatus=taskFnish;
                    }else{
                        iter.value().taskStatus=iter.value().taskStatus+1;
                    }
                    iter.value().taskStatusbool=true;//状态变化时， false不需要保存到数据库
                }else{
                    if(iter.value().taskStatus>=taskStatus_delete_){
                        iter.value().taskStatus=taskFnish;
                    }else{
                        iter.value().taskStatus=iter.value().taskStatus-1;
                    }
                }

                if(iter.value().taskStatus==taskTake_send_
                        && iter.value().taskId_ess.right(2)=="_s"){
                    iter.value().taskId_ess=iter.value().taskId_ess.mid(0,iter.value().taskId_ess.size()-2);
                }

                qDebug()<<"获取POST返回值:---->SAPTaskIndex:"<<iter.value().SAPTaskIndex<<" taskType:"<<iter.value().taskType
                       <<" containerCode:"<<iter.value().containerCode<<" taskId_ess:"<<iter.value().taskId_ess<<" taskStatus:"<<iter.value().taskStatus
                      <<" taskStatusDesc:"<<iter.value().taskStatusDesc<<" eventCodeDesc:"<<ServerInitItem.eventCodeMap.value(ReplyMsgI.errorMsg).eventCodeDesc;
            }else{
                QString eventCodeDesc=ESS_Single::getInstance()->getCurrentESS_Repost(iter.value().taskId_ess);
                if(eventCodeDesc!=""){
                    if(iter.value().taskType=="IN"){
                        if(eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成" ){
                            iter.value().taskStatus=100;
                            iter.value().taskStatusDesc="任务完成";         //判断升降机是否空闲  创建AGV运输任务
                        }if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=taskTake_ess;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                        }
                    }if(iter.value().taskType=="OUT"){
                        if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=4;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                        }if((eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成")
                                 && iter.value().taskStatus<taskFnish_ess){
                            iter.value().taskStatus=taskFnish_ess;
                            iter.value().taskStatusDesc="等待运输";     //判断升降机是否空闲  创建AGV运输任务
                        }if(iter.value().taskStatusDesc=="任务失败"){
                            iter.value().taskStatus=taskFnish;
                            iter.value().taskStatusDesc="任务失败";     //判断升降机是否空闲  创建AGV运输任务
                        }
                    }if(iter.value().taskType=="MOVE"){
                        if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=4;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                        }if((eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成")
                                 && iter.value().taskStatus<taskFnish_ess){
                            iter.value().taskStatus=taskFnish;
                            iter.value().taskStatusDesc="任务完成";     //判断升降机是否空闲  创建AGV运输任务
                        }if(eventCodeDesc=="任务失败"){
                            iter.value().taskStatus=taskFnish;
                            iter.value().taskStatusDesc="任务失败";     //判断升降机是否空闲  创建AGV运输任务
                        }
                    }

                    qDebug()<<"ESS_任务状态反馈---->SAPTaskIndex:"<<iter.value().SAPTaskIndex<<" taskType:"<<iter.value().taskType
                           <<" containerCode:"<<iter.value().containerCode<<" taskId_ess:"<<iter.value().taskId_ess
                          <<" eventCodeDesc:"<<eventCodeDesc<<" --- taskStatus:"<<iter.value().taskStatus<<iter.value().taskStatusDesc;
                }
            }


            /**************** 任务状态变化 **************/
            //上一个任务状态   当前状态与上一状态不一致时更新数据库
            if(iter.value().taskStatus!=iter.value().latstaskStatus && iter.value().taskStatusbool){
                if(iter.value().taskError==0){
                    if(iter.value().taskType=="IN"){
                        if(iter.value().latstaskStatus<taskTake_ess){//取箱成功前
                            iter.value().codeStatus=1;
                        }if(iter.value().latstaskStatus>=taskTake_ess){
                            iter.value().codeStatus=2;
                        }
                    }if(iter.value().taskType=="OUT"){
                        if(iter.value().latstaskStatus<taskFnish_ess){//放箱成功前
                            iter.value().codeStatus=3;
                        }if(iter.value().latstaskStatus>=taskFnish_ess){
                            iter.value().codeStatus=0;
                        }
                    }
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);

                    qDebug()<<"当前状态与上一状态不一致时更新数据库-->taskType:"<<iter.value().taskType<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex
                          <<" containerCode:" <<iter.value().containerCode<<" codeStatus:"<<iter.value().codeStatus
                           <<" latstaskStatus:" <<iter.value().latstaskStatus<<" taskStatus:"<<iter.value().taskStatus;
                    iter.value().latstaskStatus=iter.value().taskStatus;
                    slectSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                }
            }

            qint64 finishminutes = iter.value().finishTimer.secsTo(QDateTime::currentDateTime());  //任务完成时间差
            if(iter.value().taskStatus>=taskFnish && iter.value().finishTimer.isNull()){
                iter.value().finishTimer=QDateTime::currentDateTime();
                //清除当前升降机任务信息
                LiftCodeStatus_clear(iter.value().SAPTaskIndex);
                slectSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
            }

            //实时更新 接驳台设备 的任务状态信息
            if(iter.value().pickDesc_s!=""){
                emit sigDeviceStatus(iter.value().pickDesc_s,iter.value());                 //根据任务状态实时 绑定解绑接驳台
            }if(iter.value().pickDesc_e!=""){
                emit sigDeviceStatus(iter.value().pickDesc_e,iter.value());                //根据任务状态实时 绑定解绑接驳台
            }

            if(iter.value().taskType!="Empty"){
                if(iter.value().taskTimer.isNull()){
                    iter.value().taskTimer=QDateTime::currentDateTime();
                }else{
                   qint64 taskminutes = iter.value().taskTimer.secsTo(QDateTime::currentDateTime());      //状态更新时间
                   if(finishminutes<600 && taskminutes>=15){                  //一个小时以内 定时更新状态
                       iter.value().taskTimer=QDateTime::currentDateTime();
                       WWYLPOST WWYLPOSTI=ESS_Single::getInstance()->MES_WWYLPOSTI(iter.value(),"WS02");
                       sapMsgInterface::getInstance()->taskCodes_WW(iter.value().taskId,WWYLPOSTI,"UserNuber",2012);
                       qDebug()<<"定时 给MES 更新任务状态信息--> actionId:"<<WWYLPOSTI.actionId<<" SAPTaskIndex:"<<iter.value().SAPTaskIndex
                              <<" taskStatus:"<<iter.value().taskStatus<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                       return true;
                   }
                }

                if(!iter.value().taskId_ess.isEmpty() && iter.value().taskStatus<taskFnish_ess){
                    bool querybool=false;
                    if(iter.value().taskType=="IN"){
                        querybool=true;
                    }if(iter.value().taskType!="IN" && iter.value().taskStatus<taskFnish_ess){
                        querybool=true;
                    }

                    if(querybool){

                        qint64 queryminutes = iter.value().queryTimer.secsTo(QDateTime::currentDateTime());      //状态更新时间
                        if(finishminutes<3600 && queryminutes>=15){
                            ESS_Request ESS_RequestI;
                            ESS_RequestI.actionId="action1";//定时查询
                            ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(iter.value(),ESS_RequestI,ESS_RequestI.actionId);
                            if(ESS_RequestI.pathId!=0){
                                sapMsgInterface::getInstance()->taskCodes_query(ESS_RequestI.iKey,ESS_RequestI,"action1",ESS_RequestI.pathId);
                                qDebug()<<"-->定时查询 actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                            }
                            iter.value().queryTimer=QDateTime::currentDateTime();
                        }else{
                            if(iter.value().queryTimer.isNull()){
                                iter.value().queryTimer=QDateTime::currentDateTime();
                            }
                            QString taskStatus=sapMsgInterface::getInstance()->GetMsgRecv_taskCode(iter.value().taskId_ess);
                            //ESS 任务状态对应 SAP任务状态
                            if(taskCodeInfoMap.contains(taskStatus)){
                                if(iter.value().taskType=="IN" || iter.value().taskType=="MOVE"){
                                    if(taskStatus=="FINISHED"){
                                        iter.value().taskStatus=taskFnish;
                                        iter.value().taskStatusDesc="任务完成";
                                    }if(taskStatus=="CANCELLED" || taskStatus=="FAILED"){
                                        iter.value().taskStatus=taskStatus_delete_;
                                    }
                                }if(iter.value().taskType=="OUT"){
                                    if(taskStatus=="FINISHED" && iter.value().taskStatus<taskFnish_ess){
                                        iter.value().taskStatus=taskFnish_ess;
                                    }if(taskStatus=="CANCELLED" || taskStatus=="FAILED"){
                                        iter.value().taskStatus=taskStatus_delete_;
                                    }
                                }
                            }

                        }

                    }
                }
            }

            qint64 finishdays = iter.value().finishTimer.daysTo(QDateTime::currentDateTime());  //任务完成时间差
            if(finishdays>=2){//及时清除缓存
                qDebug()<<"及时清除缓存"<<iter.value().SAPTaskIndex;
                currentSAPExcelInfoTask.remove(iter.key());
                return true;
            }

        }else {
           qDebug()<<"QMap 数组指针越界，执行失败--taskProcessTimer"<<iter.value().containerCode;
           return false;
        }
        ++iter;
    }

    return true;
}

QString taskManagerServer::setAGVTCurrentTask(SAPExcelInfo SAPExcelInfoI,int Floor, QString sourcestation,QString destination)
{
    if(!boolagvState){return "";}
    AGVTWaitTask AGVTWaitTaskI;
    deviceI deviceItem_s;
    deviceI deviceItem_e;
    if(sourcestation!=""){
         deviceItem_s= getStationInfo_Empty(sourcestation);
    }else{
         deviceItem_e= getStationInfo_Empty(destination);    //获取 目标站点 二维码信息
    }

    QMap<QString,AGVCurrentTask*>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=AGVCurrentTaskMap.end() && iter.key()!=nullptr){
            if(iter.value()->taskisok && iter.value()->ChargeAction==0){          //初始化完成 且无充电任务的状态下
                if(iter.value()->taskId=="" && iter.value()->floornum==Floor){
                    if(destination==""){
                        if(deviceItem_s.Currentpoint==0){
                            return "";
                        }else{
                            iter.value()->destpoint=deviceItem_s.Currentpoint;       //第一个目标二维码
                            iter.value()->Nextdestpoint=deviceItem_s.waitPoint;      //下一个目标二维码
                        }
                    }else{
                        if(deviceItem_e.Currentpoint==0){
                            return "";
                        }else{
                            iter.value()->destpoint=deviceItem_e.waitPoint;          //第一个目标二维码
                            iter.value()->Nextdestpoint=deviceItem_e.Currentpoint;   //下一个目标二维码
                        }
                    }

                    iter.value()->Currentdestpoint=iter.value()->destpoint;       //当前目标二维码
                    iter.value()->taskId=SAPExcelInfoI.taskId_agv;               //唯一识别号
                    iter.value()->taskType=SAPExcelInfoI.taskType;               //任务类型 IN入库  OUT出库
                    iter.value()->SAPTaskIndex=SAPExcelInfoI.SAPTaskIndex;       //任务索引 唯一值
                    iter.value()->containerCode=SAPExcelInfoI.containerCode;     //容器编码 (即胶箱编码) ->唯一
                    iter.value()->Action_agv=0;                                  //二维码 带举升动作
                    iter.value()->Action_ess=0;                                  //夹包机器人
                    iter.value()->taskreset=true;                                //系统异常关闭时，恢复之前的任务状态

                    qDebug()<<"setAGVIP--> sourcestation:"<<sourcestation<<" destination:"<<destination;
                    qDebug()<<"setAGVIP--> AGVIP:"<<iter.value()->AGVIP<<" taskisok:"<<iter.value()->taskisok
                           <<" Currentpoint:"<<iter.value()->Currentpoint<<" RotaryState"<<iter.value()->RotaryState
                           <<" destpoint:"<<iter.value()->destpoint<<" Nextdestpoint:"<<iter.value()->Nextdestpoint<<" Currentdestpoint:"<<iter.value()->Currentdestpoint
                          <<" Action_agv:"<<iter.value()->Action_agv<<" containerCode:"<<iter.value()->containerCode;
                    return iter.value()->AGVIP;

                }
            }
            if(iter.value()->taskisok && iter.value()->ChargeAction==3){
                qint64 ChargeTimer_ = iter.value()->ChargeTimer_.secsTo(QDateTime::currentDateTime());
                if(ChargeTimer_>=120){ //先充电两分钟
                    iter.value()->ChargeAction=4;
                    qDebug()<<"有任务需要执行 提前结束充电任务-->AGVIP:"<<iter.value()->AGVIP<<" ChargeAction:"<<iter.value()->ChargeAction<<" ChargeTimer_:"<<QDateTime::currentDateTime();
                    return "";
                }
            }
        }else{
            return "";
        }
       ++iter;
    }
    return "";
}


bool taskManagerServer::getLiftCodeMap(QString codeDesc, int action, SAPExcelInfo SAPExcelInfoI)
{
    //动作指令action:0空闲  1 锁定  2到达 3解锁
    //任务锁定状态 status:0空闲  1 锁定  2到达 0空闲
    bool codeDesc_=false;
    QMap<QString,LiftCode>::iterator iter= LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()) {
        if(iter.key()!=nullptr){
            if(iter.value().codeDesc==codeDesc){
                qDebug()<<"获取升降机卡位信息---> codeDesc:"<<codeDesc<<" action:"<<action<<" Liftstatus:"<<iter.value().Liftstatus
                       <<" LiftIndex:"<<iter.value().SAPTaskIndex<<"SAP--> SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex
                      <<" containerCode:"<<SAPExcelInfoI.containerCode;
                if(iter.value().codeType=="IN"){
                    //判断 IN 料框是否允许放料  Liftstatus--->1可放料,2-3去X楼
                    if((iter.value().SAPTaskIndex==0 || iter.value().SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex)
                            && iter.value().Liftstatus==1 && action==1){
                        codeDesc_=true;
                        iter.value().status=1;
                        iter.value().SAPTaskIndex=SAPExcelInfoI.SAPTaskIndex;
                        iter.value().containerCode=SAPExcelInfoI.containerCode;
                        qDebug()<<"Lift-IN-料框锁定---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                    }

                    //判断 IN 料框是否已到达  Liftstatus--->1可放料,2-3去X楼
                    if(iter.value().SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex && action==2){
                        codeDesc_=true;
                        iter.value().status=2;
                        qDebug()<<"Lift-IN-料框到达---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                    }
                }

                if(iter.value().codeType=="OUT"){//(OUT- D101 D102 D104: 1可取料,2取料完成)
                    //判断 OUT 料框是否允许放料  Liftstatus--->1可取料,2取料完成
                    if((iter.value().SAPTaskIndex==0 || iter.value().SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex)
                            && iter.value().Liftstatus!=1 && action==1){
                        codeDesc_=true;
                        iter.value().status=1;
                        iter.value().SAPTaskIndex=SAPExcelInfoI.SAPTaskIndex;
                        iter.value().containerCode=SAPExcelInfoI.containerCode;
                        qDebug()<<"Lift-OUT-料框锁定---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                    }

                    //判断 OUT 料框是否到达 status:0空闲  1 锁定  2到达 0空闲
                    if(iter.value().SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex
                            && iter.value().status==2 && action==2){
                        codeDesc_=true;
                        iter.value().status=3;
                        qDebug()<<"Lift-OUT-料框到达---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                    }

                    //判断 OUT 料框是否允许放料  Liftstatus--->1可取料,2取料完成
                    if(iter.value().SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex && action==3){
                        codeDesc_=true;
                        iter.value().status=0;
                        iter.value().SAPTaskIndex=0;
                        iter.value().containerCode="";
                        qDebug()<<"Lift-OUT-料框离开---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                    }

                }
            }
        }else{
            qDebug()<<" codeDesc  越界";
            return false;
        }

        ++iter;
    }
    return codeDesc_;
}

deviceI taskManagerServer::getStationInfo_Empty(QString deviceDesc)
{
    deviceI deviceItem;
    stationInfoMap=ESS_Single::getInstance()->getstationInfoMap_Map();
    QMap<QString,deviceI>::const_iterator iter= stationInfoMap.begin();
    while (iter!=stationInfoMap.end()){
        if(iter!=nullptr){
            if(deviceDesc=="OUT"){
                if(iter.value().enable==1 && iter.value().StationType==deviceDesc
                        && iter.value().deviceDesc.left(7)=="STATION"
                        && iter.value().SAPTaskIndex==0){
                     deviceItem=iter.value();
                     qDebug()<<"出库时获取空闲的放箱码头--->deviceDesc:"<<iter.value().deviceDesc;
                }
            }else{
                if(iter.value().StationType=="OUT"){
                    if(iter.value().deviceDesc==deviceDesc){
                         deviceItem=iter.value();
                         qDebug()<<"获取出库的接驳台--->deviceDesc:"<<iter.value().deviceDesc;
                    }
                }else{
                    if(iter.value().onLine==1 && iter.value().deviceDesc==deviceDesc){
                         deviceItem=iter.value();
                         qDebug()<<"获取空闲的接驳台--->deviceDesc:"<<iter.value().deviceDesc;
                    }
                }
            }
        }
        ++iter;
    }
    return deviceItem;
}

bool taskManagerServer::getcurrentSAPExcelInfoTask()
{
    slecetSAP_Log slecetSAP_LogI;
    slecetSAP_LogI.taskType="new";
    QMap<int, SAPExcelInfo> newSAPExcelInfoTask_=queryServer::getInstance()->querySAPExcelInfoList(slecetSAP_LogI);
    if(!newSAPExcelInfoTask_.isEmpty()){
        foreach(const int SAPTaskIndex,newSAPExcelInfoTask_.keys())
        {
            if(!currentSAPExcelInfoTask.contains(SAPTaskIndex)){
                SAPExcelInfo SAPExcelInfoI=newSAPExcelInfoTask_.value(SAPTaskIndex);
                if(SAPExcelInfoI.taskType=="IN"){
                    SAPExcelInfoI.codeStatus=1;           //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                }if(SAPExcelInfoI.taskType=="OUT"){
                    SAPExcelInfoI.codeStatus=3;           //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                }
                slectSAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                currentSAPExcelInfoTask.insert(SAPTaskIndex,newSAPExcelInfoTask_.value(SAPTaskIndex));
            }
        }
    }
    return true;
}

bool taskManagerServer::newSAPExcelInfo_Empty()
{
    deviceI deviceItem;
    stationInfoMap=ESS_Single::getInstance()->getstationInfoMap_Map();
    QMap<QString,deviceI>::const_iterator iter= stationInfoMap.begin();
    while (iter!=stationInfoMap.end()){
        if(iter!=nullptr){//station 0无料框  1有料框
            if(iter.value().StationType=="Empty" && iter.value().onLine==1 && iter.value().status==1
                    && iter.value().SAPTaskIndex==0 && deviceItem.deviceDesc==""){
                 deviceItem=iter.value();
                 qDebug()<<"获取需要返空箱的接驳台--->deviceDesc:"<<iter.value().deviceDesc<<iter.value().stationDesc;
            }
        }else {
            return false;
        }
        ++iter;
    }

    if(deviceItem.deviceDesc!=""){
        SAPExcelInfo SAPExcelInfoI;
        SAPExcelInfoI.taskType="Empty";                       //任务类型 Empty
        SAPExcelInfoI.taskTypeDesc="返空箱";
        SAPExcelInfoI.taskId="taskId"+QDateTime::currentDateTime().toString("hhmmsszzz");         //任务编码 唯一性
        SAPExcelInfoI.containerCode="Code-"+deviceItem.deviceDesc;

        SAPExcelInfoI.sourcestation=deviceItem.deviceDesc;
        SAPExcelInfoI.destination="STATION-02";//二楼空料框返回 接驳台
        SAPExcelInfoI.floorId=SAPExcelInfoI.sourcestation.left(1)+"-"+"2";         //楼层走向  2F-3F 3F-2F

        SAPExcelInfoI.taskStatus=0;                            //任务状态
        QString taskType_=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
        SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType_);
        SAPExcelInfoI.creatTimer=QDateTime::currentDateTime();
        if(SAPExcelInfoI.taskId!=""){
           ON_SAPExcelInfo_new(SAPExcelInfoI);
        }

    }
    return true;
}

void taskManagerServer::LiftCodeStatus_clear(int SAPTaskIndex)
{
    QMap<QString,LiftCode>::iterator iter1= LiftCodeMap.begin();
    while (iter1!=LiftCodeMap.end()) {
        if(iter1.key()!=nullptr){
            if(SAPTaskIndex==iter1.value().SAPTaskIndex){
                iter1.value().status=0;                //任务锁定状态:0空闲  1 锁定  2到达 0空闲
                iter1.value().SAPTaskIndex=0;          //任务索引 唯一值
                iter1.value().containerCode="";        //容器编码 (即胶箱编码) ->唯一
                qDebug()<<"清除升降机卡位任务信息-->codeDesc:"<<iter1.value().codeDesc<<" SAPTaskIndex:"<<iter1.value().SAPTaskIndex;
            }
        }else{
            return ;
        }
        iter1++;
    }
}

bool taskManagerServer::setAGVCurrentTask_charge(AGVCurrentTask *AGVCurrentTaskI)
{
    agvORderTask agvORderTaskI;
    if(AGVCurrentTaskI->ChargeAction==1){//前往充电点二维码
        AGVCurrentTaskI->ChargeAction=2;
        AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->ChargePoint;
        emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
    }if(AGVCurrentTaskI->ChargeAction==2 &&  AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint){
        AGVCurrentTaskI->ChargeAction=3;  //到达充电点 开始充电倒计时
        AGVCurrentTaskI->ChargeTimer_=QDateTime::currentDateTime();
        qDebug()<<"开始充电计时-->AGVIP:"<<AGVCurrentTaskI->AGVIP<<" ChargeAction:"<<AGVCurrentTaskI->ChargeAction<<" ChargeTimer_:"<<QDateTime::currentDateTime();
    }if(AGVCurrentTaskI->ChargeAction==3 && AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->ChargePoint){
        qint64 ChargeTimer_ = AGVCurrentTaskI->ChargeTimer_.secsTo(QDateTime::currentDateTime());
        if(ChargeTimer_>=2000){//60*60=3600 一个小时
            AGVCurrentTaskI->ChargeAction=4;
            qDebug()<<"结束充电任务-->AGVIP:"<<AGVCurrentTaskI->AGVIP<<" ChargeAction:"<<AGVCurrentTaskI->ChargeAction<<" ChargeTimer_:"<<QDateTime::currentDateTime();
        }
    }if(AGVCurrentTaskI->ChargeAction==4 && AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->ChargePoint){
        AGVCurrentTaskI->ChargeAction=5;
        AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->waitPoint;
        emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
    }if(AGVCurrentTaskI->ChargeAction==5 &&  AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->waitPoint){
        AGVCurrentTaskI->ChargeAction=0;
    }
    return true;
    //qDebug()<<"--> AGVIP:"<<iter.value().AGVIP<<" ChargeAction:"<<iter.value().ChargeAction;
}

bool taskManagerServer::setAGVCurrentTask_task(AGVCurrentTask *AGVCurrentTaskI)
{
    agvORderTask agvORderTaskI;
    if(AGVCurrentTaskI->Action_agv==0){          //前往起始站点
        if(AGVCurrentTaskI->RotaryState>=3){     //确保托盘状态为降下
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),4,0,agvORderTaskI);
            return true;
        }
        if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint){
            AGVCurrentTaskI->Action_agv=2;       //开始举升
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),3,0,agvORderTaskI);
        }else{
            AGVCurrentTaskI->Action_agv=1;
            AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->destpoint;
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
        }
    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint
            && AGVCurrentTaskI->Action_agv==1){   //到达起始站点
            AGVCurrentTaskI->Action_agv=2;        //开始举升
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),3,0,agvORderTaskI);
    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint
            && AGVCurrentTaskI->Action_agv==1){   //到达起始站点
            AGVCurrentTaskI->Action_agv=2;        //开始举升
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),3,0,agvORderTaskI);
    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint
            && AGVCurrentTaskI->Action_agv==2 && AGVCurrentTaskI->RotaryState>=50){
            AGVCurrentTaskI->Action_agv=3;       //举升到位 开始前往目标站点
            AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->Nextdestpoint;
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
    }


    if(AGVCurrentTaskI->Currentpoint!=AGVCurrentTaskI->destpoint
            && AGVCurrentTaskI->Action_agv==3 && AGVCurrentTaskI->RotaryState>=50){
            AGVCurrentTaskI->Action_agv=4;       //AGV 离开取货点
    }

    if(!AGVCurrentTaskI->taskreset){//系统异常关闭时，恢复之前的任务状态
        //前往取货点之前
        if(AGVCurrentTaskI->Action_agv<3){
            AGVCurrentTaskI->Action_agv=0;
            AGVCurrentTaskI->taskreset=true;
            qDebug()<<"系统异常关闭时，恢复之前的任务状态--执行前往取货站点"<<AGVCurrentTaskI->AGVIP;
        }

        //到达目标站点之前
        if(AGVCurrentTaskI->Action_agv>=3 && AGVCurrentTaskI->Action_agv<Actionagv_max){
            if(AGVCurrentTaskI->WaitTimer_.isNull()){
                AGVCurrentTaskI->WaitTimer_=QDateTime::currentDateTime();
            }
            qint64 taskminutes = AGVCurrentTaskI->WaitTimer_.secsTo(QDateTime::currentDateTime());      //状态更新时间
            if(taskminutes>10 && AGVCurrentTaskI->RotaryState<5){
                emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentpoint),3,0,agvORderTaskI);
                qDebug()<<"系统异常关闭时，恢复之前的任务状态--执行举升动作"<<AGVCurrentTaskI->AGVIP;
            }
            if(taskminutes>10 && AGVCurrentTaskI->RotaryState>=50){
                AGVCurrentTaskI->Action_agv=4;
                AGVCurrentTaskI->taskreset=true;
                emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
                qDebug()<<"系统异常关闭时，恢复之前的任务状态--执行前往目标站点"<<AGVCurrentTaskI->AGVIP;
            }
        }

    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint
            && AGVCurrentTaskI->Action_agv==4 && AGVCurrentTaskI->RotaryState>=50){
        if(AGVCurrentTaskI->actionType==1){   //动作类型 actionType=0到达站点不需要返回  1到达站点倒计时结束后返回
            AGVCurrentTaskI->Action_agv=Actionagv_re;
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),4,0,agvORderTaskI);
        }else{
            AGVCurrentTaskI->Action_agv=5;       //到达目标站点 托盘开始下降
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),4,0,agvORderTaskI);
        }
    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint
            && AGVCurrentTaskI->Action_agv==5 && AGVCurrentTaskI->RotaryState<=3){
        AGVCurrentTaskI->WaitTimer_=QDateTime::currentDateTime();
        taskId_AGVStatusMap.insert(AGVCurrentTaskI->taskId,taskFnish);//SAP与AGV 任务状态绑定  100-任务完成
        AGVCurrentTaskI->lastTaskId=AGVCurrentTaskI->taskId;
        AGVCurrentTaskI->taskId="";                 //唯一识别号
        AGVCurrentTaskI->taskType="";               //任务类型 IN入库  OUT出库
        AGVCurrentTaskI->SAPTaskIndex=0;            //任务索引 唯一值
        AGVCurrentTaskI->Action_agv=Actionagv_max;
        qDebug()<<"AGV搬运任务完成--->AGVIP:"<<AGVCurrentTaskI->AGVIP<<" taskId:"<<AGVCurrentTaskI->taskId
               <<" Action_agv:"<<AGVCurrentTaskI->Action_agv<<" size():"<<taskId_AGVStatusMap.size();
    }

    return true;
}

bool taskManagerServer::setAGVCurrentTask_wait(AGVCurrentTask *AGVCurrentTaskI)
{
    agvORderTask agvORderTaskI;
    if(AGVCurrentTaskI->RotaryState<=3
            && (AGVCurrentTaskI->Action_agv==Actionagv_max || AGVCurrentTaskI->Action_agv==7)){
        if(AGVCurrentTaskI->WaitTimer_.isNull()){
           AGVCurrentTaskI->WaitTimer_=QDateTime::currentDateTime();
        }
        qint64 taskminutes = AGVCurrentTaskI->WaitTimer_.secsTo(QDateTime::currentDateTime());      //状态更新时间
        if(taskminutes>=10){
            AGVCurrentTaskI->Action_agv=8;
            AGVCurrentTaskI->taskId="返回待机点";
            AGVCurrentTaskI->WaitTimer_=QDateTime::currentDateTime();
            AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->waitPoint;
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->waitPoint),1,0,agvORderTaskI);
        }
        qDebug()<<"AGV搬运任务完成返回待机点 倒计时--->AGVIP:"<<AGVCurrentTaskI->AGVIP<<" taskminutes:"<<taskminutes;
    }

    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint && AGVCurrentTaskI->RotaryState<=3
            && AGVCurrentTaskI->Action_agv==8){
        AGVCurrentTaskI->taskId="";            //唯一识别号
        AGVCurrentTaskI->taskType="";          //任务类型 IN入库  OUT出库
        AGVCurrentTaskI->SAPTaskIndex=0;       //任务索引 唯一值
        AGVCurrentTaskI->containerCode="";     //容器编码 (即胶箱编码) ->唯一
        AGVCurrentTaskI->Action_agv=0;         //二维码 带举升动作
        AGVCurrentTaskI->Action_ess=0;         //夹包机器人
        AGVCurrentTaskI->destpoint=0;          //第一个目标二维码
        AGVCurrentTaskI->Nextdestpoint=0;      //下一个目标二维码
        AGVCurrentTaskI->Currentdestpoint=0;   //当前目标二维码
        AGVCurrentTaskI->actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
        AGVCurrentTaskI->taskreset=true;       //系统异常关闭时，恢复之前的任务状态
        qDebug()<<"AGV到达待机点任务完成--->AGVIP:"<<AGVCurrentTaskI->AGVIP;
    }

    return true;
}

bool taskManagerServer::setAGVCurrentTask_task_(AGVCurrentTask *AGVCurrentTaskI)
{
    //返回起始站点流程
    agvORderTask agvORderTaskI;
    if(AGVCurrentTaskI->Currentpoint==AGVCurrentTaskI->Currentdestpoint && AGVCurrentTaskI->Action_agv>=10){
        if(AGVCurrentTaskI->Action_agv==10 && AGVCurrentTaskI->RotaryState<=3){
            AGVCurrentTaskI->Action_agv=11;                                     //在终点执行举升动作
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),3,0,agvORderTaskI);
            return true;
        }if(AGVCurrentTaskI->Action_agv==11 && AGVCurrentTaskI->RotaryState>=50){
            AGVCurrentTaskI->Action_agv=12;                                        //举升到位 返回起始点
            AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->destpoint;
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),1,0,agvORderTaskI);
            return true;
        }if(AGVCurrentTaskI->Action_agv==12 && AGVCurrentTaskI->RotaryState>=50){
            AGVCurrentTaskI->Action_agv=13;                                     //到达起始点 执行下降动作
            emit sigAGVMoveTask(AGVCurrentTaskI->AGVIP,quint16(AGVCurrentTaskI->Currentpoint), quint16(AGVCurrentTaskI->Currentdestpoint),4,0,agvORderTaskI);
            return true;
        }if(AGVCurrentTaskI->Action_agv==13 && AGVCurrentTaskI->RotaryState<=3){    //在起始点 完成下降动作
            AGVCurrentTaskI->taskId="";            //唯一识别号
            AGVCurrentTaskI->taskType="";          //任务类型 IN入库  OUT出库
            AGVCurrentTaskI->SAPTaskIndex=0;       //任务索引 唯一值
            AGVCurrentTaskI->containerCode="";     //容器编码 (即胶箱编码) ->唯一
            AGVCurrentTaskI->Action_agv=0;         //二维码 带举升动作
            AGVCurrentTaskI->Action_ess=0;         //夹包机器人
            AGVCurrentTaskI->destpoint=0;          //第一个目标二维码
            AGVCurrentTaskI->Nextdestpoint=0;      //下一个目标二维码
            AGVCurrentTaskI->Currentdestpoint=0;   //当前目标二维码
            AGVCurrentTaskI->actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
            AGVCurrentTaskI->taskreset=true;       //系统异常关闭时，恢复之前的任务状态
        }
    }
   return true;
}


void taskManagerServer::taskManagerServerTimer()
{

    if(AGVCurrentTaskMap.isEmpty()){
        allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
        ServerInitItem=ALLServerInitItem.ServerInitItem;
        CurrentServerItem=ALLServerInitItem.CurrentServerItem;

        /************** 基础信息缓存链表赋值 *******************/
        LiftCodeMap=CurrentServerItem.LiftCodeMap;                          //升降机各个接驳台任务状态信息
        LiftCodeMap_Info=LiftCodeMap;

        AGVCurrentTaskMap=CurrentServerItem.AGVCurrentTaskMap;              //当前AGV状态信息

        currentSAPExcelInfoTask=CurrentServerItem.currentSAPExcelInfoTask;  //MES run task

        server_->ServerInitItem.eventCodeMap=ServerInitItem.eventCodeMap;   //ESS-P 事件 回调类型
    }else{

        TableWidgetcount++;
        if(countbool){
           countbool=false;
           qint64 taskTimers = taskCountTimer.secsTo(QDateTime::currentDateTime());      //状态更新时间
           if(taskCountTimer.isNull()){
               taskCountTimer=QDateTime::currentDateTime();
           }else{
                if(taskTimers>=60){
                    newSAPExcelInfo_Empty();//创建返空料框任务
                    countbool=true;
                    taskCountTimer=QDateTime::currentDateTime();
                    return;
                }
           }

           if(TableWidgetcount%2==1){
               switch (TableWidgetcount%remainder)
               {
                   case 0x01:
                        emit sigLiftCodeMap(LiftCodeMap);                   //更新升降机各个接驳台状态信息
                       break;
                   case 0x03:
                        emit sigAGVCurrentTaskMap(AGVCurrentTaskMap);       //定时更新AGV任务状态信息显示
                       break;
                   case 0x05:
                        getcurrentSAPExcelInfoTask();                       //定时获取数据库，待执行任务 任务状态为:0
                       break;
                   case 0x07:
                        ESS_Single::getInstance()->setCurrentSAPExcelInfoTask(currentSAPExcelInfoTask);
                       break;
                   default:
                       break;
               }
           }else {
               if(slectSAPExcelInfoTask.isEmpty()){
                   if(TableWidgetcount%5==0){
                       taskProcessTimer();  //实时判断任务状态 及处理
                   }else{
                       ProcessMsgRecv();    //实时判断ESS 接口返回数据
                   }
               }else{
                   threadQueryI->UP_SAPExcelInfotaskCode(slectSAPExcelInfoTask);//更新任务状态信息
                   slectSAPExcelInfoTask.clear();
               }
           }

           countbool=true;
        }
        if(TableWidgetcount>10000){TableWidgetcount=0;}
    }

}

void taskManagerServer::ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI)
{
    shelfBinInfo shelfBinInfoI;
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    newSAPExcelInfoList.clear();
    if(!newSAPExcelInfoList.contains(SAPExcelInfoI.taskId)){
        if(SAPExcelInfoI.taskType=="IN"){
            shelfBinInfoI= ESS_Single::getInstance()->getshelfBinInfo_Empty(SAPExcelInfoI);//入库时获取空闲的 库位
            if(shelfBinInfoI.shelfBinIndex!=0){
                SAPExcelInfoI.pickDesc_s="STATION-01";
                SAPExcelInfoI.podIdDesc=shelfBinInfoI.podIdDesc;
                SAPExcelInfoI.destination=shelfBinInfoI.podIdDesc;
                SAPExcelInfoI.shelfBindesc=shelfBinInfoI.shelfBindesc;
            }
            shelfBinInfoI.status=1;//0 空闲  1任务占用中
            shelfBinInfoI.containerCode=SAPExcelInfoI.containerCode;
            shelfBinInfoI.LabelNo=SAPExcelInfoI.LabelNo;
            shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
        }

        if(SAPExcelInfoI.taskType=="MOVE"){
            shelfBinInfo shelfBinInfoI_s= ESS_Single::getInstance()->getcontainerCode_desc(SAPExcelInfoI.containerCode);
            shelfBinInfo shelfBinInfoI_e= ESS_Single::getInstance()->getshelfBinInfo_Empty(SAPExcelInfoI);
            SAPExcelInfoI.oldIdDesc=shelfBinInfoI_s.podIdDesc;       //所属架位注释 -- MES
            SAPExcelInfoI.oldBinDesc=shelfBinInfoI_s.shelfBindesc;   //改架前的 Bin   (用于AGV内部移库) -- ESS

            shelfBinInfoI_s.status=3;//0 空闲  1任务占用中
            shelfBinInfoMap.insert(shelfBinInfoI_s.shelfBindesc,shelfBinInfoI_s);

            SAPExcelInfoI.newIdDesc=shelfBinInfoI_e.podIdDesc;       //所属架位注释 -- MES
            SAPExcelInfoI.newBinDesc=shelfBinInfoI_e.shelfBindesc;   //改架后的 Bin   (用于AGV内部移库) -- ESS

            shelfBinInfoI_e.status=1;//0 空闲  1任务占用中
            shelfBinInfoI_e.containerCode=SAPExcelInfoI.containerCode;
            shelfBinInfoI_e.LabelNo=SAPExcelInfoI.LabelNo;
            shelfBinInfoMap.insert(shelfBinInfoI_e.shelfBindesc,shelfBinInfoI_e);
        }

        if(SAPExcelInfoI.taskType=="Empty"){
            SAPExcelInfoI.pickDesc_s=SAPExcelInfoI.sourcestation;     //起始站点的对接码头
            SAPExcelInfoI.pickDesc_e=SAPExcelInfoI.destination;       //目标站点的对接码头
        }

        if(!shelfBinInfoMap.isEmpty()){
            threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap,"Bindesc");//更新库位状态信息
        }

        QString taskType=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
        SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
        if(SAPExcelInfoI.sourcestation!="" && SAPExcelInfoI.destination!=""){
            newSAPExcelInfoList.insert(SAPExcelInfoI.taskId,SAPExcelInfoI);
            if(ThreadInsertI->newSAPExcelInfoTask(newSAPExcelInfoList)){//(把创建成功的任务 存入数据库)
                qDebug()<<"taskManager new task--S->  任务类型:"<<SAPExcelInfoI.taskType<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                       <<" 产品编码:"<<SAPExcelInfoI.Material<<newSAPExcelInfoList.size();
            }
        }else{
            qDebug()<<"taskManager new task--E->  任务类型:"<<SAPExcelInfoI.taskType<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                   <<" sourcestation:"<<SAPExcelInfoI.sourcestation<<" destination:"<<SAPExcelInfoI.destination<<newSAPExcelInfoList.size();
        }

    }
}

void taskManagerServer::ON_SAPExcelInfoList_new(QMap<QString, SAPExcelInfo> newSAPExcelInfoList_)
{
    qDebug()<<"ON_SAPExcelInfoList_new.size:"<<newSAPExcelInfoList_.size();

    newSAPExcelInfoList.clear();
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    QMap<QString ,SAPExcelInfo>::const_iterator iter_=newSAPExcelInfoList_.begin();
    while (iter_!=newSAPExcelInfoList_.end()) {
        if(iter_!=nullptr){
            SAPExcelInfo SAPExcelInfoI=iter_.value();
            QString taskType=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
            SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
            if(SAPExcelInfoI.sourcestation!="" && SAPExcelInfoI.destination!=""){
                shelfBinInfo shelfBinInfoI_s;
                shelfBinInfoI_s.status=3;
                shelfBinInfoI_s.shelfBindesc=SAPExcelInfoI.shelfBindesc;
                shelfBinInfoMap.insert(shelfBinInfoI_s.shelfBindesc,shelfBinInfoI_s);

                SAPExcelInfoI.taskStatus=0;
                QString taskType=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
                SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);

                newSAPExcelInfoList.insert(iter_.key(),SAPExcelInfoI);
                qDebug()<<"taskManager new task--S->  任务类型:"<<SAPExcelInfoI.taskType<<SAPExcelInfoI.taskStatus<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                       <<" 产品编码:"<<SAPExcelInfoI.Material<<newSAPExcelInfoList.size();
            }else{
                qDebug()<<"taskManager new task--E->  任务类型:"<<SAPExcelInfoI.taskType<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                       <<" sourcestation:"<<SAPExcelInfoI.sourcestation<<" destination:"<<SAPExcelInfoI.destination<<newSAPExcelInfoList.size();
            }
        }else{

        }
        iter_++;
    }

    if(!newSAPExcelInfoList.isEmpty()){
        ThreadInsertI->newSAPExcelInfoTask(newSAPExcelInfoList);//(把创建成功的任务 存入数据库)
        threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap,"Bindesc");   //更新库位状态信息
    }
}

void taskManagerServer::ON_AGVMoveTask(QString AGVIP, QString taskType, AGVCurrentTask AGVCurrentTaskI)
{
    qDebug()<<"手动创建AGV搬运任务--->AGVIP:"<<AGVIP<<" taskType:"<<taskType<<" destpoint:"<<AGVCurrentTaskI.destpoint
           <<" Nextdestpoint:"<<AGVCurrentTaskI.Nextdestpoint;
    QMap<QString,AGVCurrentTask *>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=AGVCurrentTaskMap.end() && iter.key()!=nullptr){
            if(iter.value()->AGVIP==AGVIP){//初始化完成 且无任务的状态下
                if(iter.value()->taskisok && iter.value()->taskId==""){
                    if(taskType=="charge"){
                        iter.value()->ChargeAction=1;//开始充电
                    }if(taskType=="charge_"){
                        iter.value()->ChargeAction=4;//结束充电
                    }
                }

                if(taskType=="add"){
                    if(iter.value()->taskisok && iter.value()->destpoint==0 && iter.value()->containerCode==""){
                        iter.value()->taskId="AGV-"+QDateTime::currentDateTime().toString("hhmmss");            //唯一识别号
                        iter.value()->taskType="AGV";            //任务类型 IN入库  OUT出库
                        iter.value()->SAPTaskIndex=0;            //任务索引 唯一值
                        iter.value()->containerCode="container"; //容器编码 (即胶箱编码) ->唯一

                        iter.value()->Action_agv=0;
                        iter.value()->destpoint=AGVCurrentTaskI.destpoint;
                        iter.value()->Nextdestpoint=AGVCurrentTaskI.Nextdestpoint;
                        iter.value()->actionType=AGVCurrentTaskI.actionType;             //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
                        iter.value()->actionTimerCount=AGVCurrentTaskI.actionTimerCount; //倒计时 计数
                        iter.value()->Currentdestpoint=AGVCurrentTaskI.destpoint;        //当前目标二维码
                        iter.value()->taskreset=true;       //系统异常关闭时，恢复之前的任务状态
                        qDebug()<<"手动创建AGV搬运任务--->AGVIP:"<<AGVIP<<iter.value()->taskisok<<" destpoint:"<<iter.value()->destpoint;
                    }
                }

                if(taskType=="delete"){
                    iter.value()->taskId="";            //唯一识别号
                    iter.value()->taskType="";          //任务类型 IN入库  OUT出库
                    iter.value()->SAPTaskIndex=0;       //任务索引 唯一值
                    iter.value()->containerCode="";     //容器编码 (即胶箱编码) ->唯一
                    iter.value()->Action_agv=0;         //二维码 带举升动作
                    iter.value()->Action_ess=0;         //夹包机器人
                    iter.value()->destpoint=0;          //第一个目标二维码
                    iter.value()->Nextdestpoint=0;      //下一个目标二维码
                    iter.value()->Currentdestpoint=0;   //当前目标二维码
                    iter.value()->actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
                    iter.value()->taskreset=true;       //系统异常关闭时，恢复之前的任务状态
                    qDebug()<<"手动清除AGV搬运任务--->AGVIP:"<<AGVIP<<iter.value()->taskisok<<" destpoint:"<<iter.value()->destpoint;
                }

            }
        }else{
            return;
        }
       ++iter;
    }

}

void taskManagerServer::ON_AgvStateWidget(agvState agvStateItemI)
{
    if(!boolagvState){return;}
    boolagvState=false;
#if agvStateItembool

    QMap<QString,AGVCurrentTask*>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter.key()!=nullptr){
            if(iter.value()->AGVIP==agvStateItemI.agvIp){
                int Currentpoint=agvStateItemI.passPointState.toInt();                       //最新读到的二维码
                iter.value()->Currentpoint=Currentpoint;
                iter.value()->RotaryState=agvStateItemI.currentRotaryHeightState.toInt();    //当前转盘高度 mm
                iter.value()->VoltageState=agvStateItemI.currentBatteryVoltageState.toInt(); //当前电压值 mv
                iter.value()->RunStatus=agvStateItemI.RunStatus;                             //当前运行状态  1 运行 2 停止
                int agverror=agvStateItemI.currentErrorCodeState.toInt();                   //AGV当前错误代码
                iter.value()->agverror=agverror;
                iter.value()->isOnline=agvStateItemI.isOnline;

                QString TaskNumberState=agvStateItemI.currentCompletedTaskNumberState;      //AGV当前完成的任务编号
                iter.value()->Currentpointcount++;
                if(iter.value()->Currentpointcount>10000){iter.value()->Currentpointcount=0;}

                if(agvStateItemI.FinishInit && agvStateItemI.isOnline && agverror==0){
                      iter.value()->taskisok=true;   //AGV 初始化完成 且 无任务错误代码
                      if(iter.value()->VoltageState<5100 && iter.value()->taskId==""
                              && iter.value()->ChargeAction==0 && iter.value()->Action_agv==0){//进入充电流程
                          iter.value()->ChargeAction=1;
                          iter.value()->Currentdestpoint=iter.value()->ChargePoint;
                      }
                }else {
                      iter.value()->taskisok=false;
                }

                if(iter.value()->taskisok){
                    if(iter.value()->ChargeAction>0){
                        setAGVCurrentTask_charge(iter.value());             //AGV 充电动作指令函数
                    }else{
                        if(iter.value()->taskId!="" && iter.value()->Action_agv<Actionagv_max){
                            setAGVCurrentTask_task(iter.value());           //AGV 运送动作指令函数
                        }if(iter.value()->Action_agv>=Actionagv_max && iter.value()->Action_agv<Actionagv_re){
                             setAGVCurrentTask_wait(iter.value());          //AGV 返回待机点动作指令函数
                        }if(iter.value()->Action_agv>=Actionagv_re){
                            setAGVCurrentTask_task_(iter.value());          //AGV 运送动作指令函数 返回
                        }
                    }

                    /*if(iter.value()->taskId!=""){
                        taskId_AGVStatusMap.insert(iter.value()->taskId,iter.value()->Action_agv);//SAP与AGV 任务状态绑定
                        qDebug()<<" AGVIP:"<<iter.value()->AGVIP<<" taskisok:"<<iter.value()->taskisok<<" Currentpoint:"<<iter.value()->Currentpoint
                               <<" RotaryState"<<iter.value()->RotaryState<<" destpoint:"<<iter.value()->destpoint<<" Nextdestpoint:"<<iter.value()->Nextdestpoint
                              <<" Currentdestpoint:"<<iter.value()->Currentdestpoint<<" Action_agv:"<<iter.value()->Action_agv<<" containerCode:"<<iter.value()->containerCode;
                    }*/if(iter.value()->lastTaskId!=""){//绑定上一个 已完成的 任务 id
                        taskId_AGVStatusMap.insert(iter.value()->lastTaskId,taskFnish);
                    }

               }
            }
        }else{
            boolagvState=true;
            return ;
        }
        ++iter;
    }

#elif agvStateItembool_

    //    AGVCurrentTask* AGVCurrentTaskI;
    //    if(AGVCurrentTaskMap.contains(agvStateItemI.agvIp)){
    //        AGVCurrentTaskI=AGVCurrentTaskMap.value(agvStateItemI.agvIp);

    //        int Currentpoint=agvStateItemI.passPointState.toInt();                       //最新读到的二维码
    //        AGVCurrentTaskI->Currentpoint=Currentpoint;
    //        AGVCurrentTaskI->RotaryState=agvStateItemI.currentRotaryHeightState.toInt();    //当前转盘高度 mm
    //        AGVCurrentTaskI->VoltageState=agvStateItemI.currentBatteryVoltageState.toInt(); //当前电压值 mv
    //        AGVCurrentTaskI->RunStatus=agvStateItemI.RunStatus;                             //当前运行状态  1 运行 2 停止
    //        int agverror=agvStateItemI.currentErrorCodeState.toInt();                   //AGV当前错误代码
    //        AGVCurrentTaskI->agverror=agverror;
    //        AGVCurrentTaskI->isOnline=agvStateItemI.isOnline;

    //        QString TaskNumberState=agvStateItemI.currentCompletedTaskNumberState;      //AGV当前完成的任务编号
    //        AGVCurrentTaskI->Currentpointcount++;
    //        if(AGVCurrentTaskI->Currentpointcount>10000){AGVCurrentTaskI->Currentpointcount=0;}

    //        if(agvStateItemI.FinishInit && agvStateItemI.isOnline && agverror==0){
    //              AGVCurrentTaskI->taskisok=true;   //AGV 初始化完成 且 无任务错误代码
    //              if(AGVCurrentTaskI->VoltageState<5000 && AGVCurrentTaskI->taskId==""){//进入充电流程
    //                  AGVCurrentTaskI->ChargeAction=1;
    //                  AGVCurrentTaskI->Currentdestpoint=AGVCurrentTaskI->ChargePoint;
    //              }
    //        }else {
    //              AGVCurrentTaskI->taskisok=false;
    //        }

    //        if(AGVCurrentTaskI->taskisok){
    //            if(AGVCurrentTaskI->ChargeAction>0){
    //                setAGVCurrentTask_charge(AGVCurrentTaskI);             //AGV 充电动作指令函数
    //            }else{
    //                if(AGVCurrentTaskI->taskId!="" && AGVCurrentTaskI->Action_agv<Actionagv_max){
    //                    setAGVCurrentTask_task(AGVCurrentTaskI);           //AGV 运送动作指令函数
    //                }if(AGVCurrentTaskI->Action_agv>=Actionagv_max && AGVCurrentTaskI->Action_agv<Actionagv_re){
    //                     setAGVCurrentTask_wait(AGVCurrentTaskI);          //AGV 返回待机点动作指令函数
    //                }if(AGVCurrentTaskI->Action_agv>=Actionagv_re){
    //                    setAGVCurrentTask_task_(AGVCurrentTaskI);          //AGV 运送动作指令函数 返回
    //                }
    //            }

    //            if(AGVCurrentTaskI->taskId!=""){
    //                taskId_AGVStatusMap.insert(AGVCurrentTaskI->taskId,AGVCurrentTaskI->Action_agv);//SAP与AGV 任务状态绑定
    //                qDebug()<<" AGVIP:"<<AGVCurrentTaskI->AGVIP<<" taskisok:"<<AGVCurrentTaskI->taskisok<<" Currentpoint:"<<AGVCurrentTaskI->Currentpoint
    //                       <<" RotaryState"<<AGVCurrentTaskI->RotaryState<<" destpoint:"<<AGVCurrentTaskI->destpoint<<" Nextdestpoint:"<<AGVCurrentTaskI->Nextdestpoint
    //                      <<" Currentdestpoint:"<<AGVCurrentTaskI->Currentdestpoint<<" Action_agv:"<<AGVCurrentTaskI->Action_agv<<" containerCode:"<<AGVCurrentTaskI->containerCode;
    //            }if(AGVCurrentTaskI->lastTaskId!=""){//绑定上一个 已完成的 任务 id
    //                taskId_AGVStatusMap.insert(AGVCurrentTaskI->lastTaskId,taskFnish);
    //            }

    //       }

    //        AGVCurrentTaskMap.find(AGVCurrentTaskI->AGVIP).value()=AGVCurrentTaskI;

    //    }

#endif

    boolagvState=true;
}

void taskManagerServer::ON_UPSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI)
{
    QMap<int, SAPExcelInfo> UPSAPExcelInfoTask;
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while(iter!=currentSAPExcelInfoTask.end()){
        if(iter.value().containerCode!=nullptr){
            if(seletSAPExcelInfoI.SAPTaskIndex==iter.key()){
                if(seletSAPExcelInfoI.taskStatus==tasklift_ess){
                    taskId_AGVStatusMap.insert(iter.value().taskId_agv,taskFnish);
                }
                iter.value().taskStatus=seletSAPExcelInfoI.taskStatus;
                QString taskType=seletSAPExcelInfoI.taskType+"_"+QString::number(seletSAPExcelInfoI.taskStatus);
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                UPSAPExcelInfoTask.insert(iter.key(),iter.value());
                qDebug()<<"手动更新任务状态--->SAPTaskIndex:"<<seletSAPExcelInfoI.SAPTaskIndex<<" taskType:"<<taskType<<"actionId:"<<iter.value().taskStatus<<""<<iter.value().taskStatusDesc;
            }
        }
        ++iter;
    }

    if(!UPSAPExcelInfoTask.isEmpty()){
        threadQueryI->UP_SAPExcelInfotaskCode(UPSAPExcelInfoTask);//更新任务状态信息
    }

}

void taskManagerServer::ON_AGVCurrentTaskAction(QString AGVIP, QString Type, int Action)
{
    if(!boolagvState){return ;}
    QMap<QString,AGVCurrentTask*>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter.key()!=nullptr){
            if(iter.value()->AGVIP==AGVIP){
                iter.value()->Action_agv=Action;
                if(iter.value()->Action_agv==5){//任务完成返回待机点
                    iter.value()->WaitTimer_=QDateTime::currentDateTime();
                    taskId_AGVStatusMap.insert(iter.value()->taskId,taskFnish);//SAP与AGV 任务状态绑定  100-任务完成
                    iter.value()->lastTaskId=iter.value()->taskId;
                    iter.value()->taskId="";                 //唯一识别号
                    iter.value()->taskType="";               //任务类型 IN入库  OUT出库
                    iter.value()->SAPTaskIndex=0;            //任务索引 唯一值
                    iter.value()->Action_agv=Actionagv_max;
                    iter.value()->taskreset=true;           //系统异常关闭时，恢复之前的任务状态
                }

                if(iter.value()->Action_agv==100){
                    iter.value()->taskId="";            //唯一识别号
                    iter.value()->taskType="";          //任务类型 IN入库  OUT出库
                    iter.value()->SAPTaskIndex=0;       //任务索引 唯一值
                    iter.value()->containerCode="";     //容器编码 (即胶箱编码) ->唯一
                    iter.value()->Action_agv=0;         //二维码 带举升动作
                    iter.value()->Action_ess=0;         //夹包机器人
                    iter.value()->destpoint=0;          //第一个目标二维码
                    iter.value()->Nextdestpoint=0;      //下一个目标二维码
                    iter.value()->Currentdestpoint=0;   //当前目标二维码
                    iter.value()->actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
                    iter.value()->taskreset=true;       //系统异常关闭时，恢复之前的任务状态
                    iter.value()->ChargeAction=0;       //充电动作指令
                }
                qDebug()<<"手动更新AGV当前动作指令状态--->AGVIP:"<<AGVIP<<" Action:"<<Action;

            }
        }else{
            return;
        }
       ++iter;
   }
}

void taskManagerServer::ON_deleteSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI)
{

    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    QMap<int, SAPExcelInfo> seletSAPExcelInfoTask_;
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {
        if(iter.value().taskId!=nullptr){
            if(seletSAPExcelInfoI.SAPTaskIndex==iter.value().SAPTaskIndex){
                if(seletSAPExcelInfoI.taskType!="Empty" ){
                    /************* 删除任务时判断是否需要更新 本地库存 **************/
                    if(iter.value().taskError==0){
                        shelfBinInfo shelfBinInfoI;
                        if(iter.value().taskType=="IN"){
                            if(iter.value().taskStatus<taskTake_ess){//取箱成功前
                                shelfBinInfoI.status=0;
                            }if(iter.value().taskStatus>=taskTake_ess){
                                shelfBinInfoI.status=2;
                                shelfBinInfoI.LabelNo=iter.value().LabelNo;
                                shelfBinInfoI.SAPTaskIndex=iter.value().SAPTaskIndex;
                                shelfBinInfoI.containerCode=iter.value().containerCode;
                            }
                        }if(iter.value().taskType=="OUT"){
                            if(iter.value().taskStatus<taskFnish_ess){//放箱成功前
                                shelfBinInfoI.status=2;
                                shelfBinInfoI.LabelNo=iter.value().LabelNo;
                                shelfBinInfoI.SAPTaskIndex=iter.value().SAPTaskIndex;
                                shelfBinInfoI.containerCode=iter.value().containerCode;
                            }if(iter.value().taskStatus>=taskFnish_ess){
                                shelfBinInfoI.status=0;
                            }
                        }
                        shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                    }
                }

                iter.value().taskStatus=taskFnish;
                QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                iter.value().taskError=1;           //任务错误代码
                iter.value().errortextEdit=ServerInitItem.taskStatusMap.value("delete");  //异常原因详细信息

                //清除当前升降机任务信息
                LiftCodeStatus_clear(iter.value().SAPTaskIndex);

                seletSAPExcelInfoTask_.insert(iter.value().SAPTaskIndex,iter.value());

                qDebug()<<"deleteSAPExcelInfoTask --->SAPTaskIndex:"<<iter.value().SAPTaskIndex<<iter.value().containerCode;
            }
        }else{
            return;
        }
        ++iter;
    }

    if(!seletSAPExcelInfoTask_.isEmpty()){
        threadQueryI->UP_cancelTaskSAP(seletSAPExcelInfoTask_);
    }if(!shelfBinInfoMap.isEmpty()){
        threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap,"Bindesc");//更新库位状态信息
    }

}

void taskManagerServer::ON_LiftTaskStatus(LiftTask LiftTask0)
{
    //任务锁定状态 status: 0空闲  1 锁定  2到达 0空闲
    QMap<QString,LiftCode>::iterator iter= LiftCodeMap_Info.begin();
    while (iter!=LiftCodeMap_Info.end()) {
        if(iter.key()!=nullptr){
            if(iter.value().codeType=="IN"){//(IN- D100 D103 D105:1可放料,2-3去X楼)
                if(iter.value().codeDesc=="2F-IN"){
                    iter.value().Liftstatus=LiftTask0.LiftD100;
                }if(iter.value().codeDesc=="3F-IN"){
                    iter.value().Liftstatus=LiftTask0.LiftD103;
                }if(iter.value().codeDesc=="4F-IN"){
                    iter.value().Liftstatus=LiftTask0.LiftD105;
                }
                //判断 IN 料框已离开  Liftstatus--->1可放料,2-3去X楼
                if(LiftCodeMap.contains(iter.value().codeDesc)){
                   LiftCode LiftCodeI= LiftCodeMap.find(iter.value().codeDesc).value();
                   if(LiftCodeI.status==2 && iter.value().Liftstatus==1){
                       LiftCodeI.status=0;
                       LiftCodeI.SAPTaskIndex=0;
                       LiftCodeI.containerCode="";
                       LiftCodeMap.find(iter.value().codeDesc).value()=LiftCodeI;
                       qDebug()<<"Lift--料框离开---> codeDesc:"<<LiftCodeI.codeDesc<<" containerCode:"<<LiftCodeI.containerCode;
                   }
                }
            }

            if(iter.value().codeType=="OUT"){//(OUT- D101 D102 D104: 1可取料,2取料完成)
                if(iter.value().codeDesc=="2F-OUT"){
                    iter.value().Liftstatus=LiftTask0.LiftD101;
                }if(iter.value().codeDesc=="3F-OUT"){
                    iter.value().Liftstatus=LiftTask0.LiftD102;
                }if(iter.value().codeDesc=="4F-OUT"){
                    iter.value().Liftstatus=LiftTask0.LiftD104;
                }
                if(LiftCodeMap.contains(iter.value().codeDesc)){
                   LiftCode LiftCodeI= LiftCodeMap.find(iter.value().codeDesc).value();
                   if(LiftCodeI.status==1 && iter.value().Liftstatus==1){
                       LiftCodeI.status=2;
                       LiftCodeMap.find(iter.value().codeDesc).value()=LiftCodeI;
                       qDebug()<<"Lift--料框到达---> codeDesc:"<<LiftCodeI.codeDesc<<" containerCode:"<<LiftCodeI.containerCode;
                   }if(LiftCodeI.status==3 && iter.value().Liftstatus!=1){
                       LiftCodeI.status=0;
                       LiftCodeI.SAPTaskIndex=0;
                       LiftCodeI.containerCode="";
                       LiftCodeMap.find(iter.value().codeDesc).value()=LiftCodeI;
                       qDebug()<<"Lift--料框离开---> codeDesc:"<<LiftCodeI.codeDesc<<" containerCode:"<<LiftCodeI.containerCode;
                   }
                }
            }
        }else{
            return ;
        }
        ++iter;
    }

}

//清除当前升降机任务信息
void taskManagerServer::ON_LiftCodeStatus_clear(LiftCode LiftCodeItem)
{
    QMap<QString,LiftCode>::iterator iter= LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()) {
        if(iter.key()!=nullptr){
            if(iter.value().codeDesc==LiftCodeItem.codeDesc){
                iter.value().status=0;                //任务锁定状态:0空闲  1 锁定  2到达 0空闲
                iter.value().SAPTaskIndex=0;          //任务索引 唯一值
                iter.value().containerCode="";    //容器编码 (即胶箱编码) ->唯一
                qDebug()<<"ON_LiftCodeStatus_clear:"<<LiftCodeItem.codeDesc;
            }
        }else{
            return ;
        }
        ++iter;
    }
}

void taskManagerServer::ON_containerCode_clear(QString shelfBindesc, QString containerCode,QString type)
{
    if(type=="0"){//清除本地库位绑定的信息
        shelfBinInfo shelfBinInfoI;
        QMap<QString,shelfBinInfo>shelfBinInfoMap;
        shelfBinInfoI.shelfBindesc=shelfBindesc;
        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
        threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap,"Bindesc");//更新库位状态信息
        qDebug()<<" 清空本地库位--> containerCode_clear:"<<shelfBindesc<<containerCode;
    }

    if(shelfBindesc!="" && containerCode!=""){
        ESS_Request ESS_RequestI;
        SAPExcelInfo SAPExcelInfoI;
        ESS_RequestI.actionId="action8";
        ESS_RequestI.positionCode=shelfBindesc;
        ESS_RequestI.containerCode=containerCode;

        SAPExcelInfoI.pickDesc_s=shelfBindesc;
        SAPExcelInfoI.containerCode=containerCode;

        ESS_RequestI=ESS_Single::getInstance()->setESS_RequestI(SAPExcelInfoI,ESS_RequestI,ESS_RequestI.actionId);
        if(ESS_RequestI.pathId!=0){
            sapMsgInterface::getInstance()->taskCodes_actionId(ESS_RequestI.iKey,ESS_RequestI,"action8",ESS_RequestI.pathId);
            qDebug()<<" 手动清空库位--容器移出-->containerCode:"<<ESS_RequestI.containerCode<<" positionCode:"<<ESS_RequestI.positionCode;
        }
    }

}

//通过接口创建出入库任务
void taskManagerServer::ON_taskCodes_WW(QString iKey, WWYLPOST WWYLPOSTI, QString UserBadge, int pathId)
{
    sapMsgInterface::getInstance()->taskCodes_WW(iKey,WWYLPOSTI,UserBadge,pathId);
}


