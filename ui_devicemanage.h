/********************************************************************************
** Form generated from reading UI file 'devicemanage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEMANAGE_H
#define UI_DEVICEMANAGE_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceManage
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_7;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_8;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QComboBox *LiftIP_Box;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *lineEdit_floor;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *lineEdit_action;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QLineEdit *lineEdit_error;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *taskTypeBox_Lift;
    QPushButton *Sure_Button_Lift;
    QTextEdit *tabletTextEdit;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QGridLayout *gridLayout_8;
    QWidget *widget_1;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *LayoutWidget_c;
    QWidget *page_3;
    QGridLayout *gridLayout_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_S1;
    QPushButton *Button_S2;
    QPushButton *Button_S3;
    QWidget *LayoutWidget_s;
    QWidget *LayoutWidget_ss;
    QWidget *page_4;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Button_D1;
    QPushButton *Button_D2;
    QPushButton *Button_D3;
    QPushButton *Button_D4;
    QPushButton *Button_D5;
    QWidget *LayoutWidget_d;
    QWidget *LayoutWidget_dd;
    QWidget *page_2;
    QGridLayout *gridLayout_11;
    QWidget *widget_4;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DeviceManage)
    {
        if (DeviceManage->objectName().isEmpty())
            DeviceManage->setObjectName(QString::fromUtf8("DeviceManage"));
        DeviceManage->resize(1736, 1133);
        gridLayout = new QGridLayout(DeviceManage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_7 = new QWidget(DeviceManage);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(180, 300));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 166, 172);\n"
"background-color: rgb(60, 54, 69);\n"
"background-color: rgb(89, 83, 103);"));
        gridLayout_9 = new QGridLayout(widget_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(-1, -1, 20, -1);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(10);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        treeWidget = new QTreeWidget(widget_7);
        treeWidget->headerItem()->setText(0, QString());
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        treeWidget->setFont(font);
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeView {    \n"
" 	outline: 0px;   \n"
"	color: rgb(255, 255, 255);\n"
"	border: 0px solid #000000;\n"
"}\n"
"\n"
"QTreeView::branch {\n"
"	QTreeView::branch {image:none;}\n"
"}\n"
"\n"
"QTreeView::item {\n"
"	height:20px;\n"
"	padding:12px;\n"
"	padding-left:2px; \n"
"    border-top-color: transparent;\n"
"	border-left-color: transparent;\n"
"}\n"
"\n"
"QTreeView::item:hover {        \n"
"	background-color: rgb(94, 124, 133);\n"
"}\n"
" \n"
"QTreeView::item:selected {    \n"
"	background-color: rgb(118, 190, 204);\n"
"}\n"
" \n"
"QTreeView::item:selected:active{  \n"
"}\n"
" \n"
"QTreeView::item:selected:!active {   \n"
"}\n"
"/*\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/Record.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/Statement.png);\n"
"}*/\n"
"\n"
"\n"
"\n"
""));
        treeWidget->setAutoScrollMargin(12);
        treeWidget->setDefaultDropAction(Qt::ActionMask);
        treeWidget->setIconSize(QSize(40, 35));
        treeWidget->setIndentation(20);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setMinimumSectionSize(35);
        treeWidget->header()->setDefaultSectionSize(125);
        treeWidget->header()->setHighlightSections(false);

        verticalLayout_8->addWidget(treeWidget);

        verticalLayout_8->setStretch(0, 10);

        gridLayout_9->addLayout(verticalLayout_8, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(widget_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DeviceManage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 180));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);\n"
""));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 11, -1, 11);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(30);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setPointSize(16);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"\n"
""));

        horizontalLayout_9->addWidget(label_7);

        LiftIP_Box = new QComboBox(widget);
        LiftIP_Box->setObjectName(QString::fromUtf8("LiftIP_Box"));
        sizePolicy.setHeightForWidth(LiftIP_Box->sizePolicy().hasHeightForWidth());
        LiftIP_Box->setSizePolicy(sizePolicy);
        LiftIP_Box->setMinimumSize(QSize(280, 35));
        LiftIP_Box->setMaximumSize(QSize(16777215, 45));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        LiftIP_Box->setFont(font2);
        LiftIP_Box->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color:#FEFEFE;\n"
"background-color: rgb(0, 166, 172);\n"
"border: 0px solid #FFFFFF;border-radius: 3px;\n"
"}\n"
"QComboBox:hover{\n"
"	border: 1px solid #C0C4CC;\n"
"}\n"
""));

        horizontalLayout_9->addWidget(LiftIP_Box);

        horizontalLayout_9->setStretch(0, 1);

        horizontalLayout_17->addLayout(horizontalLayout_9);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"\n"
""));

        horizontalLayout_13->addWidget(label_9);

        lineEdit_floor = new QLineEdit(widget);
        lineEdit_floor->setObjectName(QString::fromUtf8("lineEdit_floor"));
        sizePolicy.setHeightForWidth(lineEdit_floor->sizePolicy().hasHeightForWidth());
        lineEdit_floor->setSizePolicy(sizePolicy);
        lineEdit_floor->setMinimumSize(QSize(100, 0));
        lineEdit_floor->setMaximumSize(QSize(200, 33));
        lineEdit_floor->setFont(font);
        lineEdit_floor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        horizontalLayout_13->addWidget(lineEdit_floor);

        horizontalLayout_13->setStretch(0, 1);

        horizontalLayout_17->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(3);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"\n"
""));

        horizontalLayout_12->addWidget(label_8);

        lineEdit_action = new QLineEdit(widget);
        lineEdit_action->setObjectName(QString::fromUtf8("lineEdit_action"));
        sizePolicy.setHeightForWidth(lineEdit_action->sizePolicy().hasHeightForWidth());
        lineEdit_action->setSizePolicy(sizePolicy);
        lineEdit_action->setMinimumSize(QSize(100, 0));
        lineEdit_action->setMaximumSize(QSize(200, 33));
        lineEdit_action->setFont(font);
        lineEdit_action->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        horizontalLayout_12->addWidget(lineEdit_action);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 5);

        horizontalLayout_17->addLayout(horizontalLayout_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(3);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"\n"
""));

        horizontalLayout_15->addWidget(label_10);

        lineEdit_error = new QLineEdit(widget);
        lineEdit_error->setObjectName(QString::fromUtf8("lineEdit_error"));
        sizePolicy.setHeightForWidth(lineEdit_error->sizePolicy().hasHeightForWidth());
        lineEdit_error->setSizePolicy(sizePolicy);
        lineEdit_error->setMinimumSize(QSize(100, 0));
        lineEdit_error->setMaximumSize(QSize(200, 33));
        lineEdit_error->setFont(font);
        lineEdit_error->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        horizontalLayout_15->addWidget(lineEdit_error);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 5);

        horizontalLayout_17->addLayout(horizontalLayout_15);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_5);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 1);
        horizontalLayout_17->setStretch(2, 1);
        horizontalLayout_17->setStretch(3, 1);
        horizontalLayout_17->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(30);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border:0px;\n"
"border-style: outset;\n"
""));

        horizontalLayout_4->addWidget(label_4);

        taskTypeBox_Lift = new QComboBox(widget);
        taskTypeBox_Lift->addItem(QString());
        taskTypeBox_Lift->addItem(QString());
        taskTypeBox_Lift->addItem(QString());
        taskTypeBox_Lift->setObjectName(QString::fromUtf8("taskTypeBox_Lift"));
        sizePolicy.setHeightForWidth(taskTypeBox_Lift->sizePolicy().hasHeightForWidth());
        taskTypeBox_Lift->setSizePolicy(sizePolicy);
        taskTypeBox_Lift->setMinimumSize(QSize(180, 35));
        taskTypeBox_Lift->setMaximumSize(QSize(16777215, 45));
        taskTypeBox_Lift->setFont(font2);
        taskTypeBox_Lift->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color:#FEFEFE;\n"
"background-color: rgb(0, 166, 172);\n"
"border: 0px solid #FFFFFF;border-radius: 3px;\n"
"}\n"
"QComboBox:hover{\n"
"	border: 1px solid #C0C4CC;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(taskTypeBox_Lift);


        horizontalLayout_14->addLayout(horizontalLayout_4);

        Sure_Button_Lift = new QPushButton(widget);
        Sure_Button_Lift->setObjectName(QString::fromUtf8("Sure_Button_Lift"));
        Sure_Button_Lift->setEnabled(true);
        sizePolicy.setHeightForWidth(Sure_Button_Lift->sizePolicy().hasHeightForWidth());
        Sure_Button_Lift->setSizePolicy(sizePolicy);
        Sure_Button_Lift->setMinimumSize(QSize(120, 40));
        Sure_Button_Lift->setMaximumSize(QSize(221, 45));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        Sure_Button_Lift->setFont(font3);
        Sure_Button_Lift->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_14->addWidget(Sure_Button_Lift);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_6->setStretch(0, 10);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_6->addLayout(verticalLayout_2);

        tabletTextEdit = new QTextEdit(widget);
        tabletTextEdit->setObjectName(QString::fromUtf8("tabletTextEdit"));
        sizePolicy.setHeightForWidth(tabletTextEdit->sizePolicy().hasHeightForWidth());
        tabletTextEdit->setSizePolicy(sizePolicy);
        tabletTextEdit->setMinimumSize(QSize(0, 50));
        tabletTextEdit->setMaximumSize(QSize(16777215, 200));
        tabletTextEdit->setFont(font);
        tabletTextEdit->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: rgb(255, 170, 127);"));

        verticalLayout_6->addWidget(tabletTextEdit);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        gridLayout_6->addLayout(verticalLayout_6, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        stackedWidget_2 = new QStackedWidget(DeviceManage);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_8 = new QGridLayout(page);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        widget_1 = new QWidget(page);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMinimumSize(QSize(0, 80));
        widget_1->setMaximumSize(QSize(16777215, 1677215));
        widget_1->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout_7 = new QGridLayout(widget_1);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(widget_1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(13, 39, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 10);

        verticalLayout_5->addLayout(horizontalLayout_8);

        LayoutWidget_c = new QWidget(widget_1);
        LayoutWidget_c->setObjectName(QString::fromUtf8("LayoutWidget_c"));

        verticalLayout_5->addWidget(LayoutWidget_c);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 20);

        gridLayout_7->addLayout(verticalLayout_5, 0, 0, 1, 1);


        gridLayout_8->addWidget(widget_1, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_5 = new QGridLayout(page_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_2 = new QWidget(page_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 80));
        widget_2->setMaximumSize(QSize(16777215, 1677215));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(13, 39, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Button_S1 = new QPushButton(widget_2);
        Button_S1->setObjectName(QString::fromUtf8("Button_S1"));
        sizePolicy.setHeightForWidth(Button_S1->sizePolicy().hasHeightForWidth());
        Button_S1->setSizePolicy(sizePolicy);
        Button_S1->setMinimumSize(QSize(110, 40));
        Button_S1->setMaximumSize(QSize(120, 40));
        Button_S1->setFont(font4);
        Button_S1->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout->addWidget(Button_S1);

        Button_S2 = new QPushButton(widget_2);
        Button_S2->setObjectName(QString::fromUtf8("Button_S2"));
        sizePolicy.setHeightForWidth(Button_S2->sizePolicy().hasHeightForWidth());
        Button_S2->setSizePolicy(sizePolicy);
        Button_S2->setMinimumSize(QSize(110, 40));
        Button_S2->setMaximumSize(QSize(120, 40));
        Button_S2->setFont(font4);
        Button_S2->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout->addWidget(Button_S2);

        Button_S3 = new QPushButton(widget_2);
        Button_S3->setObjectName(QString::fromUtf8("Button_S3"));
        sizePolicy.setHeightForWidth(Button_S3->sizePolicy().hasHeightForWidth());
        Button_S3->setSizePolicy(sizePolicy);
        Button_S3->setMinimumSize(QSize(110, 40));
        Button_S3->setMaximumSize(QSize(120, 40));
        Button_S3->setFont(font4);
        Button_S3->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout->addWidget(Button_S3);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        LayoutWidget_s = new QWidget(widget_2);
        LayoutWidget_s->setObjectName(QString::fromUtf8("LayoutWidget_s"));

        verticalLayout_3->addWidget(LayoutWidget_s);

        LayoutWidget_ss = new QWidget(widget_2);
        LayoutWidget_ss->setObjectName(QString::fromUtf8("LayoutWidget_ss"));

        verticalLayout_3->addWidget(LayoutWidget_ss);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);
        verticalLayout_3->setStretch(2, 10);

        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_4 = new QGridLayout(page_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_3 = new QWidget(page_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 80));
        widget_3->setMaximumSize(QSize(16777215, 1677215));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(15);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Button_D1 = new QPushButton(widget_3);
        Button_D1->setObjectName(QString::fromUtf8("Button_D1"));
        sizePolicy.setHeightForWidth(Button_D1->sizePolicy().hasHeightForWidth());
        Button_D1->setSizePolicy(sizePolicy);
        Button_D1->setMinimumSize(QSize(110, 40));
        Button_D1->setMaximumSize(QSize(120, 45));
        Button_D1->setFont(font4);
        Button_D1->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_7->addWidget(Button_D1);

        Button_D2 = new QPushButton(widget_3);
        Button_D2->setObjectName(QString::fromUtf8("Button_D2"));
        sizePolicy.setHeightForWidth(Button_D2->sizePolicy().hasHeightForWidth());
        Button_D2->setSizePolicy(sizePolicy);
        Button_D2->setMinimumSize(QSize(110, 40));
        Button_D2->setMaximumSize(QSize(120, 45));
        Button_D2->setFont(font4);
        Button_D2->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_7->addWidget(Button_D2);

        Button_D3 = new QPushButton(widget_3);
        Button_D3->setObjectName(QString::fromUtf8("Button_D3"));
        sizePolicy.setHeightForWidth(Button_D3->sizePolicy().hasHeightForWidth());
        Button_D3->setSizePolicy(sizePolicy);
        Button_D3->setMinimumSize(QSize(110, 40));
        Button_D3->setMaximumSize(QSize(120, 45));
        Button_D3->setFont(font4);
        Button_D3->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_7->addWidget(Button_D3);

        Button_D4 = new QPushButton(widget_3);
        Button_D4->setObjectName(QString::fromUtf8("Button_D4"));
        sizePolicy.setHeightForWidth(Button_D4->sizePolicy().hasHeightForWidth());
        Button_D4->setSizePolicy(sizePolicy);
        Button_D4->setMinimumSize(QSize(110, 40));
        Button_D4->setMaximumSize(QSize(120, 45));
        Button_D4->setFont(font4);
        Button_D4->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_7->addWidget(Button_D4);

        Button_D5 = new QPushButton(widget_3);
        Button_D5->setObjectName(QString::fromUtf8("Button_D5"));
        sizePolicy.setHeightForWidth(Button_D5->sizePolicy().hasHeightForWidth());
        Button_D5->setSizePolicy(sizePolicy);
        Button_D5->setMinimumSize(QSize(110, 40));
        Button_D5->setMaximumSize(QSize(120, 45));
        Button_D5->setFont(font4);
        Button_D5->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_7->addWidget(Button_D5);


        horizontalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_4->addLayout(horizontalLayout_3);

        LayoutWidget_d = new QWidget(widget_3);
        LayoutWidget_d->setObjectName(QString::fromUtf8("LayoutWidget_d"));

        verticalLayout_4->addWidget(LayoutWidget_d);

        LayoutWidget_dd = new QWidget(widget_3);
        LayoutWidget_dd->setObjectName(QString::fromUtf8("LayoutWidget_dd"));

        verticalLayout_4->addWidget(LayoutWidget_dd);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 10);
        verticalLayout_4->setStretch(2, 10);

        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_4->addWidget(widget_3, 1, 0, 1, 1);

        stackedWidget_2->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_11 = new QGridLayout(page_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        widget_4 = new QWidget(page_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout_10 = new QGridLayout(widget_4);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tableWidget = new QTableWidget(widget_4);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font5;
        font5.setPointSize(12);
        tableWidget->setFont(font5);
        tableWidget->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        gridLayout_10->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_4, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);

        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 20);

        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        retranslateUi(DeviceManage);

        stackedWidget_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(DeviceManage);
    } // setupUi

    void retranslateUi(QWidget *DeviceManage)
    {
        DeviceManage->setWindowTitle(QApplication::translate("DeviceManage", "Form", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("DeviceManage", "\345\215\207\351\231\215\346\234\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem1->setText(0, QApplication::translate("DeviceManage", "\346\216\245\351\251\263\345\217\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem2->setText(0, QApplication::translate("DeviceManage", "\350\207\252\345\212\250\351\227\250", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_7->setText(QApplication::translate("DeviceManage", "\345\215\207\351\231\215\346\234\272IP:", nullptr));
        label_9->setText(QApplication::translate("DeviceManage", "\345\275\223\345\211\215\346\245\274\345\261\202:", nullptr));
        label_8->setText(QApplication::translate("DeviceManage", "\347\263\273\347\273\237\346\214\207\344\273\244:", nullptr));
        label_10->setText(QApplication::translate("DeviceManage", "\345\274\202\345\270\270\344\277\241\346\201\257:", nullptr));
        label_4->setText(QApplication::translate("DeviceManage", "\345\212\250\344\275\234\346\214\207\344\273\244:", nullptr));
        taskTypeBox_Lift->setItemText(0, QApplication::translate("DeviceManage", "\346\270\205\351\231\244\346\214\207\344\273\244", nullptr));
        taskTypeBox_Lift->setItemText(1, QApplication::translate("DeviceManage", "2F-->3F", nullptr));
        taskTypeBox_Lift->setItemText(2, QApplication::translate("DeviceManage", "3F-->2F", nullptr));

        Sure_Button_Lift->setText(QApplication::translate("DeviceManage", "\347\241\256\345\256\232", nullptr));
#ifndef QT_NO_TOOLTIP
        tabletTextEdit->setToolTip(QApplication::translate("DeviceManage", "<html><head/><body><p><span style=\" color:#2aa198;\">(IN-&gt;1\345\217\257\346\224\276\346\226\231;2,3\347\233\256\346\240\207\346\245\274\345\261\202\342\200\224\342\200\224OUT--&gt;1\345\217\257\345\217\226\346\226\231,0\347\251\272\351\227\262)</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabletTextEdit->setHtml(QApplication::translate("DeviceManage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("DeviceManage", "AGV\345\205\205\347\224\265\346\241\251", nullptr));
        label_2->setText(QApplication::translate("DeviceManage", "\345\267\245\344\275\234\347\253\231-\346\216\245\351\251\263\345\217\260", nullptr));
        Button_S1->setText(QApplication::translate("DeviceManage", "2F", nullptr));
        Button_S2->setText(QApplication::translate("DeviceManage", "3F", nullptr));
        Button_S3->setText(QApplication::translate("DeviceManage", "4F", nullptr));
        label_3->setText(QApplication::translate("DeviceManage", "\350\207\252\345\212\250\351\227\250\346\216\247\345\210\266", nullptr));
        Button_D1->setText(QApplication::translate("DeviceManage", "\351\241\265\346\225\260_1", nullptr));
        Button_D2->setText(QApplication::translate("DeviceManage", "\351\241\265\346\225\260_2", nullptr));
        Button_D3->setText(QApplication::translate("DeviceManage", "\351\241\265\346\225\260_3", nullptr));
        Button_D4->setText(QApplication::translate("DeviceManage", "\351\241\265\346\225\260_4", nullptr));
        Button_D5->setText(QApplication::translate("DeviceManage", "\351\241\265\346\225\260_5", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DeviceManage", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DeviceManage", "\345\215\207\351\231\215\346\234\272\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DeviceManage", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DeviceManage", "PLC\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DeviceManage", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DeviceManage", "\344\273\273\345\212\241Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DeviceManage", "\346\226\231\346\241\206\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("DeviceManage", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("DeviceManage", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("DeviceManage", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("DeviceManage", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("DeviceManage", "\346\226\260\345\273\272\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceManage: public Ui_DeviceManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEMANAGE_H
