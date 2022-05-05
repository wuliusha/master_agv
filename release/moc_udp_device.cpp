/****************************************************************************
** Meta object code from reading C++ file 'udp_device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TcpServer/udp_device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udp_device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Udp_Device_t {
    QByteArrayData data[11];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Udp_Device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Udp_Device_t qt_meta_stringdata_Udp_Device = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Udp_Device"
QT_MOC_LITERAL(1, 11, 20), // "sigDeviceStatuschage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "DeviceIP"
QT_MOC_LITERAL(4, 42, 11), // "ActionArray"
QT_MOC_LITERAL(5, 54, 12), // "ON_SendTimer"
QT_MOC_LITERAL(6, 67, 28), // "slotReadySocketReadDatagrams"
QT_MOC_LITERAL(7, 96, 21), // "ON_DeviceStatusAction"
QT_MOC_LITERAL(8, 118, 10), // "deviceType"
QT_MOC_LITERAL(9, 129, 9), // "orderType"
QT_MOC_LITERAL(10, 139, 6) // "Action"

    },
    "Udp_Device\0sigDeviceStatuschage\0\0"
    "DeviceIP\0ActionArray\0ON_SendTimer\0"
    "slotReadySocketReadDatagrams\0"
    "ON_DeviceStatusAction\0deviceType\0"
    "orderType\0Action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Udp_Device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x0a /* Public */,
       6,    0,   40,    2, 0x0a /* Public */,
       7,    4,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    8,    9,   10,

       0        // eod
};

void Udp_Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Udp_Device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDeviceStatuschage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->ON_SendTimer(); break;
        case 2: _t->slotReadySocketReadDatagrams(); break;
        case 3: _t->ON_DeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Udp_Device::*)(QString , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Udp_Device::sigDeviceStatuschage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Udp_Device::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Udp_Device.data,
    qt_meta_data_Udp_Device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Udp_Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Udp_Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Udp_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Udp_Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Udp_Device::sigDeviceStatuschage(QString _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
