#include "network_widget.h"
#include "ui_network_widget.h"

Network_Widget::Network_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Network_Widget)
{
    ui->setupUi(this);
    Network_WidgetInit();

    NetworkTimer = new QTimer(this);
    connect(NetworkTimer,&QTimer::timeout,this,&Network_Widget::Network_WidgetTimer);
    NetworkTimer->start(600);

}

Network_Widget::~Network_Widget()
{
    delete ui;
}

void Network_Widget::Network_WidgetInit()
{
    Actionbtns<<ui->Post_Button<<ui->Clear_Button<<ui->stop_Button;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&Network_Widget::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&Network_Widget::ON_Released);
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(1)->layout()->setContentsMargins(0,0,0,0);

    WWYLPOST_show();       //QSS 动态显示
    ui->comboBox_Type->setCurrentText("ESS-P接口");

}

void Network_Widget::ESS_RequestI_show()
{
    ui->robotCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->taskCodes->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->taskGroupCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->groupPriority->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->taskCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->taskPriority->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->taskTemplateCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->containerCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toStationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->fromLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->positionCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");

    if(ESS_RequestI.actionId=="action0"  || ESS_RequestI.actionId=="action10"){
        ui->robotCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    } if(ESS_RequestI.actionId=="action1"){
        ui->taskCodes->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    } if(ESS_RequestI.actionId=="action2"){
        ui->taskGroupCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->groupPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

        ui->taskCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

        ui->containerCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->fromLocationCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->toStationCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

    } if(ESS_RequestI.actionId=="action3"){
        ui->taskGroupCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->groupPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

        ui->taskTemplateCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

        ui->containerCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->fromLocationCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->toLocationCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    } if(ESS_RequestI.actionId=="action4"){

        ui->taskGroupCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->groupPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskTemplateCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->taskPriority->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->toLocationCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

        ui->containerCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");

    } if(ESS_RequestI.actionId=="action5"){
        ui->taskCodes->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    } if(ESS_RequestI.actionId=="action6"){
        ui->containerCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->positionCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    } if(ESS_RequestI.actionId=="action7"){
        ui->containerCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->positionCode->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    }

}

ESS_Request Network_Widget::getESS_RequestI(ESS_Request ESS_Request0)
{
    ESS_Request ESS_Request01;
    ESS_Request01.pathId=ESS_Request0.pathId;
    ESS_Request01.actionId=ESS_Request0.actionId;

    ESS_Request01.robotCode=ui->robotCode->text().trimmed();
    ESS_Request01.robotCodes.append(ui->robotCode->text().trimmed());    //机器人查询接口
    ESS_Request01.taskCodes.append(ui->taskCodes->text().trimmed());     //任务查询接口

     /********** 任务指令 ************/
    ESS_Request01.taskGroupCode=ui->taskGroupCode->text().trimmed();     //任务组号
    ESS_Request01.groupPriority=ui->groupPriority->text().trimmed();     //组优先级

    /********** tasks  任务列表************/
    ESS_Request01.taskCode=ui->taskCode->text().trimmed();               //任务号
    ESS_Request01.taskPriority=ui->taskPriority->text().trimmed();       //任务优先级
    ESS_Request01.taskTemplateCode=ui->taskTemplateCode->text().trimmed(); //(移库,回库)任务模板   ()任务模板

    /********** tasks  任务列表 (taskDescribe  任务描述) ************/
    ESS_Request01.containerCode=ui->containerCode->text().trimmed();     //货箱编码
    ESS_Request01.toStationCode=ui->toStationCode->text().trimmed();     //(出库)目标工作站编码
    ESS_Request01.toLocationCode=ui->toLocationCode->text().trimmed();   //(移库 回库)目标库位编码
    ESS_Request01.fromLocationCode=ui->fromLocationCode->text().trimmed();//(出库)起始工作位  (移库)起始库位编码
    qDebug()<<"ui->positionCode->text().trimmed():"<<ui->positionCode->text().trimmed();
    ESS_Request01.positionCode=ServerInitItem.StationCodeMap.value(ui->positionCode->text().trimmed());//容器入场 / 容器离场 (入库时对接 输送线对接码头   出库时对应放箱码头)

    return ESS_Request01;
}

void Network_Widget::WWYLPOST_show()
{
    ui->boxNoEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->destinationEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");

    ui->proNoEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->pcbNumEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->resultStatusEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->sourceEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->AGV_binEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->ToEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->prinTypeEdit->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");

    if(WWYLPOSTI.actionId=="WS01"){
        ui->boxNoEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->proNoEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->pcbNumEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->destinationEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        if(ui->operateEdit->currentText().trimmed()=="OUT"){
            ui->sourceEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        }if(ui->operateEdit->currentText().trimmed()=="MOVE"){
            ui->sourceEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        }
    } if(WWYLPOSTI.actionId=="WS02"){
        ui->boxNoEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->destinationEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->resultStatusEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
        ui->sourceEdit->setStyleSheet("background-color: rgb(255, 255, 255);color:#1a1a1a");
    }

}

WWYLPOST Network_Widget::getWWYLPOSTI(WWYLPOST WWYLPOST0)
{
    WWYLPOST WWYLPOST1;
    WWYLPOST1.taskId="taskId"+QDateTime::currentDateTime().toString("mmsszzz");
    WWYLPOST1.actionId=WWYLPOST0.actionId;
    WWYLPOST1.operate=ui->operateEdit->currentText().trimmed();     //操作,IN-入库，OUT-出库
    WWYLPOST1.boxNo=ui->boxNoEdit->text().trimmed();                //箱号
    WWYLPOST1.pcbList<<"pcb1"<<"pcb2"<<"pcb3";                      //pcb集合
    WWYLPOST1.source=ui->sourceEdit->text().trimmed();      //来源  入库为NULL，出库为库位
    WWYLPOST1.destination=ui->destinationEdit->text().trimmed();//目的地。入库为仓库，出库为线体

    /*******下达订单任务************/
    if(WWYLPOST1.actionId=="WS01"){
        WWYLPOST1.proNo=ui->proNoEdit->text().trimmed();   //产品编码
        WWYLPOST1.pcbNum=ui->pcbNumEdit->text().trimmed();  //pcb数量
    }

    /*******返回任务状态************/
    if(WWYLPOST0.actionId=="WS02"){
        WWYLPOST1.resultStatus=ui->resultStatusEdit->text().trimmed();//执行结果,1-开始执行，2-执行中，3执行失败，4-执行成功
    }

    //qDebug()<<" getWWYLPOSTI:"<<WWYLPOST1.actionId;

    return WWYLPOST1;
}

void Network_Widget::TextEdit_Request_show(CurrentSend CurrentSendI)
{
    if(CurrentSendI.UrlPath!="" ){
        QString timer=QDateTime::currentDateTime().toString("yyyy:MM:dd:hh:mm:ss");
        ui->TextEdit_Request->append("UrlPath:"+timer+"\n"+CurrentSendI.UrlPath+"\n");
        if(!CurrentSendI.postJson.isEmpty()){
            ui->TextEdit_Request->append("postJson: "+timer+"\n"+QString(QJsonDocument(CurrentSendI.postJson).toJson()));
        }
        if(!CurrentSendI.postdoc.isNull()){
            ui->TextEdit_Request->append("postdoc: "+timer+"\n"+CurrentSendI.postdoc.toString().toUtf8().constData());
        }
        if(!CurrentSendI.ReplyData.isEmpty()){
            ui->TextEdit_Reply->append("Reply:"+timer+"\n");
            ui->TextEdit_Reply->append(CurrentSendI.ReplyData+"\n");
            QJsonDocument JsonAnalyse; QJsonParseError JsonError;
            JsonAnalyse = QJsonDocument::fromJson(CurrentSendI.ReplyData,&JsonError);
            QJsonObject ReplyJson = JsonAnalyse.object();//取得最外层这个大对象
            ui->TextEdit_Reply->append(QString(QJsonDocument(ReplyJson).toJson()));
        }

        ui->TextEdit_Error->append("Error:"+timer+"\n");
        ui->TextEdit_Error->append(CurrentSendI.Errorinfo);
    }

}

// QString >> QJson
QJsonObject Network_Widget::getJsonObjectFromString(const QString jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if(jsonDocument.isNull() ){
        qDebug()<< "===> please check the string "<<jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

// QJson >> QString
QString Network_Widget::getStringFromJsonObject(const QJsonObject &jsonObject)
{
    return QString(QJsonDocument(jsonObject).toJson());
}

void Network_Widget::on_Post_Button_clicked()
{
    if(ui->URL0_lineEdit->text()==""){return;}

    qDebug()<<ui->stackedWidget->currentIndex()<<ESS_RequestI.actionId<<ESS_RequestI.pathId
           <<ESS_RequestI.robotCodes.size()<<ESS_RequestI.taskCodes.size();

    QString iKey=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
    if(ui->stackedWidget->currentIndex()==0){//微网对接
         WWYLPOSTI=getWWYLPOSTI(WWYLPOSTI);
        if(ui->comboBox->currentText()=="WS01"){//暂时特殊处理
            sapMsgInterface::getInstance()->taskCodes_WW(iKey,WWYLPOSTI,currentUserNuber,2011);
        }if(ui->comboBox->currentText()=="WS02"){
            sapMsgInterface::getInstance()->taskCodes_WW(iKey,WWYLPOSTI,currentUserNuber,2012);
        }

    }else{//ESS_P 对接   0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
        ESS_RequestI=getESS_RequestI(ESS_RequestI);
        if(ESS_RequestI.pathId!=0){
            if(ESS_RequestI.actionId=="action0"){//机器人状态查询
                sapMsgInterface::getInstance()->robotCodes_query(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action1"){//任务状态查询
                sapMsgInterface::getInstance()->taskCodes_query(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action2"){//下达出库任务
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action3"){//下达移库任务
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action4"){//下达入库(回库)任务
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action5"){//任务取消
                sapMsgInterface::getInstance()->taskCodes_cancel(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action6"){//容器入场
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action7"){//容器离场
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action8"){//容器移除
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action9"){//容器创建
                sapMsgInterface::getInstance()->taskCodes_actionId(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action10"){//机器人查询
                sapMsgInterface::getInstance()->robotCodes_query_Get(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }if(ESS_RequestI.actionId=="action11"){//状态事件回调
                sapMsgInterface::getInstance()->taskCodes_request(iKey,ESS_RequestI,currentUserNuber,ESS_RequestI.pathId);
            }

        }else{

        }
    }


}

void Network_Widget::on_Clear_Button_clicked()
{
    ui->TextEdit_Error->clear();
    ui->TextEdit_Reply->clear();   ui->TextEdit_Request->clear();
}

void Network_Widget::on_comboBox_currentTextChanged(const QString &arg1)
{
    WWYLPOSTI.actionId=arg1;
    if(!ServerInitItem.sapPathMap.isEmpty()){
        QMap<int ,sapPath >::iterator iter=ServerInitItem.sapPathMap.begin();
        while (iter !=ServerInitItem.sapPathMap.end()) {//
            if(iter.value().PathName==ui->comboBox->currentText()){
                 WWYLPOSTI.actionId=iter.value().PathName;
                 ui->URL0_lineEdit->setText(iter.value().Path);
                 ui->lineEdit->setText(QString::number(iter.value().Id));
            }
            iter++;
        }
    }

    if(ui->comboBox->currentText()=="MES接口"){
        // QString >> QJson
        QJsonObject ReplyJson=getJsonObjectFromString(ui->TextEdit_Request->toPlainText());
        ui->TextEdit_Error->append("QString -------> QJson:\n"+QString(QJsonDocument(ReplyJson).toJson()));

        // QJson >> QString
        ui->TextEdit_Error->append("QJson -------> QString:\n"+getStringFromJsonObject(ReplyJson));

    }

    WWYLPOST_show();
}

void Network_Widget::on_comboBox_Type_currentTextChanged(const QString &arg1)
{
    if(arg1=="微网优联"){
        ui->comboBox->setCurrentText("WS01");
        ui->stackedWidget->setCurrentIndex(0);
    }else {
        ui->comboBox_2->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(1);
    }
}

//0查询状态  1任务查询  2出库  3移库  4回库  5任务取消
void Network_Widget::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ESS_RequestI.actionId=arg1;
    if(!ServerInitItem.sapPathMap.isEmpty()){
        QMap<int ,sapPath >::iterator iter=ServerInitItem.sapPathMap.begin();
        while (iter !=ServerInitItem.sapPathMap.end()) {//
            if(iter.value().PathName==arg1 && iter.value().Id !=0){
                ESS_RequestI.pathId=iter.value().Id;
                ESS_RequestI.actionId=iter.value().Type;
                ui->URL0_lineEdit->setText(iter.value().Path);
                ui->lineEdit->setText(QString::number(ESS_RequestI.pathId));

                ui->taskGroupCode->setText(iter.value().para1);
                ui->taskTemplateCode->setText(iter.value().para2);

                if(iter.value().funcation=="query"){
                   ui->stackedWidget_2->setCurrentIndex(0);
                }else if(iter.value().funcation=="action"){
                   ui->stackedWidget_2->setCurrentIndex(1);
                }
                qDebug()<<iter.value().Id<<iter.value().PathName<<iter.value().funcation;
            }

            iter++;
        }
    }
    ESS_RequestI_show();
}

void Network_Widget::Network_WidgetTimer()
{
    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
    CurrentSend CurrentSendI_;
    CurrentSend CurrentSend1=sapMsgInterface::getInstance()->getCurrentSend();//post
    if(CurrentSend1.UrlPath!="" || !CurrentSend1.ReplyData.isEmpty()){
        if(!qdebug_logstop && (CurrentSend1.UrlPath==UrlPath || CurrentSend1.UrlPath==UrlPath1)){

        }else{
            TextEdit_Request_show(CurrentSend1);
            sapMsgInterface::getInstance()->setCurrentSend(CurrentSendI_);
        }
    }

    CurrentSend CurrentSend2=sapMsgInterface::getInstance()->getCurrentSend_();//回调
    if(CurrentSend2.UrlPath!="" && !CurrentSend2.ReplyData.isEmpty()){
        if(!qdebug_logstop && (CurrentSend2.UrlPath==UrlPath || CurrentSend2.UrlPath==UrlPath1)){

        }else{
            TextEdit_Request_show(CurrentSend2);
            sapMsgInterface::getInstance()->setCurrentSend_(CurrentSendI_);
        }
    }

    if(ui->comboBox_2->currentText()=="状态查询接口" && ui->stackedWidget->currentIndex()==1){
        on_Post_Button_clicked();//机器人状态查询  定时压力测试
    }

}

void Network_Widget::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void Network_Widget::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_released(Button,"color:#ffffff;color: white;  border: 2px groove gray;\
                                                border-radius:15px;border-style: outset");
}


void Network_Widget::on_operateEdit_currentTextChanged(const QString &arg1)
{
    if(ui->operateEdit->currentText()=="IN"){
        ui->destinationEdit->setText("A01-01-001");
        ui->sourceEdit->setText("");
    } if(ui->operateEdit->currentText()=="OUT"){
        ui->destinationEdit->setText("3F-01");
        ui->sourceEdit->setText("");
    } if(ui->operateEdit->currentText()=="MOVE"){
        ui->destinationEdit->setText("A01-01-001");
        ui->sourceEdit->setText("A01-01-002");
    }
}

void Network_Widget::on_stop_Button_released()
{
    if(qdebug_logstop){
        qdebug_logstop=false;
        ui->stop_Button->setText("暂停");
    }else{
        qdebug_logstop=true;
        ui->stop_Button->setText("启动");
    }
}
