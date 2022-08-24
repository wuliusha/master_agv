#include "devicemanage.h"
#include "ui_devicemanage.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)


DeviceManage::DeviceManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceManage)
{
    ui->setupUi(this);

    qRegisterMetaType<LiftTask >("LiftTask");
    qRegisterMetaType<LiftCode >("LiftCode");

    DeviceManageInit();

    DeviceTimer = new QTimer(this);
    connect(DeviceTimer,&QTimer::timeout,this,&DeviceManage::ON_DeviceTimer);
    DeviceTimer->start(1200);
}

DeviceManage::~DeviceManage()
{
    delete ui;
}

void DeviceManage::ON_DeviceTimer()
{
    if(ServerInitItem.UserInfoList.isEmpty()){
        /************** 基础信息赋值 *******************/
        allServerInit ALLServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
        ServerInitItem=ALLServerInitItem.ServerInitItem;
        CurrentServerItem=ALLServerInitItem.CurrentServerItem;
    }

    if(TcpClientI->deviceQueryArray.isEmpty()){
        TcpClientI->deviceQueryArray=array_Single::GetInstance()->Lift_query("query"); //客户端模式
    }

    LiftCodeMapconut++;
    if(LiftCodeMapconut%20==0){
        if(!LiftCodeMap.isEmpty()){
            setLiftCodeMap_Status(LiftCodeMap);                    //更新接升降机状态信息
        }
    }
    if(LiftCodeMapconut>10000){LiftCodeMapconut=0;}

}

void DeviceManage::SlotsetCurrentItem(int row, int column)
{
    LiftCode LiftCodeItem;
    slectLiftCode=LiftCodeItem;
    QString codeDesc=ui->tableWidget->item(row,1)->text().trimmed();
    QMap<QString, LiftCode>::iterator iter= LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()){
        if(iter.value().codeDesc==codeDesc){
            if(iter.value().checked==0){
                iter.value().checked=1;
                slectLiftCode=iter.value();
            }else {
                iter.value().checked=0;
            }
        }else{
            iter.value().checked=0;
        }
        ++iter;
    }
    TableWidget_show();
}

void DeviceManage::DeviceManageInit()
{
    stationItemI=new stationItem;
    ui->tabWidget->insertTab(1,stationItemI, "接驳台管理");
    ui->tabWidget->setCurrentIndex(1);

    TcpClientI=new TcpClient;
    TcpClientI->Serverport=10000;
    TcpClientI->TcpServerIP="172.16.21.221";
    TcpClientI->connectHost(TcpClientI->TcpServerIP,TcpClientI->Serverport);

    threadTcpClientItem=new QThread();
    TcpClientI->moveToThread(threadTcpClientItem);
    threadTcpClientItem->start();
    connect(TcpClientI,&TcpClient::sigLiftStatuschage,this,&DeviceManage::ON_LiftStatuschage);

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&DeviceManage::SlotsetCurrentItem);

    LiftTaskI.LiftIP=TcpClientI->TcpServerIP;
    ui->LiftIP_Box->addItem(LiftTaskI.LiftIP);
    Actionbtns<<ui->LiftD100<<ui->LiftD101<<ui->LiftD102<<ui->LiftD103<<ui->LiftD104<<ui->LiftD105;

    LiftCodedesc.insert("IN_0","有料框");
    LiftCodedesc.insert("IN_1","无料框");
    LiftCodedesc.insert("IN_2","运行中");
    LiftCodedesc.insert("IN_3","运行中");
    LiftCodedesc.insert("OUT_0","无料框");
    LiftCodedesc.insert("OUT_1","有料框");
    LiftCodedesc.insert("OUT_2","运行中");
    LiftCodedesc.insert("OUT_3","运行中");

}

void DeviceManage::TableWidget_show()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget(LiftCodeMap);
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);

}

QList<RW_Excel> DeviceManage::TableWidget(QMap<QString, LiftCode> LiftCodeMap)
{
    QList<RW_Excel> ExcelList;
    foreach(LiftCode iter,LiftCodeMap.values()){
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.codeDesc;                               //升降机接驳台命名 2F-IN
        RW_ExcelItem.ExcelC=iter.codeType;                               //(IN- D100 D103 D105:1可放料,2-3去X楼)  ( OUT- D101 D102 D104: 1可取料,2取料完成)
        RW_ExcelItem.ExcelD=QString::number(iter.Liftstatus);            //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
        RW_ExcelItem.ExcelE=QString::number(iter.status);                //任务锁定状态:0空闲  1 锁定  2到达 0空闲
        RW_ExcelItem.ExcelF=QString::number(iter.SAPTaskIndex);          //任务索引 唯一值
        RW_ExcelItem.ExcelG=iter.containerCode;                          //容器编码 (即胶箱编码) ->唯一

        RW_ExcelItem.checked=iter.checked;
        if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;
            ExcelList.append(RW_ExcelItem);
        }
    }
    return ExcelList;
}

void DeviceManage::setActionbtns(QString deviceType, int Action,QString Type,QString deviceDesc)
{
    for(auto item : Actionbtns)
    {
        if(item->objectName()==deviceType){
            if(Action==0){
                item->setStyleSheet("color: white;background-color: #00a6ac;");
            }if(Action==1){
                item->setStyleSheet("color: white;background-color: rgb(255, 170, 127);");
            }if(Action>1){
                item->setStyleSheet("color: white;background-color: rgb(85,255,127);");
            }
            item->setText(deviceDesc+"\n"+LiftCodedesc.value(Type+QString::number(Action)));
        }
    }
}

bool DeviceManage::LiftCodeStatus_clear(LiftCode LiftCodeItem)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare("UPDATE [dbo].[LiftTask] SET [Liftstatus]=:Liftstatus,"
                     "[status]=:status,[SAPTaskIndex]=:SAPTaskIndex,"
                     "[containerCode]=:containerCode "
                     "WHERE ([codeDesc]=:codeDesc);");

    sqlQuery.addBindValue(0);             //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
    sqlQuery.addBindValue(0);                 //任务锁定状态:0空闲  1 锁定  2到达 0空闲
    sqlQuery.addBindValue(0);           //任务索引 唯一值
    sqlQuery.addBindValue("");          //容器编码 (即胶箱编码) ->唯一
    sqlQuery.addBindValue(LiftCodeItem.codeDesc);               //升降机接驳台命名
    if(sqlQuery.exec()){
        qDebug()<<"set LiftCodeStatus_clear S"<<LiftCodeItem.codeDesc;
        return true;
    }else {
        qDebug()<<"set codeDesc E"<<LiftCodeItem.codeDesc;
        //qDebug()<<"set codeDesc E"<<iter.value().codeDesc<<iter.value().Liftstatus<<iter.value().status<<iter.value().SAPTaskIndex;
    }
    return false;
}

//更新接升降机状态信息
bool DeviceManage::setLiftCodeMap_Status(QMap<QString, LiftCode> LiftCodeMap)
{
    bool update=true;
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    foreach(LiftCode iter,LiftCodeMap.values()){
        sqlQuery.prepare("UPDATE [dbo].[LiftTask] SET [Liftstatus]=:Liftstatus,"
                         "[status]=:status,[SAPTaskIndex]=:SAPTaskIndex,"
                         "[containerCode]=:containerCode "
                         "WHERE ([codeDesc]=:codeDesc);");
        sqlQuery.addBindValue(iter.Liftstatus);             //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
        sqlQuery.addBindValue(iter.status);                 //任务锁定状态:0空闲  1 锁定  2到达 0空闲
        sqlQuery.addBindValue(iter.SAPTaskIndex);           //任务索引 唯一值
        sqlQuery.addBindValue(iter.containerCode);          //容器编码 (即胶箱编码) ->唯一
        sqlQuery.addBindValue(iter.codeDesc);               //升降机接驳台命名
        if(sqlQuery.exec()){
            //qDebug()<<"set codeDesc S"<<iter.value().codeDesc<<iter.value().Liftstatus<<iter.value().status<<iter.value().SAPTaskIndex;
        }
    }
    return update;
}

//设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
void DeviceManage::ON_DeviceStatusAction(QString DeviceIP, QString deviceType, QString orderType, int Action)
{
    qDebug()<<"设备动作指令 ----->DeviceIP:"<<DeviceIP<<" deviceType:"<<deviceType<<" orderType:"<<orderType<<" Action:"<<Action;
}

void DeviceManage::ON_setLiftactionArray(LiftTask LiftTaskI, int startFloor, int destFloor)
{
    QString action= ui->taskTypeBox_Lift->currentText().trimmed();
    QByteArray actionArray=array_Single::GetInstance()->getLiftactionArray(LiftTaskI,startFloor,destFloor);
    TcpClientI->setTcpServer_deviceAction(TcpClientI->TcpServerIP,actionArray);     //设置客户端基础信息
    qDebug()<<"ON_setLiftactionArray -->TcpServerIP:"<<TcpClientI->TcpServerIP<<" startFloor:"<<startFloor<<" destFloor:"<<destFloor;
}

//更新各电梯状态信息
void DeviceManage::ON_LiftStatuschage(QString DeviceIP, QByteArray ActionArray)
{
    //01 23 45 67 89 10 12 14 16 18 20 22 24 26 28 30 32 34
    //81 00 03 00 02 00 03 00 06 00 07 00 08 00
    //81 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00
    //81 00 00 00 00 00 00 00 00 00 00 00 01 00

    //( 2F-进料_D100: 0 - 出料_D101: 0 ) — ( 3F-出料_D102: 0 - 进料_D103: 0 ) — ( 4F-出料_D104: 0 - 进料_D105: 1 ) --> ( error1: 0  - error2: 0 )
    //( 2F-进料_D100: 0 - 出料_D101: 0 ) — ( 3F-出料_D102: 0 - 进料_D103: 0 ) — ( 4F-出料_D104: 0 - 进料_D105: 1 ) --> ( error1: 0  - error2: 0 )

    quint16 Statushex=array_Single::GetInstance()->getSystemchage(ActionArray,0,2);
    if(LiftTaskI.LiftIP==DeviceIP && Statushex==81){

        LiftTaskI.LiftD100=array_Single::GetInstance()->getSystemchage(ActionArray,4,2);          //2F-->IN
        LiftTaskI.LiftD101=array_Single::GetInstance()->getSystemchage(ActionArray,8,2);          //2F-->OUT

        LiftTaskI.LiftD102=array_Single::GetInstance()->getSystemchage(ActionArray,12,2);         //3F-->OUT
        LiftTaskI.LiftD103=array_Single::GetInstance()->getSystemchage(ActionArray,16,2);         //3F-->IN

        LiftTaskI.LiftD104=array_Single::GetInstance()->getSystemchage(ActionArray,20,2);         //4F-->OUT
        LiftTaskI.LiftD105=array_Single::GetInstance()->getSystemchage(ActionArray,24,2);         //4F-->IN

        setActionbtns("LiftD100", LiftTaskI.LiftD100,"IN_","2F进");
        setActionbtns("LiftD101", LiftTaskI.LiftD101,"OUT_","2F出");
        setActionbtns("LiftD102", LiftTaskI.LiftD102,"OUT_","3F出");
        setActionbtns("LiftD103", LiftTaskI.LiftD103,"IN_","3F进");
        setActionbtns("LiftD104", LiftTaskI.LiftD104,"OUT_","4F出");
        setActionbtns("LiftD105", LiftTaskI.LiftD105,"IN_","4F进");

        int error1=array_Single::GetInstance()->getSystemchage(ActionArray,28,2);                 //异常信息
        int error2=array_Single::GetInstance()->getSystemchage(ActionArray,32,2);                 //异常信息

//        qDebug()<<"ON_LiftStatuschage--->LiftIP:"<<LiftTaskI.LiftIP<<" LiftD100:"<<LiftTaskI.LiftD100
//                  <<" LiftD101:"<<LiftTaskI.LiftD101<<" LiftD102:"<<LiftTaskI.LiftD102
//                    <<" LiftD103:"<<LiftTaskI.LiftD103<<" LiftD104:"<<LiftTaskI.LiftD104
//                      <<" LiftD105:"<<LiftTaskI.LiftD105;

        QStringList LiftStatus;
        LiftStatus<<"( 2F-进料_D100:"<<QString::number(LiftTaskI.LiftD100)<<"- 出料_D101:"<<QString::number(LiftTaskI.LiftD101)<<") —"
                 <<"( 3F-出料_D102:"<<QString::number(LiftTaskI.LiftD102)<<"- 进料_D103:"<<QString::number(LiftTaskI.LiftD103)<<") —"
                 <<"( 4F-出料_D104:"<<QString::number(LiftTaskI.LiftD104)<<"- 进料_D105:"<<QString::number(LiftTaskI.LiftD105)<<") -->"
                 <<"( error1:"<<QString::number(error1)<<" - error2:"<<QString::number(error2)<<") -->更新时间:"
                <<QDateTime::currentDateTime().toString("hh:mm:ss");

        ui->tabletTextEdit->setText(LiftStatus.join(" ")+"\n  升降机数据包:"+ActionArray.toHex()+" size():"+QString::number(ActionArray.size()));
        emit sig_LiftTaskStatus(LiftTaskI);
    }

}

void DeviceManage::ON_LiftCodeMap(QMap<QString, LiftCode> LiftCodeMap_)
{
    if(slectLiftCode.codeDesc==""){
        LiftCodeMap=LiftCodeMap_;
        TableWidget_show();
    }
}

//plc  电梯动作指令
void DeviceManage::on_Sure_Button_Lift_clicked()
{
   QString action= ui->taskTypeBox_Lift->currentText().trimmed();
   QByteArray actionArray=array_Single::GetInstance()->getLiftactionArray(LiftTaskI,action.left(1).toInt(), action.mid(5,1).toInt());
   TcpClientI->setTcpServer_deviceAction(TcpClientI->TcpServerIP,actionArray);
}

void DeviceManage::on_clearButton_clicked()
{
    if(ui->checkBox_Edite->isChecked()){
        if(slectLiftCode.codeDesc!=""){
            if(LiftCodeStatus_clear(slectLiftCode)){
                emit sig_LiftCodeStatus_clear(slectLiftCode);
            }
        }
    }
}
