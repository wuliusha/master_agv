#include "binwidget.h"
#include "ui_binwidget.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

binwidget::binwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::binwidget)
{
    ui->setupUi(this);
    binwidgetIint();

    binwidgetTimer = new QTimer(this);
    connect(binwidgetTimer,&QTimer::timeout,this,&binwidget::ON_binwidgetTimer);
    binwidgetTimer->start(5000);

}

binwidget::~binwidget()
{
    delete ui;
}

void binwidget::binwidgetIint()
{
    this->setWindowTitle("货位信息看板");
    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    Actionbtns<<ui->AlterButton<<ui->CancelButton<<ui->NextButton<<ui->LastButton
             <<ui->AgvExecute<<ui->CancelButton_3<<ui->clear_Button;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&binwidget::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&binwidget::ON_Released);
    }

    ui->LastButton->setVisible(false);
    ui->NextButton->setVisible(false);
    ui->enableButton->setVisible(false);
    ui->enableButton_show->setVisible(false);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(1)->layout()->setContentsMargins(0,0,0,0);

    IconHelper::Instance()->setIcon(ui->NextButton, 0xf101, 25);
    IconHelper::Instance()->setIcon(ui->LastButton, 0xf100, 25);
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&binwidget::SlotsetCurrentItem);

}

//更新显示此货架上物料信息
void binwidget::UPShelfNuberInfoShow(shelfBinInfo shelfBinInfoI,QString Action, QString UserNuber)
{
    currentUserNuber=UserNuber;
    shelfBinInfoItem= shelfBinInfoI;

    ui->Binstatus->setText(QString::number(shelfBinInfoI.status));
    ui->pcbListdesc->setText(shelfBinInfoI.podIdDesc);
    ui->fromLocationCode->setText(shelfBinInfoI.podIdDesc);

    ui->shelfBindesc->setText(shelfBinInfoI.shelfBindesc);
    ui->containerCode->setText(shelfBinInfoI.containerCode);
    ui->materialNumber->setText(shelfBinInfoI.materialShelfbinI.materialNumber);

    materialshelfBinMap=shelfBinInfoI.materialShelfbinMap;
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,MaterialTableWidget(materialshelfBinMap),comBoxlist,0);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    if(shelfBinInfoItem.binEnable==1){
        ui->enableButton->setText("使用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE;");
    }else {
        ui->enableButton->setText("禁用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(91, 91, 91);border-radius:15px;color:#FEFEFE;");
    }

    if(shelfBinInfoItem.showEnable==1){
        ui->enableButton_show->setText("显示");
        Instance::GetInstance()->SetButton_released(ui->enableButton_show,"background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE;");
    }else {
        ui->enableButton_show->setText("隐藏");
        Instance::GetInstance()->SetButton_released(ui->enableButton_show,"background-color: rgb(91, 91, 91);border-radius:15px;color:#FEFEFE;");
    }

    ui->taskType->setCurrentIndex(0);
    if(shelfBinInfoI.status==0){
         ui->taskType->setCurrentText("IN");
    }if(shelfBinInfoI.status==2){
          ui->taskType->setCurrentText("OUT");
    }

}

QList<RW_Excel> binwidget::MaterialTableWidget(QMap<QString, materialShelfbin> materialMap)
{
    RW_Excel RW_ExcelItem;QList<RW_Excel> RW_ExcelList;
    QMap<QString, materialShelfbin>::iterator iter=materialMap.begin();
    while (iter != materialMap.end()) {
        RW_ExcelItem.ExcelA=QString::number(RW_ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.value().containerCode;
        RW_ExcelItem.ExcelC=iter.value().materialNumber;
        RW_ExcelItem.ExcelD=QString::number(iter.value().realqty);
        RW_ExcelItem.ExcelE=iter.value().pcbListdesc;
        RW_ExcelItem.ExcelF=iter.value().creatTimer.toString("yyyy-MM-dd hh:mm");
        RW_ExcelList.append(RW_ExcelItem);
        iter++;
    }
    return RW_ExcelList;
}

//更新 架位 Bin 的基础信息
bool binwidget::UPShelfInfoChange()
{
    bool boolpodDesc=false;
    shelfBinInfoItem.status=ui->Binstatus->text().trimmed().toInt();
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare("UPDATE TOP(1) [dbo].[shelfInfo] SET [status]=:status,"
                      "[binEnable]=:binEnable,[showEnable]=:showEnable WHERE ([shelfBinIndex]=:shelfBinIndex);");
    sqlQuery.addBindValue(shelfBinInfoItem.status);
    sqlQuery.addBindValue(shelfBinInfoItem.binEnable);
    sqlQuery.addBindValue(shelfBinInfoItem.showEnable);
    sqlQuery.addBindValue(shelfBinInfoItem.shelfBinIndex);

    if(sqlQuery.exec()){
        boolpodDesc=true;
        qDebug()<<"UPShelfInfoChange S:"<<shelfBinInfoItem.shelfBinIndex<<shelfBinInfoItem.binEnable<<boolpodDesc;
    }else {
        qDebug()<<"UPShelfInfoChange E:"<<shelfBinInfoItem.shelfBinIndex<<shelfBinInfoItem.binEnable<<boolpodDesc;
    }
    qDebug()<<"UPShelfInfoChange :"<<boolpodDesc<<shelfBinInfoItem.shelfBinIndex<<shelfBinInfoItem.binEnable;
    return boolpodDesc;
}


void binwidget::new_SAPExcelInfo_move()
{

    QString taskType=ui->taskType->currentText();

    SAPExcelInfo SAPExcelInfoI;
    SAPExcelInfoI.taskType=taskType;                       //任务类型
    SAPExcelInfoI.taskId="taskId"+QDateTime::currentDateTime().toString("hhmmsszzz");         //任务编码 唯一性
    SAPExcelInfoI.containerCode=ui->containerCode_2->text().trimmed();
    SAPExcelInfoI.pickDesc_s=ui->pickDesc_s->currentText();

    if(taskType=="OUT"){
        SAPExcelInfoI.taskTypeDesc="出库";
        SAPExcelInfoI.sourcestation=ui->fromLocationCode->text().trimmed();
        SAPExcelInfoI.destination=ui->toStationCode->text().trimmed();
    }if(taskType=="MOVE"){
        SAPExcelInfoI.taskTypeDesc="移库";
        SAPExcelInfoI.sourcestation=ui->fromLocationCode->text().trimmed();
        SAPExcelInfoI.destination=ui->toLocationCode->text().trimmed();
    }if(taskType=="IN"){
        SAPExcelInfoI.taskTypeDesc="入库";
        SAPExcelInfoI.sourcestation="STATION-01";
        SAPExcelInfoI.destination=ui->fromLocationCode->text().trimmed();

    }

    if(SAPExcelInfoI.containerCode.size()!=10 || SAPExcelInfoI.containerCode=="A000000000"){
        queryServer::getInstance()->SetMessagebox("料框编码格式错误，无法提交移库任务");return;
    }if(SAPExcelInfoI.sourcestation==""){
        queryServer::getInstance()->SetMessagebox("起始库位格式错误，无法提交移库任务");return;
    }if(SAPExcelInfoI.destination==""){
        queryServer::getInstance()->SetMessagebox("目标库位格式错误，无法提交移库任务");return;
    }

    SAPExcelInfoI.taskStatus=0;                            //任务状态
    QString taskType_=SAPExcelInfoI.taskType+"_"+QString::number(SAPExcelInfoI.taskStatus);
    SAPExcelInfoI.taskStatusDesc=ServerInitItem.taskStatusMap.value(taskType_);
    SAPExcelInfoI.creatTimer=QDateTime::currentDateTime();

    if(SAPExcelInfoI.taskId!=""){
        emit sig_SAPExcelInfo_new(SAPExcelInfoI);
    }

}

void binwidget::ON_binwidgetTimer()
{
    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
}

void binwidget::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    if(Button->objectName()=="NextButton" || Button->objectName()=="LastButton"){
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;");
    }else{
        Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                                   border-radius:15px;border-style: outset");
    }

}

void binwidget::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();
    if(Button->objectName()=="AgvExecute" || Button->objectName()=="CancelButton_3"){
        Instance::GetInstance()->SetButton_released(Button,"background-color: rgb(80, 138, 136);color:#ffffff;color: white;  border: 2px groove gray;\
                                                    border-radius:15px;");
    }if(Button->objectName()=="NextButton" || Button->objectName()=="LastButton"){
        Instance::GetInstance()->SetButton_released(Button,"background-color: rgb(81,81,81);color:#ffffff;");
    }else{
        Instance::GetInstance()->SetButton_released(Button,"color:#ffffff;color: white;  border: 2px groove gray;\
                                                    border-radius:15px;border-style: outset");
    }

}

void binwidget::SlotsetCurrentItem(int row, int column)
{

}

//返回 物料件号信息 显示 界面
void binwidget::on_NextButton_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(1);
}
//跳到 物料件号信息 更改 界面
void binwidget::on_LastButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

//修改当前信息
void binwidget::on_AlterButton_clicked()
{
    bool UPShelfbool=queryServer::getInstance()->SetMessagebox("是否修改当前信息？");
    if(UPShelfbool){
        UPShelfbool=UPShelfInfoChange();//更新 架位 Bin 的基础信息
    }

    if(!UPShelfbool){
        queryServer::getInstance()->SetMessagebox("当前信息修改失败"+shelfBinInfoItem.shelfBindesc);
    }else {

    }

}

void binwidget::on_AgvExecute_clicked()
{
    new_SAPExcelInfo_move();                          //创建移库任务
    ui->taskType->setCurrentIndex(0);
}


void binwidget::on_enableButton_clicked()
{
    if(shelfBinInfoItem.binEnable==0){
        shelfBinInfoItem.binEnable=1;
        ui->enableButton->setText("使用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE");
    }else {
        shelfBinInfoItem.binEnable=0;
        ui->enableButton->setText("禁用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(91, 91, 91);border-radius:15px;color:#FEFEFE");
    }
}

void binwidget::on_enableButton_show_clicked()
{
    if(shelfBinInfoItem.showEnable==0){
        shelfBinInfoItem.showEnable=1;
        ui->enableButton_show->setText("显示");
        Instance::GetInstance()->SetButton_released(ui->enableButton_show,"background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE");
    }else {
        shelfBinInfoItem.showEnable=0;
        ui->enableButton_show->setText("隐藏");
        Instance::GetInstance()->SetButton_released(ui->enableButton_show,"background-color: rgb(91, 91, 91);border-radius:15px;color:#FEFEFE");
    }
}

void binwidget::on_taskType_currentTextChanged(const QString &arg1)
{

    ui->containerCode_2->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
    ui->fromLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toStationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");

    ui->containerCode_2->setText("A000000000");
    if(arg1=="OUT"){
        if(shelfBinInfoItem.containerCode!="" && shelfBinInfoItem.status==2){
            ui->toStationCode->setText("3F-01");
            ui->containerCode_2->setText(shelfBinInfoItem.containerCode);
            ui->containerCode->setText(shelfBinInfoItem.containerCode);
            ui->fromLocationCode->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
            ui->toStationCode->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
        }else {
            queryServer::getInstance()->SetMessagebox("当前库位无法出库");ui->taskType->setCurrentIndex(0);return;
        }
    }

    if(arg1=="MOVE"){
        if(shelfBinInfoItem.containerCode!=""){
            ui->containerCode->setText(shelfBinInfoItem.containerCode);
            ui->fromLocationCode->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
            ui->toLocationCode->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
        }else {
            queryServer::getInstance()->SetMessagebox("当前库位无法执行移库");ui->taskType->setCurrentIndex(0);return;
        }
    }

    if(arg1=="IN"){
        if(shelfBinInfoItem.containerCode=="" && shelfBinInfoItem.status==0){
            ui->fromLocationCode->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
        }else {
            queryServer::getInstance()->SetMessagebox("当前库位无法入库");ui->taskType->setCurrentIndex(0);return;
        }
    }

}

void binwidget::on_clear_Button_clicked()
{
    QString containerCode=ui->containerCode->text().trimmed();
    QString shelfBindesc=ui->shelfBindesc->text().trimmed();
    if(containerCode.size()==10 && shelfBindesc!=""){
        emit sig_containerCode_clear(shelfBindesc,containerCode);    //清空库位
    }

}
