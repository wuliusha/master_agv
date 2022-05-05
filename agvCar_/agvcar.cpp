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
    connect(this,&agvCar::sendpreciseCommand,this,&agvCar::ON_sendpreciseCommand);//设置小车精准定位
    connect(this,&agvCar::sendInitializeCommand,this,&agvCar::onSendInitializeCommand);

    void sendpreciseCommand();
    connect(this,&agvCar::sigTaskmoveList_Process,this,&agvCar::ON_TaskmoveList_Process);

    UPdataTimer = new QTimer(this);
    connect(UPdataTimer, SIGNAL(timeout()), this, SLOT(ONUPdataTimer_Widget()));
    UPdataTimer->start(1500);

}

agvCar::~agvCar()
{
    qDebug()<<"~agvCarNew";
}

//发送 AGV移动任务 任务表
QByteArray agvCar::assignment_move(quint8 assignmentId, quint32 assignmentStartPoint,
                              quint32 assignmentEndPoint, quint16 assignmentNextPointDistance,
                              quint8 assignmentAGVSpeed, quint8 assignmentBarrierInstruction,
                              quint16 assignmentAGVAttitudeAngle, quint16 assignmentAGVMoveAnage,
                              quint16 assignmentAGVRotaryAngle)
{

    QByteArray AssignmentArray;

    //任务标识
    AssignmentArray[0] = assignmentId;
    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;
    //导航方式
    AssignmentArray[3] = 0x02;
    //起始站点编号
    AssignmentArray[4] = char(assignmentStartPoint>>24);
    AssignmentArray[5] = char(assignmentStartPoint>>16);
    AssignmentArray[6] = char(assignmentStartPoint>>8);
    AssignmentArray[7] = char(assignmentStartPoint);
    //到达下一站点编号
    AssignmentArray[8] = char(assignmentEndPoint>>24);
    AssignmentArray[9] = char(assignmentEndPoint>>16);
    AssignmentArray[10] = char(assignmentEndPoint>>8);
    AssignmentArray[11] = char(assignmentEndPoint);
    //起始站点性质
    AssignmentArray[12] = 0x02;

    //到达站点性质
    AssignmentArray[13] = 0x02;
    //到达下一站点距离
    AssignmentArray[14] = char(assignmentNextPointDistance>>8);
    AssignmentArray[15] = char(assignmentNextPointDistance);

    //AGV运行速度
    AssignmentArray[16] = char(assignmentAGVSpeed);

    //障碍指令
    AssignmentArray[17] = char(assignmentBarrierInstruction);

    //小车姿态角度
    AssignmentArray[18] = char(assignmentAGVAttitudeAngle>>8);
    AssignmentArray[19] = char(assignmentAGVAttitudeAngle);

    //小车移动角度
    AssignmentArray[20] = char(assignmentAGVMoveAnage>>8);
    AssignmentArray[21] = char(assignmentAGVMoveAnage);

    //小车转盘角度
    AssignmentArray[22] = char(assignmentAGVRotaryAngle>>8);
    AssignmentArray[23] = char(assignmentAGVRotaryAngle);

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
    if(assignmentNo >= 65535)
    {
        assignmentNo = 1;
    }
    else
    {
        assignmentNo ++;
    }
//        qDebug()<<"AssignmentArray_move";
//        qDebug()<<AssignmentArray.toHex();
    qDebug()<<"任务序号 AssignmentCrc:"<<AssignmentCrc;
    return AssignmentArray;
}

QByteArray agvCar::assignment_move_(quint8 assignmentId, quint32 assignmentStartPoint, quint32 assignmentEndPoint, quint16 assignmentNextPointDistance, quint8 assignmentAGVSpeed, quint8 assignmentBarrierInstruction, quint16 assignmentAGVAttitudeAngle, quint16 assignmentAGVMoveAnage, quint16 assignmentAGVRotaryAngle)
{
    QByteArray AssignmentArray;

    //任务标识
    AssignmentArray[0] = assignmentId;
    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;
    //导航方式
    AssignmentArray[3] = 0x01;//磁导航
    //起始站点编号
    AssignmentArray[4] = char(assignmentStartPoint>>24);
    AssignmentArray[5] = char(assignmentStartPoint>>16);
    AssignmentArray[6] = char(assignmentStartPoint>>8);
    AssignmentArray[7] = char(assignmentStartPoint);
    //到达下一站点编号
    AssignmentArray[8] = char(assignmentEndPoint>>24);
    AssignmentArray[9] = char(assignmentEndPoint>>16);
    AssignmentArray[10] = char(assignmentEndPoint>>8);
    AssignmentArray[11] = char(assignmentEndPoint);
    //起始站点性质
    AssignmentArray[12] = 0x02;

    //到达站点性质
    AssignmentArray[13] = 0x02;
    //到达下一站点距离
    AssignmentArray[14] = char(assignmentNextPointDistance>>8);
    AssignmentArray[15] = char(assignmentNextPointDistance);

    //AGV运行速度
    AssignmentArray[16] = char(assignmentAGVSpeed);

    //障碍指令
    AssignmentArray[17] = char(assignmentBarrierInstruction);

    //小车姿态角度
    AssignmentArray[18] = char(assignmentAGVAttitudeAngle>>8);
    AssignmentArray[19] = char(assignmentAGVAttitudeAngle);

    //小车移动角度
    AssignmentArray[20] = char(assignmentAGVMoveAnage>>8);
    AssignmentArray[21] = char(assignmentAGVMoveAnage);

    //小车转盘角度
    AssignmentArray[22] = char(assignmentAGVRotaryAngle>>8);
    AssignmentArray[23] = char(assignmentAGVRotaryAngle);

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
    if(assignmentNo >= 65535)
    {
        assignmentNo = 1;
    }
    else
    {
        assignmentNo ++;
    }
//        qDebug()<<"AssignmentArray_move";
//        qDebug()<<AssignmentArray.toHex();
    qDebug()<<"磁导航-->任务序号 AssignmentCrc:"<<AssignmentCrc;
    return AssignmentArray;

}


//发送 AGV举升降下托盘任务 任务表
QByteArray agvCar::assignment_L(quint8 assignmentId, quint32 assignmentExecutePoint)
{
    qDebug()<<"  id="<<assignmentId<<"  AGV举升降下托盘任务 ="<<QString::number(assignmentExecutePoint)<<assignmentExecutePoint;

    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(assignmentId);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(assignmentExecutePoint>>24);
    AssignmentArray[5] = char(assignmentExecutePoint>>16);
    AssignmentArray[6] = char(assignmentExecutePoint>>8);
    AssignmentArray[7] = char(assignmentExecutePoint);

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
    }
    else
    {
        assignmentNo ++;
    }
    qDebug()<<"AssignmentArray  AGV举升降下托盘任务";
    qDebug()<<AssignmentArray.toHex();

    return AssignmentArray;
}

QByteArray agvCar::assignment_control(quint8 assignmentId, quint32 assignmentExecutePoint, agvORderTask agvORderTaskI)
{

    //发送 AGV 夹抱机器人取放货 动作 指令  任务标识 assignmentId

    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(assignmentId);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(assignmentExecutePoint>>24);
    AssignmentArray[5] = char(assignmentExecutePoint>>16);
    AssignmentArray[6] = char(assignmentExecutePoint>>8);
    AssignmentArray[7] = char(assignmentExecutePoint);


    AssignmentArray[8] = 0x00;        //姿态角度 (暂定0)
    AssignmentArray[9] = 0x00;        //姿态角度 (暂定0)

    AssignmentArray[10] = 0x00;        //顶盘角度 (暂定0)
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

    qDebug()<<"夹抱机器人动作指令-->  id:"<<assignmentId<<" 精准定位:"<<agvORderTaskI.comparePosition
           <<"从**上取料框:"<<agvORderTaskI.actionORder<<" 货架在左/右"<<agvORderTaskI.actionDirection
          <<" 货架层数:"<<agvORderTaskI.storageRack<<" 小车层数:"<<agvORderTaskI.AGVRack
         <<"任务序号:"<<AssignmentArray[1]<<AssignmentArray[2];

    qDebug()<<"取放货任务序号: "<<AssignmentCrc<<"   AssignmentArray:"<<AssignmentArray.toHex();

    return AssignmentArray;
}

//发送 AGV举升到指定高度任务 任务表
QByteArray agvCar::assignment_H(quint8 assignmentId, quint32 assignmentExecutePoint,
                              quint16 assignmentAGVAttitudeAngle, quint16 assignmentAGVRotaryHeight)
{
    QByteArray AssignmentArray;
    //任务标识
    AssignmentArray[0] = char(assignmentId);

    //任务序号
    AssignmentArray[1] = 0x00;
    AssignmentArray[2] = 0x00;

    //导航方式
    AssignmentArray[3] = 0x02;

    //执行站点编号
    AssignmentArray[4] = char(assignmentExecutePoint>>24);
    AssignmentArray[5] = char(assignmentExecutePoint>>16);
    AssignmentArray[6] = char(assignmentExecutePoint>>8);
    AssignmentArray[7] = char(assignmentExecutePoint);

    //小车姿态角度
    AssignmentArray[8] = char(assignmentAGVAttitudeAngle>>8);
    AssignmentArray[9] = char(assignmentAGVAttitudeAngle);

    //小车转盘角度
    AssignmentArray[10] = char(assignmentAGVRotaryHeight>>8);
    AssignmentArray[11] = char(assignmentAGVRotaryHeight);

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
qint32 agvCar::controlRange(qint32 initialData, qint32 minData, qint32 maxData)
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
        agvStateItem.lineEdit_timer=0;
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
            if(AnalysisArray.size() >= 11)
            {
                //AGV运行任务状态回复
                switch (quint16(AnalysisArray.at(10)))
                {
                case 0:
                {
                    agvStateItem.moveTaskState = "成功";
                }
                    break;
                case 1:
                {
                    agvStateItem.moveTaskState = "任务过多失败";
                }
                    break;
                case 2:
                {
                    agvStateItem.moveTaskState = "当前序号已经接收过";
                }
                    break;
                case 3:
                {
                    agvStateItem.moveTaskState = "设置目标参数出错";
                }
                    break;
                case 4:
                {
                    agvStateItem.moveTaskState = "小车当前位置信息无法执行动作任务";
                }
                    break;
                case 5:
                {
                    agvStateItem.moveTaskState = "设置角度不是 0 90 180 270这几个角度";
                }
                    break;
                case 6:
                {
                    agvStateItem.moveTaskState = "任务长度与接收数据不一致";
                }
                    break;
                case 7:
                {
                    agvStateItem.moveTaskState = "原地旋转二维码坐标给定不正确";
                }
                    break;
                case 8:
                {
                    agvStateItem.moveTaskState = "当前小车状态无法执行任务，无法执行任务（故障或者复位中）";
                }
                    break;
                default:
                    break;
                }

                if(!agvSendSubTask_action.isEmpty()){
                    SendSubTaskcount=0;
                    agvSendSubTask_action.remove(agvSendSubTask_action.firstKey());
                }
                qDebug()<<agvStateItem.agvIp<<"  任务是否成功标识:"<<quint16(AnalysisArray.at(10))<<agvStateItem.moveTaskState
                       <<agvSendSubTask_action.size();

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

                if(quint16(AnalysisArray.at(10)&0x01) == 0x01){        //AGV前面远距离激光感应
                    agvStateItem.isFrontLaserFarInducedState = true;
                }else{
                    agvStateItem.isFrontLaserFarInducedState = false;
                }

                if(quint16(AnalysisArray.at(10)&0x02) == 0x02) {       //AGV前面近距离激光感应
                    agvStateItem.isFrontLaserNearInducedState = true;
                }else{
                    agvStateItem.isFrontLaserNearInducedState = false;
                }

                if(quint16(AnalysisArray.at(10)&0x03) == 0x03){         //AGV后面远距离激光感应
                    agvStateItem.isRearLaserFarInducedState = true;
                }else{
                    agvStateItem.isRearLaserFarInducedState = false;
                }

                if(quint16(AnalysisArray.at(10)&0x04) == 0x04) {       //AGV后面近距离激光感应
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
                QString passPointState=QString::number(controlRange(((quint32)((quint8)AnalysisArray.at(12)<<24|(quint8)AnalysisArray.at(13)<<16|(quint8)AnalysisArray.at(14)<<8|(quint8)AnalysisArray.at(15))),0,99999999));
                if(passPointState.toInt()>0 && agvStateItem.passPointState!=passPointState){
                    agvStateItem.passPointState=passPointState;
                    agvStateItem.CurrentDestpointcount=0;
                }

                //AGV当前点X偏移
                agvStateItem.currentPoint_X_OffsetState = QString::number(controlRange((qint16(AnalysisArray.at(16)<<8 | AnalysisArray.at(17))),-2000,2000));

                //AGV当前点Y偏移
                agvStateItem.currentPoint_Y_OffsetState = QString::number(controlRange((qint16(AnalysisArray.at(18)<<8|AnalysisArray.at(19))),-2000,2000));

                //AGV当前姿态角度
                agvStateItem.currentPointAttitudeAngleState = QString::number(controlRange(((quint16)((quint8)AnalysisArray.at(20)<<8|(quint8)AnalysisArray.at(21))),0,360));

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
                agvStateItem.currentLeftWheelSpeedState = QString::number(controlRange((qint16(AnalysisArray.at(31)<<8|AnalysisArray.at(32))),-3000,3000));

                //AGV当前右轮速度/AGV当前后轮速度
                agvStateItem.currentRightWheelSpeedState = QString::number(controlRange((qint16(AnalysisArray.at(33)<<8|AnalysisArray.at(34))),-3000,3000));

                //AGV当前转盘举升速度
                agvStateItem.currentRotaryLiftSpeedState = QString::number(controlRange(AnalysisArray.at(35),-100,100));

                //AGV当前转盘旋转速度
                agvStateItem.currentRotaryRotateSpeedState = QString::number(controlRange(AnalysisArray.at(36),-500,500));

                //AGV当前电池电压值
                //agvStateItem.currentBatteryVoltageState = QString::number(controlRange((quint16(AnalysisArray.at(37)<<8|AnalysisArray.at(38))),0,100000));
                agvStateItem.currentBatteryVoltageState = QString::number(controlRange(((quint16)((quint8)AnalysisArray.at(37)<<8|(quint8)AnalysisArray.at(38))),0,100000));

                //AGV当前系统电流值
                agvStateItem.currentSystemCurrentState = QString::number(controlRange((quint16(AnalysisArray.at(39)<<8|AnalysisArray.at(40))),0,5000000));

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
                agvStateItem.commandNo_AGV = QString::number((quint16)((quint8)AnalysisArray.at(8)<<8|(quint8)AnalysisArray.at(9)));


                int currentTaskCountState=agvStateItem.currentTaskCountState.toInt();
                if(agvStateItem.currentErrorCodeState.toInt()==0){
                    agvStateItem.agvFinishInitcount++;
                    if(agvStateItem.agvFinishInitcount>5 && currentTaskCountState==0){
                        agvStateItem.agvFinishInit=true;
                    }
                    if(agvStateItem.agvFinishInitcount>10000){agvStateItem.agvFinishInitcount=0;}

                }else {
                    unusualcount--;                                 //AGV异常 开始同步帧编码
                    if(unusualcount<=0){
                        unusualcount=30;
                        commandNobool=true;
                        agvSendSubTask_action.clear();
                        agvStateItem.agvFinishInit=false;
                        agvStateItem.agvFinishInitcount=0;
                        agvStateItem.CurrentDestpointcount=0;
                        emit sendInitializeCommand(1004);
                        qDebug()<<"AGV异常 开始同步帧编码-->agvIp:"<<agvStateItem.agvIp<<" CurrentDestpoint:"<<agvStateItem.CurrentDestpoint;
                    }

                }

                if(agvStateItem.agvFinishInit){

                    if(currentRotaryHeightState==3 && agvStateItem.currentRotaryHeightState.toInt()<47){
                        agvStateItem.agvFinishInitcount=0;
                        agvStateItem.currentRotaryHeightStatecount++;
                        if(agvStateItem.currentRotaryHeightStatecount>20){
                           agvStateItem.currentRotaryHeightStatecount=0;
                           qDebug()<<"当前托盘状态异常  确保举升:"<<agvStateItem.passPointState.toInt();
                           agvORderTask agvORderTaskI;
                           emit AGVMoveTask(0,quint32(agvStateItem.passPointState.toInt()),3,0,agvORderTaskI);
                        }
                        return;
                    }

                    if(currentRotaryHeightState==4 && agvStateItem.currentRotaryHeightState.toInt()>3){
                        agvStateItem.agvFinishInitcount=0;
                        agvStateItem.currentRotaryHeightStatecount++;
                        if(agvStateItem.currentRotaryHeightStatecount>20){
                           agvStateItem.currentRotaryHeightStatecount=0;
                           qDebug()<<"当前托盘状态异常  确保降下 :"<<agvStateItem.passPointState.toInt();
                           agvORderTask agvORderTaskI;
                           emit AGVMoveTask(0,quint32(agvStateItem.passPointState.toInt()),4,0,agvORderTaskI);
                        }
                        return;
                    }

                    if(SendSubTaskcount>0){SendSubTaskcount--;}

                    if(commandNobool){
                        commandNobool=false;
                        qDebug()<<agvStateItem.agvIp<<"初始化时 同步前-->系统帧编码:"<<commandNo<<"  小车帧编码:"<<agvStateItem.commandNo_AGV;
                        commandNo=quint16(agvStateItem.commandNo_AGV.toInt())+1;
                        qDebug()<<agvStateItem.agvIp<<"初始化时 同步后---->系统帧编码:"<<commandNo<<"  小车帧编码:"<<agvStateItem.commandNo_AGV;

                        if(agvStateItem.CurrentDestpoint!=0){
                            agvORderTask agvORderTaskI;
                            emit AGVMoveTask(0,quint32(agvStateItem.CurrentDestpoint),1,0,agvORderTaskI);
                            qDebug()<<"在某一位置停留过久 重新触发-->agvIp:"<<agvStateItem.agvIp<<" CurrentDestpoint:"<<agvStateItem.CurrentDestpoint;
                        }
                        return;
                    }

                    if(agvStateItem.CurrentDestpoint!=0 && !commandNobool){
                        //实时触发 移动任务指令  判断当前二维码移动指令是否可以执行
                        emit sigTaskmoveList_Process(agvStateItem.passPointState.toInt());
                    }

                    /**************** 到达目标二维码 ************/
                    if(agvStateItem.CurrentDestpoint==agvStateItem.passPointState.toInt()
                            && agvStateItem.CurrentDestpoint!=0){

                        int AngleState=agvStateItem.currentPointAttitudeAngleState.toInt();
                        if(agvStateItem.CurrentDestpoint==138 && (AngleState>80 && AngleState<100)
                                && agvStateItem.agvFinishInitcount>=5){
                            agvStateItem.CurrentDestpoint=0;
                            agvStateItem.agvFinishInitcount=0;
                            agvORderTask agvORderTaskI;
                            emit AGVMoveTask(0,138,1,0,agvORderTaskI);
                            qDebug()<<"站点调整姿态角度 -->agvIp:"<<agvStateItem.agvIp<<" CurrentDestpoint:"<<agvStateItem.CurrentDestpoint;
                        }else {
                            agvStateItem.PointList.clear(); //退出管制链表
                            agvStateItem.CurrentDestpoint=0;
                            QMap<int,agvSubTask> TaskmoveList;
                            emit TaskmoveListProcess(agvIp,TaskmoveList,agvStateItem,0);
                        }
                    }


                    if(agvStateItem.CurrentDestpoint!=agvStateItem.passPointState.toInt()
                            && agvStateItem.CurrentDestpoint!=0 && currentTaskCountState==0){
                        agvStateItem.CurrentDestpointcount++;
                        bool resetbool=false;
                        if(agvStateItem.doorPoint==0 && agvStateItem.CurrentDestpointcount>=50){
                            resetbool=true;
                        }if(agvStateItem.doorPoint!=0 && agvStateItem.CurrentDestpointcount>=75){
                            resetbool=true;
                        }

                        if(resetbool){
                            commandNobool=true;
                            agvSendSubTask_action.clear();
                            agvStateItem.agvFinishInit=false;
                            agvStateItem.agvFinishInitcount=0;
                            agvStateItem.CurrentDestpointcount=0;
                            emit sendInitializeCommand(1004);
                            qDebug()<<"在某一位置停留过久 开始同步帧编码-->agvIp:"<<agvStateItem.agvIp
                                   <<" doorPoint:"<<agvStateItem.doorPoint<<" count:"<<agvStateItem.CurrentDestpointcount
                                  <<" passPointState:"<<agvStateItem.passPointState.toInt() <<" CurrentDestpoint:"<<agvStateItem.CurrentDestpoint;

                        }

                    }else{
                        agvStateItem.CurrentDestpointcount=0;
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

            if(agvStateItem.AGVChargeAction==1){ //充电任务锁定(0.充电任务无锁定，1.充电任务锁定)
                if(agvSubTaskI.RouteName=="storage1"){
                    int postureAngle=agvStateItem.currentPointAttitudeAngleState.toInt();
                    if((postureAngle>=0 && postureAngle<=10) || (postureAngle>350 && postureAngle<=360)){
                        agvSubTaskI.postureAngle=0;
                    }else{
                        agvSubTaskI.postureAngle=180;
                    }
                }
            }else{
                if(agvSubTaskI.RouteName=="storage1"){
                    quint16 postureAngle=quint16(agvStateItem.currentPointAttitudeAngleState.toInt());
                    if(postureAngle>160 && postureAngle<200){
                        agvSubTaskI.postureAngle=180;
                    }else{
                        agvSubTaskI.postureAngle=0;
                    }
                }
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
            agvSubTaskArray = assignment_L(0x03,agvSubTaskI.Point);//举升
        }
            break;
        case 4: {
            agvSubTaskArray = assignment_L(0x04,agvSubTaskI.Point);//下降
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
        QMap<int,agvSubTask >::iterator iter= agvSubTaskList_Map.begin();
        while (iter!=agvSubTaskList_Map.end()) {
            QByteArray agvSubTaskArray;
            agvSubTaskArray=setAgvSubTask(iter.value());
            if(agvSubTaskArray.size()>10){
                agvMoveAssignment.append(agvSubTaskArray);
            }
            iter++;
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
    if(agvCarSocketItemMap.keys(true).size() > 0 && agvCarSocketItemMap.keys(true).last() != nullptr){
        if(agvCarSocketItemMap.keys(true).last()->bytesAvailable()){
            QByteArray ReadArray = agvCarSocketItemMap.keys(true).last()->readAll();
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

//发送AGV初始化命令 槽函数
void agvCar::onSendInitializeCommand(int AGVAction)
{
    agvRepairSubTask agvRepairSubTaskI;
    if(AGVAction==1004){//初始化命令
        agvRepairSubTaskI.actionType=4;
        agvRepairSubTaskI.commandId=commandNo;
        //agvRepairSubTaskI.agvSubTaskArray = communication(0x0000,0x0000,command(0x04));
        agvRepairSubTaskI.agvSubTaskArray=communication(0x0000,0x0000,command_other(0x04));
        agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
        qDebug()<<"初始化命令---->: 0x04  系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
    }if(AGVAction==1020){//同步帧编码
        agvRepairSubTaskI.actionType=20;
        agvRepairSubTaskI.commandId=commandNo;
        //agvRepairSubTaskI.agvSubTaskArray = communication(0x0000,0x0000,command(0x04));
        agvRepairSubTaskI.agvSubTaskArray=communication(0x0000,0x0000,command_other(0x20));
        agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
        qDebug()<<"同步帧编码---->: 0x20  系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
    }

}

void agvCar::ON_sendpreciseCommand()
{
    agvRepairSubTask agvRepairSubTaskI;
    agvRepairSubTaskI.actionType=21;
    agvRepairSubTaskI.commandId=commandNo;
    agvRepairSubTaskI.agvSubTaskArray=communication(0x0000,0x0000,command_other(0x21));
    agvSendSubTask_action.insert(commandNo,agvRepairSubTaskI);
    qDebug()<<"精准定位-->动作指令: 0x21  系统帧编码:"<<commandNo<<" -- append  write---> "<<agvRepairSubTaskI.agvSubTaskArray.toHex();
}

//定时编译AGV任务
void agvCar::onAddAGVTaskTimerOut()
{
    if(agvSendSubTask_query.isEmpty()){
        agvSendSubTask_query=communication(0x0000,0x0000,command_other(0x02));
    }
    agvStateItem.lineEdit_timer++;
    if(agvStateItem.lineEdit_timer>50){
        agvStateItem.lineEdit_timer=110;
        agvStateItem.isOnline = false;
        agvStateItem.agvFinishInitcount=0;
    }
}


//定时发送给AGV任务
void agvCar::onSendAGVTaskTimerOut()
{
    agvSendSubTaskcount++;
    if(agvSendSubTaskcount>=10000){agvSendSubTaskcount=0;}
    if(!agvCarSocketItemMap.isEmpty()){
        if(agvCarSocketItemMap.keys(true).size() > 0 && agvCarSocketItemMap.keys(true).last() != nullptr){

            if(!agvSendSubTask_query.isEmpty() && agvSendSubTaskcount%2==0){
                agvCarSocketItemMap.keys(true).last()->write(agvSendSubTask_query,agvSendSubTask_query.size());
                //qDebug()<<"AGV查询--->:"<<agvSendSubTask_query.size()<<agvSendSubTask_query.toHex();
                return;
            }if(!agvSendSubTask_action.isEmpty() && agvSendSubTaskcount%2==1
                    && SendSubTaskcount==0){
                SendSubTaskcount=3;
                agvCarSocketItemMap.keys(true).last()->write(agvSendSubTask_action.first().agvSubTaskArray);
                agvCarSocketItemMap.keys(true).last()->flush();
                qDebug()<<"系统帧编码:"<<commandNo<<" -- send  write---> "<<agvSendSubTask_action.first().agvSubTaskArray.toHex();
                if(agvSendSubTask_action.first().actionType>1){
                    SendSubTaskcount=0;
                    agvSendSubTask_action.remove(agvSendSubTask_action.firstKey());
                }

                return;
            }
        }
    }

}

//定时读取从AGV接收任务
void agvCar::onReadAGVTaskTimerOut()
{
    if(agvReadAllTaskList.size() > 0){
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
           <<" EndQRPoint:"<<EndQRPoint<<" AGVAction:"<<AGVAction<<" FinishInit:"
          <<agvStateItem.agvFinishInit<<agvStateItem.passPointState;

    if(agvStateItem.passPointState.toInt()>0){
        StartQRPoint=quint32(agvStateItem.passPointState.toInt());
    }

    if(AGVAction>1000){
        QMap<int,agvSubTask> TaskmoveList;
        emit TaskmoveListProcess(agvIp,TaskmoveList,agvStateItem,0);

        AGVMoveinit();
        agvSendSubTask_action.clear();
        emit sendInitializeCommand(AGVAction);
        Device_door_Action("",0,0);

        commandNobool=true;
        agvStateItem.PointList.clear(); //已执行的二维码 缓存链表
        agvStateItem.CurrentDestpoint=0;
        agvStateItem.agvFinishInitcount=0;
        agvStateItem.agvFinishInit=false;
        agvStateItem.doorPoint=0;
        agvStateItem.DeviceIP_door="";
        return;
    }

    if((agvStateItem.agvFinishInit || agvStateItem.CurrentDestpoint!=int(EndQRPoint))){
        agvStateItem.AGVAction=AGVAction;

        if(AGVAction==1){
            AGVMoveinit();
            agvStateItem.PointList.clear();                 //已执行的二维码 缓存链表
            agvStateItem.CurrentDestpoint=int(EndQRPoint);
            agvStateItem.AGVChargeAction = chargetye;       //充电任务锁定(0.充电任务无锁定，1.充电任务锁定)

            quint32 Point_S=0; quint32 Point_E=0;
            QMap<int,agvSubTask > agvSubTaskMap_S;      //离开起始站点 二维码缓存链表
            QMap<int,agvSubTask > mainAgvSubTaskMap;    //当前所有路线 二维码缓存链表
            QMap<int,agvSubTask > agvSubTaskMap_E;      //进入终点站点 二维码缓存链表

            //获取站点内: Point 对应的 辅路线与对接点 Type--> 0 起点  1 终点
            mianRoute mianRouteI_S= getRouteInfo_In(StartQRPoint,0);
            mianRoute mianRouteI_E= getRouteInfo_In(EndQRPoint,1);

            if(mianRouteI_S.RouteName!=""){     //起点 在站点内
                Point_S=quint32(mianRouteI_S.Point_S);
            }else{
                Point_S=StartQRPoint;
            }

            if(mianRouteI_E.RouteName!=""){    //终点 在站点内
                Point_E=quint32(mianRouteI_E.Point_E);
            }else{
                Point_E=EndQRPoint;
            }

            if(mianRouteI_S.RouteName!=""){     //起点 在站点内 ---获取当前站点内路线信息Type :0->s  -1 ->e
                agvSubTaskMap_S=getMianRouteInfo_In(StartQRPoint,quint32(mianRouteI_S.Point_S),mianRouteI_S.StationName,0);
            }if(Point_S!=0 && Point_E!=0){      //获取站点外: 任意两点 Point 的路线规划
                mainAgvSubTaskMap=getRouteInfo_out(int(Point_S),int(Point_E),0);
            }if(mianRouteI_E.RouteName!=""){    //终点 在站点内 ---获取当前站点内路线信息Type :0->s  -1 ->e
                agvSubTaskMap_E=getMianRouteInfo_In(quint32(mianRouteI_E.Point_E),EndQRPoint,mianRouteI_E.StationName,-1);
            }

        }

        if(AGVAction==3){
            currentRotaryHeightState=3;
            agvStateItem.currentRotaryHeightStatecount=0;
            QList<QByteArray > agvMoveAssignment;              //AGV多条移动任务
            QList<agvSubTask > agvSubTaskList=agvRotateUpTask(quint32(agvStateItem.passPointState.toInt()));
            if(!agvSubTaskList.isEmpty()){//夹抱 AGV 动作基本任务
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

        if(AGVAction==4){
            currentRotaryHeightState=4;
            agvStateItem.currentRotaryHeightStatecount=0;
            QList<QByteArray > agvMoveAssignment;              //AGV多条移动任务
            QList<agvSubTask > agvSubTaskList=agvRotateDownTask(quint32(agvStateItem.passPointState.toInt()));
            if(!agvSubTaskList.isEmpty()){//夹抱 AGV 动作基本任务
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

        if(AGVAction==5){
            //QList<agvSubTask >agvSubTaskList.append(agvPivotTask(quint32(agvStateItem.passPointState.toInt()),90));//AGV原地旋转
        }

        if(AGVAction==7 && !commandNobool && agvStateItem.agvFinishInit){//发送 AGV 夹抱机器人取放货 动作 指令  assignmentId
            QList<QByteArray > agvMoveAssignment;              //AGV多条移动任务
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

        if(AGVAction==21){
            emit sendpreciseCommand();//设置小车精准定位
        }


    }else {
        qDebug()<<commandNobool<<"动作指令异常 ---->agvIp:"<<agvIp<<" StartQRPoint:"<<StartQRPoint<<" EndQRPoint:"<<EndQRPoint
               <<" AGVAction:"<<AGVAction<<" FinishInit:"<<agvStateItem.agvFinishInit
              <<agvStateItem.agvFinishInitcount;
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


bool agvCar::addAgvSubTask(int TaskId, agvSubTask agvSubTaskI, int AGVAction,QString RouteName)
{
    agvSubTask agvSubTaskItemTemp;
    agvSubTaskItemTemp.RouteName=RouteName;                     //路线名

    agvSubTaskItemTemp.TaskId=TaskId;
    agvSubTaskItemTemp.Point =agvSubTaskI.Point;                            //AGV基本任务 起始点
    agvSubTaskItemTemp.NextPoint = agvSubTaskI.NextPoint;                   //AGV基本任务 下一点
    agvSubTaskItemTemp.NextPointDistance =agvSubTaskI.NextPointDistance;    //AGV基本任务 下一点距离
    agvSubTaskItemTemp.AGVSpeed = agvSubTaskI.AGVSpeed;                     //AGV基本任务 速度
    agvSubTaskItemTemp.RotaryLowBarrierInstruction = agvSubTaskI.RotaryLowBarrierInstruction;  //AGV基本任务 顶盘降下时 激光方案（无货架）
    agvSubTaskItemTemp.RotaryHighBarrierInstruction = agvSubTaskI.RotaryHighBarrierInstruction;//AGV基本任务 顶盘举升时 激光方案（有货架）
    agvSubTaskItemTemp.postureAngle = agvSubTaskI.postureAngle;             //AGV基本任务 姿态角度
    agvSubTaskItemTemp.AGVMoveAnage = agvSubTaskI.AGVMoveAnage;             //AGV基本任务 移动角度
    agvSubTaskItemTemp.AGVRotaryAngle = agvSubTaskI.AGVRotaryAngle;         //AGV基本任务 转盘角度
    agvSubTaskItemTemp.SubTaskType = AGVAction;                             //AGV基本任务 基本任务类型

    QMap<int,agvSubTask >::iterator iter= agvSubTaskmoveMap.begin();              //AGV子任务列表 当前 未执行 的二维码任务链表
    while (iter!=agvSubTaskmoveMap.end()) {
        if(iter.value().Point==agvSubTaskItemTemp.Point && iter.value().NextPoint == agvSubTaskItemTemp.NextPoint){
                return false;
        }
        iter++;
    }

    qDebug()<<" agvSubTaskmoveMap insert--> TaskId:"<<TaskId<<agvSubTaskI.Point<<agvSubTaskI.NextPoint
           <<agvSubTaskI.NextPointDistance<<agvSubTaskI.AGVSpeed
           <<" 姿态角度:"<<agvSubTaskI.postureAngle<<" 移动角度:"<<agvSubTaskI.AGVMoveAnage
          <<" 转盘角度:"<<agvSubTaskI.AGVRotaryAngle<<AGVAction;

    agvSubTaskmoveMap.insert(TaskId,agvSubTaskItemTemp);
    return true;
}

void agvCar::AGVMoveinit()
{

    CurrentTaskId=1;
    agvSubTaskmoveMap.clear();
    agvStateItem.PointList.clear(); //退出管制链表
    agvStateItem.CurrentDestpoint=0;

}

void agvCar::pathMapInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    sqlQuery.prepare("select * from movepointmap;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            agvSubTask agvSubTaskI;
            agvSubTaskI.Id=sqlQuery.value("Id").toInt();                              //编号
            agvSubTaskI.RouteName=sqlQuery.value("RouteName").toString();                    //路线名
            agvSubTaskI.TaskId=sqlQuery.value("TaskId").toInt();                          //路径内序号
            agvSubTaskI.Point=quint32(sqlQuery.value("Point").toInt());                      //AGV基本任务 起始点
            agvSubTaskI.NextPoint=quint32(sqlQuery.value("NextPoint").toInt());                  //AGV基本任务 下一点
            agvSubTaskI.NextPointDistance=quint16(sqlQuery.value("NextPointDistance").toInt());          //AGV基本任务 下一点距离
            agvSubTaskI.AGVSpeed=quint8(sqlQuery.value("AGVSpeed").toInt());                    //AGV基本任务 速度
            agvSubTaskI.RotaryLowBarrierInstruction=quint8(sqlQuery.value("RotaryLowBarrierInstruction").toInt()); //AGV基本任务 顶盘降下时 激光方案（无货架）
            agvSubTaskI.RotaryHighBarrierInstruction=quint8(sqlQuery.value("RotaryHighBarrierInstruction").toInt());//AGV基本任务 顶盘举升时 激光方案（有货架）
            agvSubTaskI.postureAngle=quint16(sqlQuery.value("postureAngle").toInt());                   //AGV基本任务 姿态角度
            agvSubTaskI.AGVMoveAnage=quint16(sqlQuery.value("AGVMoveAnage").toInt());                   //AGV基本任务 移动角度
            agvSubTaskI.AGVRotaryAngle=quint16(sqlQuery.value("AGVRotaryAngle").toInt());               //AGV基本任务 转盘角度
            agvSubTaskI.SubTaskType =sqlQuery.value("SubTaskType").toInt();                             //AGV基本任务 基本任务类型  0正向  -1反向

            if(!agvSubTaskListinit.contains(QString::number(agvSubTaskI.Id))){
                agvSubTaskListinit.insert(QString::number(agvSubTaskI.Id),agvSubTaskI);
                //qDebug()<<agvSubTaskI.TaskId<<agvSubTaskI.Point<<agvSubTaskI.NextPoint<<agvSubTaskListinit.size();
            }

        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_station;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            Stationmap Stationmap1;
            Stationmap1.StationName=sqlQuery.value("StationName").toString();        //工位名称
            Stationmap1.StationPoint = sqlQuery.value("StationPoint").toInt();       //工位二维码
            Stationmap1.StartPoint = sqlQuery.value("StartPoint").toInt();           //StationPoint==StartPoint  出去  StationPoint！=StartPoint  进工位
            Stationmap1.PassPoint = sqlQuery.value("PassPoint").toInt();             //经过二维码 1
            Stationmap1.PassPoint1 = sqlQuery.value("PassPoint1").toInt();           //经过二维码  1
            Stationmap1.PassPoint2 = sqlQuery.value("PassPoint2").toInt();
            Stationmap1.PassPoint3 = sqlQuery.value("PassPoint3").toInt();
            Stationmap1.assistPoint = sqlQuery.value("assistPoint").toInt();        //辅路线  对接点
            Stationmap1.assistRoute = sqlQuery.value("assistRoute").toString();     //与工位连接的辅路线
            Stationmap1.SubTaskType = sqlQuery.value("SubTaskType").toInt();        //AGV基本任务 基本任务类型  0正向  -1反向

            Stationmap1.pointMap.insert(Stationmap1.StartPoint,Stationmap1.StartPoint);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint,Stationmap1.PassPoint);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint1,Stationmap1.PassPoint1);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint2,Stationmap1.PassPoint2);
            Stationmap1.pointMap.insert(Stationmap1.PassPoint3,Stationmap1.PassPoint3);

            if(!Stationmap_Map.contains(Stationmap1.StationName)){
                Stationmap_Map.insert(Stationmap1.StationName,Stationmap1);
            }

        }
    }

    sqlQuery.clear();
    sqlQuery.prepare("select * from move_mian;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            assistRoute assistRouteI;
            assistRouteI.Id=sqlQuery.value("Id").toInt();                           //序号
            assistRouteI.keyId=sqlQuery.value("keyId").toString();                  //路线编号
            assistRouteI.assistRoute_S=sqlQuery.value("assistRoute_S").toString();  //起始路线
            assistRouteI.assistPoint_S = sqlQuery.value("assistPoint_S").toInt();   //起始路线 离开点
            assistRouteI.assistRoute_E =sqlQuery.value("assistRoute_E").toString(); //目标路线
            assistRouteI.assistPoint_E =sqlQuery.value("assistPoint_E").toInt();    //目标路线  进入点

            if(!assistRoute_Map.contains(assistRouteI.Id)){ //起始点线 与 目标点路线的 对应连接关系
                assistRoute_Map.insert(assistRouteI.Id,assistRouteI);
            }

        }
    }

    sqlQuery.prepare("select * from move_mian_;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            mianRoute mianRouteI;
            mianRouteI.TaskId=sqlQuery.value("TaskId").toInt();             //序号       按照从小到大 执行
            mianRouteI.Point_S = sqlQuery.value("Point_S").toInt();         //起始
            mianRouteI.Point_E = sqlQuery.value("Point_E").toInt();         //离开
            mianRouteI.RouteName=sqlQuery.value("RouteName").toString();    //主路线名
            mianRouteI.SubTaskType = sqlQuery.value("SubTaskType").toInt(); //AGV基本任务 基本任务类型  0正向  -1反向
            mianRouteI.keyId=sqlQuery.value("keyId").toString();            //唯一识别号

            QMap<int,assistRoute >::iterator iter= assistRoute_Map.begin();
            while (iter!=assistRoute_Map.end()) {
                if(iter.value().keyId==mianRouteI.keyId){
                    iter.value().mianRouteMap.insert(mianRouteI.RouteName,mianRouteI);
                    //qDebug()<<"mianRouteMap.insert:"<<mianRouteI.TaskId<<mianRouteI.keyId;
                }
                iter++;
            }
        }
    }


    sqlQuery.clear();
    sqlQuery.prepare("select * from move_turn;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            QString RouteName=sqlQuery.value("RouteName").toString();
            int StartQRPoint= sqlQuery.value("StartQRPoint").toInt();
            int EndQRPoint=sqlQuery.value("EndQRPoint").toInt();
            if(!StartQRPointMap.contains(StartQRPoint)){        //路线以及起始点的缓存链表
                StartQRPointMap.insert(StartQRPoint,RouteName);
            }if(!EndQRPointMap.contains(EndQRPoint)){           //路线以及终点的缓存链表
                EndQRPointMap.insert(EndQRPoint,RouteName);
            }
        }
    }


}


//获取站点内: Point 对应的 辅路线与对接点 Type--> 0 起点  1 终点
mianRoute agvCar::getRouteInfo_In(quint32 Point, int Type)
{
    mianRoute mianRouteI;
    QMap<QString,Stationmap >::const_iterator iter=Stationmap_Map.begin();
    while (iter!=Stationmap_Map.end()) {
        if(iter.value().pointMap.contains(int(Point))){
            mianRouteI.StationName=iter.value().StationName;//工位名称
            mianRouteI.RouteName=iter.value().assistRoute;  //与工位连接的辅路线
            if(Type==0){//0 起点  1 终点
                mianRouteI.Point_S=iter.value().assistPoint;//辅路线  对接点
            }else{
                mianRouteI.Point_E=iter.value().assistPoint;//辅路线  对接点
            }
        }
        iter++;
    }
    qDebug()<<"判断当前二维码是否存在站点内: -->Point:"<<Point<<" Type:"<<Type
              <<"RouteName:"<<mianRouteI.RouteName<<" Point_S:"<<mianRouteI.Point_S<<" Point_E:"<<mianRouteI.Point_E;
    return mianRouteI;
}


//获取站点外: 任意两点 Point 的路线规划
QMap<int,agvSubTask > agvCar::getRouteInfo_out(int StartQRPoint, int EndQRPoint, int Type)
{

    assistRoute assistRouteI;
    QMap<int,agvSubTask > agvSubTaskMap_;
    mianRoute mianRoute_s; mianRoute mianRoute_e;
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();
    while (iter!=agvSubTaskListinit.end()) {
        if(iter!=nullptr){
            if(!Stationmap_Map.contains(iter.value().RouteName)){
                if(iter.value().Point == quint32(StartQRPoint)
                        && iter.value().RouteName!=StartQRPointMap.value(StartQRPoint)){//起始二维码
                    mianRoute_s.RouteName=iter.value().RouteName;
                    //qDebug()<<"-----StartQRPoint:"<<StartQRPoint<<mianRoute_s.RouteName;
                }if(iter.value().Point == quint32(EndQRPoint)
                        && iter.value().RouteName!=EndQRPointMap.value(EndQRPoint)){    //目标二维码
                    mianRoute_e.RouteName=iter.value().RouteName;
                    //qDebug()<<"-----EndQRPoint:"<<EndQRPoint<<mianRoute_e.RouteName;
                }
            }
        }else{
            return agvSubTaskMap_;
        }
        iter++;
    }

    if(mianRoute_s.RouteName==""){
        if(StartQRPointMap.contains(StartQRPoint)){ //路线以及起始点的缓存链表
            mianRoute_s.RouteName=StartQRPointMap.value(StartQRPoint);
        }if(EndQRPointMap.contains(StartQRPoint)){  //路线以及终点的缓存链表
            mianRoute_s.RouteName=EndQRPointMap.value(StartQRPoint);
        }
    }if(mianRoute_e.RouteName==""){
        if(StartQRPointMap.contains(EndQRPoint)){   //路线以及起始点的缓存链表
            mianRoute_e.RouteName=StartQRPointMap.value(EndQRPoint);
        }if(EndQRPointMap.contains(EndQRPoint)){    //路线以及终点的缓存链表
            mianRoute_e.RouteName=EndQRPointMap.value(EndQRPoint);
        }
    }

    if(mianRoute_s.RouteName == mianRoute_e.RouteName){
        QMap<int,agvSubTask > agvSubTaskMap_=getMianRouteInfo_out(quint32(StartQRPoint),quint32(EndQRPoint),mianRoute_s.RouteName);  
        return agvSubTaskMap_;
    }else{
        if(mianRoute_s.RouteName!="" && mianRoute_e.RouteName!=""){

            qDebug()<<" assistRoute_S:"<<mianRoute_s.RouteName<<" StartQRPoint:"<<StartQRPoint
                  <<" assistRoute_E:"<<mianRoute_e.RouteName<<" EndQRPoint:"<<EndQRPoint;
            //获取起始路线  与目标路线之间的 路线信息    (执行链表  按照 Id 从小到大 执行)
            assistRouteI=getMianRouteMap(mianRoute_s.RouteName, mianRoute_e.RouteName,StartQRPoint,EndQRPoint);

            QMap<int,agvSubTask > agvSubTaskMap_s;
            if(StartQRPoint==assistRouteI.assistPoint_S){
                //当起始二维码在 转折点时 特殊处理
                QString RouteName =getMianRouteInfo_or(StartQRPoint,mianRoute_s.RouteName,assistRouteI.assistPoint_E,mianRoute_e.RouteName);
                if(RouteName!=""){
                    agvSubTaskMap_s=getMianRouteInfo_out(quint32(StartQRPoint),quint32(assistRouteI.assistPoint_E),RouteName);
                    qDebug()<<"当起始二维码在 转折点时 特殊处理--> agvSubTaskMap_s:"<<agvSubTaskMap_s.size()<<" --- "<<StartQRPoint<<assistRouteI.assistPoint_E<<RouteName<<assistRouteI.mianRouteMap.size();
                }
            }else {
                agvSubTaskMap_s=getMianRouteInfo_out(quint32(StartQRPoint),quint32(assistRouteI.assistPoint_S),assistRouteI.assistRoute_S);
                qDebug()<<"获取起始路线--->agvSubTaskMap_s_:"<<agvSubTaskMap_s.size()<<" --- "<<StartQRPoint<<assistRouteI.assistPoint_S<<assistRouteI.assistRoute_S<<assistRouteI.mianRouteMap.size();
            }

            QMap<int,agvSubTask >mainAgvSubTaskMap;   //当前所有路线 二维码缓存链表
            if(!assistRouteI.mianRouteMap.isEmpty()){ //获取 每个路线  进入点与离开点 之间所有二维码的基础信息
                qDebug()<<" 获取 每个路线  进入点与离开点 之间所有二维码的基础信息 mianRouteMap"<<assistRouteI.mianRouteMap.size()<<assistRouteI.mianRouteMap.first().keyId;
                mainAgvSubTaskMap =getMainagvSubTaskMap(assistRouteI.mianRouteMap);
            }

            QMap<int,agvSubTask > agvSubTaskMap_e=getMianRouteInfo_out(quint32(assistRouteI.assistPoint_E),quint32(EndQRPoint),assistRouteI.assistRoute_E);

        }else{
            qDebug()<<" 1626 路径规划失败:"<<StartQRPoint<<EndQRPoint<<Type;
        }
    }

    qDebug()<<" 1492 agvSubTaskMap_:"<<agvSubTaskMap_.size()<<" StartQRPoint:"<<StartQRPoint<<" mianRoute_s:"<<mianRoute_s.RouteName
           <<" EndQRPoint:"<<EndQRPoint<<" mianRoute_e:"<<mianRoute_e.RouteName;
    return agvSubTaskMap_;
}

QString agvCar::getMianRouteInfo_or(int StartQRPoint, QString RouteName_s, int EndQRPoint, QString RouteName_e)
{
    QString RouteName="";
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter!=agvSubTaskListinit.end()) {
        if(iter.value().Point==quint32(StartQRPoint) && iter.value().RouteName!=RouteName_s){
            RouteName=iter.value().RouteName;
            return RouteName;
        }
        iter++;
    }
    return RouteName;
}

QMap<int, agvSubTask> agvCar::getMianRouteInfo_out(quint32 Point_S, quint32 Point_E, QString RouteName)
{

    QMap<int,agvSubTask > agvSubTaskMap_;
    agvSubTask agvSubTask_S;agvSubTask agvSubTask_E;
    QMap<QString,agvSubTask >::const_iterator iter=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter!=agvSubTaskListinit.end()) {
        if(iter.value().RouteName == RouteName && iter.value().SubTaskType==0){

            if(EndQRPointMap.contains(int(Point_S))){
                if(iter.value().NextPoint==Point_S){
                    agvSubTask_S=iter.value();
                }
            }else{
                if(iter.value().Point==Point_S){
                    agvSubTask_S=iter.value();
                }
            }

            if(StartQRPointMap.contains(int(Point_E))){
                if(iter.value().Point==Point_E){
                    agvSubTask_E=iter.value();
                }
            }else{
                if(iter.value().NextPoint==Point_E){
                    agvSubTask_E=iter.value();
                }
            }

        }
        iter++;
    }

    //qDebug()<<"Point_S--->RouteName:"<<RouteName<<agvSubTask_S.TaskId<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    //qDebug()<<"Point_E--->RouteName:"<<RouteName<<agvSubTask_E.TaskId<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    int SubTaskType=0;
    if(agvSubTask_S.TaskId > agvSubTask_E.TaskId){SubTaskType=-1;}
    QMap<QString,agvSubTask >::const_iterator iter1=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter1!=agvSubTaskListinit.end()) {
        if(iter1.value().RouteName == RouteName && iter1.value().SubTaskType==SubTaskType){
            if(iter1.value().Point==Point_S){
                agvSubTask_S=iter1.value();
                //qDebug()<<"1760 Point_S--->RouteName:"<<RouteName<<Point_S<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
            }if(iter1.value().NextPoint==Point_E){
                agvSubTask_E=iter1.value();
                //qDebug()<<"1761 Point_E--->RouteName:"<<RouteName<<Point_E<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
            }
        }
        iter1++;
    }

    qDebug()<<"getMianRouteInfo_out  RouteName--> Point_S 与 Point_E 二维码信息----->RouteName:"<<RouteName<<" SubTaskType:"<<SubTaskType <<Point_S<<Point_E;
    qDebug()<<"agvSubTask_S--> TaskId:"<<agvSubTask_S.TaskId<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    qDebug()<<"agvSubTask_E--> TaskId:"<<agvSubTask_E.TaskId<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    if(agvSubTask_S.TaskId!=0 && agvSubTask_E.TaskId!=0){
        QMap<QString,agvSubTask >::Iterator iter= agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {//获取起点与目标点 之间所有二维码的基础信息
            if(iter.value().Point==Point_S && iter.value().NextPoint==Point_E){
                //qDebug()<<" agvSubTask_add0:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
            }else{
                if(iter.value().RouteName == RouteName && iter.value().SubTaskType == SubTaskType){
                    if(iter.value().TaskId>=agvSubTask_S.TaskId && iter.value().TaskId<=agvSubTask_E.TaskId){
                        if(Point_S != iter.value().NextPoint){
                            //qDebug()<<" agvSubTask_add1:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                            agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
                        }
                    }
                }
            }
            iter++;
        }
    }

    agvSubTaskmoveList_add(agvSubTaskMap_);

    return agvSubTaskMap_;
}

QMap<int, agvSubTask> agvCar::getMianRouteInfo_In(quint32 Point_S, quint32 Point_E, QString RouteName, int SubTaskType)
{
    QMap<int,agvSubTask > agvSubTaskMap_;
    agvSubTask agvSubTask_S;  agvSubTask agvSubTask_E;
    QMap<QString,agvSubTask >::const_iterator iter1=agvSubTaskListinit.begin();//AGV移动基初始化
    while (iter1!=agvSubTaskListinit.end()) {
        if(iter1.value().RouteName == RouteName && iter1.value().SubTaskType==SubTaskType){

            if(EndQRPointMap.contains(int(Point_S))){
                if(iter1.value().NextPoint==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1805 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }else if(iter1.value().Point==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1811 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }else{
                if(iter1.value().Point==Point_S){
                    agvSubTask_S=iter1.value();
                    qDebug()<<"1811 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }

            if(StartQRPointMap.contains(int(Point_E))){
                if(iter1.value().Point==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1820 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }else if(iter1.value().NextPoint==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1838 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }else{
                if(iter1.value().NextPoint==Point_E){
                    agvSubTask_E=iter1.value();
                    qDebug()<<"1826 RouteName:"<<RouteName<<iter1.value().TaskId<<" Point:"<<iter1.value().Point<<" NextPoint:"<<iter1.value().NextPoint;
                }
            }

        }
        iter1++;
    }

    qDebug()<<"获取站点内路线二维码信息--->RouteName:"<<RouteName<<" SubTaskType:"<<SubTaskType<<Point_S<<Point_E;
    qDebug()<<"agvSubTask_S--> TaskId:"<<agvSubTask_S.TaskId<<" RouteName:"<<agvSubTask_S.RouteName<<" Point:"<<agvSubTask_S.Point<<" NextPoint:"<<agvSubTask_S.NextPoint;
    qDebug()<<"agvSubTask_E--> TaskId:"<<agvSubTask_E.TaskId<<" RouteName:"<<agvSubTask_E.RouteName<<" Point:"<<agvSubTask_E.Point<<" NextPoint:"<<agvSubTask_E.NextPoint;

    if(agvSubTask_S.TaskId!=0 || agvSubTask_E.TaskId!=0){
        QMap<QString,agvSubTask >::Iterator iter= agvSubTaskListinit.begin();
        while (iter!=agvSubTaskListinit.end()) {//获取起点与目标点 之间所有二维码的基础信息
            if(iter.value().RouteName == RouteName && iter.value().SubTaskType == SubTaskType){
                if((iter.value().TaskId>=agvSubTask_S.TaskId && iter.value().TaskId<=agvSubTask_E.TaskId)
                       && agvSubTask_S.TaskId>0 ){
                    if(Point_E != iter.value().Point){
                        qDebug()<<" agvSubTask_add2:"<<iter.value().RouteName<<SubTaskType<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                        agvSubTaskMap_.insert(iter.value().TaskId,iter.value());
                    }
                }

            }
            iter++;
        }
    }
    agvSubTaskmoveList_add(agvSubTaskMap_);
    return agvSubTaskMap_;
}

assistRoute agvCar::getMianRouteMap(QString RouteName_S, QString RouteName_E,int StartQRPoint,int EndQRPoint)
{
    assistRoute assistRouteI;
    QMap<int,assistRoute >::iterator iter1= assistRoute_Map.begin();//起始点辅路线 与 目标点辅路线的 对应连接关系
    while (iter1!=assistRoute_Map.end()) {
        if(iter1.value().assistRoute_S==RouteName_S && iter1.value().assistRoute_E==RouteName_E){
            assistRouteI=iter1.value();
        }
        iter1++;
    }
    qDebug()<<"获取起始路线  与目标路线之间的 路线信息--> keyId:"<<assistRouteI.keyId<<" assistRoute_S:"<<assistRouteI.assistRoute_S<<" assistPoint_S:"<<assistRouteI.assistPoint_S
          <<" assistRoute_E:"<<assistRouteI.assistRoute_E<<" assistPoint_E:"<<assistRouteI.assistPoint_E;
    return assistRouteI;
}

QMap<int, agvSubTask> agvCar::getMainagvSubTaskMap(QMap<QString, mianRoute> mianRouteMap)
{
    QMap<int, mianRoute> RouteMap_;
    QMap<int,agvSubTask >mainAgvSubTaskMap; //当前运行主路线 二维码 信息暂存
    for(int i=0;i<mianRouteMap.size();i++){
        mianRoute mianRouteI =getMianRoute_min(mianRouteMap,RouteMap_);//进行路线 二维码排序
        if(mianRouteI.TaskId!=0){
            RouteMap_.insert(mianRouteI.TaskId,mianRouteI);//防止重复误判
            qDebug()<<" 获取起始路线 与目标路线之间的 所有二维码的基础信息  mianRouteI:"<<mianRouteI.TaskId<<mianRouteI.RouteName<<mianRouteI.Point_S<<mianRouteI.Point_E<<mianRouteI.SubTaskType;
            mainAgvSubTaskMap=getMianRouteInfo_out(quint32(mianRouteI.Point_S),quint32(mianRouteI.Point_E),mianRouteI.RouteName);
        }
    }
    return mainAgvSubTaskMap;
}

mianRoute agvCar::getMianRoute_min(QMap<QString, mianRoute> mianRouteMap, QMap<int, mianRoute> RouteMap_)
{
    mianRoute mianRouteI;
    QMap<QString,mianRoute>::iterator iter0=mianRouteMap.begin();       //主路线 执行链表  按照 Id 从小到大 执行
    while (iter0!=mianRouteMap.end()) {
        if(!RouteMap_.contains(iter0.value().TaskId)){
            if(mianRouteI.TaskId==0){
                mianRouteI=iter0.value();
            }else{
                if(iter0.value().TaskId<=mianRouteI.TaskId){
                    mianRouteI=iter0.value();
                }
            }
        }
        iter0++;
    }
    return mianRouteI;
}

void agvCar::agvSubTaskmoveList_add(QMap<int, agvSubTask> agvSubTaskMap_)
{
    QMap<int,agvSubTask >::iterator iter= agvSubTaskMap_.begin();
    while (iter!=agvSubTaskMap_.end()) {
        bool SubTask =addAgvSubTask(CurrentTaskId,iter.value(),1,iter.value().RouteName);
        if(SubTask){
            CurrentTaskId++;
        }
        iter++;
    }

}

void agvCar::ON_TaskmoveList_Process(int passPointState)
{
    if(!agvSubTaskmoveMap.isEmpty() && Taskmove_Processbool){

        Taskmove_Processbool=false;
        int passTaskId=0;
        int MaxTaskId=0;                                   //当前已发送 的最大编号 数据
        int door_TaskId=0;                                                  //当前自动门 最大执行任务号
        QMap<int,agvSubTask >::iterator iter= agvSubTaskmoveMap.begin();    //AGV子任务列表 当前 未执行 的二维码任务链表
        while (iter!=agvSubTaskmoveMap.end()) {
            if(iter.value().Point ==quint32(passPointState)){
                passTaskId=iter.value().TaskId;
            }if(iter.value().complete=="1" && MaxTaskId <= iter.value().TaskId){//complete="0"   0 待执行， 1在执行 2 已经过
                MaxTaskId=iter.value().TaskId;
            }if(agvStateItem.doorPoint!=0 && quint32(agvStateItem.doorPoint)==iter.value().Point){
                door_TaskId=iter.value().TaskId;
            }if(agvStateItem.doorPoint!=0 && agvStateItem.doorPoint==agvStateItem.CurrentDestpoint){
                if(quint32(agvStateItem.doorPoint)==iter.value().NextPoint){
                    door_TaskId=iter.value().TaskId;
                }
            }
            iter++;
        }

        int passTaskId_=passTaskId+8;
        bool doorbool=false;
        QMap<int,agvSubTask> TaskmoveList;
        agvStateItem.agvSubTaskmoveListsize=0;
        if(agvStateItem.currentTaskCountState.toInt()<=5){
            QMap<int,agvSubTask >::iterator iter= agvSubTaskmoveMap.begin();              //AGV子任务列表 当前 未执行 的二维码任务链表
            while (iter!=agvSubTaskmoveMap.end()) {
                if(iter.value().TaskId>MaxTaskId && TaskmoveList.size()<=8
                       && iter.value().TaskId>=passTaskId && iter.value().TaskId<=passTaskId_){

                    if(agvStateItem.doorPoint!=0 && door_TaskId>iter.value().TaskId){
                         if(!TaskmoveList.contains(iter.value().TaskId)){
                             doorbool=true;
                             TaskmoveList.insert(iter.value().TaskId,iter.value());
                             qDebug()<<"TaskmoveList-->TaskId 1:"<<iter.value().TaskId<<" door_TaskId:"<<door_TaskId<<" Point:"<<iter.value().Point
                                    <<" NextPoint:"<<iter.value().NextPoint<<" doorPoint"<<agvStateItem.doorPoint;
                         }
                    }

                    if(agvStateItem.doorPoint==0 || (agvStateItem.doorPoint!=0 && agvStateItem.doorPoint==agvStateItem.CurrentDestpoint)){
                        if(!TaskmoveList.contains(iter.value().TaskId)){
                            TaskmoveList.insert(iter.value().TaskId,iter.value());
                            qDebug()<<"TaskmoveList-->TaskId 2:"<<iter.value().TaskId<<" door_TaskId:"<<door_TaskId<<" Point:"<<iter.value().Point
                                   <<" NextPoint:"<<iter.value().NextPoint<<" doorPoint"<<agvStateItem.doorPoint;
                        }
                    }
                }

                if(iter.value().complete=="1" && passTaskId_<iter.value().TaskId && passTaskId_!=0){
                    iter.value().complete="2";
                    //qDebug()<<passTaskId<<"agvSubTaskmoveMap.remove:"<<iter.value().TaskId<<iter.value().Point<<iter.value().NextPoint;
                }

                iter++;
            }
        }

        if(doorbool && !TaskmoveList.isEmpty()){
            TaskmoveList_Process_(TaskmoveList);
        }

        if(!doorbool){
            emit TaskmoveListProcess(agvIp,TaskmoveList,agvStateItem,1);
        }
    }

}

void agvCar::TaskmoveList_Process_(QMap<int,agvSubTask> TaskmoveList)
{
    if(!TaskmoveList.isEmpty()){
        QMap<int,agvSubTask >::iterator iter_= agvSubTaskmoveMap.begin();              //AGV子任务列表 当前 未执行 的二维码任务链表
        while (iter_!=agvSubTaskmoveMap.end()) {
            QMap<int,agvSubTask>::iterator iter= TaskmoveList.begin();
            while (iter!=TaskmoveList.end()){
                if(iter_.value().TaskId==iter.value().TaskId){
                    iter_.value().complete="1";
                    agvSubTaskList_Map.insert(iter_.value().TaskId,iter_.value());
                }
                iter++;
            }
            iter_++;
        }
    }

    if(!agvSubTaskList_Map.isEmpty()){
        setAgvSendRepairSubTaskList(); //把子任务链表 转换为待发数据
    }

    Taskmove_Processbool=true;

}

void agvCar::Device_door_Action( QString DeviceIP,int Action,int doorPoint)
{
    Taskmove_Processbool=true;
    agvStateItem.doorPoint=doorPoint;           //当前自动门 最大执行任务号
    agvStateItem.DeviceIP_door=DeviceIP;        //自动门IP
    qDebug()<<"agvCar::Device_door_Action"<<DeviceIP<<Action<<doorPoint;
}


