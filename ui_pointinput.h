/********************************************************************************
** Form generated from reading UI file 'pointinput.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTINPUT_H
#define UI_POINTINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointInput
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_41;
    QSpacerItem *horizontalSpacer_23;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_24;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_47;
    QComboBox *floorNum;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_46;
    QComboBox *coordinate;
    QHBoxLayout *horizontalLayout_90;
    QLabel *label_53;
    QLineEdit *space;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *pointEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *xEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *yEdit;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *insertButton;
    QPushButton *UPButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *PointInput)
    {
        if (PointInput->objectName().isEmpty())
            PointInput->setObjectName(QString::fromUtf8("PointInput"));
        PointInput->resize(803, 322);
        PointInput->setMinimumSize(QSize(325, 185));
        PointInput->setMaximumSize(QSize(16666, 1000));
        PointInput->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 214, 218);"));
        gridLayout = new QGridLayout(PointInput);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 11, 30, 11);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_23);

        label_22 = new QLabel(PointInput);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(0, 40));
        label_22->setMaximumSize(QSize(16777215, 45));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color:#ffffff"));

        horizontalLayout_41->addWidget(label_22);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_24);


        verticalLayout_4->addLayout(horizontalLayout_41);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(5);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_47 = new QLabel(PointInput);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_47->setFont(font1);
        label_47->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_15->addWidget(label_47);

        floorNum = new QComboBox(PointInput);
        floorNum->addItem(QString());
        floorNum->addItem(QString());
        floorNum->addItem(QString());
        floorNum->addItem(QString());
        floorNum->addItem(QString());
        floorNum->addItem(QString());
        floorNum->setObjectName(QString::fromUtf8("floorNum"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(floorNum->sizePolicy().hasHeightForWidth());
        floorNum->setSizePolicy(sizePolicy);
        floorNum->setMinimumSize(QSize(120, 35));
        floorNum->setMaximumSize(QSize(16777215, 40));
        floorNum->setFont(font);
        floorNum->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_15->addWidget(floorNum);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(5);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_46 = new QLabel(PointInput);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMaximumSize(QSize(16777215, 40));
        label_46->setFont(font1);
        label_46->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_14->addWidget(label_46);

        coordinate = new QComboBox(PointInput);
        coordinate->addItem(QString());
        coordinate->addItem(QString());
        coordinate->setObjectName(QString::fromUtf8("coordinate"));
        sizePolicy.setHeightForWidth(coordinate->sizePolicy().hasHeightForWidth());
        coordinate->setSizePolicy(sizePolicy);
        coordinate->setMinimumSize(QSize(120, 35));
        coordinate->setMaximumSize(QSize(16777215, 40));
        coordinate->setFont(font);
        coordinate->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(157, 144, 135);\n"
"QComboBox::drop-down {\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left-width: 1px;\n"
"    border-left-style: solid; \n"
"	border-left-color: gray;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}"));

        horizontalLayout_14->addWidget(coordinate);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_90 = new QHBoxLayout();
        horizontalLayout_90->setSpacing(5);
        horizontalLayout_90->setObjectName(QString::fromUtf8("horizontalLayout_90"));
        label_53 = new QLabel(PointInput);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setMaximumSize(QSize(16777215, 40));
        label_53->setFont(font1);
        label_53->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_90->addWidget(label_53);

        space = new QLineEdit(PointInput);
        space->setObjectName(QString::fromUtf8("space"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(space->sizePolicy().hasHeightForWidth());
        space->setSizePolicy(sizePolicy1);
        space->setMinimumSize(QSize(100, 0));
        space->setMaximumSize(QSize(16777215, 40));
        space->setFont(font1);
        space->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_90->addWidget(space);

        horizontalLayout_90->setStretch(0, 1);
        horizontalLayout_90->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_90);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(PointInput);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_3->addWidget(label_3);

        pointEdit = new QLineEdit(PointInput);
        pointEdit->setObjectName(QString::fromUtf8("pointEdit"));
        sizePolicy.setHeightForWidth(pointEdit->sizePolicy().hasHeightForWidth());
        pointEdit->setSizePolicy(sizePolicy);
        pointEdit->setMinimumSize(QSize(0, 30));
        pointEdit->setMaximumSize(QSize(16777215, 40));
        pointEdit->setFont(font1);
        pointEdit->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_3->addWidget(pointEdit);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PointInput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 40));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout->addWidget(label);

        xEdit = new QLineEdit(PointInput);
        xEdit->setObjectName(QString::fromUtf8("xEdit"));
        sizePolicy1.setHeightForWidth(xEdit->sizePolicy().hasHeightForWidth());
        xEdit->setSizePolicy(sizePolicy1);
        xEdit->setMinimumSize(QSize(0, 30));
        xEdit->setMaximumSize(QSize(16777215, 40));
        xEdit->setFont(font1);
        xEdit->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout->addWidget(xEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(PointInput);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:#ffffff;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_2->addWidget(label_2);

        yEdit = new QLineEdit(PointInput);
        yEdit->setObjectName(QString::fromUtf8("yEdit"));
        sizePolicy.setHeightForWidth(yEdit->sizePolicy().hasHeightForWidth());
        yEdit->setSizePolicy(sizePolicy);
        yEdit->setMinimumSize(QSize(0, 30));
        yEdit->setMaximumSize(QSize(16777215, 40));
        yEdit->setFont(font1);
        yEdit->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        horizontalLayout_2->addWidget(yEdit);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        insertButton = new QPushButton(PointInput);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        sizePolicy.setHeightForWidth(insertButton->sizePolicy().hasHeightForWidth());
        insertButton->setSizePolicy(sizePolicy);
        insertButton->setMaximumSize(QSize(16777215, 40));
        insertButton->setFont(font1);
        insertButton->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_4->addWidget(insertButton);

        UPButton = new QPushButton(PointInput);
        UPButton->setObjectName(QString::fromUtf8("UPButton"));
        sizePolicy.setHeightForWidth(UPButton->sizePolicy().hasHeightForWidth());
        UPButton->setSizePolicy(sizePolicy);
        UPButton->setMaximumSize(QSize(16777215, 40));
        UPButton->setFont(font1);
        UPButton->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_4->addWidget(UPButton);

        deleteButton = new QPushButton(PointInput);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMinimumSize(QSize(0, 35));
        deleteButton->setMaximumSize(QSize(16777215, 40));
        deleteButton->setFont(font1);
        deleteButton->setStyleSheet(QString::fromUtf8("color: white;  \n"
"border: 2px groove gray;\n"
"border-radius:15px;border:none;\n"
"background-color: rgb(0, 166, 172);"));

        horizontalLayout_4->addWidget(deleteButton);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        horizontalLayout_18->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_18);

        verticalLayout_3->setStretch(0, 5);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(PointInput);

        QMetaObject::connectSlotsByName(PointInput);
    } // setupUi

    void retranslateUi(QWidget *PointInput)
    {
        PointInput->setWindowTitle(QApplication::translate("PointInput", "\345\215\241\347\202\271\346\223\215\344\275\234", nullptr));
        label_22->setText(QApplication::translate("PointInput", "   \344\272\214\347\273\264\347\240\201\345\235\220\346\240\207\346\230\276\347\244\272\347\274\226\350\276\221\347\225\214\351\235\242   ", nullptr));
        label_47->setText(QApplication::translate("PointInput", "\346\230\276\347\244\272\346\245\274\345\261\202:", nullptr));
        floorNum->setItemText(0, QApplication::translate("PointInput", "1", nullptr));
        floorNum->setItemText(1, QApplication::translate("PointInput", "2", nullptr));
        floorNum->setItemText(2, QApplication::translate("PointInput", "3", nullptr));
        floorNum->setItemText(3, QApplication::translate("PointInput", "4", nullptr));
        floorNum->setItemText(4, QApplication::translate("PointInput", "5", nullptr));
        floorNum->setItemText(5, QApplication::translate("PointInput", "6", nullptr));

        label_46->setText(QApplication::translate("PointInput", "\351\200\222\345\242\236\346\226\271\345\220\221:", nullptr));
        coordinate->setItemText(0, QApplication::translate("PointInput", "X\346\226\271\345\220\221", nullptr));
        coordinate->setItemText(1, QApplication::translate("PointInput", "Y\346\226\271\345\220\221", nullptr));

        label_53->setText(QApplication::translate("PointInput", "\351\200\222\345\242\236\351\227\264\351\232\224:", nullptr));
        space->setText(QApplication::translate("PointInput", "0", nullptr));
        space->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("PointInput", "\345\275\223\345\211\215\345\215\241\345\217\267  \357\274\232", nullptr));
        pointEdit->setText(QString());
        label->setText(QApplication::translate("PointInput", "\345\275\223\345\211\215x\345\235\220\346\240\207 \357\274\232", nullptr));
        xEdit->setText(QApplication::translate("PointInput", "0", nullptr));
        label_2->setText(QApplication::translate("PointInput", "\345\275\223\345\211\215Y\345\235\220\346\240\207 \357\274\232", nullptr));
        yEdit->setText(QApplication::translate("PointInput", "0", nullptr));
        insertButton->setText(QApplication::translate("PointInput", "\346\267\273\345\212\240", nullptr));
        UPButton->setText(QApplication::translate("PointInput", "\346\233\264\346\226\260", nullptr));
        deleteButton->setText(QApplication::translate("PointInput", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointInput: public Ui_PointInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTINPUT_H
