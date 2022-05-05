#ifndef ANOMALY_H
#define ANOMALY_H

#include <QWidget>
#include <QtCharts/QChartGlobal>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QBarSeries>
#include<QChart>
#include<qdebug.h>
#include "queryServer/thread/threadquery.h"

struct Anoma//工作台信息
{
    QString TimerID="";//时间戳标识
    QString message="";//异常信息
};
namespace Ui {
class Anomaly;
}

class Anomaly : public QWidget
{
    Q_OBJECT

public:
    explicit Anomaly(QWidget *parent = 0);
    ~Anomaly();
    void paintEvent(QPaintEvent*);
    QTimer *StTimer;
    int AnomalyTimercount=0;bool AnomalyTimerbool=true;
    QMap<int,email_message>currentSysErrorMap;

    void AnomalyInit();//界面 初始化
    void slecetCurrentItem(QString errorMassege,int add,int row, int column);  //add 0 取消 1添加

    QList<RW_Excel> TableWidget(QMap<int,email_message>sysErrorMap);

    void tableWidget_Show();//tableWidget 更新显示
    bool SetValue(QString TimerID,QString message,QString Action);//Action 1 添加 0删除
    QString GetValue(int ID);

public slots:
    void updateGram();
    void AnomalyTimer();
    void SlotsetCurrentItem(int row,int column);

private:
    Ui::Anomaly *ui;
    QPixmap *pix;
    QColor color;
    QList<Anoma>AnomaStringlist;
};

#endif // ANOMALY_H
