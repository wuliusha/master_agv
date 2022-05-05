/********************************************************************************
** Form generated from reading UI file 'binwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINWIDGET_H
#define UI_BINWIDGET_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_binwidget
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLabel *pcbListdesc;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QLabel *shelfBindesc;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLabel *containerCode;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLabel *materialNumber;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *realqty;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *Binstatus;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *enableButton;
    QPushButton *enableButton_show;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *LastButton;
    QPushButton *NextButton;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AlterButton;
    QPushButton *CancelButton;
    QWidget *page_5;
    QGridLayout *gridLayout_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_70;
    QLabel *label_37;
    QComboBox *taskType;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_74;
    QLabel *label_40;
    QLineEdit *fromLocationCode;
    QHBoxLayout *horizontalLayout_77;
    QLabel *Tolll_6;
    QLineEdit *toStationCode;
    QHBoxLayout *horizontalLayout_81;
    QLabel *Tolll_8;
    QLineEdit *obligate3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_71;
    QLabel *label_38;
    QLineEdit *containerCode_2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_39;
    QComboBox *pickDesc_s;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_80;
    QLabel *Tolll_7;
    QLineEdit *toLocationCode;
    QHBoxLayout *horizontalLayout_83;
    QLabel *label_44;
    QLineEdit *positionCode;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *clear_Button;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *AgvExecute;
    QPushButton *CancelButton_3;

    void setupUi(QWidget *binwidget)
    {
        if (binwidget->objectName().isEmpty())
            binwidget->setObjectName(QString::fromUtf8("binwidget"));
        binwidget->resize(1267, 819);
        gridLayout_4 = new QGridLayout(binwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget = new QWidget(binwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 350));
        widget->setMaximumSize(QSize(167777, 167777));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 170, 166);\n"
""));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_8);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(16777215, 45));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_22->addWidget(label_17);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_22);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777, 16777215));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_9);

        pcbListdesc = new QLabel(widget);
        pcbListdesc->setObjectName(QString::fromUtf8("pcbListdesc"));
        pcbListdesc->setMinimumSize(QSize(0, 35));
        pcbListdesc->setFont(font1);
        pcbListdesc->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_2->addWidget(pcbListdesc);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(20);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_10->addWidget(label_7);

        shelfBindesc = new QLabel(widget);
        shelfBindesc->setObjectName(QString::fromUtf8("shelfBindesc"));
        shelfBindesc->setMinimumSize(QSize(0, 35));
        shelfBindesc->setFont(font1);
        shelfBindesc->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_10->addWidget(shelfBindesc);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(20);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_11->addWidget(label_10);

        containerCode = new QLabel(widget);
        containerCode->setObjectName(QString::fromUtf8("containerCode"));
        containerCode->setMinimumSize(QSize(0, 35));
        containerCode->setFont(font1);
        containerCode->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_11->addWidget(containerCode);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(label_4);

        materialNumber = new QLabel(widget);
        materialNumber->setObjectName(QString::fromUtf8("materialNumber"));
        materialNumber->setMinimumSize(QSize(0, 35));
        materialNumber->setFont(font1);
        materialNumber->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_8->addWidget(materialNumber);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(label_2);

        realqty = new QLabel(widget);
        realqty->setObjectName(QString::fromUtf8("realqty"));
        realqty->setMinimumSize(QSize(0, 35));
        realqty->setFont(font1);
        realqty->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_7->addWidget(realqty);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777, 16777215));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_8);

        Binstatus = new QLabel(widget);
        Binstatus->setObjectName(QString::fromUtf8("Binstatus"));
        Binstatus->setMinimumSize(QSize(0, 35));
        Binstatus->setFont(font1);
        Binstatus->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout->addWidget(Binstatus);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(20);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        enableButton = new QPushButton(widget);
        enableButton->setObjectName(QString::fromUtf8("enableButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(enableButton->sizePolicy().hasHeightForWidth());
        enableButton->setSizePolicy(sizePolicy);
        enableButton->setMinimumSize(QSize(70, 39));
        enableButton->setMaximumSize(QSize(60, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        enableButton->setFont(font2);
        enableButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE"));
        enableButton->setText(QString::fromUtf8("\344\275\277\347\224\250"));

        horizontalLayout_9->addWidget(enableButton);

        enableButton_show = new QPushButton(widget);
        enableButton_show->setObjectName(QString::fromUtf8("enableButton_show"));
        sizePolicy.setHeightForWidth(enableButton_show->sizePolicy().hasHeightForWidth());
        enableButton_show->setSizePolicy(sizePolicy);
        enableButton_show->setMinimumSize(QSize(70, 39));
        enableButton_show->setMaximumSize(QSize(60, 41));
        enableButton_show->setFont(font2);
        enableButton_show->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);border-radius:15px;color:#FEFEFE"));
        enableButton_show->setText(QString::fromUtf8("\346\230\276\347\244\272"));

        horizontalLayout_9->addWidget(enableButton_show);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        horizontalLayout_13->addLayout(horizontalLayout_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(15);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        LastButton = new QPushButton(widget);
        LastButton->setObjectName(QString::fromUtf8("LastButton"));
        sizePolicy.setHeightForWidth(LastButton->sizePolicy().hasHeightForWidth());
        LastButton->setSizePolicy(sizePolicy);
        LastButton->setMaximumSize(QSize(45, 35));
        LastButton->setStyleSheet(QString::fromUtf8("background-color: rgb(81, 81, 81);\n"
"color:#FEFEFE"));

        horizontalLayout_12->addWidget(LastButton);

        NextButton = new QPushButton(widget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        sizePolicy.setHeightForWidth(NextButton->sizePolicy().hasHeightForWidth());
        NextButton->setSizePolicy(sizePolicy);
        NextButton->setMaximumSize(QSize(45, 35));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        NextButton->setFont(font3);
        NextButton->setStyleSheet(QString::fromUtf8("background-color: rgb(81, 81, 81);\n"
"color:#FEFEFE"));

        horizontalLayout_12->addWidget(NextButton);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        horizontalLayout_13->addLayout(horizontalLayout_12);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 18);
        horizontalLayout_13->setStretch(2, 3);

        verticalLayout_4->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(verticalLayout_4);


        gridLayout_3->addLayout(verticalLayout_7, 0, 0, 1, 1);


        verticalLayout_6->addWidget(widget);

        stackedWidget_2 = new QStackedWidget(binwidget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(81, 81, 81);"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout = new QGridLayout(page_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 20, 10, 20);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        label_18 = new QLabel(page_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(16777215, 50));
        QFont font4;
        font4.setPointSize(18);
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_6->addWidget(label_18);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_6);

        tableWidget = new QTableWidget(page_4);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font5;
        font5.setPointSize(12);
        tableWidget->setFont(font5);
        tableWidget->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 10, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AlterButton = new QPushButton(page_4);
        AlterButton->setObjectName(QString::fromUtf8("AlterButton"));
        sizePolicy.setHeightForWidth(AlterButton->sizePolicy().hasHeightForWidth());
        AlterButton->setSizePolicy(sizePolicy);
        AlterButton->setMinimumSize(QSize(0, 40));
        AlterButton->setMaximumSize(QSize(16777215, 45));
        AlterButton->setFont(font1);
        AlterButton->setStyleSheet(QString::fromUtf8("color:#ffffff;color: white;\n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset;\n"
"background-color: rgb(81,81,81);\n"
""));

        horizontalLayout_5->addWidget(AlterButton);

        CancelButton = new QPushButton(page_4);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        sizePolicy.setHeightForWidth(CancelButton->sizePolicy().hasHeightForWidth());
        CancelButton->setSizePolicy(sizePolicy);
        CancelButton->setMinimumSize(QSize(0, 40));
        CancelButton->setMaximumSize(QSize(16777215, 45));
        CancelButton->setFont(font1);
        CancelButton->setStyleSheet(QString::fromUtf8("color:#ffffff;color: white;\n"
"border: 2px groove gray;\n"
"border-radius:15px;border-style: outset;\n"
"background-color: rgb(81,81,81);\n"
""));

        horizontalLayout_5->addWidget(CancelButton);

        horizontalLayout_5->setStretch(0, 10);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_5 = new QGridLayout(page_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_2 = new QWidget(page_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(167777, 167777));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 30);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(30);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_5);

        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 45));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_21->addWidget(label_16);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_21);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(20, -1, 20, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_70 = new QHBoxLayout();
        horizontalLayout_70->setObjectName(QString::fromUtf8("horizontalLayout_70"));
        label_37 = new QLabel(widget_2);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font1);
        label_37->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_70->addWidget(label_37);

        taskType = new QComboBox(widget_2);
        taskType->addItem(QString());
        taskType->addItem(QString());
        taskType->addItem(QString());
        taskType->addItem(QString());
        taskType->setObjectName(QString::fromUtf8("taskType"));
        taskType->setMinimumSize(QSize(160, 37));
        taskType->setMaximumSize(QSize(160, 37));
        taskType->setFont(font1);
        taskType->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_70->addWidget(taskType);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_70->addItem(horizontalSpacer_6);

        horizontalLayout_70->setStretch(0, 1);
        horizontalLayout_70->setStretch(1, 1);
        horizontalLayout_70->setStretch(2, 5);

        verticalLayout_2->addLayout(horizontalLayout_70);

        horizontalLayout_74 = new QHBoxLayout();
        horizontalLayout_74->setObjectName(QString::fromUtf8("horizontalLayout_74"));
        label_40 = new QLabel(widget_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font1);
        label_40->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_74->addWidget(label_40);

        fromLocationCode = new QLineEdit(widget_2);
        fromLocationCode->setObjectName(QString::fromUtf8("fromLocationCode"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fromLocationCode->sizePolicy().hasHeightForWidth());
        fromLocationCode->setSizePolicy(sizePolicy1);
        fromLocationCode->setMinimumSize(QSize(0, 35));
        fromLocationCode->setFont(font1);
        fromLocationCode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_74->addWidget(fromLocationCode);

        horizontalLayout_74->setStretch(0, 1);
        horizontalLayout_74->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_74);

        horizontalLayout_77 = new QHBoxLayout();
        horizontalLayout_77->setObjectName(QString::fromUtf8("horizontalLayout_77"));
        Tolll_6 = new QLabel(widget_2);
        Tolll_6->setObjectName(QString::fromUtf8("Tolll_6"));
        Tolll_6->setFont(font1);
        Tolll_6->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_77->addWidget(Tolll_6);

        toStationCode = new QLineEdit(widget_2);
        toStationCode->setObjectName(QString::fromUtf8("toStationCode"));
        sizePolicy1.setHeightForWidth(toStationCode->sizePolicy().hasHeightForWidth());
        toStationCode->setSizePolicy(sizePolicy1);
        toStationCode->setMinimumSize(QSize(0, 35));
        toStationCode->setFont(font1);
        toStationCode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_77->addWidget(toStationCode);

        horizontalLayout_77->setStretch(0, 1);
        horizontalLayout_77->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_77);

        horizontalLayout_81 = new QHBoxLayout();
        horizontalLayout_81->setObjectName(QString::fromUtf8("horizontalLayout_81"));
        Tolll_8 = new QLabel(widget_2);
        Tolll_8->setObjectName(QString::fromUtf8("Tolll_8"));
        Tolll_8->setFont(font1);
        Tolll_8->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_81->addWidget(Tolll_8);

        obligate3 = new QLineEdit(widget_2);
        obligate3->setObjectName(QString::fromUtf8("obligate3"));
        sizePolicy1.setHeightForWidth(obligate3->sizePolicy().hasHeightForWidth());
        obligate3->setSizePolicy(sizePolicy1);
        obligate3->setFont(font1);
        obligate3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_81->addWidget(obligate3);

        horizontalLayout_81->setStretch(0, 1);
        horizontalLayout_81->setStretch(1, 10);

        verticalLayout_2->addLayout(horizontalLayout_81);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_71 = new QHBoxLayout();
        horizontalLayout_71->setObjectName(QString::fromUtf8("horizontalLayout_71"));
        label_38 = new QLabel(widget_2);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font1);
        label_38->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_71->addWidget(label_38);

        containerCode_2 = new QLineEdit(widget_2);
        containerCode_2->setObjectName(QString::fromUtf8("containerCode_2"));
        sizePolicy1.setHeightForWidth(containerCode_2->sizePolicy().hasHeightForWidth());
        containerCode_2->setSizePolicy(sizePolicy1);
        containerCode_2->setFont(font1);
        containerCode_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_71->addWidget(containerCode_2);

        horizontalLayout_71->setStretch(0, 1);
        horizontalLayout_71->setStretch(1, 10);

        verticalLayout_5->addLayout(horizontalLayout_71);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_39 = new QLabel(widget_2);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font1);
        label_39->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_17->addWidget(label_39);

        pickDesc_s = new QComboBox(widget_2);
        pickDesc_s->addItem(QString());
        pickDesc_s->addItem(QString());
        pickDesc_s->setObjectName(QString::fromUtf8("pickDesc_s"));
        pickDesc_s->setMinimumSize(QSize(200, 37));
        pickDesc_s->setMaximumSize(QSize(160, 37));
        pickDesc_s->setFont(font1);
        pickDesc_s->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_17->addWidget(pickDesc_s);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_11);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 2);
        horizontalLayout_17->setStretch(2, 10);

        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_80 = new QHBoxLayout();
        horizontalLayout_80->setObjectName(QString::fromUtf8("horizontalLayout_80"));
        Tolll_7 = new QLabel(widget_2);
        Tolll_7->setObjectName(QString::fromUtf8("Tolll_7"));
        Tolll_7->setFont(font1);
        Tolll_7->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_80->addWidget(Tolll_7);

        toLocationCode = new QLineEdit(widget_2);
        toLocationCode->setObjectName(QString::fromUtf8("toLocationCode"));
        sizePolicy1.setHeightForWidth(toLocationCode->sizePolicy().hasHeightForWidth());
        toLocationCode->setSizePolicy(sizePolicy1);
        toLocationCode->setFont(font1);
        toLocationCode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_80->addWidget(toLocationCode);

        horizontalLayout_80->setStretch(0, 1);
        horizontalLayout_80->setStretch(1, 10);

        verticalLayout_5->addLayout(horizontalLayout_80);

        horizontalLayout_83 = new QHBoxLayout();
        horizontalLayout_83->setObjectName(QString::fromUtf8("horizontalLayout_83"));
        label_44 = new QLabel(widget_2);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_83->addWidget(label_44);

        positionCode = new QLineEdit(widget_2);
        positionCode->setObjectName(QString::fromUtf8("positionCode"));
        sizePolicy1.setHeightForWidth(positionCode->sizePolicy().hasHeightForWidth());
        positionCode->setSizePolicy(sizePolicy1);
        positionCode->setFont(font1);
        positionCode->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_83->addWidget(positionCode);

        horizontalLayout_83->setStretch(0, 1);
        horizontalLayout_83->setStretch(1, 10);

        verticalLayout_5->addLayout(horizontalLayout_83);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(10);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        clear_Button = new QPushButton(widget_2);
        clear_Button->setObjectName(QString::fromUtf8("clear_Button"));
        sizePolicy.setHeightForWidth(clear_Button->sizePolicy().hasHeightForWidth());
        clear_Button->setSizePolicy(sizePolicy);
        clear_Button->setMinimumSize(QSize(200, 45));
        clear_Button->setMaximumSize(QSize(16777215, 45));
        clear_Button->setFont(font1);
        clear_Button->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:15px;\n"
"background-color: rgb(80, 138, 136);"));

        horizontalLayout_16->addWidget(clear_Button);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_7);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(30);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        AgvExecute = new QPushButton(widget_2);
        AgvExecute->setObjectName(QString::fromUtf8("AgvExecute"));
        sizePolicy.setHeightForWidth(AgvExecute->sizePolicy().hasHeightForWidth());
        AgvExecute->setSizePolicy(sizePolicy);
        AgvExecute->setMinimumSize(QSize(200, 45));
        AgvExecute->setMaximumSize(QSize(16777215, 45));
        AgvExecute->setFont(font1);
        AgvExecute->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:15px;\n"
"background-color: rgb(80, 138, 136);\n"
""));

        horizontalLayout_15->addWidget(AgvExecute);

        CancelButton_3 = new QPushButton(widget_2);
        CancelButton_3->setObjectName(QString::fromUtf8("CancelButton_3"));
        sizePolicy.setHeightForWidth(CancelButton_3->sizePolicy().hasHeightForWidth());
        CancelButton_3->setSizePolicy(sizePolicy);
        CancelButton_3->setMinimumSize(QSize(120, 0));
        CancelButton_3->setMaximumSize(QSize(16777215, 45));
        CancelButton_3->setFont(font1);
        CancelButton_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"border-radius:15px;\n"
"background-color: rgb(80, 138, 136);\n"
""));

        horizontalLayout_15->addWidget(CancelButton_3);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 1);

        horizontalLayout_16->addLayout(horizontalLayout_15);

        horizontalLayout_16->setStretch(1, 3);
        horizontalLayout_16->setStretch(2, 1);

        verticalLayout_8->addLayout(horizontalLayout_16);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 5);
        verticalLayout_8->setStretch(2, 2);
        verticalLayout_8->setStretch(3, 1);

        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_5);

        verticalLayout_6->addWidget(stackedWidget_2);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 2);

        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(binwidget);

        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(binwidget);
    } // setupUi

    void retranslateUi(QWidget *binwidget)
    {
        binwidget->setWindowTitle(QApplication::translate("binwidget", "Form", nullptr));
        label_17->setText(QApplication::translate("binwidget", "\345\272\223\344\275\215\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        label_9->setText(QApplication::translate("binwidget", "\344\273\223\344\275\215\345\220\215\347\247\260:", nullptr));
        pcbListdesc->setText(QString());
        label_7->setText(QApplication::translate("binwidget", "\345\272\223\344\275\215\347\274\226\347\240\201:", nullptr));
        shelfBindesc->setText(QString());
        label_10->setText(QApplication::translate("binwidget", "\350\203\266\347\256\261\347\274\226\347\240\201:", nullptr));
        containerCode->setText(QString());
        label_4->setText(QApplication::translate("binwidget", "\345\267\245\345\215\225\347\274\226\347\240\201:", nullptr));
        materialNumber->setText(QString());
        label_2->setText(QApplication::translate("binwidget", "\345\272\223\345\255\230\346\225\260\351\207\217:", nullptr));
        realqty->setText(QString());
        label_8->setText(QApplication::translate("binwidget", "\345\272\223\344\275\215\347\212\266\346\200\201:", nullptr));
        Binstatus->setText(QString());
        LastButton->setText(QString());
        NextButton->setText(QString());
        label_18->setText(QApplication::translate("binwidget", "    \345\272\223\344\275\215\347\211\251\346\226\231\344\277\241\346\201\257(\345\244\207\346\263\250)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("binwidget", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("binwidget", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("binwidget", "\344\272\247\345\223\201\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("binwidget", "\345\272\223\345\255\230\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("binwidget", "PCB\351\233\206\345\220\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("binwidget", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("binwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("binwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("binwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("binwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("binwidget", "\346\226\260\345\273\272\350\241\214", nullptr));
        AlterButton->setText(QApplication::translate("binwidget", "\344\277\256\346\224\271", nullptr));
        CancelButton->setText(QApplication::translate("binwidget", "\345\217\226\346\266\210", nullptr));
        label_16->setText(QApplication::translate("binwidget", "MES \346\211\213\345\212\250\345\210\233\345\273\272\344\273\273\345\212\241\347\225\214\351\235\242", nullptr));
        label_37->setText(QApplication::translate("binwidget", "\344\273\273\345\212\241\347\261\273\345\236\213:", nullptr));
        taskType->setItemText(0, QString());
        taskType->setItemText(1, QApplication::translate("binwidget", "IN", nullptr));
        taskType->setItemText(2, QApplication::translate("binwidget", "OUT", nullptr));
        taskType->setItemText(3, QApplication::translate("binwidget", "MOVE", nullptr));

        label_40->setText(QApplication::translate("binwidget", "\345\275\223\345\211\215\345\272\223\344\275\215:", nullptr));
        fromLocationCode->setText(QString());
        fromLocationCode->setPlaceholderText(QString());
        Tolll_6->setText(QApplication::translate("binwidget", "\347\253\231\347\202\271\347\274\226\345\217\267:", nullptr));
        toStationCode->setText(QString());
        toStationCode->setPlaceholderText(QString());
        Tolll_8->setText(QApplication::translate("binwidget", "    \351\242\204\347\225\231:", nullptr));
        obligate3->setText(QString());
        obligate3->setPlaceholderText(QString());
        label_38->setText(QApplication::translate("binwidget", "\350\203\266\347\256\261\347\274\226\347\240\201:", nullptr));
        containerCode_2->setText(QString());
        containerCode_2->setPlaceholderText(QApplication::translate("binwidget", "A000000001", nullptr));
        label_39->setText(QApplication::translate("binwidget", "\345\207\272\345\272\223\347\240\201\345\244\264:", nullptr));
        pickDesc_s->setItemText(0, QApplication::translate("binwidget", "STATION-03", nullptr));
        pickDesc_s->setItemText(1, QApplication::translate("binwidget", "STATION-04", nullptr));

        Tolll_7->setText(QApplication::translate("binwidget", "\347\233\256\346\240\207\345\272\223\344\275\215:", nullptr));
        toLocationCode->setText(QString());
        toLocationCode->setPlaceholderText(QString());
        label_44->setText(QApplication::translate("binwidget", "\346\216\245\351\251\263\345\217\260\345\257\271\345\272\224\345\235\220\346\240\207:", nullptr));
        positionCode->setText(QString());
        positionCode->setPlaceholderText(QString());
        clear_Button->setText(QApplication::translate("binwidget", "\346\270\205\347\251\272\345\272\223\344\275\215", nullptr));
        AgvExecute->setText(QApplication::translate("binwidget", "\345\217\221\345\270\203\344\273\273\345\212\241", nullptr));
        CancelButton_3->setText(QApplication::translate("binwidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class binwidget: public Ui_binwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINWIDGET_H
