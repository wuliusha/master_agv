#ifndef HISTOGRAM_H
#define HISTOGRAM_H

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
struct Bench//工作台信息
{
    int ID=0;
    int Value1=-1;//发料数量
    int Value2=-1;//上架数量
};


namespace Ui {
class Histogram;
}

class Histogram : public QWidget
{
    Q_OBJECT

public:
    explicit Histogram(QWidget *parent = 0);
    ~Histogram();
    void paintEvent(QPaintEvent*);

    bool SetValue(int ID,int Value1,int Value2);
    int GetValue(int ID,int Value1);

signals:

public slots:
    void updateGram();


private:
    QPixmap *pix;
    QVector<int> Value;
    QColor color;
    QList<Bench>BenchList;
private:
    Ui::Histogram *ui;
};

#endif // HISTOGRAM_H
