/****************************************************************************
** Meta object code from reading C++ file 'sapmsginterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../queryServer/sapmsginterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sapmsginterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sapMsgInterface_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sapMsgInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sapMsgInterface_t qt_meta_stringdata_sapMsgInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "sapMsgInterface"
QT_MOC_LITERAL(1, 16, 15), // "ReplyWebService"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "RequestJson"
QT_MOC_LITERAL(4, 45, 9), // "ReplyJson"
QT_MOC_LITERAL(5, 55, 9), // "UserBadge"
QT_MOC_LITERAL(6, 65, 10), // "ActionType"
QT_MOC_LITERAL(7, 76, 10), // "ReplyError"
QT_MOC_LITERAL(8, 87, 15), // "WebServiceItiem"
QT_MOC_LITERAL(9, 103, 16), // "WebServiceItiemI"
QT_MOC_LITERAL(10, 120, 12), // "ReadResponse"
QT_MOC_LITERAL(11, 133, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 148, 5), // "Reply"
QT_MOC_LITERAL(13, 154, 11), // "sapMsgTimer"
QT_MOC_LITERAL(14, 166, 12) // "ONReplyError"

    },
    "sapMsgInterface\0ReplyWebService\0\0"
    "RequestJson\0ReplyJson\0UserBadge\0"
    "ActionType\0ReplyError\0WebServiceItiem\0"
    "WebServiceItiemI\0ReadResponse\0"
    "QNetworkReply*\0Reply\0sapMsgTimer\0"
    "ONReplyError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sapMsgInterface[] = {

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
      10,    1,   51,    2, 0x0a /* Public */,
      13,    0,   54,    2, 0x0a /* Public */,
      14,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject, QMetaType::QJsonObject, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void sapMsgInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sapMsgInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReplyWebService((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->ReplyError((*reinterpret_cast< WebServiceItiem(*)>(_a[1]))); break;
        case 2: _t->ReadResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->sapMsgTimer(); break;
        case 4: _t->ONReplyError((*reinterpret_cast< WebServiceItiem(*)>(_a[1]))); break;
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
            using _t = void (sapMsgInterface::*)(QJsonObject , QJsonObject , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sapMsgInterface::ReplyWebService)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (sapMsgInterface::*)(WebServiceItiem );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sapMsgInterface::ReplyError)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject sapMsgInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_sapMsgInterface.data,
    qt_meta_data_sapMsgInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *sapMsgInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sapMsgInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sapMsgInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sapMsgInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void sapMsgInterface::ReplyWebService(QJsonObject _t1, QJsonObject _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sapMsgInterface::ReplyError(WebServiceItiem _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
