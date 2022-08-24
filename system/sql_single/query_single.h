#ifndef QUERY_SINGLE_H
#define QUERY_SINGLE_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include<QToolButton>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#include<QMouseEvent>
#endif

#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"
#include "wrexcelprocess/wrexcelprocess.h"


class query_Single : public QObject
{
    Q_OBJECT
public:
    static QMutex mutex;
    static query_Single* query_SingleItiem;

    static query_Single *GetInstance();
    explicit query_Single(QObject *parent = nullptr);


    /*************路线管理--路线规则*********************/

    assistRoute queryAssistRoute(QString keyId);                                //根据路线编号 查找对应路线信息

    bool assistRoute_Insert(assistRoute assistRouteI);                          //创建路线信息 写入数据库

    bool assistRoute_Delete(assistRoute assistRouteI);                          //删除路线信息 删除数据库

    bool mianRouteMap_Insert(QMap<QString,mianRoute>mianRouteMap);              //创建路线的途经路线 信息 写入数据库

    bool mianRouteMap_Delete(QString keyId);                                    //删除途经路线信息

    /*************路线管理--路线信息*********************/

    QMap<int,agvSubTask > query_agvSubTaskListinit(QString RouteName,int SubTaskType);  //查找当前路线信息

    bool SubTaskListinit_insert(QMap<int,agvSubTask> agvSubTaskListinit_);              //导入路线二维码信息 到数据库

    bool agvSubTask_Delete(QString RouteName,int SubTaskType);                                              //删除路线信息


    /*************路线管理--站点绑定*********************/

    QMap<QString,Stationmap > query_Stationmap(QString StationName);    //查找当前站点路线信息

    bool Stationmap_insert(QMap<QString,Stationmap> Stationmap_Map);    //添加 站点路线信息 到数据库

    bool Stationmap_update(QMap<QString,Stationmap> Stationmap_Map);    //更新 站点路线信息

    bool Stationmap_Delete(QString StationName);                        //删除 站点路线信息


   /************   自动门配置界面   ***************/
    QMap<int,doorSubTask>query_doorSubTaskMap(QString doorIP,int doorId);   //查找当前自动门信息

    bool doorSubTaskMap_insert(QMap<int,doorSubTask>doorSubTaskMap);        //添加 自动门信息 到数据库

    bool doorSubTask_update(QMap<int,doorSubTask>doorSubTaskMap);           //更新 自动门信息

    bool doorSubTask_Delete(int doorId);                                    //删除 自动门信息

    /************   AGV小车参数配置界面   ***************/

     QMap<QString,AGVCurrentTask>query_AGVCurrentTask(QString AGVIP);           //查找当前AGV信息

     bool AGVCurrentTask_insert(QMap<QString,AGVCurrentTask>AGVCurrentTaskMap); //添加 AGV信息 到数据库

     bool AGVCurrentTask_update(QMap<QString,AGVCurrentTask>AGVCurrentTaskMap); //更新 AGV信息

     bool AGVCurrentTask_Delete(QString AGVIP);                                 //删除 AGV信息



signals:

public slots:
};

#endif // QUERY_SINGLE_H
