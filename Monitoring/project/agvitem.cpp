#include "agvitem.h"

AgvItem::AgvItem(QWidget *parent,int num) : QWidget(parent),stationX(0),stationY(0)
{
    id = num;
    effect = new QGraphicsOpacityEffect(this);
    opacity = 1.0;
    lastOpacity = 1.0;
    effect->setOpacity(opacity);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&AgvItem::AgvItemTimeout);
    timer->start(500);
}

void AgvItem::paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter painter(this);  // 创建QPainter一个对象
    painter.setBrush(color); // 画一个圆角矩形
    painter.setRenderHint(QPainter::Antialiasing);
    if(angle%180==0){
        this->resize(40,50);
        painter.drawRoundedRect(QRect(0.0, 0.0, 40.0, 30.0), 16.0, 13.0);
    }else{
        this->resize(50,40);
        painter.drawRoundedRect(QRect(0.0, 0.0, 30.0, 40.0), 13.0, 16.0);
    }

    painter.setPen(color);
    pen.setColor(QColor(0,0,0));
    pen.setWidth(5);
    painter.setFont(QFont("Arial",12));
    painter.setPen(pen);

    if(angle%180==0){
        painter.drawText(13,23,QString("%1").arg(id));
    }else{
        painter.drawText(9,28,QString("%1").arg(id));
    }

    //painter.drawText(9,28,QString("%1").arg(id-1));


}

void AgvItem::enterEvent(QEvent *)
{
    enter = true;
    timer->stop();
    effect->setOpacity(1.0);
    //this->setGraphicsEffect(effect);
    this->update();

}

void AgvItem::leaveEvent(QEvent *)
{
    //this->resize(sWidth,sHeight);
    this->update();
    //timer->start(300);
}

void AgvItem::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        float showX = (float)e->x(); float showY = (float)e->y();
        emit sigAgvItemClick();
        qDebug()<<showX<<showY<<"AgvItem    **********59";
    }
}

void AgvItem::AgvItemTimeout()
{
//    if((uint)(opacity*10) == 10)
//        lastOpacity = 1.0;
//    else if((uint)(opacity*10) == 5)
//        lastOpacity = 0.5;
//    if((uint)(lastOpacity*10) == 10)
//        opacity -= 0.1;
//    else if((uint)(lastOpacity*10) == 5)
//        opacity += 0.1;

    effect->setOpacity(opacity);
    this->setGraphicsEffect(effect);
    this->update();

}

