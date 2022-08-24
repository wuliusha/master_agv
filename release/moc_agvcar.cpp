/****************************************************************************
** Meta object code from reading C++ file 'agvcar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../agvCar/agvcar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agvcar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_agvCar_t {
    QByteArrayData data[31];
    char stringdata0[411];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_agvCar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_agvCar_t qt_meta_stringdata_agvCar = {
    {
QT_MOC_LITERAL(0, 0, 6), // "agvCar"
QT_MOC_LITERAL(1, 7, 11), // "AGVMoveTask"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "StartQRPoint"
QT_MOC_LITERAL(4, 33, 10), // "EndQRPoint"
QT_MOC_LITERAL(5, 44, 9), // "AGVAction"
QT_MOC_LITERAL(6, 54, 3), // "tye"
QT_MOC_LITERAL(7, 58, 12), // "agvORderTask"
QT_MOC_LITERAL(8, 71, 13), // "agvORderTaskI"
QT_MOC_LITERAL(9, 85, 14), // "AgvStateWidget"
QT_MOC_LITERAL(10, 100, 8), // "agvState"
QT_MOC_LITERAL(11, 109, 13), // "agvStateItem1"
QT_MOC_LITERAL(12, 123, 13), // "AGVChargeTask"
QT_MOC_LITERAL(13, 137, 5), // "AGVIP"
QT_MOC_LITERAL(14, 143, 11), // "opendcharge"
QT_MOC_LITERAL(15, 155, 20), // "sigDoorSubTaskAction"
QT_MOC_LITERAL(16, 176, 6), // "doorIP"
QT_MOC_LITERAL(17, 183, 10), // "doorAction"
QT_MOC_LITERAL(18, 194, 19), // "TaskmoveListProcess"
QT_MOC_LITERAL(19, 214, 20), // "QMap<int,agvSubTask>"
QT_MOC_LITERAL(20, 235, 12), // "TaskmoveList"
QT_MOC_LITERAL(21, 248, 12), // "agvStateItem"
QT_MOC_LITERAL(22, 261, 10), // "Initaction"
QT_MOC_LITERAL(23, 272, 11), // "onReadyRead"
QT_MOC_LITERAL(24, 284, 20), // "onAddAGVTaskTimerOut"
QT_MOC_LITERAL(25, 305, 21), // "onSendAGVTaskTimerOut"
QT_MOC_LITERAL(26, 327, 21), // "onReadAGVTaskTimerOut"
QT_MOC_LITERAL(27, 349, 13), // "onAGVMoveTask"
QT_MOC_LITERAL(28, 363, 9), // "chargetye"
QT_MOC_LITERAL(29, 373, 20), // "ONUPdataTimer_Widget"
QT_MOC_LITERAL(30, 394, 16) // "ON_AGVChargeTask"

    },
    "agvCar\0AGVMoveTask\0\0StartQRPoint\0"
    "EndQRPoint\0AGVAction\0tye\0agvORderTask\0"
    "agvORderTaskI\0AgvStateWidget\0agvState\0"
    "agvStateItem1\0AGVChargeTask\0AGVIP\0"
    "opendcharge\0sigDoorSubTaskAction\0"
    "doorIP\0doorAction\0TaskmoveListProcess\0"
    "QMap<int,agvSubTask>\0TaskmoveList\0"
    "agvStateItem\0Initaction\0onReadyRead\0"
    "onAddAGVTaskTimerOut\0onSendAGVTaskTimerOut\0"
    "onReadAGVTaskTimerOut\0onAGVMoveTask\0"
    "chargetye\0ONUPdataTimer_Widget\0"
    "ON_AGVChargeTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_agvCar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   74,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,
      12,    2,   88,    2, 0x06 /* Public */,
      15,    3,   93,    2, 0x06 /* Public */,
      18,    4,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  109,    2, 0x0a /* Public */,
      24,    0,  110,    2, 0x0a /* Public */,
      25,    0,  111,    2, 0x0a /* Public */,
      26,    0,  112,    2, 0x0a /* Public */,
      27,    5,  113,    2, 0x0a /* Public */,
      29,    0,  124,    2, 0x0a /* Public */,
      30,    2,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,    6,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   16,   17,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19, 0x80000000 | 10, QMetaType::Int,   13,   20,   21,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,   28,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   13,   14,

       0        // eod
};

void agvCar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<agvCar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AGVMoveTask((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< agvORderTask(*)>(_a[5]))); break;
        case 1: _t->AgvStateWidget((*reinterpret_cast< agvState(*)>(_a[1]))); break;
        case 2: _t->AGVChargeTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 3: _t->sigDoorSubTaskAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->TaskmoveListProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<int,agvSubTask>(*)>(_a[2])),(*reinterpret_cast< agvState(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->onAddAGVTaskTimerOut(); break;
        case 7: _t->onSendAGVTaskTimerOut(); break;
        case 8: _t->onReadAGVTaskTimerOut(); break;
        case 9: _t->onAGVMoveTask((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< agvORderTask(*)>(_a[5]))); break;
        case 10: _t->ONUPdataTimer_Widget(); break;
        case 11: _t->ON_AGVChargeTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (agvCar::*)(quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCar::AGVMoveTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (agvCar::*)(agvState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCar::AgvStateWidget)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (agvCar::*)(QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCar::AGVChargeTask)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (agvCar::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCar::sigDoorSubTaskAction)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (agvCar::*)(QString , QMap<int,agvSubTask> , agvState , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCar::TaskmoveListProcess)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject agvCar::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_agvCar.data,
    qt_meta_data_agvCar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *agvCar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *agvCar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_agvCar.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int agvCar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void agvCar::AGVMoveTask(quint32 _t1, quint32 _t2, int _t3, int _t4, agvORderTask _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void agvCar::AgvStateWidget(agvState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void agvCar::AGVChargeTask(QString _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void agvCar::sigDoorSubTaskAction(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void agvCar::TaskmoveListProcess(QString _t1, QMap<int,agvSubTask> _t2, agvState _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
