#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QThread>

#include "login/login.h"
#include "ManagerInfo/managerinfo.h"

#include "agvCar/agvcarpool.h"
#include "Device/deviceserver.h"
#include "MainDesktop/desktopserver.h"
#include "queryServer/thread/threadserver.h"
#include "taskmanager/taskmanagerserver.h"
#include "StoreInfo/storeinfoserver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void WidgetInit();//控件初始化
    void NewClassItiem();//初始化新建对象
    void CreateConnect();

public slots:
    void ON_UserLogin(QString UserNuber,QString UserName);//用户登录

private slots:

    void on_System_Button_clicked();//系统

    void on_Desktop_Button_clicked();

    void on_OutStore_Button_clicked();

    void on_StoreInfo_Button_clicked();

    void on_logInfo_Button_clicked();

private:
    Ui::MainWindow *ui;
    helperInfo helperInfoItem;

    Login *loginItiem;                      //登录
    ManagerInfo *ManagerInfoItiem;          //日志

    threadServer *threadServerI;
    QThread *threadServerItem;

    desktopServer *desktopServerI;          //主页
    QThread *threaddesktopServer;

    storeInfoServer *storeInfoServerI;      //库存管理
    QThread *threadstoreInfoServer;

    deviceServer *deviceServerI;            //设备管理
    QThread *threaddeviceServer;


    taskManagerServer *taskManagerServerI;  //任务管理
    QThread *threadtaskManagerServer;

    agvCarPool *agvCarPool1;
    QThread *ThreadagvCarPool;


};
#endif // MAINWINDOW_H
