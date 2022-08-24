/****************************************************************************
** Meta object code from reading C++ file 'system_agv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../system/system_agv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system_agv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_system_agv_t {
    QByteArrayData data[19];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_system_agv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_system_agv_t qt_meta_stringdata_system_agv = {
    {
QT_MOC_LITERAL(0, 0, 10), // "system_agv"
QT_MOC_LITERAL(1, 11, 22), // "on_query_agvip_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "on_add_agvip_clicked"
QT_MOC_LITERAL(4, 56, 23), // "on_delete_agvip_clicked"
QT_MOC_LITERAL(5, 80, 23), // "on_update_agvip_clicked"
QT_MOC_LITERAL(6, 104, 25), // "on_query_LineInfo_clicked"
QT_MOC_LITERAL(7, 130, 23), // "on_add_LineInfo_clicked"
QT_MOC_LITERAL(8, 154, 26), // "on_delete_LineInfo_clicked"
QT_MOC_LITERAL(9, 181, 26), // "on_update_LineInfo_clicked"
QT_MOC_LITERAL(10, 208, 25), // "on_Alter_LineInfo_clicked"
QT_MOC_LITERAL(11, 234, 21), // "on_query_rule_clicked"
QT_MOC_LITERAL(12, 256, 19), // "on_add_rule_clicked"
QT_MOC_LITERAL(13, 276, 22), // "on_delete_rule_clicked"
QT_MOC_LITERAL(14, 299, 21), // "on_add_rule_2_clicked"
QT_MOC_LITERAL(15, 321, 24), // "on_delete_rule_2_clicked"
QT_MOC_LITERAL(16, 346, 22), // "on_update_rule_clicked"
QT_MOC_LITERAL(17, 369, 10), // "ON_Pressed"
QT_MOC_LITERAL(18, 380, 11) // "ON_Released"

    },
    "system_agv\0on_query_agvip_clicked\0\0"
    "on_add_agvip_clicked\0on_delete_agvip_clicked\0"
    "on_update_agvip_clicked\0"
    "on_query_LineInfo_clicked\0"
    "on_add_LineInfo_clicked\0"
    "on_delete_LineInfo_clicked\0"
    "on_update_LineInfo_clicked\0"
    "on_Alter_LineInfo_clicked\0"
    "on_query_rule_clicked\0on_add_rule_clicked\0"
    "on_delete_rule_clicked\0on_add_rule_2_clicked\0"
    "on_delete_rule_2_clicked\0"
    "on_update_rule_clicked\0ON_Pressed\0"
    "ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_system_agv[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
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

       0        // eod
};

void system_agv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<system_agv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_query_agvip_clicked(); break;
        case 1: _t->on_add_agvip_clicked(); break;
        case 2: _t->on_delete_agvip_clicked(); break;
        case 3: _t->on_update_agvip_clicked(); break;
        case 4: _t->on_query_LineInfo_clicked(); break;
        case 5: _t->on_add_LineInfo_clicked(); break;
        case 6: _t->on_delete_LineInfo_clicked(); break;
        case 7: _t->on_update_LineInfo_clicked(); break;
        case 8: _t->on_Alter_LineInfo_clicked(); break;
        case 9: _t->on_query_rule_clicked(); break;
        case 10: _t->on_add_rule_clicked(); break;
        case 11: _t->on_delete_rule_clicked(); break;
        case 12: _t->on_add_rule_2_clicked(); break;
        case 13: _t->on_delete_rule_2_clicked(); break;
        case 14: _t->on_update_rule_clicked(); break;
        case 15: _t->ON_Pressed(); break;
        case 16: _t->ON_Released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject system_agv::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_system_agv.data,
    qt_meta_data_system_agv,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *system_agv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *system_agv::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_system_agv.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int system_agv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
