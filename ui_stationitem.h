/********************************************************************************
** Form generated from reading UI file 'stationitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONITEM_H
#define UI_STATIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stationItem
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *tabletTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QWidget *item_edit;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *item_s;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *cageId;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Info_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_Info;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_22;
    QLabel *sensor_1;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_24;
    QLabel *sensor_2;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_23;
    QLabel *sensor_3;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *load;
    QPushButton *unload;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *load_;
    QPushButton *unload_;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *enable;
    QPushButton *reset;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_Edite;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QPushButton *clearButton;

    void setupUi(QWidget *stationItem)
    {
        if (stationItem->objectName().isEmpty())
            stationItem->setObjectName(QString::fromUtf8("stationItem"));
        stationItem->resize(1311, 808);
        stationItem->setMinimumSize(QSize(260, 260));
        stationItem->setMaximumSize(QSize(18000, 18000));
        stationItem->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(stationItem);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 11);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(stationItem);
        if (tableWidget->columnCount() < 14)
            tableWidget->setColumnCount(14);
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
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(tableWidget);

        widget = new QWidget(stationItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 70));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 5, 0, 5);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tabletTextEdit = new QTextEdit(widget);
        tabletTextEdit->setObjectName(QString::fromUtf8("tabletTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabletTextEdit->sizePolicy().hasHeightForWidth());
        tabletTextEdit->setSizePolicy(sizePolicy);
        tabletTextEdit->setMinimumSize(QSize(0, 65));
        tabletTextEdit->setMaximumSize(QSize(16777215, 200));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        tabletTextEdit->setFont(font1);
        tabletTextEdit->setStyleSheet(QString::fromUtf8("color: white;  \n"
"background-color: rgb(255, 170, 127);"));

        horizontalLayout_5->addWidget(tabletTextEdit);

        horizontalLayout_5->setStretch(0, 10);

        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        item_edit = new QWidget(stationItem);
        item_edit->setObjectName(QString::fromUtf8("item_edit"));
        item_edit->setMinimumSize(QSize(200, 100));
        item_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(97, 97, 97);"));
        gridLayout_3 = new QGridLayout(item_edit);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        item_s = new QWidget(item_edit);
        item_s->setObjectName(QString::fromUtf8("item_s"));
        item_s->setMinimumSize(QSize(320, 260));
        item_s->setMaximumSize(QSize(360, 360));
        item_s->setStyleSheet(QString::fromUtf8("background-color: rgb(112, 161, 159);\n"
""));
        gridLayout = new QGridLayout(item_s);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        cageId = new QLabel(item_s);
        cageId->setObjectName(QString::fromUtf8("cageId"));
        cageId->setMinimumSize(QSize(100, 70));
        cageId->setMaximumSize(QSize(100, 126));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        cageId->setFont(font2);
        cageId->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 170, 166);"));
        cageId->setScaledContents(true);
        cageId->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(cageId);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_Info_4 = new QLabel(item_s);
        label_Info_4->setObjectName(QString::fromUtf8("label_Info_4"));
        label_Info_4->setMinimumSize(QSize(0, 35));
        label_Info_4->setMaximumSize(QSize(16777215, 45));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_Info_4->setFont(font3);
        label_Info_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_Info_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_Info_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Info = new QLabel(item_s);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setMaximumSize(QSize(16777215, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_Info->setFont(font4);
        label_Info->setStyleSheet(QString::fromUtf8("border-radius:5px;background-color: rgb(170, 255, 127);\n"
""));
        label_Info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Info);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(20);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, -1, 5, -1);
        label_22 = new QLabel(item_s);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(70, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font5.setPointSize(11);
        label_22->setFont(font5);
        label_22->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_19->addWidget(label_22);

        sensor_1 = new QLabel(item_s);
        sensor_1->setObjectName(QString::fromUtf8("sensor_1"));
        sensor_1->setMinimumSize(QSize(30, 30));
        sensor_1->setMaximumSize(QSize(30, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font6.setPointSize(12);
        sensor_1->setFont(font6);
        sensor_1->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(sensor_1);


        horizontalLayout_16->addLayout(horizontalLayout_19);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(-1, -1, 5, -1);
        label_24 = new QLabel(item_s);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(70, 0));
        label_24->setFont(font5);
        label_24->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_28->addWidget(label_24);

        sensor_2 = new QLabel(item_s);
        sensor_2->setObjectName(QString::fromUtf8("sensor_2"));
        sensor_2->setMinimumSize(QSize(30, 30));
        sensor_2->setMaximumSize(QSize(30, 30));
        sensor_2->setFont(font6);
        sensor_2->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_28->addWidget(sensor_2);


        horizontalLayout_16->addLayout(horizontalLayout_28);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(-1, -1, 5, -1);
        label_23 = new QLabel(item_s);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(70, 0));
        label_23->setFont(font5);
        label_23->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_20->addWidget(label_23);

        sensor_3 = new QLabel(item_s);
        sensor_3->setObjectName(QString::fromUtf8("sensor_3"));
        sensor_3->setMinimumSize(QSize(30, 30));
        sensor_3->setMaximumSize(QSize(30, 30));
        sensor_3->setFont(font6);
        sensor_3->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_20->addWidget(sensor_3);


        horizontalLayout_16->addLayout(horizontalLayout_20);

        horizontalLayout_16->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(20);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        load = new QPushButton(item_s);
        load->setObjectName(QString::fromUtf8("load"));
        sizePolicy.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy);
        load->setMinimumSize(QSize(0, 30));
        load->setFont(font4);
        load->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius:15px;border:none; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF;  \n"
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
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346"
                        "\227\266\347\232\204\347\212\266\346\200\201 */\n"
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

        horizontalLayout_29->addWidget(load);

        unload = new QPushButton(item_s);
        unload->setObjectName(QString::fromUtf8("unload"));
        unload->setEnabled(true);
        sizePolicy.setHeightForWidth(unload->sizePolicy().hasHeightForWidth());
        unload->setSizePolicy(sizePolicy);
        unload->setMinimumSize(QSize(0, 30));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        unload->setFont(font7);
        unload->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266"
                        "\347\232\204\347\212\266\346\200\201 */\n"
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
"}\n"
""));

        horizontalLayout_29->addWidget(unload);

        horizontalLayout_29->setStretch(0, 1);
        horizontalLayout_29->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_29);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        load_ = new QPushButton(item_s);
        load_->setObjectName(QString::fromUtf8("load_"));
        load_->setEnabled(true);
        sizePolicy.setHeightForWidth(load_->sizePolicy().hasHeightForWidth());
        load_->setSizePolicy(sizePolicy);
        load_->setMinimumSize(QSize(0, 30));
        load_->setFont(font4);
        load_->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266"
                        "\347\232\204\347\212\266\346\200\201 */\n"
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
"}\n"
""));

        horizontalLayout_4->addWidget(load_);

        unload_ = new QPushButton(item_s);
        unload_->setObjectName(QString::fromUtf8("unload_"));
        sizePolicy.setHeightForWidth(unload_->sizePolicy().hasHeightForWidth());
        unload_->setSizePolicy(sizePolicy);
        unload_->setMinimumSize(QSize(0, 30));
        unload_->setFont(font4);
        unload_->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266"
                        "\347\232\204\347\212\266\346\200\201 */\n"
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
"}\n"
""));

        horizontalLayout_4->addWidget(unload_);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(20);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        enable = new QPushButton(item_s);
        enable->setObjectName(QString::fromUtf8("enable"));
        sizePolicy.setHeightForWidth(enable->sizePolicy().hasHeightForWidth());
        enable->setSizePolicy(sizePolicy);
        enable->setMinimumSize(QSize(0, 30));
        enable->setFont(font4);
        enable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266"
                        "\347\232\204\347\212\266\346\200\201 */\n"
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
"}\n"
""));

        horizontalLayout_30->addWidget(enable);

        reset = new QPushButton(item_s);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setMinimumSize(QSize(0, 30));
        reset->setFont(font4);
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #298DFF; /* QPushButton\350\276\271\346\241\206\347\232\204\345\256\275\345\272\246\343\200\201\346\240\267\345\274\217\345\222\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #298DFF; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
" \n"
"QPushButton:hover {	/* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QPushButton\344\270\212\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #298DFF;\n"
"	color: #F2F2F2;\n"
"}\n"
" \n"
"QPushButton:checked { /* QPushButton\345\217\257\351\200\211\344\270\255\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #FF5242;\n"
"	background-color: #F2F2F2;\n"
"	color: #FF5242;\n"
"}\n"
" \n"
"QPushButton:pressed { /* \351\274\240\346\240\207\346\214\211\345\216\213\345\234\250QPushButton\344\270\212\346\227\266"
                        "\347\232\204\347\212\266\346\200\201 */\n"
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
"}\n"
""));

        horizontalLayout_30->addWidget(reset);

        horizontalLayout_30->setStretch(0, 1);
        horizontalLayout_30->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_30);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 5);

        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 5);

        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(item_s);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_2 = new QWidget(item_edit);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 200));

        verticalLayout_6->addWidget(widget_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        checkBox_Edite = new QCheckBox(item_edit);
        checkBox_Edite->setObjectName(QString::fromUtf8("checkBox_Edite"));
        sizePolicy.setHeightForWidth(checkBox_Edite->sizePolicy().hasHeightForWidth());
        checkBox_Edite->setSizePolicy(sizePolicy);
        checkBox_Edite->setMaximumSize(QSize(36, 36));
        QFont font8;
        font8.setPointSize(16);
        checkBox_Edite->setFont(font8);
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
        pushButton = new QPushButton(item_edit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(160, 45));
        pushButton->setMaximumSize(QSize(180, 45));
        QFont font9;
        font9.setPointSize(16);
        font9.setBold(true);
        font9.setWeight(75);
        pushButton->setFont(font9);
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

        clearButton = new QPushButton(item_edit);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setMinimumSize(QSize(160, 45));
        clearButton->setMaximumSize(QSize(160, 45));
        clearButton->setFont(font9);
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

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(horizontalLayout_8);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout);

        verticalLayout_6->setStretch(0, 5);
        verticalLayout_6->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);

        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(item_edit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(stationItem);

        QMetaObject::connectSlotsByName(stationItem);
    } // setupUi

    void retranslateUi(QWidget *stationItem)
    {
        stationItem->setWindowTitle(QApplication::translate("stationItem", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("stationItem", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("stationItem", "\346\216\245\351\251\263\345\217\260IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("stationItem", "\346\216\245\351\251\263\345\217\260\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("stationItem", "\346\216\245\351\251\263\345\217\260\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("stationItem", "\344\275\277\350\203\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("stationItem", "\346\230\257\345\220\246\347\246\273\347\272\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("stationItem", "\346\234\211\346\227\240\346\226\231\346\241\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("stationItem", "\347\253\231\347\202\271\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("stationItem", "\347\253\231\347\202\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("stationItem", "\347\253\231\347\202\271\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("stationItem", "\345\257\271\345\272\224\347\202\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("stationItem", "\345\257\271\345\272\224\347\202\271\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("stationItem", "\345\272\217\345\210\227\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("stationItem", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
#ifndef QT_NO_TOOLTIP
        tabletTextEdit->setToolTip(QApplication::translate("stationItem", "<html><head/><body><p><span style=\" color:#2aa198;\">(IN-&gt;1\345\217\257\346\224\276\346\226\231;2,3\347\233\256\346\240\207\346\245\274\345\261\202\342\200\224\342\200\224OUT--&gt;1\345\217\257\345\217\226\346\226\231,0\347\251\272\351\227\262)</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabletTextEdit->setHtml(QApplication::translate("stationItem", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        cageId->setText(QString());
        label_Info_4->setText(QApplication::translate("stationItem", "\346\216\245\351\251\263\345\217\260", nullptr));
        label_Info->setText(QString());
        label_22->setText(QApplication::translate("stationItem", " \345\205\211\347\224\2651", nullptr));
        sensor_1->setText(QString());
        label_24->setText(QApplication::translate("stationItem", " \345\205\211\347\224\2652", nullptr));
        sensor_2->setText(QString());
        label_23->setText(QApplication::translate("stationItem", "\345\205\211\347\224\2653", nullptr));
        sensor_3->setText(QString());
        load->setText(QApplication::translate("stationItem", "\344\270\212\346\226\231", nullptr));
        unload->setText(QApplication::translate("stationItem", "\345\215\270\346\226\231", nullptr));
        load_->setText(QApplication::translate("stationItem", "\351\242\204\347\225\231", nullptr));
        unload_->setText(QApplication::translate("stationItem", "\351\242\204\347\225\231", nullptr));
        enable->setText(QApplication::translate("stationItem", "\344\275\277\350\203\275", nullptr));
        reset->setText(QApplication::translate("stationItem", "\345\244\215\344\275\215", nullptr));
        checkBox_Edite->setText(QString());
        pushButton->setText(QApplication::translate("stationItem", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("stationItem", "<html><head/><body><p>\345\210\240\351\231\244\344\273\273\345\212\241\345\215\240\347\224\250</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QApplication::translate("stationItem", "\346\270\205\351\231\244\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stationItem: public Ui_stationItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONITEM_H
