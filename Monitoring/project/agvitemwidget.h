#ifndef AGVITEMWIDGET_H
#define AGVITEMWIDGET_H

#include <QWidget>
#include "agvCar/AgvStatus.h"

#include "sql_single/query_single.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"
#include "wrexcelprocess/wrexcelprocess.h"

namespace Ui {
class AgvItemWidget;
}

class AgvItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AgvItemWidget(QWidget *parent = nullptr);
    ~AgvItemWidget();

    QTimer *ItemTimer;
    int ItemTimercount=0;
    AgvStatus *agvStatus;
    ServerInit ServerInitItem;      //基础信息


    mianRoute currentMianRoute;
    assistRoute currentAssistRouteI;
    wrexcelprocess *wrexcelprocessItiem;            //Excel 读写


    void AgvItemWidgetInit();

    void treeWidgetInit();                          //treeWidge 控件初始化

    QMap<QString,int>getStation_ShowMap(QString floor,QString floor_);          //工作站名称 与 二维码绑定


signals:
    //创建AGV动作指令
    void sigAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int tye,agvORderTask agvORderTaskI);

    //创建 AGV 搬运任务
    void newAGVMoveTask(QString AGVIP,QString taskType,AGVCurrentTask AGVCurrentTaskI);


public slots:
    void ON_ItemTimer();

    void SlotsetCurrentItem(int row,int column);    //路线规则

    void SlotsetCurrentItem_2(int row,int column);  //路线信息

    void SlotsetCurrentItem_3(int row,int column);  //路线信息

    void SlotsetCurrentItem_4(int row,int column);  //AGV参数配置

    void SlotsetCurrentItem_5(int row,int column);  //自动门设置


private slots:

    void on_detail_Button_clicked();    //显示AGV 状态信息

    void on_AgvExecute_clicked();       //提交AGV 单个动作指令

    void on_CancelButton_clicked();     //取消AGV 单个动作指令

    void on_task_sure_clicked();        //创建AGV搬运任务

    void on_task_cancel_clicked();      //取消AGV搬运任务

/*************路线规则**************/
    void on_query_Button_clicked();     //根据路线编号 查找对应路线信息

    void on_addButton_clicked();        //创建路线编号

    void on_deleteButton_clicked();     //删除路线编号

    void on_addButton__clicked();       //添加路线编号 ---途经的子路线信息

    void on_deleteButton__clicked();    //删除路线编号 ---途经的子路线信息

    void on_updateButton_clicked();     //把路线编号信息提交到数据库


/*************路线信息**************/
    void on_AlterButton_clicked();      //导入路线二维码信息

    void on_query_Button_2_clicked();   //查询路线二维码信息

    void on_addButton_Info_clicked();   //添加路线二维码信息

    void on_deleteButton_Info_clicked();//删除路线二维码信息

    void on_updateButton_2_clicked();   //把路线二维码信息提交到数据库

/************   站点绑定界面   ***************/

    void on_query_Button_3_clicked();       //查询站点绑定信息

    void on_addButton_Info_2_clicked();     //添加站点信息

    void on_deleteButton_Info_2_clicked();  //删除站点信息

    void on_updateButton_3_clicked();       //更新站点信息到数据库

/************   自动门配置界面   ***************/
    void on_query_Button_4_clicked();           //查询自动门信息

    void on_addButton_Info_4_clicked();         //添加自动门

    void on_deleteButton_Info_4_clicked();      //删除自动门

    void on_updateButton_5_clicked();           //提交更新自动门

/************   AGV小车参数配置界面   ***************/

    void on_query_Button_agvip_clicked();       //查询AGV小车信息

    void on_addButton_agvip_clicked();          //添加AGV小车信息

    void on_deleteButton_agvip_clicked();       //删除AGV小车信息

    void on_updateButton_agvip_clicked();       //更新AGV小车信息

private:
    Ui::AgvItemWidget *ui;

    QList<QPushButton *>Actionbtns;

    void setAssistRouteI_show(assistRoute assistRouteI);                        //显示当前路线信息

    assistRoute getAssistRouteI_show();                                         //创建路线信息

    mianRoute getmianRoute_show();                                              //创建途经路线信息

    QList<RW_Excel>TableWidget(QMap<QString,mianRoute>mianRouteMap);            //途径的子路线新增 缓存列表

    agvSubTask currentAgvSubTask;
    QMap<int,agvSubTask > agvSubTaskListinit;
    void TableWidget_show_2();
    QList<RW_Excel>TableWidget_2(QMap<int,agvSubTask >SubTaskListinit); //显示当前路线信息

    Stationmap currentStationmap;
    QMap<QString,Stationmap >Stationmap_Map;
    void TableWidget_show_3();
    QList<RW_Excel>TableWidget_3(QMap<QString,Stationmap>Stationmap_); //显示当前路线信息

    doorSubTask doorSubTaskI;
    QMap<int,doorSubTask>doorSubTaskMap;
    void TableWidget_show_5();
    QList<RW_Excel>TableWidget_5(QMap<int,doorSubTask>doorSubTaskMap_); //显示当前路线信息


    AGVCurrentTask AGVCurrentTaskI;
    QMap<QString, AGVCurrentTask> AGVCurrentTaskMap;
    void TableWidget_show_4();
    QList<RW_Excel>TableWidget_4(QMap<QString, AGVCurrentTask> AGVCurrentTaskMap); //显示AGV信息


private slots:

    void ON_Pressed();

    void ON_Released();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_station_statrt_currentTextChanged(const QString &arg1);
    void on_station_dest_currentTextChanged(const QString &arg1);
    void on_taskstation_IP_currentTextChanged(const QString &arg1);
    void on_start_charge_clicked();
    void on_close_charge_clicked();
};

#endif // AGVITEMWIDGET_H
