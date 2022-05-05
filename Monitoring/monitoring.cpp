#include "monitoring.h"
#include "ui_monitoring.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

monitoring::monitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::monitoring)
{
    ui->setupUi(this);
    qRegisterMetaType<agvORderTask >("agvORderTask");

    monitoring_Init();
    monitoringTimer = new QTimer(this);
    connect(monitoringTimer,&QTimer::timeout,this,&monitoring::monitoringTimeout);
    monitoringTimer->start(500);


}

monitoring::~monitoring()
{
    delete ui;
}

void monitoring::monitoringTimeout()
{
    if(m_Image->left_Double){
        ON_signalPoint(m_Image->getmousePoint(),"left");
    }if(m_Image_2->left_Double){
        ON_signalPoint(m_Image_2->getmousePoint(),"left");
    }

    if(!PointInputI->currentMapPoint.isEmpty()){
        currentMapPoint=PointInputI->currentMapPoint;
    }

}

void monitoring::ON_signalPoint(QPointF mousePoint, QString Type)
{
    PointInputI->setVisible(false);
    if(mousePoint.x()>1800.00 || mousePoint.x()<50.00){
        if(ui->stackedWidget->currentIndex()==0){
            ui->stackedWidget->setCurrentIndex(1);
        }else{
            ui->stackedWidget->setCurrentIndex(0);
        }
        for(int i=0;i<AgvItemcarList.length();i++){
            AgvItemcarList[i]->setVisible(false);
            qDebug()<<ui->stackedWidget->currentIndex()<<AgvItemcarList[i]->floor<<AgvItemcarList[i]->agvip;
            if(ui->stackedWidget->currentIndex()==0 && AgvItemcarList[i]->floor==2){
                AgvItemcarList[i]->setVisible(true);
            }if(ui->stackedWidget->currentIndex()==1 && AgvItemcarList[i]->floor==3){
                AgvItemcarList[i]->setVisible(true);
            }
        }
    }else{
        mousePoint.setX(mousePoint.x());//937.5  268.5
        mousePoint.setY(mousePoint.y());

        PointInputI->move(600,300);
        PointInputI->setPoint(mousePoint);
        PointInputI->setVisible(true);
    }

    QPixmap m_pix=m_Image->getQGraphicsViewWH();
    qDebug()<<ui->stackedWidget->currentIndex()<<Type<<mousePoint.x()<<mousePoint.y()<<"   m_Image :"<<m_pix.width()<<m_pix.height();

}

void monitoring::sigAgvItemClick()
{
    if(AgvItemWidgetI->isVisible()){
        AgvItemWidgetI->setVisible(false);
    }else{
        AgvItemWidgetI->setVisible(true);
    }
}

void monitoring::OpenImage(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui->ImageGraphic->width();//获取界面控件Graphics View的宽度
    int nheight = ui->ImageGraphic->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith,nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    m_Image->SesetItemPos(3.08);//设置初始化时大小

    //connect(m_Image,&ImageWidget::signalPoint,this,&monitoring::ON_signalPoint);

    qgraphicsScene->setSceneRect(0,0,this->width(),this->height());

    ui->ImageGraphic->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件

}

void monitoring::OpenImage_2(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image_2 = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui->ImageGraphic_2->width();//获取界面控件Graphics View的宽度
    int nheight = ui->ImageGraphic_2->height();//获取界面控件Graphics View的高度
    m_Image_2->setQGraphicsViewWH(nwith,nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image_2);//将QGraphicsItem类对象放进QGraphicsScene中
    m_Image_2->SesetItemPos(19.20);//设置初始化时大小

    //connect(m_Image,&ImageWidget::signalPoint,this,&monitoring::ON_signalPoint);
    qgraphicsScene->setSceneRect(0,0,this->width(),this->height());

    ui->ImageGraphic_2->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->ImageGraphic_2->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->ImageGraphic_2->setFocus();//将界面的焦点设置到当前Graphics View控件
}

void monitoring::monitoring_Init()
{
    PointInputI = new PointInput();
    PointInputI->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->widget(0)->layout()->setContentsMargins(0,0,0,0);
    ui->stackedWidget->widget(1)->layout()->setContentsMargins(0,0,0,0);

    AgvItemWidgetI=new AgvItemWidget;
    AgvItemWidgetI->setVisible(false);
    connect(AgvItemWidgetI,&AgvItemWidget::sigAGVMoveTask,this,&monitoring::sigAGVMoveTask);
    connect(AgvItemWidgetI,&AgvItemWidget::newAGVMoveTask,this,&monitoring::newAGVMoveTask);

    OpenImage(QImage(":/image/Background_2f.png"));//界面缩放初始化
    OpenImage_2(QImage(":/image/Background_3f.png"));//界面缩放初始化

    monitoring_sqlInit();

    ui->stackedWidget->setCurrentIndex(0);

}

void monitoring::monitoring_sqlInit()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    sqlQuery.prepare("select * from AGVCurrentTask;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            if(sqlQuery.value("enable").toInt() == 1)
            {
                AgvItem *AgvItemI=new AgvItem(this,sqlQuery.value("AgvId").toInt());
                AgvItemI->agvip=sqlQuery.value("AGVIP").toString();
                AgvItemI->agvNum=sqlQuery.value("AgvId").toInt();
                AgvItemI->floor=sqlQuery.value("floornum").toInt();
                AgvItemI->color=sqlQuery.value("agvColor").toString();

                AgvItemI->sWidth=45;
                AgvItemI->sHeight=45;
                AgvItemI->resize(50,40);

                AgvItemI->angle=90;
                AgvItemI->showX=1830;
                AgvItemI->showY=30;
                AgvItemI->move(AgvItemI->showX,AgvItemI->showY);

                AgvItemI->setCursor(Qt::CrossCursor);
                if(AgvItemI->floor==2){
                    AgvItemI->setVisible(true);
                }else{
                    AgvItemI->setVisible(false);
                }
                connect(AgvItemI,&AgvItem::sigAgvItemClick,this,&monitoring::sigAgvItemClick);

                AgvItemcarList.append(AgvItemI);
                //qDebug()<<AgvItemI->floor<<AgvItemI->agvip<<AgvItemI->color<<AgvItemcarList.size();

            }

        }
    }

}

void monitoring::ON_AgvStateWidget(agvState agvStateItemI)
{
//    qDebug()<<"monitoring: "<<agvStateItemI.agvIp<<agvStateItemI.agvFinishInit<<agvStateItemI.passPointState
//           <<agvStateItemI.isFrontLaserNearInducedState<<agvStateItemI.currentBatteryVoltageState;

    for(int i=0;i<AgvItemcarList.length();i++){
        if(AgvItemcarList[i]->agvip==agvStateItemI.agvIp){
            AgvItemcarList[i]->color="#6950a1";
            if(agvStateItemI.isFrontLaserNearInducedState){//AGV前面近距离激光感应   "障碍：停车"
                AgvItemcarList[i]->color="#8B864E";
            }if(agvStateItemI.CurrentDestpoint!=0){//有任务
                 AgvItemcarList[i]->color="#98FB98";
            }if((agvStateItemI.currentErrorCodeState!="0" ||agvStateItemI.lineEdit_timer>15
                || agvStateItemI.currentBatteryVoltageState.toInt()<490)
                    && agvStateItemI.agvFinishInit){//错误报警  电压过低报警
                AgvItemcarList[i]->color="#CD3333";
            }

            mapPoint mapPoint0=currentMapPoint.value(agvStateItemI.passPointState.toDouble());
            if(mapPoint0.cardPoint>0.00){
                AgvItemcarList[i]->angle=int(mapPoint0.angle);
                if(mapPoint0.angle==0.00){
                    AgvItemcarList[i]->move(int(mapPoint0.movex-30),int(mapPoint0.movey-155));
                }else {
                    AgvItemcarList[i]->move(int(mapPoint0.movex-20),int(mapPoint0.movey-160));
                }
                //qDebug()<<" passPointState:"<<agvStateItemI.passPointState<<" angle:"<<mapPoint0.angle<<" movex:"<<mapPoint0.movex<<" movey:"<<mapPoint0.movey;
            }

        }
    }

}

void monitoring::mouseMoveEvent(QMouseEvent *e)
{

}

void monitoring::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        PointInputI->setVisible(false);
    }if(e->button() == Qt::RightButton){
        mousePoint.setX(e->x());mousePoint.setY(e->y());
        PointInputI->move(e->x(),e->y());
        PointInputI->setPoint(mousePoint);
        PointInputI->setVisible(false);PointInputI->setVisible(true);
    }
}

void monitoring::wheelEvent(QWheelEvent *e)
{
    if(e->delta()>0){//如果滚轮往上滚
        //qDebug()<<"鼠标往前滚动";
    }
    else{
        //qDebug()<<"鼠标往后滚动";
    }
}

