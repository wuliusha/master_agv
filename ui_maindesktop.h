/********************************************************************************
** Form generated from reading UI file 'maindesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDESKTOP_H
#define UI_MAINDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDesktop
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_12;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *taskStatusBox_ESS;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *taskFnish_;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_Edite;
    QPushButton *Delete_Button;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_agv;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *taskStatusBox_AGV;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_Edite_2;
    QPushButton *Button_Init;
    QHBoxLayout *horizontalLayout_25;
    QWidget *widget_3;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *MainDesktop)
    {
        if (MainDesktop->objectName().isEmpty())
            MainDesktop->setObjectName(QString::fromUtf8("MainDesktop"));
        MainDesktop->resize(1168, 927);
        MainDesktop->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(MainDesktop);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(MainDesktop);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 300));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        stackedWidget->addWidget(page_12);

        verticalLayout->addWidget(stackedWidget);

        tabWidget = new QTabWidget(MainDesktop);
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
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 80));
        QFont font1;
        font1.setPointSize(14);
        tableWidget->setFont(font1);
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

        verticalLayout_3->addWidget(tableWidget);

        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 209, 203);"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(50);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        taskStatusBox_ESS = new QComboBox(widget);
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->addItem(QString());
        taskStatusBox_ESS->setObjectName(QString::fromUtf8("taskStatusBox_ESS"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(taskStatusBox_ESS->sizePolicy().hasHeightForWidth());
        taskStatusBox_ESS->setSizePolicy(sizePolicy);
        taskStatusBox_ESS->setMinimumSize(QSize(220, 35));
        taskStatusBox_ESS->setMaximumSize(QSize(16777215, 45));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        taskStatusBox_ESS->setFont(font2);
        taskStatusBox_ESS->setStyleSheet(QString::fromUtf8("color:#000000;\n"
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

        horizontalLayout_5->addWidget(taskStatusBox_ESS);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        taskFnish_ = new QPushButton(widget);
        taskFnish_->setObjectName(QString::fromUtf8("taskFnish_"));
        sizePolicy.setHeightForWidth(taskFnish_->sizePolicy().hasHeightForWidth());
        taskFnish_->setSizePolicy(sizePolicy);
        taskFnish_->setMinimumSize(QSize(160, 45));
        taskFnish_->setMaximumSize(QSize(160, 45));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        taskFnish_->setFont(font3);
        taskFnish_->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_5->addWidget(taskFnish_);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        checkBox_Edite = new QCheckBox(widget);
        checkBox_Edite->setObjectName(QString::fromUtf8("checkBox_Edite"));
        sizePolicy.setHeightForWidth(checkBox_Edite->sizePolicy().hasHeightForWidth());
        checkBox_Edite->setSizePolicy(sizePolicy);
        checkBox_Edite->setMaximumSize(QSize(36, 36));
        QFont font4;
        font4.setPointSize(16);
        checkBox_Edite->setFont(font4);
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
        Delete_Button->setMinimumSize(QSize(160, 45));
        Delete_Button->setMaximumSize(QSize(160, 45));
        Delete_Button->setFont(font3);
        Delete_Button->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_2->addWidget(Delete_Button);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 10);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);

        gridLayout_4->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString::fromUtf8("\344\270\232\345\212\241\344\273\273\345\212\241"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_agv = new QTableWidget(tab_2);
        if (tableWidget_agv->columnCount() < 15)
            tableWidget_agv->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(7, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(8, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(9, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(10, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(11, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(12, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(13, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_agv->setHorizontalHeaderItem(14, __qtablewidgetitem24);
        tableWidget_agv->setObjectName(QString::fromUtf8("tableWidget_agv"));
        tableWidget_agv->setFont(font1);
        tableWidget_agv->setFocusPolicy(Qt::NoFocus);
        tableWidget_agv->setStyleSheet(QString::fromUtf8(""));
        tableWidget_agv->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_agv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_agv->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_agv->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_agv->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_agv->setGridStyle(Qt::NoPen);
        tableWidget_agv->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_agv->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_agv->verticalHeader()->setMinimumSectionSize(30);
        tableWidget_agv->verticalHeader()->setHighlightSections(true);
        tableWidget_agv->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_agv->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(tableWidget_agv);

        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 209, 203);"));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        taskStatusBox_AGV = new QComboBox(widget_2);
        taskStatusBox_AGV->addItem(QString());
        taskStatusBox_AGV->addItem(QString());
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
        taskStatusBox_AGV->setFont(font2);
        taskStatusBox_AGV->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 166, 172);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_6->addWidget(taskStatusBox_AGV);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        checkBox_Edite_2 = new QCheckBox(widget_2);
        checkBox_Edite_2->setObjectName(QString::fromUtf8("checkBox_Edite_2"));
        sizePolicy.setHeightForWidth(checkBox_Edite_2->sizePolicy().hasHeightForWidth());
        checkBox_Edite_2->setSizePolicy(sizePolicy);
        checkBox_Edite_2->setMaximumSize(QSize(36, 36));
        checkBox_Edite_2->setFont(font4);
        checkBox_Edite_2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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

        horizontalLayout_3->addWidget(checkBox_Edite_2);

        Button_Init = new QPushButton(widget_2);
        Button_Init->setObjectName(QString::fromUtf8("Button_Init"));
        sizePolicy.setHeightForWidth(Button_Init->sizePolicy().hasHeightForWidth());
        Button_Init->setSizePolicy(sizePolicy);
        Button_Init->setMinimumSize(QSize(150, 45));
        Button_Init->setMaximumSize(QSize(160, 45));
        Button_Init->setFont(font3);
        Button_Init->setStyleSheet(QString::fromUtf8("color: white;\n"
"color:#ffffff;\n"
"border-radius:15px;\n"
"border-style: outset;\n"
"border: 2px groove gray; \n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_3->addWidget(Button_Init);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 10);
        horizontalLayout_6->setStretch(2, 1);

        gridLayout_5->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(10);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        widget_3 = new QWidget(MainDesktop);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(500, 0));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 15);"));
        gridLayout_6 = new QGridLayout(widget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(11, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 25));
        label_11->setMaximumSize(QSize(16777, 16777215));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_11->setFont(font5);
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setStyleSheet(QString::fromUtf8("\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(255, 255, 255);"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_11);

        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777, 16777215));
        label_12->setFont(font5);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 170, 166);\n"
"border-radius:15px;border:none;\n"
"\n"
""));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_12);

        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777, 16777215));
        label_13->setFont(font5);
        label_13->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85,255,127);\n"
"border-radius:15px;border:none;"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_13);

        label_14 = new QLabel(widget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777, 16777215));
        label_14->setFont(font5);
        label_14->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(118, 77, 57);\n"
"border-radius:15px;border:none;"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(label_14);


        horizontalLayout->addLayout(horizontalLayout_26);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout_6->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_25->addWidget(widget_3);


        verticalLayout_4->addLayout(horizontalLayout_25);

        verticalLayout_4->setStretch(0, 100);
        verticalLayout_4->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(MainDesktop);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDesktop);
    } // setupUi

    void retranslateUi(QWidget *MainDesktop)
    {
        MainDesktop->setWindowTitle(QApplication::translate("MainDesktop", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainDesktop", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainDesktop", "\350\203\266\347\256\261\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainDesktop", "\350\256\242\345\215\225\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainDesktop", "\347\240\201\345\244\264\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainDesktop", "\350\265\267\345\247\213\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainDesktop", "\347\233\256\346\240\207\347\253\231\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainDesktop", "\345\272\217\345\210\227\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainDesktop", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        taskStatusBox_ESS->setItemText(0, QApplication::translate("MainDesktop", "\344\273\273\345\212\241\346\214\207\344\273\244", nullptr));
        taskStatusBox_ESS->setItemText(1, QApplication::translate("MainDesktop", "\346\226\231\346\241\206\345\205\245\345\234\272", nullptr));
        taskStatusBox_ESS->setItemText(2, QApplication::translate("MainDesktop", "\346\226\231\346\241\206\347\246\273\345\234\272", nullptr));
        taskStatusBox_ESS->setItemText(3, QApplication::translate("MainDesktop", "\346\211\247\350\241\214\350\277\220\350\276\223\344\273\273\345\212\241_S", nullptr));
        taskStatusBox_ESS->setItemText(4, QApplication::translate("MainDesktop", "\345\211\215\345\276\200\347\233\256\346\240\207\346\245\274\345\261\202", nullptr));
        taskStatusBox_ESS->setItemText(5, QApplication::translate("MainDesktop", "\346\211\247\350\241\214\350\277\220\350\276\223\344\273\273\345\212\241_E", nullptr));
        taskStatusBox_ESS->setItemText(6, QApplication::translate("MainDesktop", "\344\273\273\345\212\241\345\256\214\346\210\220", nullptr));

        taskFnish_->setText(QApplication::translate("MainDesktop", "\346\255\243\345\270\270\345\256\214\346\210\220", nullptr));
        checkBox_Edite->setText(QString());
        Delete_Button->setText(QApplication::translate("MainDesktop", "\345\274\202\345\270\270\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_agv->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainDesktop", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_agv->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainDesktop", "AGVIP", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_agv->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainDesktop", "AGV\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_agv->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainDesktop", "AGV\346\245\274\345\261\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_agv->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainDesktop", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_agv->horizontalHeaderItem(5);
        ___qtablewidgetitem15->setText(QApplication::translate("MainDesktop", "\350\265\267\345\247\213\347\233\256\346\240\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_agv->horizontalHeaderItem(6);
        ___qtablewidgetitem16->setText(QApplication::translate("MainDesktop", "\347\273\210\347\202\271\347\233\256\346\240\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_agv->horizontalHeaderItem(7);
        ___qtablewidgetitem17->setText(QApplication::translate("MainDesktop", "\345\275\223\345\211\215\347\233\256\346\240\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_agv->horizontalHeaderItem(8);
        ___qtablewidgetitem18->setText(QApplication::translate("MainDesktop", "\344\273\273\345\212\241\346\214\207\344\273\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_agv->horizontalHeaderItem(9);
        ___qtablewidgetitem19->setText(QApplication::translate("MainDesktop", "\345\272\217\345\210\227\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_agv->horizontalHeaderItem(10);
        ___qtablewidgetitem20->setText(QApplication::translate("MainDesktop", "\345\275\223\345\211\215\344\273\273\345\212\241\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_agv->horizontalHeaderItem(11);
        ___qtablewidgetitem21->setText(QApplication::translate("MainDesktop", "\344\270\212\344\270\200\344\273\273\345\212\241\347\274\226\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_agv->horizontalHeaderItem(12);
        ___qtablewidgetitem22->setText(QApplication::translate("MainDesktop", "\345\205\205\347\224\265\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_agv->horizontalHeaderItem(13);
        ___qtablewidgetitem23->setText(QApplication::translate("MainDesktop", "\345\275\223\345\211\215\347\224\265\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_agv->horizontalHeaderItem(14);
        ___qtablewidgetitem24->setText(QApplication::translate("MainDesktop", "\345\274\202\345\270\270\344\277\241\346\201\257", nullptr));
        taskStatusBox_AGV->setItemText(0, QApplication::translate("MainDesktop", "AGV\350\277\220\350\276\223\346\214\207\344\273\244", nullptr));
        taskStatusBox_AGV->setItemText(1, QApplication::translate("MainDesktop", "\345\211\215\345\276\200\350\265\267\345\247\213\347\253\231\347\202\271", nullptr));
        taskStatusBox_AGV->setItemText(2, QApplication::translate("MainDesktop", "\346\211\247\350\241\214\344\270\276\345\215\207\345\212\250\344\275\234", nullptr));
        taskStatusBox_AGV->setItemText(3, QApplication::translate("MainDesktop", "\345\211\215\345\276\200\347\233\256\346\240\207\347\253\231\347\202\271", nullptr));
        taskStatusBox_AGV->setItemText(4, QApplication::translate("MainDesktop", "\346\211\247\350\241\214\344\270\213\351\231\215\345\212\250\344\275\234", nullptr));
        taskStatusBox_AGV->setItemText(5, QApplication::translate("MainDesktop", "\344\273\273\345\212\241\345\256\214\346\210\220", nullptr));
        taskStatusBox_AGV->setItemText(6, QApplication::translate("MainDesktop", "\344\273\273\345\212\241\345\217\226\346\266\210", nullptr));

        checkBox_Edite_2->setText(QString());
        Button_Init->setText(QApplication::translate("MainDesktop", "\345\210\235\345\247\213\345\214\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainDesktop", "\347\263\273\347\273\237\344\273\273\345\212\241", nullptr));
        label_11->setText(QApplication::translate("MainDesktop", "\347\251\272\351\227\262\347\212\266\346\200\201", nullptr));
        label_12->setText(QApplication::translate("MainDesktop", "\345\244\271\346\212\261\346\255\243\345\234\250\350\277\220\350\276\223", nullptr));
        label_13->setText(QApplication::translate("MainDesktop", "\351\200\211\344\270\255\344\273\273\345\212\241", nullptr));
        label_14->setText(QApplication::translate("MainDesktop", "\345\260\217AGV\346\255\243\345\234\250\350\277\220\350\276\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDesktop: public Ui_MainDesktop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDESKTOP_H
