#include "agvdesktop.h"
#include "ui_agvdesktop.h"

agvdesktop::agvdesktop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::agvdesktop)
{
    ui->setupUi(this);
    AGVTimer = new QTimer(this);
    connect(AGVTimer,&QTimer::timeout,this,&agvdesktop::ON_AGVTimer);
    AGVTimer->start(1000);
}

agvdesktop::~agvdesktop()
{
    delete ui;
}

void agvdesktop::AGVDesktopInit()
{
    AGVServerItiem=new AGVServer;
    AGVServerItiem->listen(QHostAddress::Any,9001);
    ThreadAGVServer=new QThread();
    AGVServerItiem->moveToThread(ThreadAGVServer);
    ThreadAGVServer->start();

}

void agvdesktop::ON_AGVTimer()
{

}
