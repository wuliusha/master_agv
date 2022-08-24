#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>
#include "ess_single.h"
#include "agvCar/agvcar.h"

#include "httpserver/httpserver.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"
#include "queryServer/thread/threadquery.h"
#include "wrexcelprocess/wrexcelprocess.h"

namespace Ui {
class taskManager;
}

class taskManager : public QWidget
{
    Q_OBJECT

public:
    explicit taskManager(QWidget *parent = nullptr);
    ~taskManager();
    int postStatuscount=0;
    QString robotCodeiKey="";          //机器人编码
    QString taskStatusiKey="";         //agvStatusiKey为空时: AGV系统往 MES服务器实时更新 任务的状态信息
    QMap<QString,QString>currentlabelMap;


    void taskManagerInit();

    void postAgvStatus_ESS(QString robotCode);                  //AGV系统往 实时更新 海柔AGV的状态信息

public slots:

    void ON_taskManagerTimer();

    void SlotsetCurrentItem(int row,int column);


public:

    QTimer *StTimer;
    bool countbool=true;
    int TableWidgetcount=0;
    ServerInit ServerInitItem;      //基础信息
    ServerItem CurrentServerItem;   //需要实时更信息 链表表 整合

    QMap<QString,QString>actionIdMap;                 //动作指令集
    SAPExcelInfo seletSAPExcelInfoI;
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;

    void tableWidget_Show();                          //tableWidget 更新显示
    QList<RW_Excel>TableWidget();                     //任务列表

signals:
    void sig_deleteSAPExcelInfoTask(SAPExcelInfo seletSAPExcelInfoI);

private slots:

    void on_Delete_Button_clicked();

    void on_Qury_Button_clicked();

     void on_Cancel_Button_clicked();

     void on_unbundle_clicked();

     void on_rebundle_clicked();

     void on_unbundle_ess_clicked();

private:
    Ui::taskManager *ui;

    bool checkBoxbool=false;
    QList<QPushButton *>Indexbtns;
    QList<QPushButton *>Actionbtns;

    wrexcelprocess *wrexcelprocessItiem;//Excel 读写

};

#endif // TASKMANAGER_H
