#include "instance.h"
Instance* Instance::instanceItiem=0;
QMutex Instance::mutex;

Instance::Instance(QObject *parent)
{
    qRegisterMetaType<QList<RW_Excel >>("QList<RW_Excel >");
    qRegisterMetaType<QList<SAPExcelInfo >>("QList<SAPExcelInfo >");
    qRegisterMetaType<QList<User_Info >>("QList<User_Info >");
    qRegisterMetaType<QList<AgvState >>("QList<AgvState >");

    LblMovieStatusInit();

    //qRegisterMetaType<QMap<QString ,QMap<QString ,CagePointState > >>("QMap<QString ,QMap<QString ,CagePointState > >");
}

Instance *Instance::GetInstance()
{
    if(instanceItiem != nullptr)
        return instanceItiem;
    else
    {
        mutex.lock();
        instanceItiem=new Instance;
        return instanceItiem;
        mutex.unlock();
    }
}

void Instance::SetButtonList(QList<QPushButton *> btns, QString Buttontext)
{
    for(int i=0;i<btns.length();i++){
        btns[i]->setStyleSheet("background-color: rgb(66, 66, 66);border-radius:10px;color:#ffffff;border-style: outset;border: 2px groove gray;");
        if(btns[i]->text()==Buttontext || btns[i]->objectName()==Buttontext){
           btns[i]->setStyleSheet("background-color: rgb(85,255,127);border-radius:10px;color:#ffffff;border-style: outset;border: 2px groove gray;");
        }
    }
}

void Instance::SetButton_pressed(QPushButton *Button, QString Style)
{
    Button->setStyleSheet(Style);
}

void Instance::SetButton_released(QPushButton *Button, QString Style)
{
    Button->setStyleSheet(Style);
}

void Instance::setqDebug_log(QString logtext)
{
    currentlogtext=currentlogtext+logtext;
}

QString Instance::getqDebug_log()
{
    QString logtext=currentlogtext;
    currentlogtext="";
    return logtext;
}


bool Instance::SetMessagebox(QString Messagetext)
{
    QFont ft;ft.setPointSize(12);
    QMessageBox message(QMessageBox::NoIcon, "建议: ", Messagetext, QMessageBox::Yes | QMessageBox::No, NULL);
    message.setIconPixmap(QPixmap(":/image/call.jpg"));
    message.resize(300,200);
    message.setFont(ft);
    if(message.exec() == QMessageBox::Yes)
    {
        message.close();return true;
    }
    message.close();return false;

}

void Instance::LblMovieStatusInit()
{
    //加载gif图片
    lbl_Widget=new QWidget();
    lbl_Widget->setWindowFlags(lbl_Widget->windowFlags() | Qt::FramelessWindowHint);
    lbl_Widget->resize(300,150);
    lbl_gif=new QLabel(lbl_Widget);
    lbl_gif->move(0,50);
    lbl_gif->resize(lbl_Widget->width(),lbl_Widget->height()-50);

    lbl_gif1=new QLabel(lbl_Widget);
    lbl_gif1->move(0,0);
    lbl_gif1->resize(lbl_Widget->width(),50);
    lbl_gif1->setText("正在处理,请稍等…………");
    lbl_gif1->setStyleSheet("color:#ffffff;font:16pt '宋体';background-color: rgb(81, 81, 81);");

    lbl_Widget->setStyleSheet("border-style: outset;");
    QMovie *lblmovie = new QMovie(":/image/timg.gif");

    QSize si(lbl_gif->width(),lbl_gif->height());
    lblmovie->setScaledSize(si);
    lbl_gif->setMovie(lblmovie);
    lblmovie->start();
    lbl_Widget->setVisible(false);
}

void Instance::setLblMovieStatus(int status)
{
    if(status==1){
        if(!lbl_Widget->isVisible()){
            lbl_Widget->setVisible(false);
            lbl_Widget->setVisible(true);
        }
    }else {
        if(lbl_Widget->isVisible()){
            lbl_Widget->setVisible(false);
        }
    }
}

bool Instance::getLblMovieStatus()
{
    return  lbl_Widget->isVisible();
}



