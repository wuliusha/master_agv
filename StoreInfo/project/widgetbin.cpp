#include "widgetbin.h"

WidgetBin::WidgetBin(QWidget *parent,int num) : QWidget(parent),stationX(0),stationY(0)
{

    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());

    pix->fill(QColor(66,66,66));

    effect = new QGraphicsOpacityEffect(this);
    opacity =0.9;
    lastOpacity = 0.9;
    effect->setOpacity(opacity);
    this->setGraphicsEffect(effect);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&WidgetBin::AgvItemTimeout);
    //timer->start(500);
}

void WidgetBin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}

bool WidgetBin::SetValue(double Value)
{
    CurrentValue=Value;
    //this->resize(this->width()+5,this->height()+5);
    //CurrentValue = qrand() % 100;//取随机数
    updateGram("0");
    return false;
}


void WidgetBin::updateGram(QString Action)
{
    QPixmap *pix0=new QPixmap(size());
    pix0->fill(QColor(80,80,80));
    pix=pix0;
    QPainter *painter = new QPainter;
    QPen pen;
    //pen.setColor(Qt::white);
    painter->begin(pix);

    color="#FEFEFE";
    // 画一个圆角矩形
    painter->setBrush(color);
    //painter.drawRoundedRect(QRect(7.0, 14.0, 62.0, 42.0), 20.0, 15.0);
    painter->setPen(color);

    pen.setColor(QColor(85,245,127));//设置  图形字体  颜色
    pen.setWidth(1);
    painter->setFont(QFont("Arial",12));
    painter->setPen(pen);

    int x0=0; int y0=20;
    int count=int(100-CurrentValue);
    QString Value=QString::number(CurrentValue)+"%";
    if(shelfBinInfoItem.status==0){
        painter->setBrush(QColor(141, 131, 130));
    }if(shelfBinInfoItem.status==1){
        painter->setBrush(QColor(151, 170, 166));
    }if(shelfBinInfoItem.status==2){
        painter->setBrush(QColor(85,255,127));
    }if( shelfBinInfoItem.status==3){
        painter->setBrush(QColor(118, 77, 57));
    }

    if(CurrentValue>1){
        painter->drawRect(QRect(x0+4,y0+count,116,int(CurrentValue)));
    }else if(CurrentValue>0){
        painter->drawRect(QRect(x0+4,y0+count,116,int(CurrentValue)));
    }

    pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
//    if(shelfBinInfoItem.binEnable==0){
//        pen.setColor(QColor(255,85,0));//设置  图形字体  颜色
//    }

    pen.setWidth(5);
    painter->setPen(pen);

    painter->drawLine(x0,y0+2,x0+122,y0+2);//上
    painter->drawLine(x0,y0+102,x0+122,y0+102);//下

    painter->drawLine(x0+2,y0+5,x0+2,y0+100);//左
    painter->drawLine(x0+122,y0+5,x0+122,y0+100);//右


    painter->drawText(x0+15,y0,shelfBinInfoItem.podIdDesc);     //架位名称

    pen.setColor(QColor(170,85,0));//设置  图形字体  颜色
    pen.setWidth(3);
    painter->setPen(pen);

    //painter->drawText(x0+30,y0+60,Value);//绘制柱状图上数值

    painter->end();
    update();

}

void WidgetBin::Seteffectandshow()
{
    this->resize(this->width()+20,this->height()+10);
    effect->setOpacity(1.0);
    this->setGraphicsEffect(effect);
    updateGram("1");
    this->update();
}

void WidgetBin::enterEvent(QEvent *)
{
    //this->resize(this->width()+10,this->height()+10);
    effect->setOpacity(1.0);
    this->setGraphicsEffect(effect);
    updateGram("1");
    this->update();

    //emit signalshelfBinInfo(shelfBinInfoItem);
}

void WidgetBin::leaveEvent(QEvent *)
{
//    this->resize(this->width()-20,this->height()-10);
    effect->setOpacity(0.9);
    this->setGraphicsEffect(effect);
    updateGram("0");
    this->update();
}

void WidgetBin::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        float showX = (float)e->x(); float showY = (float)e->y();
        emit signalshelfBinInfo(shelfBinInfoItem);
        qDebug()<<"WidgetBin **********"<<shelfBinInfoItem.shelfBinIndex<<shelfBinInfoItem.shelfBindesc<<shelfBinInfoItem.containerCode
               <<showX<<showY;
    }
}



void WidgetBin::AgvItemTimeout()
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

