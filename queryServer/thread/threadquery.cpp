#include "threadquery.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

threadQuery::threadQuery(QObject *parent) : QObject(parent)
{
    threadTimer = new QTimer(this);
    connect(threadTimer,&QTimer::timeout,this,&threadQuery::threadQueryTimer);
    threadTimer->start(600);
}

void threadQuery::threadQueryTimer()
{
    QElapsedTimer timer;timer.start();
    if(!Servercountbool){return;}
    threadServercount++;

    if(threadServercount>3000){threadServercount=0;}
    if(timer.elapsed()>1000){
        qDebug()<<"Query read data cost:"<<timer.elapsed()<<"ms  "<<QDateTime::currentDateTime().toString("hh:mm ss");timer.restart();
    }
}

bool threadQuery::UP_SAPExcelInfotaskCode(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList)
{
    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, SAPExcelInfo>::const_iterator iter= slecetSAPExcelInfoList.begin();
    while (iter !=slecetSAPExcelInfoList.end()) {
        if(iter!=nullptr){
            if(!iter.value().finishTimer.isNull()){
                sqlQuery.prepare("UPDATE [dbo].[sapExcelinfo] SET [pickDesc_s]=:pickDesc_s,[taskId_ess]=:taskId_ess,[taskId_agv]=:taskId_agv,"
                                 "[taskStatus]=:taskStatus,[taskStatusDesc]=:taskStatusDesc,[taskError]=:taskError,"
                                 "[errortextEdit]=:errortextEdit,[finishTimer]=:finishTimer "
                                 "WHERE ([SAPTaskIndex]=:SAPTaskIndex);");
                sqlQuery.addBindValue(iter.value().pickDesc_s);
                sqlQuery.addBindValue(iter.value().taskId_ess);
                sqlQuery.addBindValue(iter.value().taskId_agv);
                sqlQuery.addBindValue(iter.value().taskStatus);
                sqlQuery.addBindValue(iter.value().taskStatusDesc);
                sqlQuery.addBindValue(iter.value().taskError);
                sqlQuery.addBindValue(iter.value().errortextEdit);
                sqlQuery.addBindValue(iter.value().finishTimer);
                sqlQuery.addBindValue(iter.value().SAPTaskIndex);
            }else{
                sqlQuery.prepare("UPDATE [dbo].[sapExcelinfo] SET [pickDesc_s]=:pickDesc_s,[taskId_ess]=:taskId_ess,[taskId_agv]=:taskId_agv,"
                                 "[taskStatus]=:taskStatus,[taskStatusDesc]=:taskStatusDesc,[taskError]=:taskError,"
                                 "[errortextEdit]=:errortextEdit "
                                 "WHERE ([SAPTaskIndex]=:SAPTaskIndex);");
                sqlQuery.addBindValue(iter.value().pickDesc_s);
                sqlQuery.addBindValue(iter.value().taskId_ess);
                sqlQuery.addBindValue(iter.value().taskId_agv);
                sqlQuery.addBindValue(iter.value().taskStatus);
                sqlQuery.addBindValue(iter.value().taskStatusDesc);
                sqlQuery.addBindValue(iter.value().taskError);
                sqlQuery.addBindValue(iter.value().errortextEdit);
                sqlQuery.addBindValue(iter.value().SAPTaskIndex);
            }

            if(sqlQuery.exec()){
                shelfBinInfo shelfBinInfoI;
                if(iter.value().taskType!="Empty" && iter.value().taskError==0){
                    //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
                    if(iter.value().codeStatus==0 || iter.value().codeStatus==2
                            || iter.value().codeStatus==3){
                        shelfBinInfoI.status=iter.value().codeStatus;
                        shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                        shelfBinInfoI.SAPTaskIndex=iter.value().SAPTaskIndex;
                        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);

                    }if(iter.value().codeStatus==1){
                        shelfBinInfoI.status=iter.value().codeStatus;
                        if(iter.value().containerCode.size()==10){
                            shelfBinInfoI.containerIndex=iter.value().containerCode.right(9).toInt();
                        }
                        shelfBinInfoI.containerCode=iter.value().containerCode;
                        shelfBinInfoI.shelfBindesc=iter.value().shelfBindesc;
                        shelfBinInfoI.SAPTaskIndex=iter.value().SAPTaskIndex;
                        shelfBinInfoI.LabelNo=iter.value().LabelNo;
                        shelfBinInfoMap.insert(shelfBinInfoI.shelfBindesc,shelfBinInfoI);
                    }
                }
                qDebug()<<"taskId_ess S"<<iter.value().SAPTaskIndex<<iter.value().taskId_ess
                       <<iter.value().containerCode<<iter.value().taskStatus<<iter.value().taskStatusDesc;
            }else {
                qDebug()<<"taskId_ess E"<<iter.value().SAPTaskIndex<<iter.value().taskId_ess
                       <<iter.value().containerCode<<iter.value().taskStatus<<sqlQuery.lastError();
            }
        }else{
            return false;
        }
        ++iter;
    }

    if(!shelfBinInfoMap.isEmpty()){
        sqlQuery.clear();
        foreach(shelfBinInfo iter,shelfBinInfoMap.values())
        {
            //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
            if(iter.status==0 || iter.status==1){
                int SAPTaskIndex=iter.SAPTaskIndex;
                if(iter.status==0){SAPTaskIndex=0;}
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[containerCode]=:containerCode,"
                                 "[SAPTaskIndex]=:SAPTaskIndex,[LabelNo]=:LabelNo "
                                 "WHERE ([SAPTaskIndex]=:SAPTaskIndex);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.containerCode);
                sqlQuery.addBindValue(SAPTaskIndex);
                sqlQuery.addBindValue(iter.LabelNo);
                sqlQuery.addBindValue(iter.SAPTaskIndex);

            }if(iter.status==2 || iter.status==3){
                int SAPTaskIndex=iter.SAPTaskIndex;
                if(iter.status==2){SAPTaskIndex=0;}
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[SAPTaskIndex]=:SAPTaskIndex "
                                 "WHERE ([shelfBindesc]=:shelfBindesc);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.SAPTaskIndex);
                sqlQuery.addBindValue(iter.shelfBindesc);

            }
            if(sqlQuery.exec()){
                qDebug()<<"shelfInfo S"<<iter.podIdDesc<<iter.shelfBindesc<<iter.containerCode<<" status:"<<iter.status;
            }else {
                qDebug()<<"shelfInfo E"<<iter.podIdDesc<<iter.shelfBindesc<<iter.containerCode<<" status:"<<iter.status;
            }
        }

    }
    return true;
}

bool threadQuery::UP_cancelTaskSAP(QMap<int, SAPExcelInfo> slecetSAPExcelInfoList)
{

    QMap<QString,shelfBinInfo>shelfBinInfoMap;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    foreach(SAPExcelInfo iter,slecetSAPExcelInfoList.values()){
        sqlQuery.prepare("UPDATE [dbo].[sapExcelinfo] SET [taskStatus]=:taskStatus,"
                         "[taskStatusDesc]=:taskStatusDesc,[taskError]=:taskError,"
                         "[errortextEdit]=:errortextEdit,[finishTimer]=:finishTimer "
                         "WHERE [SAPTaskIndex]=:SAPTaskIndex;");
        sqlQuery.addBindValue(iter.taskStatus);
        sqlQuery.addBindValue(iter.taskStatusDesc);
        sqlQuery.addBindValue(iter.taskError);
        sqlQuery.addBindValue(iter.errortextEdit);
        sqlQuery.addBindValue(QDateTime::currentDateTime());
        sqlQuery.addBindValue(iter.SAPTaskIndex);

        if(sqlQuery.exec()){
            qDebug()<<"UP_cancelTaskSAP S"<<iter.SAPTaskIndex<<iter.taskId<<iter.Priority
                   <<iter.taskStatus<<iter.cancelTask;
        }else {
            qDebug()<<"UP_cancelTaskSAP E"<<iter.SAPTaskIndex<<iter.taskId<<iter.Priority
                   <<iter.taskStatus<<sqlQuery.lastError();
        }
    }
    return true;

}


//**********************************库存管理********************************//

bool threadQuery::setshelfBinInfo_Status(QMap<QString,shelfBinInfo>shelfBinInfoMap,QString type)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    foreach(shelfBinInfo iter,shelfBinInfoMap.values())
    {
        if(type=="Index"){
            //0 空闲  1入库中  2入库完成  3出库中  0出库完成--空闲
            if(iter.status==0 || iter.status==1){
                int SAPTaskIndex=iter.SAPTaskIndex;
                if(iter.status==0){SAPTaskIndex=0;}
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[containerCode]=:containerCode,"
                                 "[SAPTaskIndex]=:SAPTaskIndex,[LabelNo]=:LabelNo "
                                 "WHERE ([SAPTaskIndex]=:SAPTaskIndex);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.containerCode);
                sqlQuery.addBindValue(SAPTaskIndex);
                sqlQuery.addBindValue(iter.LabelNo);
                sqlQuery.addBindValue(iter.SAPTaskIndex);

            }if(iter.status==2 || iter.status==3){
                int SAPTaskIndex=iter.SAPTaskIndex;
                if(iter.status==2){SAPTaskIndex=0;}
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[SAPTaskIndex]=:SAPTaskIndex "
                                 "WHERE ([shelfBindesc]=:shelfBindesc);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.SAPTaskIndex);
                sqlQuery.addBindValue(iter.shelfBindesc);

            }

        }if(type=="Bindesc"){
            if(iter.status==3){
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[SAPTaskIndex]=:SAPTaskIndex "
                                 "WHERE ([shelfBindesc]=:shelfBindesc);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.SAPTaskIndex);
                sqlQuery.addBindValue(iter.shelfBindesc);

            }else{
                sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [status]=:status,[containerCode]=:containerCode,"
                                 "[SAPTaskIndex]=:SAPTaskIndex,[LabelNo]=:LabelNo "
                                 "WHERE ([shelfBindesc]=:shelfBindesc);");
                sqlQuery.addBindValue(iter.status);
                sqlQuery.addBindValue(iter.containerCode);
                sqlQuery.addBindValue(iter.SAPTaskIndex);
                sqlQuery.addBindValue(iter.LabelNo);
                sqlQuery.addBindValue(iter.shelfBindesc);
            }

        }

        if(sqlQuery.exec()){
            qDebug()<<"shelfInfo S"<<iter.podIdDesc<<iter.shelfBindesc<<iter.containerCode<<" status:"<<iter.status;
        }else {
            update= false;
            qDebug()<<"shelfInfo E"<<iter.podIdDesc<<iter.shelfBindesc<<iter.containerCode<<" status:"<<iter.status;
        }
    }

    return update;
}

