#include "agviteminfo.h"
#include "ui_agviteminfo.h"
//红色 #FF4500  橙色  #EEB422  绿色 #76EE00  #00FF00  淡绿色 #98FB98  黑色 #050505
agviteminfo::agviteminfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::agviteminfo)
{
    ui->setupUi(this);
    this->setWindowTitle("小藩机器人参数界面");
    My_SqlInit();//数据初始化

    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

    _StatusSocket= new RobotStatusTcp(this);
//    connect(_StatusSocket,SIGNAL(sigPrintInfo(QString)),this,SLOT(slotPrintInfo(QString)));
//    connect(_StatusSocket,SIGNAL(sigChangedText(bool,int,QByteArray,QByteArray,int,int)),
//            this,SLOT(slotChangedText(bool,int,QByteArray,QByteArray,int,int)));

    _ControlSocket= new RobotStatusTcp(this);
//    connect(_ControlSocket,SIGNAL(sigPrintInfo(QString)),this,SLOT(slotPrintInfo(QString)));
//    connect(_ControlSocket,SIGNAL(sigChangedText(bool,int,QByteArray,QByteArray,int,int)),
//            this,SLOT(slotChangedText(bool,int,QByteArray,QByteArray,int,int)));

    CreateConnect(_StatusSocket,19204);
    CreateConnect(_ControlSocket,19206);

    StatusTimer = new QTimer(this);
    connect(StatusTimer,&QTimer::timeout,this,&agviteminfo::RoboshopStatetimer);
    StatusTimer->start(1000);

    connect(this,&agviteminfo::Roboshop_Action,this,&agviteminfo::ON_Roboshop_Action);//实时更新Roboshop 状态信息
    connect(_ControlSocket,&RobotStatusTcp::Roboshop_ret_code,this,&agviteminfo::ON_Roboshop_ret_code);//实时更新Roboshop 状态信息
    connect(_ControlSocket,&RobotStatusTcp::returnwriteTcpData,this,&agviteminfo::ON_returnwriteTcpData);//返回发送 数据信息  显示


}

agviteminfo::~agviteminfo()
{
    delete ui;
}


void agviteminfo::CreateConnect(RobotStatusTcp *StatusTcp,quint16 port)
{
    qDebug() << "try CreateConnect  43";
    QString strInfo;
    switch (StatusTcp->connectHost(RoboshopStateItem.Roboshop_IP,port)) {
    case 1:
        strInfo = QString(QStringLiteral("连接失败"));
        qDebug() << strInfo;
        break;
    default:
        break;
    }
}

void agviteminfo::_StatusSocketProcess()//_StatusSocket 数据处理
{
    if(_StatusSocket->tcpSocket()->state()==QAbstractSocket::UnconnectedState
          &&  _StatusSocket->tcpSocket()){
        _StatusSocket_online_count++;
        _StatusSocket->RoboshopStateItem.isOnline=false;
        if(_StatusSocket_online_count==10){
            _StatusSocket->releaseTcpSocket();
        }
        if(_StatusSocket_online_count==15){
            _StatusSocket_online_count=0;
            CreateConnect(_StatusSocket,19204);
        }
    }
    if(_StatusSocket->tcpSocket()->state()!=QAbstractSocket::UnconnectedState
          &&  _StatusSocket->tcpSocket()){
            _StatusSocket_online_count=0;
    }

    if(_StatusSocket->tcpSocket()->state()==QAbstractSocket::ConnectedState
           && _StatusSocket->tcpSocket()){
        uint16_t sendCommand =1100;//报头数据类型
        QString sendDataStr = "";uint16_t number =0; //序号
        QByteArray sendData = sendDataStr.toLatin1();   //数据区数据
        if(_StatusSocket->writeTcpData(sendCommand,sendData,number)){  //发送数据
            //qDebug()<<sendCommand<<sendData<<number<<" 发送数据 225";
        }
    }
}

void agviteminfo::_ControlSocketProcess()//_ControlSocket 数据处理
{
    if(RoboshopActionItem.relocation=="0"){//0断开当前连接
        RoboshopActionItem.relocation="1";
        _ControlSocket->releaseTcpSocket();return;
    }
    if(RoboshopActionItem.relocation=="1"){//1开始建立新连接
        RoboshopActionItem.relocation="2";
        CreateConnect(_ControlSocket,RoboshopActionItem.port);return;
    }
    if(_ControlSocket->tcpSocket() && RoboshopActionItem.relocation=="2"
            && _ControlSocket->tcpSocket()->state()==QAbstractSocket::ConnectedState){
        uint16_t sendCommand=0;  uint16_t number=0; //前往下一个 科室
        foreach (description description1, descriptionlist){//执行动作解析链表
            if(description1.resDescription==RoboshopActionItem.descrip){
                sendCommand=description1.reqValue;//sendCommand - 报文类型
                QByteArray sendData = RoboshopActionItem.sendDataStr.toLatin1(); //数据区数据
                if(_ControlSocket->writeTcpData(sendCommand,sendData,number)){//sendCommand - 报文类型  sendData - 数据区数据  number - 序号
                    if(RoboshopActionItem.descrip=="机器人重定位"){
                        ui->relocation->setText("确认");
                    }
                    if(RoboshopActionItem.descrip=="确认重定位正确"){
                        ui->relocation->setText("重定位");
                    }
                    ui->widget->setEnabled(true);     RoboshopActionItem.relocation="3";
                    RoboshopActionItem.sendDataStr="";RoboshopActionItem.descrip="";

                }
            }
        }
    }

}

void agviteminfo::RoboshopStatetimer()
{
    _StatusSocketProcess();  //_StatusSocket 数据处理
    _ControlSocketProcess();//_ControlSocket 数据处理
    UP_RoboshopState();
}

void agviteminfo::stateChanged(QAbstractSocket::SocketState state)
{
    QString info;
    switch (_StatusSocket->tcpSocket()->state()) {
    case QAbstractSocket::UnconnectedState:
        info = "QAbstractSocket::UnconnectedState";
        break;
    case QAbstractSocket::HostLookupState:
        info = "QAbstractSocket::HostLookupState";
        break;
    case QAbstractSocket::ConnectingState:
        info = "QAbstractSocket::ConnectingState";
        break;
    case QAbstractSocket::ConnectedState:
        info = "QAbstractSocket::ConnectedState \n";
        break;
    case QAbstractSocket::BoundState:
        info = "QAbstractSocket::BoundState";
        break;
    case QAbstractSocket::ListeningState:
        info = "QAbstractSocket::ListeningState";
        break;
    case QAbstractSocket::ClosingState:
        info = "QAbstractSocket::ClosingState";
        break;
    }
    qDebug()<<info;
}

void agviteminfo::ON_Roboshop_ret_code(QByteArray RecvData)
{
    ui->widget->setEnabled(true);
    _ControlSocket->releaseTcpSocket();
    QByteArray headB = RecvData.left(16);//截取报头16位后面的数据区数据
    QByteArray json_data = RecvData.mid(16, RecvData.size());
    QJsonObject json_object = QJsonDocument::fromJson(json_data).object();

    ui->RecvHead->setText(_ControlSocket->hexToQString(RecvData.left(16).toHex()));
    ui->json_object->setText("ret_code="+QString::number(json_object.value("ret_code").toInt())+"             ::          err_msg="+json_object.value("err_msg").toString());
    ui->RecvData->setText(_ControlSocket->hexToQString(RecvData.toHex()));

    qDebug()<<headB;
    qDebug()<<json_data;
    qDebug()<<"数据发送成功，_ControlSocket 断开连接 ret_code="<<json_object.value("ret_code").toInt()<<"err_msg"<<json_object.value("err_msg").toString();

}
void agviteminfo::ON_returnwriteTcpData(QByteArray writeData)
{
    ui->writeTcpData->setText(_ControlSocket->hexToQString(writeData.toHex()));
}
void agviteminfo::receiveTcpError(QAbstractSocket::SocketError error)
{

}

void agviteminfo::ON_Roboshop_Action(QString lm_station, QString descrip, QString Action)
{
    qDebug()<<lm_station<<descrip<<Action<<"LM 动作指令  动作类型  0 1";
    foreach (lmstation lmstation1, lmstationlist) {//导航与重定位坐标
        if(lmstation1.LM_Name==lm_station && descrip=="路径导航"){
            RoboshopActionItem.sendDataStr=lmstation1.navigation;
        }
        if(lmstation1.LM_Name==lm_station && descrip=="机器人重定位"){
            RoboshopActionItem.sendDataStr=lmstation1.relocation;
        }
    }
    RoboshopActionItem.descrip=descrip;
    foreach (description description1, descriptionlist){//执行动作解析链表
        if(description1.resDescription==RoboshopActionItem.descrip){
            ui->widget->setEnabled(false);
            RoboshopActionItem.port=description1.port;//TCP端口
            if(_ControlSocket->_port!=description1.port && _ControlSocket->tcpSocket()){
                RoboshopActionItem.relocation="0";
            }
            if(_ControlSocket->_port==description1.port && _ControlSocket->tcpSocket()){
                if(_ControlSocket->tcpSocket()->state()==QAbstractSocket::ConnectedState){
                    RoboshopActionItem.relocation="2";
                }
                if(_ControlSocket->tcpSocket()->state()!=QAbstractSocket::ConnectedState){
                    RoboshopActionItem.relocation="0";
                }
            }
        }
    }

}




//取消导航
void agviteminfo::on_cancelnavigation_clicked()
{
    emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"机器人取消当前任务","1");//LM 动作指令  动作类型  0 1
}
//重定位
void agviteminfo::on_relocation_clicked()
{
    if(ui->relocation->text()=="重定位"){
        emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"机器人重定位","2");//LM 动作指令  动作类型  0 1
    }
    if(ui->relocation->text()=="确认"){
        emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"确认重定位正确","2");//LM 动作指令  动作类型  0 1
    }
}
//暂停导航
void agviteminfo::on_pausenavigation_clicked()
{
    if(ui->pausenavigation->text()=="暂\n停\n导\n航"){
        ui->pausenavigation->setText("继\n续\n导\n航");
        emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"机器人暂停当前任务","1");//LM 动作指令  动作类型  0 1
        return;
    }
    if(ui->pausenavigation->text()=="继\n续\n导\n航"){
        ui->pausenavigation->setText("暂\n停\n导\n航");
        emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"机器人继续当前任务","1");//LM 动作指令  动作类型  0 1
    }
}
//导航
void agviteminfo::on_navigation_clicked()
{
    emit Roboshop_Action(ui->comboBox_LM_Name->currentText(),"路径导航","1");//LM 动作指令  动作类型  0 1
}


void agviteminfo::My_SqlInit()
{
    QSqlDatabase sqlDatabase = SqlConnectionPool::openSqlConnection();
    sqlDatabase.transaction();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from lmstation;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            lmstation lmstation1;
            lmstation1.LM_Name=sqlQuery.value("LM_Name").toString();     //地图站点
            lmstation1.navigation=sqlQuery.value("navigation").toString();  //导航
            lmstation1.relocation=sqlQuery.value("relocation").toString();  //重定位
            lmstationlist.append(lmstation1);      //导航与重定位坐标
            //qDebug()<<lmstation1.navigation;
        }
    }

    sqlQuery.prepare("select * from description;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            description description1;
            description1.Type=sqlQuery.value("Type").toString();           //类型
            description1.resDescription=sqlQuery.value("resDescription").toString();//动作命令解析
            description1.port=quint16(sqlQuery.value("port").toInt());              //TCP端口
            description1.reqValue=quint16(sqlQuery.value("reqValue").toInt());          //报文类型
            descriptionlist.append(description1); //执行动作解析链表
            //qDebug()<<   description1.resDescription;
        }
    }

    sqlDatabase.commit();
    SqlConnectionPool::closeSqlConnection(sqlDatabase);
}


//定时更新显示状态
void agviteminfo::UP_RoboshopState()
{
    if (_StatusSocket->tcpSocket() && _StatusSocket->tcpSocket()->state()==QAbstractSocket::ConnectedState)
    {
        RoboshopStateItem=_StatusSocket->RoboshopStateItem;

    }
    emit UPRoboshopState(RoboshopStateItem);//实时更新Roboshop 状态信息
    ui->Roboshop_IP->setText(RoboshopStateItem.Roboshop_IP);                      //RoboshopIP
    ui->controller_temp->setText(QString::number(RoboshopStateItem.controller_temp));//控制器温度, 单位 ℃
    ui->controller_humi->setText(QString::number(RoboshopStateItem. controller_humi));//控制器湿度, 单位 %
    ui->controller_voltage->setText(QString::number(RoboshopStateItem. controller_voltage));//控制器电压, 单位 V

    ui->Roboshopx->setText(QString::number(RoboshopStateItem.x)); //	机器人的 x 坐标, 单位 m
    ui->Roboshopy->setText(QString::number(RoboshopStateItem.y));//机器人的 y 坐标, 单位 m
    ui->angle->setText(QString::number(RoboshopStateItem.angle));//机器人的 angle 坐标, 单位 rad

    ui->confidence->setText(QString::number(RoboshopStateItem.confidence));//机器人的定位置信度, 范围 [0, 1]
    if(RoboshopStateItem.confidence>=0.90){
        ui->confidence->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(85,255,127);");
    }
    if(RoboshopStateItem.confidence<0.90){
        ui->confidence->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,0,0);");
    }

    ui->current_station->setText(RoboshopStateItem.current_station);//机器人当前所在站点的 ID（该判断比较严格，机器人必须很靠近某一个站点(<50cm)，否则为空字符，即不处于任何站点）
    ui->last_station->setText(RoboshopStateItem.last_station);//机器人上一个所在站点的 ID

    ui->Roboshopvx->setText(QString::number(RoboshopStateItem.vx));//机器人在机器人坐标系的 x 方向速度, 单位 m/s
    ui->Roboshopvy->setText(QString::number(RoboshopStateItem.vx));//机器人在机器人坐标系的 y 方向速度, 单位 m/s

    /*
     *减速的原因 / 被阻挡的原因, 0 = Ultrasonic (超声), 1 = Laser (激光), 2 = Fallingdown (防跌落传感器),
     * 3 = Collision (碰撞传感器), 4 = Infrared (红外传感器),
     * 5 = Lock（锁车开关），6 = 动态障碍物，
     * 7 = 虚拟激光点，8 = 3D 相机
    */
    ui->blocked->setText("");//机器人是否被阻挡
    ui->block_reason->setText("");//机器人是否被阻挡
    if(RoboshopStateItem. blocked){
        ui->blocked->setText("机器人被阻挡");
        ui->block_reason->setText(QString::number(RoboshopStateItem.block_reason));//******被阻挡的原因,
        ui->block_x->setText(QString::number(RoboshopStateItem.block_x));//最近障碍物位置的 x 坐标, 单位 m
        ui->block_y->setText(QString::number(RoboshopStateItem.block_y));//最近障碍物位置的 y 坐标, 单位 m

    }
    ui->slowed->setText("");//机器人是否减速
    ui->slow_reason->setText("");//机器人是否被阻挡
    if(RoboshopStateItem. slowed){
        ui->slowed->setText("机器人被减速");
        ui->slow_reason->setText(QString::number(RoboshopStateItem.slow_reason));//******减速的原因,
        ui->slow_x->setText(QString::number(RoboshopStateItem.slow_x));//最近的导致减速的障碍物位置的 x 坐标, 单位 m
        ui->slow_y->setText(QString::number(RoboshopStateItem.slow_y));//最近的导致减速的障碍物位置的 y 坐标, 单位 m
    }
    ui->charging->setText("");//电池是否正在充电
    ui->charging->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,255,255);");
    if(RoboshopStateItem.charging){//电池是否正在充电
        ui->charging->setText("正在充电");
        ui->charging->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(85,255,127);");
    }

    ui->voltage->setText(QString::number(RoboshopStateItem.voltage));//电压, 单位 V
    ui->voltage->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(85,255,127);");
    if(RoboshopStateItem.voltage<500){
        ui->voltage->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,0,0);");
    }
    ui->current->setText(QString::number(RoboshopStateItem.current));//电流, 单位 A

    ui->emergency->setText(QString::number(RoboshopStateItem.emergency));//true 表示急停按钮处于激活状态(按下), false 表示急停按钮处于非激活状态(拔起)
    ui->emergency->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,255,255);");
    if(RoboshopStateItem.emergency){
        ui->emergency->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,0,0);");
    }

    ui->driver_emc->setText(QString::number(RoboshopStateItem.driver_emc));//true 表示驱动器发生急停, false 驱动器发生未急停
    ui->driver_emc->setStyleSheet("background-color: rgb(81,81,81);color: rgb(255,255,255);");
    if(RoboshopStateItem.driver_emc){
        ui->driver_emc->setStyleSheet("background-color: rgb(81,81,81);color: rgb(255,0,0);");
    }

    ui->task_status->setText(QString::number(RoboshopStateItem.task_status)); //0 = NONE, 1 = WAITING, 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
    ui->task_type->setText(QString::number(RoboshopStateItem.task_type));//导航类型, 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 5 = 钻货架, 6 = 跟随, 7 = 平动转动, 8 = 磁条导航, 100 = 其他
    ui->target_id->setText(RoboshopStateItem.target_id);//	当前导航要去的站点, 仅当 task_type 为 2 或 3 时该字段有效, task_status 为 RUNNING 时说明正在去这个站点, task_status 为 COMPLETED 时说明已经到达这个站点, task_status 为 FAILED 时说明去这个站点失败, task_status 为 SUSPENDED 说明去这个站点的导航暂停
    ui->roboroute_target->setText(RoboshopStateItem.roboroute_target);//	调度系统 RoboRoute 让机器人去的最终目标站点 ID
    ui->reloc_status->setText(QString::number(RoboshopStateItem.reloc_status));//0 = FAILED(定位失败), 1 = SUCCESS(定位正确), 2 = RELOCING(正在重定位), 3=COMPLETED(定位完成)

//    QList<QList<double> > path;//机器人所在区域 id 的数组(由于地图上的区域是可以重叠的, 所以机器人可能同时在多个区域)，数组可能为空
//    QList<QString> finished_path;//当前导航路径上已经经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效点。如果是路径导航， 这里会列出所有已经经过的中间点
//    QList<QString> unfinished_path;//当前导航路径上尚未经过的站点, 为站点的数组, 仅当 task_type 为 3 或 4 时该字段有效。如果是路径导航， 这里会列出所有尚未经过的中间点;

//    QJsonObject warnings;//报警码 Warning 的数组, 所有出现的 Warning 报警都会出现在数据中
//    QJsonObject errors;//报警码 Error 的数组, 所有出现的 Error 报警都会出现在数据中

    ui->warnings->setText(QString(QJsonDocument(RoboshopStateItem.warnings).toJson()));//报警码 Warning 的数组, 所有出现的 Warning 报警都会出现在数据中
    ui->errors->setText(QString(QJsonDocument(RoboshopStateItem.errors).toJson()));//报警码 Error 的数组, 所有出现的 Error 报警都会出现在数据中
    ui->err_msg->setText(RoboshopStateItem.err_msg);


    ui->ret_code->setText(QString::number(RoboshopStateItem.ret_code));//API 错误码
    ui->reloc_status->setText(RoboshopStateItem.err_msg);//错误信息

//自定义
    ui->isOnline->setText("离线");
    ui->isOnline->setStyleSheet("background-color: rgb(81, 81, 81);color: rgb(255,0,0);");
    if(RoboshopStateItem.isOnline){ //Roboshop是否掉线
        ui->isOnline->setText("在线");
        ui->isOnline->setStyleSheet("background-color: rgb(85, 81, 81);color: rgb(85,255,127);");
    }

    ui->RunState->setText("停止");
    if(RoboshopStateItem.RunState){ui->RunState->setText("运行");}

    ui->Roboshop_ChargeAction->setText("");
    if(RoboshopStateItem.Roboshop_ChargeAction=="1"){
        ui->Roboshop_ChargeAction->setText("充电中");
    }
    ui->relocation_2->setText(RoboshopActionItem.descrip+""+ RoboshopActionItem.relocation);

}
