#include "histogram.h"
#include "ui_histogram.h"

Histogram::Histogram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Histogram)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());

    pix->fill(QColor(66,66,66));
    setMinimumSize(760,310);

    for(int i=1;i<8;i++){
        Bench Bench0;Bench0.ID=i;BenchList.append(Bench0);
    }
}

Histogram::~Histogram()
{
    delete ui;
}

void Histogram::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}

void Histogram::updateGram()
{
    QPixmap *pix0=new QPixmap(size());
    pix0->fill(QColor(66,66,66));
    this->setMinimumSize(760,310);
    QPixmap *oldpix=pix;
    pix=pix0;
    delete oldpix;
    QPainter *painter = new QPainter;
    QPen pen;
    //pen.setColor(Qt::white);
    painter->begin(pix);

    color="#FEFEFE";
    // 画一个圆角矩形
    painter->setBrush(color);
    //painter.drawRoundedRect(QRect(7.0, 14.0, 62.0, 42.0), 20.0, 15.0);
    painter->setPen(color);
    pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
    //pen.setWidth(5);
    painter->setFont(QFont("Arial",12));
    painter->setPen(pen);

    int x0=50;
    int y0=280;
    int distance=100;
    //-----------完成X和Y坐标系的绘制--------------
    //-----Y坐标系--------
//    painter->drawLine(x0,y0,x0,20);
//    painter->drawLine(x0-4,20+4,x0,20);
//    painter->drawLine(x0+4,20+4,x0,20);
//    painter->drawText(20,20,tr("Y"));

    int equal =280;
    for(int i=0;i<8;i++){
        equal =280-(7-i)*40;
        pen.setColor(QColor(205,179,139));//设置  图形字体  颜色
        painter->setPen(pen);
        painter->drawLine(x0,equal,750,equal);

        if(equal==0){equal=15;}
        pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
        painter->setPen(pen);
        painter->drawText(-50+x0,equal+10,tr("%1").arg((7-i)*100));//比例1：1
    }

    //-----X坐标系--------
    painter->drawLine(x0,y0,750,y0);
//    painter->drawLine(750-4,y0-4,750,y0);
//    painter->drawLine(750-4,y0+4,750,y0);
//    painter->drawText(750+5,y0,tr("X"));

    //-----X坐标系刻度--------
    for(int row=1;row<=7;row++)
    {
        QString s=QString::number(row);
        painter->drawText(x0+25 + distance * (row-1),y0 + 20,s);
    }

    //--------------柱状统计图绘制---------------------
//    for(int rowValue=1;rowValue<=7;rowValue++)
//    {
//        //int value = Value.at(rowValue-1);
//        int value1=GetValue(rowValue, 1);int maxcount1=0;
//        int left=x0 + distance * (rowValue-1);
//        if(left==0){left=20;}

//        painter->setBrush(QColor(62,102,149));
//        if(value1>=700){ painter->setBrush(QColor(255,0,0));maxcount1=35;}
//        if(value1>0){
//            painter->drawRect(QRect(left,y0-value1*0.4,30,value1*0.4));
//            painter->drawText(left-maxcount1-5,y0-value1*0.4-5+maxcount1,tr("%1").arg(value1));//绘制柱状图上数值
//        }

//        int value2=GetValue(rowValue, 2);int maxcount2=0;
//        painter->setBrush(QColor(255,255,127));
//        if(value2>=700){ painter->setBrush(QColor(255,0,0));maxcount2=35;}

//        if(value2>0){
//            painter->drawRect(QRect(left+30,y0-value2*0.4,30,value2*0.4));
//            painter->drawText(left+35+maxcount2,y0-value2*0.4-5+maxcount2,tr("%1").arg(value2));//绘制柱状图上数值
//        }
//        //qDebug()<<rowValue<<value1<<value2;
//    }



    int allvalue1=0;int allvalue2=0;
    painter->setFont(QFont("Arial",14));
    for(int rowValue=1;rowValue<=7;rowValue++)
    {
        int value1=GetValue(rowValue, 1);int maxcount1=0;
        int left=x0 + distance * (rowValue-1);
        if(left==0){left=20;}

        painter->setBrush(QColor(62,102,149));
        if(value1>0){
            if(value1>=700){
                pen.setColor(QColor(255,0,0));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->setBrush(QColor(255,0,0));
                painter->drawRect(QRect(left,y0-value1*0.4,30,value1*0.4));

                pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->drawText(left-maxcount1-5,y0-value1*0.4-5+maxcount1,tr("%1").arg(value1));//绘制柱状图上数值

            }else {
                pen.setColor(QColor(62,102,149));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->setBrush(QColor(62,102,149));
                painter->drawRect(QRect(left,y0-value1*0.4,30,value1*0.4-1));

                pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
                painter->setPen(pen);

                int text=left-maxcount1-5;
                if(value1<100){text=text+5;}
                if(value1<10){text=text+10;}
                painter->drawText(text,y0-value1*0.4-5+maxcount1,tr("%1").arg(value1));//绘制柱状图上数值
            }
        }

        int value2=GetValue(rowValue, 2);int maxcount2=0;
        if(value2>0){
            if(value2>=700){
                pen.setColor(QColor(255,0,0));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->setBrush(QColor(255,0,0));
                painter->drawRect(QRect(left+30,y0-value2*0.4,30,value2*0.4));

                pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->drawText(left+35+maxcount2,y0-value2*0.4-5+maxcount2,tr("%1").arg(value2));//绘制柱状图上数值
            }else {
                pen.setColor(QColor(255,255,127));//设置  图形字体  颜色
                painter->setPen(pen);
                painter->setBrush(QColor(255,255,127));
                painter->drawRect(QRect(left+30,y0-value2*0.4,30,value2*0.4));

                pen.setColor(QColor(255,245,255));//设置  图形字体  颜色
                painter->setPen(pen);
                int text=left+25+maxcount2;
                if(value2<100){text=text+5;}
                if(value2<10){text=text+10;}
                painter->drawText(text,y0-value2*0.4-5+maxcount2,tr("%1").arg(value2));//绘制柱状图上数值
            }

        }

        allvalue1=value1;
        allvalue2=value2;
    }



    painter->end();
    update();
}

bool Histogram::SetValue(int ID, int Value1, int Value2)
{
    bool updateGrambool=false;
    for(int i=0;i<BenchList.length();i++){
        if(BenchList[i].ID==ID){
           if(BenchList[i].Value1!=Value1 || BenchList[i].Value2!=Value2){
                updateGrambool =true;
                BenchList[i].Value1=Value1;
                BenchList[i].Value2=Value2;
           }
        }
    }
    if(updateGrambool){
        updateGram();
        //qDebug()<<ID<<Value1<<Value2;
    }
    return updateGrambool;
}

int Histogram::GetValue(int ID, int Value1)
{
    for(int i=0;i<BenchList.length();i++){
        if(BenchList[i].ID==ID){
            if(Value1==1){
                return BenchList[i].Value1;
            }
            if(Value1==2){
                return BenchList[i].Value2;
            }
        }
    }
    return 0;
}

