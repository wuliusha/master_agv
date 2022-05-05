/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_2;

    void setupUi(QWidget *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Histogram->resize(783, 336);
        layoutWidget = new QWidget(Histogram);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 310, 451, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(80);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
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
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

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
        horizontalLayout->setStretch(1, 5);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));

        horizontalLayout_2->addWidget(label_4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_2->addWidget(label_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QWidget *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Form", nullptr));
        label_3->setText(QString());
        label->setText(QApplication::translate("Histogram", "\345\217\221\346\226\231\346\225\260\351\207\217(Item)", nullptr));
        label_4->setText(QString());
        label_2->setText(QApplication::translate("Histogram", "\344\270\212\346\236\266\346\225\260\351\207\217(Item)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
