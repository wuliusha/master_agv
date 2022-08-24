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
    qRegisterMetaType<WWYLPOST >("WWYLPOST");
    this->setWindowTitle("货位信息看板");
    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);

}

//更新显示此货架上物料信息
void binwidget::UPShelfNuberInfoShow(shelfBinInfo shelfBinInfoI,QString Action, QString UserNuber)
{
    qDebug()<<"更新显示此货架上物料信息";
    currentUserNuber=UserNuber;
    shelfBinInfoItem= shelfBinInfoI;

    ui->Binstatus->setText(QString::number(shelfBinInfoI.status));
    ui->SAPTaskIndex->setText(QString::number(shelfBinInfoI.SAPTaskIndex));
    ui->pcbListdesc->setText(shelfBinInfoI.podIdDesc);
    ui->fromLocationCode->setText(shelfBinInfoI.podIdDesc);

    ui->shelfBindesc->setText(shelfBinInfoI.shelfBindesc);
    ui->shelfBindesc_e->setText(shelfBinInfoI.shelfBindesc);
    ui->containerCode->setText(shelfBinInfoI.containerCode);
    ui->LabelNo->setText(shelfBinInfoI.LabelNo);

    if(shelfBinInfoI.status==0){
        ui->Binstatus_box->setCurrentText("空闲状态");
    }if(shelfBinInfoI.status==1){
        ui->Binstatus_box->setCurrentText("正在入库");
    }if(shelfBinInfoI.status==2){
        ui->Binstatus_box->setCurrentText("入库完成");
    }if(shelfBinInfoI.status==3){
        ui->Binstatus_box->setCurrentText("正在出库");
    }

//    materialshelfBinMap=shelfBinInfoI.materialShelfbinMap;
//    QStringList comBoxlist;
//    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,MaterialTableWidget(materialshelfBinMap),comBoxlist,0);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    if(shelfBinInfoItem.binEnable==1){
        ui->enableButton->setText("使用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE;");
    }else {
        ui->enableButton->setText("禁用");
        Instance::GetInstance()->SetButton_released(ui->enableButton,"background-color: rgb(91, 91, 91);border-radius:15px;color:#FEFEFE;");
    }

    ui->taskType->setCurrentIndex(0);
    if(shelfBinInfoI.status==0){
         ui->taskType->setCurrentText("IN");
    }if(shelfBinInfoI.status==2){
         ui->taskType->setCurrentText("OUT");
    }

    ui->containerCode->setStyleSheet("background-color: rgb(151, 170, 166);color:#434343");
    ui->LabelNo->setStyleSheet("background-color: rgb(151, 170, 166);color:#FEFEFE");
    ui->SAPTaskIndex->setStyleSheet("background-color: rgb(151, 170, 166);color:#FEFEFE");
    ui->Binstatus->setStyleSheet("background-color: rgb(151, 170, 166);color:#FEFEFE");
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
        ++iter;
    }
    return RW_ExcelList;
}

//更新 架位 Bin 的基础信息
bool binwidget::UPShelfInfoChange()
{
    bool boolpodDesc=false;
    shelfBinInfoItem.containerCode=ui->containerCode->text().trimmed();
    shelfBinInfoItem.LabelNo=ui->LabelNo->text().trimmed();
    shelfBinInfoItem.SAPTaskIndex=ui->SAPTaskIndex->text().trimmed().toInt();
    shelfBinInfoItem.status=ui->Binstatus->text().trimmed().toInt();

    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare("UPDATE [dbo].[shelfInfo] SET [containerCode]=:containerCode,[LabelNo]=:LabelNo,[SAPTaskIndex]=:SAPTaskIndex,"
                      "[status]=:status,[binEnable]=:binEnable,[showEnable]=:showEnable WHERE ([shelfBinIndex]=:shelfBinIndex);");
    sqlQuery.addBindValue(shelfBinInfoItem.containerCode);
    sqlQuery.addBindValue(shelfBinInfoItem.LabelNo);
    sqlQuery.addBindValue(shelfBinInfoItem.SAPTaskIndex);
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

WWYLPOST binwidget::getWWYLPOSTI(WWYLPOST WWYLPOST0)
{
    WWYLPOST WWYLPOST1;
    WWYLPOST1.actionId=WWYLPOST0.actionId;
    WWYLPOST1.taskId="taskId"+QDateTime::currentDateTime().toString("mmsszzz"); //任务唯一编码
    WWYLPOST1.taskType=ui->taskType->currentText().trimmed();                   //任务类型(OUT 出库，MOVE 点对点IN 入库)
    WWYLPOST1.boxNo=ui->containerCode_2->text().trimmed();                      //料框编号，非必填（可以输入产品编码获取料框）
    WWYLPOST1.boxNum="1";                                                       //料箱数量(入库时默认是1,出库时>0)

    if(WWYLPOST1.taskType=="OUT"){
        WWYLPOST1.proNo=ui->LabelNo->text().trimmed();
        WWYLPOST1.source=ui->fromLocationCode->text().trimmed();
        WWYLPOST1.destination=ui->toStationCode->text().trimmed();
    }if(WWYLPOST1.taskType=="IN"){
        WWYLPOST1.proNo="LabelNo-IN";
        WWYLPOST1.destination=ui->fromLocationCode->text().trimmed();
    }

    return WWYLPOST1;
}


void binwidget::new_SAPExcelInfo_move()
{
    SAPExcelInfo SAPExcelInfoI;
    SAPExcelInfoI.taskType="MOVE";                       //任务类型
    SAPExcelInfoI.taskId="taskId"+QDateTime::currentDateTime().toString("hhmmsszzz");         //任务编码 唯一性
    SAPExcelInfoI.containerCode=ui->containerCode_2->text().trimmed();
    SAPExcelInfoI.pickDesc_s=ui->pickDesc_s->currentText();

    SAPExcelInfoI.taskTypeDesc="移库";
    SAPExcelInfoI.sourcestation=ui->fromLocationCode->text().trimmed();
    SAPExcelInfoI.destination=ui->toLocationCode->text().trimmed();


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

void binwidget::tableWidget_Show()
{
    //解决显示卡顿问题:  https://blog.csdn.net/u014746838/article/details/102642083
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QStringList comBoxlist;
    QList<RW_Excel> ExcelList=TableWidget();
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    ui->tableWidget->sortItems(0, Qt::AscendingOrder);// 对 n 列排序, 默认升序
}

QList<RW_Excel> binwidget::TableWidget()
{
    QList<RW_Excel> ExcelList;
    QMap<QString, shelfBinInfo>::const_iterator iter= seletshelfBinInfoMap.begin();
    while (iter!=seletshelfBinInfoMap.end()) {
        if(iter!=nullptr){
            int incount=0;
            RW_Excel RW_ExcelItem;
            RW_ExcelItem.ExcelA=QString::number(iter.value().shelfBinIndex);
            RW_ExcelItem.ExcelB=iter.value().podIdDesc;
            RW_ExcelItem.ExcelC=iter.value().shelfBindesc;
            RW_ExcelItem.ExcelD=QString::number(iter.value().status);
            RW_ExcelItem.ExcelE=iter.value().containerCode;
            RW_ExcelItem.ExcelF=QString::number(iter.value().SAPTaskIndex);
            RW_ExcelItem.ExcelG=iter.value().LabelNo;
            if(incount==0){
                incount=1;
                RW_ExcelItem.corlor=0;
                ExcelList.append(RW_ExcelItem);
            }
        }else{
            return ExcelList;
        }
        ++iter;
    }
    return ExcelList;
}


void binwidget::ON_binwidgetTimer()
{
    if(ServerInitItem.UserInfoList.isEmpty()){
        /************** 基础信息赋值 *******************/
        allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
        ServerInitItem=ALLServerInitItem.ServerInitItem;
    }
}

//修改当前信息
void binwidget::on_AlterButton_clicked()
{
    bool UPShelfbool=queryServer::getInstance()->SetMessagebox("是否修改当前信息？");
    if(UPShelfbool){
        UPShelfbool=UPShelfInfoChange();//更新 架位 Bin 的基础信息
    }
}

void binwidget::on_AgvExecute_clicked()
{
    QString taskType=ui->taskType->currentText();
    if(taskType=="MOVE"){
        new_SAPExcelInfo_move();                          //创建移库任务
    }else {
        WWYLPOSTI.actionId="WS01";
        WWYLPOSTI=getWWYLPOSTI(WWYLPOSTI);
        emit sig_taskCodes_WW(WWYLPOSTI.taskId,WWYLPOSTI,currentUserNuber,2011);
    }
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

void binwidget::on_taskType_currentTextChanged(const QString &arg1)
{

    ui->containerCode_2->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
    ui->fromLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toLocationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->toStationCode->setStyleSheet("background-color: rgb(111, 109, 133);color:#FEFEFE");
    ui->shelfBindesc_e->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");
    ui->containerCode_3->setStyleSheet("background-color: rgb(255, 255, 245);color:#434343");

    ui->containerCode_2->setText("A000000000");
    if(arg1=="OUT"){
        if(shelfBinInfoItem.containerCode!="" && shelfBinInfoItem.status==2){
            ui->toStationCode->setText("3FA01");
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
    if(ui->checkBox_Edite->isChecked()){
        QString containerCode=ui->containerCode->text().trimmed();
        QString shelfBindesc=ui->shelfBindesc->text().trimmed();
        if(containerCode.size()==10 && shelfBindesc!=""){
            emit sig_containerCode_clear(shelfBindesc,containerCode,"0");    //清空库位
        }else{
            queryServer::getInstance()->SetMessagebox("关键项信息错误");
        }
    }else{
        queryServer::getInstance()->SetMessagebox("请点击选择按钮");
    }

}


void binwidget::on_clear_Button_2_clicked()
{
    if(ui->checkBox_Edite->isChecked()){
        QString containerCode=ui->containerCode_3->text().trimmed();
        QString shelfBindesc=ui->shelfBindesc_e->text().trimmed();
        if(containerCode.size()==10 && shelfBindesc!=""){
            emit sig_containerCode_clear(shelfBindesc,containerCode,"1");    //清空库位
        }else{
            queryServer::getInstance()->SetMessagebox("关键项信息错误");
        }
    }else{
        queryServer::getInstance()->SetMessagebox("请点击选择按钮");
    }
}


void binwidget::on_CancelButton_clicked()
{
    ui->containerCode_2->setText("A000000000");
    ui->containerCode_3->setText("A000000000");
}


void binwidget::on_queryButton_clicked()
{
    if(!ui->queryLabelNo->text().isEmpty()){
        seletshelfBinInfoMap= ESS_Single::getInstance()->getshelfBinInfoMap("LabelNo",ui->queryLabelNo->text().trimmed(),"");
        tableWidget_Show();
        ui->queryLabelNo->setText("");
    }
}

void binwidget::on_Binstatus_box_currentTextChanged(const QString &arg1)
{
    if(arg1=="空闲状态"){
        ui->Binstatus->setText("0");
    }if(arg1=="正在入库"){
        ui->Binstatus->setText("1");
    }if(arg1=="入库完成"){
        ui->Binstatus->setText("2");
    }if(arg1=="正在出库"){
        ui->Binstatus->setText("3");
    }
}
