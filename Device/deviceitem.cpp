#include "deviceitem.h"
#include "ui_deviceitem.h"

DeviceItem::DeviceItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceItem)
{
    ui->setupUi(this);
    DeviceItemInit();
    viceTimer = new QTimer(this);
    connect(viceTimer,&QTimer::timeout,this,&DeviceItem::ON_DeviceTimer);
    viceTimer->start(800);
}

DeviceItem::~DeviceItem()
{
    delete ui;
}

void DeviceItem::DeviceItemInit()
{
    cageIdMap.insert("door-0",":/image/door_close.png");
    cageIdMap.insert("door-1",":/image/door_opend.png");
    cageIdMap.insert("charge-0",":/image/charge.png");
    cageIdMap.insert("charge-1",":/image/charge.png");
    cageIdMap.insert("station-0",":/image/station0.bmp");
    cageIdMap.insert("station-1",":/image/station1.bmp");
    cageIdMap.insert("station-2",":/image/station2.bmp");
    cageIdMap.insert("station-3",":/image/station3.ico");
    cageIdMap.insert("station-4",":/image/station4.bmp");
    cageIdMap.insert("station-5",":/image/station5.bmp");

    StatusMap.insert("door-0","关门");
    StatusMap.insert("door-1","开门");
    StatusMap.insert("charge-0","收回");
    StatusMap.insert("charge-1","伸出");
    StatusMap.insert("station-0","无料框");
    StatusMap.insert("station-1","空料框");
    StatusMap.insert("station-2","待取货");
    StatusMap.insert("station-3","运输中");
    StatusMap.insert("station-4","已送达");
    StatusMap.insert("station-5","已送达");

    Actionbtns<<ui->enable_Button<<ui->reset_Button<<ui->action_Button1<<ui->action_Button2;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&DeviceItem::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&DeviceItem::ON_Released);
    }

}


//(备注: 任务执行过程中,取箱与放箱操作可重复执行,用于任务异常时，人工纠正后可继续执行)

//入库:-1 默认值  1容器到位   2到达工作站  3取箱成功  4离开工作站  5放箱成功  6任务完成

//出库:-1 默认值  0开始执行   1取箱中   3取箱成功  4等待放箱  5到达工作站   6允许放箱  7放箱成功  8任务完成

//移库:-1 默认值  0开始执行   1取箱中   3取箱成功  4等待放箱  5放箱成功  7任务完成

void DeviceItem::DeviceItem_widget_Show()
{
    if(currentDeviceI.currentEnable==0){
        ui->cageId->setPixmap(QPixmap(":/image/station.bmp"));
        ui->label_Info->setText(deviceDesc+"-"+"禁用");
        ui->enable_Button->setText("禁用");
    }else{
        if(currentDeviceI.onLine==0){
            ui->cageId->setPixmap(QPixmap(StatusMap.value(deviceType+"-"+QString::number(currentDeviceI.status))));
            ui->label_Info->setText(deviceDesc+"-"+"离线");
            ui->label_Info->setStyleSheet("color: red;border-radius:5px;background-color: rgb(170, 255, 127);");
        }else{
            //qDebug()<<deviceType<<currentDeviceI.status<<cageIdMap.value(deviceType+"-"+QString::number(currentDeviceI.status));
            ui->cageId->setPixmap(QPixmap(cageIdMap.value(deviceType+"-"+QString::number(currentDeviceI.status))));
            ui->label_Info->setText(deviceDesc+"-"+StatusMap.value(deviceType+"-"+QString::number(currentDeviceI.status)));
            ui->label_Info->setStyleSheet("color: white;border-radius:5px;background-color: rgb(170, 255, 127);");

            if(currentDeviceI.sensor_1==1){
                ui->sensor_1->setStyleSheet("background-color: rgb(170, 255, 127);border-radius:15px;padding:15px 30px;");
            }else{
                ui->sensor_1->setStyleSheet("background-color: rgb(150, 150, 150);border-radius:15px;padding:15px 30px;");
            }if(currentDeviceI.sensor_2==1){
                ui->sensor_2->setStyleSheet("background-color: rgb(170, 255, 127);border-radius:15px;padding:15px 30px;");
            }else{
                ui->sensor_2->setStyleSheet("background-color: rgb(150, 150, 150);border-radius:15px;padding:15px 30px;");
            }
        }
        ui->enable_Button->setText("使用");
    }

    if(deviceType=="charge"){
        ui->action_Button1->setText("伸出");
        ui->action_Button2->setText("收回");
    } if(deviceType=="door"){
        ui->action_Button1->setText("开门");
        ui->action_Button2->setText("关门");
    } if(deviceType=="station"){
        ui->action_Button1->setText("前滚动");
        ui->action_Button2->setText("后滚动");
    }

}

void DeviceItem::ON_DeviceTimer()
{
    DeviceItem_widget_Show();//实时更新工作站点 状态信息
}

void DeviceItem::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    QColor color(112, 161, 159);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(color));

    painter.fillRect(this->rect().x(),this->rect().y(),this->rect().width(),this->rect().height(),QBrush(color));
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

}

//指令1
void DeviceItem::on_action_Button1_clicked()
{
    emit sigDeviceStatusAction(deviceIP,deviceType,"action1",1);
}

//指令2
void DeviceItem::on_action_Button2_clicked()
{
    emit sigDeviceStatusAction(deviceIP,deviceType,"action2",2);
}

void DeviceItem::on_enable_Button_clicked()
{
    if(currentDeviceI.currentEnable==0){
        currentDeviceI.currentEnable=1;
    }else{
        currentDeviceI.currentEnable=0;
    }
}

//复位
void DeviceItem::on_reset_Button_clicked()
{
    emit sigDeviceStatusAction(deviceIP,deviceType, "clear", 0);
}

void DeviceItem::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"background-color: rgb(85,255,127);border-radius:15px;padding:5px 10px;");
}

void DeviceItem::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();
    Instance::GetInstance()->SetButton_released(Button,"background-color: rgb(255, 170, 127);border-radius:5px;padding:5px 10px;");
}



