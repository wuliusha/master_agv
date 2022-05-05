/********************************************************************************
** Form generated from reading UI file 'managerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERINFO_H
#define UI_MANAGERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerInfo
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *logInfo_Button;
    QToolButton *Binchage_Button;
    QToolButton *Network_Button;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *qdebug_log;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *stop_Button;
    QPushButton *clear_Button;
    QWidget *page_5;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QStackedWidget *stackedWidget_3;
    QWidget *page_8;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_36;
    QTextEdit *GetMaterial2;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_38;
    QLineEdit *GetorderId;
    QWidget *page_9;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_42;
    QLineEdit *getLabelNoType;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_46;
    QLineEdit *get_Todesc;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_37;
    QLineEdit *GetoperaterIndex;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_47;
    QComboBox *taskTypeBox;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_43;
    QComboBox *taskStatusBox;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_44;
    QDateEdit *Selete_DateEdit;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_45;
    QDateEdit *Selete_DateEdit_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *Qury_Button;
    QPushButton *Cancel_Button;
    QTableWidget *tableWidget;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureLead_Button;
    QPushButton *Cancel_Button_2;

    void setupUi(QWidget *ManagerInfo)
    {
        if (ManagerInfo->objectName().isEmpty())
            ManagerInfo->setObjectName(QString::fromUtf8("ManagerInfo"));
        ManagerInfo->resize(1458, 686);
        ManagerInfo->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(ManagerInfo);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(ManagerInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(30);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        logInfo_Button = new QToolButton(widget_2);
        logInfo_Button->setObjectName(QString::fromUtf8("logInfo_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logInfo_Button->sizePolicy().hasHeightForWidth());
        logInfo_Button->setSizePolicy(sizePolicy);
        logInfo_Button->setMaximumSize(QSize(500, 300));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        logInfo_Button->setFont(font);
        logInfo_Button->setStyleSheet(QString::fromUtf8("color:#ffffff;"));
        logInfo_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(logInfo_Button);

        Binchage_Button = new QToolButton(widget_2);
        Binchage_Button->setObjectName(QString::fromUtf8("Binchage_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Binchage_Button->sizePolicy().hasHeightForWidth());
        Binchage_Button->setSizePolicy(sizePolicy1);
        Binchage_Button->setMaximumSize(QSize(500, 300));
        Binchage_Button->setFont(font);
        Binchage_Button->setStyleSheet(QString::fromUtf8(""));
        Binchage_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Binchage_Button->setAutoRaise(false);

        horizontalLayout_8->addWidget(Binchage_Button);

        Network_Button = new QToolButton(widget_2);
        Network_Button->setObjectName(QString::fromUtf8("Network_Button"));
        sizePolicy.setHeightForWidth(Network_Button->sizePolicy().hasHeightForWidth());
        Network_Button->setSizePolicy(sizePolicy);
        Network_Button->setMaximumSize(QSize(500, 300));

        horizontalLayout_8->addWidget(Network_Button);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);

        horizontalLayout->addLayout(horizontalLayout_8);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);

        stackedWidget = new QStackedWidget(ManagerInfo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_9 = new QGridLayout(page_3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        qdebug_log = new QTextEdit(page_3);
        qdebug_log->setObjectName(QString::fromUtf8("qdebug_log"));
        qdebug_log->setMaximumSize(QSize(16777215, 16778));
        QFont font1;
        font1.setPointSize(12);
        qdebug_log->setFont(font1);
        qdebug_log->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_2->addWidget(qdebug_log);

        widget_4 = new QWidget(page_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 119, 123);"));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stop_Button = new QPushButton(widget_4);
        stop_Button->setObjectName(QString::fromUtf8("stop_Button"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stop_Button->sizePolicy().hasHeightForWidth());
        stop_Button->setSizePolicy(sizePolicy2);
        stop_Button->setMinimumSize(QSize(100, 0));
        stop_Button->setMaximumSize(QSize(120, 40));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        stop_Button->setFont(font2);
        stop_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; "));

        horizontalLayout_3->addWidget(stop_Button);

        clear_Button = new QPushButton(widget_4);
        clear_Button->setObjectName(QString::fromUtf8("clear_Button"));
        sizePolicy2.setHeightForWidth(clear_Button->sizePolicy().hasHeightForWidth());
        clear_Button->setSizePolicy(sizePolicy2);
        clear_Button->setMinimumSize(QSize(100, 0));
        clear_Button->setMaximumSize(QSize(120, 40));
        clear_Button->setFont(font2);
        clear_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; "));

        horizontalLayout_3->addWidget(clear_Button);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4->setStretch(0, 10);
        horizontalLayout_4->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_4);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 1);

        gridLayout_9->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_8 = new QGridLayout(page_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(page_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 80));
        widget_3->setMaximumSize(QSize(16777215, 100));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(134, 120, 146);\n"
"background-color: rgb(111, 109, 133);\n"
""));
        gridLayout_5 = new QGridLayout(widget_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(11, 0, 11, -1);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(20);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        stackedWidget_3 = new QStackedWidget(widget_3);
        stackedWidget_3->setObjectName(QString::fromUtf8("stackedWidget_3"));
        stackedWidget_3->setMinimumSize(QSize(0, 0));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        gridLayout_7 = new QGridLayout(page_8);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(15);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(1);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_36 = new QLabel(page_8);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        QFont font3;
        font3.setPointSize(16);
        label_36->setFont(font3);
        label_36->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_36->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_36);

        GetMaterial2 = new QTextEdit(page_8);
        GetMaterial2->setObjectName(QString::fromUtf8("GetMaterial2"));
        GetMaterial2->setMaximumSize(QSize(16777215, 35));
        GetMaterial2->setFont(font3);
        GetMaterial2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_11->addWidget(GetMaterial2);

        verticalLayout_11->setStretch(0, 1);

        horizontalLayout_13->addLayout(verticalLayout_11);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(1);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        label_38 = new QLabel(page_8);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font3);
        label_38->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_38->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_38);

        GetorderId = new QLineEdit(page_8);
        GetorderId->setObjectName(QString::fromUtf8("GetorderId"));
        sizePolicy2.setHeightForWidth(GetorderId->sizePolicy().hasHeightForWidth());
        GetorderId->setSizePolicy(sizePolicy2);
        GetorderId->setMaximumSize(QSize(16777215, 33));
        GetorderId->setFont(font3);
        GetorderId->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_16->addWidget(GetorderId);

        verticalLayout_16->setStretch(0, 1);
        verticalLayout_16->setStretch(1, 1);

        horizontalLayout_13->addLayout(verticalLayout_16);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);

        gridLayout_7->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        stackedWidget_3->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        gridLayout_4 = new QGridLayout(page_9);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_42 = new QLabel(page_9);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font3);
        label_42->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_42->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_42);

        getLabelNoType = new QLineEdit(page_9);
        getLabelNoType->setObjectName(QString::fromUtf8("getLabelNoType"));
        sizePolicy2.setHeightForWidth(getLabelNoType->sizePolicy().hasHeightForWidth());
        getLabelNoType->setSizePolicy(sizePolicy2);
        getLabelNoType->setMinimumSize(QSize(60, 0));
        getLabelNoType->setMaximumSize(QSize(300, 33));
        getLabelNoType->setFont(font3);
        getLabelNoType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(getLabelNoType);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_46 = new QLabel(page_9);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font3);
        label_46->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_46->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_46);

        get_Todesc = new QLineEdit(page_9);
        get_Todesc->setObjectName(QString::fromUtf8("get_Todesc"));
        sizePolicy2.setHeightForWidth(get_Todesc->sizePolicy().hasHeightForWidth());
        get_Todesc->setSizePolicy(sizePolicy2);
        get_Todesc->setMinimumSize(QSize(60, 0));
        get_Todesc->setMaximumSize(QSize(300, 33));
        get_Todesc->setFont(font3);
        get_Todesc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_17->addWidget(get_Todesc);


        horizontalLayout_5->addLayout(verticalLayout_17);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_37 = new QLabel(page_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font3);
        label_37->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_37->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_37);

        GetoperaterIndex = new QLineEdit(page_9);
        GetoperaterIndex->setObjectName(QString::fromUtf8("GetoperaterIndex"));
        sizePolicy2.setHeightForWidth(GetoperaterIndex->sizePolicy().hasHeightForWidth());
        GetoperaterIndex->setSizePolicy(sizePolicy2);
        GetoperaterIndex->setMaximumSize(QSize(16777215, 33));
        GetoperaterIndex->setFont(font3);
        GetoperaterIndex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_12->addWidget(GetoperaterIndex);

        verticalLayout_12->setStretch(0, 1);
        verticalLayout_12->setStretch(1, 1);

        horizontalLayout_5->addLayout(verticalLayout_12);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        gridLayout_4->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        stackedWidget_3->addWidget(page_9);

        horizontalLayout_15->addWidget(stackedWidget_3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(15);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_47 = new QLabel(widget_3);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font3);
        label_47->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_47->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_47);

        taskTypeBox = new QComboBox(widget_3);
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->setObjectName(QString::fromUtf8("taskTypeBox"));
        sizePolicy2.setHeightForWidth(taskTypeBox->sizePolicy().hasHeightForWidth());
        taskTypeBox->setSizePolicy(sizePolicy2);
        taskTypeBox->setMinimumSize(QSize(0, 35));
        taskTypeBox->setFont(font2);
        taskTypeBox->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(148, 214, 218);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        verticalLayout_18->addWidget(taskTypeBox);


        horizontalLayout_18->addLayout(verticalLayout_18);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_43 = new QLabel(widget_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font3);
        label_43->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_43->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_43);

        taskStatusBox = new QComboBox(widget_3);
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->setObjectName(QString::fromUtf8("taskStatusBox"));
        sizePolicy2.setHeightForWidth(taskStatusBox->sizePolicy().hasHeightForWidth());
        taskStatusBox->setSizePolicy(sizePolicy2);
        taskStatusBox->setMinimumSize(QSize(0, 35));
        taskStatusBox->setFont(font2);
        taskStatusBox->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(148, 214, 218);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        verticalLayout_13->addWidget(taskStatusBox);


        horizontalLayout_18->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_44 = new QLabel(widget_3);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font3);
        label_44->setLayoutDirection(Qt::LeftToRight);
        label_44->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_44->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_44);

        Selete_DateEdit = new QDateEdit(widget_3);
        Selete_DateEdit->setObjectName(QString::fromUtf8("Selete_DateEdit"));
        sizePolicy2.setHeightForWidth(Selete_DateEdit->sizePolicy().hasHeightForWidth());
        Selete_DateEdit->setSizePolicy(sizePolicy2);
        Selete_DateEdit->setMaximumSize(QSize(16777215, 40));
        Selete_DateEdit->setFont(font3);
        Selete_DateEdit->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(0, 166, 172);\n"
"QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: rgb(100,100,100);\n"
"spacing: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"width: 50px;                   //\345\256\275\345\272\246\357\274\210\351\253\230\345\272\246\351\232\217\346\216\247\344\273\266\357\274\211\n"
"border-left-width: 1px;   //\345\212\240\345\267\246\350\276\271\346\241\206\347\272\277\357\274\210\345\217\257\344\273\245\344\270\215\350\246\201\357\274\214\344\270\213\345\220\214\357\274\211\n"
"border-left-style: solid;  //\345\267\246\350\276\271\346\241\206\347\272\277\347\261\273\345\236\213\n"
"border-left-color: gray;  //\345\267\246\350\276\271\346\241\206\347\272\277\351\242\234\350\211\262\n"
"}\n"
"\n"
"\n"
""));
        Selete_DateEdit->setProperty("showGroupSeparator", QVariant(true));
        Selete_DateEdit->setDateTime(QDateTime(QDate(2020, 3, 1), QTime(0, 0, 0)));
        Selete_DateEdit->setCalendarPopup(true);

        verticalLayout_14->addWidget(Selete_DateEdit);


        horizontalLayout_18->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_45 = new QLabel(widget_3);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font3);
        label_45->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_45->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_45);

        Selete_DateEdit_2 = new QDateEdit(widget_3);
        Selete_DateEdit_2->setObjectName(QString::fromUtf8("Selete_DateEdit_2"));
        sizePolicy2.setHeightForWidth(Selete_DateEdit_2->sizePolicy().hasHeightForWidth());
        Selete_DateEdit_2->setSizePolicy(sizePolicy2);
        Selete_DateEdit_2->setMaximumSize(QSize(16777215, 40));
        Selete_DateEdit_2->setFont(font3);
        Selete_DateEdit_2->setStyleSheet(QString::fromUtf8("color:#FEFEFE;\n"
"background-color: rgb(0, 166, 172);\n"
"QDateEdit\n"
"{\n"
"font-size: 16px;\n"
"background-color: white;\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"border-color: rgb(100,100,100);\n"
"spacing: 5px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"width: 50px;                   //\345\256\275\345\272\246\357\274\210\351\253\230\345\272\246\351\232\217\346\216\247\344\273\266\357\274\211\n"
"border-left-width: 1px;   //\345\212\240\345\267\246\350\276\271\346\241\206\347\272\277\357\274\210\345\217\257\344\273\245\344\270\215\350\246\201\357\274\214\344\270\213\345\220\214\357\274\211\n"
"border-left-style: solid;  //\345\267\246\350\276\271\346\241\206\347\272\277\347\261\273\345\236\213\n"
"border-left-color: gray;  //\345\267\246\350\276\271\346\241\206\347\272\277\351\242\234\350\211\262\n"
"}\n"
"\n"
"\n"
""));
        Selete_DateEdit_2->setDateTime(QDateTime(QDate(2020, 3, 1), QTime(23, 59, 0)));
        Selete_DateEdit_2->setCalendarPopup(true);

        verticalLayout_15->addWidget(Selete_DateEdit_2);


        horizontalLayout_18->addLayout(verticalLayout_15);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 1);
        horizontalLayout_18->setStretch(3, 1);

        horizontalLayout_15->addLayout(horizontalLayout_18);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_19->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(20);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        Qury_Button = new QPushButton(widget_3);
        Qury_Button->setObjectName(QString::fromUtf8("Qury_Button"));
        sizePolicy2.setHeightForWidth(Qury_Button->sizePolicy().hasHeightForWidth());
        Qury_Button->setSizePolicy(sizePolicy2);
        Qury_Button->setMinimumSize(QSize(100, 0));
        Qury_Button->setMaximumSize(QSize(16777215, 40));
        Qury_Button->setFont(font2);
        Qury_Button->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset\n"
""));

        horizontalLayout_14->addWidget(Qury_Button);

        Cancel_Button = new QPushButton(widget_3);
        Cancel_Button->setObjectName(QString::fromUtf8("Cancel_Button"));
        sizePolicy2.setHeightForWidth(Cancel_Button->sizePolicy().hasHeightForWidth());
        Cancel_Button->setSizePolicy(sizePolicy2);
        Cancel_Button->setMinimumSize(QSize(100, 0));
        Cancel_Button->setMaximumSize(QSize(16777215, 40));
        Cancel_Button->setFont(font2);
        Cancel_Button->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset"));

        horizontalLayout_14->addWidget(Cancel_Button);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_14);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_15->addLayout(verticalLayout_5);

        horizontalLayout_15->setStretch(0, 3);
        horizontalLayout_15->setStretch(1, 5);
        horizontalLayout_15->setStretch(2, 1);
        horizontalLayout_15->setStretch(3, 1);

        gridLayout_5->addLayout(horizontalLayout_15, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_3);

        tableWidget = new QTableWidget(page_5);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font4.setPointSize(12);
        tableWidget->setFont(font4);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        widget = new QWidget(page_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 119, 123);"));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(30);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        sureLead_Button = new QPushButton(widget);
        sureLead_Button->setObjectName(QString::fromUtf8("sureLead_Button"));
        sureLead_Button->setMinimumSize(QSize(160, 45));
        sureLead_Button->setMaximumSize(QSize(160, 45));
        sureLead_Button->setFont(font2);
        sureLead_Button->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset"));

        horizontalLayout_9->addWidget(sureLead_Button);

        Cancel_Button_2 = new QPushButton(widget);
        Cancel_Button_2->setObjectName(QString::fromUtf8("Cancel_Button_2"));
        Cancel_Button_2->setMinimumSize(QSize(160, 45));
        Cancel_Button_2->setMaximumSize(QSize(160, 45));
        Cancel_Button_2->setFont(font2);
        Cancel_Button_2->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset"));

        horizontalLayout_9->addWidget(Cancel_Button_2);


        gridLayout_6->addLayout(horizontalLayout_9, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        gridLayout_8->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page_5);

        verticalLayout_3->addWidget(stackedWidget);

        verticalLayout_3->setStretch(0, 1);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(ManagerInfo);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManagerInfo);
    } // setupUi

    void retranslateUi(QWidget *ManagerInfo)
    {
        ManagerInfo->setWindowTitle(QApplication::translate("ManagerInfo", "Form", nullptr));
        logInfo_Button->setText(QString());
        Binchage_Button->setText(QString());
        Network_Button->setText(QString());
        stop_Button->setText(QApplication::translate("ManagerInfo", "\346\232\202\345\201\234", nullptr));
        clear_Button->setText(QApplication::translate("ManagerInfo", "\346\270\205\351\231\244", nullptr));
        label_36->setText(QApplication::translate("ManagerInfo", "\344\272\247\345\223\201\347\274\226\347\240\201", nullptr));
        label_38->setText(QApplication::translate("ManagerInfo", "\347\274\226\347\240\201\350\203\266\347\256\261", nullptr));
        label_42->setText(QApplication::translate("ManagerInfo", "\350\264\264\347\272\270\347\261\273\345\236\213", nullptr));
        label_46->setText(QApplication::translate("ManagerInfo", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label_37->setText(QApplication::translate("ManagerInfo", "\346\213\243\351\200\211\345\217\260", nullptr));
        label_47->setText(QApplication::translate("ManagerInfo", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        taskTypeBox->setItemText(0, QApplication::translate("ManagerInfo", "\345\205\250\351\203\250\347\261\273\345\236\213", nullptr));
        taskTypeBox->setItemText(1, QApplication::translate("ManagerInfo", "\345\205\245\345\272\223\344\273\273\345\212\241", nullptr));
        taskTypeBox->setItemText(2, QApplication::translate("ManagerInfo", "\345\207\272\345\272\223\344\273\273\345\212\241", nullptr));
        taskTypeBox->setItemText(3, QApplication::translate("ManagerInfo", "\347\247\273\345\272\223\344\273\273\345\212\241", nullptr));

        label_43->setText(QApplication::translate("ManagerInfo", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        taskStatusBox->setItemText(0, QApplication::translate("ManagerInfo", "\345\205\250\351\203\250\347\212\266\346\200\201", nullptr));
        taskStatusBox->setItemText(1, QApplication::translate("ManagerInfo", "\345\267\262\345\256\214\346\210\220\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(2, QApplication::translate("ManagerInfo", "\346\224\276\347\256\261\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(3, QApplication::translate("ManagerInfo", "\345\217\226\347\256\261\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(4, QApplication::translate("ManagerInfo", "\350\277\220\350\276\223\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(5, QApplication::translate("ManagerInfo", "\345\276\205\345\210\206\351\205\215\344\273\273\345\212\241", nullptr));

        label_44->setText(QApplication::translate("ManagerInfo", "\350\265\267\345\247\213\346\227\266\351\227\264", nullptr));
        label_45->setText(QApplication::translate("ManagerInfo", "\346\210\252\350\207\263\346\227\266\351\227\264", nullptr));
        label_2->setText(QString());
        Qury_Button->setText(QApplication::translate("ManagerInfo", "\346\237\245\350\257\242", nullptr));
        Cancel_Button->setText(QApplication::translate("ManagerInfo", "\345\217\226\346\266\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ManagerInfo", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ManagerInfo", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ManagerInfo", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ManagerInfo", "\344\272\247\345\223\201\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ManagerInfo", "PCB\351\233\206\345\220\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ManagerInfo", "\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ManagerInfo", "\350\265\267\345\247\213\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ManagerInfo", "\347\233\256\346\240\207\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ManagerInfo", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ManagerInfo", "\346\230\257\345\220\246\346\200\245\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("ManagerInfo", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("ManagerInfo", "\345\256\214\346\210\220\346\227\266\351\227\264", nullptr));
        sureLead_Button->setText(QApplication::translate("ManagerInfo", "\347\241\256\345\256\232\345\257\274\345\207\272", nullptr));
        Cancel_Button_2->setText(QApplication::translate("ManagerInfo", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerInfo: public Ui_ManagerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERINFO_H
