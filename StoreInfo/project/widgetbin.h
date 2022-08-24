#ifndef WIDGETBIN_H
#define WIDGETBIN_H

#include <QObject>
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
#include"queryServer/queryserver.h"

class WidgetBin : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetBin(QWidget *parent = nullptr,int num = 0);


    void paintEvent(QPaintEvent*);
    bool SetValue(double Value);
    void updateGram(QString Action);
    void Seteffectandshow();

signals:
    void signalshelfBinInfo(shelfBinInfo shelfBinInfoI);

private slots:
    void AgvItemTimeout();

private:

    void enterEvent(QEvent*);
    void leaveEvent(QEvent *);
//  void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *e);

public:

    double CurrentValue=0.00;


    QString BinIndexdesc="";   //所属架位显示索引
    shelfBinInfo shelfBinInfoItem;

    QPixmap *pix;
    QColor color;

    QString podId="";
    int layer=0;
    int side=0;

    int stationX; //地图显示坐标
    int stationY;

    int sWidth;   //显示宽度
    int sHeight;  //显示高度

    int showX;
    int showY;

private:
    QTimer *timer;
    bool enter;
    double opacity=1.0;
    double lastOpacity;
    QGraphicsOpacityEffect* effect;

};

#endif // WIDGETBIN_H
