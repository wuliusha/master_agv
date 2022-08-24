#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QThread>

#include "login/login.h"
#include "agvCar/agvcarpool.h"
#include "record/dailyrecord.h"
#include "system/systemserver.h"
#include "ManagerInfo/managerinfo.h"

#include "Device/managerserver.h"
#include "MainDesktop/maindesktop.h"
#include "taskmanager/taskmanagerserver.h"
#include "queryServer/thread/threadserver.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void WidgetInit(bool Visible);     //控件初始化
    void NewClassItiem();               //初始化新建对象
    void CreateConnect();

public slots:
    void ON_UserLogin(QString UserNuber,QString UserName);//用户登录

private slots:

    void on_lab_Ico_clicked();

    void on_btn_System_clicked();

    void on_btn_Device_clicked();

    void on_btn_Edite_clicked();

    void on_btn_log_clicked();

    void ON_Pressed();

    void ON_Released();

private:
    Ui::MainWindow *ui;

    Login *loginItiem;                     //登录
    ManagerInfo *ManagerInfoItem;          //菜单管理
    dailyRecord *dailyRecordItem;          //日志

    threadServer *threadServerI;
    QThread *threadServerItem;

    MainDesktop *MainDesktopItem;           //主页

    managerServer *managerServerI;            //设备管理
    QThread *threaddeviceServer;

    systemServer *systemServerI;            //系统管理
    QThread *threadsystemServer;

    taskManagerServer *taskManagerServerI;  //任务管理
    QThread *threadtaskManagerServer;

    agvCarPool *agvCarPool1;
    QThread *ThreadagvCarPool;

    QList<QPushButton *>Actionbtns;

};
#endif // MAINWINDOW_H
