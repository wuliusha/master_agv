/********************************************************************************
** Form generated from reading UI file 'chartview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTVIEW_H
#define UI_CHARTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartView
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_13;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label_finishcount;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *label_DN_count;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QLabel *label_SL_count;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_17;
    QLabel *label_LM_count;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QLabel *label_Other_count;
    QLabel *label_allcount;

    void setupUi(QWidget *ChartView)
    {
        if (ChartView->objectName().isEmpty())
            ChartView->setObjectName(QString::fromUtf8("ChartView"));
        ChartView->resize(609, 336);
        layoutWidget = new QWidget(ChartView);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 310, 527, 26));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(20, 0));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(20, 0));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 229, 0);"));

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_2->addWidget(label_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(20, 0));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        horizontalLayout_7->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_7->addWidget(label_10);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 3);

        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(7);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(20, 0));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

        horizontalLayout_8->addWidget(label_12);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_8->addWidget(label_16);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);

        horizontalLayout_10->addLayout(horizontalLayout_8);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(20, 0));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));

        horizontalLayout_10->addWidget(label_11);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_10->addWidget(label_13);

        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 3);

        horizontalLayout_9->addLayout(horizontalLayout_10);

        horizontalLayout_9->setStretch(0, 2);
        horizontalLayout_9->setStretch(1, 2);
        horizontalLayout_9->setStretch(2, 2);
        horizontalLayout_9->setStretch(3, 2);
        layoutWidget1 = new QWidget(ChartView);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(420, 120, 141, 175));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(20, 0));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));

        horizontalLayout_3->addWidget(label_5);

        label_finishcount = new QLabel(layoutWidget1);
        label_finishcount->setObjectName(QString::fromUtf8("label_finishcount"));
        label_finishcount->setFont(font);
        label_finishcount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_3->addWidget(label_finishcount);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(20, 0));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 229, 0);"));

        horizontalLayout_4->addWidget(label_6);

        label_DN_count = new QLabel(layoutWidget1);
        label_DN_count->setObjectName(QString::fromUtf8("label_DN_count"));
        label_DN_count->setFont(font);
        label_DN_count->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_4->addWidget(label_DN_count);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(20, 0));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        horizontalLayout_5->addWidget(label_14);

        label_SL_count = new QLabel(layoutWidget1);
        label_SL_count->setObjectName(QString::fromUtf8("label_SL_count"));
        label_SL_count->setFont(font);
        label_SL_count->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(label_SL_count);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(20, 0));
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

        horizontalLayout_11->addWidget(label_17);

        label_LM_count = new QLabel(layoutWidget1);
        label_LM_count->setObjectName(QString::fromUtf8("label_LM_count"));
        label_LM_count->setFont(font);
        label_LM_count->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_11->addWidget(label_LM_count);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(20, 0));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));

        horizontalLayout_6->addWidget(label_15);

        label_Other_count = new QLabel(layoutWidget1);
        label_Other_count->setObjectName(QString::fromUtf8("label_Other_count"));
        label_Other_count->setFont(font);
        label_Other_count->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_6->addWidget(label_Other_count);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_6);

        label_allcount = new QLabel(layoutWidget1);
        label_allcount->setObjectName(QString::fromUtf8("label_allcount"));
        label_allcount->setFont(font);
        label_allcount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        verticalLayout->addWidget(label_allcount);


        retranslateUi(ChartView);

        QMetaObject::connectSlotsByName(ChartView);
    } // setupUi

    void retranslateUi(QWidget *ChartView)
    {
        ChartView->setWindowTitle(QApplication::translate("ChartView", "Form", nullptr));
        label_3->setText(QString());
        label->setText(QApplication::translate("ChartView", "\345\267\262\345\256\214\346\210\220", nullptr));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("ChartView", "\345\276\205\345\217\221DN", nullptr));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("ChartView", "\345\276\205\345\217\221SL", nullptr));
        label_12->setText(QString());
        label_16->setText(QApplication::translate("ChartView", "\345\276\205\345\217\221LM", nullptr));
        label_11->setText(QString());
        label_13->setText(QApplication::translate("ChartView", "\345\276\205\345\217\221Other", nullptr));
        label_5->setText(QString());
        label_finishcount->setText(QString());
        label_6->setText(QString());
        label_DN_count->setText(QString());
        label_14->setText(QString());
        label_SL_count->setText(QString());
        label_17->setText(QString());
        label_LM_count->setText(QString());
        label_15->setText(QString());
        label_Other_count->setText(QString());
        label_allcount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartView: public Ui_ChartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTVIEW_H
