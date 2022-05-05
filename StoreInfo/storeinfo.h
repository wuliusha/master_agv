#ifndef STOREINFO_H
#define STOREINFO_H

#include <QWidget>
#include <QTimer>

#include "project/binwidget.h"
#include "project/widgetbin.h"
#include "singleProject/single_project.h"
#include "queryServer/queryserver.h"
#include "queryServer/thread/threadinsert.h"
#include "queryServer/thread/threadquery.h"

namespace Ui {
class StoreInfo;
}

class StoreInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StoreInfo(QWidget *parent = 0);
    ~StoreInfo();

    QTimer *StoreInfoTimer;
    int StoreTimercount=0;
    QString currentUserNuber="";

    binwidget *binwidgetItem;

    QList<QPushButton *>Actionbtns;
    QMap<QString,WidgetBin*>WidgetBinQMap;

    QMap<QString,shelfBinInfo>shelfBinInfoMap;        //站点 的实时状态信息链表
    QMap<QString ,shelfBinInfo>currentBinInfoMap;     //当前货架架位信息显示

public slots:
    void upStoreInfoTimer();


public:
    void StoreInfoInit();

    void setCurrentBinInfo(int podId);       //设置当前显示的货架

    void newWidgetBin();                     //创建显示Item

    void UPdateWidgetBin();                 //更新显示 Item

    QMap<QString,shelfBinInfo> shelfBinInfoMap_query(int podId);           //获取 Bin 的基础信息

signals:
    void sinalStoreCheck(int ikey,QString LableNO);//查仓任务  到达提醒

private slots:

    void on_query_Button_clicked();

    void on_queryMaterial_returnPressed();

public slots:
    void ON_shelfBinInfo(shelfBinInfo shelfBinInfoItem);


private:
    Ui::StoreInfo *ui;

    ThreadInsert *ThreadInsertI;
    QThread *ThreadInsertItiem;

    threadQuery *threadQueryI;
    QThread *threadQueryItem;

    QMap<QString, shelfBinInfo> newshelfBinInfo();

public slots:
    void ON_Pressed();
    void ON_Released();

};

#endif // STOREINFO_H
