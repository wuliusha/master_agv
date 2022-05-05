#ifndef AGVITEMINFO_H
#define AGVITEMINFO_H

#include <QWidget>

#include "SCStatusTcp/robotstatustcp.h"
#include "sqlConnect/sqlconnectionpool.h"
#pragma execution_character_set("utf-8")

namespace Ui {
class agviteminfo;
}

class agviteminfo : public QWidget
{
    Q_OBJECT

public:
    explicit agviteminfo(QWidget *parent = nullptr);
    ~agviteminfo();
    QTimer *StatusTimer;
    RoboshopAction RoboshopActionItem;   //Roboshop 导航指令
    RoboshopState RoboshopStateItem;    //Roboshop 当前状态信息
    QList<lmstation>lmstationlist;      //导航与重定位坐标
    QList<description>descriptionlist; //执行动作解析链表

    void CreateConnect(RobotStatusTcp *StatusTcp,quint16 port);//@brief myConnection - 建立/断开连接
    void _StatusSocketProcess();//_StatusSocket 数据处理
    void _ControlSocketProcess();//_ControlSocket 数据处理

    void My_SqlInit();
    void UP_RoboshopState();//Roboshop 当前状态信息

signals:
    void UPRoboshopState(RoboshopState RoboshopState0);//实时更新Roboshop 状态信息
    void Roboshop_Action(QString lm_station,QString descrip,QString Action);//LM 动作指令  动作类型  0 1

public slots:

    /**
     * @brief SCTcpToolWidget::stateChanged - tcp槽，实时监测tcp状态
     * @param state - socket的当前状态
     */
    void stateChanged(QAbstractSocket::SocketState state);
    void ON_Roboshop_ret_code(QByteArray RecvData);//控制指令数据返回
    /**
     * @brief SCTcpToolWidget::receiveTcpError - tcp槽 返回tcp错误
     * @param error - socket的错误描述
     */
    void receiveTcpError(QAbstractSocket::SocketError error);

    void ON_Roboshop_Action(QString lm_station,QString descrip,QString Action);//LM 动作指令  动作类型  0 1
    void ON_returnwriteTcpData(QByteArray writeData);


private slots:
    void RoboshopStatetimer();
    void on_cancelnavigation_clicked();
    void on_relocation_clicked();
    void on_pausenavigation_clicked();
    void on_navigation_clicked();

private:
    Ui::agviteminfo *ui;
    int _StatusSocket_online_count=0;
    RobotStatusTcp *_StatusSocket= Q_NULLPTR;
    RobotStatusTcp *_ControlSocket= Q_NULLPTR;
};

#endif // AGVITEMINFO_H
