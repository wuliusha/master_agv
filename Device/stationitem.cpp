#include "stationitem.h"
#include "ui_stationitem.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

stationItem::stationItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stationItem)
{
    ui->setupUi(this);
    qRegisterMetaType<QMap<QString,deviceI>>("QMap<QString,deviceI>");

    stationItemInit();     //接驳台站点初始化

    stationTimer = new QTimer(this);
    connect(stationTimer,&QTimer::timeout,this,&stationItem::ON_stationTimer);
    stationTimer->start(2000);

}

stationItem::~stationItem()
{
    delete ui;
}

void stationItem::stationItemInit()
{

    Udp_DeviceI=new Udp_Device;
    Udp_DeviceI->setListen(9003);
    threadUdpItem=new QThread();
    Udp_DeviceI->moveToThread(threadUdpItem);
    threadUdpItem->start();
    connect(Udp_DeviceI,&Udp_Device::sigDeviceStatuschage,this,&stationItem::ON_stationItemStatus);

    TcpServerI=new TcpServer;
    TcpServerI->listen(QHostAddress::Any,9002);
    threadTcpServertem=new QThread();
    TcpServerI->moveToThread(threadTcpServertem);
    threadTcpServertem->start();
    connect(TcpServerI,&TcpServer::sigDeviceStatuschage,this,&stationItem::ON_stationItemStatus);

    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",25,25);
    connect(ui->tableWidget,&QTableWidget::cellClicked,this,&stationItem::SlotsetCurrentItem);

    stationSqlInit("Init");                 //接驳台站点数据库初始化
}

void stationItem::stationSqlInit(QString type)
{
    stationInfoMap.clear();
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select * from deviceI where  enable =:enable;");
    sqlQuery.addBindValue(1);
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            deviceI deviceItem;
            deviceItem.deviceId=sqlQuery.value("deviceId").toInt();                 //设备Id
            deviceItem.deviceIP=sqlQuery.value("deviceIP").toString();              //设备IP
            deviceItem.deviceDesc=sqlQuery.value("deviceDesc").toString();          //设备名称
            deviceItem.deviceType=sqlQuery.value("deviceType").toString();          //设备类型
            deviceItem.enable=sqlQuery.value("enable").toInt();                     //使能

            /******************* 接驳台类型 **************/
            deviceItem.StationType=sqlQuery.value("StationType").toString();        //站点类型
            deviceItem.stationDesc=sqlQuery.value("stationDesc").toString();         //站点名称
            deviceItem.Currentpoint=sqlQuery.value("Currentpoint").toInt();          //当前所在二维码
            deviceItem.waitDesc=sqlQuery.value("waitDesc").toString();
            deviceItem.waitPoint=sqlQuery.value("waitPoint").toInt();                //待机点二维码

            deviceItem.SAPTaskIndex=sqlQuery.value("SAPTaskIndex").toInt();          //任务索引 唯一值
            deviceItem.taskStatus=sqlQuery.value("taskStatus").toInt();              //任务状态
            deviceItem.taskStatusDesc=sqlQuery.value("taskStatusDesc").toString();   //任务状态注释
            deviceItem.agvNum=sqlQuery.value("agvNum").toInt();                      //小车编号

            if(type=="Init"){
                if(!stationInfoMap.contains(deviceItem.deviceDesc) && deviceItem.deviceDesc!=""){
                    deviceIP_desc.insert(deviceItem.deviceIP,deviceItem.deviceDesc);
                    stationInfoMap.insert(deviceItem.deviceDesc,deviceItem);
                    if(deviceItem.enable==1){
                        //fc 00 13 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 5a
                        QByteArray queryArray=array_Single::GetInstance()->device_query(deviceItem.deviceType);
                        /*************** UDP ********************/
                        Udp_DeviceI->setDeviceInit(deviceItem.deviceIP,queryArray);

                        /*************** TCP ********************/
                        deviceServer deviceServerI;
                        deviceServerI.deviceIP=deviceItem.deviceIP;
                        deviceServerI.queryArray=queryArray;
                        TcpServerI->setdeviceServerInfo(deviceServerI);
                    }
                }
            }else{
                if(deviceItem.deviceDesc!=""){
                    deviceIP_desc.insert(deviceItem.deviceIP,deviceItem.deviceDesc);
                    stationInfoMap.insert(deviceItem.deviceDesc,deviceItem);
                    qDebug()<<" type:"<<type<<deviceItem.deviceDesc;
                }
            }

        }
    }

    TableWidget_show();//tableWidget 更新显示
}

void stationItem::ON_stationTimer()
{
    TableWidgetcount++;
    if(TableWidgetbool){
        TableWidgetbool=false;
        if(!ui->checkBox_Edite->isChecked() && TableWidgetcount%2==1){
            if(currentStation.deviceIP==""){
                TableWidget_show();//tableWidget 更新显示
            }if( TableWidgetcount%10==1){
                UP_DeviceStatus_Timer(stationInfoMap);    //实时更新接驳台 任务状态
            }
        }else{
            ESS_Single::getInstance()->setStationInfoMap(stationInfoMap);
        }
        TableWidgetbool=true;
    }
}

void stationItem::SlotsetCurrentItem(int row, int column)
{
    deviceI deviceItem;
    currentStation=deviceItem;
    ui->label_Info->setText("");
    QString deviceIP=ui->tableWidget->item(row,1)->text().trimmed();
    QMap<QString, deviceI>::iterator iter= stationInfoMap.begin();
    while (iter!=stationInfoMap.end()){
        if(iter.value().deviceIP==deviceIP){
            if(iter.value().checked==0){
                iter.value().checked=1;
                currentStation=iter.value();
            }else {
                iter.value().checked=0;
            }
        }else{
            iter.value().checked=0;
        }
        ++iter;
    }

    ui->label_Info->setText(currentStation.deviceDesc);
    if(!ui->checkBox_Edite->isChecked()){
        TableWidget_show();//tableWidget 更新显示
    }

}

void stationItem::ON_stationItemStatus(QString DeviceIP, QByteArray ActionArray)
{
    if(!stationbool){return;}
    stationbool=false;
    if(stationInfoMap.contains(deviceIP_desc.value(DeviceIP))){
        deviceI deviceItem=stationInfoMap.find(deviceIP_desc.value(DeviceIP)).value();
        deviceItem.onLine=1;
        deviceItem.onLinecount=0;
        if(deviceItem.deviceType=="station"){
            controlbox controlboxI;//=array_Single::GetInstance()->setSystemchage(DeviceIP,ActionArray);
            deviceItem.status=0;
            deviceItem.statusDesc="无料框";
            if(ActionArray.at(8)==1){
                controlboxI.X10=1;
            }if(ActionArray.at(8)==2){
                controlboxI.X11=1;
            }if(ActionArray.at(8)==3){
                controlboxI.X10=1;
                controlboxI.X11=1;
                deviceItem.status=1;
                deviceItem.statusDesc="有料框";
            }

            controlboxI.boxID=deviceItem.deviceId;
            deviceItem.controlboxItem=controlboxI;
            controlboxI.datetimer=QDateTime::currentDateTime();
            QStringList LiftStatus;
            if(currentStation.deviceId==deviceItem.deviceId){
                LiftStatus<<" ActionArray:"<<QString::number(ActionArray.at(8))<<" 光电感应1-->X10:"<<QString::number(controlboxI.X10)<<"  光电感应2-->X11:"<<QString::number(controlboxI.X11)
                                     <<"  更新时间:"<<QDateTime::currentDateTime().toString("hh:mm:ss")
                                    <<" size:"<<QString::number(stationInfoMap.size());
                 ui->tabletTextEdit->setText(LiftStatus.join(" ")+"\n 升降机数据包:"+ActionArray.toHex()+" size():"+QString::number(ActionArray.size()));
            }
        }

        stationInfoMap.find(deviceItem.deviceDesc).value()=deviceItem;

    }
    stationbool=true;
}

void stationItem::ON_DeviceStatusAction(QString DeviceIP, QString deviceType, QString orderType, int Action)
{
    if(deviceType=="station"){
        TcpServerI->setdeviceServerAction(DeviceIP, array_Single::GetInstance()->deviceaction_s(Action));
    }
    qDebug()<<"接驳台动作指令------>DeviceIP:"<<DeviceIP<<" deviceType:"<<deviceType<<" orderType:"<<orderType<<" Action:"<<Action;
}

void stationItem::ON_DeviceStatus(QString deviceDesc, SAPExcelInfo SAPExcelInfoI)
{
    if(!stationbool){return;}
    if(stationInfoMap.contains(deviceDesc)){
        int taskStatus=taskStatus_delete;          //任务状态
        deviceI deviceItem=stationInfoMap.find(deviceDesc).value();
        if(deviceItem.StationType=="IN" ){
            taskStatus=taskTake_ess;
        }if(deviceItem.StationType=="OUT"){
            taskStatus=taskFnish_ess;
        }

        if(deviceItem.SAPTaskIndex==0 && SAPExcelInfoI.taskStatus<taskStatus){
            deviceItem.SAPTaskIndex=SAPExcelInfoI.SAPTaskIndex;             //任务索引 唯一值
            deviceItem.taskStatus=SAPExcelInfoI.taskStatus;                 //任务状态
            deviceItem.taskStatusDesc=SAPExcelInfoI.taskStatusDesc;         //任务状态注释
        }if(deviceItem.SAPTaskIndex==SAPExcelInfoI.SAPTaskIndex){
            if(SAPExcelInfoI.taskStatus<taskStatus){
                deviceItem.taskStatus=SAPExcelInfoI.taskStatus;             //任务状态
                deviceItem.taskStatusDesc=SAPExcelInfoI.taskStatusDesc;     //任务状态注释
            }else{
                deviceItem.SAPTaskIndex=0;                                  //任务索引 唯一值
                deviceItem.taskStatus=0;                                    //任务状态
                deviceItem.taskStatusDesc="";                               //任务状态注释
            }
        }
        stationInfoMap.find(deviceItem.deviceDesc).value()=deviceItem;
        //qDebug()<<" setTaskStatus:"<<deviceItem.deviceId<<deviceItem.onLine<<deviceItem.status<<deviceItem.taskStatus<<deviceItem.taskStatusDesc;
    }
}

void stationItem::TableWidget_show()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    QList<RW_Excel> ExcelList=TableWidget();
    QStringList comBoxlist;
    table_single::GetInstance()->UP_TableWidget(ui->tableWidget,ExcelList,comBoxlist,0);
    if(ExcelList.isEmpty()){
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
        return;
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//列宽根据表格大小自适应
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableWidget->sortItems(1, Qt::AscendingOrder);// 对 n 列排序, 默认升序

}

QList<RW_Excel> stationItem::TableWidget()
{
    QList<RW_Excel> ExcelList;
    foreach(deviceI iter,stationInfoMap.values()){
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(iter.deviceId); //设备Id
        RW_ExcelItem.ExcelB=iter.deviceIP;                  //设备IP
        RW_ExcelItem.ExcelC=iter.deviceDesc;                //设备名称
        RW_ExcelItem.ExcelD=iter.deviceType;                //空满
        RW_ExcelItem.ExcelE=QString::number(iter.enable);
        if(iter.onLine==0){
          RW_ExcelItem.ExcelF="离线";
          RW_ExcelItem.corlor=4;
        }else{
          RW_ExcelItem.ExcelF="在线";
          if(iter.status==freeStatus){
             RW_ExcelItem.corlor=0;
          }else {
             RW_ExcelItem.corlor=2;
          }
        }
        RW_ExcelItem.ExcelG=iter.statusDesc;                    //是否有料框
        RW_ExcelItem.ExcelH=iter.StationType;                   //站点类型
        RW_ExcelItem.ExcelI=iter.stationDesc;                   //站点名称
        RW_ExcelItem.ExcelJ=QString::number(iter.Currentpoint); //当前所在二维码
        RW_ExcelItem.ExcelK=iter.waitDesc;                      //站点名称
        RW_ExcelItem.ExcelL=QString::number(iter.waitPoint);    //等待点二维码
        RW_ExcelItem.ExcelM=QString::number(iter.SAPTaskIndex); //任务索引 唯一值
        RW_ExcelItem.ExcelN=iter.taskStatusDesc+"_"+QString::number(iter.taskStatus);//任务状态注释
        RW_ExcelItem.checked=iter.checked;

        if(incount==0){
            incount=1;
            iter.onLinecount++;
            if(iter.onLinecount>15){
                iter.onLine=0;
                iter.onLinecount=0;
            }
            ExcelList.append(RW_ExcelItem);
        }

    }
    return ExcelList;
}


void stationItem::on_load_clicked()
{
    if(!ui->label_Info->text().isEmpty()){
        TcpServerI->setdeviceServerAction(currentStation.deviceIP, array_Single::GetInstance()->deviceaction_s(1));
    }
}

void stationItem::on_unload_clicked()
{
    if(!ui->label_Info->text().isEmpty()){
        TcpServerI->setdeviceServerAction(currentStation.deviceIP, array_Single::GetInstance()->deviceaction_s(2));
    }
}

void stationItem::on_reset_clicked()
{
    if(!ui->label_Info->text().isEmpty()){
        //TcpServerI->setdeviceServerAction(currentStation.deviceIP,array_Single::GetInstance()->deviceaction_plc(0));
    }
}

void stationItem::on_clearButton_clicked()
{
    if(!currentStation.deviceDesc.isEmpty()){
         if(ui->checkBox_Edite->isChecked()){
            UP_DeviceStatus_clear(currentStation);
            stationSqlInit("clear");                       //接驳台站点数据库初始化
         }
    }
}

void stationItem::on_pushButton_clicked()
{
    QMap<int,deviceI>StationInfoMap_;
     if(ui->checkBox_Edite->isChecked()){
         for (int i=0;i<stationInfoMap.size();i++) {
             deviceI deviceItem;
             deviceItem.deviceId=ui->tableWidget->item(i,0)->text().trimmed().toInt();    //设备Id
             deviceItem.deviceIP=ui->tableWidget->item(i,1)->text().trimmed();            //设备IP
             deviceItem.deviceDesc=ui->tableWidget->item(i,2)->text().trimmed();          //设备名称
             deviceItem.deviceType=ui->tableWidget->item(i,3)->text().trimmed();          //设备类型
             deviceItem.enable=ui->tableWidget->item(i,4)->text().trimmed().toInt();      //使能

             deviceItem.StationType=ui->tableWidget->item(i,7)->text().trimmed();
             deviceItem.stationDesc=ui->tableWidget->item(i,8)->text().trimmed();
             deviceItem.Currentpoint=ui->tableWidget->item(i,9)->text().trimmed().toInt();
             deviceItem.waitDesc=ui->tableWidget->item(i,10)->text().trimmed();
             deviceItem.waitPoint=ui->tableWidget->item(i,11)->text().trimmed().toInt();
             StationInfoMap_.insert(deviceItem.deviceId,deviceItem);
         }

         if(!StationInfoMap_.isEmpty()){
             UP_DeviceStatus(StationInfoMap_);    //更新数据库
             stationSqlInit("push");                 //接驳台站点数据库初始化
         }
     }
}

void stationItem::UP_DeviceStatus(QMap<int, deviceI> StationInfoMap_)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<int, deviceI>::const_iterator iter= StationInfoMap_.begin();
    while (iter!=StationInfoMap_.end()) {
         if(iter!=nullptr){
             sqlQuery.prepare("UPDATE [dbo].[deviceI] SET [deviceIP]=:deviceIP,[deviceDesc]=:deviceDesc,"
                              "[deviceType]=:deviceType,[enable]=:enable,[StationType]=:StationType,"
                              "[stationDesc]=:stationDesc,[Currentpoint]=:Currentpoint,"
                              "[waitDesc]=:waitDesc,[waitPoint]=:waitPoint "
                              "WHERE ([deviceId]=:deviceId);");

             sqlQuery.addBindValue(iter.value().deviceIP);
             sqlQuery.addBindValue(iter.value().deviceDesc);
             sqlQuery.addBindValue(iter.value().deviceType);
             sqlQuery.addBindValue(iter.value().enable);

             sqlQuery.addBindValue(iter.value().StationType);
             sqlQuery.addBindValue(iter.value().stationDesc);
             sqlQuery.addBindValue(iter.value().Currentpoint);
             sqlQuery.addBindValue(iter.value().waitDesc);
             sqlQuery.addBindValue(iter.value().waitPoint);

             sqlQuery.addBindValue(iter.value().deviceId);

             if(sqlQuery.exec()){
                 qDebug()<<"deviceI S-->StationId"<<iter.value().deviceId<<iter.value().deviceDesc;
             }
         }else{

         }
         ++iter;
    }

}

void stationItem::UP_DeviceStatus_Timer(QMap<QString, deviceI> StationInfoMap_)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    QMap<QString, deviceI>::const_iterator iter= StationInfoMap_.begin();
    while (iter!=StationInfoMap_.end()){
         if(iter!=nullptr){
             sqlQuery.prepare("UPDATE [dbo].[deviceI] SET [SAPTaskIndex]=:SAPTaskIndex,[taskStatus]=:taskStatus,"
                              "[taskStatusDesc]=:taskStatusDesc,[agvNum]=:agvNum "
                              "WHERE ([deviceId]=:deviceId);");
             sqlQuery.addBindValue(iter.value().SAPTaskIndex);
             sqlQuery.addBindValue(iter.value().taskStatus);
             sqlQuery.addBindValue(iter.value().taskStatusDesc);
             sqlQuery.addBindValue(iter.value().agvNum);
             sqlQuery.addBindValue(iter.value().deviceId);
             if(sqlQuery.exec()){
                 //qDebug()<<"UP_DeviceStatus_ S-->StationId"<<iter.value().deviceId<<iter.value().deviceDesc;
             }
         }else{
             return;
         }
         ++iter;
    }

}

void stationItem::UP_DeviceStatus_clear(deviceI deviceItem)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.prepare("UPDATE [dbo].[deviceI] SET [SAPTaskIndex]=:SAPTaskIndex,[taskStatus]=:taskStatus,"
                     "[taskStatusDesc]=:taskStatusDesc,[agvNum]=:agvNum "
                     "WHERE ([deviceId]=:deviceId);");
    sqlQuery.addBindValue(0);
    sqlQuery.addBindValue(0);
    sqlQuery.addBindValue("");
    sqlQuery.addBindValue(0);
    sqlQuery.addBindValue(deviceItem.deviceId);
    if(sqlQuery.exec()){
        qDebug()<<"DeviceStatus_clear S-->StationId"<<deviceItem.deviceId<<deviceItem.deviceDesc;
    }

}

