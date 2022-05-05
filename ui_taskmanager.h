/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskManager
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
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
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
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
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_table;
    QLineEdit *lineEdit_count;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *taskStatusBox_ESS;
    QComboBox *taskStatusBox_AGV;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_Edite;
    QPushButton *Delete_Button;
    QWidget *page_2;

    void setupUi(QWidget *taskManager)
    {
        if (taskManager->objectName().isEmpty())
            taskManager->setObjectName(QString::fromUtf8("taskManager"));
        taskManager->resize(1682, 740);
        taskManager->setMinimumSize(QSize(0, 120));
        taskManager->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(taskManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(taskManager);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 80));
        widget_2->setMaximumSize(QSize(16777215, 100));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(134, 120, 146);\n"
"background-color: rgb(111, 109, 133);\n"
"background-color: rgb(148, 214, 218);\n"
""));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(10, 0, 10, 10);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(20);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        stackedWidget_3 = new QStackedWidget(widget_2);
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
        QFont font;
        font.setPointSize(16);
        label_36->setFont(font);
        label_36->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_36->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_36);

        GetMaterial2 = new QTextEdit(page_8);
        GetMaterial2->setObjectName(QString::fromUtf8("GetMaterial2"));
        GetMaterial2->setMaximumSize(QSize(16777215, 35));
        GetMaterial2->setFont(font);
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
        label_38->setFont(font);
        label_38->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_38->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_38);

        GetorderId = new QLineEdit(page_8);
        GetorderId->setObjectName(QString::fromUtf8("GetorderId"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GetorderId->sizePolicy().hasHeightForWidth());
        GetorderId->setSizePolicy(sizePolicy);
        GetorderId->setMaximumSize(QSize(16777215, 33));
        GetorderId->setFont(font);
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
        gridLayout_2 = new QGridLayout(page_9);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_42 = new QLabel(page_9);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font);
        label_42->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_42->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_42);

        getLabelNoType = new QLineEdit(page_9);
        getLabelNoType->setObjectName(QString::fromUtf8("getLabelNoType"));
        sizePolicy.setHeightForWidth(getLabelNoType->sizePolicy().hasHeightForWidth());
        getLabelNoType->setSizePolicy(sizePolicy);
        getLabelNoType->setMinimumSize(QSize(60, 0));
        getLabelNoType->setMaximumSize(QSize(300, 33));
        getLabelNoType->setFont(font);
        getLabelNoType->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_9->addWidget(getLabelNoType);


        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_46 = new QLabel(page_9);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font);
        label_46->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_46->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_46);

        get_Todesc = new QLineEdit(page_9);
        get_Todesc->setObjectName(QString::fromUtf8("get_Todesc"));
        sizePolicy.setHeightForWidth(get_Todesc->sizePolicy().hasHeightForWidth());
        get_Todesc->setSizePolicy(sizePolicy);
        get_Todesc->setMinimumSize(QSize(60, 0));
        get_Todesc->setMaximumSize(QSize(300, 33));
        get_Todesc->setFont(font);
        get_Todesc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_17->addWidget(get_Todesc);


        horizontalLayout_4->addLayout(verticalLayout_17);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_37 = new QLabel(page_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font);
        label_37->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_37->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_37);

        GetoperaterIndex = new QLineEdit(page_9);
        GetoperaterIndex->setObjectName(QString::fromUtf8("GetoperaterIndex"));
        sizePolicy.setHeightForWidth(GetoperaterIndex->sizePolicy().hasHeightForWidth());
        GetoperaterIndex->setSizePolicy(sizePolicy);
        GetoperaterIndex->setMaximumSize(QSize(16777215, 33));
        GetoperaterIndex->setFont(font);
        GetoperaterIndex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_12->addWidget(GetoperaterIndex);

        verticalLayout_12->setStretch(0, 1);
        verticalLayout_12->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_12);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        stackedWidget_3->addWidget(page_9);

        horizontalLayout_15->addWidget(stackedWidget_3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(30);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_47 = new QLabel(widget_2);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font);
        label_47->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_47->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_47);

        taskTypeBox = new QComboBox(widget_2);
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->addItem(QString());
        taskTypeBox->setObjectName(QString::fromUtf8("taskTypeBox"));
        sizePolicy.setHeightForWidth(taskTypeBox->sizePolicy().hasHeightForWidth());
        taskTypeBox->setSizePolicy(sizePolicy);
        taskTypeBox->setMinimumSize(QSize(0, 35));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        taskTypeBox->setFont(font1);
        taskTypeBox->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(148, 214, 218);\n"
"background-color: rgb(80, 138, 136);\n"
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
        label_43 = new QLabel(widget_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font);
        label_43->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_43->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_43);

        taskStatusBox = new QComboBox(widget_2);
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->addItem(QString());
        taskStatusBox->setObjectName(QString::fromUtf8("taskStatusBox"));
        sizePolicy.setHeightForWidth(taskStatusBox->sizePolicy().hasHeightForWidth());
        taskStatusBox->setSizePolicy(sizePolicy);
        taskStatusBox->setMinimumSize(QSize(0, 35));
        taskStatusBox->setFont(font1);
        taskStatusBox->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(148, 214, 218);\n"
"background-color: rgb(80, 138, 136);\n"
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
        label_44 = new QLabel(widget_2);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font);
        label_44->setLayoutDirection(Qt::LeftToRight);
        label_44->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_44->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_44);

        Selete_DateEdit = new QDateEdit(widget_2);
        Selete_DateEdit->setObjectName(QString::fromUtf8("Selete_DateEdit"));
        sizePolicy.setHeightForWidth(Selete_DateEdit->sizePolicy().hasHeightForWidth());
        Selete_DateEdit->setSizePolicy(sizePolicy);
        Selete_DateEdit->setMaximumSize(QSize(16777215, 40));
        Selete_DateEdit->setFont(font);
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
        label_45 = new QLabel(widget_2);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font);
        label_45->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        label_45->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_45);

        Selete_DateEdit_2 = new QDateEdit(widget_2);
        Selete_DateEdit_2->setObjectName(QString::fromUtf8("Selete_DateEdit_2"));
        sizePolicy.setHeightForWidth(Selete_DateEdit_2->sizePolicy().hasHeightForWidth());
        Selete_DateEdit_2->setSizePolicy(sizePolicy);
        Selete_DateEdit_2->setMaximumSize(QSize(16777215, 40));
        Selete_DateEdit_2->setFont(font);
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
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_19->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(15);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        Qury_Button = new QPushButton(widget_2);
        Qury_Button->setObjectName(QString::fromUtf8("Qury_Button"));
        sizePolicy.setHeightForWidth(Qury_Button->sizePolicy().hasHeightForWidth());
        Qury_Button->setSizePolicy(sizePolicy);
        Qury_Button->setMinimumSize(QSize(100, 0));
        Qury_Button->setMaximumSize(QSize(16777215, 40));
        Qury_Button->setFont(font1);
        Qury_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_14->addWidget(Qury_Button);

        Cancel_Button = new QPushButton(widget_2);
        Cancel_Button->setObjectName(QString::fromUtf8("Cancel_Button"));
        sizePolicy.setHeightForWidth(Cancel_Button->sizePolicy().hasHeightForWidth());
        Cancel_Button->setSizePolicy(sizePolicy);
        Cancel_Button->setMinimumSize(QSize(100, 0));
        Cancel_Button->setMaximumSize(QSize(16777215, 40));
        Cancel_Button->setFont(font1);
        Cancel_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"background-color: rgb(0, 166, 172);"));

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

        gridLayout_4->addLayout(horizontalLayout_15, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setPointSize(12);
        tableWidget->setFont(font2);
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

        verticalLayout_2->addWidget(tableWidget);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 120));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 119, 123);"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_table = new QLineEdit(widget);
        lineEdit_table->setObjectName(QString::fromUtf8("lineEdit_table"));
        sizePolicy.setHeightForWidth(lineEdit_table->sizePolicy().hasHeightForWidth());
        lineEdit_table->setSizePolicy(sizePolicy);
        lineEdit_table->setMinimumSize(QSize(0, 30));
        lineEdit_table->setMaximumSize(QSize(16777215, 35));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        lineEdit_table->setFont(font3);
        lineEdit_table->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        horizontalLayout_5->addWidget(lineEdit_table);

        lineEdit_count = new QLineEdit(widget);
        lineEdit_count->setObjectName(QString::fromUtf8("lineEdit_count"));
        sizePolicy.setHeightForWidth(lineEdit_count->sizePolicy().hasHeightForWidth());
        lineEdit_count->setSizePolicy(sizePolicy);
        lineEdit_count->setMinimumSize(QSize(100, 30));
        lineEdit_count->setMaximumSize(QSize(120, 40));
        lineEdit_count->setFont(font);
        lineEdit_count->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; "));

        horizontalLayout_5->addWidget(lineEdit_count);

        horizontalLayout_5->setStretch(0, 10);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        taskStatusBox_ESS = new QComboBox(widget);
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->setObjectName(QString::fromUtf8("taskStatusBox_ESS"));
        sizePolicy.setHeightForWidth(taskStatusBox_ESS->sizePolicy().hasHeightForWidth());
        taskStatusBox_ESS->setSizePolicy(sizePolicy);
        taskStatusBox_ESS->setMinimumSize(QSize(260, 35));
        taskStatusBox_ESS->setMaximumSize(QSize(16777215, 45));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        taskStatusBox_ESS->setFont(font4);
        taskStatusBox_ESS->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(124, 133, 119);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_3->addWidget(taskStatusBox_ESS);

        taskStatusBox_AGV = new QComboBox(widget);
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->setObjectName(QString::fromUtf8("taskStatusBox_AGV"));
        sizePolicy.setHeightForWidth(taskStatusBox_AGV->sizePolicy().hasHeightForWidth());
        taskStatusBox_AGV->setSizePolicy(sizePolicy);
        taskStatusBox_AGV->setMinimumSize(QSize(260, 35));
        taskStatusBox_AGV->setMaximumSize(QSize(16777215, 45));
        taskStatusBox_AGV->setFont(font4);
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

        horizontalLayout_3->addWidget(taskStatusBox_AGV);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);

        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        checkBox_Edite = new QCheckBox(widget);
        checkBox_Edite->setObjectName(QString::fromUtf8("checkBox_Edite"));
        sizePolicy.setHeightForWidth(checkBox_Edite->sizePolicy().hasHeightForWidth());
        checkBox_Edite->setSizePolicy(sizePolicy);
        checkBox_Edite->setMaximumSize(QSize(36, 36));
        checkBox_Edite->setFont(font);
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

        horizontalLayout_2->addWidget(checkBox_Edite);

        Delete_Button = new QPushButton(widget);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));
        sizePolicy.setHeightForWidth(Delete_Button->sizePolicy().hasHeightForWidth());
        Delete_Button->setSizePolicy(sizePolicy);
        Delete_Button->setMinimumSize(QSize(120, 45));
        Delete_Button->setMaximumSize(QSize(160, 45));
        Delete_Button->setFont(font1);
        Delete_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; "));

        horizontalLayout_2->addWidget(Delete_Button);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 5);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(taskManager);

        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(taskManager);
    } // setupUi

    void retranslateUi(QWidget *taskManager)
    {
        taskManager->setWindowTitle(QApplication::translate("taskManager", "Form", nullptr));
        label_36->setText(QApplication::translate("taskManager", "\344\272\247\345\223\201\347\274\226\347\240\201", nullptr));
        label_38->setText(QApplication::translate("taskManager", "\347\274\226\347\240\201\350\203\266\347\256\261", nullptr));
        label_42->setText(QApplication::translate("taskManager", "\350\264\264\347\272\270\347\261\273\345\236\213", nullptr));
        label_46->setText(QApplication::translate("taskManager", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label_37->setText(QApplication::translate("taskManager", "\346\213\243\351\200\211\345\217\260", nullptr));
        label_47->setText(QApplication::translate("taskManager", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        taskTypeBox->setItemText(0, QApplication::translate("taskManager", "\345\205\250\351\203\250\347\261\273\345\236\213", nullptr));
        taskTypeBox->setItemText(1, QApplication::translate("taskManager", "\345\205\245\345\272\223\344\273\273\345\212\241", nullptr));
        taskTypeBox->setItemText(2, QApplication::translate("taskManager", "\345\207\272\345\272\223\344\273\273\345\212\241", nullptr));
        taskTypeBox->setItemText(3, QApplication::translate("taskManager", "\347\247\273\345\272\223\344\273\273\345\212\241", nullptr));

        label_43->setText(QApplication::translate("taskManager", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        taskStatusBox->setItemText(0, QApplication::translate("taskManager", "\345\205\250\351\203\250\347\212\266\346\200\201", nullptr));
        taskStatusBox->setItemText(1, QApplication::translate("taskManager", "\345\267\262\345\256\214\346\210\220\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(2, QApplication::translate("taskManager", "\346\224\276\347\256\261\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(3, QApplication::translate("taskManager", "\345\217\226\347\256\261\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(4, QApplication::translate("taskManager", "\350\277\220\350\276\223\344\270\255\344\273\273\345\212\241", nullptr));
        taskStatusBox->setItemText(5, QApplication::translate("taskManager", "\345\276\205\345\210\206\351\205\215\344\273\273\345\212\241", nullptr));

        label_44->setText(QApplication::translate("taskManager", "\350\265\267\345\247\213\346\227\266\351\227\264", nullptr));
        label_45->setText(QApplication::translate("taskManager", "\346\210\252\350\207\263\346\227\266\351\227\264", nullptr));
        label_2->setText(QString());
        Qury_Button->setText(QApplication::translate("taskManager", "\346\237\245\350\257\242", nullptr));
        Cancel_Button->setText(QApplication::translate("taskManager", "\345\217\226\346\266\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("taskManager", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("taskManager", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("taskManager", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("taskManager", "\344\272\247\345\223\201\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("taskManager", "\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("taskManager", "\345\272\223\345\255\230\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("taskManager", "\345\257\271\345\272\224\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("taskManager", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("taskManager", "\345\257\271\346\216\245\347\240\201\345\244\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("taskManager", "\344\273\273\345\212\241\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("taskManager", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        taskStatusBox_ESS->setItemText(0, QApplication::translate("taskManager", "ESS\344\273\273\345\212\241\346\214\207\344\273\244", nullptr));
        taskStatusBox_ESS->setItemText(1, QApplication::translate("taskManager", "STATION-01_\345\205\245\345\234\272", nullptr));
        taskStatusBox_ESS->setItemText(2, QApplication::translate("taskManager", "STATION-03_\347\246\273\345\234\272", nullptr));
        taskStatusBox_ESS->setItemText(3, QApplication::translate("taskManager", "STATION-04_\347\246\273\345\234\272", nullptr));
        taskStatusBox_ESS->setItemText(4, QApplication::translate("taskManager", "\345\205\245\345\272\223\345\256\214\346\210\220", nullptr));
        taskStatusBox_ESS->setItemText(5, QApplication::translate("taskManager", "\345\217\226\346\266\210ESS\344\273\273\345\212\241", nullptr));

        taskStatusBox_AGV->setItemText(0, QApplication::translate("taskManager", "AGV\350\277\220\350\276\223\346\214\207\344\273\244", nullptr));
        taskStatusBox_AGV->setItemText(1, QApplication::translate("taskManager", "\346\211\247\350\241\214\350\265\267\345\247\213\346\245\274\345\261\202\344\273\273\345\212\241", nullptr));
        taskStatusBox_AGV->setItemText(2, QApplication::translate("taskManager", "\346\211\247\350\241\214\347\233\256\346\240\207\346\245\274\345\261\202\344\273\273\345\212\241", nullptr));
        taskStatusBox_AGV->setItemText(3, QApplication::translate("taskManager", "-------------------", nullptr));
        taskStatusBox_AGV->setItemText(4, QApplication::translate("taskManager", "-------------------", nullptr));

        checkBox_Edite->setText(QString());
        Delete_Button->setText(QApplication::translate("taskManager", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskManager: public Ui_taskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
