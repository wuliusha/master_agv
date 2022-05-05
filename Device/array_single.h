#ifndef ARRAY_SINGLE_H
#define ARRAY_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif


#include "sqlConnect/ConnectionPool.h"
#include "singleProject/single_project.h"
#include "httpserver/httpconnection.h"

class array_Single : public QObject
{
    Q_OBJECT
public:
    static QMutex mutex;
    static array_Single* array_SingleItiem;

    static array_Single *GetInstance();
    explicit array_Single(QObject *parent = nullptr);

    /************** 接驳台部分 ***************/

    QByteArray device_query(QString deviceType);//设备类型 deviceType--> query查询

    //设备类型 deviceType-->  动作指令 orderType
    QByteArray device_action(QString deviceType,QString orderType);

    //进制的转换  获取当前设备各个IO口的状态
    controlbox setSystemchage(QString DeviceIP,QByteArray AnalysisArray);


    /************** 升降机部分 ***************/

    //电梯类型 --> query查询
    QByteArray Lift_query(QString liftType);

    //获取升降机的动作及查询指令---单个
    QByteArray getLiftactionArray(LiftTask LiftTaskI,int startFloor,int destFloor);

    //获取升降机的动作及查询指令---批量
    QByteArray getLiftAnalysisArray(LiftTask LiftTaskI,QString actionType,int startFloor,int destFloor);

    //进制的转换  获取当前设备各个IO口的状态
    quint16 getSystemchage(QByteArray AnalysisArray,int bye,int count);


signals:

public slots:
};

#endif // ARRAY_SINGLE_H
