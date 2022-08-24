#ifndef SYSTEM_AGV_H
#define SYSTEM_AGV_H

#include <QWidget>
#include "agvCar/AgvStatus.h"
#include "queryServer/queryserver.h"
#include "sql_single/query_single.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"
#include "wrexcelprocess/wrexcelprocess.h"

namespace Ui {
class system_agv;
}

class system_agv : public QWidget
{
    Q_OBJECT

public:
    explicit system_agv(QWidget *parent = nullptr);
    ~system_agv();

    void system_agvInit();          //初始化函数

    void SlotsetCurrentItem_agv(int row,int column);        //AGV参数配置

    void SlotsetCurrentItem_Line(int row,int column);       //路线信息

    void SlotsetCurrentItem_rule(int row,int column);       //路线规则



    AGVCurrentTask AGVCurrentTaskI;
    QMap<QString, AGVCurrentTask> AGVCurrentTaskMap;
    void TableWidget_show_agv();
    QList<RW_Excel>TableWidget_agv(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap); //显示AGV信息


    agvSubTask currentAgvSubTask;
    QMap<int,agvSubTask > agvSubTaskListinit;
    void TableWidget_show_Line();
    QList<RW_Excel>TableWidget_Line(QMap<int,agvSubTask >SubTaskListinit);           //路线信息

    void TableWidget_show_rule(assistRoute assistRouteI);                           //路线规则
    QList<RW_Excel>TableWidget_rule(QMap<QString,mianRoute>mianRouteMap);

    assistRoute getAssistRouteI();                                                  //创建路线信息
    mianRoute getmianRoute();                                                       //创建途经路线信息



private slots:
     /********* AGV参数配置 **********/
    void on_query_agvip_clicked();

    void on_add_agvip_clicked();            //创建AGV--项

    void on_delete_agvip_clicked();         //删除AGV--项

    void on_update_agvip_clicked();         //更新AGV参数信息

    /*********** 路线信息 *********/
    void on_query_LineInfo_clicked();

    void on_add_LineInfo_clicked();         //添加路径二维码信息

    void on_delete_LineInfo_clicked();      //删除路径二维码信息

    void on_update_LineInfo_clicked();      //更新路径二维码信息

    void on_Alter_LineInfo_clicked();       //导入路线二维码信息

    /********* 路线规则 ************/
    void on_query_rule_clicked();

    void on_add_rule_clicked();         //创建路径规则--项

    void on_delete_rule_clicked();      //删除路径规则--项

    void on_add_rule_2_clicked();       //添加路线编号 ---途经的子路线信息

    void on_delete_rule_2_clicked();    //删除路线编号 ---途经的子路线信息

    void on_update_rule_clicked();      //把路线规则信息提交到数据库


    void ON_Pressed();

    void ON_Released();
private:
    Ui::system_agv *ui;

    QTimer *ItemTimer;
    ServerInit ServerInitItem;              //基础信息

    mianRoute currentMianRoute;
    assistRoute currentAssistRouteI;
    wrexcelprocess *wrexcelprocessItiem;            //Excel 读写

    QList<QPushButton *>Actionbtns;
};

#endif // SYSTEM_AGV_H
