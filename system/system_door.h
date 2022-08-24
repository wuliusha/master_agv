#ifndef SYSTEM_DOOR_H
#define SYSTEM_DOOR_H

#include <QWidget>

#include "sql_single/query_single.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"

namespace Ui {
class system_door;
}

class system_door : public QWidget
{
    Q_OBJECT

public:
    explicit system_door(QWidget *parent = nullptr);
    ~system_door();

    void system_doorInit();         //自动门类  初始化函数

    doorSubTask doorSubTaskI;
    QMap<int,doorSubTask>doorSubTaskMap;
    void TableWidget_show_door();
    QList<RW_Excel>TableWidget_door(QMap<int,doorSubTask>doorSubTaskMap_); //显示当前路线信息


private slots:

    void SlotsetCurrentItem_door(int row,int column);       //路线规则

    void on_query_door_clicked();

    void on_add_door_clicked();

    void on_delete_door_clicked();

    void on_update_door_clicked();

    void ON_Pressed();

    void ON_Released();

private:
    Ui::system_door *ui;
    QList<QPushButton *>Actionbtns;

};

#endif // SYSTEM_DOOR_H
