#ifndef MAINDESKTOP_H
#define MAINDESKTOP_H

#include <QWidget>
#include "Monitoring/monitoring.h"
#include "queryServer/queryserver.h"

#include "taskmanager/ess_single.h"
#include "singleProject/single_project.h"


namespace Ui {
class MainDesktop;
}

class MainDesktop : public QWidget
{
    Q_OBJECT

public:
    explicit MainDesktop(QWidget *parent = 0);
    ~MainDesktop();
    bool Desktop=true;
    int TableWidgetcount=0;
    QTimer *DesktopTimer;
    monitoring *monitoringI;

    void MainDesktopInit();

    QMap<int,email_message>email_messageMap;
    QMap<int, record_log>currentRecord_logMap;

    int taskStatusiKey_count=0;
    QMap<QString,int> taskStatusiKeylist;                   //agvStatusiKey为空时: AGV系统往 MES服务器实时更新 任务的状态信息

    SAPExcelInfo seletSAPExcelInfoI;
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;

    AGVCurrentTask *AGVCurrentTaskI;
    QMap<QString,AGVCurrentTask*>AGVCurrentTaskMap;         //当前AGV状态信息

    void tableWidget_Show();                                //tableWidget 更新显示
    QList<RW_Excel>TableWidget();                           //任务列表

    void tableWidget_Show_agv();                            //tableWidget 更新显示
    QList<RW_Excel>TableWidget_agv();                       //任务列表

    void CancelInit(QString taskType);                      //更新显示

    //******************************* 设备任务状态更新部分*****************************//

    bool setAGVCurrentTaskMap_Status(QMap<QString,AGVCurrentTask*>AGVCurrentTaskMap);//更新AGV状态信息


signals:

    void sig_deleteSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI);   //异常删除任务

    void sig_UPSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI);      //更新SAP 任务状态

    //手动更新AGV当前动作指令状态
    void sig_AGVCurrentTaskAction(QString AGVIP,QString Type, int Action);

public slots:
    void ON_MainDesktopTimer();

    void SlotsetCurrentItem(int row, int column);

    void SlotsetCurrentItem_2(int row, int column);



    void slotAGVCurrentTaskMap(QMap<QString,AGVCurrentTask*>AGVCurrentTaskMapI);

    void ON_Click();

private slots:

    void on_taskStatusBox_ESS_currentTextChanged(const QString &arg1);

    void on_taskFnish__clicked();

    void on_Delete_Button_clicked();

    void on_taskStatusBox_AGV_currentTextChanged(const QString &arg1);

    void on_Button_Init_clicked();

private:
    Ui::MainDesktop *ui;
    QPushButton *currentlabel;
};

#endif // MAINDESKTOP_H
