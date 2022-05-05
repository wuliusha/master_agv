#include "chartview.h"
#include "ui_chartview.h"

ChartView::ChartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartView)
{
    ui->setupUi(this);

}

ChartView::~ChartView()
{
    delete ui;
}

void ChartView::SetChartPercent(int finishcount, int unfinishcount, int DN_count,
                                int SL_count, int LM_count, int Other_count)
{
    m_nPeopleCount=0;
    m_answerMap.clear();m_numList.clear();
    if(finishcount>0){
        m_answerMap.insert("已完成", finishcount);
    }
    if(DN_count>0){
        m_answerMap.insert("待发DN", DN_count);
    }
    if(SL_count>0){
        m_answerMap.insert("待发SL", SL_count);
    }
    if(LM_count>0){
        m_answerMap.insert("待发LM", LM_count);
    }
    if(Other_count>0){
        m_answerMap.insert("待发Other", Other_count);
    }

//    QMap<QString, int> m_answerMapI;
//    for (int i=0;i<m_answerMap.size();i++) {
//        QString countstr="";int countint=10000;
//        QMap<QString, int>::iterator iter= m_answerMap.begin();
//        while (iter!=m_answerMap.end()) {
//            if(!m_answerMapI.contains(iter.key()) && countint>=iter.value()){
//                countstr=iter.key();
//                countint=iter.value();
//                //qDebug()<<"iter.key() "<<iter.key()<<iter.value();
//            }
//            iter++;
//        }
//        if(countint<10000){
//            qDebug()<<"countstr<<countint"<<countstr<<countint;
//            m_answerMapI.insert(countstr,countint);
//        }


//    }
//    m_answerMap=m_answerMapI;


    //                qDebug()<<"已完成"<<finishcount<<"未完成"<<unfinishcount<<"待发DN"<<DN_count<<"待发SL"<< SL_count
    //                       <<"待发LM"<<LM_count<<"待发Other"<< Other_count;


    m_answerStrList = m_answerMap.keys();
    m_numList = m_answerMap.values();
    foreach (int num, m_numList) {
        m_nPeopleCount += num;
    }
    ui->label_finishcount->setText(" "+QString::number(finishcount));
    ui->label_DN_count->setText(" "+QString::number(DN_count));
    ui->label_SL_count->setText(" "+QString::number(SL_count));
    ui->label_LM_count->setText(" "+QString::number(LM_count));
    ui->label_Other_count->setText(" "+QString::number(Other_count));
    ui->label_allcount->setText("总数: "+QString::number(m_nPeopleCount));
    this->update();
}

void ChartView::paintEvent(QPaintEvent *e)
{
    QMap<int ,painterpick>drawTextlist;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
//    painter.drawImage(this->rect(),m_bg);

    QRectF rect(-140, -140,(140 << 1), (140 << 1));
    QList<QColor> colorList;

    painter.translate(210, 150);

    qreal startAngle = 0;
    int count=0;int textPosXcount=0;int textPosYcount=0;
    QMapIterator<QString, int> itero1(m_answerMap);
    while (itero1.hasNext()) {
        itero1.next();
        count++;
        int num=itero1.value();
        //生成随机颜色并过滤掉白色
        int colorR, colorG, colorB;
        if(itero1.key()=="已完成"){
            colorR=85;colorG=255;colorB=0;textPosXcount=35;textPosYcount=60;
        }if(itero1.key()=="待发DN"){
            colorR=229;colorG=229;colorB=0;textPosXcount=35;textPosYcount=60;
        }if(itero1.key()=="待发SL"){ 
            colorR=0;colorG=170;colorB=255;textPosXcount=45;textPosYcount=10;
        }if(itero1.key()=="待发LM"){
            colorR=255;colorG=170;colorB=0;textPosXcount=-10;textPosYcount=30;
        }if(itero1.key()=="待发Other"){        
            colorR=170;colorG=170;colorB=127;textPosXcount=35;textPosYcount=60;
        }

        QColor color(colorR, colorG, colorB);
        colorList.append(color);

        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(color));

        //该答案选项所占比例
        qreal percentNum = (qreal)num/(qreal)m_nPeopleCount;

        //所占比例对应的角度
        qreal arcLength = 360*percentNum;

        //画扇形
        QPainterPath path;
        path.arcTo(rect, startAngle, arcLength);

        //扇形二等分线的角度
        qreal middleAngle = startAngle + arcLength/2;
        qreal radianNum = 0;
        if(middleAngle >= 0 && middleAngle < 90){
            radianNum = middleAngle*m_pi/180;
        }
        else if(middleAngle >= 90 && middleAngle < 180){
            radianNum = (180 - middleAngle)*m_pi/180;
        }
        else if(middleAngle >= 180 && middleAngle < 270){
            radianNum = (middleAngle - 180)*m_pi/180;
        }
        else if(middleAngle >= 270 && middleAngle < 360){
            radianNum = (360 - middleAngle)*m_pi/180;
        }
        //二等分线的中点距原点的距离
        qreal textPosY = 60*sin(radianNum)*1.5;
        qreal textPosX = 60*cos(radianNum)*1.5;


        //根据二等分线所在的象限确定二等分线的中点坐标
        if(middleAngle >= 0 && middleAngle < 90)
        {
            textPosY = -textPosY;
        }
        else if(middleAngle >= 90 && middleAngle < 180)
        {
            textPosX = -textPosX;
            textPosY = -textPosY;
        }
        else if(middleAngle >= 180 && middleAngle < 270)
        {
            textPosX = -textPosX;
        }
        startAngle += arcLength;

        percentNum=percentNum*100;
        QString percentStr = QString::number(percentNum, 'f', 0)+"%";
        if(percentNum<1){
             percentStr = QString::number(percentNum, 'f', 1)+"%";
        }

//        qDebug()<<"percentNum"<<itero1.value()<<itero1.key()<<percentNum;
//        QString percentStr = QString::number(percentNum*100 + 0.5);
//        percentStr = getPercentInt(percentStr) + "%";

        painter.drawPath(path);

        painter.setPen(QColor(Qt::white));

        painterpick painterpickI;
        painterpickI.textPosX=textPosX;
        painterpickI.textPosY=textPosY;
        painterpickI.num=num;
        painterpickI.percentStr=percentStr;
        drawTextlist.insert(count,painterpickI);

        QFont ft;
        ft.setPointSize(16);
        painter.setFont(ft);
        if(percentNum<5){
            if(percentNum<1){
                painter.drawText(textPosX+40, textPosY -10,80, 25, Qt::AlignCenter, percentStr);
            }else {
                painter.drawText(textPosX+25, textPosY -10,80, 25, Qt::AlignCenter, percentStr);
            }
         }else{
            painter.drawText(textPosX - 25, textPosY -10,80, 25, Qt::AlignCenter, percentStr);
        }

    }

//    QMapIterator<int, painterpick> itero2(drawTextlist);
//    while (itero2.hasNext()) {
//        itero2.next();
//        qDebug()<<"painter.drawText:"<<itero2.value().textPosX-25<<itero2.value().textPosX-10<<itero2.value().percentStr;
//        //painter.drawText(itero2.value().textPosX,itero2.value().textPosX,100, 40, Qt::AlignCenter, itero2.value().percentStr);

//    }

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor(0, 0, 0));
    painter.translate(-210, -150);
    QWidget::paintEvent(e);

}

QString ChartView::getPercentInt(const QString &percentStr)
{
    QString percentIntStr;
    for(int i = 0;i < percentStr.size();++i){
        if(percentStr.at(i) == '.')
        {
            break;
        }
        percentIntStr += percentStr.at(i);
    }
    return percentIntStr;
}


