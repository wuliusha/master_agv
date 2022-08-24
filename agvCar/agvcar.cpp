#include "agvcar.h"
#include <QDebug>
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

agvCar::agvCar()
{

    qRegisterMetaType<agvState >("agvState");
    qRegisterMetaType<agvORderTask >("agvORderTask");
    qRegisterMetaType<QMap<int,int >>("'QMap<int,int>");
    qRegisterMetaType<QList<agvState >>("QList<agvState >");
    qRegisterMetaType<QList<agvSubTask >>("QList<agvSubTask >");
    qRegisterMetaType<QMap<int,agvSubTask>>("QMap<int,agvSubTask>");

    connect(this,&agvCar::AGVMoveTask,this,&agvCar::onAGVMoveTask);
    connect(this,&agvCar::AGVChargeTask,this,&agvCar::ON_AGVChargeTask);

    UPdataTimer = new QTimer(this);
    connect(UPdataTimer, SIGNAL(timeout()), this, SLOT(ONUPdataTimer_Widget()));
    UPdataTimer->start(2000);

}

agvCar::~agvCar()
{
    qDebug()<<"~agvCarNew";
}

//发送 AGV移动任务 任务表
QByteArray agvCar::assignment_move(quint8 taskType, quint32 StartPoint,quint32 EndPoint, quint16 Distance,quint8 Speed,
                                   quint8 BarrierInstruction,quint16 AttitudeAngle, quint16 MoveAnage,quint16 RotaryAngle)
{

    QByteArray AssignmentArray;

    //任务标识
    AssignmentArray[0] = char(taskType);
    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;
    //导航方式
    AssignmentArray[3] = 0x02;
    //起始站点编号
    AssignmentArray[4] = char(StartPoint>>24);
    AssignmentArray[5] = char(StartPoint>>16);
    AssignmentArray[6] = char(StartPoint>>8);
    AssignmentArray[7] = char(StartPoint);
    //到达下一站点编号
    AssignmentArray[8] = char(EndPoint>>24);
    AssignmentArray[9] = char(EndPoint>>16);
    AssignmentArray[10] = char(EndPoint>>8);
    AssignmentArray[11] = char(EndPoint);
    //起始站点性质
    AssignmentArray[12] = 0x02;

    //到达站点性质
    AssignmentArray[13] = 0x02;
    //到达下一站点距离
    AssignmentArray[14] = char(Distance>>8);
    AssignmentArray[15] = char(Distance);

    //AGV运行速度
    AssignmentArray[16] = char(Speed);

    //障碍指令
    AssignmentArray[17] = char(BarrierInstruction);

    //小车姿态角度
    AssignmentArray[18] = char(AttitudeAngle>>8);
    AssignmentArray[19] = char(AttitudeAngle);

    //小车移动角度
    AssignmentArray[20] = char(MoveAnage>>8);
    AssignmentArray[21] = char(MoveAnage);

    //小车转盘角度
    AssignmentArray[22] = char(RotaryAngle>>8);
    AssignmentArray[23] = char(RotaryAngle);

    //预留
    AssignmentArray[24] = 0x00;
    AssignmentArray[25] = 0x00;
    AssignmentArray[26] = 0x00;
    AssignmentArray[27] = 0x00;

    //CRC编码
    quint16 AssignmentCrc = crc16((unsigned char*)AssignmentArray.constData(),AssignmentArray.size());

    //CRC编码 任务序号
    AssignmentArray[1] = char(AssignmentCrc>>8);
    AssignmentArray[2] = char(AssignmentCrc);

    //任务计数
    if(assignmentNo >= 65535){
        assignmentNo = 1;
    }else{
        assignmentNo ++;
    }
//        qDebug()<<"AssignmentArray_move";
//        qDebug()<<AssignmentArray.toHex();
    qDebug()<<"任务序号 AssignmentCrc:"<<AssignmentCrc;
    return AssignmentArray;
}


//发送 AGV举升降下托盘任务 任务表
QByteArray agvCar::assignment_tray(quint8 taskType, quint32 ExecutePoint)
{
    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(taskType);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(ExecutePoint>>24);
    AssignmentArray[5] = char(ExecutePoint>>16);
    AssignmentArray[6] = char(ExecutePoint>>8);
    AssignmentArray[7] = char(ExecutePoint);

    //预留
    AssignmentArray[8] = 0x00;
    AssignmentArray[9] = 0x00;
    AssignmentArray[10] = 0x00;
    AssignmentArray[11] = 0x00;
    AssignmentArray[12] = 0x00;
    AssignmentArray[13] = 0x00;
    AssignmentArray[14] = 0x00;
    AssignmentArray[15] = 0x00;
    AssignmentArray[16] = 0x00;
    AssignmentArray[17] = 0x00;
    AssignmentArray[18] = 0x00;
    AssignmentArray[19] = 0x00;
    AssignmentArray[20] = 0x00;
    AssignmentArray[21] = 0x00;
    AssignmentArray[22] = 0x00;
    AssignmentArray[23] = 0x00;
    AssignmentArray[24] = 0x00;
    AssignmentArray[25] = 0x00;
    AssignmentArray[26] = 0x00;
    AssignmentArray[27] = 0x00;

    //CRC编码
    quint16 AssignmentCrc = quint16(crc16((unsigned char*)AssignmentArray.constData(),AssignmentArray.size()));

    //CRC编码 任务序号
    AssignmentArray[1] = char(AssignmentCrc>>8);
    AssignmentArray[2] = char(AssignmentCrc);

    //任务计数
    if(assignmentNo >= 65535)
    {
        assignmentNo = 1;
    }else{
        assignmentNo ++;
    }
    qDebug()<<" AGV举升降下托盘任务: taskType="<<taskType<<" ExecutePoint:"<<ExecutePoint;
    qDebug()<<AssignmentArray.toHex();

    return AssignmentArray;
}

//发送 AGV举升到指定高度任务 任务表
QByteArray agvCar::assignment_Rotary(quint8 taskType, quint32 ExecutePoint,quint16 AttitudeAngle, quint16 RotaryHeight)
{
    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(taskType);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(ExecutePoint>>24);
    AssignmentArray[5] = char(ExecutePoint>>16);
    AssignmentArray[6] = char(ExecutePoint>>8);
    AssignmentArray[7] = char(ExecutePoint);

    //小车姿态角度
    AssignmentArray[8] = char(AttitudeAngle>>8);
    AssignmentArray[9] = char(AttitudeAngle);

    //小车转盘角度
    AssignmentArray[10] = char(RotaryHeight>>8);
    AssignmentArray[11] = char(RotaryHeight);

    //预留
    AssignmentArray[12] = 0x00;
    AssignmentArray[13] = 0x00;
    AssignmentArray[14] = 0x00;
    AssignmentArray[15] = 0x00;
    AssignmentArray[16] = 0x00;
    AssignmentArray[17] = 0x00;
    AssignmentArray[18] = 0x00;
    AssignmentArray[19] = 0x00;
    AssignmentArray[20] = 0x00;
    AssignmentArray[21] = 0x00;
    AssignmentArray[22] = 0x00;
    AssignmentArray[23] = 0x00;
    AssignmentArray[24] = 0x00;
    AssignmentArray[25] = 0x00;
    AssignmentArray[26] = 0x00;
    AssignmentArray[27] = 0x00;

    //CRC编码
    quint16 AssignmentCrc = crc16((unsigned char*)AssignmentArray.constData(),AssignmentArray.size());

    //CRC编码 任务序号
    AssignmentArray[1] = char(AssignmentCrc>>8);
    AssignmentArray[2] = char(AssignmentCrc);

    //任务计数
    if(assignmentNo >= 65535)
    {
        assignmentNo = 1;
    }
    else
    {
        assignmentNo ++;
    }

    qDebug()<<"AssignmentArray_发送 AGV举升到指定高度任务 任务表";
    qDebug()<<AssignmentArray.toHex();
    return AssignmentArray;
}

//发送 AGV 夹抱机器人取放货 动作 指令  assignmentId
QByteArray agvCar::assignment_control(quint8 taskType, quint32 ExecutePoint, agvORderTask agvORderTaskI)
{

    //发送 AGV 夹抱机器人取放货 动作 指令  任务标识 assignmentId

    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(taskType);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(ExecutePoint>>24);
    AssignmentArray[5] = char(ExecutePoint>>16);
    AssignmentArray[6] = char(ExecutePoint>>8);
    AssignmentArray[7] = char(ExecutePoint);


    AssignmentArray[8] = 0x00;        //姿态角度 (暂定0)
    AssignmentArray[9] = 0x00;        //姿态角度 (暂定0)

    AssignmentArray[10] = 0x00;       //顶盘角度 (暂定0)
    AssignmentArray[11] = 0x00;       //姿态角度 (暂定0)

    AssignmentArray[12] = char(agvORderTaskI.comparePosition);    //精准定位 1  不精准定位0
    AssignmentArray[13] = char(agvORderTaskI.actionORder);        //0x01 从货架上取   0x02从车上取
    AssignmentArray[14] = char(agvORderTaskI.actionDirection);    //货架在左边 0x01   在右边 0x02

    if(agvORderTaskI.AGVRack_Type==1){//0 默认是从货架取放   1从小精灵上进行取放
        AssignmentArray[15] = 0x00;
        AssignmentArray[17] = char(agvORderTaskI.storageRack);        //货架层数
    }else{
        AssignmentArray[15] = char(agvORderTaskI.storageRack);        //货架层数
        AssignmentArray[17] = 0x00;
    }

    AssignmentArray[16] = char(agvORderTaskI.AGVRack);            //夹抱机器层数

    //预留

    AssignmentArray[18] = 0x00;
    AssignmentArray[19] = 0x00;
    AssignmentArray[20] = 0x00;
    AssignmentArray[21] = 0x00;
    AssignmentArray[22] = 0x00;
    AssignmentArray[23] = 0x00;
    AssignmentArray[24] = 0x00;
    AssignmentArray[25] = 0x00;
    AssignmentArray[26] = 0x00;
    AssignmentArray[27] = 0x00;

    //CRC编码
    quint16 AssignmentCrc = quint16(crc16((unsigned char*)AssignmentArray.constData(),AssignmentArray.size()));

    //CRC编码 任务序号
    AssignmentArray[1] = char(AssignmentCrc>>8);
    AssignmentArray[2] = char(AssignmentCrc);

    //任务计数
    if(assignmentNo >= 65535)
    {
        assignmentNo = 1;
    }
    else
    {
        assignmentNo ++;
    }

    qDebug()<<"夹抱机器人动作指令-->  id:"<<taskType<<" 精准定位:"<<agvORderTaskI.comparePosition
           <<"从**上取料框:"<<agvORderTaskI.actionORder<<" 货架在左/右"<<agvORderTaskI.actionDirection
          <<" 货架层数:"<<agvORderTaskI.storageRack<<" 小车层数:"<<agvORderTaskI.AGVRack
         <<"任务序号:"<<AssignmentArray[1]<<AssignmentArray[2];

    qDebug()<<"取放货任务序号: "<<AssignmentCrc<<"   AssignmentArray:"<<AssignmentArray.toHex();

    return AssignmentArray;
}

//发送 AGV任务命令表   多任务
QByteArray agvCar::command_order(quint8 commandId, QList<QByteArray > assignmentList)
{
    QByteArray CommandArray;

    //命令码
    CommandArray[0] = char(commandId);

    switch (commandId)
    {
    case 0x01:
    {
        //贞编码
        CommandArray[1] = char(commandNo>>8);
        CommandArray[2] = char(commandNo);

        if(commandNo >= 65535)
        {
            commandNo = 2;
        }
        else
        {
            commandNo ++;
        }

        //任务数
        CommandArray[3] = char(assignmentList.size());

        //任务
        for(int i=0;i<assignmentList.size();i++)
        {
            CommandArray.append(assignmentList.at(i));
        }
    }
        break;
    default:
        break;
    }

    return CommandArray;
}

//发送 AGV其他命令表
QByteArray agvCar::command(quint16 commandId)
{
    QByteArray CommandArray;

    //命令码
    CommandArray[0] = char(commandId);

    switch (commandId)
    {
    case 0x02:
    {
        //贞编码
        CommandArray[1] = 0x00;
        CommandArray[2] = 0x00;
    }
        break;
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0A:
    {
        //贞编码
        CommandArray[1] = char(commandNo)>>8;
        CommandArray[2] = char(commandNo);

        if(commandNo >= 65535)
        {
            commandNo = 2;
        }
        else
        {
            commandNo ++;
        }
    }
        break;
    default:
        break;
    }

    return CommandArray;
}

//发送 AGV其他命令表
QByteArray agvCar::command_other(quint16 commandId)
{
    QByteArray CommandArray;

    //命令码
    CommandArray[0] = char(commandId);

    switch (commandId)
    {
    case 0x02:
    {
        //贞编码
        CommandArray[1] = 0x00;
        CommandArray[2] = 0x00;
    }
        break;
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x15:
    case 0x20:
    case 0x0A:
    {
        //贞编码
        CommandArray[1] = char(commandNo>>8);
        CommandArray[2] = char(commandNo);

        if(commandNo >= 65535)
        {
            commandNo = 2;
        }
        else
        {
            commandNo ++;
        }
    }
        break;

    default:
        break;
    }

    return CommandArray;
}

//发送 AGV通信贞
QByteArray agvCar::communication(quint16 targetAddress, quint16 sourceAddress,
                                 QByteArray commandArray)
{
    QByteArray CommunicationArray;
    //起始码
    CommunicationArray[0] = char(0xFC);

    //整贞长度
    CommunicationArray[1] = 0x00;
    CommunicationArray[2] = 0x00;

    //目标地址
    CommunicationArray[3] = char(agvTargetAddress>>8);
    CommunicationArray[4] = char(agvTargetAddress);

    //源地址
    CommunicationArray[5] = 0x00;
    CommunicationArray[6] = 0x00;

    //命令
    CommunicationArray.append(commandArray);

    //整贞长度
    quint16 communicationLength = quint16(CommunicationArray.length() + 3);
    CommunicationArray[1] = char(communicationLength>>8);
    CommunicationArray[2] = char(communicationLength);

    //CRC校验
    quint16 commandCrc = quint16(crc16((unsigned char*)CommunicationArray.constData(),CommunicationArray.size()));

    //CRC高位
    CommunicationArray[commandArray.length() + 7] = char(commandCrc>>8);

    //CRC低位
    CommunicationArray[commandArray.length() + 8] = char(commandCrc);

    //结束码
    CommunicationArray[commandArray.length() + 9] = 0x5A;

    return CommunicationArray;
}

//控制数据范围
quint32 agvCar::controlRange(quint32 initialData, quint32 minData, quint32 maxData)
{
    if((initialData < minData) || (initialData > maxData))
    {
        initialData = 0;
    }
    return initialData;
}

//解析AGV状态数据
void agvCar::analysis(QByteArray AnalysisArray)
{

    if(AnalysisArray.size() >= 10)
    {
        agvStateItem.agvIp = agvIp;
        agvStateItem.isOnline = true;
        agvStateItem.lastTimer=0;
        //当前回复AGV目标地址
        agvTargetAddress = quint16(AnalysisArray[5] <<8|AnalysisArray[6]);

        //当前回复命令码
        agvStateItem.commandState = QString::number(quint16(AnalysisArray[7]));

        if(quint16(AnalysisArray[7]) != 0x02){
            //当前通信贞编码
            agvStateItem.communicationNumberState = QString::number(quint16(AnalysisArray.at(8)<<8|AnalysisArray.at(9)));
        }

        switch (quint16(AnalysisArray[7]))
        {
            case 0x01:
            {
                if(AnalysisArray.size() >= 11){
                    agvStateItem.moveTaskState = quint16(AnalysisArray.at(10));
                    qDebug()<<agvStateItem.agvIp<<"  任务是否成功标识:"<<agvStateItem.moveTaskState;
                }
            }
            break;
        case 0x02:
        case 0x03:
        case 0x04:
        case 0x06:
        case 0x07:
        case 0x08:
        case 0x09:
        case 0x0a:
        {
            if(AnalysisArray.size() >= 47){
                agvStateItem.FarInducedState="";                       //障碍感应注释
                if(quint16(AnalysisArray.at(10)&0x01) == 0x01){        //AGV前面远距离激光感应
                    agvStateItem.isFrontLaserFarInducedState = true;
                }else{
                    agvStateItem.isFrontLaserFarInducedState = false;
                }if(quint16(AnalysisArray.at(10)&0x02) == 0x02) {       //AGV前面近距离激光感应
                    agvStateItem.FarInducedState="前-障碍";
                    agvStateItem.isFrontLaserNearInducedState = true;
                }else{
                    agvStateItem.isFrontLaserNearInducedState = false;
                }

                if(quint16(AnalysisArray.at(10)&0x03) == 0x03){         //AGV后面远距离激光感应
                    agvStateItem.isRearLaserFarInducedState = true;
                }else{
                    agvStateItem.isRearLaserFarInducedState = false;
                }if(quint16(AnalysisArray.at(10)&0x04) == 0x04) {       //AGV后面近距离激光感应
                    agvStateItem.FarInducedState="后-障碍";
                    agvStateItem.isRearLaserNearInducedState = true;
                }else{
                    agvStateItem.isRearLaserNearInducedState = false;
                }

                if(quint16(AnalysisArray.at(10)>>2&0x01) == 0x01){     //AGV前面近距离激光感应
                    agvStateItem.RunStatus = 2; //停止
                }else{
                    agvStateItem.RunStatus = 1; //移动
                }

                if(quint16(AnalysisArray.at(11)&0x01) == 0x01){        //AGV在二维码上标志
                    agvStateItem.isFindQRCodeState = true;
                }else{
                    agvStateItem.isFindQRCodeState = false;
                }

                if(quint16(AnalysisArray.at(11) & 0x02) == 0x01){      //AGV转盘下限位感应
                    agvStateItem.isRotaryLowState = true;
                }else{
                    agvStateItem.isRotaryLowState = false;
                }

                if(quint16(AnalysisArray.at(11) & 0x03) == 0x01){      //AGV转盘上限位感应 1001  0101 0011
                    agvStateItem.isRotaryHighState = true;
                }else{
                    agvStateItem.isRotaryHighState = false;
                }

                if(quint16(AnalysisArray.at(11) & 0x04) == 0x01){      //AGV转盘原点检测状态
                    agvStateItem.isRotaryOriginPointState = true;
                }else{
                    agvStateItem.isRotaryOriginPointState = false;
                }

                if((quint16(AnalysisArray.at(11)>>4) & 0x01) == 0x01){//AGV激光触发停止状态  AGV强制停车   0001 1001
                    agvStateItem.isLaserTriggerStop = true;
                }else{
                    agvStateItem.isLaserTriggerStop = false;
                }

                if(quint16(AnalysisArray.at(11) & 0x80) == 0x01){ //AGV充电回路状态1000 0000
                    agvStateItem.isOpenChargingCircuit = true;//1001
                }else{
                    agvStateItem.isOpenChargingCircuit = false;//0101
                }

                //AGV上次读到的二维码点
                QString passPointState=QString::number(controlRange((quint32(quint8(AnalysisArray.at(12))<<24|quint8(AnalysisArray.at(13))<<16|quint8(AnalysisArray.at(14))<<8|quint8(AnalysisArray.at(15)))),0,99999999));
                if(passPointState.toInt()>0 && agvStateItem.passPointState!=passPointState){
                    agvStateItem.passPointState=passPointState;
                    agvStateItem.ActionItem.waitTimer=QDateTime::currentDateTime();
                }

                //AGV当前点X偏移
                agvStateItem.currentPoint_X_OffsetState = QString::number(controlRange((quint32(quint8(AnalysisArray.at(16))<<8 | quint8(AnalysisArray.at(17)))),quint32(-2000),2000));

                //AGV当前点Y偏移
                agvStateItem.currentPoint_Y_OffsetState = QString::number(controlRange((quint32(AnalysisArray.at(18)<<8|AnalysisArray.at(19))),quint32(-2000),2000));

                //AGV当前姿态角度
                agvStateItem.currentPointAttitudeAngleState = QString::number(controlRange((quint32(quint8(AnalysisArray.at(20))<<8|quint8(AnalysisArray.at(21)))),0,360));

                //AGV当前转盘角度
                agvStateItem.currentPointRotaryAngleState = QString::number(controlRange((quint16(AnalysisArray.at(22)<<8|AnalysisArray.at(23))),0,360));

                //AGV当前移动角度
                agvStateItem.currentPointMoveAngleState = QString::number(controlRange((quint16(AnalysisArray.at(24)<<8|AnalysisArray.at(25))),0,360));

                //AGV当前执行任务编号
                agvStateItem.currentTaskNumberState = QString::number(quint16(AnalysisArray.at(26)<<8|AnalysisArray.at(27)));

                //AGV当前任务数
                agvStateItem.currentTaskCountState = QString::number(AnalysisArray.at(28));

                //AGV当前转盘高度
                agvStateItem.currentRotaryHeightState = QString::number(controlRange((quint16 (AnalysisArray.at(29)<<8|AnalysisArray.at(30))),0,100));

                //AGV当前左轮速度/AGV当前前轮速度
                agvStateItem.currentLeftWheelSpeedState = QString::number(controlRange((quint32(AnalysisArray.at(31)<<8|AnalysisArray.at(32))),quint32(-3000),3000));

                //AGV当前右轮速度/AGV当前后轮速度
                agvStateItem.currentRightWheelSpeedState = QString::number(controlRange((quint32(AnalysisArray.at(33)<<8|AnalysisArray.at(34))),quint32(-3000),3000));

                //AGV当前转盘举升速度
                agvStateItem.currentRotaryLiftSpeedState = QString::number(controlRange(quint32(AnalysisArray.at(35)),quint32(-100),100));

                //AGV当前转盘旋转速度
                agvStateItem.currentRotaryRotateSpeedState = QString::number(controlRange(quint32(AnalysisArray.at(36)),quint32(-500),500));

                //AGV当前电池电压值
                //agvStateItem.currentBatteryVoltageState = QString::number(controlRange((quint16(AnalysisArray.at(37)<<8|AnalysisArray.at(38))),0,100000));
                agvStateItem.currentBatteryVoltageState = QString::number(controlRange((quint16(quint8(AnalysisArray.at(37))<<8|quint8(AnalysisArray.at(38)))),0,100000));

                //AGV当前电池电量 %
                //agvStateItem.currentBatteryelectricity = QString::number(controlRange((quint16(AnalysisArray.at(39)<<8|AnalysisArray.at(40))),0,5000000));
                agvStateItem.currentBatteryelectricity =QString::number(controlRange((quint16(quint8(AnalysisArray.at(39))<<8)),0,1000));

                //AGV当前系统电流值
                agvStateItem.currentSystemCurrentState=QString::number(double(AnalysisArray.at(40))*0.1);

                //AGV当前错误代码
                agvStateItem.currentErrorCodeState = QString::number(AnalysisArray.at(41));

                //AGV当前警告代码
                agvStateItem.currentWarningCodeState = QString::number(AnalysisArray.at(42));

                //AGV当前举升货架编号
                agvStateItem.currentLiftingPodNumberState = QString::number(quint16(AnalysisArray.at(43)<<8|AnalysisArray.at(44)));

                //AGV当前完成的动作编号
                agvStateItem.currentCompletedTaskNumberState = QString::number(quint16(AnalysisArray.at(45)<<8|AnalysisArray.at(46)));

                agvStateItem.commandNo=QString::number(commandNo) ;//系统 通信贞编码
                //agvStateItem.commandNo_AGV= QString::number(quint16(AnalysisArray.at(8)<<8|AnalysisArray.at(9)));
                agvStateItem.commandNo_AGV = QString::number(quint16(quint8(AnalysisArray.at(8))<<8|quint8(AnalysisArray.at(9))));

                int currentTaskCountState=agvStateItem.currentTaskCountState.toInt();   //AGV当前剩余任务数
                if(agvStateItem.currentErrorCodeState.toInt()==0){                      //AGV当前错误代码
                    agvStateItem.FinishInitcount++;
                    if(agvStateItem.FinishInitcount>5 && currentTaskCountState==0){
                        agvStateItem.FinishInit=true;                                   //AGV初始化完成
                    }if(agvStateItem.FinishInitcount>10000){
                        agvStateItem.FinishInitcount=0;
                    }
                }else {
                    unusualcount--;
                    if(unusualcount<=0){
                        unusualcount=30;
                        setAGVORderInit();                                              //AGV 异常时参数初始化
                        sendAGVORderCommand(100);                                       //发送 AGV (初始化命令/同步帧编码) 函数
                    }
                    return;
                }

                if(agvStateItem.FinishInit){
                    if(SendSubTaskcount>0){SendSubTaskcount--;}
                    if(currentRotaryHeightState==3 && agvStateItem.currentRotaryHeightState.toInt()<47){
                        agvStateItem.FinishInitcount=0;
                        agvStateItem.RotaryHeightStatecount++;
                        if(agvStateItem.RotaryHeightStatecount>20){
                           agvStateItem.RotaryHeightStatecount=0;
                           qDebug()<<"当前托盘状态异常  确保举升:"<<agvStateItem.passPointState.toInt();
                           agvORderTask agvORderTaskI;
                           emit AGVMoveTask(0,quint32(agvStateItem.passPointState.toInt()),3,0,agvORderTaskI);
                        }
                        return;
                    }

                    if(currentRotaryHeightState==4 && agvStateItem.currentRotaryHeightState.toInt()>3){
                        agvStateItem.FinishInitcount=0;
                        agvStateItem.RotaryHeightStatecount++;
                        if(agvStateItem.RotaryHeightStatecount>20){
                           agvStateItem.RotaryHeightStatecount=0;
                           qDebug()<<"当前托盘状态异常  确保降下 :"<<agvStateItem.passPointState.toInt();
                           agvORderTask agvORderTaskI;
                           emit AGVMoveTask(0,quint32(agvStateItem.passPointState.toInt()),4,0,agvORderTaskI);
                        }
                        return;
                    }

                    /**************** 到达目标二维码 ************/
                    if(agvStateItem.ActionItem.CurrentDestpoint==agvStateItem.passPointState.toInt()
                            && agvStateItem.ActionItem.CurrentDestpoint!=0){
                        agvStateItem.ActionItem.CurrentDestpoint=0;
                        agvStateItem.ActionItem.RunPointList.clear(); //退出管制链表
                    }

                    if(agvStateItem.ActionItem.CurrentDestpoint!=0){
                        qint64 taskminutes = agvStateItem.ActionItem.waitTimer.secsTo(QDateTime::currentDateTime());      //状态更新时间
                        if(taskminutes%2==1){
                            //实时触发 移动任务指令  判断当前二维码移动指令是否可以执行
                            setTaskmoveList_Process(agvStateItem.passPointState.toInt(),agvStateItem.currentTaskCountState.toInt());
                        }else{
                            if(agvStateItem.ActionItem.waitFlag){
                               if(taskminutes>15){
                                    agvORderTask agvORderTaskI;
                                    agvStateItem.ActionItem.waitFlag=false;
                                    agvStateItem.ActionItem.waitTimer=QDateTime::currentDateTime();
                                    emit AGVMoveTask(0,quint32(agvStateItem.ActionItem.CurrentDestpoint),1,0,agvORderTaskI);
                                    qDebug()<<"在某一位置停留过久 重新触发-->agvIp:"<<agvStateItem.agvIp<<" CurrentDestpoint:"<<agvStateItem.ActionItem.CurrentDestpoint;
                                }
                            }else{
                                if(agvStateItem.ActionItem.CurrentDestpoint!=agvStateItem.passPointState.toInt()
                                        && currentTaskCountState==0 && taskminutes>15){
                                    agvStateItem.ActionItem.waitFlag=true;
                                    agvStateItem.ActionItem.waitTimer=QDateTime::currentDateTime();

                                }
                            }
                        }
                    }

                }

            }
        }
            break;
        case 0x05:
        {

        }
            break;
        default:
            break;
        }
    }

}

//AGV原地旋转
agvSubTask agvCar::agvPivotTask(quint32 PivotPoint, quint16 moveAnage)
{
    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.Point = PivotPoint;
    agvSubTaskItemTemp.NextPoint = PivotPoint;
    agvSubTaskItemTemp.NextPointDistance = 1000;
    agvSubTaskItemTemp.AGVSpeed = 30;
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = 2;
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = 2;
    agvSubTaskItemTemp.AGVMoveAnage = moveAnage;
    agvSubTaskItemTemp.AGVRotaryAngle = 0;

    agvSubTaskItemTemp.SubTaskType = 1;

    return agvSubTaskItemTemp;
}

//AGV举升顶盘
QList<agvSubTask> agvCar::agvRotateUpTask(quint32 UpPoint)
{
    QList<agvSubTask> agvSubTaskListTemp;

    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.Point = UpPoint;
    agvSubTaskItemTemp.NextPoint = UpPoint;
    agvSubTaskItemTemp.NextPointDistance = 1000;
    agvSubTaskItemTemp.AGVSpeed = 60;
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = 2;
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = 2;
    agvSubTaskItemTemp.AGVMoveAnage = 0;
    agvSubTaskItemTemp.AGVRotaryAngle = 0;
    agvSubTaskItemTemp.SubTaskType = 3;
    agvSubTaskListTemp.append(agvSubTaskItemTemp);

    return agvSubTaskListTemp;
}

//AGV降下顶盘
QList<agvSubTask> agvCar::agvRotateDownTask(quint32 DownPoint)
{
    QList<agvSubTask> agvSubTaskListTemp;

    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.Point = DownPoint;
    agvSubTaskItemTemp.NextPoint = DownPoint;
    agvSubTaskItemTemp.NextPointDistance = 1000;
    agvSubTaskItemTemp.AGVSpeed = 60;
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = 2;
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = 2;
    agvSubTaskItemTemp.AGVMoveAnage = 0;
    agvSubTaskItemTemp.AGVRotaryAngle = 0;
    agvSubTaskItemTemp.SubTaskType = 4;
    agvSubTaskListTemp.append(agvSubTaskItemTemp);

    return agvSubTaskListTemp;
}

QList<agvSubTask> agvCar::agvORderTaskTask(quint32 DownPoint, agvORderTask agvORderTaskI)
{
    QList<agvSubTask> agvSubTaskListTemp;

    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.Point = DownPoint;
    agvSubTaskItemTemp.NextPoint = DownPoint;
    agvSubTaskItemTemp.NextPointDistance = 1000;
    agvSubTaskItemTemp.AGVSpeed = 60;
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = 2;
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = 2;
    agvSubTaskItemTemp.AGVMoveAnage = 0;
    agvSubTaskItemTemp.AGVRotaryAngle = 0;
    agvSubTaskItemTemp.SubTaskType = 7;             //夹抱 AGV 动作基本任务

    agvSubTaskItemTemp.agvORderTaskI=agvORderTaskI;//夹抱 AGV 动作基本任务

    agvSubTaskListTemp.append(agvSubTaskItemTemp);

    return agvSubTaskListTemp;
}

//任务路径转换为任务通信贞   agvAction:执行动作(1.移动动作/2.避让动作/3.举升动作/4.降下动作/5.清除动作/6.停止动作)
QByteArray agvCar::setAgvSubTask(agvSubTask agvSubTaskI)
{
    QByteArray agvSubTaskArray;
    if(agvSubTaskI.TaskId >0  || agvSubTaskI.SubTaskType!=1)
    {
        switch (agvSubTaskI.SubTaskType)
        {
        case 1:
        {
            quint8 RotaryBarrierInstruction;
            if(agvStateItem.isRotaryLowState){
                RotaryBarrierInstruction=agvSubTaskI.RotaryLowBarrierInstruction;
            }else{
                RotaryBarrierInstruction=agvSubTaskI.RotaryHighBarrierInstruction;
            }
            agvSubTaskArray = assignment_move(0x01,agvSubTaskI.Point,agvSubTaskI.NextPoint,
                                         agvSubTaskI.NextPointDistance,agvSubTaskI.AGVSpeed,
                                         RotaryBarrierInstruction,agvSubTaskI.postureAngle,
                                         agvSubTaskI.AGVMoveAnage,agvSubTaskI.AGVRotaryAngle);

            qDebug()<<" TaskId:"<<agvSubTaskI.TaskId<<" Point:"<<agvSubTaskI.Point<<" NextPoint:"<<agvSubTaskI.NextPoint
                   <<" 距离:"<<agvSubTaskI.NextPointDistance<<" AGVSpeed:"<<agvSubTaskI.AGVSpeed
                  <<" 激光方案:"<<RotaryBarrierInstruction<<" 姿态角度:"<<agvSubTaskI.postureAngle
                 <<" 移动角度:"<<agvSubTaskI.AGVMoveAnage<<" 转盘角度:"<<agvSubTaskI.AGVRotaryAngle
                <<" 当前姿态角度:"<<agvStateItem.currentPointAttitudeAngleState
                <<"RouteName:"<<agvSubTaskI.RouteName;

        }
            break;
        case 3:{
            agvSubTaskArray = assignment_tray(0x03,agvSubTaskI.Point);//举升
        }
            break;
        case 4: {
            agvSubTaskArray = assignment_tray(0x04,agvSubTaskI.Point);//下降
        }
            break;

        case 7:{
            //发送 AGV 夹抱机器人取放货 动作 指令
            qDebug()<<"发送 AGV 夹抱机器人取放货 动作 指令";
            agvSubTaskArray = assignment_control(0x07,agvSubTaskI.Point,agvSubTaskI.agvORderTaskI);//下降
        }
            break;
        default:
            break;
        }
    }

    return agvSubTaskArray;
}

void agvCar::setAgvSendRepairSubTaskList()
{
    if(!agvSubTaskList_Map.isEmpty()){
        QList<QByteArray > agvMoveAssignment;              //AGV多条移动任务
        foreach(agvSubTask iter,agvSubTaskList_Map.values())
        {
            QByteArray agvSubTaskArray;
            agvSubTaskArray=setAgvSubTask(iter);
            if(agvSubTaskArray.size()>10){
                agvMoveAssignment.append(agvSubTaskArray);
            }
        }

        if(agvMoveAssignment.size()>0){
            agvRepairSubTask agvRepairSubTaskI;
            agvRepairSubTaskI.actionType=1;
            agvRepairSubTaskI.commandId=commandNo;
            agvRepairSubTaskI.agvSubTaskArray=communication(0x00,0x00,command_order(0x01,agvMoveAssignment));
            agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
            //qDebug()<<"SendSubTask----->  系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
        }

        agvSubTaskList_Map.clear();
    }

}

//从AGV接收数据 槽函数
void agvCar::onReadyRead()
{
    if(!agvCarSocketItemMap.isEmpty()){
        if(agvCarSocketItemMap.lastKey()->state()==QAbstractSocket::ConnectedState){
            if(agvCarSocketItemMap.lastKey()->bytesAvailable()){
                QByteArray ReadArray = agvCarSocketItemMap.lastKey()->readAll();
                //qDebug()<<"AGV状态返回--->:"<<ReadArray.size()<<ReadArray.toHex();
                if(ReadArray[0] == char(0xFC) && ReadArray.size() >= 10){
                    int ReadArrayLength = quint16(ReadArray[1]<<8) |quint16(ReadArray.at(2));
                    if(ReadArray.size() >= ReadArrayLength && ReadArrayLength>0){
                        if(quint16(ReadArray.at(ReadArrayLength - 1)) == 0x5A){
                            agvReadAllTaskList.append(ReadArray.left(ReadArrayLength));
                            ReadArray.remove(0,ReadArrayLength);
                        }
                    }
                }
            }
        }
    }
}


//定时编译AGV任务
void agvCar::onAddAGVTaskTimerOut()
{
    if(agvSendSubTask_query.isEmpty()){
        agvSendSubTask_query=communication(0x0000,0x0000,command_other(0x02));
        qDebug()<<"agvSendSubTask_query:"<<agvSendSubTask_query.toHex();
    }

    agvStateItem.lastTimer++;
    if(agvStateItem.lastTimer>50){
        agvStateItem.lastTimer=110;
        agvStateItem.isOnline = false;
        agvStateItem.FinishInitcount=0;
    }
}


//定时发送给AGV任务
void agvCar::onSendAGVTaskTimerOut()
{
    agvSendSubTaskcount++;
    if(agvSendSubTaskcount>=10000){agvSendSubTaskcount=0;}
    if(!agvCarSocketItemMap.isEmpty()){
        if(agvCarSocketItemMap.lastKey()->state()==QAbstractSocket::ConnectedState){
            if(!agvSendSubTask_query.isEmpty() && agvSendSubTaskcount%2==0){
                agvCarSocketItemMap.lastKey()->write(agvSendSubTask_query,agvSendSubTask_query.size());
                //qDebug()<<"AGV查询--->:"<<agvSendSubTask_query.size()<<agvSendSubTask_query.toHex();
                return;
            }if(!agvSendSubTask_action.isEmpty() && agvSendSubTaskcount%2==1
                    && SendSubTaskcount==0){
                SendSubTaskcount=3;
                agvCarSocketItemMap.lastKey()->write(agvSendSubTask_action.first().agvSubTaskArray);
                agvCarSocketItemMap.lastKey()->flush();
                qDebug()<<"系统帧编码:"<<commandNo<<" -- send  write---> "<<agvSendSubTask_action.first().agvSubTaskArray.toHex();
                agvSendSubTask_action.remove(agvSendSubTask_action.firstKey());
                return;
            }
        }
    }
}

//定时读取从AGV接收任务
void agvCar::onReadAGVTaskTimerOut()
{
    if(!agvReadAllTaskList.isEmpty()){
        //qDebug()<<"定时读取从AGV接收任务--Read:"<<agvIp<<agvReadAllTaskList.first().toHex();
        analysis(agvReadAllTaskList.first());
        agvReadAllTaskList.removeFirst();
    }else{

    }

}

//分配AGV任务 槽函数
void agvCar::onAGVMoveTask(quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction, int chargetye, agvORderTask agvORderTaskI)
{

    qDebug()<<"new onAGVMoveTask ---->agvIp:"<<agvIp<<" StartQRPoint:"<<StartQRPoint
           <<" EndQRPoint:"<<EndQRPoint<<" AGVAction:"<<AGVAction<<" FinishInit:" <<agvStateItem.FinishInit<<agvStateItem.passPointState;

    if(agvStateItem.passPointState.toInt()>0){
        StartQRPoint=quint32(agvStateItem.passPointState.toInt());
    }

    if((agvStateItem.FinishInit || agvStateItem.ActionItem.CurrentDestpoint!=int(EndQRPoint))){

        if(AGVAction==1 && StartQRPoint!=EndQRPoint){
            setAGVMoveinit();
            agvStateItem.ActionItem.CurrentDestpoint=int(EndQRPoint);
            agvStateItem.ActionItem.ChargeAction = chargetye;           //充电任务锁定(0.充电任务无锁定，1.充电任务锁定)

            quint32 Point_S=0; quint32 Point_E=0;
            QMap<int,agvSubTask > agvSubTaskMap_S;      //离开起始站点 二维码缓存链表
            QMap<int,agvSubTask > mainAgvSubTaskMap;    //当前所有路线 二维码缓存链表
            QMap<int,agvSubTask > agvSubTaskMap_E;      //进入终点站点 二维码缓存链表

            //获取站点内: Point 对应的 辅路线与对接点 Type--> 0 起点  1 终点
            mianRoute mianRouteI_S= AGV_Single::GetInstance()->getRouteInfo_In(StartQRPoint,0);
            mianRoute mianRouteI_E= AGV_Single::GetInstance()->getRouteInfo_In(EndQRPoint,1);
            if(mianRouteI_S.RouteName!=""){     //起点 在站点内
                Point_S=quint32(mianRouteI_S.Point_S);
            }else{
                Point_S=StartQRPoint;
            }if(mianRouteI_E.RouteName!=""){    //终点 在站点内
                Point_E=quint32(mianRouteI_E.Point_E);
            }else{
                Point_E=EndQRPoint;
            }

            AGV_Single::GetInstance()->setAGV_SingleInit(); //设置参数初始化函数
            if(mianRouteI_S.StationName==mianRouteI_E.StationName && mianRouteI_E.RouteName!=""){
                mainAgvSubTaskMap=AGV_Single::GetInstance()->getMianRouteInfo_out(quint32(StartQRPoint),quint32(EndQRPoint),mianRouteI_S.StationName);
                qDebug()<<"起点与终点均在站点内 Point 的路线规划:"<<mainAgvSubTaskMap.size()<<agvSubTaskmoveMap.size();
            }else{
                if(mianRouteI_S.RouteName!=""){                 //起点 在站点内 ---获取当前站点内路线信息Type :0->s  -1 ->e
                    agvSubTaskMap_S=AGV_Single::GetInstance()->getMianRouteInfo_In(StartQRPoint,quint32(mianRouteI_S.Point_S),mianRouteI_S.StationName,0);
                    qDebug()<<"起点在站点内 ---获取当前站点内路线信息:"<<agvSubTaskMap_S.size()<<agvSubTaskmoveMap.size();
                }if(Point_S!=0 && Point_E!=0){                  //获取站点外: 任意两点 Point 的路线规划
                    mainAgvSubTaskMap=AGV_Single::GetInstance()->getRouteInfo_out(int(Point_S),int(Point_E),0);
                    qDebug()<<"获取站点外: 任意两点 Point 的路线规划:"<<mainAgvSubTaskMap.size()<<agvSubTaskmoveMap.size();
                }if(mianRouteI_E.RouteName!=""){                //终点 在站点内 ---获取当前站点内路线信息Type :0->s  -1 ->e
                    agvSubTaskMap_E=AGV_Single::GetInstance()->getMianRouteInfo_In(quint32(mianRouteI_E.Point_E),EndQRPoint,mianRouteI_E.StationName,-1);
                     qDebug()<<"终点在站点内 ---获取当前站点内路线信息:"<<agvSubTaskMap_E.size()<<agvSubTaskmoveMap.size();
                }
            }
            agvSubTaskmoveMap=AGV_Single::GetInstance()->getAgvSubTaskmoveMap();//获取当前运行路线 AGV二维码任务链表
        }

        //动作指令: 0x03 托盘上升
        if(AGVAction==3){
            currentRotaryHeightState=3;
            agvStateItem.RotaryHeightStatecount=0;
            QList<QByteArray > agvMoveAssignment;
            QList<agvSubTask > agvSubTaskList=agvRotateUpTask(quint32(agvStateItem.passPointState.toInt()));
            if(!agvSubTaskList.isEmpty()){
                QByteArray agvSubTaskArray;
                agvSubTaskList.first().SubTaskType=3;
                agvSubTaskArray=setAgvSubTask(agvSubTaskList.first());
                if(agvSubTaskArray.size()>10){
                    agvMoveAssignment.append(agvSubTaskArray);
                    agvRepairSubTask agvRepairSubTaskI;
                    agvRepairSubTaskI.actionType=3;
                    agvRepairSubTaskI.commandId=commandNo;
                    agvRepairSubTaskI.agvSubTaskArray=communication(0x00,0x00,command_order(0x01,agvMoveAssignment));
                    agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
                    qDebug()<<" 动作指令: 0x03 托盘上升 系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
                }
            }
        }

        //动作指令: 0x04  托盘下降
        if(AGVAction==4){
            currentRotaryHeightState=4;
            agvStateItem.RotaryHeightStatecount=0;
            QList<QByteArray > agvMoveAssignment;
            QList<agvSubTask > agvSubTaskList=agvRotateDownTask(quint32(agvStateItem.passPointState.toInt()));
            if(!agvSubTaskList.isEmpty()){
                QByteArray agvSubTaskArray;
                agvSubTaskList.first().SubTaskType=4;
                agvSubTaskArray=setAgvSubTask(agvSubTaskList.first());
                if(agvSubTaskArray.size()>10){
                    agvMoveAssignment.append(agvSubTaskArray);
                    agvRepairSubTask agvRepairSubTaskI;
                    agvRepairSubTaskI.actionType=4;
                    agvRepairSubTaskI.commandId=commandNo;
                    agvRepairSubTaskI.agvSubTaskArray=communication(0x00,0x00,command_order(0x01,agvMoveAssignment));
                    agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
                    qDebug()<<" 动作指令: 0x04  托盘下降 系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
                }
            }
        }

        //发送 AGV 夹抱机器人取放货 动作 指令  assignmentId
        if(AGVAction==7  && agvStateItem.FinishInit){
            QList<QByteArray > agvMoveAssignment;
            QList<agvSubTask > agvSubTaskList=agvORderTaskTask(quint32(agvStateItem.passPointState.toInt()),agvORderTaskI);
            if(!agvSubTaskList.isEmpty()){//夹抱 AGV 动作基本任务
                QByteArray agvSubTaskArray;
                agvSubTaskList.first().SubTaskType=7;
                agvSubTaskArray=setAgvSubTask(agvSubTaskList.first());
                if(agvSubTaskArray.size()>10){
                    agvMoveAssignment.append(agvSubTaskArray);
                    agvRepairSubTask agvRepairSubTaskI;
                    agvRepairSubTaskI.actionType=7;
                    agvRepairSubTaskI.commandId=commandNo;
                    agvRepairSubTaskI.agvSubTaskArray=communication(0x00,0x00,command_order(0x01,agvMoveAssignment));
                    agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
                    qDebug()<<" 动作指令: 0x07 系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
                }
            }
        }

    }else {
        qDebug()<<"动作指令异常 ---->agvIp:"<<agvIp<<" StartQRPoint:"<<StartQRPoint<<" EndQRPoint:"<<EndQRPoint
               <<" AGVAction:"<<AGVAction<<" FinishInit:"<<agvStateItem.FinishInit<<agvStateItem.FinishInitcount;
    }

    if(AGVAction==10 || AGVAction==11){//打开关闭充电回路
        emit AGVChargeTask(agvIp,quint16(AGVAction));
    }

    if(AGVAction==100){
        setAGVMoveinit();                   //设置 AGV动态参数初始化
        sendAGVORderCommand(AGVAction);     //发送 AGV (初始化命令/同步帧编码) 函数
    }

}

void agvCar::ONUPdataTimer_Widget()
{
   if(agvStateItem.agvIp!=""){
       emit AgvStateWidget(agvStateItem);
   }
}

void agvCar::ON_AGVChargeTask(QString AGVIP, quint16 opendcharge)
{
    agvRepairSubTask agvRepairSubTaskI;
    agvRepairSubTaskI.actionType=20;
    agvRepairSubTaskI.commandId=commandNo;
    agvRepairSubTaskI.agvSubTaskArray=communication(0x0000,0x0000,command_other(quint8(opendcharge)));
    agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
    qDebug()<<"打开AGV 充电回路 系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
    qDebug()<<agvIp<<"-----"<<AGVIP<<"打开AGV 充电回路:-->opendcharge:"<<opendcharge;
}

//设置 AGV动态参数初始化
void agvCar::setAGVMoveinit()
{
    agvSubTaskmoveMap.clear();
    agvSendSubTask_action.clear();                                  //当前正在发送给AGV任务列表
    agvStateItem.ActionItem.RunPointList.clear();                   //正在执行的二维码 缓存链表  taskId-Point
    agvStateItem.ActionItem.CurrentDestpoint=0;                     //当前目标二维码
    agvStateItem.ActionItem.waitTimer=QDateTime::currentDateTime(); //某个时间点停留时间计时

}

//AGV 异常时参数初始化
void agvCar::setAGVORderInit()
{
    agvStateItem.FinishInit=false;
    agvStateItem.FinishInitcount=0;
}

void agvCar::sendAGVORderCommand(int AGVAction)
{
    agvRepairSubTask agvRepairSubTaskI;             //待发送通信贞
    if(AGVAction==100){//初始化命令
        agvRepairSubTaskI.actionType=4;
        agvRepairSubTaskI.commandId=commandNo;
        agvRepairSubTaskI.agvSubTaskArray=communication(0x0000,0x0000,command_other(0x04));
        agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
        qDebug()<<"初始化命令---->: 0x04  系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
    }
}


void agvCar::setTaskmoveList_Process(int passPointState,int currentTaskCount)
{
    if(!agvSubTaskmoveMap.isEmpty() && Taskmove_Processbool){
        Taskmove_Processbool=false;
        int passTaskId=0;int MaxTaskId=0;                                   //当前已发送 的最大编号 数据
        foreach(agvSubTask iter,agvSubTaskmoveMap.values())
        {
            if(iter.Point ==quint32(passPointState)){
                passTaskId=iter.TaskId;
            }if(iter.complete=="1" && MaxTaskId <= iter.TaskId){//complete="0"   0 待执行， 1在执行 2 已经过
                MaxTaskId=iter.TaskId;
            }
        }

        QMap<int,agvSubTask> TaskmoveList;
        currentTaskCount=MaxTaskId-passTaskId;
        if(currentTaskCount<=10){
            foreach(agvSubTask iter,agvSubTaskmoveMap.values())
            {
                if(iter.TaskId>MaxTaskId && TaskmoveList.size()<=8){
                    if(!TaskmoveList.contains(iter.TaskId)){
                        TaskmoveList.insert(iter.TaskId,iter);
//                        qDebug()<<"TaskmoveList-->TaskId:"<<iter.TaskId<<" Point:"<<iter.Point <<" NextPoint:"<<iter.NextPoint<<" 当前二维码:"<<passPointState
//                              <<" MaxTaskId:"<<MaxTaskId<<" passTaskId:"<<passTaskId<<" 剩余任务数:"<<currentTaskCount;
                    }
                }
            }
        }

        if(!TaskmoveList.isEmpty()){
            TaskmoveList_Process_(TaskmoveList,passTaskId);
        }
        Taskmove_Processbool=true;
    }

}

void agvCar::TaskmoveList_Process_(QMap<int,agvSubTask> TaskmoveList,int passTaskId)
{
    if(!TaskmoveList.isEmpty()){
        //AGV子任务列表 -- 运行的二维码任务链表  (0 待执行， 1在执行 2 已经过)
        QMap<int,agvSubTask >::iterator iter_= agvSubTaskmoveMap.begin();
        while (iter_!=agvSubTaskmoveMap.end()){
            if(iter_.key()!=NULL){
                if(iter_.value().complete=="1" && passTaskId<iter_.value().TaskId && passTaskId!=0){
                    iter_.value().complete="2";
                }if(TaskmoveList.contains(iter_.value().TaskId)){
                    iter_.value().complete="1";
                    agvSubTaskList_Map.insert(iter_.value().TaskId,iter_.value());
                }
            }else{
                return;
            }
            iter_++;
        }
    }

    if(!agvSubTaskList_Map.isEmpty()){
        setAgvSendRepairSubTaskList(); //把子任务链表 转换为待发数据
    }
}


