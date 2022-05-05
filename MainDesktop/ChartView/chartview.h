#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QWidget>
#include<qdebug.h>
#include <complex>
#include <QPainter>
#include <QMap>
struct painterpick{
    double textPosX=0.00;       //今天的数量
    double textPosY=0.00;    //已完成数量
    double num=0.00;  //未完成数量
    QString percentStr="";       //待发DN
};

namespace Ui {
class ChartView;
}

class ChartView : public QWidget
{
    Q_OBJECT

public:
    explicit ChartView(QWidget *parent = 0);
    ~ChartView();
    //QPainter painter;

    void SetChartPercent(int finishcount, int unfinishcount, int DN_count,int SL_count,int LM_count,int Other_count);

protected:
    void paintEvent(QPaintEvent *e);


private:
    QString getPercentInt(const QString &percentStr);
private:
    Ui::ChartView *ui;

    QTimer *Timer;
    QMap<QString, int> m_answerMap;
    QList<int> m_numList;
    QList<QString> m_answerStrList;
    int m_nPeopleCount=0;
    qreal m_pi = 3.1415;

};

#endif // CHARTVIEW_H
