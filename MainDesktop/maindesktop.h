#ifndef MAINDESKTOP_H
#define MAINDESKTOP_H

#include <QWidget>
#include "anomaly.h"
#include "taskmanager/ess_single.h"
#include "singleProject/single_project.h"
#include "ChartView/chartview.h"
#include "ChartView/histogram.h"
#include "queryServer/queryserver.h"
#include "Monitoring/monitoringserver.h"

namespace Ui {
class MainDesktop;
}

class MainDesktop : public QWidget
{
    Q_OBJECT

public:
    explicit MainDesktop(QWidget *parent = 0);
    ~MainDesktop();
    QTimer *DesktopTimer;
    monitoringServer *monitoringServerI;
    QThread *threadmonitoringServer;

    countpick countpickItem;

    QMap<int, record_log>currentRecord_logMap;

    void MainDesktopInit();
    void SetstackedWidget(int Page);

    void UPTableWidgetShow();                       //定时更新统计界面

    void tableWidget_Show();                          //tableWidget 更新显示
    QList<RW_Excel>TableWidget();                     //任务列表
    QMap<int, SAPExcelInfo>seletSAPExcelInfoTask;

    QMap<int,email_message>email_messageMap;

signals:

public slots:
    void ON_MainDesktopTimer();

    void SlotsetCurrentItem_2(int row, int column);

private slots:
    void on_refreshButton_clicked();

    void on_refreshButton_pressed();

    void on_refreshButton_released();

private:
    Ui::MainDesktop *ui;
    QList<QPushButton *>Indexbtns;

    ChartView *ChartViewItiem;//饼形图
    Histogram *HistogramiIt0;//柱状图
    Anomaly *AnomalyItiem;//异常信息

};

#endif // MAINDESKTOP_H
