#ifndef BINWIDGET_H
#define BINWIDGET_H

#include <QWidget>
#include <QMouseEvent>

#include "taskmanager/ess_single.h"
#include "queryServer/queryserver.h"
#include "singleProject/single_project.h"
#include "queryServer/thread/threadinsert.h"

namespace Ui {
class binwidget;
}

class binwidget : public QWidget
{
    Q_OBJECT

public:
    explicit binwidget(QWidget *parent = nullptr);
    ~binwidget();
    QTimer *binwidgetTimer;

    QList<QPushButton *>Actionbtns;
    shelfBinInfo shelfBinInfoItem;
    QString currentUserNuber="";

    void binwidgetIint();
    void UPShelfNuberInfoShow(shelfBinInfo  shelfBinInfoI,QString Action,QString UserNuber);//更新显示此货架上物料信息

    QList<RW_Excel> MaterialTableWidget(QMap<QString ,materialShelfbin > materialMap);//转化位Tablewidget 数据显示

    bool UPShelfInfoChange();                              //更新 架位 Bin 的基础信息

    void new_SAPExcelInfo_move();                          //创建移库任务

signals:
    void sig_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);  //创建MES任务

    void sig_containerCode_clear(QString shelfBindesc,QString containerCode);    //清空库位

public slots:
    void ON_binwidgetTimer();

    void SlotsetCurrentItem(int row,int column);

    void ON_Pressed();
    void ON_Released();

private slots:
    void on_NextButton_clicked();

    void on_LastButton_clicked();

    void on_AlterButton_clicked();

    void on_AgvExecute_clicked();

    void on_enableButton_clicked();

    void on_enableButton_show_clicked();

    void on_taskType_currentTextChanged(const QString &arg1);

    void on_clear_Button_clicked();

private:
    Ui::binwidget *ui;
    ServerInit ServerInitItem;      //基础信息
    QMap<QString ,materialShelfbin >materialshelfBinMap;//ikey -架位  多对一 物料件号-仓号-批次作为唯一键值

};

#endif // BINWIDGET_H
