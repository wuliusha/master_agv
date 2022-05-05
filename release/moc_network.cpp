/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../managerinfo/Network/network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Network_t {
    QByteArrayData data[17];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Network_t qt_meta_stringdata_Network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Network"
QT_MOC_LITERAL(1, 8, 15), // "ReplyWebService"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "RequestJson"
QT_MOC_LITERAL(4, 37, 9), // "ReplyJson"
QT_MOC_LITERAL(5, 47, 9), // "UserBadge"
QT_MOC_LITERAL(6, 57, 10), // "ActionType"
QT_MOC_LITERAL(7, 68, 10), // "ReplyError"
QT_MOC_LITERAL(8, 79, 9), // "Errorinfo"
QT_MOC_LITERAL(9, 89, 12), // "ReadResponse"
QT_MOC_LITERAL(10, 102, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 117, 5), // "Reply"
QT_MOC_LITERAL(12, 123, 17), // "ON_WebService_get"
QT_MOC_LITERAL(13, 141, 7), // "UrlPath"
QT_MOC_LITERAL(14, 149, 7), // "JsonGet"
QT_MOC_LITERAL(15, 157, 18), // "ON_WebService_post"
QT_MOC_LITERAL(16, 176, 8) // "JsonPost"

    },
    "Network\0ReplyWebService\0\0RequestJson\0"
    "ReplyJson\0UserBadge\0ActionType\0"
    "ReplyError\0Errorinfo\0ReadResponse\0"
    "QNetworkReply*\0Reply\0ON_WebService_get\0"
    "UrlPath\0JsonGet\0ON_WebService_post\0"
    "JsonPost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Network[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   51,    2, 0x0a /* Public */,
      12,    4,   54,    2, 0x0a /* Public */,
      15,    4,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString,   13,   14,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString,   13,   16,    5,    6,

       0        // eod
};

void Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReplyWebService((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->ReplyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ReadResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->ON_WebService_get((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->ON_WebService_post((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Network::*)(QJsonObject , QJsonObject , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::ReplyWebService)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Network::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::ReplyError)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Network::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Network.data,
    qt_meta_data_Network,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Network.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Network::ReplyWebService(QJsonObject _t1, QJsonObject _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Network::ReplyError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
