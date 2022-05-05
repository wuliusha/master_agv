#include "array_single.h"

#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase)

array_Single* array_Single::array_SingleItiem=0;
QMutex array_Single::mutex;


array_Single::array_Single(QObject *parent) : QObject(parent)
{

}

QByteArray array_Single::device_query(QString deviceType)
{
    //FC 00 13 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 5A
    QByteArray  ByteArray;
    ByteArray.append(char(0xFC));
    ByteArray.append(char(0x00));
    ByteArray.append(0x13);
    QByteArray zero0;
    zero0.fill(0x00,4);

    ByteArray.append(zero0);
    if(deviceType=="charge"){
        ByteArray.append(0x02);     //控制盒--充电桩类型
    }else{
        ByteArray.append(0x10);     //控制盒--其他类型
    }

    QByteArray zero;
    zero.fill(0x00,10);
    ByteArray.append(zero);
    ByteArray.append(0x05a);

    //qDebug()<<"指令类型:"<<orderType<<" 动作指令:"<<Action<<" ByteArray:"<<ByteArray.toHex();

    return ByteArray;
}

QByteArray array_Single::device_action(QString deviceType, QString orderType)
{
    QByteArray  ByteArray;
    ByteArray.append(char(0xFC));
    ByteArray.append(char(0x00));
    ByteArray.append(0x13);
    QByteArray zero0;
    zero0.fill(0x00,4);

    ByteArray.append(zero0);
    if(deviceType=="charge"){           //控制盒--充电桩类型
        ByteArray.append(0x01);
        if(orderType=="action1"){
            ByteArray.append(char(0x01));
        }if(orderType=="action2"){
            ByteArray.append(char(0x00));
        }
    }

    if(deviceType=="station"){          //控制盒--带滚筒接驳台类型
        if(orderType=="start"){         //请求上料信号
            ByteArray.append(0x01);
        }if(orderType=="start_run"){    //上料完成请求离开信号
            ByteArray.append(0x02);
        }if(orderType=="unload"){       //请求卸料请求信号
            ByteArray.append(0x03);
        }if(orderType=="unload_run"){   //卸料完成请求离开信号
            ByteArray.append(0x04);
        }
        ByteArray.append(char(0x00));
    }

    if(deviceType=="door"){             //控制盒--自动门类型
        if(orderType=="action1"){
            ByteArray.append(0x01);
            ByteArray.append(char(0x00));
        }if(orderType=="action2"){
            ByteArray.append(0x02);
            ByteArray.append(char(0x00));
        }
    }

    if(deviceType=="door_f"){           //控制盒--风淋门类型
        if(orderType=="open_front"){    //前门打开
            ByteArray.append(0x01);
        }if(orderType=="open_back"){    //后门打开
            ByteArray.append(0x02);
        }if(orderType=="close"){        //风淋门——关门
            ByteArray.append(0x03);
        }
        ByteArray.append(char(0x00));
    }

    QByteArray zero;
    zero.fill(0x00,9);
    ByteArray.append(zero);
    ByteArray.append(0x05a);

    //qDebug()<<"设备类型:"<<deviceType<<"指令类型:"<<orderType<<" 动作指令:"<<Action<<" ByteArray:"<<ByteArray.toHex();
    return ByteArray;

}

controlbox array_Single::setSystemchage(QString DeviceIP, QByteArray AnalysisArray)
{
    //01 23 45 67 89 10 12 14 16 18 20 22 24 26
    //FC 00 13 00 00 00 01 10 13 14 00 00 00 00 00 00  00 00 5A

    QString strHex=AnalysisArray.toHex();

    bool hexok_I;
    QString strHex_I=strHex.mid(12,2);
    int boxID=strHex_I.toInt(&hexok_I,16);     //十六进制转十进制
    QString byte_I=QString("%1").arg(boxID, 8, 2, QLatin1Char('0')); // 十进制转二进制（至少保留4位）20 Return "00010100"
    qDebug() <<"systemchage---->hexok_I"<<hexok_I<<" boxID:"<<boxID<<" byte_I"<<byte_I;

    bool hexok_X;
    QString strHex_X=strHex.mid(16,2);
    int Statushex_X=strHex_X.toInt(&hexok_X,16);     //十六进制转十进制
    QString byte_X=QString("%1").arg(Statushex_X, 8, 2, QLatin1Char('0')); // 十进制转二进制（至少保留4位）20 Return "00010100"
    qDebug() <<"systemchage---->hexok_X"<<hexok_X<<" byte_X"<<byte_X;

    bool hexok_Y;
    QString strHex_Y=strHex.mid(18,2);
    int Statushex_Y=strHex_Y.toInt(&hexok_Y,16);     //十六进制转十进制
    QString byte_Y=QString("%1").arg(Statushex_Y, 8, 2, QLatin1Char('0')); // 十进制转二进制（至少保留4位）20 Return "00010100"
    qDebug() <<"systemchage---->hexok_Y"<<hexok_Y<<" byte_Y"<<byte_Y<<"--";
    if(AnalysisArray[0] == char(0xFC)){
        qDebug() <<"systemchage---->"<<hexok_Y<<" byte_Y"<<byte_Y<<"--"<<quint16(AnalysisArray.at(0))<<quint16(AnalysisArray.at(1))<<quint16(AnalysisArray.at(7));
    }

    controlbox controlboxI;

    controlboxI.boxID=boxID;           //控制盒拨号编码编号
    controlboxI.boxIP=DeviceIP;    //

    controlboxI.X17=byte_X.mid(0,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X16=byte_X.mid(1,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X15=byte_X.mid(2,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X14=byte_X.mid(3,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X13=byte_X.mid(4,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X12=byte_X.mid(5,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X11=byte_X.mid(6,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.X10=byte_X.mid(7,1).toInt();             //1表示有信号  0表示无信号

    controlboxI.Y17=byte_Y.mid(0,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y16=byte_Y.mid(1,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y15=byte_Y.mid(2,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y14=byte_Y.mid(3,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y13=byte_Y.mid(4,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y12=byte_Y.mid(5,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y11=byte_Y.mid(6,1).toInt();             //1表示有信号  0表示无信号
    controlboxI.Y10=byte_Y.mid(7,1).toInt();             //1表示有信号  0表示无信号

    qDebug()<<"boxID:"<<controlboxI.boxID<<" X17:"<<controlboxI.X17<<" X16:"<<controlboxI.X16<<" X15:"<<controlboxI.X15
              <<" X14:"<<controlboxI.X14<<" X13:"<<controlboxI.X13<<" X12:"<<controlboxI.X12
                <<" X11:"<<controlboxI.X11<<" X10:"<<controlboxI.X10;

    qDebug()<<"boxID:"<<controlboxI.boxID<<" Y17:"<<controlboxI.Y17<<" Y16:"<<controlboxI.Y16<<" Y15:"<<controlboxI.Y15
              <<" Y14:"<<controlboxI.Y14<<" Y13:"<<controlboxI.Y13<<" Y12:"<<controlboxI.Y12
                <<" Y11:"<<controlboxI.Y11<<" Y10:"<<controlboxI.Y10;
    return controlboxI;
}

QByteArray array_Single::Lift_query(QString liftType)
{
    QByteArray  ByteArray;
    //01 FF 0A 00 64 00 00 00 20 44 06 00
    ByteArray.append(0x01);
    ByteArray.append(char(0xFF));
    ByteArray.append(char(0x0A));
    ByteArray.append(char(0x00));
    ByteArray.append(0x64);
    QByteArray zero0;
    zero0.fill(0x00,3);
    ByteArray.append(zero0);
    ByteArray.append(0x20);
    ByteArray.append(0x44);
    ByteArray.append(0x06);
    ByteArray.append(char(0x00));

    qDebug()<<"Lift_query--->liftType:"<<liftType<<"  ByteArray:"<<ByteArray.toHex();
    return ByteArray;
}

//获取升降机的动作及查询指令---单个
QByteArray array_Single::getLiftactionArray(LiftTask LiftTaskI, int startFloor, int destFloor)
{
    QByteArray  ByteArray;
    ByteArray.append(0x03);
    ByteArray.append(char(0xFF));
    ByteArray.append(char(0x0A));
    ByteArray.append(char(0x00));

    if(startFloor==2){
        ByteArray.append(0x64);//D100
    }if(startFloor==3){
        ByteArray.append(0x67);//D103
    }if(startFloor==5){
        ByteArray.append(0x69);//D105
    }

    QByteArray zero0;
    zero0.fill(0x00,3);
    ByteArray.append(zero0);
    ByteArray.append(0x20);
    ByteArray.append(0x44);

    ByteArray.append(0x01);
    ByteArray.append(char(0x00));

    if((startFloor==2 && destFloor==3)|| (startFloor==3 && destFloor==2)
    || (startFloor==4 && destFloor==2)){
        ByteArray.append(char(0x02));
        ByteArray.append(char(0x00));
    }if((startFloor==2 && destFloor==4)|| (startFloor==3 && destFloor==4)
            || (startFloor==4 && destFloor==3)){
        ByteArray.append(char(0x03));
        ByteArray.append(char(0x00));
    }

    qDebug()<<"升降机指令类型--->LiftIP:"<<LiftTaskI.LiftIP<<" startFloor-destFloor:"<<startFloor<<"-"<<destFloor;
    qDebug()<<"ByteArray:"<<ByteArray.toHex();
    return ByteArray;
}

//获取升降机的动作及查询指令---批量
QByteArray array_Single::getLiftAnalysisArray(LiftTask LiftTaskI,QString actionType, int startFloor, int destFloor)
{
    QByteArray  ByteArray;
    qDebug()<<"升降机指令类型--->actionType:"<<actionType<<" startFloor-destFloor:"<<startFloor<<"-"<<destFloor;

    if(actionType=="query"){
        //01 FF 0A 00 64 00 00 00 20 44 06 00
        ByteArray.append(0x01);
        ByteArray.append(char(0xFF));
        ByteArray.append(char(0x0A));
        ByteArray.append(char(0x00));
        ByteArray.append(0x64);
        QByteArray zero0;
        zero0.fill(0x00,3);
        ByteArray.append(zero0);
        ByteArray.append(0x20);
        ByteArray.append(0x44);
        ByteArray.append(0x06);
        ByteArray.append(char(0x00));

    }

    if(actionType=="action"){

        //        (1可放料)---(1可取料)    (1可取料)---(1可放料)    (1可取料)---(1可放料)
        //          D100       D101        D102       D103        D104       D105
        //        2F-3F-:2                          3F-2F-:2               4F-2F-:2
        //        2F-4F-:3                          3F-4F-:3               4F-3F-:3

        //批量写入:D100 -D105 ( 3-8)
        //03 FF 0A 00  64 00 00 00 20 44 06 00 03  00 04 00 05 00 06 00 07 00 08 00

        ByteArray.append(0x03);
        ByteArray.append(char(0xFF));
        ByteArray.append(char(0x0A));
        ByteArray.append(char(0x00));
        ByteArray.append(0x64);
        QByteArray zero0;
        zero0.fill(0x00,3);
        ByteArray.append(zero0);
        ByteArray.append(0x20);
        ByteArray.append(0x44);

        ByteArray.append(0x06);
        ByteArray.append(char(0x00));

        //D100 写入
        if(startFloor==2){
            destFloor=destFloor-1;
            ByteArray.append(char(destFloor));
            ByteArray.append(char(0x00));
        }else{
            ByteArray.append(char(LiftTaskI.LiftD100));
            ByteArray.append(char(0x00));
        }

        //D101 写入
        ByteArray.append(char(LiftTaskI.LiftD101));
        ByteArray.append(char(0x00));

        //D102 写入

        ByteArray.append(char(LiftTaskI.LiftD102));
        ByteArray.append(char(0x00));

        //D103 写入
        if(startFloor==3){
            if(destFloor==4){destFloor=destFloor-1;}
            ByteArray.append(char(destFloor));
            ByteArray.append(char(0x00));
        }else{
            ByteArray.append(char(LiftTaskI.LiftD103));
            ByteArray.append(char(0x00));
        }

        //D104 写入
        ByteArray.append(char(LiftTaskI.LiftD104));
        ByteArray.append(char(0x00));

        //D105 写入
        if(startFloor==4){
            ByteArray.append(char(destFloor));
            ByteArray.append(char(0x00));
        }else{
            ByteArray.append(char(LiftTaskI.LiftD105));
            ByteArray.append(char(0x00));
        }
    }

    qDebug()<<"ByteArray:"<<ByteArray.toHex();
    return ByteArray;
}


quint16 array_Single::getSystemchage(QByteArray AnalysisArray,int bye,int count)
{
    QString strHex=AnalysisArray.toHex();

//    int Status=strHex.mid(bye,count).toInt();
//    QString hex=QString("%1").arg(Status, 4, 16, QLatin1Char('0')); // 十进制转十六进制(保留4位) 20 Return "0014"
//    QString byte=QString("%1").arg(Status, 4, 2, QLatin1Char('0')); // 十进制转二进制（至少保留4位）20 Return "10100"
//    qDebug() <<"systemchage  String-->dec:"<<Status<<" hex:"<<hex<<" byte:"<<byte;

    bool hexok;bool byteok;
    QString hex=strHex.mid(bye,count);
    QString byte=strHex.mid(bye,count);
    int Statusint=hex.toInt(&hexok,16);     //十六进制转十进制

    int Statusbyte=byte.toInt(&byteok,2);   //二进制转十进制
    quint16 Statushex=quint16(hex.toInt());

    //qDebug() <<"进制转换---》systemchage  int---->Statusint"<<Statusint<<hexok<<"  Statusbyte"<<Statusbyte<<byteok<<" Statushex"<<Statushex;

    return Statushex;
}



array_Single *array_Single::GetInstance()
{
    if(array_SingleItiem != nullptr){
        return array_SingleItiem;
    }else{
        mutex.lock();
        array_SingleItiem=new array_Single;
        mutex.unlock();
        return array_SingleItiem;
    }
}
