#include "taskmanagerserver.h"

taskManagerServer::taskManagerServer(QObject *parent) : QObject(parent)
{
    taskManagerServerInit();

    StTimer = new QTimer(this);
    connect(StTimer,&QTimer::timeout,this,&taskManagerServer::taskManagerServerTimer);
    StTimer->start(300);

}

void taskManagerServer::taskManagerServerInit()
{
    taskmanagerItem=new taskManager;
    connect(this,&taskManagerServer::sigUP_SAPExcelInfo,taskmanagerItem,&taskManager::ONUP_SAPExcelInfo);
    connect(taskmanagerItem,&taskManager::sig_UPSAPExcelInfoTask,this,&taskManagerServer::ON_UPSAPExcelInfoTask);
    connect(taskmanagerItem,&taskManager::sig_deleteSAPExcelInfoTask,this,&taskManagerServer::ON_deleteSAPExcelInfoTask);


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


    server_=new HttpServer;//ESS 专用
    if(!server_->listen(QHostAddress::Any,58898)){
        qDebug()<<"启动服务器失败 taskManager 58898";
        exit(-1);
    }

    connect(server_,&HttpServer::sig_SAPExcelInfo_new,this,&taskManagerServer::ON_SAPExcelInfo_new);

}

QMap<int, SAPExcelInfo> taskManagerServer::taskProcessTimer(QMap<int, SAPExcelInfo>currentSAPExcelInfoTask)
{
    ESS_Request ESS_RequestI;
    QMap<int, SAPExcelInfo> UPSAPExcelInfoTask;
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {
        if(iter.value().containerCode!=nullptr){
            int startfloor=iter.value().floorId.left(1).toInt();
            int destfloor=iter.value().floorId.right(1).toInt();
            if(iter.value().taskType!="Empty"){//任务类型: OUT MOVE  IN
                if(iter.value().taskStatus==0){//开始创建 ESS 任务
                    bool Request=true;
                    if(iter.value().taskType=="OUT"){
                        ESS_RequestI.actionId="action2";
                        StationInfo StationInfoI=getStationInfo(iter.value().pickDesc_s);//获取当前站点信息
                        qDebug()<<"StationInfo--->"<<StationInfoI.StationDesc<<StationInfoI.containerCode;
                        if(StationInfoI.StationDesc!="" && (StationInfoI.containerCode==""
                             || StationInfoI.containerCode==iter.value().containerCode)){//入库任务一次最多只能下发5个 给ESS
                            setStationInfoMap(iter.value().pickDesc_s,iter.value().containerCode,1,"add");    //设置并更新接驳台状态信息
                        }else{
                            Request=false;
                        }
                    }if(iter.value().taskType=="MOVE"){
                        ESS_RequestI.actionId="action3";
                    }if(iter.value().taskType=="IN"){
                        ESS_RequestI.actionId="action4";
                        StationInfo StationInfoI=getStationInfo(iter.value().sourcestation);//获取当前站点信息
                        //qDebug()<<"StationDesc:"<<StationInfoI.StationDesc<<" TaskIndexListdesc:"<<StationInfoI.TaskIndexListdesc<<StationInfoI.TaskIndexList.size();
                        if(StationInfoI.StationDesc!="" && StationInfoI.containerCode==""){//入库任务一次最多只能下发5个 给ESS
                            setStationInfoMap(iter.value().sourcestation,iter.value().containerCode,1,"add");//设置并更新接驳台状态信息
                        }else{
                            Request=false;
                        }
                    }

                    if(Request){//允许下发给 ESS
                        iter.value().taskStatus++;
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        iter.value().taskId_ess="taskCode-"+QString::number(iter.value().SAPTaskIndex)+"-"+QDateTime::currentDateTime().toString("zzz");

                        ESS_RequestI.containerCode=iter.value().containerCode;
                        UPSAPExcelInfoTask.insert(iter.key(),iter.value());
                        qDebug()<<"taskType:"<<taskType<<" actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;

                        if(!UPSAPExcelInfoTask.isEmpty()){
                            if(ESS_RequestI.actionId!=""){
                                ESS_Single::GetInstance()->setESS_RequestI(UPSAPExcelInfoTask.first(),ESS_RequestI,ESS_RequestI.actionId);
                                qDebug()<<"-->setESS_RequestI actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                            }
                            return currentSAPExcelInfoTask;
                        }
                    }
                }
            }else{

            }
            //实时检查入库端 容器是否到位
            if(iter.value().taskType=="IN" && iter.value().taskStatus==2){
                StationInfo StationInfoI=getStationInfo(iter.value().sourcestation);    //获取当前站点信息
                //qDebug()<<"实时检查入库端 容器是否到位:"<<iter.value().sourcestation<<StationInfoI.containerCode<<StationInfoI.status<<StationInfoI.taskStatus;
                //status状态 0无料框  1有料框 ; taskStatus 任务状态  0空闲  1占用  2正在执行  3执行完成  0空闲
                if(StationInfoI.status==1 && StationInfoI.containerCode==iter.value().containerCode){
                    iter.value().taskStatus=3;//容器到位
                }
            }

            //给ESS 下发 容器到位信号
            if(iter.value().taskType=="IN" && iter.value().taskStatus==3){
                iter.value().taskStatus=4;//容器到位 下发成功
                QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);

                ESS_RequestI.actionId="action6";
                ESS_RequestI.positionCode=iter.value().pickDesc_s;
                ESS_RequestI.containerCode=iter.value().containerCode;
                UPSAPExcelInfoTask.insert(iter.key(),iter.value());

                qDebug()<<"taskType:"<<iter.value().taskType<<" actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                if(!UPSAPExcelInfoTask.isEmpty()){
                    threadQueryI->UP_SAPExcelInfotaskCode(UPSAPExcelInfoTask);//容器到位 下发成功
                    if(ESS_RequestI.actionId!=""){
                        ESS_Single::GetInstance()->setESS_RequestI(UPSAPExcelInfoTask.first(),ESS_RequestI,ESS_RequestI.actionId);
                        qDebug()<<"-->setESS_RequestI actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                    }
                    return currentSAPExcelInfoTask;
                }
            }

            /**************** 出库任务/返空料框 电梯流程部分 **************/
            //判断升降机 进料口 是否允许放料
            if((iter.value().taskType=="OUT" && iter.value().taskStatus==9)
                    || (iter.value().taskType=="Empty" && iter.value().taskStatus==0)){
                if(getLiftCodeMap(QString::number(startfloor)+"F-IN",1,iter.value())){ //判断 2F-IN 是否允许放料
                    iter.value().taskStatus=10;             //进入电梯流程
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
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
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                }
            }

            //判断起始楼层 AGV  是否完成取货
            if(iter.value().taskType!="IN" && iter.value().taskStatus==11){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()>3){//AGV离开（容器离场）
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
                QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                //设置并更新接驳台状态信息
                setStationInfoMap(iter.value().pickDesc_s,iter.value().containerCode,0,"delete");

                if(iter.value().taskType=="OUT"){
                    ESS_RequestI.actionId="action7";//出库时  给ESS 发容器离场
                    ESS_RequestI.positionCode=iter.value().pickDesc_s;
                    ESS_RequestI.containerCode=iter.value().containerCode;
                    UPSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<"容器离场-->taskType:"<<iter.value().taskType<<" actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                    if(!UPSAPExcelInfoTask.isEmpty()){
                        threadQueryI->UP_SAPExcelInfotaskCode(UPSAPExcelInfoTask);//出库时  给ESS 发容器离场
                        if(ESS_RequestI.actionId!=""){
                            ESS_Single::GetInstance()->setESS_RequestI(UPSAPExcelInfoTask.first(),ESS_RequestI,ESS_RequestI.actionId);
                            qDebug()<<"-->setESS_RequestI actionId:"<<ESS_RequestI.actionId<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                        }
                        return currentSAPExcelInfoTask;
                    }
                }

            }

            //判断起始楼层 AGV 是否到达电梯接驳台
            if(iter.value().taskType!="IN" && iter.value().taskStatus==14){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    qDebug()<<"AGV 到达起始电梯接驳台  --->taskId_agv:"<<iter.value().taskId_agv<<" taskStatus:"<<iter.value().taskStatus<<" taskStatusDesc:"<<iter.value().taskStatusDesc;
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()==100){//状态==100 则此次运输任务完成
                        taskId_AGVStatusMap.remove(iter.value().taskId_agv);//SAP与AGV 任务状态绑定
                        iter.value().taskStatus=15;//到达电梯接驳台
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        getLiftCodeMap(QString::number(startfloor)+"F-IN",2,iter.value());//料框到达: 2F-IN
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    }
                }
            }

            //判断 目标楼层 F-OUT 是否允许放料
            if(iter.value().taskType!="IN" && iter.value().taskStatus==15){
                if(getLiftCodeMap(QString::number(destfloor)+"F-OUT",1,iter.value())){
                    iter.value().taskStatus=16;             //前往目标楼层
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                    //升降机的动作指令---单个
                    emit sigsetLiftactionArray(LiftTaskI,startfloor,destfloor);
                    seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<" 前往目标楼层 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                          <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                }
            }

            //读取目标楼层电梯状态，判断是否可以取货
            if(iter.value().taskType!="IN" && iter.value().taskStatus==16){
                if(getLiftCodeMap(QString::number(destfloor)+"F-OUT",2,iter.value())){
                    iter.value().taskStatus=17;//等待目标楼层AGV执行
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                    seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<" 等待目标楼层AGV执行 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                          <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                }
            }

            //等待目标楼层AGV执行
            if(iter.value().taskType!="IN" && iter.value().taskStatus==17){
                StationInfo StationInfoI=getStationInfo(iter.value().destination);//获取当前站点信息 目标站点无料框时方可进去
                if(StationInfoI.StationDesc!="" && StationInfoI.online==1
                        && StationInfoI.status==0){     //状态 0无料框  1有料框
                    SAPExcelInfo SAPExcelInfoI=iter.value();
                    SAPExcelInfoI.taskId_agv="agv"+QDateTime::currentDateTime().toString("ddhhmmss");
                    QString AGVIP=setAGVTCurrentTask(SAPExcelInfoI,startfloor,SAPExcelInfoI.pickDesc_e,"");        //出库时 创建AGV配送任务
                    qDebug()<<"获取目标楼层AGV--->AGVIP"<<AGVIP<<iter.value().SAPTaskIndex<<startfloor<<SAPExcelInfoI.pickDesc_s;
                    if(AGVIP!=""){
                        iter.value().AGVIP=AGVIP;
                        iter.value().taskStatus=18;
                        iter.value().taskId_agv=SAPExcelInfoI.taskId_agv;
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                        if(iter.value().taskType=="Empty"){//返空料框时  到达目标楼层 解锁起始点占用状态
                            setStationInfoMap(iter.value().sourcestation,iter.value().containerCode,0,"delete");//设置并更新接驳台状态信息
                        }
                        qDebug()<<" 目标楼层AGV执行 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                               <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    }
                }else{
                    //qDebug()<<"目标站点异常无法前往:--->"<<iter.value().destination<<" online:"<<StationInfoI.online<<" status:"<<StationInfoI.status;
                }
            }

            if(iter.value().taskType!="IN" && iter.value().taskStatus==18){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()>3){//离开目标电梯 取货点
                        iter.value().taskStatus=20;                                 //离开目标电梯 取货点
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                        qDebug()<<" 目标楼层AGV执行 SAPTaskIndex:"<<iter.value().SAPTaskIndex
                              <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    }
                }
            }

            //判断目标楼层AGV 执行 状态
            if(iter.value().taskType!="IN" && iter.value().taskStatus==19){
                if(taskId_AGVStatusMap.contains(iter.value().taskId_agv)){
                    if(taskId_AGVStatusMap.find(iter.value().taskId_agv).value()==100){//状态==100 则此次运输任务完成
                        taskId_AGVStatusMap.remove(iter.value().taskId_agv);//SAP与AGV 任务状态绑定
                        iter.value().taskStatus=100;//任务完成
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                        qDebug()<<" 目标楼层AGV任务完成  SAPTaskIndex:"<<iter.value().SAPTaskIndex
                              <<" taskStatus:"<<iter.value().taskStatus<<" containerCode:"<<iter.value().containerCode;
                    }
                }
            }

        }else {
            qDebug()<<"QMap_ 数组指针越界，执行失败--taskProcessTimer"<<iter.value().containerCode;
           return currentSAPExcelInfoTask;
        }
        iter++;
    }

    if(!seletSAPExcelInfoTask.isEmpty()){
        threadQueryI->UP_SAPExcelInfotaskCode(seletSAPExcelInfoTask);//更新任务状态信息
    }
    return currentSAPExcelInfoTask;
}

QMap<int, SAPExcelInfo> taskManagerServer::ProcessMsgRecv(QMap<int, SAPExcelInfo>currentSAPExcelInfoTask)
{
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;  
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while (iter!=currentSAPExcelInfoTask.end()) {

        if(iter.value().containerCode!=nullptr){
            ReplyMsg ReplyMsgI=sapMsgInterface::getInstance()->GetMsgRecv_Msg(iter.value().taskId_ess);
            if(ReplyMsgI.keyId!=""){
                if(ReplyMsgI.status==0){
                    iter.value().taskStatus=iter.value().taskStatus+1;
                    QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                    iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                    seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                }else{
                    iter.value().taskStatus=iter.value().taskStatus-1;
                    setStationInfoMap(iter.value().sourcestation,iter.value().containerCode,0,"delete");//设置并更新接驳台状态信息
                }
                QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                qDebug()<<"post GetMsgRecv_Msg---->SAPTaskIndex:"<<iter.value().SAPTaskIndex<<" taskType:"<<iter.value().taskType
                       <<" containerCode:"<<iter.value().containerCode<<" taskId_ess:"<<iter.value().taskId_ess<<" taskStatus:"<<iter.value().taskStatus
                      <<" taskStatusDesc:"<<iter.value().taskStatusDesc<<" eventCodeDesc:"<<ServerInitItem.eventCodeMap.value(ReplyMsgI.errorMsg).eventCodeDesc;
            }else{
                QString eventCodeDesc=ESS_Single::GetInstance()->getCurrentESS_Repost(iter.value().taskId_ess);
                if(eventCodeDesc!=""){
                    if(iter.value().taskType=="IN"){
                        if(eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成" ){
                            iter.value().taskStatus=100;
                            iter.value().taskStatusDesc="任务完成";     //判断升降机是否空闲  创建AGV运输任务
                        }if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=6;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                            setStationInfoMap(iter.value().sourcestation,iter.value().containerCode,0,"delete");//设置并更新接驳台状态信息
                        }
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    }if(iter.value().taskType=="OUT"){
                        if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=4;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                        }if((eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成")
                                 && iter.value().taskStatus<9){
                            iter.value().taskStatus=9;
                            iter.value().taskStatusDesc="等待运输";     //判断升降机是否空闲  创建AGV运输任务
                        }if(iter.value().taskStatusDesc=="任务失败"){
                            iter.value().taskStatus=100;
                            iter.value().taskStatusDesc="任务失败";     //判断升降机是否空闲  创建AGV运输任务
                        }
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());

                    }if(iter.value().taskType=="MOVE"){
                        if(eventCodeDesc=="取箱成功"){
                            iter.value().taskStatus=4;
                            iter.value().taskStatusDesc=eventCodeDesc;     //判断升降机是否空闲  创建AGV运输任务
                        }if((eventCodeDesc=="放箱成功" || eventCodeDesc=="任务完成")
                                 && iter.value().taskStatus<9){
                            iter.value().taskStatus=100;
                            iter.value().taskStatusDesc="任务完成";     //判断升降机是否空闲  创建AGV运输任务
                        }if(eventCodeDesc=="任务失败"){
                            iter.value().taskStatus=100;
                            iter.value().taskStatusDesc="任务失败";     //判断升降机是否空闲  创建AGV运输任务
                        }
                        seletSAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    }

                    qDebug()<<"ESS_任务状态反馈---->SAPTaskIndex:"<<iter.value().SAPTaskIndex<<" taskType:"<<iter.value().taskType
                           <<" containerCode:"<<iter.value().containerCode<<" taskId_ess:"<<iter.value().taskId_ess
                          <<" eventCodeDesc:"<<eventCodeDesc<<" --- taskStatus:"<<iter.value().taskStatus<<iter.value().taskStatusDesc;
                }

            }

            if(iter.value().taskType!="Empty"){//实时更新（60s）
                qint64 taskminutes = iter.value().taskTimer.secsTo(QDateTime::currentDateTime());      //状态更新时间
                qint64 finishminutes = iter.value().finishTimer.secsTo(QDateTime::currentDateTime());  //任务完成时间差
                //qDebug()<<iter.value().taskType<<finishminutes<<taskminutes<<iter.value().taskTimer<<iter.value().finishTimer;
                if(finishminutes<3600 && taskminutes>=15){//一个小时以内 定时更新状态
                    iter.value().taskTimer=QDateTime::currentDateTime();
                    emit sigUP_SAPExcelInfo(iter.value());                //定时往 MES 更新 任务状态信息
                }
            }

            qint64 finishdays = iter.value().finishTimer.daysTo(QDateTime::currentDateTime());  //任务完成时间差
            if(seletSAPExcelInfoTask.isEmpty() && finishdays>=2){//及时清除缓存
                currentSAPExcelInfoTask.remove(iter.key());
                return currentSAPExcelInfoTask;
            }
        }else {
            qDebug()<<"QMap 数组指针越界，执行失败--taskProcessTimer"<<iter.value().containerCode;
           return currentSAPExcelInfoTask;
        }
        iter++;
    }

    if(!seletSAPExcelInfoTask.isEmpty()){
        threadQueryI->UP_SAPExcelInfotaskCode(seletSAPExcelInfoTask);//更新任务状态信息
    }

    return currentSAPExcelInfoTask;
}

QString taskManagerServer::setAGVTCurrentTask(SAPExcelInfo SAPExcelInfoI,int Floor, QString sourcestation,QString destination)
{
    AGVTWaitTask AGVTWaitTaskI;
    StationInfo StationInfo_s=getStationInfo(sourcestation);        //获取 起始站点 二维码信息
    StationInfo StationInfo_e=getStationInfo(destination);          //获取 目标站点 二维码信息
    QMap<QString,AGVCurrentTask>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=AGVCurrentTaskMap.end() && iter.key()!=nullptr){
            if(iter.value().taskisok && iter.value().ChargeAction==0){//初始化完成 且无充电任务的状态下
                if(iter.value().taskId=="" && iter.value().floornum==Floor){
                    iter.value().taskId=SAPExcelInfoI.taskId_agv;               //唯一识别号
                    iter.value().taskType=SAPExcelInfoI.taskType;               //任务类型 IN入库  OUT出库
                    iter.value().SAPTaskIndex=SAPExcelInfoI.SAPTaskIndex;       //任务索引 唯一值
                    iter.value().containerCode=SAPExcelInfoI.containerCode;     //容器编码 (即胶箱编码) ->唯一
                    iter.value().Action_agv=0;                                  //二维码 带举升动作
                    iter.value().Action_ess=0;                                  //夹包机器人
                    if(destination==""){
                        iter.value().destpoint=StationInfo_s.currentpoint;      //第一个目标二维码
                        iter.value().Nextdestpoint=StationInfo_s.liftpoint;     //下一个目标二维码
                    }else{
                        iter.value().destpoint=StationInfo_e.liftpoint;         //第一个目标二维码
                        iter.value().Nextdestpoint=StationInfo_e.currentpoint;  //下一个目标二维码
                    }

                    iter.value().Currentdestpoint=iter.value().destpoint;       //当前目标二维码
                    qDebug()<<"setAGVIP--> sourcestation:"<<sourcestation<<" destination:"<<destination;
                    qDebug()<<"setAGVIP--> AGVIP:"<<iter.value().AGVIP<<" taskisok:"<<iter.value().taskisok
                           <<" Currentpoint:"<<iter.value().Currentpoint<<" RotaryState"<<iter.value().RotaryState
                           <<" destpoint:"<<iter.value().destpoint<<" Nextdestpoint:"<<iter.value().Nextdestpoint<<" Currentdestpoint:"<<iter.value().Currentdestpoint
                          <<" Action_agv:"<<iter.value().Action_agv<<" containerCode:"<<iter.value().containerCode;

                    return iter.value().AGVIP;
                }
            }
        }else{
            return "";
        }
       iter++;
    }
    return "";
}


void taskManagerServer::InsertISAPAction()
{
    if(ThreadInsertI->ActionItiem.SAPAction > 1){//0 无状态 1 执行更新 2 更新完成  3 执行取消  4取消完成
        if(ThreadInsertI->ActionItiem.SAPAction==2){
            newSAPExcelInfoList.clear();
            ThreadInsertI->ActionItiem.SAPAction =0;
        }
        if(ThreadInsertI->ActionItiem.SAPAction==4){
            ThreadInsertI->ActionItiem.SAPAction =0;
        }
    }
}

StationInfo taskManagerServer::getStationInfoMap(QString Station_Type)
{
    StationInfo StationInfoI;
    QMap<QString,StationInfo >::const_iterator iter=currentStationInfoMap.begin();
    while (iter!=currentStationInfoMap.end()) {
        if(iter.value().StationType==Station_Type && iter.value().enable==1){
            if(StationInfoI.StationId==0){
                StationInfoI=iter.value();
            }if(iter.value().TaskIndexList.size() < StationInfoI.TaskIndexList.size()){
                StationInfoI=iter.value();
            }
        }
        iter++;
    }
    return StationInfoI;
}

StationInfo taskManagerServer::getStationInfo(QString StationDesc)
{
    StationInfo StationInfoI;
    QMap<QString ,StationInfo >::const_iterator iter=currentStationInfoMap.begin();
    while (iter!=currentStationInfoMap.end()) {
        if(iter != nullptr){
            if(iter.value().StationDesc==StationDesc){
                return iter.value();
            }
        }else{
            return StationInfoI;
        }
        iter++;
    }
    return StationInfoI;
}

void taskManagerServer::setStationInfoMap(QString StationDesc,QString containerCode,int orderStatus,QString orderType)
{
    QMap<int,StationInfo>StationInfoMap;
    QMap<QString ,StationInfo >::iterator iter=currentStationInfoMap.begin();
    while (iter!=currentStationInfoMap.end()) {
        if(iter.value().StationDesc==StationDesc){
            iter.value().taskStatus=orderStatus;//任务状态  0空闲  1锁定
            if((orderType=="add" || orderType=="update") && containerCode!=""){
                iter.value().containerCode=containerCode;
                if(!iter.value().TaskIndexList.contains(containerCode)){
                    iter.value().TaskIndexList.append(containerCode);
                    iter.value().TaskIndexListdesc=iter.value().TaskIndexList.join("&");
                }
            }if(orderType=="delete" && containerCode!=""){
                if(iter.value().containerCode==containerCode){
                    iter.value().containerCode="";
                }if(iter.value().TaskIndexList.contains(containerCode)){
                    iter.value().TaskIndexList.removeAll(containerCode);
                    iter.value().TaskIndexListdesc=iter.value().TaskIndexList.join("&");
                }
            }if(orderType=="lock" && containerCode!=""){//只是锁定
                if(!iter.value().TaskIndexList.contains(containerCode)){
                    iter.value().TaskIndexList.append(containerCode);
                    iter.value().TaskIndexListdesc=iter.value().TaskIndexList.join("&");
                }
            }
            StationInfoMap.insert(iter.value().StationId,iter.value());
            qDebug()<<"---setStationInfoMap orderType:"<<orderType<<" StationDesc:"<<iter.value().StationDesc
                   <<" containerCode:"<<iter.value().containerCode<<" orderStatus:"<<orderStatus
                   <<iter.value().TaskIndexListdesc<<iter.value().TaskIndexList.size();

        }
        iter++;
    }

    if(!StationInfoMap.isEmpty()){
        threadQueryI->setStationInfo_Status(StationInfoMap);                //更新 站点 的实时状态信息sql
        ESS_Single::GetInstance()->UP_StationInfoMap(currentStationInfoMap);//更新 站点 的实时状态信息链表
    }

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
//                qDebug()<<" codeDesc:"<<codeDesc<<" action:"<<action<<" SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex
//                      <<" taskStatus:"<<SAPExcelInfoI.taskStatus<<" containerCode:"<<SAPExcelInfoI.containerCode;

                if(iter.value().codeType=="IN"){
                    //判断 IN 料框是否允许放料  Liftstatus--->1可放料,2-3去X楼
                    if(iter.value().SAPTaskIndex==0 && iter.value().Liftstatus==1 && action==1){
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
                    if(iter.value().SAPTaskIndex==0 && iter.value().Liftstatus!=1 && action==1){
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
            qDebug()<<" LiftCodeMap  越界";
            return false;
        }
        iter++;
    }

    ESS_Single::GetInstance()->setLiftCodeMap(LiftCodeMap);
    return codeDesc_;
}

QMap<int, SAPExcelInfo> taskManagerServer::getcurrentSAPExcelInfoTask(QMap<int, SAPExcelInfo> SAPExcelInfoTask)
{
    QMap<int, SAPExcelInfo>::const_iterator iter= CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()){
        if(iter!=nullptr){
            if(!SAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
                SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
            }else{
                int taskStatus=iter.value().taskStatus-SAPExcelInfoTask.value(iter.value().SAPTaskIndex).taskStatus;
                if(taskStatus>=3){
                    SAPExcelInfoTask.insert(iter.value().SAPTaskIndex,iter.value());
                    qDebug()<<"taskManagerServer-->任务状态变化:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<iter.value().taskStatusDesc;
                }
                //qDebug()<<"SAPTaskIndex1:"<<iter.value().SAPTaskIndex<<iter.value().taskStatus<<iter.value().taskStatusDesc;
            }
        }
        iter++;
    }
    return SAPExcelInfoTask;
}

bool taskManagerServer::newSAPExcelInfo_Empty(QString tasktype, StationInfo StationInfoI)
{
    SAPExcelInfo SAPExcelInfoI;
    SAPExcelInfoI.taskType="Empty";                       //任务类型
    SAPExcelInfoI.taskTypeDesc="返空箱";
    SAPExcelInfoI.taskId="taskId"+QDateTime::currentDateTime().toString("hhmmsszzz");         //任务编码 唯一性
    SAPExcelInfoI.containerCode="Code-"+StationInfoI.StationDesc;

    SAPExcelInfoI.sourcestation=StationInfoI.StationDesc;
    SAPExcelInfoI.destination="STATION-02";//二楼空料框返回 接驳台
    SAPExcelInfoI.floorId=SAPExcelInfoI.sourcestation.left(1)+"-"+"2";         //楼层走向  2F-3F 3F-2F

    SAPExcelInfoI.taskStatus=0;                            //任务状态
    QString taskType_=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
    SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType_);
    SAPExcelInfoI.creatTimer=QDateTime::currentDateTime();
    if(SAPExcelInfoI.taskId!=""){
       ON_SAPExcelInfo_new(SAPExcelInfoI);
    }
    return true;
}


void taskManagerServer::taskManagerServerTimer()
{
    InsertISAPAction();                        //实时sql数据库写入状态
    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
    CurrentServerItem=ESS_Single::GetInstance()->getCurrentServerItem();

    if(AGVCurrentTaskMap.isEmpty()){
        AGVCurrentTaskMap=CurrentServerItem.AGVCurrentTaskMap;
    }if(currentStationInfoMap.isEmpty()){
        currentStationInfoMap=CurrentServerItem.StationInfoMap;
    }if(LiftCodeMap.isEmpty()){
        LiftCodeMap=CurrentServerItem.LiftCodeMap;
    }if(server_->ServerInitItem.eventCodeMap.isEmpty()){
        server_->ServerInitItem.eventCodeMap=ServerInitItem.eventCodeMap;
    }

    currentSAPExcelInfoTask=getcurrentSAPExcelInfoTask(currentSAPExcelInfoTask);

    TableWidgetcount++;
    if(countbool){
       countbool=false;
       if(TableWidgetcount%2==1){//偶数
           InsertISAPAction();  //实时检查 MES 下发的信任务
//           if(TableWidgetcount%10==0){
//                threadQueryI->setAGVCurrentTaskMap_Status(AGVCurrentTaskMap);        //更新AGV状态信息
//           }if(TableWidgetcount%20==0){
//               threadQueryI->setLiftCodeMap_Status(LiftCodeMap);                          //更新接升降机状态信息
//           }
       }else {
           if(TableWidgetcount%5==0){
               currentSAPExcelInfoTask=taskProcessTimer(currentSAPExcelInfoTask);  //实时判断任务状态 及处理
           }else{
               currentSAPExcelInfoTask=ProcessMsgRecv(currentSAPExcelInfoTask);    //实时判断ESS 接口返回数据
           }
       }
       countbool=true;
    }

    if(TableWidgetcount>10000){TableWidgetcount=0;}

}

void taskManagerServer::ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI)
{
    if(!newSAPExcelInfoList.contains(SAPExcelInfoI.containerCode)){
        if(SAPExcelInfoI.taskType=="OUT"){
             StationInfo StationInfoI = getStationInfoMap("OUT");   //获取当前任务数最少的 接驳台
             if(StationInfoI.StationId!=0 && SAPExcelInfoI.pickDesc_s==""){
                SAPExcelInfoI.pickDesc_s=StationInfoI.StationDesc;  //起始站点的对接码头
                setStationInfoMap(StationInfoI.StationDesc,SAPExcelInfoI.containerCode,1,"lock");    //设置并更新接驳台状态信息
             }
             shelfBinInfo shelfBinInfoI= ESS_Single::GetInstance()->getcontainerCode_desc(SAPExcelInfoI.containerCode);//出库时获取当前胶箱库位
             if(shelfBinInfoI.shelfBinIndex!=0){
                 SAPExcelInfoI.podIdDesc=shelfBinInfoI.podIdDesc;        //所属架位注释 -- MES
                 SAPExcelInfoI.shelfBindesc=shelfBinInfoI.shelfBindesc;  //所属架位注释 -- ESS
             }
             if(SAPExcelInfoI.LabelNo==""){
                 SAPExcelInfoI.LabelNo="LabelNo-IN";//默认工单凭证号
             }
             SAPExcelInfoI.floorId="2-"+SAPExcelInfoI.destination.left(1);//楼层走向  2F-3F 3F-2F
             qDebug()<<" StationId:"<<StationInfoI.StationId<<" StationDesc:"<<StationInfoI.StationDesc;
        }

        if(SAPExcelInfoI.taskType=="IN"){
            shelfBinInfo shelfBinInfoI= ESS_Single::GetInstance()->getshelfBinInfo_Empty(SAPExcelInfoI);//入库时获取空闲的 库位
            if(shelfBinInfoI.shelfBinIndex!=0){
                SAPExcelInfoI.pickDesc_s="STATION-01";
                SAPExcelInfoI.podIdDesc=shelfBinInfoI.podIdDesc;
                SAPExcelInfoI.destination=shelfBinInfoI.podIdDesc;
                SAPExcelInfoI.shelfBindesc=shelfBinInfoI.shelfBindesc;
            }
            if(SAPExcelInfoI.LabelNo==""){
                SAPExcelInfoI.LabelNo="LabelNo-IN";//默认工单凭证号
            }

            shelfBinInfoI.status=1;//0 空闲  1任务占用中
            shelfBinInfoI.containerCode=SAPExcelInfoI.containerCode;
            shelfBinInfoI.LabelNo=SAPExcelInfoI.LabelNo;

            QMap<QString,shelfBinInfo>shelfBinInfoMap;
            shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
            threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap);//更新库位状态信息
        }

        if(SAPExcelInfoI.taskType=="MOVE"){
            shelfBinInfo shelfBinInfoI_s= ESS_Single::GetInstance()->getcontainerCode_desc(SAPExcelInfoI.containerCode);
            shelfBinInfo shelfBinInfoI_e= ESS_Single::GetInstance()->getshelfBinInfo_Empty(SAPExcelInfoI);
            SAPExcelInfoI.oldIdDesc=shelfBinInfoI_s.podIdDesc;       //所属架位注释 -- MES
            SAPExcelInfoI.oldBinDesc=shelfBinInfoI_s.shelfBindesc;   //改架前的 Bin   (用于AGV内部移库) -- ESS
            SAPExcelInfoI.newIdDesc=shelfBinInfoI_e.podIdDesc;       //所属架位注释 -- MES
            SAPExcelInfoI.newBinDesc=shelfBinInfoI_e.shelfBindesc;   //改架后的 Bin   (用于AGV内部移库) -- ESS
        }

        if(SAPExcelInfoI.taskType=="Empty"){
            SAPExcelInfoI.pickDesc_s=SAPExcelInfoI.sourcestation;     //起始站点的对接码头
            SAPExcelInfoI.pickDesc_e=SAPExcelInfoI.destination;       //目标站点的对接码头
            setStationInfoMap(SAPExcelInfoI.sourcestation,SAPExcelInfoI.containerCode,1,"add");    //设置并更新接驳台状态信息
        }

        QString taskType=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
        SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
        if(SAPExcelInfoI.sourcestation!="" && SAPExcelInfoI.destination!=""){
            newSAPExcelInfoList.insert(SAPExcelInfoI.taskId,SAPExcelInfoI);
            if(ThreadInsertI->newSAPExcelInfoTask(newSAPExcelInfoList)){//(把创建成功的任务 存入数据库)
                qDebug()<<"taskManager new task--S->  任务类型:"<<SAPExcelInfoI.taskType<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                       <<" 产品编码:"<<SAPExcelInfoI.Material<<newSAPExcelInfoList.size();
                newSAPExcelInfoList.clear();
            }
        }else{
            qDebug()<<"taskManager new task--E->  任务类型:"<<SAPExcelInfoI.taskType<<" 胶箱编码:"<<SAPExcelInfoI.containerCode
                   <<" 产品编码:"<<SAPExcelInfoI.Material<<newSAPExcelInfoList.size();
        }

    }

}

void taskManagerServer::ON_AGVMoveTask(QString AGVIP, QString taskType, AGVCurrentTask AGVCurrentTaskI)
{
    qDebug()<<"手动创建AGV搬运任务--->AGVIP:"<<AGVIP<<" taskType:"<<taskType<<" destpoint:"<<AGVCurrentTaskI.destpoint
           <<" Nextdestpoint:"<<AGVCurrentTaskI.Nextdestpoint;

    QMap<QString,AGVCurrentTask>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=AGVCurrentTaskMap.end() && iter.key()!=nullptr){
            if(iter.value().AGVIP==AGVIP){//初始化完成 且无任务的状态下
                if(iter.value().taskisok && iter.value().taskId==""){
                    if(taskType=="charge"){
                        iter.value().ChargeAction=1;//开始充电
                    }if(taskType=="charge_"){
                        iter.value().ChargeAction=4;//结束充电
                    }
                }

                if(taskType=="add"){
                    if(iter.value().taskisok && iter.value().destpoint==0 && iter.value().containerCode==""){
                        iter.value().taskId="AGV-"+QDateTime::currentDateTime().toString("hhmmss");            //唯一识别号
                        iter.value().taskType="AGV";            //任务类型 IN入库  OUT出库
                        iter.value().SAPTaskIndex=0;            //任务索引 唯一值
                        iter.value().containerCode="container"; //容器编码 (即胶箱编码) ->唯一

                        iter.value().Action_agv=0;
                        iter.value().destpoint=AGVCurrentTaskI.destpoint;
                        iter.value().Nextdestpoint=AGVCurrentTaskI.Nextdestpoint;
                        iter.value().actionType=AGVCurrentTaskI.actionType;             //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返回
                        iter.value().actionTimerCount=AGVCurrentTaskI.actionTimerCount; //倒计时 计数
                        iter.value().Currentdestpoint=AGVCurrentTaskI.destpoint;        //当前目标二维码
                        qDebug()<<"手动创建AGV搬运任务--->AGVIP:"<<AGVIP<<iter.value().taskisok<<" destpoint:"<<iter.value().destpoint;
                    }
                }

                if(taskType=="clear"){
                    iter.value().taskId="";            //唯一识别号
                    iter.value().taskType="";          //任务类型 IN入库  OUT出库
                    iter.value().SAPTaskIndex=0;       //任务索引 唯一值
                    iter.value().containerCode="";     //容器编码 (即胶箱编码) ->唯一
                    iter.value().Action_agv=0;         //二维码 带举升动作
                    iter.value().Action_ess=0;         //夹包机器人
                    iter.value().destpoint=0;          //第一个目标二维码
                    iter.value().Nextdestpoint=0;      //下一个目标二维码
                    iter.value().Currentdestpoint=0;   //当前目标二维码
                    iter.value().actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
                    qDebug()<<"手动清除AGV搬运任务--->AGVIP:"<<AGVIP<<iter.value().taskisok<<" destpoint:"<<iter.value().destpoint;
                }

            }
        }else{
            return;
        }
       iter++;
    }
}

void taskManagerServer::ON_AgvStateWidget(agvState agvStateItemI)
{

//    qDebug()<<"taskManager: "<<agvStateItemI.agvIp<<agvStateItemI.agvFinishInit<<agvStateItemI.passPointState
//       <<agvStateItemI.isFrontLaserNearInducedState<<agvStateItemI.currentBatteryVoltageState
//      <<AGVCurrentTaskMap.size();

    QMap<QString,AGVCurrentTask>::iterator iter= AGVCurrentTaskMap.begin();
    while (iter!=AGVCurrentTaskMap.end()) {
        if(iter!=AGVCurrentTaskMap.end() &&iter.key()!=nullptr){

            if(iter.value().AGVIP==agvStateItemI.agvIp){
                int Currentpoint=agvStateItemI.passPointState.toInt();                      //最新读到的二维码
                iter.value().Currentpoint=Currentpoint;
                iter.value().RotaryState=agvStateItemI.currentRotaryHeightState.toInt();    //当前转盘高度 mm
                iter.value().VoltageState=agvStateItemI.currentBatteryVoltageState.toInt(); //当前电压值 mv
                iter.value().RunStatus=agvStateItemI.RunStatus;                             //当前运行状态  1 运行 2 停止
                int agverror=agvStateItemI.currentErrorCodeState.toInt();                   //AGV当前错误代码
                QString TaskNumberState=agvStateItemI.currentCompletedTaskNumberState;      //AGV当前完成的任务编号
                iter.value().Currentpointcount++;
                if(iter.value().Currentpointcount>10000){iter.value().Currentpointcount=0;}

                if(agvStateItemI.agvFinishInit && agvStateItemI.isOnline && agverror==0){
                      iter.value().taskisok=true;   //AGV 初始化完成 且 无任务错误代码
                      if(iter.value().VoltageState<5100 && iter.value().taskId==""){//进入充电流程
                          iter.value().ChargeAction=1;
                          iter.value().Currentdestpoint=iter.value().ChargePoint;
                      }if(iter.value().lastTaskId!="" && iter.value().taskType!="AGV"){//绑定上一个 已完成的 任务 id
                          taskId_AGVStatusMap.insert(iter.value().lastTaskId,100);
                      }
                }else {
                      iter.value().taskisok=false;
                }

                agvORderTask agvORderTaskI;
                if(iter.value().taskisok && iter.value().ChargeAction>0){
                   if(iter.value().ChargeAction==1){//前往充电点二维码
                        iter.value().ChargeAction=2;
                        iter.value().Currentdestpoint=iter.value().ChargePoint;
                        emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),1,0,agvORderTaskI);
                    }if(iter.value().ChargeAction==2 &&  iter.value().Currentpoint==iter.value().Currentdestpoint){
                        iter.value().ChargeAction=3;  //到达充电点 开始充电倒计时
                        iter.value().ChargeTimer_=QDateTime::currentDateTime();
                        qDebug()<<"开始充电计时-->AGVIP:"<<iter.value().AGVIP<<" ChargeAction:"<<iter.value().ChargeAction<<" ChargeTimer_:"<<QDateTime::currentDateTime();
                    }if(iter.value().ChargeAction==3 &&  iter.value().Currentpoint==iter.value().ChargePoint){
                        qint64 ChargeTimer_ = iter.value().ChargeTimer_.secsTo(QDateTime::currentDateTime());
                        if(ChargeTimer_>=1800){//60*60=3600 一个小时
                            iter.value().ChargeAction=4;
                            qDebug()<<"结束充电任务-->AGVIP:"<<iter.value().AGVIP<<" ChargeAction:"<<iter.value().ChargeAction<<" ChargeTimer_:"<<QDateTime::currentDateTime();
                        }
                    }if(iter.value().ChargeAction==4 &&  iter.value().Currentpoint==iter.value().ChargePoint){
                        iter.value().ChargeAction=5;
                        iter.value().Currentdestpoint=iter.value().waitPoint;
                        emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),1,0,agvORderTaskI);
                    }if(iter.value().ChargeAction==5 &&  iter.value().Currentpoint==iter.value().waitPoint){
                        iter.value().ChargeAction=0;
                    }
                    //qDebug()<<"--> AGVIP:"<<iter.value().AGVIP<<" ChargeAction:"<<iter.value().ChargeAction;
                }

                if(iter.value().taskisok && iter.value().taskId!="" && iter.value().containerCode!=""){
                    if(iter.value().taskType!="AGV"){
                        taskId_AGVStatusMap.insert(iter.value().taskId,iter.value().Action_agv);//SAP与AGV 任务状态绑定
                    }

                    qDebug()<<" AGVIP:"<<iter.value().AGVIP<<" taskisok:"<<iter.value().taskisok
                           <<" Currentpoint:"<<iter.value().Currentpoint<<" RotaryState"<<iter.value().RotaryState
                           <<" destpoint:"<<iter.value().destpoint<<" Nextdestpoint:"<<iter.value().Nextdestpoint<<" Currentdestpoint:"<<iter.value().Currentdestpoint
                          <<" Action_agv:"<<iter.value().Action_agv<<" containerCode:"<<iter.value().containerCode;

                    if(iter.value().Action_agv==0){          //前往起始站点
                        if(iter.value().RotaryState>=3){     //确保托盘状态为降下
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),4,0,agvORderTaskI);
                            return;
                        }
                        if(iter.value().Currentpoint==iter.value().Currentdestpoint){
                            iter.value().Action_agv=2;       //开始举升
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),3,0,agvORderTaskI);
                        }else{
                            iter.value().Action_agv=1;
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),1,0,agvORderTaskI);
                        }
                    }

                    if(iter.value().Currentpoint==iter.value().Currentdestpoint
                            &&iter.value().Action_agv==1){   //到达起始站点
                            iter.value().Action_agv=2;       //开始举升
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),3,0,agvORderTaskI);
                    }

                    if(iter.value().Currentpoint==iter.value().Currentdestpoint
                            &&iter.value().Action_agv==1){   //到达起始站点
                            iter.value().Action_agv=2;       //开始举升
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),3,0,agvORderTaskI);
                    }

                    if(iter.value().Currentpoint==iter.value().Currentdestpoint
                            && iter.value().Action_agv==2 && iter.value().RotaryState>=50){
                            iter.value().Action_agv=3;       //举升到位 开始前往目标站点
                            iter.value().Currentdestpoint=iter.value().Nextdestpoint;
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),1,0,agvORderTaskI);
                    }

                    if(iter.value().Currentpoint!=iter.value().destpoint
                            && iter.value().Action_agv==3 && iter.value().RotaryState>=50){
                            iter.value().Action_agv=4;       //AGV 离开取货点
                    }

                    if(iter.value().Currentpoint==iter.value().Currentdestpoint
                            && iter.value().Action_agv==4 && iter.value().RotaryState>=50){
                        if(iter.value().actionType==1){   //动作类型 actionType=0到达站点不需要返回  1到达站点倒计时结束后返回
                            iter.value().Action_agv=10;
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),4,0,agvORderTaskI);
                        }else{
                            iter.value().Action_agv=5;       //到达目标站点 托盘开始下降
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),4,0,agvORderTaskI);
                        }
                    }

                    if(iter.value().Currentpoint==iter.value().Currentdestpoint
                            && iter.value().Action_agv==5 && iter.value().RotaryState<=3){

                        iter.value().lastTaskId=iter.value().taskId;
                        iter.value().taskId="";            //唯一识别号
                        iter.value().taskType="";          //任务类型 IN入库  OUT出库
                        iter.value().SAPTaskIndex=0;       //任务索引 唯一值
                        iter.value().containerCode="";     //容器编码 (即胶箱编码) ->唯一
                        iter.value().Action_agv=0;         //二维码 带举升动作
                        iter.value().Action_ess=0;         //夹包机器人
                        iter.value().destpoint=0;          //第一个目标二维码
                        iter.value().Nextdestpoint=0;      //下一个目标二维码
                        iter.value().Currentdestpoint=0;   //当前目标二维码
                        iter.value().actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
                        if(iter.value().containerCode!=""){

                        }else{//返回待机点
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().waitPoint),1,0,agvORderTaskI);
                        }
                        taskId_AGVStatusMap.insert(iter.value().taskId,100);//SAP与AGV 任务状态绑定  100-任务完成
                        qDebug()<<"AGV搬运任务完成--->AGVIP:"<<iter.value().AGVIP<<" taskId:"<<iter.value().taskId
                               <<" Action_agv:"<<iter.value().Action_agv<<" size():"<<taskId_AGVStatusMap.size();
                    }

                    //返回起始站点流程
                    if(iter.value().Currentpoint==iter.value().Currentdestpoint && iter.value().Action_agv>=10){

                        if(iter.value().Action_agv==10 && iter.value().RotaryState<=3){
                            iter.value().Action_agv=11;                                     //在终点执行举升动作
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),3,0,agvORderTaskI);
                            return;
                        }if(iter.value().Action_agv==11 && iter.value().RotaryState>=50){
                            iter.value().Action_agv=12;                                        //举升到位 返回起始点
                            iter.value().Currentdestpoint=iter.value().destpoint;
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),1,0,agvORderTaskI);
                            return;
                        }if(iter.value().Action_agv==12 && iter.value().RotaryState>=50){
                            iter.value().Action_agv=13;                                     //到达起始点 执行下降动作
                            emit sigAGVMoveTask(iter.value().AGVIP,quint16(iter.value().Currentpoint), quint16(iter.value().Currentdestpoint),4,0,agvORderTaskI);
                            return;
                        }if(iter.value().Action_agv==13 && iter.value().RotaryState<=3){    //在起始点 完成下降动作
                            iter.value().taskId="";            //唯一识别号
                            iter.value().taskType="";          //任务类型 IN入库  OUT出库
                            iter.value().SAPTaskIndex=0;       //任务索引 唯一值
                            iter.value().containerCode="";     //容器编码 (即胶箱编码) ->唯一
                            iter.value().Action_agv=0;         //二维码 带举升动作
                            iter.value().Action_ess=0;         //夹包机器人
                            iter.value().destpoint=0;          //第一个目标二维码
                            iter.value().Nextdestpoint=0;      //下一个目标二维码
                            iter.value().Currentdestpoint=0;   //当前目标二维码
                            iter.value().actionType=0;         //动作类型 0到达站点不需要返回  1到达站点倒计时结束后返
                        }

                    }

                }

            }

        }else{
            return ;
        }

        iter++;
    }

}

void taskManagerServer::ON_UPSAPExcelInfoTask(QMap<int,SAPExcelInfo>seletSAPExcelInfoTask, ESS_Request ESS_RequestI,QString taskType)
{
    //qDebug()<<"taskType:"<<taskType<<"actionId:"<<ESS_RequestI.actionId;
    QMap<int, SAPExcelInfo> UPSAPExcelInfoTask;
    QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
    while(iter!=currentSAPExcelInfoTask.end()){
        if(iter.value().containerCode!=nullptr){
            if(seletSAPExcelInfoTask.contains(iter.key())){
                SAPExcelInfo SAPExcelInfoI=seletSAPExcelInfoTask.find(iter.key()).value();
                QString taskType=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
                iter.value().taskStatus=SAPExcelInfoI.taskStatus;
                iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                //iter.value().taskId_ess="taskCode-"+QString::number(iter.value().SAPTaskIndex)+"-"+QDateTime::currentDateTime().toString("zzz");
                UPSAPExcelInfoTask.insert(iter.key(),iter.value());
                if(SAPExcelInfoI.taskStatus==100){
                    setStationInfoMap(iter.value().pickDesc_s,iter.value().containerCode,0,"delete");//设置并更新接驳台状态信息
                }
                qDebug()<<"手动更新任务状态--->SAPTaskIndex:"<<SAPExcelInfoI.SAPTaskIndex<<" taskType:"<<taskType<<"actionId:"<<iter.value().taskStatus<<""<<iter.value().taskStatusDesc;
            }
        }
        iter++;
    }

    if(!UPSAPExcelInfoTask.isEmpty()){
        threadQueryI->UP_SAPExcelInfotaskCode(UPSAPExcelInfoTask);//更新任务状态信息
    }

}

void taskManagerServer::ON_deleteSAPExcelInfoTask(QMap<int, SAPExcelInfo> seletSAPExcelInfoTask)
{
    if(!seletSAPExcelInfoTask.isEmpty()){
        if(threadQueryI->UP_cancelTaskSAP(seletSAPExcelInfoTask)){
            QMap<int, SAPExcelInfo>::iterator iter=currentSAPExcelInfoTask.begin();
            while (iter!=currentSAPExcelInfoTask.end()) {
                if(iter.value().containerCode!=nullptr){
                    if(seletSAPExcelInfoTask.contains(iter.value().SAPTaskIndex)){
                        iter.value().taskStatus=100;
                        QString taskType=iter.value().taskType+"_"+QString::number(iter.value().taskStatus);
                        iter.value().taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType);
                        iter.value().taskError=1;           //任务错误代码
                        iter.value().errortextEdit=ServerInitItem.taskStatusMap.value("delete");  //异常原因详细信息
                        setStationInfoMap(iter.value().pickDesc_s,iter.value().containerCode,0,"delete");//设置并更新接驳台状态信息
                        qDebug()<<"deleteSAPExcelInfoTask:"<<iter.value().SAPTaskIndex<<iter.value().containerCode;
                    }
                }else{
                    return;
                }
                iter++;
            }
        }
    }
}

void taskManagerServer::ON_LiftTaskStatus(LiftTask LiftTask0)
{
    //任务锁定状态 status: 0空闲  1 锁定  2到达 0空闲
    QMap<QString,LiftCode>::iterator iter= LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()) {
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
                if(iter.value().status==2 && iter.value().Liftstatus==1){
                    iter.value().status=0;
                    iter.value().SAPTaskIndex=0;
                    iter.value().containerCode="";
                    qDebug()<<"Lift--料框已离开---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
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

                //判断 OUT 料框已到达 ---> Liftstatus:1可取料,2取料完成
                if(iter.value().status==1 && iter.value().Liftstatus==1){
                    iter.value().status=2;
                    qDebug()<<"Lift--取料完成---> codeDesc:"<<iter.value().codeDesc<<" containerCode:"<<iter.value().containerCode;
                }
            }

        }else{
            return ;
        }
        iter++;
    }
}

 //更新各设备状态信息  控制盒-接驳台类型
void taskManagerServer::ON_DeviceStatus_station(QString DeviceIP, int online, int DeviceStatus, controlbox controlboxI)
{
    if(currentStationInfoMap.contains(DeviceIP)){
        //qDebug()<<"taskManagerServer---> DeviceIP:"<<DeviceIP<<" online:"<<online<<" DeviceStatus:"<<DeviceStatus;
        QMap<QString,StationInfo >::iterator iter=currentStationInfoMap.begin();
        while (iter!=currentStationInfoMap.end()){
            if(iter.value().StationIP!=nullptr){
                if(iter.value().StationIP==DeviceIP){
                    iter.value().online=online;
                    iter.value().status=DeviceStatus;
                    if(newSAPExcelInfoList.isEmpty()){
                        if(iter.value().StationType=="Empty" && iter.value().containerCode==""
                               && online==1 && DeviceStatus==1){
                            newSAPExcelInfo_Empty("Empty",iter.value());//创建空返空箱任务
                            return;
                        }
                    }
                }
            }else{
                return;
            }
            iter++;
        }
    }
}

void taskManagerServer::ON_containerCode_clear(QString shelfBindesc, QString containerCode)
{
    QMap<int, SAPExcelInfo> seletSAPExcelInfoTask;
    QMap<int, SAPExcelInfo>::iterator iter=CurrentServerItem.currentSAPExcelInfoTask.begin();
    while (iter!=CurrentServerItem.currentSAPExcelInfoTask.end()){
        if(iter.value().containerCode!=nullptr){
            if(iter.value().containerCode==containerCode
                    && iter.value().shelfBindesc==shelfBindesc
                    && iter.value().taskStatus<9){
                seletSAPExcelInfoTask.insert(iter.key(),iter.value());
                qDebug()<<" 清空库位 containerCode_clear:"<<iter.value().SAPTaskIndex<<iter.value().shelfBindesc<<iter.value().containerCode;
            }
        }else{
            return;
        }
        iter++;
    }

    if(!seletSAPExcelInfoTask.isEmpty()){
        ON_deleteSAPExcelInfoTask(seletSAPExcelInfoTask);
    }else{
        shelfBinInfo shelfBinInfoI;
        QMap<QString,shelfBinInfo>shelfBinInfoMap;
        shelfBinInfoI.shelfBindesc=shelfBindesc;
        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
        threadQueryI->setshelfBinInfo_Status(shelfBinInfoMap);//更新库位状态信息
    }
    qDebug()<<" 清空库位 containerCode_clear:"<<shelfBindesc<<containerCode;

}


