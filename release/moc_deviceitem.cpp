/****************************************************************************
** Meta object code from reading C++ file 'deviceitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Device/deviceitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceItem_t {
    QByteArrayData data[14];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceItem_t qt_meta_stringdata_DeviceItem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DeviceItem"
QT_MOC_LITERAL(1, 11, 21), // "sigDeviceStatusAction"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "DeviceIP"
QT_MOC_LITERAL(4, 43, 10), // "deviceType"
QT_MOC_LITERAL(5, 54, 9), // "orderType"
QT_MOC_LITERAL(6, 64, 6), // "Action"
QT_MOC_LITERAL(7, 71, 14), // "ON_DeviceTimer"
QT_MOC_LITERAL(8, 86, 25), // "on_action_Button1_clicked"
QT_MOC_LITERAL(9, 112, 25), // "on_action_Button2_clicked"
QT_MOC_LITERAL(10, 138, 24), // "on_enable_Button_clicked"
QT_MOC_LITERAL(11, 163, 23), // "on_reset_Button_clicked"
QT_MOC_LITERAL(12, 187, 10), // "ON_Pressed"
QT_MOC_LITERAL(13, 198, 11) // "ON_Released"

    },
    "DeviceItem\0sigDeviceStatusAction\0\0"
    "DeviceIP\0deviceType\0orderType\0Action\0"
    "ON_DeviceTimer\0on_action_Button1_clicked\0"
    "on_action_Button2_clicked\0"
    "on_enable_Button_clicked\0"
    "on_reset_Button_clicked\0ON_Pressed\0"
    "ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->ON_DeviceTimer(); break;
        case 2: _t->on_action_Button1_clicked(); break;
        case 3: _t->on_action_Button2_clicked(); break;
        case 4: _t->on_enable_Button_clicked(); break;
        case 5: _t->on_reset_Button_clicked(); break;
        case 6: _t->ON_Pressed(); break;
        case 7: _t->ON_Released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceItem::*)(QString , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceItem::sigDeviceStatusAction)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceItem::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DeviceItem.data,
    qt_meta_data_DeviceItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeviceItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DeviceItem::sigDeviceStatusAction(QString _t1, QString _t2, QString _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
