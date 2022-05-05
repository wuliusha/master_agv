#include "query_single.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

query_Single* query_Single::query_SingleItiem=0;
QMutex query_Single::mutex;

query_Single::query_Single(QObject *parent) : QObject(parent)
{

}


/*************路线管理--路线规则*********************/

//根据路线编号 查找对应路线信息
assistRoute query_Single::queryAssistRoute(QString keyId)
{
    assistRoute assistRouteI;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from move_mian where  keyId=:keyId;");
    sqlQuery.addBindValue(keyId);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            assistRouteI.Id=sqlQuery.value("Id").toInt();                           //序号
            assistRouteI.keyId=sqlQuery.value("keyId").toString();                  //路线编号
            assistRouteI.assistRoute_S=sqlQuery.value("assistRoute_S").toString();  //起始路线
            assistRouteI.assistPoint_S = sqlQuery.value("assistPoint_S").toInt();   //起始路线 离开点
            assistRouteI.assistRoute_E =sqlQuery.value("assistRoute_E").toString(); //目标路线
            assistRouteI.assistPoint_E =sqlQuery.value("assistPoint_E").toInt();    //目标路线  进入点
        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_mian_ where  keyId=:keyId;");
    sqlQuery.addBindValue(keyId);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            mianRoute mianRouteI;
            mianRouteI.keyId=sqlQuery.value("keyId").toString();            //唯一识别号
            mianRouteI.TaskId=sqlQuery.value("TaskId").toInt();             //序号       按照从小到大 执行
            mianRouteI.Point_S = sqlQuery.value("Point_S").toInt();         //起始
            mianRouteI.Point_E = sqlQuery.value("Point_E").toInt();         //离开
            mianRouteI.RouteName=sqlQuery.value("RouteName").toString();    //主路线名
            mianRouteI.SubTaskType = sqlQuery.value("SubTaskType").toInt(); //AGV基本任务 基本任务类型  0正向  -1反向
            if(mianRouteI.TaskId>assistRouteI.TaskId){
                assistRouteI.TaskId=mianRouteI.TaskId;
            }
            assistRouteI.mianRouteMap.insert(mianRouteI.RouteName,mianRouteI);
        }
    }

    return assistRouteI;
}

//创建路线信息 写入数据库
bool query_Single::assistRoute_Insert(assistRoute assistRouteI)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("INSERT INTO [dbo].[move_mian] ([keyId],[assistRoute_S], [assistPoint_S],"
                     "[assistRoute_E],[assistPoint_E]) VALUES (:keyId,:assistRoute_S,:assistPoint_S,"
                     ":assistRoute_E,:assistPoint_E );");
    sqlQuery.addBindValue(assistRouteI.keyId);                      //路线编号
    sqlQuery.addBindValue(assistRouteI.assistRoute_S);               //起始路线
    sqlQuery.addBindValue(assistRouteI.assistPoint_S);                 //起始路线 离开点
    sqlQuery.addBindValue(assistRouteI.assistRoute_E);               //目标路线
    sqlQuery.addBindValue(assistRouteI.assistPoint_E);                 //目标路线  进入点
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }
}

//删除路线信息 删除数据库
bool query_Single::assistRoute_Delete(assistRoute assistRouteI)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare(QString("DELETE FROM move_mian WHERE [keyId]=:keyId"));
    sqlQuery.addBindValue(assistRouteI.keyId);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }
}

//创建路线的途经路线 信息 写入数据库
bool query_Single::mianRouteMap_Insert(QMap<QString, mianRoute> mianRouteMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    if(!mianRouteMap.isEmpty()){//途径的子路线新增 缓存列表
        QMap<QString,mianRoute>::const_iterator iter_=mianRouteMap.begin();
        while (iter_!=mianRouteMap.end()) {
            sqlQuery.prepare("INSERT INTO [dbo].[move_mian_] ([keyId],"
                             "[TaskId], [Point_S],[RouteName],[Point_E],[SubTaskType]) VALUES (:keyId,"
                             ":TaskId,:Point_S,:RouteName,:Point_E,:SubTaskType );");

            sqlQuery.addBindValue(iter_.value().keyId);       //路线编号
            sqlQuery.addBindValue(iter_.value().TaskId);            //路径内序号  按照从小到大 执行
            sqlQuery.addBindValue(iter_.value().Point_S);         //起始二维码
            sqlQuery.addBindValue(iter_.value().RouteName);    //路线名称
            sqlQuery.addBindValue(iter_.value().Point_E);        //离开二维码
            sqlQuery.addBindValue(iter_.value().SubTaskType);     //AGV基本任务 基本任务类型  0正向  -1反向
            if(sqlQuery.exec()){

            }
            iter_++;
        }
    }
    return true;
}

//删除途经路线信息
bool query_Single::mianRouteMap_Delete(QString keyId)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare(QString("DELETE FROM move_mian_ WHERE [keyId]=:keyId"));
    sqlQuery.addBindValue(keyId);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }

}

/*************路线管理--路线信息*********************/


//查找当前路线信息
QMap<int, agvSubTask> query_Single::query_agvSubTaskListinit(QString RouteName, int SubTaskType)
{
    QMap<int, agvSubTask> agvSubTaskListinit;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from movepointmap where  RouteName=:RouteName and SubTaskType=:SubTaskType;");
    sqlQuery.addBindValue(RouteName);
    sqlQuery.addBindValue(SubTaskType);
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

            if(!agvSubTaskListinit.contains(agvSubTaskI.TaskId)){
                agvSubTaskListinit.insert(agvSubTaskI.TaskId,agvSubTaskI);
                qDebug()<<"查找当前路线信息"<<agvSubTaskI.RouteName<<agvSubTaskI.TaskId<<agvSubTaskI.Point<<agvSubTaskI.NextPoint<<agvSubTaskListinit.size();
            }

        }
    }
    return agvSubTaskListinit;
}

//导入路线二维码信息 到数据库
bool query_Single::SubTaskListinit_insert(QMap<int,agvSubTask > agvSubTaskListinit_)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<int ,agvSubTask >::iterator iter_=agvSubTaskListinit_.begin();
    while (iter_!=agvSubTaskListinit_.end()) {
        agvSubTask agvSubTaskI=iter_.value();
        sqlQuery.prepare("INSERT INTO [dbo].[movepointmap] ([RouteName],"
                         "[TaskId], [Point],[NextPoint],[NextPointDistance],[AGVSpeed],"
                         "[RotaryLowBarrierInstruction], [RotaryHighBarrierInstruction],"
                         "[postureAngle],[AGVMoveAnage],[AGVRotaryAngle],[SubTaskType]) VALUES (:RouteName,"
                         ":TaskId,:Point,:NextPoint,:NextPointDistance,:AGVSpeed,"
                         ":RotaryLowBarrierInstruction,:RotaryHighBarrierInstruction,"
                         ":postureAngle,:AGVMoveAnage,:AGVRotaryAngle,:SubTaskType );");

        //sqlQuery.addBindValue(agvSubTaskI.Id);                              //编号
        sqlQuery.addBindValue(agvSubTaskI.RouteName);                       //路线名
        sqlQuery.addBindValue(agvSubTaskI.TaskId);                          //路径内序号
        sqlQuery.addBindValue(agvSubTaskI.Point);                           //AGV基本任务 起始点
        sqlQuery.addBindValue(agvSubTaskI.NextPoint);                       //AGV基本任务 下一点
        sqlQuery.addBindValue(agvSubTaskI.NextPointDistance);               //AGV基本任务 下一点距离
        sqlQuery.addBindValue(agvSubTaskI.AGVSpeed);                        //AGV基本任务 速度
        sqlQuery.addBindValue(agvSubTaskI.RotaryLowBarrierInstruction);     //AGV基本任务 顶盘降下时 激光方案（无货架）
        sqlQuery.addBindValue(agvSubTaskI.RotaryHighBarrierInstruction);    //AGV基本任务 顶盘举升时 激光方案（有货架）
        sqlQuery.addBindValue(agvSubTaskI.postureAngle);                    //AGV基本任务 姿态角度
        sqlQuery.addBindValue(agvSubTaskI.AGVMoveAnage);                    //AGV基本任务 移动角度
        sqlQuery.addBindValue(agvSubTaskI.AGVRotaryAngle);                  //AGV基本任务 转盘角度
        sqlQuery.addBindValue(agvSubTaskI.SubTaskType);                     //AGV基本任务 基本任务类型  0正向  -1反向
        if(!sqlQuery.exec()){

        }

        iter_++;
    }

    if(sqlDatabase.commit()){

    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;
}

bool query_Single::agvSubTask_Delete(QString RouteName,int SubTaskType)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare(QString("DELETE FROM movepointmap WHERE RouteName=:RouteName and SubTaskType=:SubTaskType;"));
    sqlQuery.addBindValue(RouteName);
    sqlQuery.addBindValue(SubTaskType);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }

}


/*************路线管理--站点绑定*********************/

//查找当前站点路线信息
QMap<QString, Stationmap> query_Single::query_Stationmap(QString StationName)
{
    QMap<QString, Stationmap>Stationmap_Map;
    QMap<QString, agvSubTask> agvSubTaskListinit;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    if(StationName==""){
        sqlQuery.prepare("select * from move_station ;");
    }else{
        sqlQuery.prepare("select * from move_station where  StationName=:StationName ;");
        sqlQuery.addBindValue(StationName);
    }

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

    return Stationmap_Map;

}

//添加 站点路线信息 到数据库
bool query_Single::Stationmap_insert(QMap<QString, Stationmap> Stationmap_Map)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<QString ,Stationmap >::iterator iter_=Stationmap_Map.begin();
    while (iter_!=Stationmap_Map.end()) {
        sqlQuery.prepare("INSERT INTO [dbo].[move_station] ([StationName],[StationPoint],"
                         "[StartPoint],[PassPoint],[PassPoint1],[PassPoint2],"
                         "[PassPoint3], [assistPoint],"
                         "[assistRoute],[SubTaskType]) VALUES (:StationName,:StationPoint,"
                         ":StartPoint,:PassPoint,:PassPoint1,:PassPoint2,"
                         ":PassPoint3,:assistPoint,"
                         ":assistRoute,:SubTaskType );");

        sqlQuery.addBindValue(iter_.value().StationName);                //工位名称
        sqlQuery.addBindValue(iter_.value().StationPoint);                  //工位二维码
        sqlQuery.addBindValue(iter_.value().StartPoint);                    // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
        sqlQuery.addBindValue(iter_.value().PassPoint);                    //经过二维码 0
        sqlQuery.addBindValue(iter_.value().PassPoint1);                   //经过二维码 1
        sqlQuery.addBindValue(iter_.value().PassPoint2);                    //经过二维码 2
        sqlQuery.addBindValue(iter_.value().PassPoint3);                    //经过二维码 3
        sqlQuery.addBindValue(iter_.value().assistPoint);                   //辅路线  对接点
        sqlQuery.addBindValue(iter_.value().assistRoute);                //与工位连接的辅路线
        sqlQuery.addBindValue(iter_.value().SubTaskType);                   //AGV基本任务 基本任务类型  0正向  -1反向

        if(!sqlQuery.exec()){

        }

        iter_++;
    }

    if(sqlDatabase.commit()){

    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;
}

//更新 站点路线信息
bool query_Single::Stationmap_update(QMap<QString, Stationmap> Stationmap_Map)
{
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, Stationmap>::const_iterator iter= Stationmap_Map.begin();
    while (iter !=Stationmap_Map.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE [dbo].[move_station] SET [StationPoint]=:StationPoint,"
                             "[StartPoint]=:StartPoint,[PassPoint]=:PassPoint,[PassPoint1]=:PassPoint1,"
                             "[PassPoint2]=:PassPoint2,[PassPoint3]=:PassPoint3,[assistPoint]=:assistPoint,"
                             "[assistRoute]=:assistRoute,[SubTaskType]=:SubTaskType "
                             "WHERE [StationName]=:StationName;");

            sqlQuery.addBindValue(iter.value().StationPoint);     //工位二维码
            sqlQuery.addBindValue(iter.value().StartPoint);       // StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
            sqlQuery.addBindValue(iter.value().PassPoint);        //经过二维码 0
            sqlQuery.addBindValue(iter.value().PassPoint1);       //经过二维码 1
            sqlQuery.addBindValue(iter.value().PassPoint2);       //经过二维码 2
            sqlQuery.addBindValue(iter.value().PassPoint3);       //经过二维码 3
            sqlQuery.addBindValue(iter.value().assistPoint);      //辅路线  对接点
            sqlQuery.addBindValue(iter.value().assistRoute);      //与工位连接的辅路线
            sqlQuery.addBindValue(iter.value().SubTaskType);      //AGV基本任务 基本任务类型  0正向  -1反向
            sqlQuery.addBindValue(iter.value().StationName);      //工位名称

            if(sqlQuery.exec()){
                qDebug()<<"更新 站点路线信息 S"<<iter.value().StationName;
            }else {
                qDebug()<<"更新 站点路线信息 E"<<iter.value().StationName;
            }
        }else{
            return false;
        }
        iter++;
    }

    return true;
}

//删除 站点路线信息
bool query_Single::Stationmap_Delete(QString StationName)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare(QString("DELETE FROM move_station WHERE [StationName]=:StationName"));
    sqlQuery.addBindValue(StationName);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }
}

//查找当前自动门信息
QMap<int, doorSubTask> query_Single::query_doorSubTaskMap(QString doorIP, int doorId)
{

    QMap<int, doorSubTask> doorSubTaskMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    if(doorIP==""){
        sqlQuery.prepare("select * from doorSubTask ;");
    }else{
        sqlQuery.prepare("select * from doorSubTask where  doorIP=:doorIP ;");
        sqlQuery.addBindValue(doorIP);
    }

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
                doorSubTaskI.door_acionI.NextPointList.append(NextPointList[i].trimmed().toInt());
            }

            doorSubTaskI.enable=sqlQuery.value("enable").toInt();
            doorSubTaskI.page=sqlQuery.value("page").toInt();

            //doorSubTaskI.NextPointdesc= doorSubTaskI.NextPointList.join("&");
            if(!doorSubTaskMap.contains(doorSubTaskI.doorId) && doorSubTaskI.doorIP!=""){
                doorSubTaskMap.insert(doorSubTaskI.doorId,doorSubTaskI);
                qDebug()<<" doorSubTaskI:"<<doorSubTaskI.doorId<<doorSubTaskI.doorIP<<doorSubTaskI.Point<<doorSubTaskI.NextPoint
                       <<doorSubTaskI.NextPointdesc<<doorSubTaskMap.size();
            }

        }
    }

    return doorSubTaskMap;

}

 //添加 自动门信息 到数据库
bool query_Single::doorSubTaskMap_insert(QMap<int, doorSubTask> doorSubTaskMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, doorSubTask>::iterator iter_=doorSubTaskMap.begin();
    while (iter_!=doorSubTaskMap.end()) {
        sqlQuery.prepare("INSERT INTO [dbo].[doorSubTask] ([doorIP],[doorDesc],"
                         "[Point],[NextPoint],[NextPointdesc],"
                         "[page],[enable]) VALUES (:doorIP,:doorDesc,"
                         ":Point,:NextPoint,:NextPointdesc,"
                         ":page,:enable );");
        sqlQuery.addBindValue(iter_.value().doorIP);              //自动门IP地址
        sqlQuery.addBindValue(iter_.value().doorDesc);            //自动门名称
        sqlQuery.addBindValue(iter_.value().Point);               //起始点  用于开门
        sqlQuery.addBindValue(iter_.value().NextPoint);           //下一点  用于开门
        sqlQuery.addBindValue(iter_.value().NextPointdesc);       //保持开门信号二维码链表
        sqlQuery.addBindValue(iter_.value().page);                //当前页面索引
        sqlQuery.addBindValue(iter_.value().enable);              //使用禁用使能
        if(!sqlQuery.exec()){

        }

        iter_++;
    }

    if(sqlDatabase.commit()){

    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;

}

//更新 自动门信息
bool query_Single::doorSubTask_update(QMap<int, doorSubTask> doorSubTaskMap)
{
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, doorSubTask>::const_iterator iter= doorSubTaskMap.begin();
    while (iter !=doorSubTaskMap.end()) {
        if(iter!=nullptr){
            sqlQuery.prepare("UPDATE [dbo].[doorSubTask] SET [doorIP]=:doorIP,"
                             "[doorDesc]=:doorDesc,[Point]=:Point,[NextPoint]=:NextPoint,"
                             "[NextPointdesc]=:NextPointdesc,"
                             "[page]=:page,[enable]=:enable "
                             "WHERE [Id]=:Id;");

            sqlQuery.addBindValue(iter.value().doorIP);              //自动门IP地址
            sqlQuery.addBindValue(iter.value().doorDesc);            //自动门名称
            sqlQuery.addBindValue(iter.value().Point);               //起始点  用于开门
            sqlQuery.addBindValue(iter.value().NextPoint);           //下一点  用于开门
            sqlQuery.addBindValue(iter.value().NextPointdesc);       //保持开门信号二维码链表
            sqlQuery.addBindValue(iter.value().page);                //当前页面索引
            sqlQuery.addBindValue(iter.value().enable);              //使用禁用使能
            sqlQuery.addBindValue(iter.value().doorId);

            if(sqlQuery.exec()){
                qDebug()<<"更新 自动门信息 S"<<iter.value().doorId<<iter.value().doorIP
                       <<iter.value().doorDesc<<iter.value().Point<<iter.value().NextPoint<<iter.value().NextPointdesc;
            }else {
                qDebug()<<"更新 自动门信息 E"<<iter.value().doorId<<iter.value().doorIP;
            }
        }else{
            return false;
        }
        iter++;
    }

    return true;
}

//删除 自动门信息
bool query_Single::doorSubTask_Delete(int doorId)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare(QString("DELETE FROM doorSubTask WHERE [Id]=:Id"));
    sqlQuery.addBindValue(doorId);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }
}

/************   AGV小车参数配置界面   ***************/

//查找当前AGV信息
QMap<QString, AGVCurrentTask> query_Single::query_AGVCurrentTask(QString AGVIP)
{
    QMap<QString, AGVCurrentTask> AGVCurrentTaskMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    if(AGVIP==""){
        sqlQuery.prepare("select * from AGVCurrentTask ;");
    }else{
        sqlQuery.prepare("select * from AGVCurrentTask where  AGVIP=:AGVIP ;");
        sqlQuery.addBindValue(AGVIP);
    }

    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            AGVCurrentTask AGVCurrentTaskI;
            AGVCurrentTaskI.AGVId=sqlQuery.value("AGVId").toInt();                      //小车编号
            AGVCurrentTaskI.AGVIP=sqlQuery.value("AGVIP").toString();                   //小车 ip
            AGVCurrentTaskI.enable=sqlQuery.value("enable").toInt();                    //1使用  0禁用
            AGVCurrentTaskI.AGVType=sqlQuery.value("AGVType").toInt();                  //AGV类型    0默认小精灵   1夹抱AGV
            AGVCurrentTaskI.floornum=sqlQuery.value("floornum").toInt();                //AGV所在楼层
            AGVCurrentTaskI.waitPoint=sqlQuery.value("waitPoint").toInt();              //待机点二维码

            AGVCurrentTaskI.taskId=sqlQuery.value("taskId").toString();                 //唯一识别号
            AGVCurrentTaskI.taskType=sqlQuery.value("taskType").toString();             //任务类型 IN入库  OUT出库
            AGVCurrentTaskI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();        //任务索引 唯一值
            AGVCurrentTaskI.containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

            AGVCurrentTaskI.chargeIP=sqlQuery.value("chargeIP").toString();             //充电桩IP
            AGVCurrentTaskI.ChargePoint=sqlQuery.value("ChargePoint").toInt();          //充电点二维码
            AGVCurrentTaskI.ChargeWait=sqlQuery.value("ChargeWait").toInt();            //充电点前一个二维码
            AGVCurrentTaskI.MoveAnage=sqlQuery.value("MoveAnage").toInt();              //小车进出充电位置 姿态以及移动角度
            AGVCurrentTaskI.ChargeAction=sqlQuery.value("ChargeAction").toInt();        //充电动作指令
            AGVCurrentTaskI.ChargeTimer=sqlQuery.value("ChargeTimer").toInt();          //充电计时 还剩余多少 分钟  60 *60 =3600秒
            AGVCurrentTaskI.ChargeAction_all=sqlQuery.value("ChargeAction_all").toInt();//总的充电动作逻辑

            if(!AGVCurrentTaskMap.contains(AGVCurrentTaskI.AGVIP)){
                AGVCurrentTaskMap.insert(AGVCurrentTaskI.AGVIP,AGVCurrentTaskI);
                //qDebug()<<"AGVIP:"<<AGVCurrentTaskI.AGVIP<<" AGVType:"<<AGVCurrentTaskI.AGVType<<" chargeIP:"<<AGVCurrentTaskI.chargeIP;
            }

        }
    }

    return AGVCurrentTaskMap;
}

//添加 AGV信息 到数据库
bool query_Single::AGVCurrentTask_insert(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, AGVCurrentTask>::iterator iter_=AGVCurrentTaskMap.begin();
    while (iter_!=AGVCurrentTaskMap.end()) {
        sqlQuery.prepare("INSERT INTO [dbo].[AGVCurrentTask] ([Id],[AGVId],[AGVIP],"
                         "[enable],[AGVType],[floornum],[waitPoint],"
                         "[chargeIP],[ChargePoint],"
                         "[ChargeWait],[MoveAnage]) VALUES (:Id,:AGVId,:AGVIP,"
                         ":enable,:AGVType,:floornum,:waitPoint,"
                         ":chargeIP,:ChargePoint,"
                         ":ChargeWait,:MoveAnage );");

        sqlQuery.addBindValue(iter_.value().AGVId);
        sqlQuery.addBindValue(iter_.value().AGVId);                //小车编号
        sqlQuery.addBindValue(iter_.value().AGVIP);                //小车 ip
        sqlQuery.addBindValue(iter_.value().enable);               //1使用  0禁用
        sqlQuery.addBindValue(iter_.value().AGVType);              //AGV类型    0默认小精灵   1夹抱AGV
        sqlQuery.addBindValue(iter_.value().floornum);             //AGV所在楼层
        sqlQuery.addBindValue(iter_.value().waitPoint);            //待机点二维码

        sqlQuery.addBindValue(iter_.value().chargeIP);             //充电桩IP
        sqlQuery.addBindValue(iter_.value().ChargePoint);          //充电点二维码
        sqlQuery.addBindValue(iter_.value().ChargeWait);           //充电点前一个二维码
        sqlQuery.addBindValue(iter_.value().MoveAnage);            //小车进出充电位置 姿态以及移动角度
        if(!sqlQuery.exec()){

        }

        iter_++;
    }

    if(sqlDatabase.commit()){

    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;
}

//更新 AGV信息
bool query_Single::AGVCurrentTask_update(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap)
{
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, AGVCurrentTask>::const_iterator iter= AGVCurrentTaskMap.begin();
    while (iter !=AGVCurrentTaskMap.end()) {
        if(iter!=nullptr){

            sqlQuery.prepare("UPDATE [dbo].[AGVCurrentTask] SET [AGVId]=:AGVId,"
                             "[enable]=:enable,[AGVType]=:AGVType,[floornum]=:floornum,"
                             "[waitPoint]=:waitPoint,[chargeIP]=:chargeIP,[ChargePoint]=:ChargePoint,"
                             "[ChargeWait]=:ChargeWait,[MoveAnage]=:MoveAnage "
                             "WHERE [AGVIP]=:AGVIP;");

            sqlQuery.addBindValue(iter.value().AGVId);                //小车编号
            sqlQuery.addBindValue(iter.value().enable);               //1使用  0禁用
            sqlQuery.addBindValue(iter.value().AGVType);              //AGV类型    0默认小精灵   1夹抱AGV
            sqlQuery.addBindValue(iter.value().floornum);             //AGV所在楼层
            sqlQuery.addBindValue(iter.value().waitPoint);            //待机点二维码
            sqlQuery.addBindValue(iter.value().chargeIP);             //充电桩IP
            sqlQuery.addBindValue(iter.value().ChargePoint);          //充电点二维码
            sqlQuery.addBindValue(iter.value().ChargeWait);           //充电点前一个二维码
            sqlQuery.addBindValue(iter.value().MoveAnage);            //小车进出充电位置 姿态以及移动角度
            sqlQuery.addBindValue(iter.value().AGVIP);                //小车 ip

            if(sqlQuery.exec()){
                qDebug()<<"更新  AGV信息 S"<<iter.value().AGVIP<<iter.value().chargeIP;
            }else {
                qDebug()<<"更新  AGV信息 E"<<iter.value().AGVIP<<iter.value().chargeIP;
            }
        }else{
            return false;
        }
        iter++;
    }

    return true;
}

//删除 AGV信息
bool query_Single::AGVCurrentTask_Delete(QString AGVIP)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare(QString("DELETE FROM AGVCurrentTask WHERE [AGVIP]=:AGVIP"));
    sqlQuery.addBindValue(AGVIP);
    if(sqlQuery.exec()){
        return true;
    }else {
        return false;
    }

}


query_Single *query_Single::GetInstance()
{
    if(query_SingleItiem != nullptr){
        return query_SingleItiem;
    }else{
        mutex.lock();
        query_SingleItiem=new query_Single;
        mutex.unlock();
        return query_SingleItiem;
    }
}
