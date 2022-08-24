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
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceManage
{
public:
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
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
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_Edite;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *clearButton;
    QPushButton *pushButton;
    QWidget *widget_7;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_ViewA_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *LiftD100;
    QPushButton *LiftD101;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *LiftD102;
    QPushButton *LiftD103;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *LiftD104;
    QPushButton *LiftD105;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *button_5FOUT;
    QPushButton *button_5FIN;

    void setupUi(QWidget *DeviceManage)
    {
        if (DeviceManage->objectName().isEmpty())
            DeviceManage->setObjectName(QString::fromUtf8("DeviceManage"));
        DeviceManage->resize(1289, 608);
        gridLayout_3 = new QGridLayout(DeviceManage);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(DeviceManage);
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
"	border-color:rgb(48, 104, 151);\n"
"	border-style: outset;\n"
"	background-color: rgb(132, 171, 208);\n"
"	background: transparent;\n"
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
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 180));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);\n"
"background-color: rgb(128, 209, 203);\n"
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_floor->setFont(font3);
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
        lineEdit_action->setFont(font3);
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
        lineEdit_error->setFont(font3);
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
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        Sure_Button_Lift->setFont(font4);
        Sure_Button_Lift->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius:15px;border:none; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #00a6ac; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: white;  \n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"	border-image: url(:/image/close2.png);\n"
"}\n"
"\n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227"
                        "\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #55ff7f;\n"
"}\n"
" \n"
"QPushButton:checked:pressed { /* QPushButton\345\244\204\344\272\216\345\217\257\351\200\211\344\270\255\344\270\224\351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:disabled { /* QPushButton\347\246\201\347\224\250\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #CDCDCD;\n"
"	background-color: #CDCDCD;\n"
"	color: #B4B4B4;\n"
"}"));

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
        tabletTextEdit->setFont(font3);
        tabletTextEdit->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: rgb(255, 170, 127);"));

        verticalLayout_6->addWidget(tabletTextEdit);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        gridLayout_6->addLayout(verticalLayout_6, 0, 0, 1, 1);


        verticalLayout_4->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);\n"
"background-color: rgb(112, 161, 159);\n"
"background-color: rgb(255, 255, 255);"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font5;
        font5.setPointSize(12);
        tableWidget->setFont(font5);
        tableWidget->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        checkBox_Edite = new QCheckBox(tab_2);
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

        horizontalLayout_8->addWidget(checkBox_Edite);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        clearButton = new QPushButton(tab_2);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setMinimumSize(QSize(110, 45));
        clearButton->setMaximumSize(QSize(160, 45));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        clearButton->setFont(font6);
        clearButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius:15px;border:none; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #00a6ac; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: white;  \n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"	border-image: url(:/image/close2.png);\n"
"}\n"
"\n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227"
                        "\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #55ff7f;\n"
"}\n"
" \n"
"QPushButton:checked:pressed { /* QPushButton\345\244\204\344\272\216\345\217\257\351\200\211\344\270\255\344\270\224\351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:disabled { /* QPushButton\347\246\201\347\224\250\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #CDCDCD;\n"
"	background-color: #CDCDCD;\n"
"	color: #B4B4B4;\n"
"}"));

        horizontalLayout_7->addWidget(clearButton);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(120, 45));
        pushButton->setMaximumSize(QSize(160, 45));
        pushButton->setFont(font6);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius:15px;border:none; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #00a6ac; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: white;  \n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"	border-image: url(:/image/close2.png);\n"
"}\n"
"\n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227"
                        "\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #55ff7f;\n"
"}\n"
" \n"
"QPushButton:checked:pressed { /* QPushButton\345\244\204\344\272\216\345\217\257\351\200\211\344\270\255\344\270\224\351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:disabled { /* QPushButton\347\246\201\347\224\250\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #CDCDCD;\n"
"	background-color: #CDCDCD;\n"
"	color: #B4B4B4;\n"
"}"));

        horizontalLayout_7->addWidget(pushButton);

        horizontalLayout_7->setStretch(1, 1);

        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        widget_7 = new QWidget(tab_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(360, 0));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: #00a6ac;"));
        gridLayout = new QGridLayout(widget_7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_ViewA_2 = new QPushButton(widget_7);
        Button_ViewA_2->setObjectName(QString::fromUtf8("Button_ViewA_2"));
        sizePolicy.setHeightForWidth(Button_ViewA_2->sizePolicy().hasHeightForWidth());
        Button_ViewA_2->setSizePolicy(sizePolicy);
        Button_ViewA_2->setMinimumSize(QSize(0, 40));
        Button_ViewA_2->setMaximumSize(QSize(16777215, 45));
        Button_ViewA_2->setFont(font6);
        Button_ViewA_2->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"border-radius:15px;\n"
"background-color: rgb(0, 131, 197);"));

        horizontalLayout->addWidget(Button_ViewA_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(15);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LiftD100 = new QPushButton(widget_7);
        LiftD100->setObjectName(QString::fromUtf8("LiftD100"));
        sizePolicy.setHeightForWidth(LiftD100->sizePolicy().hasHeightForWidth());
        LiftD100->setSizePolicy(sizePolicy);
        LiftD100->setFont(font6);
        LiftD100->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_11->addWidget(LiftD100);

        LiftD101 = new QPushButton(widget_7);
        LiftD101->setObjectName(QString::fromUtf8("LiftD101"));
        sizePolicy.setHeightForWidth(LiftD101->sizePolicy().hasHeightForWidth());
        LiftD101->setSizePolicy(sizePolicy);
        LiftD101->setFont(font6);
        LiftD101->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_11->addWidget(LiftD101);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(15);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        LiftD102 = new QPushButton(widget_7);
        LiftD102->setObjectName(QString::fromUtf8("LiftD102"));
        sizePolicy.setHeightForWidth(LiftD102->sizePolicy().hasHeightForWidth());
        LiftD102->setSizePolicy(sizePolicy);
        LiftD102->setFont(font6);
        LiftD102->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_16->addWidget(LiftD102);

        LiftD103 = new QPushButton(widget_7);
        LiftD103->setObjectName(QString::fromUtf8("LiftD103"));
        sizePolicy.setHeightForWidth(LiftD103->sizePolicy().hasHeightForWidth());
        LiftD103->setSizePolicy(sizePolicy);
        LiftD103->setFont(font6);
        LiftD103->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_16->addWidget(LiftD103);


        verticalLayout_7->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(15);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        LiftD104 = new QPushButton(widget_7);
        LiftD104->setObjectName(QString::fromUtf8("LiftD104"));
        sizePolicy.setHeightForWidth(LiftD104->sizePolicy().hasHeightForWidth());
        LiftD104->setSizePolicy(sizePolicy);
        LiftD104->setFont(font6);
        LiftD104->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_18->addWidget(LiftD104);

        LiftD105 = new QPushButton(widget_7);
        LiftD105->setObjectName(QString::fromUtf8("LiftD105"));
        sizePolicy.setHeightForWidth(LiftD105->sizePolicy().hasHeightForWidth());
        LiftD105->setSizePolicy(sizePolicy);
        LiftD105->setFont(font6);
        LiftD105->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: #00a6ac;"));

        horizontalLayout_18->addWidget(LiftD105);


        verticalLayout_7->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(15);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        button_5FOUT = new QPushButton(widget_7);
        button_5FOUT->setObjectName(QString::fromUtf8("button_5FOUT"));
        sizePolicy.setHeightForWidth(button_5FOUT->sizePolicy().hasHeightForWidth());
        button_5FOUT->setSizePolicy(sizePolicy);
        button_5FOUT->setFont(font6);
        button_5FOUT->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: #00a6ac;"));

        horizontalLayout_19->addWidget(button_5FOUT);

        button_5FIN = new QPushButton(widget_7);
        button_5FIN->setObjectName(QString::fromUtf8("button_5FIN"));
        sizePolicy.setHeightForWidth(button_5FIN->sizePolicy().hasHeightForWidth());
        button_5FIN->setSizePolicy(sizePolicy);
        button_5FIN->setFont(font6);
        button_5FIN->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: #00a6ac;"));

        horizontalLayout_19->addWidget(button_5FIN);


        verticalLayout_7->addLayout(horizontalLayout_19);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1);
        verticalLayout_7->setStretch(2, 1);
        verticalLayout_7->setStretch(3, 1);

        verticalLayout->addLayout(verticalLayout_7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(widget_7);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 10);

        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(DeviceManage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DeviceManage);
    } // setupUi

    void retranslateUi(QWidget *DeviceManage)
    {
        DeviceManage->setWindowTitle(QApplication::translate("DeviceManage", "Form", nullptr));
        label_7->setText(QApplication::translate("DeviceManage", "\345\215\207\351\231\215\346\234\272IP:", nullptr));
        label_9->setText(QApplication::translate("DeviceManage", "\345\275\223\345\211\215\346\245\274\345\261\202:", nullptr));
        label_8->setText(QApplication::translate("DeviceManage", "\347\263\273\347\273\237\346\214\207\344\273\244:", nullptr));
        label_10->setText(QApplication::translate("DeviceManage", "\345\274\202\345\270\270\344\277\241\346\201\257:", nullptr));
        label_4->setText(QApplication::translate("DeviceManage", "\345\212\250\344\275\234\346\214\207\344\273\244:", nullptr));
        taskTypeBox_Lift->setItemText(0, QApplication::translate("DeviceManage", "\346\270\205\351\231\244\346\214\207\344\273\244", nullptr));
        taskTypeBox_Lift->setItemText(1, QApplication::translate("DeviceManage", "2F-->3F", nullptr));
        taskTypeBox_Lift->setItemText(2, QApplication::translate("DeviceManage", "3F-->2F", nullptr));
        taskTypeBox_Lift->setItemText(3, QApplication::translate("DeviceManage", "2F-->4F", nullptr));
        taskTypeBox_Lift->setItemText(4, QApplication::translate("DeviceManage", "4F-->2F", nullptr));

        Sure_Button_Lift->setText(QApplication::translate("DeviceManage", "\347\241\256\345\256\232", nullptr));
#ifndef QT_NO_TOOLTIP
        tabletTextEdit->setToolTip(QApplication::translate("DeviceManage", "<html><head/><body><p><span style=\" color:#2aa198;\">(IN-&gt;1\345\217\257\346\224\276\346\226\231;2,3\347\233\256\346\240\207\346\245\274\345\261\202\342\200\224\342\200\224OUT--&gt;1\345\217\257\345\217\226\346\226\231,0\347\251\272\351\227\262)</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabletTextEdit->setHtml(QApplication::translate("DeviceManage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:16pt;\"><br /></p></body></html>", nullptr));
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
        ___qtablewidgetitem5->setText(QApplication::translate("DeviceManage", "\344\273\273\345\212\241\345\272\217\345\210\227\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DeviceManage", "\345\256\271\345\231\250\347\274\226\347\240\201", nullptr));
        checkBox_Edite->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("DeviceManage", "<html><head/><body><p>\345\210\240\351\231\244\344\273\273\345\212\241\345\215\240\347\224\250</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QApplication::translate("DeviceManage", "\346\270\205\351\231\244", nullptr));
        pushButton->setText(QApplication::translate("DeviceManage", "\351\242\204\347\225\231", nullptr));
        Button_ViewA_2->setText(QApplication::translate("DeviceManage", " \345\215\207\351\231\215\346\234\272\347\212\266\346\200\201 ", nullptr));
        LiftD100->setText(QApplication::translate("DeviceManage", "2F-\345\205\245\346\226\231", nullptr));
        LiftD101->setText(QApplication::translate("DeviceManage", "2F-\345\207\272\346\226\231", nullptr));
        LiftD102->setText(QApplication::translate("DeviceManage", "3F-\345\207\272\346\226\231", nullptr));
        LiftD103->setText(QApplication::translate("DeviceManage", "3F-\345\205\245\346\226\231", nullptr));
        LiftD104->setText(QApplication::translate("DeviceManage", "4F-\345\207\272\346\226\231", nullptr));
        LiftD105->setText(QApplication::translate("DeviceManage", "4F-\345\205\245\346\226\231", nullptr));
        button_5FOUT->setText(QApplication::translate("DeviceManage", "\351\242\204\347\225\231", nullptr));
        button_5FIN->setText(QApplication::translate("DeviceManage", "\351\242\204\347\225\231", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DeviceManage", "\345\215\207\351\231\215\346\234\272\351\203\250\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceManage: public Ui_DeviceManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEMANAGE_H
