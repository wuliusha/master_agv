#ifndef SYSTEM_STATION_H
#define SYSTEM_STATION_H

#include <QWidget>

#include "sql_single/query_single.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"


namespace Ui {
class system_station;
}

class system_station : public QWidget
{
    Q_OBJECT

public:
    explicit system_station(QWidget *parent = nullptr);
    ~system_station();

    void system_stationInit();          //站点类 初始化函数

    Stationmap currentStationmap;
    QMap<QString,Stationmap >Stationmap_Map;
    void TableWidget_show_station();
    QList<RW_Excel>TableWidget_station(QMap<QString,Stationmap>Stationmap_); //显示当前路线信息



private slots:

    void SlotsetCurrentItem_station(int row,int column);    //站点信息

    void on_query_station_clicked();

    void on_add_station_clicked();

    void on_delete_station_clicked();

    void on_update_station_clicked();



    void ON_Pressed();

    void ON_Released();

private:
    Ui::system_station *ui;

    QList<QPushButton *>Actionbtns;

};

#endif // SYSTEM_STATION_H
