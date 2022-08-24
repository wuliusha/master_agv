/********************************************************************************
** Form generated from reading UI file 'system_agv.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_AGV_H
#define UI_SYSTEM_AGV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_system_agv
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_9;
    QGridLayout *gridLayout_15;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_48;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_27;
    QHBoxLayout *horizontalLayout_49;
    QHBoxLayout *horizontalLayout_51;
    QHBoxLayout *horizontalLayout_57;
    QLabel *label_69;
    QLineEdit *AGVIP;
    QPushButton *query_agvip;
    QSpacerItem *horizontalSpacer_28;
    QHBoxLayout *horizontalLayout_52;
    QPushButton *add_agvip;
    QPushButton *delete_agvip;
    QTableWidget *tableWidget_agv;
    QHBoxLayout *horizontalLayout_53;
    QSpacerItem *horizontalSpacer_29;
    QHBoxLayout *horizontalLayout_54;
    QPushButton *update_agvip;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QWidget *widget_6;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_33;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_36;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_63;
    QLineEdit *currentLine;
    QComboBox *lineType;
    QPushButton *query_LineInfo;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *add_LineInfo;
    QPushButton *delete_LineInfo;
    QTableWidget *tableWidget_Line;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *Alter_LineInfo;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *update_LineInfo;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_4;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *query_rule;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_91;
    QLabel *label_54;
    QLineEdit *keyId;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *add_rule;
    QPushButton *delete_rule;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_88;
    QLabel *label_51;
    QLineEdit *assistRoute_S;
    QHBoxLayout *horizontalLayout_86;
    QLabel *label_49;
    QLineEdit *assistPoint_S;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_90;
    QLabel *label_53;
    QLineEdit *assistRoute_E;
    QHBoxLayout *horizontalLayout_87;
    QLabel *label_50;
    QLineEdit *assistPoint_E;
    QWidget *widget_2;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_31;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_19;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_95;
    QLabel *label_58;
    QLineEdit *RouteName;
    QHBoxLayout *horizontalLayout_96;
    QLabel *label_59;
    QLineEdit *SubTaskType;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_93;
    QLabel *label_56;
    QLineEdit *Point_S;
    QHBoxLayout *horizontalLayout_94;
    QLabel *label_57;
    QLineEdit *Point_E;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *add_rule_2;
    QPushButton *delete_rule_2;
    QTableWidget *tableWidget_rule;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer;
    QPushButton *update_rule;

    void setupUi(QWidget *system_agv)
    {
        if (system_agv->objectName().isEmpty())
            system_agv->setObjectName(QString::fromUtf8("system_agv"));
        system_agv->resize(1279, 701);
        gridLayout = new QGridLayout(system_agv);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(system_agv);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"	border-width:5px;\n"
"	border-color:rgb(112, 161, 159);\n"
"	border-style: outset;\n"
"	background-color: rgb(132, 171, 208);\n"
"} \n"
"\n"
"QTabBar::tab{\n"
"	border-color:rgb(48, 104, 151);\n"
"	border-bottom-color: #00aa7f;\n"
"	border-top-left-radius: 10px;\n"
"	border-top-right-radius: 10px;\n"
"	max-width:30ex;\n"
"    min-width:30ex; \n"
"	min-height:15px;\n"
"	font:18px Times New Roman;\n"
"	padding: 0px;\n"
"}\n"
"QTabBar::tab:hover{\n"
"	background:rgb(198, 197, 146);\n"
"    color:black;\n"
"}\n"
"QTabBar::tab:selected{\n"
"	border-color: black;\n"
"	background:green;\n"
"	color:white;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"	border-top: 2px solid #E5E5E5;\n"
"	border-bottom: 2px solid #E5E5E5;\n"
"	border-left:1px solid #E5E5E5;\n"
"	alignment: right;\n"
"	font-size: 14px;\n"
"	background-color:#FFFFFF;\n"
"}\n"
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_9 = new QWidget(tab_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 212, 169);"));
        gridLayout_15 = new QGridLayout(widget_9);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(20);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_26);

        label_23 = new QLabel(widget_9);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(16777215, 45));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_48->addWidget(label_23);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_27);


        verticalLayout_15->addLayout(horizontalLayout_48);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(100);
        horizontalLayout_51->setObjectName(QString::fromUtf8("horizontalLayout_51"));
        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setSpacing(5);
        horizontalLayout_57->setObjectName(QString::fromUtf8("horizontalLayout_57"));
        label_69 = new QLabel(widget_9);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_69->setFont(font2);
        label_69->setStyleSheet(QString::fromUtf8("color: white;  \n"
""));

        horizontalLayout_57->addWidget(label_69);

        AGVIP = new QLineEdit(widget_9);
        AGVIP->setObjectName(QString::fromUtf8("AGVIP"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AGVIP->sizePolicy().hasHeightForWidth());
        AGVIP->setSizePolicy(sizePolicy);
        AGVIP->setMinimumSize(QSize(180, 30));
        AGVIP->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(12);
        AGVIP->setFont(font3);
        AGVIP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_57->addWidget(AGVIP);


        horizontalLayout_51->addLayout(horizontalLayout_57);

        query_agvip = new QPushButton(widget_9);
        query_agvip->setObjectName(QString::fromUtf8("query_agvip"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(query_agvip->sizePolicy().hasHeightForWidth());
        query_agvip->setSizePolicy(sizePolicy1);
        query_agvip->setMinimumSize(QSize(120, 40));
        query_agvip->setMaximumSize(QSize(120, 40));
        QFont font4;
        font4.setPointSize(16);
        query_agvip->setFont(font4);
        query_agvip->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_51->addWidget(query_agvip);

        horizontalLayout_51->setStretch(0, 3);
        horizontalLayout_51->setStretch(1, 1);

        horizontalLayout_49->addLayout(horizontalLayout_51);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_28);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(20);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        add_agvip = new QPushButton(widget_9);
        add_agvip->setObjectName(QString::fromUtf8("add_agvip"));
        sizePolicy1.setHeightForWidth(add_agvip->sizePolicy().hasHeightForWidth());
        add_agvip->setSizePolicy(sizePolicy1);
        add_agvip->setMinimumSize(QSize(120, 40));
        add_agvip->setMaximumSize(QSize(16777215, 45));
        add_agvip->setFont(font2);
        add_agvip->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_52->addWidget(add_agvip);

        delete_agvip = new QPushButton(widget_9);
        delete_agvip->setObjectName(QString::fromUtf8("delete_agvip"));
        sizePolicy1.setHeightForWidth(delete_agvip->sizePolicy().hasHeightForWidth());
        delete_agvip->setSizePolicy(sizePolicy1);
        delete_agvip->setMinimumSize(QSize(120, 0));
        delete_agvip->setMaximumSize(QSize(16777215, 45));
        delete_agvip->setFont(font2);
        delete_agvip->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_52->addWidget(delete_agvip);


        horizontalLayout_49->addLayout(horizontalLayout_52);


        verticalLayout_15->addLayout(horizontalLayout_49);

        tableWidget_agv = new QTableWidget(widget_9);
        if (tableWidget_agv->columnCount() < 10)
            tableWidget_agv->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        if (tableWidget_agv->rowCount() < 5)
            tableWidget_agv->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_agv->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_agv->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_agv->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_agv->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_agv->setVerticalHeaderItem(4, __qtablewidgetitem14);
        tableWidget_agv->setObjectName(QString::fromUtf8("tableWidget_agv"));
        tableWidget_agv->setFont(font3);
        tableWidget_agv->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout_15->addWidget(tableWidget_agv);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(10);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_29);

        horizontalLayout_54 = new QHBoxLayout();
        horizontalLayout_54->setSpacing(20);
        horizontalLayout_54->setObjectName(QString::fromUtf8("horizontalLayout_54"));
        update_agvip = new QPushButton(widget_9);
        update_agvip->setObjectName(QString::fromUtf8("update_agvip"));
        sizePolicy1.setHeightForWidth(update_agvip->sizePolicy().hasHeightForWidth());
        update_agvip->setSizePolicy(sizePolicy1);
        update_agvip->setMinimumSize(QSize(160, 40));
        update_agvip->setMaximumSize(QSize(16777215, 45));
        update_agvip->setFont(font2);
        update_agvip->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_54->addWidget(update_agvip);


        horizontalLayout_53->addLayout(horizontalLayout_54);

        horizontalLayout_53->setStretch(0, 10);
        horizontalLayout_53->setStretch(1, 1);

        verticalLayout_15->addLayout(horizontalLayout_53);

        verticalLayout_15->setStretch(0, 1);
        verticalLayout_15->setStretch(1, 1);
        verticalLayout_15->setStretch(2, 10);
        verticalLayout_15->setStretch(3, 1);

        gridLayout_15->addLayout(verticalLayout_15, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_9, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_6 = new QWidget(tab);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout_10 = new QGridLayout(widget_6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(20);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_20);

        label_18 = new QLabel(widget_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(16777215, 45));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_33->addWidget(label_18);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_21);


        verticalLayout_7->addLayout(horizontalLayout_33);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(100);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(5);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_63 = new QLabel(widget_6);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setFont(font2);
        label_63->setStyleSheet(QString::fromUtf8("color: white;  \n"
""));

        horizontalLayout_20->addWidget(label_63);

        currentLine = new QLineEdit(widget_6);
        currentLine->setObjectName(QString::fromUtf8("currentLine"));
        sizePolicy.setHeightForWidth(currentLine->sizePolicy().hasHeightForWidth());
        currentLine->setSizePolicy(sizePolicy);
        currentLine->setMinimumSize(QSize(180, 30));
        currentLine->setMaximumSize(QSize(16777215, 40));
        currentLine->setFont(font3);
        currentLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_20->addWidget(currentLine);

        lineType = new QComboBox(widget_6);
        lineType->addItem(QString());
        lineType->addItem(QString());
        lineType->setObjectName(QString::fromUtf8("lineType"));
        sizePolicy1.setHeightForWidth(lineType->sizePolicy().hasHeightForWidth());
        lineType->setSizePolicy(sizePolicy1);
        lineType->setMinimumSize(QSize(120, 35));
        lineType->setMaximumSize(QSize(16777215, 45));
        lineType->setFont(font1);
        lineType->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
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

        horizontalLayout_20->addWidget(lineType);


        horizontalLayout_34->addLayout(horizontalLayout_20);

        query_LineInfo = new QPushButton(widget_6);
        query_LineInfo->setObjectName(QString::fromUtf8("query_LineInfo"));
        sizePolicy1.setHeightForWidth(query_LineInfo->sizePolicy().hasHeightForWidth());
        query_LineInfo->setSizePolicy(sizePolicy1);
        query_LineInfo->setMinimumSize(QSize(120, 40));
        query_LineInfo->setMaximumSize(QSize(120, 40));
        query_LineInfo->setFont(font4);
        query_LineInfo->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_34->addWidget(query_LineInfo);

        horizontalLayout_34->setStretch(0, 3);
        horizontalLayout_34->setStretch(1, 1);

        horizontalLayout_36->addLayout(horizontalLayout_34);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_4);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(20);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        add_LineInfo = new QPushButton(widget_6);
        add_LineInfo->setObjectName(QString::fromUtf8("add_LineInfo"));
        sizePolicy1.setHeightForWidth(add_LineInfo->sizePolicy().hasHeightForWidth());
        add_LineInfo->setSizePolicy(sizePolicy1);
        add_LineInfo->setMinimumSize(QSize(120, 40));
        add_LineInfo->setMaximumSize(QSize(16777215, 45));
        add_LineInfo->setFont(font2);
        add_LineInfo->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_35->addWidget(add_LineInfo);

        delete_LineInfo = new QPushButton(widget_6);
        delete_LineInfo->setObjectName(QString::fromUtf8("delete_LineInfo"));
        sizePolicy1.setHeightForWidth(delete_LineInfo->sizePolicy().hasHeightForWidth());
        delete_LineInfo->setSizePolicy(sizePolicy1);
        delete_LineInfo->setMinimumSize(QSize(120, 0));
        delete_LineInfo->setMaximumSize(QSize(16777215, 45));
        delete_LineInfo->setFont(font2);
        delete_LineInfo->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_35->addWidget(delete_LineInfo);


        horizontalLayout_36->addLayout(horizontalLayout_35);


        verticalLayout_7->addLayout(horizontalLayout_36);

        tableWidget_Line = new QTableWidget(widget_6);
        if (tableWidget_Line->columnCount() < 12)
            tableWidget_Line->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(9, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(10, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_Line->setHorizontalHeaderItem(11, __qtablewidgetitem26);
        if (tableWidget_Line->rowCount() < 5)
            tableWidget_Line->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_Line->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_Line->setVerticalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_Line->setVerticalHeaderItem(2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_Line->setVerticalHeaderItem(3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_Line->setVerticalHeaderItem(4, __qtablewidgetitem31);
        tableWidget_Line->setObjectName(QString::fromUtf8("tableWidget_Line"));
        tableWidget_Line->setFont(font3);
        tableWidget_Line->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout_7->addWidget(tableWidget_Line);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(10);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        Alter_LineInfo = new QPushButton(widget_6);
        Alter_LineInfo->setObjectName(QString::fromUtf8("Alter_LineInfo"));
        sizePolicy1.setHeightForWidth(Alter_LineInfo->sizePolicy().hasHeightForWidth());
        Alter_LineInfo->setSizePolicy(sizePolicy1);
        Alter_LineInfo->setMinimumSize(QSize(0, 40));
        Alter_LineInfo->setMaximumSize(QSize(16777215, 45));
        Alter_LineInfo->setFont(font2);
        Alter_LineInfo->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_18->addWidget(Alter_LineInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(20);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        update_LineInfo = new QPushButton(widget_6);
        update_LineInfo->setObjectName(QString::fromUtf8("update_LineInfo"));
        sizePolicy1.setHeightForWidth(update_LineInfo->sizePolicy().hasHeightForWidth());
        update_LineInfo->setSizePolicy(sizePolicy1);
        update_LineInfo->setMinimumSize(QSize(160, 40));
        update_LineInfo->setMaximumSize(QSize(16777215, 45));
        update_LineInfo->setFont(font2);
        update_LineInfo->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_32->addWidget(update_LineInfo);


        horizontalLayout_18->addLayout(horizontalLayout_32);

        horizontalLayout_18->setStretch(1, 10);
        horizontalLayout_18->setStretch(2, 1);

        verticalLayout_7->addLayout(horizontalLayout_18);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1);
        verticalLayout_7->setStretch(2, 10);
        verticalLayout_7->setStretch(3, 1);

        gridLayout_10->addLayout(verticalLayout_7, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_6, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(10);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        widget_4->setMaximumSize(QSize(167777, 167777));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout_7 = new QGridLayout(widget_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_7);

        label_19 = new QLabel(widget_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(16777215, 45));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_23->addWidget(label_19);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_11);

        query_rule = new QPushButton(widget_4);
        query_rule->setObjectName(QString::fromUtf8("query_rule"));
        sizePolicy1.setHeightForWidth(query_rule->sizePolicy().hasHeightForWidth());
        query_rule->setSizePolicy(sizePolicy1);
        query_rule->setMinimumSize(QSize(120, 40));
        query_rule->setMaximumSize(QSize(120, 40));
        query_rule->setFont(font4);
        query_rule->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_23->addWidget(query_rule);


        verticalLayout_3->addLayout(horizontalLayout_23);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(50);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_91 = new QHBoxLayout();
        horizontalLayout_91->setSpacing(3);
        horizontalLayout_91->setObjectName(QString::fromUtf8("horizontalLayout_91"));
        label_54 = new QLabel(widget_4);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setFont(font2);
        label_54->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_91->addWidget(label_54);

        keyId = new QLineEdit(widget_4);
        keyId->setObjectName(QString::fromUtf8("keyId"));
        sizePolicy.setHeightForWidth(keyId->sizePolicy().hasHeightForWidth());
        keyId->setSizePolicy(sizePolicy);
        keyId->setMinimumSize(QSize(30, 0));
        keyId->setMaximumSize(QSize(16777215, 45));
        keyId->setFont(font3);
        keyId->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_91->addWidget(keyId);

        horizontalLayout_91->setStretch(0, 1);
        horizontalLayout_91->setStretch(1, 10);

        horizontalLayout_17->addLayout(horizontalLayout_91);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_3);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(30);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        add_rule = new QPushButton(widget_4);
        add_rule->setObjectName(QString::fromUtf8("add_rule"));
        sizePolicy1.setHeightForWidth(add_rule->sizePolicy().hasHeightForWidth());
        add_rule->setSizePolicy(sizePolicy1);
        add_rule->setMinimumSize(QSize(120, 35));
        add_rule->setMaximumSize(QSize(16777215, 45));
        add_rule->setFont(font2);
        add_rule->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);\n"
""));

        horizontalLayout_16->addWidget(add_rule);

        delete_rule = new QPushButton(widget_4);
        delete_rule->setObjectName(QString::fromUtf8("delete_rule"));
        sizePolicy1.setHeightForWidth(delete_rule->sizePolicy().hasHeightForWidth());
        delete_rule->setSizePolicy(sizePolicy1);
        delete_rule->setMinimumSize(QSize(120, 0));
        delete_rule->setMaximumSize(QSize(16777215, 45));
        delete_rule->setFont(font2);
        delete_rule->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);\n"
""));

        horizontalLayout_16->addWidget(delete_rule);


        horizontalLayout_17->addLayout(horizontalLayout_16);

        horizontalLayout_17->setStretch(0, 5);
        horizontalLayout_17->setStretch(1, 1);
        horizontalLayout_17->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(50);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_88 = new QHBoxLayout();
        horizontalLayout_88->setSpacing(3);
        horizontalLayout_88->setObjectName(QString::fromUtf8("horizontalLayout_88"));
        label_51 = new QLabel(widget_4);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setFont(font2);
        label_51->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_88->addWidget(label_51);

        assistRoute_S = new QLineEdit(widget_4);
        assistRoute_S->setObjectName(QString::fromUtf8("assistRoute_S"));
        sizePolicy.setHeightForWidth(assistRoute_S->sizePolicy().hasHeightForWidth());
        assistRoute_S->setSizePolicy(sizePolicy);
        assistRoute_S->setMinimumSize(QSize(180, 30));
        assistRoute_S->setMaximumSize(QSize(16777215, 45));
        assistRoute_S->setFont(font3);
        assistRoute_S->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_88->addWidget(assistRoute_S);

        horizontalLayout_88->setStretch(0, 1);
        horizontalLayout_88->setStretch(1, 10);

        horizontalLayout_6->addLayout(horizontalLayout_88);

        horizontalLayout_86 = new QHBoxLayout();
        horizontalLayout_86->setSpacing(3);
        horizontalLayout_86->setObjectName(QString::fromUtf8("horizontalLayout_86"));
        label_49 = new QLabel(widget_4);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setFont(font2);
        label_49->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_86->addWidget(label_49);

        assistPoint_S = new QLineEdit(widget_4);
        assistPoint_S->setObjectName(QString::fromUtf8("assistPoint_S"));
        sizePolicy.setHeightForWidth(assistPoint_S->sizePolicy().hasHeightForWidth());
        assistPoint_S->setSizePolicy(sizePolicy);
        assistPoint_S->setMinimumSize(QSize(180, 0));
        assistPoint_S->setMaximumSize(QSize(16777215, 45));
        assistPoint_S->setFont(font3);
        assistPoint_S->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_86->addWidget(assistPoint_S);

        horizontalLayout_86->setStretch(0, 1);
        horizontalLayout_86->setStretch(1, 10);

        horizontalLayout_6->addLayout(horizontalLayout_86);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(50);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_90 = new QHBoxLayout();
        horizontalLayout_90->setSpacing(3);
        horizontalLayout_90->setObjectName(QString::fromUtf8("horizontalLayout_90"));
        label_53 = new QLabel(widget_4);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setFont(font2);
        label_53->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_90->addWidget(label_53);

        assistRoute_E = new QLineEdit(widget_4);
        assistRoute_E->setObjectName(QString::fromUtf8("assistRoute_E"));
        sizePolicy.setHeightForWidth(assistRoute_E->sizePolicy().hasHeightForWidth());
        assistRoute_E->setSizePolicy(sizePolicy);
        assistRoute_E->setMinimumSize(QSize(180, 30));
        assistRoute_E->setMaximumSize(QSize(16777215, 45));
        assistRoute_E->setFont(font3);
        assistRoute_E->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_90->addWidget(assistRoute_E);

        horizontalLayout_90->setStretch(0, 1);
        horizontalLayout_90->setStretch(1, 10);

        horizontalLayout_8->addLayout(horizontalLayout_90);

        horizontalLayout_87 = new QHBoxLayout();
        horizontalLayout_87->setSpacing(3);
        horizontalLayout_87->setObjectName(QString::fromUtf8("horizontalLayout_87"));
        label_50 = new QLabel(widget_4);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setFont(font2);
        label_50->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_87->addWidget(label_50);

        assistPoint_E = new QLineEdit(widget_4);
        assistPoint_E->setObjectName(QString::fromUtf8("assistPoint_E"));
        sizePolicy.setHeightForWidth(assistPoint_E->sizePolicy().hasHeightForWidth());
        assistPoint_E->setSizePolicy(sizePolicy);
        assistPoint_E->setMinimumSize(QSize(180, 0));
        assistPoint_E->setMaximumSize(QSize(16777215, 45));
        assistPoint_E->setFont(font3);
        assistPoint_E->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_87->addWidget(assistPoint_E);

        horizontalLayout_87->setStretch(0, 1);
        horizontalLayout_87->setStretch(1, 10);

        horizontalLayout_8->addLayout(horizontalLayout_87);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_8);


        gridLayout_7->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_13->addWidget(widget_4);

        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(167777, 167777));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout_8 = new QGridLayout(widget_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(15);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_18);

        label_21 = new QLabel(widget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(16777215, 45));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_31->addWidget(label_21);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_19);


        verticalLayout_5->addLayout(horizontalLayout_31);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_95 = new QHBoxLayout();
        horizontalLayout_95->setSpacing(3);
        horizontalLayout_95->setObjectName(QString::fromUtf8("horizontalLayout_95"));
        label_58 = new QLabel(widget_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setMinimumSize(QSize(0, 40));
        label_58->setFont(font2);
        label_58->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_95->addWidget(label_58);

        RouteName = new QLineEdit(widget_2);
        RouteName->setObjectName(QString::fromUtf8("RouteName"));
        sizePolicy.setHeightForWidth(RouteName->sizePolicy().hasHeightForWidth());
        RouteName->setSizePolicy(sizePolicy);
        RouteName->setMinimumSize(QSize(120, 0));
        RouteName->setFont(font3);
        RouteName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_95->addWidget(RouteName);

        horizontalLayout_95->setStretch(0, 1);
        horizontalLayout_95->setStretch(1, 10);

        horizontalLayout_4->addLayout(horizontalLayout_95);

        horizontalLayout_96 = new QHBoxLayout();
        horizontalLayout_96->setSpacing(3);
        horizontalLayout_96->setObjectName(QString::fromUtf8("horizontalLayout_96"));
        label_59 = new QLabel(widget_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setFont(font2);
        label_59->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_96->addWidget(label_59);

        SubTaskType = new QLineEdit(widget_2);
        SubTaskType->setObjectName(QString::fromUtf8("SubTaskType"));
        sizePolicy.setHeightForWidth(SubTaskType->sizePolicy().hasHeightForWidth());
        SubTaskType->setSizePolicy(sizePolicy);
        SubTaskType->setMinimumSize(QSize(120, 0));
        SubTaskType->setFont(font3);
        SubTaskType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_96->addWidget(SubTaskType);

        horizontalLayout_96->setStretch(0, 1);
        horizontalLayout_96->setStretch(1, 10);

        horizontalLayout_4->addLayout(horizontalLayout_96);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_93 = new QHBoxLayout();
        horizontalLayout_93->setSpacing(3);
        horizontalLayout_93->setObjectName(QString::fromUtf8("horizontalLayout_93"));
        label_56 = new QLabel(widget_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setMinimumSize(QSize(0, 35));
        label_56->setMaximumSize(QSize(16777215, 40));
        label_56->setFont(font2);
        label_56->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_93->addWidget(label_56);

        Point_S = new QLineEdit(widget_2);
        Point_S->setObjectName(QString::fromUtf8("Point_S"));
        sizePolicy.setHeightForWidth(Point_S->sizePolicy().hasHeightForWidth());
        Point_S->setSizePolicy(sizePolicy);
        Point_S->setMinimumSize(QSize(120, 0));
        Point_S->setFont(font3);
        Point_S->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_93->addWidget(Point_S);

        horizontalLayout_93->setStretch(0, 1);
        horizontalLayout_93->setStretch(1, 10);

        horizontalLayout_7->addLayout(horizontalLayout_93);

        horizontalLayout_94 = new QHBoxLayout();
        horizontalLayout_94->setSpacing(3);
        horizontalLayout_94->setObjectName(QString::fromUtf8("horizontalLayout_94"));
        label_57 = new QLabel(widget_2);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setFont(font2);
        label_57->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(170, 255, 127);\n"
"background-color: rgb(151, 170, 166);"));

        horizontalLayout_94->addWidget(label_57);

        Point_E = new QLineEdit(widget_2);
        Point_E->setObjectName(QString::fromUtf8("Point_E"));
        sizePolicy.setHeightForWidth(Point_E->sizePolicy().hasHeightForWidth());
        Point_E->setSizePolicy(sizePolicy);
        Point_E->setMinimumSize(QSize(120, 0));
        Point_E->setFont(font3);
        Point_E->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_94->addWidget(Point_E);

        horizontalLayout_94->setStretch(0, 1);
        horizontalLayout_94->setStretch(1, 10);

        horizontalLayout_7->addLayout(horizontalLayout_94);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_35);

        add_rule_2 = new QPushButton(widget_2);
        add_rule_2->setObjectName(QString::fromUtf8("add_rule_2"));
        sizePolicy1.setHeightForWidth(add_rule_2->sizePolicy().hasHeightForWidth());
        add_rule_2->setSizePolicy(sizePolicy1);
        add_rule_2->setMinimumSize(QSize(120, 40));
        add_rule_2->setMaximumSize(QSize(16777215, 45));
        add_rule_2->setFont(font2);
        add_rule_2->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_5->addWidget(add_rule_2);

        delete_rule_2 = new QPushButton(widget_2);
        delete_rule_2->setObjectName(QString::fromUtf8("delete_rule_2"));
        sizePolicy1.setHeightForWidth(delete_rule_2->sizePolicy().hasHeightForWidth());
        delete_rule_2->setSizePolicy(sizePolicy1);
        delete_rule_2->setMinimumSize(QSize(120, 0));
        delete_rule_2->setMaximumSize(QSize(16777215, 45));
        delete_rule_2->setFont(font2);
        delete_rule_2->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_5->addWidget(delete_rule_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(verticalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);

        tableWidget_rule = new QTableWidget(widget_2);
        if (tableWidget_rule->columnCount() < 7)
            tableWidget_rule->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(5, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_rule->setHorizontalHeaderItem(6, __qtablewidgetitem38);
        if (tableWidget_rule->rowCount() < 5)
            tableWidget_rule->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_rule->setVerticalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_rule->setVerticalHeaderItem(1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_rule->setVerticalHeaderItem(2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_rule->setVerticalHeaderItem(3, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_rule->setVerticalHeaderItem(4, __qtablewidgetitem43);
        tableWidget_rule->setObjectName(QString::fromUtf8("tableWidget_rule"));
        tableWidget_rule->setFont(font3);
        tableWidget_rule->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout_6->addWidget(tableWidget_rule);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(15);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer);

        update_rule = new QPushButton(widget_2);
        update_rule->setObjectName(QString::fromUtf8("update_rule"));
        sizePolicy1.setHeightForWidth(update_rule->sizePolicy().hasHeightForWidth());
        update_rule->setSizePolicy(sizePolicy1);
        update_rule->setMinimumSize(QSize(180, 40));
        update_rule->setMaximumSize(QSize(16777215, 45));
        update_rule->setFont(font2);
        update_rule->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_19->addWidget(update_rule);

        horizontalLayout_19->setStretch(0, 20);
        horizontalLayout_19->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_19);

        verticalLayout_6->setStretch(0, 3);
        verticalLayout_6->setStretch(1, 10);
        verticalLayout_6->setStretch(2, 1);

        gridLayout_8->addLayout(verticalLayout_6, 0, 0, 1, 1);


        verticalLayout_13->addWidget(widget_2);

        verticalLayout_13->setStretch(0, 1);
        verticalLayout_13->setStretch(1, 3);

        gridLayout_4->addLayout(verticalLayout_13, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(system_agv);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(system_agv);
    } // setupUi

    void retranslateUi(QWidget *system_agv)
    {
        system_agv->setWindowTitle(QApplication::translate("system_agv", "Form", nullptr));
        label_23->setText(QApplication::translate("system_agv", " AGV\345\217\202\346\225\260\351\205\215\347\275\256\347\225\214\351\235\242   ", nullptr));
        label_69->setText(QApplication::translate("system_agv", "AGVIP:", nullptr));
        AGVIP->setText(QString());
        AGVIP->setPlaceholderText(QString());
        query_agvip->setText(QApplication::translate("system_agv", "\346\237\245\350\257\242", nullptr));
        add_agvip->setText(QApplication::translate("system_agv", "\346\267\273\345\212\240", nullptr));
        delete_agvip->setText(QApplication::translate("system_agv", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_agv->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("system_agv", "\345\260\217\350\275\246Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_agv->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("system_agv", "AGVIP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_agv->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("system_agv", "enable", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_agv->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("system_agv", "AGV\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_agv->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("system_agv", "\346\245\274\345\261\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_agv->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("system_agv", "\345\276\205\346\234\272\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_agv->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("system_agv", "\345\205\205\347\224\265\346\241\251IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_agv->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("system_agv", "\345\205\205\347\224\265\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_agv->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("system_agv", "\345\205\205\347\224\265\350\260\203\346\225\264\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_agv->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("system_agv", "\345\205\205\347\224\265\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_agv->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_agv->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_agv->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_agv->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_agv->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        update_agvip->setText(QApplication::translate("system_agv", "\346\217\220\344\272\244\346\233\264\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("system_agv", " AGV\345\217\202\346\225\260 ", nullptr));
        label_18->setText(QApplication::translate("system_agv", "   \350\267\257\347\272\277\344\277\241\346\201\257\347\274\226\350\276\221\347\225\214\351\235\242   ", nullptr));
        label_63->setText(QApplication::translate("system_agv", "\345\275\223\345\211\215\350\267\257\347\272\277:", nullptr));
        currentLine->setText(QApplication::translate("system_agv", "2F-L1", nullptr));
        currentLine->setPlaceholderText(QApplication::translate("system_agv", "Line", nullptr));
        lineType->setItemText(0, QApplication::translate("system_agv", "\346\255\243\345\220\221", nullptr));
        lineType->setItemText(1, QApplication::translate("system_agv", "\345\217\215\345\220\221", nullptr));

        query_LineInfo->setText(QApplication::translate("system_agv", "\346\237\245\350\257\242", nullptr));
        add_LineInfo->setText(QApplication::translate("system_agv", "\346\267\273\345\212\240", nullptr));
        delete_LineInfo->setText(QApplication::translate("system_agv", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_Line->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_Line->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("system_agv", "\346\211\247\350\241\214\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_Line->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("system_agv", "\350\265\267\345\247\213\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_Line->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QApplication::translate("system_agv", "\344\270\213\344\270\200\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_Line->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QApplication::translate("system_agv", "\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_Line->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QApplication::translate("system_agv", "\351\200\237\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_Line->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QApplication::translate("system_agv", "\346\277\200\345\205\211\346\226\271\346\241\210(\345\215\207)", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_Line->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QApplication::translate("system_agv", "\346\277\200\345\205\211\346\226\271\346\241\210(\351\231\215)", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_Line->horizontalHeaderItem(8);
        ___qtablewidgetitem23->setText(QApplication::translate("system_agv", "\345\247\277\346\200\201\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_Line->horizontalHeaderItem(9);
        ___qtablewidgetitem24->setText(QApplication::translate("system_agv", "\347\247\273\345\212\250\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_Line->horizontalHeaderItem(10);
        ___qtablewidgetitem25->setText(QApplication::translate("system_agv", "\350\275\254\347\233\230\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_Line->horizontalHeaderItem(11);
        ___qtablewidgetitem26->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\346\226\271\345\220\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_Line->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_Line->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_Line->verticalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_Line->verticalHeaderItem(3);
        ___qtablewidgetitem30->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_Line->verticalHeaderItem(4);
        ___qtablewidgetitem31->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        Alter_LineInfo->setText(QApplication::translate("system_agv", " \350\267\257\347\272\277\345\257\274\345\205\245 ", nullptr));
        update_LineInfo->setText(QApplication::translate("system_agv", "\346\217\220\344\272\244\346\233\264\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("system_agv", "\350\267\257\347\272\277\344\277\241\346\201\257\347\274\226\350\276\221", nullptr));
        label_19->setText(QApplication::translate("system_agv", "   \350\267\257\347\272\277\350\247\204\345\210\231\347\256\241\347\220\206\347\225\214\351\235\242   ", nullptr));
        query_rule->setText(QApplication::translate("system_agv", "\346\237\245\350\257\242", nullptr));
        label_54->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\347\274\226\345\217\267:", nullptr));
        keyId->setText(QApplication::translate("system_agv", "2F-Line1&2F-Line2", nullptr));
        keyId->setPlaceholderText(QApplication::translate("system_agv", "Line1-Line2", nullptr));
        add_rule->setText(QApplication::translate("system_agv", "\345\210\233\345\273\272", nullptr));
        delete_rule->setText(QApplication::translate("system_agv", "\345\210\240\351\231\244", nullptr));
        label_51->setText(QApplication::translate("system_agv", "\350\265\267\347\202\271\350\267\257\347\272\277\345\220\215\347\247\260:", nullptr));
        assistRoute_S->setText(QString());
        assistRoute_S->setPlaceholderText(QApplication::translate("system_agv", "Route_S", nullptr));
        label_49->setText(QApplication::translate("system_agv", "\350\265\267\347\202\271\350\267\257\347\272\277\347\246\273\345\274\200\347\202\271:", nullptr));
        assistPoint_S->setText(QString());
        assistPoint_S->setPlaceholderText(QApplication::translate("system_agv", "Point_S", nullptr));
        label_53->setText(QApplication::translate("system_agv", "\347\273\210\347\202\271\350\267\257\347\272\277\345\220\215\347\247\260:", nullptr));
        assistRoute_E->setText(QString());
        assistRoute_E->setPlaceholderText(QApplication::translate("system_agv", "Route_E", nullptr));
        label_50->setText(QApplication::translate("system_agv", "\347\273\210\347\202\271\350\267\257\347\272\277\350\277\233\345\205\245\347\202\271:", nullptr));
        assistPoint_E->setText(QString());
        assistPoint_E->setPlaceholderText(QApplication::translate("system_agv", "Point_E", nullptr));
        label_21->setText(QApplication::translate("system_agv", "   \351\200\224\347\273\217\347\232\204\345\255\220\350\267\257\347\272\277\344\277\241\346\201\257   ", nullptr));
        label_58->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\345\220\215\347\247\260:", nullptr));
        RouteName->setText(QString());
        RouteName->setPlaceholderText(QApplication::translate("system_agv", "RouteName", nullptr));
        label_59->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\346\226\271\345\220\221:", nullptr));
        SubTaskType->setText(QString());
        SubTaskType->setPlaceholderText(QApplication::translate("system_agv", "SubTaskType", nullptr));
        label_56->setText(QApplication::translate("system_agv", "\350\265\267\345\247\213\347\202\271:", nullptr));
        Point_S->setText(QString());
        Point_S->setPlaceholderText(QApplication::translate("system_agv", "Point_S", nullptr));
        label_57->setText(QApplication::translate("system_agv", "\347\246\273\345\274\200\347\202\271:", nullptr));
        Point_E->setText(QString());
        Point_E->setPlaceholderText(QApplication::translate("system_agv", "Point_E", nullptr));
        add_rule_2->setText(QApplication::translate("system_agv", "\346\267\273\345\212\240", nullptr));
        delete_rule_2->setText(QApplication::translate("system_agv", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_rule->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("system_agv", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_rule->horizontalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_rule->horizontalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("system_agv", "\346\211\247\350\241\214\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_rule->horizontalHeaderItem(3);
        ___qtablewidgetitem35->setText(QApplication::translate("system_agv", "\350\265\267\345\247\213\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_rule->horizontalHeaderItem(4);
        ___qtablewidgetitem36->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_rule->horizontalHeaderItem(5);
        ___qtablewidgetitem37->setText(QApplication::translate("system_agv", "\347\246\273\345\274\200\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_rule->horizontalHeaderItem(6);
        ___qtablewidgetitem38->setText(QApplication::translate("system_agv", "\350\267\257\347\272\277\346\226\271\345\220\221", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_rule->verticalHeaderItem(0);
        ___qtablewidgetitem39->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_rule->verticalHeaderItem(1);
        ___qtablewidgetitem40->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_rule->verticalHeaderItem(2);
        ___qtablewidgetitem41->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_rule->verticalHeaderItem(3);
        ___qtablewidgetitem42->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_rule->verticalHeaderItem(4);
        ___qtablewidgetitem43->setText(QApplication::translate("system_agv", "\346\226\260\345\273\272\350\241\214", nullptr));
        update_rule->setText(QApplication::translate("system_agv", "\346\217\220\344\272\244\346\233\264\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("system_agv", " \350\267\257\347\272\277\350\247\204\345\210\231\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class system_agv: public Ui_system_agv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_AGV_H
