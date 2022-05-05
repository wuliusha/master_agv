#ifndef NETWORK_WIDGET_H
#define NETWORK_WIDGET_H

#include <QWidget>
#include "network.h"
#include "singleProject/iconhelper/iconhelper.h"
#include "queryServer/queryserver.h"

namespace Ui {
class Network_Widget;
}

class Network_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Network_Widget(QWidget *parent = 0);
    ~Network_Widget();
    QTimer *NetworkTimer;
    ServerInit ServerInitItem;      //基础信息

    bool  qdebug_logstop=false;
    QString UrlPath="http://172.16.21.101:19000/wms/robotQuery";
    QString UrlPath1="http://172.16.6.20:8099/shift/agv/taskStatus";

    WWYLPOST WWYLPOSTI;
    ESS_Request ESS_RequestI;

    QString currentUserNuber="";

    void Network_WidgetInit();

    void ESS_RequestI_show();   //QSS 动态显示
    ESS_Request getESS_RequestI(ESS_Request ESS_Request0);

    void WWYLPOST_show();
    WWYLPOST getWWYLPOSTI(WWYLPOST WWYLPOST0);              //把SAP 任务状态 转换为post 并实时更新更新到 MES

    void TextEdit_Request_show(CurrentSend CurrentSendI);

    // QString >> QJson
    QJsonObject getJsonObjectFromString(const QString jsonString);

    // QJson >> QString
    QString getStringFromJsonObject(const QJsonObject& jsonObject);



private slots:

    void on_Post_Button_clicked();

    void on_Clear_Button_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_Type_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_operateEdit_currentTextChanged(const QString &arg1);


    void on_stop_Button_released();

public slots:
    void Network_WidgetTimer();
    void ON_Pressed();
    void ON_Released();


private:
    Ui::Network_Widget *ui;
    QList<QPushButton *>Actionbtns;
};

#endif // NETWORK_WIDGET_H
