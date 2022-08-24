#include "pointinput.h"
#include "ui_pointinput.h"
#define ASMORDERDBSTR ConnectPoolFactory::getInstance()->getConnectPool(ConnectPoolFactory::AsmOrderDataBase0)

PointInput::PointInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointInput)
{
    ui->setupUi(this);
    PointInput_Init();

}

PointInput::~PointInput()
{
    delete ui;
}

void PointInput::on_insertButton_clicked()
{
    if(ui->pointEdit->text().isEmpty()) {
        QMessageBox::information(this,"提示","卡号不能为空"); return;
    }else{
        ONUPdatanowPoint(getMapPoint(), "1");
    }
}

void PointInput::on_UPButton_clicked()
{
    if(ui->pointEdit->text().isEmpty()) {
        QMessageBox::information(this,"提示","卡号不能为空"); return;
    }else{
        ONUPdatanowPoint(getMapPoint(), "0");
    }
}

void PointInput::on_deleteButton_clicked()
{
    if(ui->pointEdit->text().isEmpty()) {
        QMessageBox::information(this,"提示","卡号不能为空"); return;
    }else{
        ONUPdatanowPoint(getMapPoint(), "-1");
    }
}

void PointInput::setPoint(const QPointF &tempPoint,int floor)
{
    nowPoint = tempPoint;
    ui->xEdit->setText(QString::number(nowPoint.x()));
    ui->yEdit->setText(QString::number(nowPoint.y()));
    ui->floorNum->setCurrentIndex(floor-1);

}

mapPoint PointInput::getMapPoint()
{
    QString floordesc = ui->floorNum->currentText().trimmed();
    QString xdesc = ui->xEdit->text().trimmed();
    QString ydesc = ui->yEdit->text().trimmed();
    QString carddesc = ui->pointEdit->text().trimmed();

    mapPoint mapPointI;
    mapPointI.cardPoint=carddesc.toDouble();
    mapPointI.floor=floordesc.toDouble();
    mapPointI.movex=xdesc.toDouble();
    mapPointI.movey=ydesc.toDouble();

    double xEdit=ui->xEdit->text().trimmed().toDouble();
    double yEdit=ui->yEdit->text().trimmed().toDouble();
    double space=ui->space->text().trimmed().toDouble();
    if(ui->coordinate->currentText().trimmed()=="X方向"){
        mapPointI.angle=0.00;
        ui->xEdit->setText(QString::number(xEdit+space));
        ui->yEdit->setText(QString::number(yEdit));
    }else{
        mapPointI.angle=90.00;//显示角度
        ui->xEdit->setText(QString::number(xEdit));
        ui->yEdit->setText(QString::number(yEdit+space));
    }
    ui->pointEdit->setText("");
    return mapPointI;
}

void PointInput::ONUPdatanowPoint(mapPoint mapPointI, QString Action)
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);

    if(Action=="1"){
        sqlQuery.prepare("INSERT INTO [dbo].[mapPoint] ([cardPoint], [floor],[movex],"
                         "[movey],[angle]) VALUES (:cardPoint,:floor,:movex,:movey,:angle);");
        sqlQuery.addBindValue(mapPointI.cardPoint);
        sqlQuery.addBindValue(mapPointI.floor);
        sqlQuery.addBindValue(mapPointI.movex);
        sqlQuery.addBindValue(mapPointI.movey);
        sqlQuery.addBindValue(mapPointI.angle);
        if(!sqlQuery.exec()){
            qDebug()<<"INSERT: "<<sqlQuery.lastError()<<mapPointI.cardPoint;
        }
    }

    if(Action=="0"){
        sqlQuery.prepare("UPDATE [dbo].[mapPoint] SET [floor]=:floor,[movex]=:movex,[movey]=:movey,[angle]=:angle "
                         "WHERE [cardPoint]=:cardPoint;");
        sqlQuery.addBindValue(mapPointI.floor);
        sqlQuery.addBindValue(mapPointI.movex);
        sqlQuery.addBindValue(mapPointI.movey);
        sqlQuery.addBindValue(mapPointI.angle);
        sqlQuery.addBindValue(mapPointI.cardPoint);
        if(!sqlQuery.exec()){
            qDebug()<<"UPDATE: "<<sqlQuery.lastError()<<mapPointI.cardPoint;
        }
    }

    if(Action=="-1"){
        sqlQuery.prepare(QString("DELETE FROM mapPoint WHERE ([cardPoint]=:cardPoint AND [floor]=:floor) "));
        sqlQuery.addBindValue(mapPointI.cardPoint);
        sqlQuery.addBindValue(mapPointI.floor);
        if(!sqlQuery.exec()){
            qDebug()<<"DELETE: "<<sqlQuery.lastError()<<mapPointI.cardPoint;

        }
    }

    sqlMapPoint_Init();
}

void PointInput::PointInput_Init()
{

    this->setWindowTitle(QString("二维码坐标参数"));

    Actionbtns<<ui->insertButton<<ui->UPButton<<ui->deleteButton;
    for(int i=0;i<Actionbtns.length();i++){
        connect(Actionbtns[i],&QPushButton::pressed,this,&PointInput::ON_Pressed);
        connect(Actionbtns[i],&QPushButton::released,this,&PointInput::ON_Released);
    }

    sqlMapPoint_Init();
}

void PointInput::sqlMapPoint_Init()
{
    connectBuilder build(ASMORDERDBSTR);
    QSqlDatabase sqlDatabase =  build.getOpenDatabase();
    QSqlQuery sqlQuery(sqlDatabase);
    sqlQuery.setForwardOnly(true);

    currentMapPoint.clear();
    sqlQuery.prepare("select * from mapPoint;");
    if(sqlQuery.exec())
    {
        while(sqlQuery.next())
        {
            mapPoint mapPointI;
            mapPointI.cardPoint=sqlQuery.value("cardPoint").toDouble();
            mapPointI.floor=sqlQuery.value("floor").toDouble();
            mapPointI.movex=sqlQuery.value("movex").toDouble();
            mapPointI.movey=sqlQuery.value("movey").toDouble();
            mapPointI.angle=sqlQuery.value("angle").toDouble();
            if(!currentMapPoint.contains(mapPointI.cardPoint)){ //类型解析 DN AV OTH 离线发料
                currentMapPoint.insert(mapPointI.cardPoint,mapPointI);
            }
        }
    }

}

void PointInput::ON_Pressed()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_pressed(Button,"background-color: rgb(85,255,127);color:#ffffff;color: white;  border: 2px groove gray;\
                                               border-radius:15px;border-style: outset");
}

void PointInput::ON_Released()
{
    QPushButton *Button = (QPushButton *)this->sender();Button->objectName();
    Instance::GetInstance()->SetButton_released(Button,"color: white;border: 2px groove gray;border-radius:15px;border:none;background-color: rgb(0, 166, 172);");
}


