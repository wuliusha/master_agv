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

    shelfBinInfo shelfBinInfoItem;
    QString currentUserNuber="";

    void binwidgetIint();
    void UPShelfNuberInfoShow(shelfBinInfo  shelfBinInfoI,QString Action,QString UserNuber);//更新显示此货架上物料信息

    QList<RW_Excel> MaterialTableWidget(QMap<QString ,materialShelfbin > materialMap);//转化位Tablewidget 数据显示

    bool UPShelfInfoChange();                              //更新 架位 Bin 的基础信息

    WWYLPOST WWYLPOSTI;
    WWYLPOST getWWYLPOSTI(WWYLPOST WWYLPOST0);              //把SAP 任务状态 转换为post 并实时更新更新到 MES

    void new_SAPExcelInfo_move();                          //创建移库任务

    void tableWidget_Show();                                //tableWidget 更新显示
    QList<RW_Excel>TableWidget();                           //任务列表

signals:
    void sig_SAPExcelInfo_new(SAPExcelInfo SAPExcelInfoI);  //创建MES任务

    void sig_containerCode_clear(QString shelfBindesc,QString containerCode,QString type);    //清空库位 0本地库  1远程库

    void sig_taskCodes_WW(QString iKey, WWYLPOST WWYLPOSTII, QString UserBadge, int pathId);  //通过接口创建出入库任务

public slots:

    void ON_binwidgetTimer();

private slots:

    void on_AlterButton_clicked();

    void on_AgvExecute_clicked();

    void on_enableButton_clicked();

    void on_taskType_currentTextChanged(const QString &arg1);

    void on_clear_Button_clicked();

    void on_CancelButton_clicked();

    void on_clear_Button_2_clicked();

    void on_queryButton_clicked();

    void on_Binstatus_box_currentTextChanged(const QString &arg1);

private:
    Ui::binwidget *ui;
    ServerInit ServerInitItem;      //基础信息
    QMap<QString ,shelfBinInfo >seletshelfBinInfoMap;          //查询工单信息
    QMap<QString ,materialShelfbin >materialshelfBinMap;//ikey -架位  多对一 物料件号-仓号-批次作为唯一键值

};

#endif // BINWIDGET_H
