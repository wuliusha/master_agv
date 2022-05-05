/****************************************************************************
** Meta object code from reading C++ file 'agvitemwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Monitoring/project/agvitemwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agvitemwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgvItemWidget_t {
    QByteArrayData data[61];
    char stringdata0[1240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgvItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgvItemWidget_t qt_meta_stringdata_AgvItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AgvItemWidget"
QT_MOC_LITERAL(1, 14, 14), // "sigAGVMoveTask"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "AGVIP"
QT_MOC_LITERAL(4, 36, 12), // "StartQRPoint"
QT_MOC_LITERAL(5, 49, 10), // "EndQRPoint"
QT_MOC_LITERAL(6, 60, 9), // "AGVAction"
QT_MOC_LITERAL(7, 70, 3), // "tye"
QT_MOC_LITERAL(8, 74, 12), // "agvORderTask"
QT_MOC_LITERAL(9, 87, 13), // "agvORderTaskI"
QT_MOC_LITERAL(10, 101, 14), // "newAGVMoveTask"
QT_MOC_LITERAL(11, 116, 8), // "taskType"
QT_MOC_LITERAL(12, 125, 14), // "AGVCurrentTask"
QT_MOC_LITERAL(13, 140, 15), // "AGVCurrentTaskI"
QT_MOC_LITERAL(14, 156, 12), // "ON_ItemTimer"
QT_MOC_LITERAL(15, 169, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(16, 188, 3), // "row"
QT_MOC_LITERAL(17, 192, 6), // "column"
QT_MOC_LITERAL(18, 199, 20), // "SlotsetCurrentItem_2"
QT_MOC_LITERAL(19, 220, 20), // "SlotsetCurrentItem_3"
QT_MOC_LITERAL(20, 241, 20), // "SlotsetCurrentItem_4"
QT_MOC_LITERAL(21, 262, 20), // "SlotsetCurrentItem_5"
QT_MOC_LITERAL(22, 283, 24), // "on_detail_Button_clicked"
QT_MOC_LITERAL(23, 308, 21), // "on_AgvExecute_clicked"
QT_MOC_LITERAL(24, 330, 23), // "on_CancelButton_clicked"
QT_MOC_LITERAL(25, 354, 20), // "on_task_sure_clicked"
QT_MOC_LITERAL(26, 375, 22), // "on_task_cancel_clicked"
QT_MOC_LITERAL(27, 398, 23), // "on_query_Button_clicked"
QT_MOC_LITERAL(28, 422, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(29, 443, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(30, 467, 21), // "on_addButton__clicked"
QT_MOC_LITERAL(31, 489, 24), // "on_deleteButton__clicked"
QT_MOC_LITERAL(32, 514, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(33, 538, 22), // "on_AlterButton_clicked"
QT_MOC_LITERAL(34, 561, 25), // "on_query_Button_2_clicked"
QT_MOC_LITERAL(35, 587, 25), // "on_addButton_Info_clicked"
QT_MOC_LITERAL(36, 613, 28), // "on_deleteButton_Info_clicked"
QT_MOC_LITERAL(37, 642, 25), // "on_updateButton_2_clicked"
QT_MOC_LITERAL(38, 668, 25), // "on_query_Button_3_clicked"
QT_MOC_LITERAL(39, 694, 27), // "on_addButton_Info_2_clicked"
QT_MOC_LITERAL(40, 722, 30), // "on_deleteButton_Info_2_clicked"
QT_MOC_LITERAL(41, 753, 25), // "on_updateButton_3_clicked"
QT_MOC_LITERAL(42, 779, 25), // "on_query_Button_4_clicked"
QT_MOC_LITERAL(43, 805, 27), // "on_addButton_Info_4_clicked"
QT_MOC_LITERAL(44, 833, 30), // "on_deleteButton_Info_4_clicked"
QT_MOC_LITERAL(45, 864, 25), // "on_updateButton_5_clicked"
QT_MOC_LITERAL(46, 890, 29), // "on_query_Button_agvip_clicked"
QT_MOC_LITERAL(47, 920, 26), // "on_addButton_agvip_clicked"
QT_MOC_LITERAL(48, 947, 29), // "on_deleteButton_agvip_clicked"
QT_MOC_LITERAL(49, 977, 29), // "on_updateButton_agvip_clicked"
QT_MOC_LITERAL(50, 1007, 10), // "ON_Pressed"
QT_MOC_LITERAL(51, 1018, 11), // "ON_Released"
QT_MOC_LITERAL(52, 1030, 25), // "on_treeWidget_itemClicked"
QT_MOC_LITERAL(53, 1056, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(54, 1073, 4), // "item"
QT_MOC_LITERAL(55, 1078, 36), // "on_station_statrt_currentText..."
QT_MOC_LITERAL(56, 1115, 4), // "arg1"
QT_MOC_LITERAL(57, 1120, 34), // "on_station_dest_currentTextCh..."
QT_MOC_LITERAL(58, 1155, 36), // "on_taskstation_IP_currentText..."
QT_MOC_LITERAL(59, 1192, 23), // "on_start_charge_clicked"
QT_MOC_LITERAL(60, 1216, 23) // "on_close_charge_clicked"

    },
    "AgvItemWidget\0sigAGVMoveTask\0\0AGVIP\0"
    "StartQRPoint\0EndQRPoint\0AGVAction\0tye\0"
    "agvORderTask\0agvORderTaskI\0newAGVMoveTask\0"
    "taskType\0AGVCurrentTask\0AGVCurrentTaskI\0"
    "ON_ItemTimer\0SlotsetCurrentItem\0row\0"
    "column\0SlotsetCurrentItem_2\0"
    "SlotsetCurrentItem_3\0SlotsetCurrentItem_4\0"
    "SlotsetCurrentItem_5\0on_detail_Button_clicked\0"
    "on_AgvExecute_clicked\0on_CancelButton_clicked\0"
    "on_task_sure_clicked\0on_task_cancel_clicked\0"
    "on_query_Button_clicked\0on_addButton_clicked\0"
    "on_deleteButton_clicked\0on_addButton__clicked\0"
    "on_deleteButton__clicked\0"
    "on_updateButton_clicked\0on_AlterButton_clicked\0"
    "on_query_Button_2_clicked\0"
    "on_addButton_Info_clicked\0"
    "on_deleteButton_Info_clicked\0"
    "on_updateButton_2_clicked\0"
    "on_query_Button_3_clicked\0"
    "on_addButton_Info_2_clicked\0"
    "on_deleteButton_Info_2_clicked\0"
    "on_updateButton_3_clicked\0"
    "on_query_Button_4_clicked\0"
    "on_addButton_Info_4_clicked\0"
    "on_deleteButton_Info_4_clicked\0"
    "on_updateButton_5_clicked\0"
    "on_query_Button_agvip_clicked\0"
    "on_addButton_agvip_clicked\0"
    "on_deleteButton_agvip_clicked\0"
    "on_updateButton_agvip_clicked\0ON_Pressed\0"
    "ON_Released\0on_treeWidget_itemClicked\0"
    "QTreeWidgetItem*\0item\0"
    "on_station_statrt_currentTextChanged\0"
    "arg1\0on_station_dest_currentTextChanged\0"
    "on_taskstation_IP_currentTextChanged\0"
    "on_start_charge_clicked\0on_close_charge_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgvItemWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,  234,    2, 0x06 /* Public */,
      10,    3,  247,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  254,    2, 0x0a /* Public */,
      15,    2,  255,    2, 0x0a /* Public */,
      18,    2,  260,    2, 0x0a /* Public */,
      19,    2,  265,    2, 0x0a /* Public */,
      20,    2,  270,    2, 0x0a /* Public */,
      21,    2,  275,    2, 0x0a /* Public */,
      22,    0,  280,    2, 0x08 /* Private */,
      23,    0,  281,    2, 0x08 /* Private */,
      24,    0,  282,    2, 0x08 /* Private */,
      25,    0,  283,    2, 0x08 /* Private */,
      26,    0,  284,    2, 0x08 /* Private */,
      27,    0,  285,    2, 0x08 /* Private */,
      28,    0,  286,    2, 0x08 /* Private */,
      29,    0,  287,    2, 0x08 /* Private */,
      30,    0,  288,    2, 0x08 /* Private */,
      31,    0,  289,    2, 0x08 /* Private */,
      32,    0,  290,    2, 0x08 /* Private */,
      33,    0,  291,    2, 0x08 /* Private */,
      34,    0,  292,    2, 0x08 /* Private */,
      35,    0,  293,    2, 0x08 /* Private */,
      36,    0,  294,    2, 0x08 /* Private */,
      37,    0,  295,    2, 0x08 /* Private */,
      38,    0,  296,    2, 0x08 /* Private */,
      39,    0,  297,    2, 0x08 /* Private */,
      40,    0,  298,    2, 0x08 /* Private */,
      41,    0,  299,    2, 0x08 /* Private */,
      42,    0,  300,    2, 0x08 /* Private */,
      43,    0,  301,    2, 0x08 /* Private */,
      44,    0,  302,    2, 0x08 /* Private */,
      45,    0,  303,    2, 0x08 /* Private */,
      46,    0,  304,    2, 0x08 /* Private */,
      47,    0,  305,    2, 0x08 /* Private */,
      48,    0,  306,    2, 0x08 /* Private */,
      49,    0,  307,    2, 0x08 /* Private */,
      50,    0,  308,    2, 0x08 /* Private */,
      51,    0,  309,    2, 0x08 /* Private */,
      52,    2,  310,    2, 0x08 /* Private */,
      55,    1,  315,    2, 0x08 /* Private */,
      57,    1,  318,    2, 0x08 /* Private */,
      58,    1,  321,    2, 0x08 /* Private */,
      59,    0,  324,    2, 0x08 /* Private */,
      60,    0,  325,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    3,    4,    5,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 12,    3,   11,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53, QMetaType::Int,   54,   17,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AgvItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AgvItemWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 1: _t->newAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< AGVCurrentTask(*)>(_a[3]))); break;
        case 2: _t->ON_ItemTimer(); break;
        case 3: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->SlotsetCurrentItem_2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SlotsetCurrentItem_3((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SlotsetCurrentItem_4((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->SlotsetCurrentItem_5((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_detail_Button_clicked(); break;
        case 9: _t->on_AgvExecute_clicked(); break;
        case 10: _t->on_CancelButton_clicked(); break;
        case 11: _t->on_task_sure_clicked(); break;
        case 12: _t->on_task_cancel_clicked(); break;
        case 13: _t->on_query_Button_clicked(); break;
        case 14: _t->on_addButton_clicked(); break;
        case 15: _t->on_deleteButton_clicked(); break;
        case 16: _t->on_addButton__clicked(); break;
        case 17: _t->on_deleteButton__clicked(); break;
        case 18: _t->on_updateButton_clicked(); break;
        case 19: _t->on_AlterButton_clicked(); break;
        case 20: _t->on_query_Button_2_clicked(); break;
        case 21: _t->on_addButton_Info_clicked(); break;
        case 22: _t->on_deleteButton_Info_clicked(); break;
        case 23: _t->on_updateButton_2_clicked(); break;
        case 24: _t->on_query_Button_3_clicked(); break;
        case 25: _t->on_addButton_Info_2_clicked(); break;
        case 26: _t->on_deleteButton_Info_2_clicked(); break;
        case 27: _t->on_updateButton_3_clicked(); break;
        case 28: _t->on_query_Button_4_clicked(); break;
        case 29: _t->on_addButton_Info_4_clicked(); break;
        case 30: _t->on_deleteButton_Info_4_clicked(); break;
        case 31: _t->on_updateButton_5_clicked(); break;
        case 32: _t->on_query_Button_agvip_clicked(); break;
        case 33: _t->on_addButton_agvip_clicked(); break;
        case 34: _t->on_deleteButton_agvip_clicked(); break;
        case 35: _t->on_updateButton_agvip_clicked(); break;
        case 36: _t->ON_Pressed(); break;
        case 37: _t->ON_Released(); break;
        case 38: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->on_station_statrt_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_station_dest_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->on_taskstation_IP_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_start_charge_clicked(); break;
        case 43: _t->on_close_charge_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AgvItemWidget::*)(QString , quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgvItemWidget::sigAGVMoveTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AgvItemWidget::*)(QString , QString , AGVCurrentTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AgvItemWidget::newAGVMoveTask)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AgvItemWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AgvItemWidget.data,
    qt_meta_data_AgvItemWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AgvItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgvItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AgvItemWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AgvItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void AgvItemWidget::sigAGVMoveTask(QString _t1, quint32 _t2, quint32 _t3, int _t4, int _t5, agvORderTask _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AgvItemWidget::newAGVMoveTask(QString _t1, QString _t2, AGVCurrentTask _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
