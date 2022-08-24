#include "imagewidget.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <math.h>

ImageWidget::ImageWidget(QPixmap *pixmap)
{
    m_pix = *pixmap;
    setAcceptDrops(true);//If enabled is true, this item will accept hover events; otherwise, it will ignore them. By default, items do not accept hover events.
    m_scaleValue = 5.0;
    m_scaleDafault = 0;
    m_isMove = false;

    setScale(m_scaleValue);
}

QRectF ImageWidget::boundingRect() const
{
    return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,
                  m_pix.width(), m_pix.height());
}

void ImageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *)
{
    painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
    painter->setFont(QFont("Arial",12));
    for(int i=0;i<AgvItemcarList.length();i++){
        if(AgvItemcarList[i].floor==floor){
            painter->setBrush(AgvItemcarList[i].color);
            painter->setRenderHint(QPainter::Antialiasing);
            if(AgvItemcarList[i].angle%180==0){
                painter->drawRoundedRect(QRect(int(AgvItemcarList[i].stationX-15),int(AgvItemcarList[i].stationY-20), 40.0, 30.0), 16.0, 13.0);
                painter->drawText(int(AgvItemcarList[i].stationX),int(AgvItemcarList[i].stationY),QString("%1").arg(AgvItemcarList[i].agvNum));
            }else{
                painter->drawRoundedRect(QRect(int(AgvItemcarList[i].stationX-15),int(AgvItemcarList[i].stationY-20), 30.0, 40.0), 13.0, 16.0);
                painter->drawText(int(AgvItemcarList[i].stationX-10),int(AgvItemcarList[i].stationY+20),QString("%1").arg(AgvItemcarList[i].agvNum));
            }
        }
    }
}

void ImageWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        m_isMove = true;//标记鼠标左键被按下
    }
    else if(event->button() == Qt::RightButton)
    {
        ResetItemPos();//右击鼠标重置大小  图片大小
        SesetItemPos(scaleValue_01);//右击鼠标重置大小  初始化大小
    }
}

void ImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_isMove)
    {
        QPointF point = (event->pos() - m_startPos)*m_scaleValue;
        moveBy(point.x(), point.y());
    }
}

void ImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    m_isMove = false;//标记鼠标左键已经抬起
}

//1 QPointQMouseEvent::globalPos();//窗口坐标，这个是返回鼠标的全局坐标
//2 QPointQCursor::pos()[static];//返回相对显示器的全局坐标
//3 QPointQMouseEvent::pos();//返回相对这个widget的位置
//4 QPointQWidget::pos();//这个属性获得的是当前目前控件在父窗口中的位置
//5 constQPointF&QMouseEvent::screenPos()const;//和QPoint QMouseEvent::globalPos() 值相同，但是类型更高精度的QPointF
//6 QPointQWidget::mapToGlobal(constQPoint& pos)const;//将窗口坐标转换成显示器坐标
//7 QPointQWidget::mapFromGlobal(constQPoint& pos)const;//将显示器坐标转换成窗口坐标
//8 QPointQWidget::mapToParent(constQPoint& pos)const;//将窗口坐标获得的pos转换成父类widget的坐标
//9 QPointQWidget::mapFromParent(constQPoint& pos)const;//将父类窗口坐标转换成当前窗口坐标
//10 QPointQWidget::mapTo(constQWidget* parent,constQPoint& pos)const;//将当前窗口坐标转换成指定parent坐标
//12 Qpoint pt=cursor().pos();//获取当前鼠标位置

void ImageWidget::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        left_Double=true;
        mousePoint = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        for(int i=0;i<AgvItemcarList.length();i++){
            AgvItemcarList[i].stationX=int(mousePoint.rx());
            AgvItemcarList[i].stationY=int(mousePoint.ry());
        }
        qDebug()<<" mousePoint 1"<<mousePoint.rx()<<mousePoint.ry();
    }
    if(event->button() == Qt::RightButton){
        right_Double=true;
        //emit signalPoint(mousePoint,"right");//left right
    }
}

void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent *event)//鼠标滚轮事件
{
    if((event->delta() > 0)&&(m_scaleValue >= 30))//最大放大到原始图像的50倍
    {
        return;
    }
    else if((event->delta() < 0)&&(m_scaleValue <= m_scaleDafault))//图像缩小到自适应大小之后就不继续缩小
    {
        ResetItemPos();//重置图片大小和位置，使之自适应控件窗口大小
    }
    else
    {
        qreal qrealOriginScale = m_scaleValue;
        if(event->delta() > 0)//鼠标滚轮向前滚动
        {
            m_scaleValue*=1.1;//每次放大10%
        }
        else
        {
            m_scaleValue*=0.9;//每次缩小10%
        }
        setScale(m_scaleValue);
        if(event->delta() > 0)
        {
            moveBy(-event->pos().x()*qrealOriginScale*0.1, -event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            moveBy(event->pos().x()*qrealOriginScale*0.1, event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
    }
}

void ImageWidget::setQGraphicsViewWH(int nwidth, int nheight)//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
{
    int nImgWidth = m_pix.width();
    int nImgHeight = m_pix.height();
    qreal temp1 = nwidth*1.0/nImgWidth;
    qreal temp2 = nheight*1.0/nImgHeight;
    if(temp1>temp2)
    {
        m_scaleDafault = temp2;
    }
    else
    {
        m_scaleDafault = temp1;
    }
    setScale(m_scaleDafault);
    m_scaleValue = m_scaleDafault;
}

QPixmap ImageWidget::getQGraphicsViewWH()
{
    return m_pix;
}

QPointF ImageWidget::getmousePoint()
{
    left_Double=false;
    right_Double=false;
    return mousePoint;
}

void ImageWidget::setAgvItemcarList_date(AgvItem AgvItemI)
{
    for(int i=0;i<AgvItemcarList.length();i++){
        if(AgvItemcarList[i].agvip==AgvItemI.agvip){
            AgvItemcarList[i]=AgvItemI;
        }
    }
}

void ImageWidget::ResetItemPos()//重置图片位置
{
    m_scaleValue = m_scaleDafault; //缩放比例回到一开始的自适应比例
    setScale(m_scaleDafault);     //缩放到一开始的自适应大小
    setPos(0,0);
}

void ImageWidget::newQGraphicsItem()
{

}

void ImageWidget::SesetItemPos(qreal  scaleValue)
{
    scaleValue_01=scaleValue;
    m_scaleValue*=scaleValue;     //每次缩小10%
    setScale(m_scaleValue);        //缩放到一开始的自适应大小
    setPos(0,0);
}

qreal ImageWidget::getScaleValue() const
{
    return m_scaleValue;
}
