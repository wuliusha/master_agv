/********************************************************************************
** Form generated from reading UI file 'dooritem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOORITEM_H
#define UI_DOORITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doorItem
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *cageId;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Info;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_22;
    QLabel *sensor_1;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_24;
    QLabel *sensor_2;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *enable_Button;
    QPushButton *reset_Button;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *forward_Button;
    QPushButton *late_Button;

    void setupUi(QWidget *doorItem)
    {
        if (doorItem->objectName().isEmpty())
            doorItem->setObjectName(QString::fromUtf8("doorItem"));
        doorItem->resize(272, 262);
        doorItem->setMinimumSize(QSize(260, 260));
        doorItem->setMaximumSize(QSize(272, 262));
        doorItem->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));
        gridLayout = new QGridLayout(doorItem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cageId = new QLabel(doorItem);
        cageId->setObjectName(QString::fromUtf8("cageId"));
        cageId->setMinimumSize(QSize(100, 70));
        cageId->setMaximumSize(QSize(100, 126));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        cageId->setFont(font);
        cageId->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 170, 166);"));
        cageId->setScaledContents(true);
        cageId->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cageId);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        label_Info = new QLabel(doorItem);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        label_Info->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(15);
        label_Info->setFont(font1);
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
        label_22 = new QLabel(doorItem);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(70, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(11);
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_19->addWidget(label_22);

        sensor_1 = new QLabel(doorItem);
        sensor_1->setObjectName(QString::fromUtf8("sensor_1"));
        sensor_1->setMinimumSize(QSize(30, 30));
        sensor_1->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(12);
        sensor_1->setFont(font3);
        sensor_1->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(sensor_1);


        horizontalLayout_16->addLayout(horizontalLayout_19);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(-1, -1, 5, -1);
        label_24 = new QLabel(doorItem);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMinimumSize(QSize(70, 0));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_28->addWidget(label_24);

        sensor_2 = new QLabel(doorItem);
        sensor_2->setObjectName(QString::fromUtf8("sensor_2"));
        sensor_2->setMinimumSize(QSize(30, 30));
        sensor_2->setMaximumSize(QSize(30, 30));
        sensor_2->setFont(font3);
        sensor_2->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150);\n"
"border-radius:15px;padding:15px 30px;"));
        sensor_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_28->addWidget(sensor_2);


        horizontalLayout_16->addLayout(horizontalLayout_28);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(20);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        enable_Button = new QPushButton(doorItem);
        enable_Button->setObjectName(QString::fromUtf8("enable_Button"));
        enable_Button->setFont(font3);
        enable_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_30->addWidget(enable_Button);

        reset_Button = new QPushButton(doorItem);
        reset_Button->setObjectName(QString::fromUtf8("reset_Button"));
        reset_Button->setFont(font3);
        reset_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 122, 41);\n"
"background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_30->addWidget(reset_Button);

        horizontalLayout_30->setStretch(0, 1);
        horizontalLayout_30->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_30);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(20);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        forward_Button = new QPushButton(doorItem);
        forward_Button->setObjectName(QString::fromUtf8("forward_Button"));
        forward_Button->setFont(font3);
        forward_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_29->addWidget(forward_Button);

        late_Button = new QPushButton(doorItem);
        late_Button->setObjectName(QString::fromUtf8("late_Button"));
        late_Button->setEnabled(true);
        late_Button->setFont(font3);
        late_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 122, 41);\n"
"background-color: rgb(255, 170, 127);\n"
"border-radius:5px;padding:5px 10px;"));

        horizontalLayout_29->addWidget(late_Button);

        horizontalLayout_29->setStretch(0, 1);
        horizontalLayout_29->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_29);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(doorItem);

        QMetaObject::connectSlotsByName(doorItem);
    } // setupUi

    void retranslateUi(QWidget *doorItem)
    {
        doorItem->setWindowTitle(QApplication::translate("doorItem", "Form", nullptr));
        cageId->setText(QString());
        label_Info->setText(QString());
        label_22->setText(QApplication::translate("doorItem", " \344\274\240\346\204\237\345\231\2501", nullptr));
        sensor_1->setText(QString());
        label_24->setText(QApplication::translate("doorItem", " \344\274\240\346\204\237\345\231\2502", nullptr));
        sensor_2->setText(QString());
        enable_Button->setText(QApplication::translate("doorItem", "\344\275\277\347\224\250", nullptr));
        reset_Button->setText(QApplication::translate("doorItem", "\345\244\215\344\275\215", nullptr));
        forward_Button->setText(QApplication::translate("doorItem", "\345\274\200\351\227\250", nullptr));
        late_Button->setText(QApplication::translate("doorItem", "\345\205\263\351\227\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doorItem: public Ui_doorItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOORITEM_H
