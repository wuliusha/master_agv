/****************************************************************************
** Meta object code from reading C++ file 'anomaly.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainDesktop/anomaly.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'anomaly.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Anomaly_t {
    QByteArrayData data[7];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Anomaly_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Anomaly_t qt_meta_stringdata_Anomaly = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Anomaly"
QT_MOC_LITERAL(1, 8, 10), // "updateGram"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "AnomalyTimer"
QT_MOC_LITERAL(4, 33, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(5, 52, 3), // "row"
QT_MOC_LITERAL(6, 56, 6) // "column"

    },
    "Anomaly\0updateGram\0\0AnomalyTimer\0"
    "SlotsetCurrentItem\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Anomaly[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    2,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

       0        // eod
};

void Anomaly::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Anomaly *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateGram(); break;
        case 1: _t->AnomalyTimer(); break;
        case 2: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Anomaly::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Anomaly.data,
    qt_meta_data_Anomaly,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Anomaly::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Anomaly::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Anomaly.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Anomaly::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
