#include "agvitem.h"

AgvItem::AgvItem(QWidget *parent) :
    QWidget(parent),stationX(0),stationY(0)
{
    effect = new QGraphicsOpacityEffect(this);
    opacity = 1.0;
    lastOpacity = 1.0;
    effect->setOpacity(opacity);
    this->setGraphicsEffect(effect);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&AgvItem::timeout);
    timer->start(1000);

    color="#FF0000";
    this->resize(58,48);this->sWidth=110;this->sHeight=60;
    this->showX=1500;this->showY=150;
    this->move(this->showX,this->showY);
    this->setCursor(Qt::CrossCursor);

    agviteminfoItem =new agviteminfo;agviteminfoItem->move(180,100);
}


void AgvItem::paintEvent(QPaintEvent *)
{
    QPainter painter(this);             // 创建QPainter一个对象
    QPen pen;
    color="#FEFEFE";
    // 画一个圆角矩形
    painter.setBrush(color);
    //painter.drawRoundedRect(QRect(7.0, 14.0, 62.0, 42.0), 20.0, 15.0);
    painter.setPen(color);
    pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
    pen.setWidth(5);
    //painter.setFont(QFont("Arial",12));
    painter.setPen(pen);
    this->resize(sWidth,sHeight+60);

    painter.setRenderHint(QPainter::Antialiasing, true);    // 反走样
    QFont iconFont=IconHelper::Instance()->GetIcon(0xf101,20);//获取 图形字体
    painter.setFont(iconFont);
    QChar c=0xf0f9;//0xf0f9
    painter.drawText(sWidth/2-50,sHeight,c);

    //    QTransform transform;
    //    transform.rotate(90.0);//旋转90度
    //    painter.setTransform(transform);
    //    //painter.translate(sWidth / 2, sHeight / 2);
    //    //painter.rotate(90);

}

void AgvItem::enterEvent(QEvent *)
{
    enter = true;AgvItemMove=true;
    this->resize(sWidth,sHeight);
    color="#FF0000";
    timer->stop();
    effect->setOpacity(1.0);
    this->setGraphicsEffect(effect);
    this->update();
}

void AgvItem::leaveEvent(QEvent *)
{
    this->resize(sWidth,sHeight);
//    color="#FFFF00";
    this->update();
    timer->start(300);
    AgvItemMove=false;
}

void AgvItem::mousePressEvent(QMouseEvent *)
{

}

void AgvItem::mouseMoveEvent(QMouseEvent *event)
{
    //这里必须使用buttons()
    if(event->buttons() & Qt::LeftButton) //进行的按位与
    {
        float showX = event->globalX(); float showY = event->globalY();
        //qDebug()<<showX<<showY<<"AgvItem    **********59";
    }
}

void AgvItem::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        float showX = (float)e->x(); float showY = (float)e->y();
        //qDebug()<<showX<<showY<<"RightButton    **********59";
    }
}

void AgvItem::mouseReleaseEvent(QMouseEvent *event)
{
    if((event->globalX()-showX<-20 || event->globalX()-showX>20)
            ||(event->globalY()-showY<-10 || event->globalY()-showY>10)){
        if(AgvItemMove){
            showX=event->globalX();
            showY=event->globalY();
            this->move(event->globalX()-(sWidth/3-5),event->globalY()-(sHeight/3+20));
        }
    }
    agviteminfoItem->hide();
    agviteminfoItem->show();
}

void AgvItem::timeout()
{
    if((uint)(opacity*10) == 10)
        lastOpacity = 1.0;
    else if((uint)(opacity*10) == 5)
        lastOpacity = 0.5;
    if((uint)(lastOpacity*10) == 10)
        opacity -= 0.1;
    else if((uint)(lastOpacity*10) == 5)
        opacity += 0.1;
    effect->setOpacity(opacity);
    this->setGraphicsEffect(effect);
    this->update();
}


