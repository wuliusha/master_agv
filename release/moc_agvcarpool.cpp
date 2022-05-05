/****************************************************************************
** Meta object code from reading C++ file 'agvcarpool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../agvCar/agvcarpool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agvcarpool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_agvCarPool_t {
    QByteArrayData data[31];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_agvCarPool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_agvCarPool_t qt_meta_stringdata_agvCarPool = {
    {
QT_MOC_LITERAL(0, 0, 10), // "agvCarPool"
QT_MOC_LITERAL(1, 11, 11), // "allAGVState"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "QList<agvState>"
QT_MOC_LITERAL(4, 40, 11), // "AGVMoveTask"
QT_MOC_LITERAL(5, 52, 5), // "AGVIP"
QT_MOC_LITERAL(6, 58, 12), // "StartQRPoint"
QT_MOC_LITERAL(7, 71, 10), // "EndQRPoint"
QT_MOC_LITERAL(8, 82, 9), // "AGVAction"
QT_MOC_LITERAL(9, 92, 3), // "tye"
QT_MOC_LITERAL(10, 96, 12), // "agvORderTask"
QT_MOC_LITERAL(11, 109, 13), // "agvORderTaskI"
QT_MOC_LITERAL(12, 123, 14), // "AgvStateWidget"
QT_MOC_LITERAL(13, 138, 8), // "agvState"
QT_MOC_LITERAL(14, 147, 13), // "agvStateItem1"
QT_MOC_LITERAL(15, 161, 20), // "sigDoorSubTaskAction"
QT_MOC_LITERAL(16, 182, 6), // "doorIP"
QT_MOC_LITERAL(17, 189, 10), // "doorAction"
QT_MOC_LITERAL(18, 200, 25), // "onAgvCarSocketDeleteLater"
QT_MOC_LITERAL(19, 226, 13), // "onAGVMoveTask"
QT_MOC_LITERAL(20, 240, 16), // "ON_AGVChargeTask"
QT_MOC_LITERAL(21, 257, 11), // "opendcharge"
QT_MOC_LITERAL(22, 269, 22), // "ON_TaskmoveListProcess"
QT_MOC_LITERAL(23, 292, 20), // "QMap<int,agvSubTask>"
QT_MOC_LITERAL(24, 313, 12), // "TaskmoveList"
QT_MOC_LITERAL(25, 326, 12), // "agvStateItem"
QT_MOC_LITERAL(26, 339, 10), // "Initaction"
QT_MOC_LITERAL(27, 350, 21), // "ON_Device_door_Status"
QT_MOC_LITERAL(28, 372, 8), // "DeviceIP"
QT_MOC_LITERAL(29, 381, 6), // "online"
QT_MOC_LITERAL(30, 388, 12) // "DeviceStatus"

    },
    "agvCarPool\0allAGVState\0\0QList<agvState>\0"
    "AGVMoveTask\0AGVIP\0StartQRPoint\0"
    "EndQRPoint\0AGVAction\0tye\0agvORderTask\0"
    "agvORderTaskI\0AgvStateWidget\0agvState\0"
    "agvStateItem1\0sigDoorSubTaskAction\0"
    "doorIP\0doorAction\0onAgvCarSocketDeleteLater\0"
    "onAGVMoveTask\0ON_AGVChargeTask\0"
    "opendcharge\0ON_TaskmoveListProcess\0"
    "QMap<int,agvSubTask>\0TaskmoveList\0"
    "agvStateItem\0Initaction\0ON_Device_door_Status\0"
    "DeviceIP\0online\0DeviceStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_agvCarPool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    6,   62,    2, 0x06 /* Public */,
      12,    1,   75,    2, 0x06 /* Public */,
      15,    3,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,   85,    2, 0x0a /* Public */,
      19,    6,   86,    2, 0x0a /* Public */,
      20,    2,   99,    2, 0x0a /* Public */,
      22,    4,  104,    2, 0x0a /* Public */,
      27,    3,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 10,    5,    6,    7,    8,    9,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   16,   17,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 10,    5,    6,    7,    8,    9,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    5,   21,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 23, 0x80000000 | 13, QMetaType::Int,    5,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   28,   29,   30,

       0        // eod
};

void agvCarPool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<agvCarPool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->allAGVState((*reinterpret_cast< QList<agvState>(*)>(_a[1]))); break;
        case 1: _t->AGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 2: _t->AgvStateWidget((*reinterpret_cast< agvState(*)>(_a[1]))); break;
        case 3: _t->sigDoorSubTaskAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->onAgvCarSocketDeleteLater(); break;
        case 5: _t->onAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 6: _t->ON_AGVChargeTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 7: _t->ON_TaskmoveListProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<int,agvSubTask>(*)>(_a[2])),(*reinterpret_cast< agvState(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->ON_Device_door_Status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (agvCarPool::*)(QList<agvState> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCarPool::allAGVState)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (agvCarPool::*)(QString , quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCarPool::AGVMoveTask)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (agvCarPool::*)(agvState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCarPool::AgvStateWidget)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (agvCarPool::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&agvCarPool::sigDoorSubTaskAction)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject agvCarPool::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_agvCarPool.data,
    qt_meta_data_agvCarPool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *agvCarPool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *agvCarPool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_agvCarPool.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int agvCarPool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void agvCarPool::allAGVState(QList<agvState> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void agvCarPool::AGVMoveTask(QString _t1, quint32 _t2, quint32 _t3, int _t4, int _t5, agvORderTask _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void agvCarPool::AgvStateWidget(agvState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void agvCarPool::sigDoorSubTaskAction(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
