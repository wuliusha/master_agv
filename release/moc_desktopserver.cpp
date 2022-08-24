/****************************************************************************
** Meta object code from reading C++ file 'desktopserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainDesktop/desktopserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktopserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_desktopServer_t {
    QByteArrayData data[26];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_desktopServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_desktopServer_t qt_meta_stringdata_desktopServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "desktopServer"
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
QT_MOC_LITERAL(14, 156, 14), // "AgvStateWidget"
QT_MOC_LITERAL(15, 171, 8), // "agvState"
QT_MOC_LITERAL(16, 180, 13), // "agvStateItem1"
QT_MOC_LITERAL(17, 194, 26), // "sig_deleteSAPExcelInfoTask"
QT_MOC_LITERAL(18, 221, 22), // "QMap<int,SAPExcelInfo>"
QT_MOC_LITERAL(19, 244, 21), // "seletSAPExcelInfoTask"
QT_MOC_LITERAL(20, 266, 22), // "sig_UPSAPExcelInfoTask"
QT_MOC_LITERAL(21, 289, 11), // "ESS_Request"
QT_MOC_LITERAL(22, 301, 12), // "ESS_RequestI"
QT_MOC_LITERAL(23, 314, 24), // "sig_AGVCurrentTaskAction"
QT_MOC_LITERAL(24, 339, 4), // "Type"
QT_MOC_LITERAL(25, 344, 6) // "Action"

    },
    "desktopServer\0sigAGVMoveTask\0\0AGVIP\0"
    "StartQRPoint\0EndQRPoint\0AGVAction\0tye\0"
    "agvORderTask\0agvORderTaskI\0newAGVMoveTask\0"
    "taskType\0AGVCurrentTask\0AGVCurrentTaskI\0"
    "AgvStateWidget\0agvState\0agvStateItem1\0"
    "sig_deleteSAPExcelInfoTask\0"
    "QMap<int,SAPExcelInfo>\0seletSAPExcelInfoTask\0"
    "sig_UPSAPExcelInfoTask\0ESS_Request\0"
    "ESS_RequestI\0sig_AGVCurrentTaskAction\0"
    "Type\0Action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_desktopServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x06 /* Public */,
      10,    3,   57,    2, 0x06 /* Public */,
      14,    1,   64,    2, 0x06 /* Public */,
      17,    1,   67,    2, 0x06 /* Public */,
      20,    3,   70,    2, 0x06 /* Public */,
      23,    3,   77,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    3,    4,    5,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 12,    3,   11,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 21, QMetaType::QString,   19,   22,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   24,   25,

       0        // eod
};

void desktopServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<desktopServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 1: _t->newAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< AGVCurrentTask(*)>(_a[3]))); break;
        case 2: _t->AgvStateWidget((*reinterpret_cast< agvState(*)>(_a[1]))); break;
        case 3: _t->sig_deleteSAPExcelInfoTask((*reinterpret_cast< QMap<int,SAPExcelInfo>(*)>(_a[1]))); break;
        case 4: _t->sig_UPSAPExcelInfoTask((*reinterpret_cast< QMap<int,SAPExcelInfo>(*)>(_a[1])),(*reinterpret_cast< ESS_Request(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->sig_AGVCurrentTaskAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (desktopServer::*)(QString , quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::sigAGVMoveTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (desktopServer::*)(QString , QString , AGVCurrentTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::newAGVMoveTask)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (desktopServer::*)(agvState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::AgvStateWidget)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (desktopServer::*)(QMap<int,SAPExcelInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::sig_deleteSAPExcelInfoTask)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (desktopServer::*)(QMap<int,SAPExcelInfo> , ESS_Request , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::sig_UPSAPExcelInfoTask)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (desktopServer::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&desktopServer::sig_AGVCurrentTaskAction)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject desktopServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_desktopServer.data,
    qt_meta_data_desktopServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *desktopServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *desktopServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_desktopServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int desktopServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void desktopServer::sigAGVMoveTask(QString _t1, quint32 _t2, quint32 _t3, int _t4, int _t5, agvORderTask _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void desktopServer::newAGVMoveTask(QString _t1, QString _t2, AGVCurrentTask _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void desktopServer::AgvStateWidget(agvState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void desktopServer::sig_deleteSAPExcelInfoTask(QMap<int,SAPExcelInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void desktopServer::sig_UPSAPExcelInfoTask(QMap<int,SAPExcelInfo> _t1, ESS_Request _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void desktopServer::sig_AGVCurrentTaskAction(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
