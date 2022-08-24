/********************************************************************************
** Form generated from reading UI file 'agvitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGVITEMWIDGET_H
#define UI_AGVITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgvItemWidget
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *detail_Button;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_46;
    QComboBox *taskStatusBox_AGV;
    QHBoxLayout *horizontalLayout_89;
    QLabel *label_52;
    QLineEdit *taskSTQRPoint;
    QHBoxLayout *horizontalLayout_84;
    QLabel *label_45;
    QLineEdit *taskEndQRPoint;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *taskActionBox_AGV;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *AgvExecute;
    QPushButton *CancelButton;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_34;
    QCheckBox *checkBox_Edite;
    QPushButton *Delete_Button;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_62;
    QComboBox *taskstation_IP;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_65;
    QComboBox *AGVType;
    QHBoxLayout *horizontalLayout_58;
    QHBoxLayout *horizontalLayout_62;
    QLabel *label_70;
    QComboBox *station_statrt;
    QHBoxLayout *horizontalLayout_63;
    QLabel *label_71;
    QComboBox *station_dest;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_97;
    QComboBox *StationDesc_s;
    QLineEdit *taskstation_s;
    QHBoxLayout *horizontalLayout_98;
    QComboBox *StationDesc_e;
    QLineEdit *taskstation_e;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_66;
    QComboBox *actionType;
    QHBoxLayout *horizontalLayout_99;
    QLabel *label_64;
    QLineEdit *waitTimer;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *task_sure;
    QPushButton *task_cancel;
    QHBoxLayout *horizontalLayout_25;
    QLineEdit *masege;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *start_charge;
    QPushButton *close_charge;
    QStackedWidget *stackedWidget;
    QWidget *page_6;

    void setupUi(QWidget *AgvItemWidget)
    {
        if (AgvItemWidget->objectName().isEmpty())
            AgvItemWidget->setObjectName(QString::fromUtf8("AgvItemWidget"));
        AgvItemWidget->resize(1570, 719);
        gridLayout_3 = new QGridLayout(AgvItemWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(10);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        widget_3 = new QWidget(AgvItemWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 130));
        widget_3->setMaximumSize(QSize(167777, 167777));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(16777215, 45));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_22->addWidget(label_17);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_8);

        detail_Button = new QPushButton(widget_3);
        detail_Button->setObjectName(QString::fromUtf8("detail_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(detail_Button->sizePolicy().hasHeightForWidth());
        detail_Button->setSizePolicy(sizePolicy);
        detail_Button->setMinimumSize(QSize(45, 40));
        detail_Button->setMaximumSize(QSize(50, 40));
        QFont font1;
        font1.setPointSize(16);
        detail_Button->setFont(font1);
        detail_Button->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"border-radius:15px;"));

        horizontalLayout_22->addWidget(detail_Button);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(30);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_46 = new QLabel(widget_3);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_46->setFont(font2);
        label_46->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
""));

        horizontalLayout->addWidget(label_46);

        taskStatusBox_AGV = new QComboBox(widget_3);
        taskStatusBox_AGV->setObjectName(QString::fromUtf8("taskStatusBox_AGV"));
        sizePolicy.setHeightForWidth(taskStatusBox_AGV->sizePolicy().hasHeightForWidth());
        taskStatusBox_AGV->setSizePolicy(sizePolicy);
        taskStatusBox_AGV->setMinimumSize(QSize(260, 35));
        taskStatusBox_AGV->setMaximumSize(QSize(16777215, 45));
        taskStatusBox_AGV->setFont(font);
        taskStatusBox_AGV->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout->addWidget(taskStatusBox_AGV);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_89 = new QHBoxLayout();
        horizontalLayout_89->setSpacing(3);
        horizontalLayout_89->setObjectName(QString::fromUtf8("horizontalLayout_89"));
        label_52 = new QLabel(widget_3);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setFont(font2);
        label_52->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_89->addWidget(label_52);

        taskSTQRPoint = new QLineEdit(widget_3);
        taskSTQRPoint->setObjectName(QString::fromUtf8("taskSTQRPoint"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(taskSTQRPoint->sizePolicy().hasHeightForWidth());
        taskSTQRPoint->setSizePolicy(sizePolicy1);
        taskSTQRPoint->setMinimumSize(QSize(180, 0));
        QFont font3;
        font3.setPointSize(12);
        taskSTQRPoint->setFont(font3);
        taskSTQRPoint->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_89->addWidget(taskSTQRPoint);

        horizontalLayout_89->setStretch(0, 1);
        horizontalLayout_89->setStretch(1, 10);

        horizontalLayout_2->addLayout(horizontalLayout_89);

        horizontalLayout_84 = new QHBoxLayout();
        horizontalLayout_84->setSpacing(3);
        horizontalLayout_84->setObjectName(QString::fromUtf8("horizontalLayout_84"));
        label_45 = new QLabel(widget_3);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font2);
        label_45->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_84->addWidget(label_45);

        taskEndQRPoint = new QLineEdit(widget_3);
        taskEndQRPoint->setObjectName(QString::fromUtf8("taskEndQRPoint"));
        sizePolicy1.setHeightForWidth(taskEndQRPoint->sizePolicy().hasHeightForWidth());
        taskEndQRPoint->setSizePolicy(sizePolicy1);
        taskEndQRPoint->setMinimumSize(QSize(180, 0));
        taskEndQRPoint->setFont(font3);
        taskEndQRPoint->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_84->addWidget(taskEndQRPoint);

        horizontalLayout_84->setStretch(0, 1);
        horizontalLayout_84->setStretch(1, 10);

        horizontalLayout_2->addLayout(horizontalLayout_84);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        taskActionBox_AGV = new QComboBox(widget_3);
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->addItem(QString());
        taskActionBox_AGV->setObjectName(QString::fromUtf8("taskActionBox_AGV"));
        sizePolicy.setHeightForWidth(taskActionBox_AGV->sizePolicy().hasHeightForWidth());
        taskActionBox_AGV->setSizePolicy(sizePolicy);
        taskActionBox_AGV->setMinimumSize(QSize(200, 35));
        taskActionBox_AGV->setMaximumSize(QSize(16777215, 45));
        taskActionBox_AGV->setFont(font);
        taskActionBox_AGV->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_14->addWidget(taskActionBox_AGV);


        horizontalLayout_2->addLayout(horizontalLayout_14);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(30);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        AgvExecute = new QPushButton(widget_3);
        AgvExecute->setObjectName(QString::fromUtf8("AgvExecute"));
        sizePolicy.setHeightForWidth(AgvExecute->sizePolicy().hasHeightForWidth());
        AgvExecute->setSizePolicy(sizePolicy);
        AgvExecute->setMinimumSize(QSize(0, 45));
        AgvExecute->setMaximumSize(QSize(16777215, 45));
        AgvExecute->setFont(font2);
        AgvExecute->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:15px;\n"
"background-color: rgb(80, 138, 136);\n"
""));

        horizontalLayout_10->addWidget(AgvExecute);

        CancelButton = new QPushButton(widget_3);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        sizePolicy.setHeightForWidth(CancelButton->sizePolicy().hasHeightForWidth());
        CancelButton->setSizePolicy(sizePolicy);
        CancelButton->setMinimumSize(QSize(120, 0));
        CancelButton->setMaximumSize(QSize(16777215, 45));
        CancelButton->setFont(font2);
        CancelButton->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:15px;\n"
"background-color: rgb(80, 138, 136);\n"
""));

        horizontalLayout_10->addWidget(CancelButton);


        horizontalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_9->addWidget(widget_3);

        widget_5 = new QWidget(AgvItemWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(20);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_20 = new QLabel(widget_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMaximumSize(QSize(16777215, 45));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_29->addWidget(label_20);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_34);

        checkBox_Edite = new QCheckBox(widget_5);
        checkBox_Edite->setObjectName(QString::fromUtf8("checkBox_Edite"));
        sizePolicy.setHeightForWidth(checkBox_Edite->sizePolicy().hasHeightForWidth());
        checkBox_Edite->setSizePolicy(sizePolicy);
        checkBox_Edite->setMaximumSize(QSize(36, 36));
        checkBox_Edite->setFont(font1);
        checkBox_Edite->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	Color:white;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 35px;\n"
"    height: 35px;\n"
"}QCheckBox::indicator:unchecked {\n"
"    image: url(:/image/unchecked.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/image/checked.png);\n"
"}"));

        horizontalLayout_9->addWidget(checkBox_Edite);

        Delete_Button = new QPushButton(widget_5);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));
        sizePolicy.setHeightForWidth(Delete_Button->sizePolicy().hasHeightForWidth());
        Delete_Button->setSizePolicy(sizePolicy);
        Delete_Button->setMinimumSize(QSize(90, 45));
        Delete_Button->setMaximumSize(QSize(90, 45));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        Delete_Button->setFont(font4);
        Delete_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; "));

        horizontalLayout_9->addWidget(Delete_Button);

        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);

        horizontalLayout_29->addLayout(horizontalLayout_9);


        verticalLayout_18->addLayout(horizontalLayout_29);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(20);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(15);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(80);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(60, -1, 60, -1);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(15);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(50);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(3);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_62 = new QLabel(widget_5);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setMinimumSize(QSize(0, 40));
        label_62->setFont(font2);
        label_62->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_26->addWidget(label_62);

        taskstation_IP = new QComboBox(widget_5);
        taskstation_IP->setObjectName(QString::fromUtf8("taskstation_IP"));
        sizePolicy.setHeightForWidth(taskstation_IP->sizePolicy().hasHeightForWidth());
        taskstation_IP->setSizePolicy(sizePolicy);
        taskstation_IP->setMinimumSize(QSize(180, 35));
        taskstation_IP->setMaximumSize(QSize(16777215, 45));
        taskstation_IP->setFont(font);
        taskstation_IP->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_26->addWidget(taskstation_IP);

        horizontalLayout_26->setStretch(0, 1);
        horizontalLayout_26->setStretch(1, 5);

        horizontalLayout_11->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(3);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_65 = new QLabel(widget_5);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setFont(font2);
        label_65->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_27->addWidget(label_65);

        AGVType = new QComboBox(widget_5);
        AGVType->addItem(QString());
        AGVType->addItem(QString());
        AGVType->addItem(QString());
        AGVType->setObjectName(QString::fromUtf8("AGVType"));
        sizePolicy.setHeightForWidth(AGVType->sizePolicy().hasHeightForWidth());
        AGVType->setSizePolicy(sizePolicy);
        AGVType->setMinimumSize(QSize(180, 35));
        AGVType->setMaximumSize(QSize(16777215, 45));
        AGVType->setFont(font);
        AGVType->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_27->addWidget(AGVType);

        horizontalLayout_27->setStretch(0, 1);
        horizontalLayout_27->setStretch(1, 5);

        horizontalLayout_11->addLayout(horizontalLayout_27);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setSpacing(50);
        horizontalLayout_58->setObjectName(QString::fromUtf8("horizontalLayout_58"));
        horizontalLayout_62 = new QHBoxLayout();
        horizontalLayout_62->setSpacing(3);
        horizontalLayout_62->setObjectName(QString::fromUtf8("horizontalLayout_62"));
        label_70 = new QLabel(widget_5);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setMinimumSize(QSize(0, 40));
        label_70->setFont(font2);
        label_70->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_62->addWidget(label_70);

        station_statrt = new QComboBox(widget_5);
        station_statrt->setObjectName(QString::fromUtf8("station_statrt"));
        sizePolicy.setHeightForWidth(station_statrt->sizePolicy().hasHeightForWidth());
        station_statrt->setSizePolicy(sizePolicy);
        station_statrt->setMinimumSize(QSize(180, 35));
        station_statrt->setMaximumSize(QSize(16777215, 45));
        station_statrt->setFont(font);
        station_statrt->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_62->addWidget(station_statrt);

        horizontalLayout_62->setStretch(0, 1);
        horizontalLayout_62->setStretch(1, 5);

        horizontalLayout_58->addLayout(horizontalLayout_62);

        horizontalLayout_63 = new QHBoxLayout();
        horizontalLayout_63->setSpacing(3);
        horizontalLayout_63->setObjectName(QString::fromUtf8("horizontalLayout_63"));
        label_71 = new QLabel(widget_5);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setFont(font2);
        label_71->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_63->addWidget(label_71);

        station_dest = new QComboBox(widget_5);
        station_dest->setObjectName(QString::fromUtf8("station_dest"));
        sizePolicy.setHeightForWidth(station_dest->sizePolicy().hasHeightForWidth());
        station_dest->setSizePolicy(sizePolicy);
        station_dest->setMinimumSize(QSize(180, 35));
        station_dest->setMaximumSize(QSize(16777215, 45));
        station_dest->setFont(font);
        station_dest->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_63->addWidget(station_dest);

        horizontalLayout_63->setStretch(0, 1);
        horizontalLayout_63->setStretch(1, 5);

        horizontalLayout_58->addLayout(horizontalLayout_63);

        horizontalLayout_58->setStretch(0, 1);
        horizontalLayout_58->setStretch(1, 1);

        verticalLayout_10->addLayout(horizontalLayout_58);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(50);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_97 = new QHBoxLayout();
        horizontalLayout_97->setSpacing(3);
        horizontalLayout_97->setObjectName(QString::fromUtf8("horizontalLayout_97"));
        StationDesc_s = new QComboBox(widget_5);
        StationDesc_s->addItem(QString());
        StationDesc_s->setObjectName(QString::fromUtf8("StationDesc_s"));
        sizePolicy.setHeightForWidth(StationDesc_s->sizePolicy().hasHeightForWidth());
        StationDesc_s->setSizePolicy(sizePolicy);
        StationDesc_s->setMinimumSize(QSize(180, 35));
        StationDesc_s->setMaximumSize(QSize(16777215, 45));
        StationDesc_s->setFont(font);
        StationDesc_s->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_97->addWidget(StationDesc_s);

        taskstation_s = new QLineEdit(widget_5);
        taskstation_s->setObjectName(QString::fromUtf8("taskstation_s"));
        sizePolicy1.setHeightForWidth(taskstation_s->sizePolicy().hasHeightForWidth());
        taskstation_s->setSizePolicy(sizePolicy1);
        taskstation_s->setMinimumSize(QSize(180, 0));
        taskstation_s->setFont(font3);
        taskstation_s->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_97->addWidget(taskstation_s);

        horizontalLayout_97->setStretch(1, 10);

        horizontalLayout_24->addLayout(horizontalLayout_97);

        horizontalLayout_98 = new QHBoxLayout();
        horizontalLayout_98->setSpacing(3);
        horizontalLayout_98->setObjectName(QString::fromUtf8("horizontalLayout_98"));
        StationDesc_e = new QComboBox(widget_5);
        StationDesc_e->addItem(QString());
        StationDesc_e->setObjectName(QString::fromUtf8("StationDesc_e"));
        sizePolicy.setHeightForWidth(StationDesc_e->sizePolicy().hasHeightForWidth());
        StationDesc_e->setSizePolicy(sizePolicy);
        StationDesc_e->setMinimumSize(QSize(180, 35));
        StationDesc_e->setMaximumSize(QSize(16777215, 45));
        StationDesc_e->setFont(font);
        StationDesc_e->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_98->addWidget(StationDesc_e);

        taskstation_e = new QLineEdit(widget_5);
        taskstation_e->setObjectName(QString::fromUtf8("taskstation_e"));
        sizePolicy1.setHeightForWidth(taskstation_e->sizePolicy().hasHeightForWidth());
        taskstation_e->setSizePolicy(sizePolicy1);
        taskstation_e->setMinimumSize(QSize(180, 30));
        taskstation_e->setFont(font3);
        taskstation_e->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_98->addWidget(taskstation_e);

        horizontalLayout_98->setStretch(1, 10);

        horizontalLayout_24->addLayout(horizontalLayout_98);


        verticalLayout_10->addLayout(horizontalLayout_24);


        horizontalLayout_12->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(15);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(3);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        label_66 = new QLabel(widget_5);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setFont(font2);
        label_66->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_37->addWidget(label_66);

        actionType = new QComboBox(widget_5);
        actionType->addItem(QString());
        actionType->addItem(QString());
        actionType->setObjectName(QString::fromUtf8("actionType"));
        sizePolicy.setHeightForWidth(actionType->sizePolicy().hasHeightForWidth());
        actionType->setSizePolicy(sizePolicy);
        actionType->setMinimumSize(QSize(180, 35));
        actionType->setMaximumSize(QSize(16777215, 45));
        actionType->setFont(font);
        actionType->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_37->addWidget(actionType);

        horizontalLayout_37->setStretch(0, 1);
        horizontalLayout_37->setStretch(1, 5);

        verticalLayout_11->addLayout(horizontalLayout_37);

        horizontalLayout_99 = new QHBoxLayout();
        horizontalLayout_99->setSpacing(3);
        horizontalLayout_99->setObjectName(QString::fromUtf8("horizontalLayout_99"));
        label_64 = new QLabel(widget_5);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setFont(font2);
        label_64->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_99->addWidget(label_64);

        waitTimer = new QLineEdit(widget_5);
        waitTimer->setObjectName(QString::fromUtf8("waitTimer"));
        sizePolicy1.setHeightForWidth(waitTimer->sizePolicy().hasHeightForWidth());
        waitTimer->setSizePolicy(sizePolicy1);
        waitTimer->setMinimumSize(QSize(180, 30));
        waitTimer->setFont(font3);
        waitTimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_99->addWidget(waitTimer);

        horizontalLayout_99->setStretch(0, 1);
        horizontalLayout_99->setStretch(1, 10);

        verticalLayout_11->addLayout(horizontalLayout_99);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(50);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        task_sure = new QPushButton(widget_5);
        task_sure->setObjectName(QString::fromUtf8("task_sure"));
        sizePolicy.setHeightForWidth(task_sure->sizePolicy().hasHeightForWidth());
        task_sure->setSizePolicy(sizePolicy);
        task_sure->setMinimumSize(QSize(0, 45));
        task_sure->setMaximumSize(QSize(16777215, 45));
        task_sure->setFont(font2);
        task_sure->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_28->addWidget(task_sure);

        task_cancel = new QPushButton(widget_5);
        task_cancel->setObjectName(QString::fromUtf8("task_cancel"));
        sizePolicy.setHeightForWidth(task_cancel->sizePolicy().hasHeightForWidth());
        task_cancel->setSizePolicy(sizePolicy);
        task_cancel->setMinimumSize(QSize(120, 0));
        task_cancel->setMaximumSize(QSize(16777215, 45));
        task_cancel->setFont(font2);
        task_cancel->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);\n"
""));

        horizontalLayout_28->addWidget(task_cancel);

        horizontalLayout_28->setStretch(0, 1);
        horizontalLayout_28->setStretch(1, 1);

        verticalLayout_11->addLayout(horizontalLayout_28);


        horizontalLayout_12->addLayout(verticalLayout_11);

        horizontalLayout_12->setStretch(0, 2);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_12->addLayout(horizontalLayout_12);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(80);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(60, -1, 60, -1);
        masege = new QLineEdit(widget_5);
        masege->setObjectName(QString::fromUtf8("masege"));
        sizePolicy1.setHeightForWidth(masege->sizePolicy().hasHeightForWidth());
        masege->setSizePolicy(sizePolicy1);
        masege->setMinimumSize(QSize(180, 35));
        masege->setMaximumSize(QSize(2000, 35));
        masege->setFont(font3);
        masege->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_25->addWidget(masege);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(50);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        start_charge = new QPushButton(widget_5);
        start_charge->setObjectName(QString::fromUtf8("start_charge"));
        sizePolicy.setHeightForWidth(start_charge->sizePolicy().hasHeightForWidth());
        start_charge->setSizePolicy(sizePolicy);
        start_charge->setMinimumSize(QSize(0, 45));
        start_charge->setMaximumSize(QSize(16777215, 45));
        start_charge->setFont(font2);
        start_charge->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_30->addWidget(start_charge);

        close_charge = new QPushButton(widget_5);
        close_charge->setObjectName(QString::fromUtf8("close_charge"));
        sizePolicy.setHeightForWidth(close_charge->sizePolicy().hasHeightForWidth());
        close_charge->setSizePolicy(sizePolicy);
        close_charge->setMinimumSize(QSize(180, 0));
        close_charge->setMaximumSize(QSize(16777215, 45));
        close_charge->setFont(font2);
        close_charge->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);\n"
""));

        horizontalLayout_30->addWidget(close_charge);

        horizontalLayout_30->setStretch(0, 1);
        horizontalLayout_30->setStretch(1, 1);

        horizontalLayout_25->addLayout(horizontalLayout_30);

        horizontalLayout_25->setStretch(0, 2);
        horizontalLayout_25->setStretch(1, 1);

        verticalLayout_12->addLayout(horizontalLayout_25);

        verticalLayout_12->setStretch(0, 4);
        verticalLayout_12->setStretch(1, 1);

        verticalLayout_17->addLayout(verticalLayout_12);

        stackedWidget = new QStackedWidget(widget_5);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 100));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        stackedWidget->addWidget(page_6);

        verticalLayout_17->addWidget(stackedWidget);

        verticalLayout_17->setStretch(0, 1);
        verticalLayout_17->setStretch(1, 2);

        verticalLayout_18->addLayout(verticalLayout_17);

        verticalLayout_18->setStretch(0, 1);
        verticalLayout_18->setStretch(1, 10);

        gridLayout->addLayout(verticalLayout_18, 0, 0, 1, 1);


        verticalLayout_9->addWidget(widget_5);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 5);

        gridLayout_3->addLayout(verticalLayout_9, 0, 0, 1, 1);


        retranslateUi(AgvItemWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AgvItemWidget);
    } // setupUi

    void retranslateUi(QWidget *AgvItemWidget)
    {
        AgvItemWidget->setWindowTitle(QApplication::translate("AgvItemWidget", "Form", nullptr));
        label_17->setText(QApplication::translate("AgvItemWidget", "AGV\345\215\225\344\270\252\346\214\207\344\273\244  ", nullptr));
        detail_Button->setText(QString());
        label_46->setText(QApplication::translate("AgvItemWidget", "AGVIP:", nullptr));
        label_52->setText(QApplication::translate("AgvItemWidget", "\350\265\267\345\247\213:", nullptr));
        taskSTQRPoint->setText(QString());
        taskSTQRPoint->setPlaceholderText(QApplication::translate("AgvItemWidget", "\350\265\267\345\247\213\344\272\214\347\273\264\347\240\201", nullptr));
        label_45->setText(QApplication::translate("AgvItemWidget", "\347\233\256\346\240\207:", nullptr));
        taskEndQRPoint->setText(QString());
        taskEndQRPoint->setPlaceholderText(QApplication::translate("AgvItemWidget", "\347\233\256\346\240\207\344\272\214\347\273\264\347\240\201", nullptr));
        taskActionBox_AGV->setItemText(0, QApplication::translate("AgvItemWidget", "\347\247\273\345\212\250\346\214\207\344\273\244", nullptr));
        taskActionBox_AGV->setItemText(1, QApplication::translate("AgvItemWidget", "\344\270\276\345\215\207\346\214\207\344\273\244", nullptr));
        taskActionBox_AGV->setItemText(2, QApplication::translate("AgvItemWidget", "\344\270\213\351\231\215\346\214\207\344\273\244", nullptr));
        taskActionBox_AGV->setItemText(3, QApplication::translate("AgvItemWidget", "\345\274\200\345\247\213\345\205\205\347\224\265", nullptr));
        taskActionBox_AGV->setItemText(4, QApplication::translate("AgvItemWidget", "\347\273\223\346\235\237\345\205\205\347\224\265", nullptr));
        taskActionBox_AGV->setItemText(5, QApplication::translate("AgvItemWidget", "\345\210\235\345\247\213\345\214\226\345\221\275\344\273\244", nullptr));
        taskActionBox_AGV->setItemText(6, QApplication::translate("AgvItemWidget", "\345\220\214\346\255\245\345\270\247\347\274\226\347\240\201", nullptr));

        AgvExecute->setText(QApplication::translate("AgvItemWidget", " \347\241\256\345\256\232\346\211\247\350\241\214 ", nullptr));
        CancelButton->setText(QApplication::translate("AgvItemWidget", "\345\217\226\346\266\210", nullptr));
        label_20->setText(QApplication::translate("AgvItemWidget", "AGV\350\277\220\350\276\223\344\273\273\345\212\241\347\225\214\351\235\242   ", nullptr));
        checkBox_Edite->setText(QString());
        Delete_Button->setText(QApplication::translate("AgvItemWidget", "\345\276\252\347\216\257", nullptr));
        label_62->setText(QApplication::translate("AgvItemWidget", "AGVIP:", nullptr));
        label_65->setText(QApplication::translate("AgvItemWidget", "\345\212\250\344\275\234\347\261\273\345\236\213:", nullptr));
        AGVType->setItemText(0, QApplication::translate("AgvItemWidget", "\344\270\276\345\215\207\347\261\273\345\236\213", nullptr));
        AGVType->setItemText(1, QApplication::translate("AgvItemWidget", "\346\273\232\347\255\222\347\261\273\345\236\213", nullptr));
        AGVType->setItemText(2, QApplication::translate("AgvItemWidget", "\345\244\271\346\212\261\347\261\273\345\236\213", nullptr));

        label_70->setText(QApplication::translate("AgvItemWidget", "\350\265\267\345\247\213\347\253\231\347\202\271:", nullptr));
        label_71->setText(QApplication::translate("AgvItemWidget", "\347\233\256\346\240\207\347\253\231\347\202\271:", nullptr));
        StationDesc_s->setItemText(0, QApplication::translate("AgvItemWidget", "\350\265\267\345\247\213\344\272\214\347\273\264\347\240\201", nullptr));

        taskstation_s->setText(QString());
        taskstation_s->setPlaceholderText(QApplication::translate("AgvItemWidget", "\350\265\267\345\247\213\344\272\214\347\273\264\347\240\201", nullptr));
        StationDesc_e->setItemText(0, QApplication::translate("AgvItemWidget", "\347\233\256\346\240\207\344\272\214\347\273\264\347\240\201", nullptr));

        taskstation_e->setText(QString());
        taskstation_e->setPlaceholderText(QApplication::translate("AgvItemWidget", "\347\233\256\346\240\207\344\272\214\347\273\264\347\240\201", nullptr));
        label_66->setText(QApplication::translate("AgvItemWidget", "\346\230\257\345\220\246\350\277\224\345\233\236:", nullptr));
        actionType->setItemText(0, QApplication::translate("AgvItemWidget", "\344\270\215\346\230\257", nullptr));
        actionType->setItemText(1, QApplication::translate("AgvItemWidget", "\346\230\257", nullptr));

        label_64->setText(QApplication::translate("AgvItemWidget", "\347\255\211\345\276\205\346\227\266\351\227\264:", nullptr));
        waitTimer->setText(QApplication::translate("AgvItemWidget", "15", nullptr));
        waitTimer->setPlaceholderText(QApplication::translate("AgvItemWidget", "\347\247\222", nullptr));
        task_sure->setText(QApplication::translate("AgvItemWidget", " \347\241\256\345\256\232\346\217\220\344\272\244 ", nullptr));
        task_cancel->setText(QApplication::translate("AgvItemWidget", "\345\217\226\346\266\210", nullptr));
        masege->setText(QString());
        masege->setPlaceholderText(QApplication::translate("AgvItemWidget", "\346\217\220\347\244\272:", nullptr));
        start_charge->setText(QApplication::translate("AgvItemWidget", "\345\274\200\345\247\213\345\205\205\347\224\265", nullptr));
        close_charge->setText(QApplication::translate("AgvItemWidget", "\347\273\223\346\235\237\345\205\205\347\224\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgvItemWidget: public Ui_AgvItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGVITEMWIDGET_H
