#ifndef POINTINPUT_H
#define POINTINPUT_H

#include <QDialog>
#include <QPoint>
#include "agvCar/agvcarpool.h"
#include "sql_single/query_single.h"

struct mapPoint{
    double cardPoint=0.00;
    double floor=0.00;
    double movex=0.00;
    double movey=0.00;
    double angle=0.00;

};

namespace Ui {
class PointInput;
}

class PointInput : public QDialog
{
    Q_OBJECT

public:
    explicit PointInput(QWidget *parent = 0);
    ~PointInput();

    void setPoint(const QPointF& tempPoint);
    mapPoint getMapPoint();
    void ONUPdatanowPoint(mapPoint mapPointI,QString Action);

    QList<QPushButton *>Actionbtns;
    QMap<double,mapPoint>currentMapPoint;
    void PointInput_Init();

    void sqlMapPoint_Init();
private:
    QPointF nowPoint;


private slots:
    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_UPButton_clicked();

public slots:
    void ON_Pressed();

    void ON_Released();

private:
    Ui::PointInput *ui;
};

#endif // POINTINPUT_H
