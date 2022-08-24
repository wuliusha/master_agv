/********************************************************************************
** Form generated from reading UI file 'AgvStatus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGVSTATUS_H
#define UI_AGVSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgvStatus
{
public:
    QGridLayout *gridLayout;
    QTableWidget *agvShow;

    void setupUi(QWidget *AgvStatus)
    {
        if (AgvStatus->objectName().isEmpty())
            AgvStatus->setObjectName(QString::fromUtf8("AgvStatus"));
        AgvStatus->resize(1416, 526);
        gridLayout = new QGridLayout(AgvStatus);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        agvShow = new QTableWidget(AgvStatus);
        if (agvShow->columnCount() < 15)
            agvShow->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        agvShow->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        if (agvShow->rowCount() < 10)
            agvShow->setRowCount(10);
        agvShow->setObjectName(QString::fromUtf8("agvShow"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(agvShow->sizePolicy().hasHeightForWidth());
        agvShow->setSizePolicy(sizePolicy);
        agvShow->setSizeIncrement(QSize(0, 0));
        QFont font;
        agvShow->setFont(font);
        agvShow->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        agvShow->setMouseTracking(false);
        agvShow->setFocusPolicy(Qt::NoFocus);
        agvShow->setContextMenuPolicy(Qt::NoContextMenu);
        agvShow->setLayoutDirection(Qt::LeftToRight);
        agvShow->setAutoFillBackground(true);
        agvShow->setStyleSheet(QString::fromUtf8("QHeaderView::section:vertical\n"
"{\n"
"    border-left: 1px solid #fffff8;\n"
"}\n"
"QWidget {\n"
"    background-color:#afdfe4\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color:rgba(25,25,25,25);\n"
"    padding: 4px;\n"
"    border: 1px solid #282828;\n"
"    font-size: 14px;\n"
"}\n"
""));
        agvShow->setFrameShape(QFrame::WinPanel);
        agvShow->setLineWidth(1);
        agvShow->setMidLineWidth(0);
        agvShow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        agvShow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        agvShow->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        agvShow->setAutoScrollMargin(12);
        agvShow->setEditTriggers(QAbstractItemView::NoEditTriggers);
        agvShow->setTabKeyNavigation(false);
        agvShow->setProperty("showDropIndicator", QVariant(false));
        agvShow->setDragDropOverwriteMode(false);
        agvShow->setSelectionMode(QAbstractItemView::NoSelection);
        agvShow->setSelectionBehavior(QAbstractItemView::SelectRows);
        agvShow->setTextElideMode(Qt::ElideMiddle);
        agvShow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        agvShow->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        agvShow->setShowGrid(false);
        agvShow->setGridStyle(Qt::DashLine);
        agvShow->setCornerButtonEnabled(false);
        agvShow->setRowCount(10);
        agvShow->setColumnCount(15);
        agvShow->horizontalHeader()->setCascadingSectionResizes(true);
        agvShow->horizontalHeader()->setMinimumSectionSize(50);
        agvShow->horizontalHeader()->setDefaultSectionSize(92);
        agvShow->verticalHeader()->setVisible(false);
        agvShow->verticalHeader()->setCascadingSectionResizes(true);
        agvShow->verticalHeader()->setMinimumSectionSize(40);
        agvShow->verticalHeader()->setDefaultSectionSize(40);
        agvShow->verticalHeader()->setHighlightSections(true);

        gridLayout->addWidget(agvShow, 0, 0, 1, 1);


        retranslateUi(AgvStatus);

        QMetaObject::connectSlotsByName(AgvStatus);
    } // setupUi

    void retranslateUi(QWidget *AgvStatus)
    {
        AgvStatus->setWindowTitle(QApplication::translate("AgvStatus", "AGV STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem = agvShow->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AgvStatus", "AGVIP", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = agvShow->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AgvStatus", "\344\272\214\347\273\264\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = agvShow->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AgvStatus", "X\345\201\217\347\247\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = agvShow->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AgvStatus", "Y\345\201\217\347\247\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = agvShow->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AgvStatus", "\345\247\277\346\200\201\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = agvShow->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("AgvStatus", "\350\275\254\347\233\230\350\247\222\345\272\246-\351\253\230\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = agvShow->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("AgvStatus", "\347\247\273\345\212\250\350\247\222\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = agvShow->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("AgvStatus", "\350\275\254\347\233\230\344\270\212\351\231\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = agvShow->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("AgvStatus", "\350\275\254\347\233\230\344\270\213\351\231\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = agvShow->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("AgvStatus", "\344\273\273\345\212\241\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = agvShow->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("AgvStatus", "\345\275\223\345\211\215\347\224\265\345\216\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = agvShow->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("AgvStatus", "\351\224\231\350\257\257\344\273\243\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = agvShow->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("AgvStatus", "          \345\270\247\347\274\226\347\240\201         ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = agvShow->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("AgvStatus", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = agvShow->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("AgvStatus", "\346\214\207\344\273\244\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgvStatus: public Ui_AgvStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGVSTATUS_H
