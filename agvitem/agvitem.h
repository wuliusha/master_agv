#ifndef AgvItem_H
#define AgvItem_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QTimer>
#include "agviteminfo.h"
#include <QGraphicsOpacityEffect>
#include "iconhelper/iconhelper.h"
class AgvItem : public QWidget
{
    Q_OBJECT
public:
    explicit AgvItem(QWidget *parent = 0);

    bool AgvItemMove=false;
    agviteminfo *agviteminfoItem;
private:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *event);


public:
    QColor color;
    int stationX; //地图显示坐标
    int stationY;
    int sWidth; //显示宽度
    int sHeight;  //显示高度
    int floor;
    int showX=0,showY=0;

private:
    QTimer *timer;
    bool enter;
    double opacity;
    double lastOpacity;
    QGraphicsOpacityEffect* effect;

private slots:
    void timeout();
signals:
    void sigCarPressed(int carNum);

public slots:

};

#endif // AgvItem_H
