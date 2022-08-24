/****************************************************************************
** Meta object code from reading C++ file 'stationitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Device/stationitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stationitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_stationItem_t {
    QByteArrayData data[22];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_stationItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_stationItem_t qt_meta_stringdata_stationItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "stationItem"
QT_MOC_LITERAL(1, 12, 15), // "ON_stationTimer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(4, 48, 3), // "row"
QT_MOC_LITERAL(5, 52, 6), // "column"
QT_MOC_LITERAL(6, 59, 20), // "ON_stationItemStatus"
QT_MOC_LITERAL(7, 80, 8), // "DeviceIP"
QT_MOC_LITERAL(8, 89, 11), // "ActionArray"
QT_MOC_LITERAL(9, 101, 21), // "ON_DeviceStatusAction"
QT_MOC_LITERAL(10, 123, 10), // "deviceType"
QT_MOC_LITERAL(11, 134, 9), // "orderType"
QT_MOC_LITERAL(12, 144, 6), // "Action"
QT_MOC_LITERAL(13, 151, 15), // "ON_DeviceStatus"
QT_MOC_LITERAL(14, 167, 10), // "deviceDesc"
QT_MOC_LITERAL(15, 178, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(16, 191, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(17, 205, 15), // "on_load_clicked"
QT_MOC_LITERAL(18, 221, 17), // "on_unload_clicked"
QT_MOC_LITERAL(19, 239, 16), // "on_reset_clicked"
QT_MOC_LITERAL(20, 256, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(21, 279, 21) // "on_pushButton_clicked"

    },
    "stationItem\0ON_stationTimer\0\0"
    "SlotsetCurrentItem\0row\0column\0"
    "ON_stationItemStatus\0DeviceIP\0ActionArray\0"
    "ON_DeviceStatusAction\0deviceType\0"
    "orderType\0Action\0ON_DeviceStatus\0"
    "deviceDesc\0SAPExcelInfo\0SAPExcelInfoI\0"
    "on_load_clicked\0on_unload_clicked\0"
    "on_reset_clicked\0on_clearButton_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stationItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    2,   65,    2, 0x0a /* Public */,
       6,    2,   70,    2, 0x0a /* Public */,
       9,    4,   75,    2, 0x0a /* Public */,
      13,    2,   84,    2, 0x0a /* Public */,
      17,    0,   89,    2, 0x08 /* Private */,
      18,    0,   90,    2, 0x08 /* Private */,
      19,    0,   91,    2, 0x08 /* Private */,
      20,    0,   92,    2, 0x08 /* Private */,
      21,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    7,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void stationItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<stationItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ON_stationTimer(); break;
        case 1: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ON_stationItemStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->ON_DeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->ON_DeviceStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SAPExcelInfo(*)>(_a[2]))); break;
        case 5: _t->on_load_clicked(); break;
        case 6: _t->on_unload_clicked(); break;
        case 7: _t->on_reset_clicked(); break;
        case 8: _t->on_clearButton_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject stationItem::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_stationItem.data,
    qt_meta_data_stationItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *stationItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stationItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_stationItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int stationItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
