#include "queryserver.h"
STATEMENTINSTANCE(queryServer)
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

queryServer::queryServer(QObject *parent) : QObject(parent)
{

}

void queryServer::setCurrentServerInitItem(ServerItem CServerItem, ServerInit CServerInit)
{
    ALLServerInitItem.ServerInitItem=CServerInit;
    ALLServerInitItem.CurrentServerItem=CServerItem;
}

allServerInit queryServer::getCurrentServerInitItem()
{
    return ALLServerInitItem;
}

QList<User_Info> queryServer::getUserInfoList()
{
    return ALLServerInitItem.ServerInitItem.UserInfoList;
}

//**********************************任务查询********************************//
QMap<int, SAPExcelInfo> queryServer::querySAPExcelInfoList(slecetSAP_Log slecetSAP_LogI)
{
    QMap<int, SAPExcelInfo> SAPExcelInfoTask;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();

    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    if(!slecetSAP_LogI.labelNoMap.isEmpty() || !slecetSAP_LogI.materialMap.isEmpty()){
        QMap<QString,QString>selectMap;int action=0;//0标签号 1 件号
        if(!slecetSAP_LogI.labelNoMap.isEmpty()){
            selectMap=slecetSAP_LogI.labelNoMap;
        }else if(!slecetSAP_LogI.materialMap.isEmpty()) {
            selectMap=slecetSAP_LogI.materialMap;action=1;
        }

        QMap<QString,QString>::iterator iter =selectMap.begin();
        while(iter !=selectMap.end()){
            if(action==0){//标签号
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where  LabelNo =:LabelNo;");
                sqlQuery.addBindValue(iter.value());
            }else {
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where  containerCode =:containerCode;");
                sqlQuery.addBindValue(iter.value());
            }

            if(sqlQuery.exec())
            {
                while(sqlQuery.next())
                {
                    SAPExcelInfo SAPExcelInfoI;
                    SAPExcelInfoI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();//索引 唯一值
                    if(SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                        continue;
                    }

                    SAPExcelInfoI.taskType=sqlQuery.value("taskType").toString();        //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
                    SAPExcelInfoI.taskTypeDesc=sqlQuery.value("taskTypeDesc").toString();

                    SAPExcelInfoI.taskId=sqlQuery.value("taskId").toString();          //任务编码 唯一性
                    SAPExcelInfoI.taskId_ess=sqlQuery.value("taskId_ess").toString();      //夹抱机器人 任务编码 唯一性
                    SAPExcelInfoI.taskId_agv=sqlQuery.value("taskId_agv").toString();      //举升机器人 任务编码 唯一性

                    SAPExcelInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();          //任务状态
                    SAPExcelInfoI.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();  //任务状态注释

                    SAPExcelInfoI.sourcestation=sqlQuery.value("sourcestation").toString();   //来源 入库为NULL，出库为库位
                    SAPExcelInfoI.pickDesc_s=sqlQuery.value("pickDesc_s").toString();       //起始站点的对接码头

                    SAPExcelInfoI.pickDesc_e=sqlQuery.value("pickDesc_e").toString();      //目标站点的对接码头
                    SAPExcelInfoI.destination=sqlQuery.value("destination").toString();     //目的地。入库为库位，出库为线体

                    SAPExcelInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();    //所属架位注释 -- ESS
                    SAPExcelInfoI.containerCode=sqlQuery.value("containerCode").toString();   //容器编码 (即胶箱编码) ->唯一

                    SAPExcelInfoI.oldIdDesc=sqlQuery.value("oldIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.oldBinDesc=sqlQuery.value("oldBinDesc").toString();         //改架前的 Bin   (用于AGV内部移库) -- ESS

                    SAPExcelInfoI.newIdDesc=sqlQuery.value("newIdDesc").toString();       //所属架位注释 -- MES
                    SAPExcelInfoI.newBinDesc=sqlQuery.value("newBinDesc").toString();         //改架后的 Bin   (用于AGV内部移库) -- ESS

                    SAPExcelInfoI.cancelTask=sqlQuery.value("cancelTask").toInt();          //大于0  取消
                    SAPExcelInfoI.Priority=sqlQuery.value("Priority").toDouble();       //出库任务 优先级 1-100 由高到低  默认值不变100
                    SAPExcelInfoI.taskError=sqlQuery.value("taskError").toInt();           //任务错误代码
                    SAPExcelInfoI.errortextEdit=sqlQuery.value("errortextEdit").toString();  //异常原因详细信息

                    SAPExcelInfoI.lastuser=sqlQuery.value("lastuser").toString();          //操作员
                    SAPExcelInfoI.taskTimer=QDateTime::currentDateTime();
                    SAPExcelInfoI.creatTimer=sqlQuery.value("creatTimer").toDateTime();      //创建时间
                    SAPExcelInfoI.finishTimer=sqlQuery.value("finishTimer").toDateTime();     //完成时间

                /********************* MES 的订单物料信息 *********************/

                    SAPExcelInfoI.LabelNo=sqlQuery.value("LabelNo").toString();        //贴纸凭证号
                    SAPExcelInfoI.Material=sqlQuery.value("Material").toString();       //物料编码
                    SAPExcelInfoI.customsType=sqlQuery.value("customsType").toString();    //类型属性

                    SAPExcelInfoI.taskQty=sqlQuery.value("taskQty").toDouble();      //数量
                    SAPExcelInfoI.MaterialListdesc=sqlQuery.value("MaterialListdesc").toString();     //物料编码 集合
                    SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");             //物料编码 集合

                    if(!SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                        SAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                        //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus;
                    }
                    //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
                }
            }else {
                qDebug()<<"queryNewMissionInfo"<<sqlQuery.record();
            }
            ++iter;
        }

    }else {
        if(slecetSAP_LogI.taskType!=""){
            if(slecetSAP_LogI.taskType=="new"){
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where taskStatus >=:taskStatus and taskStatus <=:taskStatus;");
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
            }else{
                sqlQuery.prepare("select * from sapExcelinfo "
                                 "where taskType =:taskType and taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                                 "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
                sqlQuery.addBindValue(slecetSAP_LogI.taskType);
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
                sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
                sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
            }
        }else{
            sqlQuery.prepare("select * from sapExcelinfo "
                             "where taskStatus >=:taskStatus and taskStatus <=:taskStatus "
                             "and creatTimer >=:creatTimer and creatTimer <=:creatTimer;");
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_s);
            sqlQuery.addBindValue(slecetSAP_LogI.taskStatus_e);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeS);
            sqlQuery.addBindValue(slecetSAP_LogI.QDateTimeE);
        }

        if(sqlQuery.exec())
        {
            while(sqlQuery.next())
            {
                SAPExcelInfo SAPExcelInfoI;
                SAPExcelInfoI.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();          //索引 唯一值
                if(SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                    continue;
                }

                SAPExcelInfoI.taskType=sqlQuery.value("taskType").toString();               //任务类型  OUT-出库  IN-入库  MOVE-移库  Empty-返空箱
                SAPExcelInfoI.taskTypeDesc=sqlQuery.value("taskTypeDesc").toString();

                SAPExcelInfoI.taskId=sqlQuery.value("taskId").toString();                   //任务编码 唯一性
                SAPExcelInfoI.taskId_ess=sqlQuery.value("taskId_ess").toString();           //夹抱机器人 任务编码 唯一性
                SAPExcelInfoI.taskId_agv=sqlQuery.value("taskId_agv").toString();           //举升机器人 任务编码 唯一性
                SAPExcelInfoI.floorId=sqlQuery.value("floorId").toString();                 //楼层走向  2F-3F 3F-2F

                SAPExcelInfoI.taskStatus=sqlQuery.value("taskStatus").toInt();              //任务状态
                SAPExcelInfoI.latstaskStatus=SAPExcelInfoI.taskStatus;                      //上一个任务状态   当前状态与上一状态不一致时更新数据库
                SAPExcelInfoI.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();   //任务状态注释

                SAPExcelInfoI.sourcestation=sqlQuery.value("sourcestation").toString();     //来源 入库为NULL，出库为库位
                SAPExcelInfoI.pickDesc_s=sqlQuery.value("pickDesc_s").toString();           //起始站点的对接码头

                SAPExcelInfoI.pickDesc_e=sqlQuery.value("pickDesc_e").toString();           //目标站点的对接码头
                SAPExcelInfoI.destination=sqlQuery.value("destination").toString();         //目的地。入库为库位，出库为线体

                SAPExcelInfoI.podIdDesc=sqlQuery.value("podIdDesc").toString();             //所属架位注释 -- MES
                SAPExcelInfoI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();       //所属架位注释 -- ESS
                SAPExcelInfoI.containerCode=sqlQuery.value("containerCode").toString();     //容器编码 (即胶箱编码) ->唯一

                SAPExcelInfoI.oldIdDesc=sqlQuery.value("oldIdDesc").toString();             //所属架位注释 -- MES
                SAPExcelInfoI.oldBinDesc=sqlQuery.value("oldBinDesc").toString();           //改架前的 Bin   (用于AGV内部移库) -- ESS

                SAPExcelInfoI.newIdDesc=sqlQuery.value("newIdDesc").toString();             //所属架位注释 -- MES
                SAPExcelInfoI.newBinDesc=sqlQuery.value("newBinDesc").toString();           //改架后的 Bin   (用于AGV内部移库) -- ESS

                SAPExcelInfoI.cancelTask=sqlQuery.value("cancelTask").toInt();              //大于0  取消
                SAPExcelInfoI.Priority=sqlQuery.value("Priority").toDouble();               //出库任务 优先级 1-100 由高到低  默认值不变100
                SAPExcelInfoI.taskError=sqlQuery.value("taskError").toInt();                //任务错误代码
                SAPExcelInfoI.errortextEdit=sqlQuery.value("errortextEdit").toString();     //异常原因详细信息

                SAPExcelInfoI.lastuser=sqlQuery.value("lastuser").toString();               //操作员
                SAPExcelInfoI.taskTimer=QDateTime::currentDateTime();
                SAPExcelInfoI.creatTimer=sqlQuery.value("creatTimer").toDateTime();         //创建时间
                SAPExcelInfoI.finishTimer=sqlQuery.value("finishTimer").toDateTime();       //完成时间

            /********************* MES 的订单物料信息 *********************/

                SAPExcelInfoI.LabelNo=sqlQuery.value("LabelNo").toString();                 //贴纸凭证号
                SAPExcelInfoI.Material=sqlQuery.value("Material").toString();               //物料编码
                SAPExcelInfoI.customsType=sqlQuery.value("customsType").toString();         //类型属性
                SAPExcelInfoI.storeCode=sqlQuery.value("storeCode").toString();             //仓号属性
                SAPExcelInfoI.taskQty=sqlQuery.value("taskQty").toDouble();                  //数量
                SAPExcelInfoI.MaterialListdesc=sqlQuery.value("MaterialListdesc").toString();//物料编码 集合
                SAPExcelInfoI.MaterialList=SAPExcelInfoI.MaterialListdesc.split("&");        //物料编码 集合
                //SAPExcelInfoI.MaterialListdesc= SAPExcelInfoI.MaterialList.join("&");

                if(!SAPExcelInfoTask.contains(SAPExcelInfoI.SAPTaskIndex)){
                    SAPExcelInfoTask.insert(SAPExcelInfoI.SAPTaskIndex,SAPExcelInfoI);
                    //qDebug()<<"wait119:"<<SAPExcelInfoI.SAPTaskIndex<<SAPExcelInfoI.Material<<SAPExcelInfoI.taskStatus<<SAPExcelInfoI.taskTimer;
                }
                //qDebug()<<missionInfoI.ikey<<missionInfoI.updateQty<<sqlQuery.record();
            }

        }else {
            qDebug()<<"querySAPExcelInfoList_T size ->"<<SAPExcelInfoTask.size()<<sqlQuery.record();
        }

    }
    qDebug()<<"querySAPExcelInfoList_T size ->"<<SAPExcelInfoTask.size();
    return SAPExcelInfoTask;
}

//获取 未处理的系统异常信息
QMap<int, email_message> queryServer::getsyserror_message()
{
    QMap<int,email_message> syserror_messageMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery1(sqlDatabase);
    sqlQuery1.prepare("select * from syserror_message"
                      " where  status=:status;");
    sqlQuery1.addBindValue(0);
    if(sqlQuery1.exec())
    {
        while(sqlQuery1.next())
        {
            email_message email_messageI;
            email_messageI.taskId=sqlQuery1.value("taskId").toInt();
            email_messageI.message=sqlQuery1.value("message").toString();
            email_messageI.creatTime=sqlQuery1.value("creatTime").toDateTime();
            email_messageI.status=sqlQuery1.value("status").toInt();
            syserror_messageMap.insert(email_messageI.taskId,email_messageI);
            //qDebug()<<"获取 未处理的系统异常信息…………"<<email_messageI.taskId<<email_messageI.message<<email_messageI.creatTime<<email_messageI.status;
        }
    }else {
        qDebug() << sqlQuery1.lastQuery();
    }
    return syserror_messageMap;
}

//设置 已处理的系统异常信息状态
bool queryServer::setsyserror_message(email_message email_messageI)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("update syserror_message "
                     "set status = :status "
                     "where taskId = :taskId;");
    sqlQuery.addBindValue(1);
    sqlQuery.addBindValue(email_messageI.taskId);
    if(sqlQuery.exec()){
        qDebug()<<"setsyserror  email_message: "<<email_messageI.taskId<<email_messageI.message<<email_messageI.status;
    }
    return true;
}

QMap<int, email_message> queryServer::getemail_message()
{
    QMap<int,email_message> email_messageMap;
    //QDateTime QDateTimeI=QDateTime::currentDateTime().addDays(-1);
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery1(sqlDatabase);
    sqlQuery1.prepare("select * from email_message"
                      " where  status=:status;");
    sqlQuery1.addBindValue(0);
    if(sqlQuery1.exec())
    {
        while(sqlQuery1.next())
        {
            email_message email_messageI;
            email_messageI.taskId=sqlQuery1.value("taskId").toInt();
            email_messageI.message=sqlQuery1.value("message").toString();
            email_messageI.creatTime=sqlQuery1.value("creatTime").toDateTime();
            email_messageI.status=sqlQuery1.value("status").toInt();
            email_messageMap.insert(email_messageI.taskId,email_messageI);
            //qDebug()<<"获取到需要满足发邮件的信息…………"<<email_messageI.taskId<<email_messageI.message<<email_messageI.creatTime<<email_messageI.status;
        }
    }else {
        qDebug() << sqlQuery1.lastQuery();
    }

    return email_messageMap;
}

QMap<QString, materialInfo> queryServer::querymaterialInfoMap()
{
    QMap<QString, materialInfo>materialInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    sqlQuery.prepare("select * from materialInfo;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            materialInfo materialInfoI;
            materialInfoI.materialNumber=sqlQuery.value("materialNumber").toString();  //物料件号
            materialInfoI.base_unit=sqlQuery.value("unit").toString();      //基础单位   base_qty: 5 ---> base_unit: M/EA(米) ---> weighUnit: kg  代表的是5(米/个) / kg
            materialInfoI.base_qty=sqlQuery.value("base_qty").toDouble();       //基础数量
            materialInfoI.unit=sqlQuery.value("unit").toString();            //单位

            materialInfoI.batch=sqlQuery.value("batch").toString();           //批次
            materialInfoI.store=sqlQuery.value("store").toString();           //仓号
            materialInfoI.plant=sqlQuery.value("plant").toString();         //工厂
            materialInfoI.describe=sqlQuery.value("describe").toString(); //描述

            materialInfoI.unitOfWeigh=sqlQuery.value("unitOfWeigh").toString(); //物料净重
            materialInfoI.weighUnit=sqlQuery.value("weighUnit").toString();//重量单位
            materialInfoI.customsType=sqlQuery.value("customsType").toString(); //报关类型 Local国内 Tax保税 Import征税
            materialInfoI.weightChange=sqlQuery.value("weightChange").toDouble();//  --kg 的换算系数
            materialInfoI.density=sqlQuery.value("density").toDouble();        //密度

            QString ikey=materialInfoI.materialNumber+materialInfoI.store+materialInfoI.batch;
            if(!materialInfoMap.contains(ikey)){
                materialInfoMap.insert(ikey,materialInfoI);
            }
        }
    }

    return materialInfoMap;
}


QMap<int, record_log> queryServer::queryRecord_log_nowDate()
{
    QMap<int, record_log> record_logMap;
    QDateTime QDateTimeS=QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 00:00:00" ,"yyyy-MM-dd hh:mm:ss");
    QDateTime QDateTimeE=QDateTime::fromString(QDateTime::currentDateTime().toString("yyyy-MM-dd")+" 23:59:00" ,"yyyy-MM-dd hh:mm:ss");
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from record_log "
                     "where Time >=:Time and Time <=:Time;");
    sqlQuery.addBindValue(QDateTimeS);
    sqlQuery.addBindValue(QDateTimeE);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            record_log record_logI;
            record_logI.logId=sqlQuery.value("logId").toInt();//索引 唯一值
            if(record_logMap.contains(record_logI.logId)){
                continue;
            }
            record_logI.TypeId =sqlQuery.value("TypeId").toInt();
            record_logI.LabelNo=sqlQuery.value("LabelNo").toString();     //标签
            record_logI.Material=sqlQuery.value("Material").toString();    //物料件号
            record_logI.shelfBinIndex=sqlQuery.value("shelfBinIndex").toInt();    //架位 Bin index
            record_logI.shelfBindesc=sqlQuery.value("shelfBindesc").toString();   //架位号   desc
            record_logI.store=sqlQuery.value("store").toString();          //仓号
            record_logI.batch=sqlQuery.value("batch").toString();          //批次
            record_logI.Unit=sqlQuery.value("Unit").toString();           //单位
            record_logI.sapQty=sqlQuery.value("sapQty").toDouble();          //贴纸数量
            record_logI.readlQty=sqlQuery.value("readlQty").toDouble();        //实际数量
            record_logI.UserNumber=sqlQuery.value("UserNumber").toString();     //操作员
            record_logI.taskType=sqlQuery.value("taskType").toString();       //任务类型  1出库  2入库 3盘点 4查仓 5改位入库
            record_logI.errorTypeId=sqlQuery.value("errorTypeId").toInt();       //错误类型.
            record_logI.errormassega=sqlQuery.value("errormassega").toString();   //错误注释
            record_logI.Time=sqlQuery.value("Time").toDateTime();         //时间
            record_logI.nowDate=sqlQuery.value("nowDate").toString();        //日期

            record_logI.base_weigh=sqlQuery.value("base_weigh").toDouble();//SAP单个数量 的重量 kg
            record_logI.WeighType=sqlQuery.value("WeighType").toString();//称重类型   称重  计数
            record_logI.allWeigh=sqlQuery.value("allWeigh").toDouble();//称出总重   (kg)
            record_logI.weigh_base=sqlQuery.value("weigh_base").toDouble();//称出单个重量
            record_logI.weigh_pcs=sqlQuery.value("weigh_pcs").toDouble();//计数的数量
            record_logI.IssueType=sqlQuery.value("IssueType").toString();//发料类型  344 LM DN SL
            record_logI.LabelType=sqlQuery.value("LabelType").toString();//贴纸类型 N KT
            record_logI.operaterIndex=sqlQuery.value("operaterIndex").toInt();//操作台编号


            if(!record_logMap.contains(record_logI.logId)){
                record_logMap.insert(record_logI.logId,record_logI);
                //qDebug()<<"query record_log nowDate S"<<record_logI.LabelNo<<record_logI.Material<<record_logI.readlQty;
            }
        }
    }else {
        qDebug()<<"query record_log nowDate"<<sqlQuery.record();
    }
    //qDebug()<<"query record_log nowDate"<<record_logMap.size();
    return record_logMap;

}

bool queryServer::SetMessagebox(QString Messagetext)
{
    QFont ft;ft.setPointSize(12);
    QMessageBox message(QMessageBox::NoIcon, "建议: ", Messagetext, QMessageBox::Yes | QMessageBox::No, NULL);
    message.setIconPixmap(QPixmap(":/image/call.jpg"));
    message.resize(300,200);
    message.setFont(ft);
    if(message.exec() == QMessageBox::Yes)
    {
        message.close();return true;
    }
    message.close();return false;
}

