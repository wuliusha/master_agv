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
    int StoreTimercount=16;
    bool storeTimerbool=true;
    QString currentUserNuber="";

    binwidget *binwidgetItem;
    QMap<QString,WidgetBin*>WidgetBinQMap;
    QMap<QString ,shelfBinInfo>currentBinInfoMap;     //当前货架架位信息显示

public slots:
    void upStoreInfoTimer();


public:
    void StoreInfoInit();

    void newWidgetBin();                     //创建显示Item

    void UPdateWidgetBin();                 //更新显示 Item

signals:
    void sinalStoreCheck(int ikey,QString LableNO);//查仓任务  到达提醒

    void sig_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);  //创建MES任务

    void sig_containerCode_clear(QString shelfBindesc,QString containerCode,QString type);    //清空库位 0本地库  1远程库


private slots:

    void on_query_Button_clicked();

    void on_queryLineEdit_returnPressed();

    void on_pushButton_clicked();



public slots:
    void ON_shelfBinInfo(shelfBinInfo shelfBinInfoItem);

    //创建 SAP 任务
    void ON_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);

    //清空库位
    void ON_containerCode_clear(QString shelfBindesc,QString containerCode,QString type);



private:
    Ui::StoreInfo *ui;

    ThreadInsert *ThreadInsertI;
    QThread *ThreadInsertItiem;

    threadQuery *threadQueryI;
    QThread *threadQueryItem;

    QMap<QString, shelfBinInfo> newshelfBinInfo();


};

#endif // STOREINFO_H
