#include "AgvStatus.h"
#include "ui_AgvStatus.h"

AgvStatus::AgvStatus(QWidget *parent) :
    QWidget(parent),autoOpenCount(0),
    ui(new Ui::AgvStatus)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&AgvStatus::timerTimeOut);
    timer->start(1200);
    ui->agvShow->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    ui->agvShow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->agvShow->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->agvShow->verticalHeader()->setVisible(false); //设置垂直头不可见

    for(int i = 0;i < ui->agvShow->rowCount();++i){
        for(int j = 0;j < ui->agvShow->columnCount();++j){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setTextAlignment(Qt::AlignCenter);
            item->setFont(QFont("Cambria", 14, QFont::Normal));
            item->setTextColor(QColor(128,255,255));
            ui->agvShow->setItem(i,j,item);
        }
    }

    //返回指令接收状态
    moveTaskStateMap.insert(0,"成功");
    moveTaskStateMap.insert(1,"任务过多失败");
    moveTaskStateMap.insert(2,"当前序号已经接收过");
    moveTaskStateMap.insert(3,"设置目标参数出错");
    moveTaskStateMap.insert(4,"小车当前位置信息无法执行动作任务");
    moveTaskStateMap.insert(5,"设置角度不是 0 90 180 270这几个角度");
    moveTaskStateMap.insert(6,"任务长度与接收数据不一致");
    moveTaskStateMap.insert(7,"原地旋转二维码坐标给定不正确");
    moveTaskStateMap.insert(8,"无法执行任务（故障或者复位中）");

}

AgvStatus::~AgvStatus()
{
    delete ui;
}

QString AgvStatus::getErrorCodeText(ERROR_CODE code)
{
    QString str;
    switch (code) {
    case ERROR_NULL:
        str = QObject::tr("(%1)无错误").arg(code);
        break;
    case ERROR_GYROTIMEOUT:
        str = QObject::tr("(%1)陀螺仪通信超时").arg(code);
        break;
    case ERROR_GYROINITERROR:
        str = QObject::tr("(%1)陀螺仪初始化故障").arg(code);
        break;
    case ERROR_MOTOR1_TIMEOUT:
        str = QObject::tr("(%1)马达1通信超时").arg(code);
        break;
    case ERROR_MOTOR2_TIMEOUT:
        str = QObject::tr("(%1)马达2通信超时").arg(code);
        break;
    case ERROR_MOTOR3_TIMEOUT:
        str = QObject::tr("(%1)马达3通信超时").arg(code);
        break;
    case ERROR_MOTOR4_TIMEOUT:
        str = QObject::tr("(%1)马达4通信超时").arg(code);
        break;
    case ERROR_MOTOR5_TIMEOUT:
        str = QObject::tr("(%1)马达5通信超时").arg(code);
        break;
    case ERROR_MOTOR1_ALARM:
        str = QObject::tr("(%1)马达1故障报警").arg(code);
        break;
    case ERROR_MOTOR2_ALARM:
        str = QObject::tr("(%1)马达2故障报警").arg(code);
        break;
    case ERROR_MOTOR3_ALARM:
        str = QObject::tr("(%1)马达3故障报警").arg(code);
        break;
    case ERROR_MOTOR4_ALARM:
        str = QObject::tr("(%1)马达4故障报警").arg(code);
        break;
    case ERROR_MOTOR5_ALARM:
        str = QObject::tr("(%1)马达5故障报警").arg(code);
        break;
    case ERROR_MOTOR1_CONTROL:
        str = QObject::tr("(%1)马达1控制故障").arg(code);
        break;
    case ERROR_MOTOR2_CONTROL:
        str = QObject::tr("(%1)马达2控制故障").arg(code);
        break;
    case ERROR_MOTOR3_CONTROL:
        str = QObject::tr("(%1)马达3控制故障").arg(code);
        break;
    case ERROR_MOTOR4_CONTROL:
        str = QObject::tr("(%1)马达4控制故障").arg(code);
        break;
    case  ERROR_MOTOR5_CONTROL:
        str = QObject::tr("(%1)马达5控制故障").arg(code);
        break;
    case ERROR_CONTROL_ANGLE_FRONT:
        str = QObject::tr("(%1)前转角度控制故障").arg(code);
        break;
    case  ERROR_CONTROL_ANGLE_BACK:
        str = QObject::tr("(%1)后转角度控制故障").arg(code);
        break;
    case  ERROR_MOTOR_ZERO_INIT:
        str = QObject::tr("(%1)旋转马达位置初始化").arg(code);
        break;
    case  ERROR_DRIVER_UPDOWN:
        str = QObject::tr("(%1)驱动升降故障").arg(code);
        break;
    case  ERROR_EMSTOP:
        str = QObject::tr("(%1)急停按下报警").arg(code);
        break;
    case  ERROR_OFFSET_LINE:
        str = QObject::tr("(%1)路径偏移过大").arg(code);
        break;
    case  ERROR_QRCODE_LOST:
        str = QObject::tr("(%1)丢失二维码故障").arg(code);
        break;
    case  ERROR_ROTATION_OFFSETMAX:
        str = QObject::tr("(%1)原地旋转偏差二维码过大").arg(code);
        break;
    case  ERROR_POBLIFT_OUTHEIGHT:
        str = QObject::tr("(%1)頂盘参数在行程允许范围外").arg(code);
        break;
    case  ERROR_POBLIFT_NOTINIT:
        str = QObject::tr("(%1)頂盘未原点初始化").arg(code);
        break;
    case  ERROR_LASER_FAR:
        str = QObject::tr("(%1)长激光感应").arg(code);
        break;
    default:
        str = QObject::tr("(%1)故障代码获取失败").arg(code);
        break;
    }
    return str;
}

QString AgvStatus::getWarningCodeText(int code)
{
    QString str;
    switch (code) {
    case 0:
        str = QObject::tr("(%1)无警告").arg(code);
        break;
    case 1:
        str = QObject::tr("(%1)当前电压值过低").arg(code);
        break;
    default:
        str = QObject::tr("(%1)警告代码获取失败").arg(code);
        break;
    }
    return str;
}

void AgvStatus::closeEvent(QCloseEvent *)
{
    autoOpenCount = 0;
}

void AgvStatus::timerTimeOut()
{
    const QMap<agvCar *,QString> &agvMap = agvCarPool::getInstance()->getAgvCarMap();
    QTableWidgetItem *item = nullptr;
    int i = 0;
    foreach(auto agvitem,agvMap.keys())
    {
        QColor agvStatusColor;
        if(!agvitem->agvStateItem.isOnline){
            agvStatusColor = QColor(255,0,0);
        }else{
            if(agvitem->agvStateItem.currentBatteryVoltageState.toInt() < 510){
                agvStatusColor = QColor(255,255,0);
            }else{
                agvStatusColor = QColor(29,149,63);
            }
        }
        item = ui->agvShow->takeItem(i,0);
        item->setTextColor(agvStatusColor);
        item->setText(QString::number(agvitem->agvId));
        ui->agvShow->setItem(i,0,item);

        item = ui->agvShow->takeItem(i,1);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.passPointState)+"-"+QString::number(agvitem->agvStateItem.ActionItem.doorPoint));
        ui->agvShow->setItem(i,1,item);
        item = ui->agvShow->takeItem(i,2);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.currentPoint_X_OffsetState));
        ui->agvShow->setItem(i,2,item);
        item = ui->agvShow->takeItem(i,3);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.currentPoint_Y_OffsetState));
        ui->agvShow->setItem(i,3,item);
        item = ui->agvShow->takeItem(i,4);
        item->setTextColor(agvStatusColor);
        item->setText(agvitem->agvStateItem.currentPointAttitudeAngleState.isEmpty()?"":QString("%1°").arg(agvitem->agvStateItem.currentPointAttitudeAngleState));
        ui->agvShow->setItem(i,4,item);

        item = ui->agvShow->takeItem(i,5);
        item->setTextColor(agvStatusColor);
        item->setText(agvitem->agvStateItem.currentPointRotaryAngleState.isEmpty()?"":QString("%1").arg(agvitem->agvStateItem.currentPointRotaryAngleState+"-"+agvitem->agvStateItem.currentRotaryHeightState));
        ui->agvShow->setItem(i,5,item);

        item = ui->agvShow->takeItem(i,6);
        item->setTextColor(agvStatusColor);
        item->setText(agvitem->agvStateItem.currentPointMoveAngleState.isEmpty()? "" :QString("%1°").arg(agvitem->agvStateItem.currentPointMoveAngleState));
        ui->agvShow->setItem(i,6,item);

        item = ui->agvShow->takeItem(i,7);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.isRotaryHighState));
        ui->agvShow->setItem(i,7,item);

        item = ui->agvShow->takeItem(i,8);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.isRotaryLowState));
        ui->agvShow->setItem(i,8,item);

        item = ui->agvShow->takeItem(i,9);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.currentCompletedTaskNumberState
                                        +"-"+agvitem->agvStateItem.currentTaskNumberState));
        ui->agvShow->setItem(i,9,item);

        item = ui->agvShow->takeItem(i,10);
        item->setTextColor(agvStatusColor);
        item->setText(QString("%1").arg(agvitem->agvStateItem.currentBatteryVoltageState
                                        +"-"+agvitem->agvStateItem.currentBatteryelectricity));
        ui->agvShow->setItem(i,10,item);

        item = ui->agvShow->takeItem(i,11);
        item->setTextColor(agvStatusColor);
        item->setText(getErrorCodeText((ERROR_CODE)agvitem->agvStateItem.currentErrorCodeState.toInt()));
        ui->agvShow->setItem(i,11,item);

        item = ui->agvShow->takeItem(i,12);
        item->setTextColor(agvStatusColor);
        item->setText(agvitem->agvStateItem.commandNo+"-"+agvitem->agvStateItem.commandNo_AGV);
        ui->agvShow->setItem(i,12,item);

        item = ui->agvShow->takeItem(i,13);
        item->setTextColor(agvStatusColor);
        if(agvitem->agvStateItem.isFrontLaserNearInducedState || agvitem->agvStateItem.isRearLaserNearInducedState){
            item->setText(agvitem->agvStateItem.FarInducedState);
        }else{
            item->setText((agvitem->agvStateItem.isOnline?"在线":"掉线")+agvitem->agvStateItem.currentTaskCountState);
        }
        ui->agvShow->setItem(i,13,item);

        item = ui->agvShow->takeItem(i,14);
        item->setTextColor(agvStatusColor);
        item->setText(moveTaskStateMap.value(agvitem->agvStateItem.moveTaskState));
        ui->agvShow->setItem(i,14,item);

        ++i;

        if((ERROR_CODE)agvitem->agvStateItem.currentErrorCodeState.toInt() != ERROR_NULL ||
               agvitem->agvStateItem.currentWarningCodeState.toInt() != 0 ||
                agvitem->agvStateItem.isFrontLaserNearInducedState){
            if(autoOpenCount > 10){
                this->show();
                this->activateWindow();
            }else{
                ++autoOpenCount;
            }
        }else{
            autoOpenCount = 0;
        }
    }
}
