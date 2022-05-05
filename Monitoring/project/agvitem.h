#ifndef AGVITEM_H
#define AGVITEM_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include "agvitemwidget.h"


class AgvItem : public QWidget
{
    Q_OBJECT

public:
    explicit AgvItem(QWidget *parent = nullptr, int num = 0);

signals:
    void sigAgvItemClick();

private slots:
    void AgvItemTimeout();

private:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent *);
//  void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent *e);

public:
    int floor;
    int id;     //小车编号
    int agvNum; //小车编号
    QString agvip;
    QColor color;
    int angle=0;

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

#endif // AGVITEM_H
