#ifndef MANAGERINFO_H
#define MANAGERINFO_H

#include <QWidget>
#include "Network/network_widget.h"
#include "singleProject/single_project.h"
#include "queryServer/queryserver.h"
#include "queryServer/thread/threadquery.h"
#include "wrexcelprocess/wrexcelprocess.h"

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
    bool qdebug_logstop=true;//日志显示
    int taskTypeId=0;
    QList<QString>taskTypeBoxList;
    QList<QPushButton *>Indexbtns;
    QList<QPushButton *>Actionbtns;

    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;


private slots:
    void ON_ManagerTimer();

    void on_Qury_Button_clicked();//以选择条件查询 日志

    void on_Cancel_Button_clicked();

    void on_Cancel_Button_2_clicked();

    void on_logInfo_Button_clicked();

    void on_Binchage_Button_clicked();

    void on_Network_Button_clicked();

    void on_stop_Button_clicked();

    void on_clear_Button_clicked();

    void on_sureLead_Button_clicked();

public:
    void ManagerInfoInit();

    void tableWidget_Show();

    void SlotsetCurrentItem(int row,int column);
    void slecetCurrentItem(QString LabelNo,QString Material,int add,int row, int column); //add 0 取消 1添加


signals:

public slots:
    void ON_Pressed();
    void ON_Released();


private:
    Ui::ManagerInfo *ui;
    QTimer *ManagerTimer;
    helperInfo helperInfoItem;

    ServerInit ServerInitItem;      //基础信息
    wrexcelprocess *wrexcelprocessItiem;//Excel 读写

    int currentPostWS02Mapcount=0;
    bool boolPostWS02Map=false;

    threadQuery *threadQueryI;
    QThread *threadQueryItem;

    Network_Widget *Network_WidgetItiem;//SAP测试

};

#endif // MANAGERINFO_H
