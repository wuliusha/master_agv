#include "queryserver.h"
STATEMENTINSTANCE(queryServer)
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

queryServer::queryServer(QObject *parent) : QObject(parent)
{

}

void queryServer::setCurrentServerInitItem(ServerInit CServerInit)
{
    ServerInitItem=CServerInit;
}

ServerInit queryServer::getCurrentServerInitItem()
{
    return ServerInitItem;
}

QList<User_Info> queryServer::getUserInfoList()
{
    return ServerInitItem.UserInfoList;
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

QMap<QString, materialShelfbin> queryServer::querymaterialshelfBinMap(shelfBinInfo shelfBinInfoItem)
{
    QMap<QString, materialShelfbin>materialshelfBinMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery1(sqlDatabase);
    sqlQuery1.setForwardOnly(true);

    sqlQuery1.prepare("select * from materialShelfbinMap "
                     "where shelfBinIndex =:shelfBinIndex and containerIndex =:containerIndex;");
    sqlQuery1.addBindValue(shelfBinInfoItem.shelfBinIndex);
    sqlQuery1.addBindValue(shelfBinInfoItem.containerIndex);

    if(sqlQuery1.exec())
    {
        while(sqlQuery1.next())
        {
            materialShelfbin materialShelfbinI;
            materialShelfbinI.containerIndex=sqlQuery1.value("containerIndex").toInt();     //容器编码索引 ->唯一
            materialShelfbinI.containerCode=sqlQuery1.value("containerCode").toString();    //容器编码 (即胶箱编码) ->唯一

            materialShelfbinI.shelfBinIndex=sqlQuery1.value("shelfBinIndex").toInt();       //所属架位索引 ->唯一
            materialShelfbinI.shelfBindesc=sqlQuery1.value("shelfBindesc").toString();      //所属架位注释 ->唯一

            materialShelfbinI.materialNumber=sqlQuery1.value("materialNumber").toString();  //物料件号

            materialShelfbinI.pcbListdesc=sqlQuery1.value("pcbListdesc").toString();        //PCB 集合
            materialShelfbinI.pcbList=materialShelfbinI.pcbListdesc.split("&");
            //QString pcbListdesc= materialShelfbinI.pcbList.join("&");

            materialShelfbinI.status=sqlQuery1.value("status").toInt();                     //0 空闲  1任务占用中

            materialShelfbinI.plant=sqlQuery1.value("plant").toString();                    //工厂
            materialShelfbinI.storeCode=sqlQuery1.value("storeCode").toString();            //仓号
            materialShelfbinI.base_unit=sqlQuery1.value("base_unit").toString();            //基础单位
            materialShelfbinI.customsType=sqlQuery1.value("customsType").toString();        //报关类型

            materialShelfbinI.realqty=sqlQuery1.value("realqty").toDouble();                //订单里数量
            materialShelfbinI.checkqty=sqlQuery1.value("checkqty").toDouble();              //盘点数量

            materialShelfbinI.creatTimer=sqlQuery1.value("creatTimer").toDateTime();        //上次盘点时间

            materialShelfbinI.lastuser=sqlQuery1.value("lastuser").toString();              //上次盘点操作员
            materialShelfbinI.lastCheckTimer=sqlQuery1.value("lastCheckTimer").toDateTime();//上次盘点时间

            if(!materialshelfBinMap.contains(materialShelfbinI.containerCode)){
                materialshelfBinMap.insert(materialShelfbinI.containerCode,materialShelfbinI);
            }

        }
    }

    return materialshelfBinMap;
}

shelfBinInfo queryServer::querymaterialshelfBinMap_(shelfBinInfo shelfBinInfoItem)
{
    shelfBinInfo shelfBinInfoI;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery1(sqlDatabase);
    sqlQuery1.setForwardOnly(true);

    sqlQuery1.prepare("select * from materialShelfbinMap "
                     "where materialNumber =:materialNumber or containerCode =:containerCode or shelfBindesc =:shelfBindesc;");
    sqlQuery1.addBindValue(shelfBinInfoItem.materialShelfbinI.materialNumber);
    sqlQuery1.addBindValue(shelfBinInfoItem.containerCode);
    sqlQuery1.addBindValue(shelfBinInfoItem.shelfBindesc);

    if(sqlQuery1.exec())
    {
        while(sqlQuery1.next())
        {
            shelfBinInfo shelfBinInfoI;
            shelfBinInfoI.containerIndex=sqlQuery1.value("containerIndex").toInt();     //容器编码索引 ->唯一
            shelfBinInfoI.containerCode=sqlQuery1.value("containerCode").toString();    //容器编码 (即胶箱编码) ->唯一
            shelfBinInfoI.shelfBinIndex=sqlQuery1.value("shelfBinIndex").toInt();       //所属架位索引 ->唯一
            shelfBinInfoI.shelfBindesc=sqlQuery1.value("shelfBindesc").toString();      //所属架位注释 ->唯一
            shelfBinInfoI.materialShelfbinI.materialNumber=sqlQuery1.value("materialNumber").toString();  //物料件号
        }
    }

    return shelfBinInfoI;
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

