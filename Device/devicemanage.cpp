#include "devicemanage.h"
#include "ui_devicemanage.h"

DeviceManage::DeviceManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceManage)
{
    ui->setupUi(this);

    qRegisterMetaType<LiftTask >("LiftTask");

    DeviceManageInit();

    DeviceTimer = new QTimer(this);
    connect(DeviceTimer,&QTimer::timeout,this,&DeviceManage::ON_DeviceTimer);
    DeviceTimer->start(700);
}

DeviceManage::~DeviceManage()
{
    delete ui;
}

void DeviceManage::ON_DeviceTimer()
{
    ServerInitItem=queryServer::getInstance()->getCurrentServerInitItem();
    CurrentServerItem=ESS_Single::GetInstance()->getCurrentServerItem();
    if(!CurrentServerItem.StationInfoMap.isEmpty() && DeviceItemMap_S.isEmpty()){
        newDeviceItem_S();//创建 新的设备 Item  接驳台
    }if(!ServerInitItem.doorSubTaskMap.isEmpty() && DeviceItemMap_D.isEmpty()){
        newDeviceItem_D();//创建 新的设备 Item  自动门
    }

    TableWidget_show();//显示当前电梯各个接驳台任务状态线信息

    if(!DeviceItemMap_S.isEmpty()){
        controlbox controlboxI;
        QMap<QString,DeviceItem*>::iterator iter0= DeviceItemMap_S.begin();//自动门控制
        while (iter0!=DeviceItemMap_S.end()) {
            if(iter0.key()!=nullptr){
                iter0.value()->currentDeviceI.onLinecount++;
                if(iter0.value()->currentDeviceI.onLinecount>12){
                    iter0.value()->currentDeviceI.status=-1;
                    iter0.value()->currentDeviceI.onLine=0;
                    iter0.value()->currentDeviceI.onLinecount=0;
                    //更新各设备状态信息  控制盒-自动门类型
                    emit sigDeviceStatus_station(iter0.value()->currentDeviceI.deviceIP,iter0.value()->currentDeviceI.onLine,iter0.value()->currentDeviceI.status,controlboxI);
                }
            }else {
                return;
            }
            iter0++;
        }
    }
}

void DeviceManage::DeviceManageInit()
{

    Udp_DeviceI=new Udp_Device;//port=9003
    threadUdpItem=new QThread();
    Udp_DeviceI->moveToThread(threadUdpItem);
    threadUdpItem->start();
    connect(Udp_DeviceI,&Udp_Device::sigDeviceStatuschage,this,&DeviceManage::ON_DeviceStatuschage);

    TcpServerI=new TcpServer;
    TcpServerI->listen(QHostAddress::Any,9002);
    threadTcpServertem=new QThread();
    TcpServerI->moveToThread(threadTcpServertem);
    threadTcpServertem->start();

    connect(TcpServerI,&TcpServer::sigDeviceStatuschage,this,&DeviceManage::ON_DeviceStatuschage);


    TcpClientI=new TcpClient;
    TcpClientI->Serverport=10000;
    TcpClientI->TcpServerIP="172.16.21.221";
    TcpClientI->connectHost(TcpClientI->TcpServerIP,TcpClientI->Serverport);
    threadTcpClientItem=new QThread();
    TcpClientI->moveToThread(threadTcpClientItem);
    threadTcpClientItem->start();

    setLiftTaskInfo();       //创建 电梯 Item
    table_single::GetInstance()->TableWidgetInit(ui->tableWidget,12,"QHeaderView::section{background-color:rgb(193,205,205);font:12pt '宋体';color: black;};",35,35);

    connect(TcpServerI,&TcpServer::sigLiftStatuschage,this,&DeviceManage::ON_LiftStatuschage);
    connect(TcpClientI,&TcpClient::sigLiftStatuschage,this,&DeviceManage::ON_LiftStatuschage);
    Actionbtns<<ui->Sure_Button_Lift<<ui->Button_S1<<ui->Button_S2<<ui->Button_S3
             <<ui->Button_D1<<ui->Button_D2<<ui->Button_D3<<ui->Button_D4<<ui->Button_D5;

    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&DeviceManage::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&DeviceManage::ON_Released);
        connect(Actionbtns[i],&QPushButton::clicked,this,&DeviceManage::ON_ClickProcess);
    }

    ui->stackedWidget_2->setCurrentIndex(3);
    ui->stackedWidget_2->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(1)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(2)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget_2->widget(3)->layout()->setContentsMargins(0,0,0,0);

    LiftTaskI.LiftIP=TcpClientI->TcpServerIP;
    ui->LiftIP_Box->addItem(LiftTaskI.LiftIP);

}

void DeviceManage::newDeviceItem_S()
{

    QMap<QString ,StationInfo >::iterator iter=CurrentServerItem.StationInfoMap.begin();
    while (iter!=CurrentServerItem.StationInfoMap.end()) {
        if(!DeviceItemMap_S.contains(iter.value().StationIP)){
            DeviceItem *DeviceItemI=new DeviceItem();

            DeviceItemI->deviceType="station";
            DeviceItemI->page=iter.value().page;
            DeviceItemI->deviceId=iter.value().StationId;
            DeviceItemI->deviceIP=iter.value().StationIP;
            DeviceItemI->deviceDesc=iter.value().StationDesc;

            DeviceItemI->currentDeviceI.deviceId=DeviceItemI->deviceId;          //设备Id
            DeviceItemI->currentDeviceI.deviceIP=DeviceItemI->deviceIP;          //设备IP
            DeviceItemI->currentDeviceI.deviceDesc=DeviceItemI->deviceDesc;      //设备名称
            DeviceItemI->currentDeviceI.deviceType=DeviceItemI->deviceType;      //设备类型  自动门 door  站点接驳台 Station
            DeviceItemI->currentDeviceI.currentEnable=iter.value().enable;       //使能

            /*************** UDP ********************/
            Udp_DeviceI->setDeviceInit(iter.value().StationIP,DeviceItemI->deviceType);
            connect(DeviceItemI,&DeviceItem::sigDeviceStatusAction,Udp_DeviceI,&Udp_Device::ON_DeviceStatusAction);

            /*************** TCP ********************/
//            TcpServer_device TcpServer_deviceI;
//            TcpServer_deviceI.deviceIP=DeviceItemI->deviceIP;
//            TcpServer_deviceI.deviceQueryArray=array_Single::GetInstance()->device_query(DeviceItemI->deviceType);
//            TcpServerI->setTcpServer_deviceInfo(TcpServer_deviceI);
//            connect(DeviceItemI,&DeviceItem::sigDeviceStatusAction,TcpServerI,&TcpServer::ON_DeviceStatusAction);

            DeviceItemMap_S.insert(iter.value().StationIP,DeviceItemI);

        }
        iter++;
    }
    setLayout_show(ui->LayoutWidget_s,ui->LayoutWidget_ss,"station",DeviceItemMap_S);       //设置初始化布局

}

void DeviceManage::newDeviceItem_D()
{
    QMap<QString ,doorSubTask >::iterator iter=ServerInitItem.doorSubTaskMap.begin();
    while (iter!=ServerInitItem.doorSubTaskMap.end()) {
        if(!DeviceItemMap_D.contains(iter.value().doorIP)){
            DeviceItem *DeviceItemI=new DeviceItem();
            DeviceItemI->deviceType="door";
            DeviceItemI->page=iter.value().page;
            DeviceItemI->deviceId=iter.value().doorId;
            DeviceItemI->deviceIP=iter.value().doorIP;
            DeviceItemI->deviceDesc=iter.value().doorDesc;

            DeviceItemI->currentDeviceI.deviceId=DeviceItemI->deviceId;          //设备Id
            DeviceItemI->currentDeviceI.deviceIP=DeviceItemI->deviceIP;          //设备IP
            DeviceItemI->currentDeviceI.deviceDesc=DeviceItemI->deviceDesc;      //设备名称
            DeviceItemI->currentDeviceI.deviceType=DeviceItemI->deviceType;      //设备类型  自动门 door  站点接驳台 Station
            DeviceItemI->currentDeviceI.currentEnable=iter.value().enable;       //使能

            /*************** UDP ********************/
            Udp_DeviceI->setDeviceInit(DeviceItemI->deviceIP,DeviceItemI->deviceType);
            connect(DeviceItemI,&DeviceItem::sigDeviceStatusAction,Udp_DeviceI,&Udp_Device::ON_DeviceStatusAction);

            /*************** TCP ********************/
            TcpServer_device TcpServer_deviceI;
            TcpServer_deviceI.deviceIP=DeviceItemI->deviceIP;
            TcpServer_deviceI.deviceQueryArray=array_Single::GetInstance()->device_query(DeviceItemI->deviceType);
            TcpServerI->setTcpServer_deviceInfo(TcpServer_deviceI);
            connect(DeviceItemI,&DeviceItem::sigDeviceStatusAction,TcpServerI,&TcpServer::ON_DeviceStatusAction);

            DeviceItemI->setStyleSheet("border-radius:15px;background-color: rgb(0, 135, 146);");
            DeviceItemMap_D.insert(iter.value().doorIP,DeviceItemI);
        }
        iter++;
    }

    setLayout_show(ui->LayoutWidget_d,ui->LayoutWidget_dd,"door",DeviceItemMap_D);//设置初始化布局
}

void DeviceManage::setLiftTaskInfo()
{
    //服务器模式
//    TcpServer_device TcpServer_deviceI;
//    TcpServer_deviceI.deviceIP=LiftTaskI.LiftIP;
//    TcpServer_deviceI.deviceQueryArray=array_Single::GetInstance()->getLiftAnalysisArray(LiftTaskI,"query",0,0);
//    TcpServerI->setTcpServer_deviceInfo(TcpServer_deviceI);          //设置客户端基础信息

    //客户端模式
    TcpClientI->deviceQueryArray=array_Single::GetInstance()->Lift_query("query");

}

void DeviceManage::setLayout_show(QWidget *LayoutWidget,QWidget *LayoutWidget_,QString deviceType, QMap<QString, DeviceItem *> DeviceItemMap)
{

    QHBoxLayout *DeviceHBoxLayout = new QHBoxLayout;//水平
    QHBoxLayout *DeviceHBoxLayout2 = new QHBoxLayout;//水平
    for(int i=1;i<=50;i++){
        QMap<QString,DeviceItem*>::const_iterator iter=DeviceItemMap.begin();
        while (iter !=DeviceItemMap.end()){
            if(iter.value()->deviceId==i){
                int deviceId=iter.value()->deviceId%10;
                if(deviceType=="station"){deviceId=iter.value()->deviceDesc.right(2).toInt()%10;}
                if(deviceId>0 && deviceId<=5){
                    DeviceHBoxLayout->addWidget(iter.value());
                    DeviceHBoxLayout->setSpacing(50);
                    DeviceHBoxLayout->setStretchFactor(iter.value(),1);
                }else{
                    DeviceHBoxLayout2->addWidget(iter.value());
                    DeviceHBoxLayout2->setSpacing(50);
                    DeviceHBoxLayout2->setStretchFactor(iter.value(),1);
                }
                if(iter.value()->page==1){
                    iter.value()->setVisible(true);
                }else{
                    iter.value()->setVisible(false);
                }
                //qDebug()<<iter.value()->deviceIP<<iter.value()->deviceId<<deviceId;
            }
            iter++;
        }
    }

    DeviceHBoxLayout->addStretch();  // 添加伸缩  居左显示
    LayoutWidget->setLayout(DeviceHBoxLayout);
    LayoutWidget->layout()->setContentsMargins(0,10,0,0);

    DeviceHBoxLayout2->addStretch();  // 添加伸缩  居左显示
    LayoutWidget_->setLayout(DeviceHBoxLayout2);
    LayoutWidget_->layout()->setContentsMargins(0,10,0,0);

}

void DeviceManage::UPLayout_show(QMap<QString, DeviceItem *> DeviceItemMap, int page)
{
    bool showbool=false;
    QMap<QString,DeviceItem*>::const_iterator iter=DeviceItemMap.begin();
    while (iter !=DeviceItemMap.end()){
        if(iter.value()->page == page){
            showbool=true;
            iter.value()->setVisible(true);
        }else{
            iter.value()->setVisible(false);
        }
        iter++;
    }

    if(!showbool){
        QMap<QString,DeviceItem*>::const_iterator iter=DeviceItemMap.begin();
        while (iter !=DeviceItemMap.end()){
            if(iter.value()->page == 1){
                iter.value()->setVisible(true);
            }
            iter++;
        }
    }

}

void DeviceManage::TableWidget_show()
{
    QMap<QString,LiftCode>LiftCodeMap=ESS_Single::GetInstance()->getLiftCodeMap();
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
    QMap<QString, LiftCode>::const_iterator iter= LiftCodeMap.begin();
    while (iter!=LiftCodeMap.end()) {
        int incount=0;
        RW_Excel RW_ExcelItem;
        RW_ExcelItem.ExcelA=QString::number(ExcelList.size()+1);
        RW_ExcelItem.ExcelB=iter.value().codeDesc;                               //升降机接驳台命名 2F-IN
        RW_ExcelItem.ExcelC=iter.value().codeType;                               //(IN- D100 D103 D105:1可放料,2-3去X楼)  ( OUT- D101 D102 D104: 1可取料,2取料完成)
        RW_ExcelItem.ExcelD=QString::number(iter.value().Liftstatus);            //升降机感应器状态 (IN-D100 D103 D105:1可放料,2-3去X楼) (OUT-D101 D102 D104: 1可取料,2取料完成)
        RW_ExcelItem.ExcelE=QString::number(iter.value().status);                //任务锁定状态:0空闲  1 锁定  2到达 0空闲
        RW_ExcelItem.ExcelF=QString::number(iter.value().SAPTaskIndex);          //任务索引 唯一值
        RW_ExcelItem.ExcelG=iter.value().containerCode;                          //容器编码 (即胶箱编码) ->唯一

        if(incount==0){
            incount=1;
            RW_ExcelItem.corlor=0;
            ExcelList.append(RW_ExcelItem);
        }
        iter++;
    }
    return ExcelList;
}


void DeviceManage::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset;border:none;");
}

void DeviceManage::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_released(Button,"background-color: rgb(0, 166, 172);color:#ffffff;color: white;  border: 2px groove gray;\
                                                border-radius:15px;border:none;");
}

void DeviceManage::ON_ClickProcess()
{
    QPushButton *Button = (QPushButton *)this->sender();
    int page=Button->objectName().right(1).toInt();
    if(Button->objectName().right(2).left(1)=="S"){
        UPLayout_show(DeviceItemMap_S, page);
    }if(Button->objectName().right(2).left(1)=="D"){
        UPLayout_show(DeviceItemMap_D, page);
    }

}

//设备动作指令——————> DeviceIP：设备IP     deviceType：设备类型   orderType：动作指令   Action：动作标识
void DeviceManage::ON_DeviceStatusAction(QString DeviceIP, QString deviceType, QString orderType, int Action)
{
    if(deviceType=="door"){
        Udp_DeviceI->ON_DeviceStatusAction(DeviceIP,deviceType,orderType,Action);
    }if(deviceType=="station"){
        TcpServerI->ON_DeviceStatusAction(DeviceIP,deviceType,orderType,Action);
    }
    qDebug()<<"ON_DeviceStatusAction -->DeviceIP:"<<DeviceIP<<" deviceType:"<<deviceType<<" orderType:"<<orderType<<" Action:"<<Action;
}

void DeviceManage::ON_setLiftactionArray(LiftTask LiftTaskI, int startFloor, int destFloor)
{
    if(destFloor!=4){
        QString action= ui->taskTypeBox_Lift->currentText().trimmed();
        QByteArray actionArray=array_Single::GetInstance()->getLiftactionArray(LiftTaskI,startFloor,destFloor);
        TcpClientI->setTcpServer_deviceAction(TcpClientI->TcpServerIP,actionArray);     //设置客户端基础信息
        qDebug()<<"ON_setLiftactionArray -->TcpServerIP:"<<TcpClientI->TcpServerIP<<" startFloor:"<<startFloor<<" destFloor:"<<destFloor;
    }
}


//更新各电梯状态信息
void DeviceManage::ON_LiftStatuschage(QString DeviceIP, QByteArray ActionArray)
{
    //01 23 45 67 89 10 12 14 16 18 20 22 24 26
    //81 00 03 00 02 00 03 00 06 00 07 00 08 00
    quint16 Statushex=array_Single::GetInstance()->getSystemchage(ActionArray,0,2);
    if(LiftTaskI.LiftIP==DeviceIP && Statushex==81){

        LiftTaskI.LiftD100=array_Single::GetInstance()->getSystemchage(ActionArray,4,2);          //2F-->IN
        LiftTaskI.LiftD101=array_Single::GetInstance()->getSystemchage(ActionArray,8,2);         //2F-->OUT

        LiftTaskI.LiftD102=array_Single::GetInstance()->getSystemchage(ActionArray,12,2);         //3F-->OUT
        LiftTaskI.LiftD103=array_Single::GetInstance()->getSystemchage(ActionArray,16,2);         //3F-->IN

        LiftTaskI.LiftD104=array_Single::GetInstance()->getSystemchage(ActionArray,20,2);         //4F-->OUT
        LiftTaskI.LiftD105=array_Single::GetInstance()->getSystemchage(ActionArray,24,2);         //4F-->IN

//        qDebug()<<"ON_LiftStatuschage--->LiftIP:"<<LiftTaskI.LiftIP<<" LiftD100:"<<LiftTaskI.LiftD100
//                  <<" LiftD101:"<<LiftTaskI.LiftD101<<" LiftD102:"<<LiftTaskI.LiftD102
//                    <<" LiftD103:"<<LiftTaskI.LiftD103<<" LiftD104:"<<LiftTaskI.LiftD104
//                      <<" LiftD105:"<<LiftTaskI.LiftD105;

        QStringList LiftStatus;
        LiftStatus<<"( 2F-进料_D100:"<<QString::number(LiftTaskI.LiftD100)<<"- 出料_D101:"<<QString::number(LiftTaskI.LiftD101)<<") —"
                 <<"( 3F-出料_D102:"<<QString::number(LiftTaskI.LiftD102)<<"- 进料_D103:"<<QString::number(LiftTaskI.LiftD103)<<") —"
                 <<"( 4F-出料_D104:"<<QString::number(LiftTaskI.LiftD104)<<"- 进料_D105:"<<QString::number(LiftTaskI.LiftD105)<<") -->"
                 <<QDateTime::currentDateTime().toString("hh:mm:ss");

        ui->tabletTextEdit->setText(LiftStatus.join(" "));
        emit sig_LiftTaskStatus(LiftTaskI);
    }

}


void DeviceManage::ON_DeviceStatuschage(QString DeviceIP, QByteArray ActionArray)
{

    //controlbox controlboxI=array_Single::GetInstance()->setSystemchage(DeviceIP,ActionArray);
    controlbox controlboxI;
    if(ActionArray.at(8)==1){
        controlboxI.X10=1;
    }if(ActionArray.at(8)==2){
        controlboxI.X11=1;
    }if(ActionArray.at(8)==3){
        controlboxI.X10=1;
        controlboxI.X11=1;
    }

    if(DeviceItemMap_D.contains(DeviceIP)){
        QMap<QString,DeviceItem*>::iterator iter0= DeviceItemMap_D.begin();//自动门控制
        while (iter0!=DeviceItemMap_D.end()) {
            if(iter0.value()->deviceIP==DeviceIP){
                iter0.value()->currentDeviceI.onLine=0;
                iter0.value()->currentDeviceI.status=0;
                iter0.value()->currentDeviceI.sensor_1=controlboxI.X10;                 //1号光电感应 状态  0无  1有
                iter0.value()->currentDeviceI.sensor_2=controlboxI.X11;                 //2号光电感应 状态  0无  1有

                if(controlboxI.X10==1 && controlboxI.X11==1){
                    iter0.value()->currentDeviceI.onLine=1;
                    iter0.value()->currentDeviceI.status=1;
                }else{
                    iter0.value()->currentDeviceI.onLine=1;
                    iter0.value()->currentDeviceI.status=0;
                }
                //更新各设备状态信息  控制盒-自动门类型
                emit sigDeviceStatus_door(DeviceIP,iter0.value()->currentDeviceI.onLine,iter0.value()->currentDeviceI.status,controlboxI);
            }
            iter0++;
        }
    }

    if(DeviceItemMap_S.contains(DeviceIP)){
        QMap<QString,DeviceItem*>::iterator iter0= DeviceItemMap_S.begin();//自动门控制
        while (iter0!=DeviceItemMap_S.end()) {
            if(iter0.value()->deviceIP==DeviceIP){
                iter0.value()->currentDeviceI.onLine=1;
                iter0.value()->currentDeviceI.onLinecount=0;
                iter0.value()->currentDeviceI.sensor_1=controlboxI.X10;                 //1号光电感应 状态  0无  1有
                iter0.value()->currentDeviceI.sensor_2=controlboxI.X11;                 //2号光电感应 状态  0无  1有

                if(controlboxI.X10==1 && controlboxI.X11==1){
                    iter0.value()->currentDeviceI.status=1;
                }else{
                    iter0.value()->currentDeviceI.status=0;
                }

                //更新各设备状态信息  控制盒-自动门类型
                emit sigDeviceStatus_station(DeviceIP,iter0.value()->currentDeviceI.onLine,iter0.value()->currentDeviceI.status,controlboxI);
            }
            iter0++;
        }
    }

}



//plc  电梯动作指令
void DeviceManage::on_Sure_Button_Lift_clicked()
{
   QString action= ui->taskTypeBox_Lift->currentText().trimmed();
   QByteArray actionArray=array_Single::GetInstance()->getLiftactionArray(LiftTaskI,action.left(1).toInt(), action.mid(5,1).toInt());
   //TcpServerI->setTcpServer_deviceAction(LiftTaskI.LiftIP,actionArray);          //设置客户端基础信息

   TcpClientI->setTcpServer_deviceAction(TcpClientI->TcpServerIP,actionArray);     //设置客户端基础信息

}

void DeviceManage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->treeWidget->verticalScrollBar()->setVisible(false);
    ui->treeWidget->horizontalScrollBar()->setVisible(false);
    QString treeWidget=item->text(column);
    if(treeWidget=="升降机" ){
        ui->stackedWidget_2->setCurrentIndex(3);
    }if(treeWidget=="接驳台"){
        ui->stackedWidget_2->setCurrentIndex(1);
    }if(treeWidget=="自动门"){
        ui->stackedWidget_2->setCurrentIndex(2);
    }
}


