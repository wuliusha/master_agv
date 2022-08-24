#ifndef AGVITEMWIDGET_H
#define AGVITEMWIDGET_H

#include <QWidget>
#include "agvCar/AgvStatus.h"

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

    //AGV管理界面初始化
    void AgvItemWidgetInit();

    //工作站名称 与 二维码绑定
    QMap<QString,int>getStation_ShowMap(QString floor,QString floor_);

signals:
    //创建AGV动作指令
    void sigAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int tye,agvORderTask agvORderTaskI);

    //创建 AGV 搬运任务
    void newAGVMoveTask(QString AGVIP,QString taskType,AGVCurrentTask AGVCurrentTaskI);


public slots:
    void ON_ItemTimer();


private slots:

    void on_detail_Button_clicked();    //显示AGV 状态信息

    void on_AgvExecute_clicked();       //提交AGV 单个动作指令

    void on_CancelButton_clicked();     //取消AGV 单个动作指令

    void on_task_sure_clicked();        //创建AGV搬运任务

    void on_task_cancel_clicked();      //取消AGV搬运任务

    void on_start_charge_clicked();     //手动开始充电任务

    void on_close_charge_clicked();     //手动结束充电任务


private:
    Ui::AgvItemWidget *ui;
    QList<QPushButton *>Actionbtns;

private slots:

    void ON_Pressed();

    void ON_Released();

    void on_station_statrt_currentTextChanged(const QString &arg1);    //工作站名称 与 二维码绑定

    void on_station_dest_currentTextChanged(const QString &arg1);      //工作站名称 与 二维码绑定

    void on_taskstation_IP_currentTextChanged(const QString &arg1);    //工作站名称 与 二维码绑定

};

#endif // AGVITEMWIDGET_H
