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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *lab_Ico;
    QPushButton *btn_log;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMax;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_Edite;
    QPushButton *btn_Device;
    QPushButton *btn_System;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_6;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1169, 603);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 55));
        widget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(71, 71, 71);"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(11, -1, 11, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lab_Ico = new QPushButton(widget);
        lab_Ico->setObjectName(QString::fromUtf8("lab_Ico"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab_Ico->sizePolicy().hasHeightForWidth());
        lab_Ico->setSizePolicy(sizePolicy);
        lab_Ico->setMinimumSize(QSize(40, 30));
        lab_Ico->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lab_Ico);

        btn_log = new QPushButton(widget);
        btn_log->setObjectName(QString::fromUtf8("btn_log"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_log->sizePolicy().hasHeightForWidth());
        btn_log->setSizePolicy(sizePolicy1);
        btn_log->setMinimumSize(QSize(40, 30));

        horizontalLayout_2->addWidget(btn_log);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        btnMax = new QPushButton(widget);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        QFont font;
        font.setPointSize(18);
        btnMax->setFont(font);
        btnMax->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(btnMax);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_Edite = new QPushButton(widget);
        btn_Edite->setObjectName(QString::fromUtf8("btn_Edite"));
        sizePolicy1.setHeightForWidth(btn_Edite->sizePolicy().hasHeightForWidth());
        btn_Edite->setSizePolicy(sizePolicy1);
        btn_Edite->setMinimumSize(QSize(40, 30));

        horizontalLayout->addWidget(btn_Edite);

        btn_Device = new QPushButton(widget);
        btn_Device->setObjectName(QString::fromUtf8("btn_Device"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_Device->sizePolicy().hasHeightForWidth());
        btn_Device->setSizePolicy(sizePolicy2);
        btn_Device->setMinimumSize(QSize(31, 0));
        btn_Device->setCursor(QCursor(Qt::ArrowCursor));
        btn_Device->setFocusPolicy(Qt::NoFocus);
        btn_Device->setStyleSheet(QString::fromUtf8(""));
        btn_Device->setFlat(true);

        horizontalLayout->addWidget(btn_Device);

        btn_System = new QPushButton(widget);
        btn_System->setObjectName(QString::fromUtf8("btn_System"));
        sizePolicy1.setHeightForWidth(btn_System->sizePolicy().hasHeightForWidth());
        btn_System->setSizePolicy(sizePolicy1);
        btn_System->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btn_System);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 1);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(2, 10);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(600, 300));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_6 = new QGridLayout(page);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 50);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1169, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        lab_Ico->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\344\270\273\351\241\265</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        lab_Ico->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_log->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\347\263\273\347\273\237\346\227\245\345\277\227\344\273\245\345\217\212\346\216\245\345\217\243\346\265\213\350\257\225\347\225\214\351\235\242</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        btn_log->setText(QString());
        btnMax->setText(QApplication::translate("MainWindow", "\346\231\272\350\203\275\344\273\223\345\202\250\347\263\273\347\273\237\347\225\214\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        btn_Edite->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\350\217\234\345\215\225\346\240\217</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        btn_Edite->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_Device->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\350\256\276\345\244\207\347\256\241\347\220\206</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        btn_Device->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_System->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\347\263\273\347\273\237\350\256\276\347\275\256</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        btn_System->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
