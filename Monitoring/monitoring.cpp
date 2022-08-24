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
    }if(m_Image->right_Double || m_Image_2->right_Double){
        if(AgvItemWidgetI->isVisible()){
            AgvItemWidgetI->setVisible(false);
        }else{
            AgvItemWidgetI->setVisible(true);
        }
        m_Image->right_Double=false; m_Image_2->right_Double=false;
    }

    if(!PointInputI->currentMapPoint.isEmpty()){
        currentMapPoint=PointInputI->currentMapPoint;
    }

}

void monitoring::ON_signalPoint(QPointF mousePoint, QString Type)
{
    int floor=2;
    PointInputI->setVisible(false);
    if(mousePoint.x()>860.00 || mousePoint.x()<-860.00){
        if(ui->stackedWidget->currentIndex()==0){
            floor=3;
            ui->stackedWidget->setCurrentIndex(1);
        }else{
            ui->stackedWidget->setCurrentIndex(0);
        }
    }else{
        mousePoint.setX(mousePoint.x());//937.5  268.5
        mousePoint.setY(mousePoint.y());
        if(ui->stackedWidget->currentIndex()==1){
            floor=3;
        }
        PointInputI->move(600,300);
        PointInputI->setPoint(mousePoint,floor);
        PointInputI->setVisible(true);
    }

    QPixmap m_pix=m_Image->getQGraphicsViewWH();
    qDebug()<<ui->stackedWidget->currentIndex()<<Type<<mousePoint.x()<<mousePoint.y()<<"   m_Image :"<<m_pix.width()<<m_pix.height();

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
    m_Image->floor=2;
    //connect(m_Image,&ImageWidget::signalPoint,this,&monitoring::ON_signalPoint);

    qgraphicsScene->setSceneRect(0,0,this->width(),this->height());

    ui->ImageGraphic->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->ImageGraphic->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->ImageGraphic->setFocus();//将界面的焦点设置到当前Graphics View控件

}

void monitoring::OpenImage_2(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);        //The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;   //要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image_2 = new ImageWidget(&ConvertPixmap);            //实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui->ImageGraphic_2->width();                //获取界面控件Graphics View的宽度
    int nheight = ui->ImageGraphic_2->height();             //获取界面控件Graphics View的高度
    m_Image_2->setQGraphicsViewWH(nwith,nheight);           //将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image_2);//将QGraphicsItem类对象放进QGraphicsScene中
    m_Image_2->SesetItemPos(19.20);//设置初始化时大小
    m_Image_2->floor=3;
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
                AgvItem AgvItemI;
                AgvItemI.agvip=sqlQuery.value("AGVIP").toString();
                AgvItemI.agvNum=sqlQuery.value("AgvId").toInt();
                AgvItemI.floor=sqlQuery.value("floornum").toInt();
                AgvItemI.color=sqlQuery.value("agvColor").toString();
                AgvItemI.angle=180;
                AgvItemcarList.append(AgvItemI);
                //qDebug()<<AgvItemI->floor<<AgvItemI->agvip<<AgvItemI->color<<AgvItemcarList.size();
            }
        }
    }

    m_Image->AgvItemcarList=AgvItemcarList;
    m_Image_2->AgvItemcarList=AgvItemcarList;

}

void monitoring::ON_AgvStateWidget(agvState agvStateItemI)
{
//    qDebug()<<"monitoring: "<<agvStateItemI.agvIp<<agvStateItemI.agvFinishInit<<agvStateItemI.passPointState
//           <<agvStateItemI.isFrontLaserNearInducedState<<agvStateItemI.currentBatteryVoltageState;
    if(!boolagvState){return;}
    boolagvState=false;                            //槽函数 保护机制
    for(int i=0;i<AgvItemcarList.length();i++){
        if(AgvItemcarList[i].agvip==agvStateItemI.agvIp){
            AgvItemcarList[i].color="#764d39";
            if(agvStateItemI.isFrontLaserNearInducedState
                    || agvStateItemI.isRearLaserNearInducedState
                    || agvStateItemI.isLeftLaserNearInducedState
                    || agvStateItemI.isRightLaserNearInducedState){
                AgvItemcarList[i].color="#6f37a6";
            }if(agvStateItemI.ActionItem.CurrentDestpoint!=0){
                 AgvItemcarList[i].color="#e5bb64";
            }if((agvStateItemI.currentErrorCodeState!="0" || !agvStateItemI.isOnline)
                    && agvStateItemI.FinishInit){
                AgvItemcarList[i].color="#a11715";
            }
            mapPoint mapPoint0=currentMapPoint.value(agvStateItemI.passPointState.toDouble());
            if(mapPoint0.cardPoint>0.00){
                AgvItemcarList[i].angle=int(mapPoint0.angle);
                AgvItemcarList[i].stationX=int(mapPoint0.movex);
                AgvItemcarList[i].stationY=int(mapPoint0.movey);
                m_Image->setAgvItemcarList_date(AgvItemcarList[i]);
                m_Image_2->setAgvItemcarList_date(AgvItemcarList[i]);
                //qDebug()<<" passPointState:"<<agvStateItemI.passPointState<<" angle:"<<mapPoint0.angle<<" movex:"<<mapPoint0.movex<<" movey:"<<mapPoint0.movey;
            }
        }
    }
    boolagvState=true;                            //槽函数 保护机制
}

void monitoring::mouseMoveEvent(QMouseEvent *e)
{

}

void monitoring::mouseDoubleClickEvent(QMouseEvent *e)
{
    int floor=2;
    if(e->button() == Qt::LeftButton)
    {
        PointInputI->setVisible(false);
    }if(e->button() == Qt::RightButton){
        mousePoint.setX(e->x());mousePoint.setY(e->y());
        PointInputI->move(e->x(),e->y());
        PointInputI->setPoint(mousePoint,floor);
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

