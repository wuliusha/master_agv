#include "systemmanage.h"
#include "ui_systemmanage.h"

systemManage::systemManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::systemManage)
{
    ui->setupUi(this);
    systemManageInit();            //系统配置管理初始化

}

systemManage::~systemManage()
{
    delete ui;
}

void systemManage::systemManageInit()
{
    system_agvI=new system_agv;
    ui->tabWidget->insertTab(0,system_agvI, "AGV配置");

    system_doorI=new system_door;
    ui->tabWidget->insertTab(1,system_doorI, "自动门配置");

    system_stationI=new system_station;
    ui->tabWidget->insertTab(2,system_stationI, "站点配置");

    ui->tabWidget->setCurrentIndex(0);

}
