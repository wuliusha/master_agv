#include "agv_single.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

AGV_Single *AGV_Single::pThis = nullptr;
QMutex *AGV_Single::getInstanceMutex = new QMutex(QMutex::Recursive);

AGV_Single::AGV_Single(QObject *parent) : QObject(parent)
{
    pathMapInit();//二维码数据初始化
}

AGV_Single *AGV_Single::GetInstance()
{
    QMutexLocker locker(getInstanceMutex);
    if(pThis == nullptr)
    {
        pThis = new AGV_Single();
    }
    return pThis;
}

void AGV_Single::setAGV_SingleInit()
{
    CurrentTaskId=1;
    agvSubTaskmoveMap.clear();
}

QMap<int, agvSubTask> AGV_Single::getAgvSubTaskmoveMap()
{
    return agvSubTaskmoveMap;
}

void AGV_Single::agvSubTaskmoveList_add(QMap<int, agvSubTask> agvSubTaskMap_)
{
    QMap<int,agvSubTask >::iterator iter= agvSubTaskMap_.begin();
    while (iter!=agvSubTaskMap_.end()){
        bool SubTask =addAgvSubTask(CurrentTaskId,iter.value(),1,iter.value().RouteName);
        if(SubTask){
            CurrentTaskId++;
        }
        ++iter;
    }

}

bool AGV_Single::addAgvSubTask(int TaskId, agvSubTask agvSubTaskI, int AGVAction,QString RouteName)
{
    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.RouteName=RouteName;                     //路线名

    agvSubTaskItemTemp.TaskId=TaskId;
    agvSubTaskItemTemp.Point =agvSubTaskI.Point;                            //AGV基本任务 起始点
    agvSubTaskItemTemp.NextPoint = agvSubTaskI.NextPoint;                   //AGV基本任务 下一点
    agvSubTaskItemTemp.NextPointDistance =agvSubTaskI.NextPointDistance;    //AGV基本任务 下一点距离
    agvSubTaskItemTemp.AGVSpeed = agvSubTaskI.AGVSpeed;                     //AGV基本任务 速度
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = agvSubTaskI.RotaryLowBarrierInstruction;  //AGV基本任务 顶盘降下时 激光方案（无货架）
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = agvSubTaskI.RotaryHighBarrierInstruction;//AGV基本任务 顶盘举升时 激光方案（有货架）
    agvSubTaskItemTemp.postureAngle = agvSubTaskI.postureAngle;             //AGV基本任务 姿态角度
    agvSubTaskItemTemp.AGVMoveAnage = agvSubTaskI.AGVMoveAnage;             //AGV基本任务 移动角度
    agvSubTaskItemTemp.AGVRotaryAngle = agvSubTaskI.AGVRotaryAngle;         //AGV基本任务 转盘角度
    agvSubTaskItemTemp.SubTaskType = AGVAction;                             //AGV基本任务 基本任务类型

    QMap<int,agvSubTask >::iterator iter= agvSubTaskmoveMap.begin();              //AGV子任务列表 当前 未执行 的二维码任务链表
    while (iter!=agvSubTaskmoveMap.end()) {
        if(iter.value().Point==agvSubTaskItemTemp.Point && iter.value().NextPoint == agvSubTaskItemTemp.NextPoint){
                return false;
        }
        ++iter;
    }

//    qDebug()<<" agvSubTaskmoveMap insert--> TaskId:"<<TaskId<<agvSubTaskI.Point<<agvSubTaskI.NextPoint
//           <<agvSubTaskI.NextPointDistance<<agvSubTaskI.AGVSpeed
//           <<" 姿态角度:"<<agvSubTaskI.postureAngle<<" 移动角度:"<<agvSubTaskI.AGVMoveAnage
//          <<" 转盘角度:"<<agvSubTaskI.AGVRotaryAngle<<AGVAction;

    agvSubTaskmoveMap.insert(TaskId,agvSubTaskItemTemp);
    return true;
}




void AGV_Single::pathMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from movepointmap;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            agvSubTask agvSubTaskI;
            agvSubTaskI.Id=sqlQuery.value("Id").toInt();                              //编号
            agvSubTaskI.RouteName=sqlQuery.value("RouteName").toString();                    //路线名
            agvSubTaskI.TaskId=sqlQuery.value("TaskId").toInt();                          //路径内序号
            agvSubTaskI.Point=quint32(sqlQuery.value("Point").toInt());                      //AGV基本任务 起始点
            agvSubTaskI.NextPoint=quint32(sqlQuery.value("NextPoint").toInt());                  //AGV基本任务 下一点
            agvSubTaskI.NextPointDistance=quint16(sqlQuery.value("NextPointDistance").toInt());          //AGV基本任务 下一点距离
            agvSubTaskI.AGVSpeed=quint8(sqlQuery.value("AGVSpeed").toInt());                    //AGV基本任务 速度
            agvSubTaskI.RotaryLowBarrierInstruction=quint8(sqlQuery.value("RotaryLowBarrierInstruction").toInt()); //AGV基本任务 顶盘降下时 激光方案（无货架）
            agvSubTaskI.RotaryHighBarrierInstruction=quint8(sqlQuery.value("RotaryHighBarrierInstruction").toInt());//AGV基本任务 顶盘举升时 激光方案（有货架）
            agvSubTaskI.postureAngle=quint16(sqlQuery.value("postureAngle").toInt());                   //AGV基本任务 姿态角度
            agvSubTaskI.AGVMoveAnage=quint16(sqlQuery.value("AGVMoveAnage").toInt());                   //AGV基本任务 移动角度
            agvSubTaskI.AGVRotaryAngle=quint16(sqlQuery.value("AGVRotaryAngle").toInt());               //AGV基本任务 转盘角度
            agvSubTaskI.SubTaskType =sqlQuery.value("SubTaskType").toInt();                             //AGV基本任务 基本任务类型  0正向  -1反向

            if(!agvSubTaskListinit.contains(QString::number(agvSubTaskI.Id))){
                agvSubTaskListinit.insert(QString::number(agvSubTaskI.Id),agvSubTaskI);
                //qDebug()<<agvSubTaskI.TaskId<<agvSubTaskI.Point<<agvSubTaskI.NextPoint<<agvSubTaskListinit.size();
            }

        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_station;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            Stationmap Stationmap1;
            Stationmap1.StationName=sqlQuery.value("StationName").toString();        //工位名称
            Stationmap1.StationPoint = sqlQuery.value("StationPoint").toInt();       //工位二维码
            Stationmap1.StartPoint = sqlQuery.value("StartPoint").toInt();           //StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
            Stationmap1.PassPoint = sqlQuery.value("PassPoint").toInt();             //经过二维码 1
            Stationmap1.PassPoint1 = sqlQuery.value("PassPoint1").toInt();           //经过二维码  1
            Stationmap1.PassPoint2 = sqlQuery.value("PassPoint2").toInt();
            Stationmap1.PassPoint3 = sqlQuery.value("PassPoint3").toInt();
            Stationmap1.assistPoint = sqlQuery.value("assistPoint").toInt();        //辅路线  对接点
            Stationmap1.assistRoute = sqlQuery.value("assistRoute").toString();     //与工位连接的辅路线
            Stationmap1.SubTaskType = sqlQuery.value("SubTaskType").toInt();        //AGV基本任务 基本任务类型  0正向  -1反向

            Stationmap1.pointMap.insert(Stationmap1.StartPoint,Stationmap1.StartPoint);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint,Stationmap1.PassPoint);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint1,Stationmap1.PassPoint1);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint2,Stationmap1.PassPoint2);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint3,Stationmap1.PassPoint3);

            if(!Stationmap_Map.contains(Stationmap1.StationName)){
                Stationmap_Map.insert(Stationmap1.StationName,Stationmap1);
            }

        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_mian;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            assistRoute assistRouteI;
            assistRouteI.Id=sqlQuery.value("Id").toInt();                           //序号
            assistRouteI.keyId=sqlQuery.value("keyId").toString();                  //路线编号
            assistRouteI.assistRoute_S=sqlQuery.value("assistRoute_S").toString();  //起始路线
            assistRouteI.assistPoint_S = sqlQuery.value("assistPoint_S").toInt();   //起始路线 离开点
            assistRouteI.assistRoute_E =sqlQuery.value("assistRoute_E").toString(); //目标路线
            assistRouteI.assistPoint_E =sqlQuery.value("assistPoint_E").toInt();    //目标路线  进入点

            if(!assistRoute_Map.contains(assistRouteI.Id)){ //起始点线 与 目标点路线的 对应连接关系
                assistRoute_Map.insert(assistRouteI.Id,assistRouteI);
            }

        }
    }

    sqlQuery.prepare("select * from move_mian_;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            mianRoute mianRouteI;
            mianRouteI.TaskId=sqlQuery.value("TaskId").toInt();             //序号       按照从小到大 执行
            mianRouteI.Point_S = sqlQuery.value("Point_S").toInt();         //起始
            mianRouteI.Point_E = sqlQuery.value("Point_E").toInt();         //离开
            mianRouteI.RouteName=sqlQuery.value("RouteName").toString();    //主路线名
            mianRouteI.SubTaskType = sqlQuery.value("SubTaskType").toInt(); //AGV基本任务 基本任务类型  0正向  -1反向
            mianRouteI.keyId=sqlQuery.value("keyId").toString();            //唯一识别号

            QMap<int,assistRoute >::iterator iter= assistRoute_Map.begin();
            while (iter!=assistRoute_Map.end()) {
                if(iter.value().keyId==mianRouteI.keyId){
                    iter.value().mianRouteMap.insert(mianRouteI.RouteName,mianRouteI);
                    //qDebug()<<"mianRouteMap.insert:"<<mianRouteI.TaskId<<mianRouteI.keyId;
                }
                ++iter;
            }
        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_turn;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            QString RouteName=sqlQuery.value("RouteName").toString();
            int StartQRPoint= sqlQuery.value("StartQRPoint").toInt();
            int EndQRPoint=sqlQuery.value("EndQRPoint").toInt();
            if(!StartQRPointMap.contains(StartQRPoint)){        //路线以及起始点的缓存链表
                StartQRPointMap.insert(StartQRPoint,RouteName);
            }if(!EndQRPointMap.contains(EndQRPoint)){           //路线以及终点的缓存链表
                EndQRPointMap.insert(EndQRPoint,RouteName);
            }
        }
    }

}



//获取当前站点内路线信息Type :0->s  -1 ->e
QMap<int, agvSubTask> AGV_Single::getMianRouteInfo_In(quint32 Point_S, quint32 Point_E, QString RouteName, int SubTaskType)
{
    QMap<int,agvSubTask > agvSubTaskMap_;
    agvSubTask agvSubTask_S;  agvSubTask agvSubTask_E;
    QMap<QString,agvSubTask >::const_iterator iter1=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter1!=agvSubTaskListinit.end()) {
        if(iter1.value().RouteName == RouteName && iter1.value().SubTaskType==SubTaskType){

            if(EndQRPointMap.contains(int(Point_S))){
                if(iter1.value().NextPoint==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1805 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }else if(iter1.value().Point==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1811 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }else{
                if(iter1.value().Point==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1811 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }

            if(StartQRPointMap.contains(int(Point_E))){
                if(iter1.value().Point==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1820 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }else if(iter1.value().NextPoint==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1838 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }else{
                if(iter1.value().NextPoint==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1826 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }

        }
        iter1++;
    }

    qDebug()<<"获取站点内路线二维码信息--->RouteName:"<<RouteName<<" SubTaskType:"<<SubTaskType<<Point_S<<Point_E;
    qDebug()<<"agvSubTask_S--> TaskId:"<<agvSubTask_S.TaskId<<" RouteName:"<<agvSubTask_S.RouteName<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    qDebug()<<"agvSubTask_E--> TaskId:"<<agvSubTask_E.TaskId<<" RouteName:"<<agvSubTask_E.RouteName<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    if(agvSubTask_S.TaskId!=0 || agvSubTask_E.TaskId!=0){
        QMap<QString,agvSubTask >::Iterator iter= agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {//获取起点与目标点 之间所有二维码的基础信息
            if(iter.value().RouteName == RouteName && iter.value().SubTaskType == SubTaskType){
                if(iter.value().TaskId>=agvSubTask_S.TaskId && iter.value().TaskId<=agvSubTask_E.TaskId){
                    if(Point_E != iter.value().Point){
                        qDebug()<<" agvSubTask_add2:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                        agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
                    }
                }

            }
            ++iter;
        }
    }
    agvSubTaskmoveList_add(agvSubTaskMap_);
    return agvSubTaskMap_;
}

//获取站点外: 任意两点 Point 的路线规划
QMap<int,agvSubTask > AGV_Single::getRouteInfo_out(int StartQRPoint, int EndQRPoint, int Type)
{

    assistRoute assistRouteI;
    QMap<int,agvSubTask > agvSubTaskMap_;
    mianRoute mianRoute_s; mianRoute mianRoute_e;
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();
    while (iter!=agvSubTaskListinit.end()) {
        if(iter!=nullptr){
            if(!Stationmap_Map.contains(iter.value().RouteName)){
                if(iter.value().Point == quint32(StartQRPoint)
                        && iter.value().RouteName!=StartQRPointMap.value(StartQRPoint)){//起始二维码
                    mianRoute_s.RouteName=iter.value().RouteName;
                    //qDebug()<<"-----StartQRPoint:"<<StartQRPoint<<mianRoute_s.RouteName;
                }if(iter.value().Point == quint32(EndQRPoint)
                        && iter.value().RouteName!=EndQRPointMap.value(EndQRPoint)){    //目标二维码
                    mianRoute_e.RouteName=iter.value().RouteName;
                    //qDebug()<<"-----EndQRPoint:"<<EndQRPoint<<mianRoute_e.RouteName;
                }
            }
        }else{
            return agvSubTaskMap_;
        }
        ++iter;
    }

    if(mianRoute_s.RouteName==""){
        if(StartQRPointMap.contains(StartQRPoint)){ //路线以及起始点的缓存链表
            mianRoute_s.RouteName=StartQRPointMap.value(StartQRPoint);
        }if(EndQRPointMap.contains(StartQRPoint)){  //路线以及终点的缓存链表
            mianRoute_s.RouteName=EndQRPointMap.value(StartQRPoint);
        }
    }if(mianRoute_e.RouteName==""){
        if(StartQRPointMap.contains(EndQRPoint)){   //路线以及起始点的缓存链表
            mianRoute_e.RouteName=StartQRPointMap.value(EndQRPoint);
        }if(EndQRPointMap.contains(EndQRPoint)){    //路线以及终点的缓存链表
            mianRoute_e.RouteName=EndQRPointMap.value(EndQRPoint);
        }
    }

    if(mianRoute_s.RouteName == mianRoute_e.RouteName){
        QMap<int,agvSubTask > agvSubTaskMap_=getMianRouteInfo_out(quint32(StartQRPoint),quint32(EndQRPoint),mianRoute_s.RouteName);
        return agvSubTaskMap_;
    }else{
        if(mianRoute_s.RouteName!="" && mianRoute_e.RouteName!=""){

            qDebug()<<" assistRoute_S:"<<mianRoute_s.RouteName<<" StartQRPoint:"<<StartQRPoint
                  <<" assistRoute_E:"<<mianRoute_e.RouteName<<" EndQRPoint:"<<EndQRPoint;
            //获取起始路线  与目标路线之间的 路线信息    (执行链表  按照 Id 从小到大 执行)
            assistRouteI=getMianRouteMap(mianRoute_s.RouteName, mianRoute_e.RouteName,StartQRPoint,EndQRPoint);

            QMap<int,agvSubTask > agvSubTaskMap_s;
            if(StartQRPoint==assistRouteI.assistPoint_S){
                //当起始二维码在 转折点时 特殊处理
                QString RouteName =getMianRouteInfo_or(StartQRPoint,mianRoute_s.RouteName,assistRouteI.assistPoint_E,mianRoute_e.RouteName);
                if(RouteName!=""){
                    agvSubTaskMap_s=getMianRouteInfo_out(quint32(StartQRPoint),quint32(assistRouteI.assistPoint_E),RouteName);
                    qDebug()<<"当起始二维码在 转折点时 特殊处理--> agvSubTaskMap_s:"<<agvSubTaskMap_s.size()<<" --- "<<StartQRPoint<<assistRouteI.assistPoint_E<<RouteName<<assistRouteI.mianRouteMap.size();
                }
            }else {
                agvSubTaskMap_s=getMianRouteInfo_out(quint32(StartQRPoint),quint32(assistRouteI.assistPoint_S),assistRouteI.assistRoute_S);
                qDebug()<<"获取起始路线--->agvSubTaskMap_s_:"<<agvSubTaskMap_s.size()<<" --- "<<StartQRPoint<<assistRouteI.assistPoint_S<<assistRouteI.assistRoute_S<<assistRouteI.mianRouteMap.size();
            }

            QMap<int,agvSubTask >mainAgvSubTaskMap;   //当前所有路线 二维码缓存链表
            if(!assistRouteI.mianRouteMap.isEmpty()){ //获取 每个路线  进入点与离开点 之间所有二维码的基础信息
                qDebug()<<" 获取 每个路线  进入点与离开点 之间所有二维码的基础信息 mianRouteMap"<<assistRouteI.mianRouteMap.size()<<assistRouteI.mianRouteMap.first().keyId;
                mainAgvSubTaskMap =getMainagvSubTaskMap(assistRouteI.mianRouteMap);
            }

            QMap<int,agvSubTask > agvSubTaskMap_e=getMianRouteInfo_out(quint32(assistRouteI.assistPoint_E),quint32(EndQRPoint),assistRouteI.assistRoute_E);

        }else{
            qDebug()<<" 1626 路径规划失败:"<<StartQRPoint<<EndQRPoint<<Type;
        }
    }

    qDebug()<<" 1492 agvSubTaskMap_:"<<agvSubTaskMap_.size()<<StartQRPoint<<EndQRPoint;
    return agvSubTaskMap_;
}

//获取站点内: Point 对应的 辅路线与对接点 Type--> 0 起点  1 终点
mianRoute AGV_Single::getRouteInfo_In(quint32 Point, int Type)
{
    mianRoute mianRouteI;
    QMap<QString,Stationmap >::const_iterator iter=Stationmap_Map.begin();
    while (iter!=Stationmap_Map.end()) {
        if(iter.value().pointMap.contains(int(Point))){
            mianRouteI.StationName=iter.value().StationName;//工位名称
            mianRouteI.RouteName=iter.value().assistRoute;  //与工位连接的辅路线
            if(Type==0){//0 起点  1 终点
                mianRouteI.Point_S=iter.value().assistPoint;//辅路线  对接点
            }else{
                mianRouteI.Point_E=iter.value().assistPoint;//辅路线  对接点
            }
        }
        ++iter;
    }
    qDebug()<<"判断当前二维码是否存在站点内: -->Point:"<<Point<<" Type:"<<Type
              <<"RouteName:"<<mianRouteI.RouteName<<" Point_S:"<<mianRouteI.Point_S<<" Point_E:"<<mianRouteI.Point_E;
    return mianRouteI;
}

QString AGV_Single::getMianRouteInfo_or(int StartQRPoint, QString RouteName_s, int EndQRPoint, QString RouteName_e)
{
    QString RouteName="";
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter!=agvSubTaskListinit.end()) {
        if(iter.value().Point==quint32(StartQRPoint) && iter.value().RouteName!=RouteName_s){
            RouteName=iter.value().RouteName;
            return RouteName;
        }
        ++iter;
    }
    return RouteName;
}

QMap<int, agvSubTask> AGV_Single::getMianRouteInfo_out(quint32 Point_S, quint32 Point_E, QString RouteName)
{

    QMap<int,agvSubTask > agvSubTaskMap_;
    agvSubTask agvSubTask_S;agvSubTask agvSubTask_E;
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter!=agvSubTaskListinit.end()) {
        if(iter.value().RouteName == RouteName && iter.value().SubTaskType==0){

            if(EndQRPointMap.contains(int(Point_S))){
                if(iter.value().NextPoint==Point_S){
                    agvSubTask_S=iter.value();
                }
            }else{
                if(iter.value().Point==Point_S){
                    agvSubTask_S=iter.value();
                }
            }

            if(StartQRPointMap.contains(int(Point_E))){
                if(iter.value().Point==Point_E){
                    agvSubTask_E=iter.value();
                }
            }else{
                if(iter.value().NextPoint==Point_E){
                    agvSubTask_E=iter.value();
                }
            }

        }
        ++iter;
    }

    //qDebug()<<"Point_S--->RouteName:"<<RouteName<<agvSubTask_S.TaskId<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    //qDebug()<<"Point_E--->RouteName:"<<RouteName<<agvSubTask_E.TaskId<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    int SubTaskType=0;
    if(agvSubTask_S.TaskId > agvSubTask_E.TaskId){SubTaskType=-1;}
    QMap<QString,agvSubTask >::const_iterator iter1=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter1!=agvSubTaskListinit.end()) {
        if(iter1.value().RouteName == RouteName && iter1.value().SubTaskType==SubTaskType){
            if(iter1.value().Point==Point_S){
                agvSubTask_S=iter1.value();
                //qDebug()<<"1760 Point_S--->RouteName:"<<RouteName<<Point_S<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
            }if(iter1.value().NextPoint==Point_E){
                agvSubTask_E=iter1.value();
                //qDebug()<<"1761 Point_E--->RouteName:"<<RouteName<<Point_E<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
            }
        }
        iter1++;
    }

    qDebug()<<"获取任意路线的两点之间的路径信息---->RouteName:"<<RouteName<<" SubTaskType:"<<SubTaskType<<" Point_S:"<<Point_S<<" Point_E:"<<Point_E;
    qDebug()<<"agvSubTask_S--> TaskId:"<<agvSubTask_S.TaskId<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    qDebug()<<"agvSubTask_E--> TaskId:"<<agvSubTask_E.TaskId<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    if(agvSubTask_S.TaskId!=0 && agvSubTask_E.TaskId!=0){
        QMap<QString,agvSubTask >::Iterator iter= agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {//获取起点与目标点 之间所有二维码的基础信息
            if(iter.value().Point==Point_S && iter.value().NextPoint==Point_E){
                //qDebug()<<" agvSubTask_add0:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
            }else{
                if(iter.value().RouteName == RouteName && iter.value().SubTaskType == SubTaskType){
                    if(iter.value().TaskId>=agvSubTask_S.TaskId && iter.value().TaskId<=agvSubTask_E.TaskId){
                        if(Point_S != iter.value().NextPoint){
                            //qDebug()<<" agvSubTask_add1:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                            agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
                        }
                    }
                }
            }
            ++iter;
        }
    }

    agvSubTaskmoveList_add(agvSubTaskMap_);

    return agvSubTaskMap_;
}


assistRoute AGV_Single::getMianRouteMap(QString RouteName_S, QString RouteName_E,int StartQRPoint,int EndQRPoint)
{
    assistRoute assistRouteI;
    QMap<int,assistRoute >::iterator iter1= assistRoute_Map.begin();//起始点辅路线 与 目标点辅路线的 对应连接关系
    while (iter1!=assistRoute_Map.end()) {
        if(iter1.value().assistRoute_S==RouteName_S && iter1.value().assistRoute_E==RouteName_E){
            assistRouteI=iter1.value();
        }
        iter1++;
    }
    qDebug()<<"获取起始路线  与目标路线之间的 路线信息--> keyId:"<<assistRouteI.keyId<<" assistRoute_S:"<<assistRouteI.assistRoute_S<<" assistPoint_S:"<<assistRouteI.assistPoint_S
          <<" assistRoute_E:"<<assistRouteI.assistRoute_E<<" assistPoint_E:"<<assistRouteI.assistPoint_E;
    return assistRouteI;
}

QMap<int, agvSubTask> AGV_Single::getMainagvSubTaskMap(QMap<QString, mianRoute> mianRouteMap)
{
    QMap<int, mianRoute> RouteMap_;
    QMap<int,agvSubTask >mainAgvSubTaskMap; //当前运行主路线 二维码 信息暂存
    for(int i=0;i<mianRouteMap.size();i++){
        mianRoute mianRouteI =getMianRoute_min(mianRouteMap,RouteMap_);//进行路线 二维码排序
        if(mianRouteI.TaskId!=0){
            RouteMap_.insert(mianRouteI.TaskId,mianRouteI);//防止重复误判
            qDebug()<<" 获取起始路线 与目标路线之间的 所有二维码的基础信息  mianRouteI:"<<mianRouteI.TaskId<<mianRouteI.RouteName<<mianRouteI.Point_S<<mianRouteI.Point_E<<mianRouteI.SubTaskType;
            mainAgvSubTaskMap=getMianRouteInfo_out(quint32(mianRouteI.Point_S),quint32(mianRouteI.Point_E),mianRouteI.RouteName);
        }
    }
    return mainAgvSubTaskMap;
}

mianRoute AGV_Single::getMianRoute_min(QMap<QString, mianRoute> mianRouteMap, QMap<int, mianRoute> RouteMap_)
{
    mianRoute mianRouteI;
    QMap<QString,mianRoute>::iterator iter0=mianRouteMap.begin();       //主路线 执行链表  按照 Id 从小到大 执行
    while (iter0!=mianRouteMap.end()) {
        if(!RouteMap_.contains(iter0.value().TaskId)){
            if(mianRouteI.TaskId==0){
                mianRouteI=iter0.value();
            }else{
                if(iter0.value().TaskId<=mianRouteI.TaskId){
                    mianRouteI=iter0.value();
                }
            }
        }
        iter0++;
    }
    return mianRouteI;
}
