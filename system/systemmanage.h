#ifndef SYSTEMMANAGE_H
#define SYSTEMMANAGE_H

#include <QWidget>
#include "system_agv.h"
#include "system_door.h"
#include "system_station.h"

namespace Ui {
class systemManage;
}

class systemManage : public QWidget
{
    Q_OBJECT

public:
    explicit systemManage(QWidget *parent = nullptr);
    ~systemManage();

    void systemManageInit();            //系统配置管理初始化



private:
    Ui::systemManage *ui;

    system_agv *system_agvI;
    system_door *system_doorI;
    system_station *system_stationI;

};

#endif // SYSTEMMANAGE_H
