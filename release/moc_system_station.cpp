/****************************************************************************
** Meta object code from reading C++ file 'system_station.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../system/system_station.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'system_station.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_system_station_t {
    QByteArrayData data[11];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_system_station_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_system_station_t qt_meta_stringdata_system_station = {
    {
QT_MOC_LITERAL(0, 0, 14), // "system_station"
QT_MOC_LITERAL(1, 15, 26), // "SlotsetCurrentItem_station"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 3), // "row"
QT_MOC_LITERAL(4, 47, 6), // "column"
QT_MOC_LITERAL(5, 54, 24), // "on_query_station_clicked"
QT_MOC_LITERAL(6, 79, 22), // "on_add_station_clicked"
QT_MOC_LITERAL(7, 102, 25), // "on_delete_station_clicked"
QT_MOC_LITERAL(8, 128, 25), // "on_update_station_clicked"
QT_MOC_LITERAL(9, 154, 10), // "ON_Pressed"
QT_MOC_LITERAL(10, 165, 11) // "ON_Released"

    },
    "system_station\0SlotsetCurrentItem_station\0"
    "\0row\0column\0on_query_station_clicked\0"
    "on_add_station_clicked\0on_delete_station_clicked\0"
    "on_update_station_clicked\0ON_Pressed\0"
    "ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_system_station[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void system_station::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<system_station *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SlotsetCurrentItem_station((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_query_station_clicked(); break;
        case 2: _t->on_add_station_clicked(); break;
        case 3: _t->on_delete_station_clicked(); break;
        case 4: _t->on_update_station_clicked(); break;
        case 5: _t->ON_Pressed(); break;
        case 6: _t->ON_Released(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject system_station::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_system_station.data,
    qt_meta_data_system_station,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *system_station::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *system_station::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_system_station.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int system_station::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
