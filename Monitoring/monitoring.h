#ifndef MONITORING_H
#define MONITORING_H

#include <QWidget>
#include "project/agvitemwidget.h"
#include "project/imagewidget.h"
#include "project/pointinput.h"

namespace Ui {
class monitoring;
}

class monitoring : public QWidget
{
    Q_OBJECT

public:
    explicit monitoring(QWidget *parent = nullptr);
    ~monitoring();


signals:
    //发布AGV任务
    void sigAGVMoveTask(QString AGVIP, quint32 StartQRPoint, quint32 EndQRPoint, int AGVAction,int tye,agvORderTask agvORderTaskI);

    //创建 AGV 搬运任务
    void newAGVMoveTask(QString AGVIP,QString taskType,AGVCurrentTask AGVCurrentTaskI);

public slots:
    void monitoringTimeout();
    void ON_signalPoint(QPointF mousePoint,QString Type);

public :
    QTimer *monitoringTimer;

    ImageWidget *m_Image;
    ImageWidget *m_Image_2;

    PointInput *PointInputI;
    AgvItemWidget *AgvItemWidgetI;

    bool boolagvState=true;                            //槽函数 保护机制
    QList<AgvItem > AgvItemcarList;
    QMap<double,mapPoint>currentMapPoint;

    QPoint mousePoint; //当前鼠标的位置

    void OpenImage(QImage image);
    void OpenImage_2(QImage image);

    void monitoring_Init();

    void monitoring_sqlInit();

    void ON_AgvStateWidget(agvState agvStateItemI);             //AGV 详细状态信息

private:
    void mouseMoveEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);// 这个是鼠标上下滚轮的时候会调用

private:
    Ui::monitoring *ui;

};

#endif // MONITORING_H
