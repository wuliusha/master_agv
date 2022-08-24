/********************************************************************************
** Form generated from reading UI file 'dailyrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAILYRECORD_H
#define UI_DAILYRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dailyRecord
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *qdebug_log;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *stop_Button;
    QPushButton *clear_Button;
    QWidget *tab_2;

    void setupUi(QWidget *dailyRecord)
    {
        if (dailyRecord->objectName().isEmpty())
            dailyRecord->setObjectName(QString::fromUtf8("dailyRecord"));
        dailyRecord->resize(1238, 601);
        gridLayout_2 = new QGridLayout(dailyRecord);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(dailyRecord);
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        qdebug_log = new QTextEdit(tab);
        qdebug_log->setObjectName(QString::fromUtf8("qdebug_log"));
        qdebug_log->setMaximumSize(QSize(16777215, 16778));
        QFont font1;
        font1.setPointSize(12);
        qdebug_log->setFont(font1);
        qdebug_log->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(33, 33, 33);"));

        verticalLayout_2->addWidget(qdebug_log);

        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 90, 100);"));
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stop_Button->sizePolicy().hasHeightForWidth());
        stop_Button->setSizePolicy(sizePolicy);
        stop_Button->setMinimumSize(QSize(100, 40));
        stop_Button->setMaximumSize(QSize(120, 40));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        stop_Button->setFont(font2);
        stop_Button->setStyleSheet(QString::fromUtf8("\n"
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

        horizontalLayout_3->addWidget(stop_Button);

        clear_Button = new QPushButton(widget_4);
        clear_Button->setObjectName(QString::fromUtf8("clear_Button"));
        sizePolicy.setHeightForWidth(clear_Button->sizePolicy().hasHeightForWidth());
        clear_Button->setSizePolicy(sizePolicy);
        clear_Button->setMinimumSize(QSize(100, 40));
        clear_Button->setMaximumSize(QSize(120, 40));
        clear_Button->setFont(font2);
        clear_Button->setStyleSheet(QString::fromUtf8("\n"
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

        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(dailyRecord);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dailyRecord);
    } // setupUi

    void retranslateUi(QWidget *dailyRecord)
    {
        dailyRecord->setWindowTitle(QApplication::translate("dailyRecord", "Form", nullptr));
        stop_Button->setText(QApplication::translate("dailyRecord", "\345\220\257\345\212\250", nullptr));
        clear_Button->setText(QApplication::translate("dailyRecord", "\346\270\205\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("dailyRecord", "\347\263\273\347\273\237\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class dailyRecord: public Ui_dailyRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYRECORD_H
