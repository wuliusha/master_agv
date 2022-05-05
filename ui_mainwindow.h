/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *Desktop_Button;
    QToolButton *OutStore_Button;
    QToolButton *StoreInfo_Button;
    QToolButton *System_Button;
    QToolButton *logInfo_Button;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_UserNuber;
    QLabel *label_UserName;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1059, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_6 = new QGridLayout(page);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(175, 180, 219);\n"
"background-color: rgb(42, 92, 170);"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(30);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Desktop_Button = new QToolButton(widget_2);
        Desktop_Button->setObjectName(QString::fromUtf8("Desktop_Button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Desktop_Button->sizePolicy().hasHeightForWidth());
        Desktop_Button->setSizePolicy(sizePolicy);
        Desktop_Button->setMaximumSize(QSize(500, 300));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Desktop_Button->setFont(font);
        Desktop_Button->setStyleSheet(QString::fromUtf8("color:#ffffff;"));
        Desktop_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(Desktop_Button);

        OutStore_Button = new QToolButton(widget_2);
        OutStore_Button->setObjectName(QString::fromUtf8("OutStore_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OutStore_Button->sizePolicy().hasHeightForWidth());
        OutStore_Button->setSizePolicy(sizePolicy1);
        OutStore_Button->setMaximumSize(QSize(500, 300));
        OutStore_Button->setFont(font);
        OutStore_Button->setStyleSheet(QString::fromUtf8(""));
        OutStore_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        OutStore_Button->setAutoRaise(false);

        horizontalLayout_2->addWidget(OutStore_Button);

        StoreInfo_Button = new QToolButton(widget_2);
        StoreInfo_Button->setObjectName(QString::fromUtf8("StoreInfo_Button"));
        sizePolicy.setHeightForWidth(StoreInfo_Button->sizePolicy().hasHeightForWidth());
        StoreInfo_Button->setSizePolicy(sizePolicy);
        StoreInfo_Button->setMaximumSize(QSize(500, 300));

        horizontalLayout_2->addWidget(StoreInfo_Button);

        System_Button = new QToolButton(widget_2);
        System_Button->setObjectName(QString::fromUtf8("System_Button"));
        sizePolicy.setHeightForWidth(System_Button->sizePolicy().hasHeightForWidth());
        System_Button->setSizePolicy(sizePolicy);
        System_Button->setMaximumSize(QSize(500, 300));
        System_Button->setFont(font);
        System_Button->setStyleSheet(QString::fromUtf8(""));
        System_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(System_Button);

        logInfo_Button = new QToolButton(widget_2);
        logInfo_Button->setObjectName(QString::fromUtf8("logInfo_Button"));
        sizePolicy.setHeightForWidth(logInfo_Button->sizePolicy().hasHeightForWidth());
        logInfo_Button->setSizePolicy(sizePolicy);
        logInfo_Button->setMaximumSize(QSize(500, 300));
        logInfo_Button->setFont(font);
        logInfo_Button->setStyleSheet(QString::fromUtf8(""));
        logInfo_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(logInfo_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_UserNuber = new QLabel(widget_2);
        label_UserNuber->setObjectName(QString::fromUtf8("label_UserNuber"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        label_UserNuber->setFont(font1);
        label_UserNuber->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        verticalLayout->addWidget(label_UserNuber);

        label_UserName = new QLabel(widget_2);
        label_UserName->setObjectName(QString::fromUtf8("label_UserName"));
        label_UserName->setFont(font1);
        label_UserName->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        verticalLayout->addWidget(label_UserName);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 5);
        horizontalLayout_2->setStretch(6, 2);

        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        stackedWidget_2 = new QStackedWidget(page);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setEnabled(true);
        stackedWidget_2->setStyleSheet(QString::fromUtf8("border:1px;"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        stackedWidget_2->addWidget(page_3);

        verticalLayout_4->addWidget(stackedWidget_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 12);

        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1059, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Desktop_Button->setText(QString());
        OutStore_Button->setText(QString());
        StoreInfo_Button->setText(QString());
        System_Button->setText(QString());
        logInfo_Button->setText(QString());
        label_UserNuber->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_UserName->setText(QApplication::translate("MainWindow", "\345\267\245\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
