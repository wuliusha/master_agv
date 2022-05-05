/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TcpServer/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    QByteArrayData data[13];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpClient"
QT_MOC_LITERAL(1, 10, 18), // "sigLiftStatuschage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "DeviceIP"
QT_MOC_LITERAL(4, 39, 11), // "ActionArray"
QT_MOC_LITERAL(5, 51, 8), // "sigclose"
QT_MOC_LITERAL(6, 60, 9), // "sigonline"
QT_MOC_LITERAL(7, 70, 6), // "online"
QT_MOC_LITERAL(8, 77, 12), // "stateChanged"
QT_MOC_LITERAL(9, 90, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(10, 119, 5), // "state"
QT_MOC_LITERAL(11, 125, 19), // "receiveTcpReadyRead"
QT_MOC_LITERAL(12, 145, 12) // "ON_SendTimer"

    },
    "TcpClient\0sigLiftStatuschage\0\0DeviceIP\0"
    "ActionArray\0sigclose\0sigonline\0online\0"
    "stateChanged\0QAbstractSocket::SocketState\0"
    "state\0receiveTcpReadyRead\0ON_SendTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
      11,    0,   56,    2, 0x0a /* Public */,
      12,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLiftStatuschage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->sigclose(); break;
        case 2: _t->sigonline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 4: _t->receiveTcpReadyRead(); break;
        case 5: _t->ON_SendTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)(QString , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sigLiftStatuschage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sigclose)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sigonline)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TcpClient.data,
    qt_meta_data_TcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::sigLiftStatuschage(QString _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClient::sigclose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpClient::sigonline(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
