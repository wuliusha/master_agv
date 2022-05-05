#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QPoint>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <QObject>
#include <QDebug>


enum Enum_ZoomState{
    NO_STATE,
    RESET,
    ZOOM_IN,
    ZOOM_OUT
};

// class ImageWidget :public QObject, QGraphicsItem
class ImageWidget :public QGraphicsItem
{
    //Q_OBJECT
public:

    ImageWidget(QPixmap *pixmap);
    QRectF  boundingRect() const;
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void    wheelEvent(QGraphicsSceneWheelEvent *event);
    void    ResetItemPos();
    void    newQGraphicsItem(); //new 子类图元
    void    SesetItemPos(qreal  scaleValue);     //设置初始化时比例
    void    mousePressEvent(QGraphicsSceneMouseEvent *event);
    void    mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void    mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void    mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    qreal   getScaleValue() const;
    void    setQGraphicsViewWH(int nwidth,int nheight);
    QPixmap getQGraphicsViewWH();//获取当前图片大小
    QPointF getmousePoint();


signals:
    //void signalPoint(QPointF mousePoint,QString Type);//left
public:
    QPointF mousePoint;
    bool    left_Double=false;

private:
    qreal   m_scaleValue;
    qreal  scaleValue_01;

    qreal   m_scaleDafault;
    QPixmap m_pix;
    int     m_zoomState;
    bool    m_isMove;
    QPointF m_startPos;




};
#endif // IMAGEWIDGET_H
