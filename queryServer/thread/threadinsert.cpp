#include "threadinsert.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

ThreadInsert::ThreadInsert(QObject *parent) : QObject(parent)
{
    threadTimer = new QTimer(this);
    connect(threadTimer,&QTimer::timeout,this,&ThreadInsert::ON_threadTimer);
    threadTimer->start(800);

}

void ThreadInsert::ON_threadTimer()
{

    if(!insetSAPExcel  || !insertlabelMsgStruct || !insertMaterialShelfbinInfo){
        return;//错开写入数据库
    }
    if(upSAPExcelcount>0){upSAPExcelcount--;}

    //往数据库 写入 新的 SAPExcelInfo 任务
    if(!newStroageTaskMapList.isEmpty() && insetSAPExcel){
        insetSAPExcel=false;
        if(newSAPExcelInfoTask(newStroageTaskMapList[0])){
            newStroageTaskMapList.removeAt(0);
        }
        insetSAPExcel=true;
        return;
    }if(newStroageTaskMapList.isEmpty()){
        if(ActionItiem.SAPAction== 1 && upSAPExcelcount<=0){//0 无状态 1 执行更新 2 更新完成  3 执行取消  4取消完成
            ActionItiem.SAPAction=2;
        }
    }


    //往本地数据库，添加新的容器信息
    if(!newMaterialShelfbinMapList.isEmpty() && insertMaterialShelfbinInfo){
        insertMaterialShelfbinInfo=false;
        insertIntoNewmaterialShelfbinInfo(newMaterialShelfbinMapList[0]);
        newMaterialShelfbinMapList.removeAt(0);
        insertMaterialShelfbinInfo=true;
    }

    //往数据库 写入 每次  WS01  SAP 反馈的数据  记录
    if(!insertrecord_sapMapList.isEmpty() && insertlabelMsgStruct){
        insertlabelMsgStruct=false;
        insertIntorecord_sap(insertrecord_sapMapList[0]);
        insertrecord_sapMapList.removeAt(0);
        insertlabelMsgStruct=true;
    }

}

//Action 0 无状态 1 执行更新 2 更新完成  3 执行取消  4取消完成
void ThreadInsert::setSAPAction(int Action, QMap<QString, SAPExcelInfo> StroageTaskMap, int pickStation)
{
    ActionItiem.SAPAction=Action;
    upSAPExcelcount=5;
    if(ActionItiem.SAPAction==1){
        if(!newStroageTaskMap.isEmpty()){
            newStroageTaskMapList.append(newStroageTaskMap);
            newStroageTaskMap.clear();
        }
        ActionItiem.pickStation=pickStation;
    }

    if(ActionItiem.SAPAction==3){
        newStroageTaskMap.clear();
        newStroageTaskMapList.clear();
        ActionItiem.StroageTaskMap=StroageTaskMap;
    }

    if(!insertrecord_sapMap.isEmpty()){
        insertrecord_sapMapList.append(insertrecord_sapMap);
        insertrecord_sapMap.clear();
    }

}

bool ThreadInsert::addSAPExcelInfoTask(SAPExcelInfo SAPExcelInfoI, QString Ikey,int type)
{
    if(!newStroageTaskMap.contains(Ikey)){
        newStroageTaskMap.insert(Ikey,SAPExcelInfoI);
        if(newStroageTaskMap.size()>=50 || type==1){
            newStroageTaskMapList.append(newStroageTaskMap);
            newStroageTaskMap.clear();
        }
        return true;
    }
    return false;
}

bool ThreadInsert::newSAPExcelInfoTask(QMap<QString, SAPExcelInfo> newStroageTaskMap)
{
    bool newtaskbool=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, SAPExcelInfo>::iterator iter= newStroageTaskMap.begin();
    while (iter !=newStroageTaskMap.end()) {

        sqlQuery.prepare("INSERT INTO [dbo].[sapExcelinfo] ([taskType], [taskTypeDesc],"
                         "[taskId], [taskId_ess], [taskId_agv], [floorId], [taskStatus], [taskStatusDesc], [sourcestation],"
                         "[pickDesc_s], [pickDesc_e], [destination], [podIdDesc], [shelfBindesc], [containerCode],"
                         "[batch], [oldIdDesc], [oldBinDesc], [newIdDesc], [newBinDesc],[Priority],"
                         "[cancelTask], [taskError], [errortextEdit], [lastuser], [creatTimer],"
                         "[LabelNo], [Material], [customsType], [storeCode],"
                         "[taskQty],[MaterialListdesc]) VALUES (:taskType, :taskTypeDesc,"
                         ":taskId, :taskId_ess, :taskId_agv, :floorId, :taskStatus, :taskStatusDesc, :sourcestation,"
                         ":pickDesc_s, :pickDesc_e, :destination, :podIdDesc, :shelfBindesc, :containerCode,"
                         ":batch, :oldIdDesc, :oldBinDesc, :newIdDesc, :newBinDesc, :Priority,"
                         ":cancelTask, :taskError, :errortextEdit, :lastuser,:creatTimer,"
                         ":LabelNo, :Material, :customsType, :storeCode,"
                         ":taskQty,:MaterialListdesc);");

        sqlQuery.addBindValue(iter.value().taskType);        //任务类型  1出库  2入库 3盘点 4查仓 5改位入库
        sqlQuery.addBindValue(iter.value().taskTypeDesc);    //操作 OUT-出库  IN-入库

        sqlQuery.addBindValue(iter.value().taskId);          //任务编码 唯一性
        sqlQuery.addBindValue(iter.value().taskId_ess);      //夹抱机器人 任务编码 唯一性
        sqlQuery.addBindValue(iter.value().taskId_agv);      //举升机器人 任务编码 唯一性
        sqlQuery.addBindValue(iter.value().floorId);         //楼层走向  2F-3F 3F-2F

        sqlQuery.addBindValue(iter.value().taskStatus);      //任务状态
        sqlQuery.addBindValue(iter.value().taskStatusDesc);  //任务状态注释

        sqlQuery.addBindValue(iter.value().sourcestation);   //来源 入库为NULL，出库为库位
        sqlQuery.addBindValue(iter.value().pickDesc_s);       //起始站点的对接码头

        sqlQuery.addBindValue(iter.value().pickDesc_e);      //目标站点的对接码头
        sqlQuery.addBindValue(iter.value().destination);     //目的地。入库为库位，出库为线体

        sqlQuery.addBindValue(iter.value().podIdDesc);       //所属架位注释 -- MES
        sqlQuery.addBindValue(iter.value().shelfBindesc);    //所属架位注释 -- ESS
        sqlQuery.addBindValue(iter.value().containerCode);   //容器编码 (即胶箱编码) ->唯一
        sqlQuery.addBindValue(iter.value().batch);           //批次

        sqlQuery.addBindValue(iter.value().oldIdDesc);       //所属架位注释 -- MES
        sqlQuery.addBindValue(iter.value().oldBinDesc);      //改架前的 Bin   (用于AGV内部移库) -- ESS

        sqlQuery.addBindValue(iter.value().newIdDesc);       //所属架位注释 -- MES
        sqlQuery.addBindValue(iter.value().newBinDesc);      //改架后的 Bin   (用于AGV内部移库) -- ESS

        sqlQuery.addBindValue(iter.value().Priority);        //出库任务 优先级 1-100 由高到低  默认值不变100
        sqlQuery.addBindValue(iter.value().cancelTask);      //大于0  取消
        sqlQuery.addBindValue(iter.value().taskError);       //任务错误代码
        sqlQuery.addBindValue(iter.value().errortextEdit);   //异常原因详细信息

        sqlQuery.addBindValue(iter.value().lastuser);        //操作员
        sqlQuery.addBindValue(QDateTime::currentDateTime()); //创建时间

    /********************* MES 的订单物料信息 *********************/
        sqlQuery.addBindValue(iter.value().LabelNo);          //贴纸凭证号
        sqlQuery.addBindValue(iter.value().Material);         //物料编码
        sqlQuery.addBindValue(iter.value().customsType);      //类型属性
        sqlQuery.addBindValue(iter.value().storeCode);        //仓号属性
        sqlQuery.addBindValue(iter.value().taskQty);          //数量
        sqlQuery.addBindValue(iter.value().MaterialListdesc); //物料编码 集合

        if(sqlQuery.exec()){
            qDebug()<<"insert sql ##############S newStroageTaskMap:"<<iter.value().taskType<<iter.value().containerCode<<iter.value().taskStatus<<iter.value().taskStatusDesc;
        }else {
            qDebug()<<"insert sql **************E newStroageTaskMap:"<<iter.value().LabelNo<<iter.value().taskType;
        }

        iter++;
    }

    if(!sqlDatabase.commit()){
        newtaskbool=false;
        sqlDatabase.rollback();
    }

    qDebug()<<"return newtaskbool:"<<newtaskbool;
    return newtaskbool;
}

bool ThreadInsert::addNewmaterialShelfbinInfo(materialShelfbin materialShelfbinI, int status)
{
    QString ikey=materialShelfbinI.containerCode;
    if(!newMaterialShelfbinMap.contains(ikey)){
        if(newMaterialShelfbinMap.size()>=1){
            newMaterialShelfbinMapList.append(newMaterialShelfbinMap);
            newMaterialShelfbinMap.clear();
        }
        return true;
    }
    return false;
}

bool ThreadInsert::insertIntoNewmaterialShelfbinInfo(QMap<QString, materialShelfbin> newMaterialShelfbinMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<QString ,materialShelfbin >::iterator iter=newMaterialShelfbinMap.begin();
    while (iter!=newMaterialShelfbinMap.end()) {
        materialShelfbin materialShelfbinI=iter.value();
        if(!newMaterialShelfbinMap.contains(materialShelfbinI.containerCode)){

            sqlQuery.prepare("INSERT INTO [dbo].[materialShelfbinMap] ([containerIndex], [containerCode],"
                             "[shelfBinIndex], [shelfBindesc],[materialNumber],[pcbListdesc],[plant],"
                             "[status], [storeCode],[base_unit],[customsType],[realqty],[checkqty],"
                             "[creatTimer],[lastuser],[lastCheckTimer]) VALUES (:containerIndex,:containerCode,"
                             ":shelfBinIndex,:shelfBindesc,:materialNumber,:pcbListdesc,:plant,"
                             ":status,:storeCode,:base_unit,:customsType,:realqty,:checkqty,"
                             ":creatTimer,:lastuser,:lastCheckTimer );");

            sqlQuery.addBindValue(materialShelfbinI.containerIndex);
            sqlQuery.addBindValue(materialShelfbinI.containerCode);
            sqlQuery.addBindValue(materialShelfbinI.shelfBinIndex);
            sqlQuery.addBindValue(materialShelfbinI.shelfBindesc);
            sqlQuery.addBindValue(materialShelfbinI.materialNumber);
            sqlQuery.addBindValue(materialShelfbinI.pcbListdesc);
            sqlQuery.addBindValue(materialShelfbinI.plant);
            sqlQuery.addBindValue(materialShelfbinI.status);
            sqlQuery.addBindValue(materialShelfbinI.storeCode);
            sqlQuery.addBindValue(materialShelfbinI.base_unit);
            sqlQuery.addBindValue(materialShelfbinI.customsType);
            sqlQuery.addBindValue(materialShelfbinI.realqty);
            sqlQuery.addBindValue(materialShelfbinI.checkqty);
            sqlQuery.addBindValue(materialShelfbinI.creatTimer);
            sqlQuery.addBindValue(materialShelfbinI.lastuser);
            sqlQuery.addBindValue(materialShelfbinI.lastCheckTimer);

            if(!sqlQuery.exec()){

            }
        }

        iter++;
    }

    if(sqlDatabase.commit()){
        newMaterialShelfbinMapList.removeAt(0);
    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;
}

bool ThreadInsert::insertIntoshelfBinInfoInfo(QMap<QString, shelfBinInfo> newshelfBinInfoMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    QMap<QString ,shelfBinInfo >::iterator iter=newshelfBinInfoMap.begin();
    while (iter!=newshelfBinInfoMap.end()) {
        shelfBinInfo shelfBinInfoI=iter.value();
        sqlQuery.prepare("INSERT INTO [dbo].[shelfInfo] ([shelfBinIndex], [shelfBindesc],"
                         "[podId], [podIdDesc],[containerIndex],[containerCode],[storeCode],"
                         "[LabelNo], [binEnable],[showEnable],[setFull],[layer],[side],"
                         "[volume], [allvolume],[percent],[realqty],"
                         "[weight],[maxweight]) VALUES (:shelfBinIndex,:shelfBindesc,"
                         ":podId,:podIdDesc,:containerIndex,:containerCode,:storeCode,"
                         ":LabelNo,:binEnable,:showEnable,:setFull,:layer,:side,"
                         ":volume,:allvolume,:percent,:realqty,"
                         ":weight,:maxweight );");

        sqlQuery.addBindValue(shelfBinInfoI.shelfBinIndex);         //所属架位索引
        sqlQuery.addBindValue(shelfBinInfoI.shelfBindesc);          //所属架位注释
        sqlQuery.addBindValue(shelfBinInfoI.podId);                 //货架编号
        sqlQuery.addBindValue(shelfBinInfoI.podIdDesc);             //货架注释
        sqlQuery.addBindValue(shelfBinInfoI.containerIndex);        //容器编码索引 ->唯一
        sqlQuery.addBindValue(shelfBinInfoI.containerCode);         //容器编码 (即胶箱编码) ->唯一
        sqlQuery.addBindValue(shelfBinInfoI.storeCode);             //仓号属性
        sqlQuery.addBindValue(shelfBinInfoI.LabelNo);               //工单凭证号
        sqlQuery.addBindValue(shelfBinInfoI.binEnable);             //使用/禁用
        sqlQuery.addBindValue(shelfBinInfoI.showEnable);            //是否显示
        sqlQuery.addBindValue(shelfBinInfoI.setFull);               //0未满  1已满
        sqlQuery.addBindValue(shelfBinInfoI.layer);                 //第几层
        sqlQuery.addBindValue(shelfBinInfoI.side);                  //A,B 面
        sqlQuery.addBindValue(shelfBinInfoI.volume);                //Bin的体积 14升
        sqlQuery.addBindValue(shelfBinInfoI.allvolume);             //总体积
        sqlQuery.addBindValue(shelfBinInfoI.percent);               //占用 %
        sqlQuery.addBindValue(shelfBinInfoI.realqty);               //实际存放数量
        sqlQuery.addBindValue(shelfBinInfoI.status);                //0 空闲  1任务占用中
        sqlQuery.addBindValue(shelfBinInfoI.weight);                //实际存放重量
        sqlQuery.addBindValue(shelfBinInfoI.maxweight);             //最大存放重量

        if(!sqlQuery.exec()){

        }

        iter++;
    }

    if(sqlDatabase.commit()){

    }else {
        sqlDatabase.rollback();
        return false;
    }
    return true;
}

void ThreadInsert::insertrecord_sap(labelMsgStruct labelMsgStructI)
{
    insertrecord_sapMap.insert(labelMsgStructI.labelNo,labelMsgStructI);
    if(insertrecord_sapMap.size()>=50){
        insertrecord_sapMapList.append(insertrecord_sapMap);
        insertrecord_sapMap.clear();
    }
}

void ThreadInsert::insertIntorecord_sap(QMap<QString ,labelMsgStruct >insertrecord_sapMap)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString ,labelMsgStruct >::iterator iter=insertrecord_sapMap.begin();
    while (iter!=insertrecord_sapMap.end()) {
        labelMsgStruct labelMsgStructI=iter.value();

        sqlQuery.prepare("INSERT INTO [dbo].[record_ws01] ([labelNo], [material], "
                         "[plant], [store], [bin], [base_unit], [base_qty], [unit], "
                         "[qty], [describe], [batch], [unitOfWeigh], [weighUnit],"
                         " [customsType], [result], [message], "
                         "[timer],[replylabelNo],[IssueType], [IssueStore],"
                         "[IssueBin], [rv_customs_type], [sp_customs_type]) VALUES (:labelNo,:material,:plant,"
                         ":store, :bin, :base_unit, :base_qty,:unit, :qty, :describe, :batch, "
                         ":unitOfWeigh, :weighUnit, :customsType, "
                         ":result, :message, :timer,:replylabelNo,"
                         ":IssueType, :IssueStore, :IssueBin , :rv_customs_type, :sp_customs_type);");

        sqlQuery.addBindValue(labelMsgStructI.labelNo);
        sqlQuery.addBindValue(labelMsgStructI.material);
        sqlQuery.addBindValue(labelMsgStructI.plant);
        sqlQuery.addBindValue(labelMsgStructI.rv_Store);
        sqlQuery.addBindValue(labelMsgStructI.rv_Bin);
        sqlQuery.addBindValue(labelMsgStructI.base_unit);
        sqlQuery.addBindValue(labelMsgStructI.base_qty);
        sqlQuery.addBindValue(labelMsgStructI.unit);
        sqlQuery.addBindValue(labelMsgStructI.qty);
        sqlQuery.addBindValue(labelMsgStructI.describe);
        sqlQuery.addBindValue(labelMsgStructI.batch);
        sqlQuery.addBindValue(labelMsgStructI.unitOfWeigh);
        sqlQuery.addBindValue(labelMsgStructI.weighUnit);
        sqlQuery.addBindValue(labelMsgStructI.customsType);
        sqlQuery.addBindValue(labelMsgStructI.result);
        sqlQuery.addBindValue(labelMsgStructI.message);
        sqlQuery.addBindValue(QDateTime::currentDateTime());
        sqlQuery.addBindValue(labelMsgStructI.replylabelNo);
        sqlQuery.addBindValue(labelMsgStructI.IssueType);
        sqlQuery.addBindValue(labelMsgStructI.IssueStore);
        sqlQuery.addBindValue(labelMsgStructI.IssueBin);
        sqlQuery.addBindValue(labelMsgStructI.rv_customs_type);
        sqlQuery.addBindValue(labelMsgStructI.sp_customs_type);

        if(!sqlQuery.exec()){
            qDebug()<<"record_sap: "<<labelMsgStructI.labelNo;
        }
        iter++;
    }

    if(sqlDatabase.commit()){
        insertrecord_sapMap.clear();
    }else {
        sqlDatabase.rollback();
    }

}

void ThreadInsert::insertrecord_log(QMap<QString, record_log> record_logMap, int TypeId)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);
    int count=0;
    QMap<QString, record_log>::iterator iter= record_logMap.begin();
    while (iter!=record_logMap.end()) {

        sqlQuery.prepare( "INSERT INTO [dbo].[record_log] ([LabelNo], [Material],"
                          "[shelfBinIndex], [shelfBindesc], [store], [batch], [Unit],"
                          "[sapQty], [readlQty], [UserNumber], [taskType], [errorTypeId],"
                          "[errormassega], [Time], [nowDate], [TypeId], "
                          "[WeighType], [allWeigh], [weigh_base], [weigh_pcs],"
                          "[base_weigh], [IssueType], [LabelType], [operaterIndex],[orderId]) VALUES (:LabelNo, :Material, "
                          ":shelfBinIndex, :shelfBindesc, :store, :batch, :Unit, "
                          ":sapQty, :readlQty, :UserNumber, :taskType, :errorTypeId, "
                          ":errormassega, :Time, :nowDate,:TypeId,"
                          ":WeighType,:allWeigh,:weigh_base,:weigh_pcs,"
                          ":base_weigh,:IssueType,:LabelType,:operaterIndex,:orderId);");

        sqlQuery.addBindValue(iter.value().LabelNo);        //1
        sqlQuery.addBindValue(iter.value().Material);       //2
        sqlQuery.addBindValue(iter.value().shelfBinIndex);  //3
        sqlQuery.addBindValue(iter.value().shelfBindesc);   //4
        sqlQuery.addBindValue(iter.value().store);          //5
        sqlQuery.addBindValue(iter.value().batch);          //6
        sqlQuery.addBindValue(iter.value().Unit);           //7
        sqlQuery.addBindValue(iter.value().sapQty);         //8
        sqlQuery.addBindValue(iter.value().readlQty);       //9
        sqlQuery.addBindValue(iter.value().UserNumber);     //10
        sqlQuery.addBindValue(iter.value().taskType);       //11
        sqlQuery.addBindValue(iter.value().errorTypeId);    //12
        sqlQuery.addBindValue(iter.value().errormassega);   //13
        sqlQuery.addBindValue(iter.value().Time);           //14
        sqlQuery.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd"));//15
        sqlQuery.addBindValue(TypeId);                      //16
        sqlQuery.addBindValue(iter.value().WeighType);      //17
        sqlQuery.addBindValue(iter.value().allWeigh);       //18
        sqlQuery.addBindValue(iter.value().weigh_base);     //19
        sqlQuery.addBindValue(iter.value().weigh_pcs);      //20
        sqlQuery.addBindValue(iter.value().base_weigh);     //21
        sqlQuery.addBindValue(iter.value().IssueType);      //22
        sqlQuery.addBindValue(iter.value().LabelType);      //23
        sqlQuery.addBindValue(iter.value().operaterIndex);  //24
        sqlQuery.addBindValue(iter.value().orderId);        //25

        if(sqlQuery.exec()){
            count++;
            qDebug()<<"record_log:"<<iter.value().Material<<iter.value().store<<iter.value().batch<<iter.value().readlQty<<"  count:"<<count;
        }
        iter++;
    }

    if(!sqlDatabase.commit()){
        sqlDatabase.rollback();
    }

}

void ThreadInsert::insertemail_message(email_message email_messageI)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare("INSERT INTO [dbo].[email_message] ([message], [creatTime],"
                     "[status]) VALUES (:message,:creatTime,:status);");

    sqlQuery.addBindValue(email_messageI.message);
    sqlQuery.addBindValue(QDateTime::currentDateTime());
    sqlQuery.addBindValue(email_messageI.status);
    if(!sqlQuery.exec()){
        qDebug()<<""<<sqlQuery.lastError()<<email_messageI.message;
    }
}


