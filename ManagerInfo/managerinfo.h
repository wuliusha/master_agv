#ifndef MANAGERINFO_H
#define MANAGERINFO_H

#include <QWidget>
#include "StoreInfo/storeinfo.h"
#include "taskmanager/taskmanager.h"


namespace Ui {
class ManagerInfo;
}

class ManagerInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerInfo(QWidget *parent = 0);
    ~ManagerInfo();
    bool booltable=true;
    QList<QPushButton *>Actionbtns;
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;


    StoreInfo *StoreInfoItem;        //库存管理
    taskManager *taskmanagerItem;    //任务管理

private slots:
    void ON_ManagerTimer();

public:
    void ManagerInfoInit();

signals:

public slots:
    void ON_Pressed();

    void ON_Released();

private:
    Ui::ManagerInfo *ui;
    QTimer *ManagerTimer;

    ServerInit ServerInitItem;      //基础信息
    wrexcelprocess *wrexcelprocessItiem;//Excel 读写

    int currentPostWS02Mapcount=0;
    bool boolPostWS02Map=false;

    threadQuery *threadQueryI;
    QThread *threadQueryItem;


};

#endif // MANAGERINFO_H
