/****************************************************************************
** Meta object code from reading C++ file 'devicemanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Device/devicemanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicemanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceManage_t {
    QByteArrayData data[33];
    char stringdata0[475];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceManage_t qt_meta_stringdata_DeviceManage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DeviceManage"
QT_MOC_LITERAL(1, 13, 18), // "sig_LiftTaskStatus"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "LiftTask"
QT_MOC_LITERAL(4, 42, 9), // "LiftTaskI"
QT_MOC_LITERAL(5, 52, 23), // "sigDeviceStatus_station"
QT_MOC_LITERAL(6, 76, 8), // "DeviceIP"
QT_MOC_LITERAL(7, 85, 6), // "online"
QT_MOC_LITERAL(8, 92, 12), // "DeviceStatus"
QT_MOC_LITERAL(9, 105, 10), // "controlbox"
QT_MOC_LITERAL(10, 116, 11), // "controlboxI"
QT_MOC_LITERAL(11, 128, 20), // "sigDeviceStatus_door"
QT_MOC_LITERAL(12, 149, 20), // "sigDeviceStatus_Lift"
QT_MOC_LITERAL(13, 170, 22), // "sigDeviceStatus_charge"
QT_MOC_LITERAL(14, 193, 14), // "ON_DeviceTimer"
QT_MOC_LITERAL(15, 208, 10), // "ON_Pressed"
QT_MOC_LITERAL(16, 219, 11), // "ON_Released"
QT_MOC_LITERAL(17, 231, 15), // "ON_ClickProcess"
QT_MOC_LITERAL(18, 247, 21), // "ON_DeviceStatusAction"
QT_MOC_LITERAL(19, 269, 10), // "deviceType"
QT_MOC_LITERAL(20, 280, 9), // "orderType"
QT_MOC_LITERAL(21, 290, 6), // "Action"
QT_MOC_LITERAL(22, 297, 21), // "ON_setLiftactionArray"
QT_MOC_LITERAL(23, 319, 10), // "startFloor"
QT_MOC_LITERAL(24, 330, 9), // "destFloor"
QT_MOC_LITERAL(25, 340, 18), // "ON_LiftStatuschage"
QT_MOC_LITERAL(26, 359, 11), // "ActionArray"
QT_MOC_LITERAL(27, 371, 20), // "ON_DeviceStatuschage"
QT_MOC_LITERAL(28, 392, 27), // "on_Sure_Button_Lift_clicked"
QT_MOC_LITERAL(29, 420, 25), // "on_treeWidget_itemClicked"
QT_MOC_LITERAL(30, 446, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(31, 463, 4), // "item"
QT_MOC_LITERAL(32, 468, 6) // "column"

    },
    "DeviceManage\0sig_LiftTaskStatus\0\0"
    "LiftTask\0LiftTaskI\0sigDeviceStatus_station\0"
    "DeviceIP\0online\0DeviceStatus\0controlbox\0"
    "controlboxI\0sigDeviceStatus_door\0"
    "sigDeviceStatus_Lift\0sigDeviceStatus_charge\0"
    "ON_DeviceTimer\0ON_Pressed\0ON_Released\0"
    "ON_ClickProcess\0ON_DeviceStatusAction\0"
    "deviceType\0orderType\0Action\0"
    "ON_setLiftactionArray\0startFloor\0"
    "destFloor\0ON_LiftStatuschage\0ActionArray\0"
    "ON_DeviceStatuschage\0on_Sure_Button_Lift_clicked\0"
    "on_treeWidget_itemClicked\0QTreeWidgetItem*\0"
    "item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    4,   92,    2, 0x06 /* Public */,
      11,    4,  101,    2, 0x06 /* Public */,
      12,    4,  110,    2, 0x06 /* Public */,
      13,    4,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  128,    2, 0x0a /* Public */,
      15,    0,  129,    2, 0x0a /* Public */,
      16,    0,  130,    2, 0x0a /* Public */,
      17,    0,  131,    2, 0x0a /* Public */,
      18,    4,  132,    2, 0x0a /* Public */,
      22,    3,  141,    2, 0x0a /* Public */,
      25,    2,  148,    2, 0x0a /* Public */,
      27,    2,  153,    2, 0x0a /* Public */,
      28,    0,  158,    2, 0x08 /* Private */,
      29,    2,  159,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    6,    7,    8,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    6,    7,    8,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    6,    7,    8,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    6,    7,    8,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,   19,   20,   21,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    6,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    6,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30, QMetaType::Int,   31,   32,

       0        // eod
};

void DeviceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_LiftTaskStatus((*reinterpret_cast< LiftTask(*)>(_a[1]))); break;
        case 1: _t->sigDeviceStatus_station((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< controlbox(*)>(_a[4]))); break;
        case 2: _t->sigDeviceStatus_door((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< controlbox(*)>(_a[4]))); break;
        case 3: _t->sigDeviceStatus_Lift((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< controlbox(*)>(_a[4]))); break;
        case 4: _t->sigDeviceStatus_charge((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< controlbox(*)>(_a[4]))); break;
        case 5: _t->ON_DeviceTimer(); break;
        case 6: _t->ON_Pressed(); break;
        case 7: _t->ON_Released(); break;
        case 8: _t->ON_ClickProcess(); break;
        case 9: _t->ON_DeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->ON_setLiftactionArray((*reinterpret_cast< LiftTask(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->ON_LiftStatuschage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 12: _t->ON_DeviceStatuschage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 13: _t->on_Sure_Button_Lift_clicked(); break;
        case 14: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceManage::*)(LiftTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sig_LiftTaskStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceManage::*)(QString , int , int , controlbox );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sigDeviceStatus_station)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeviceManage::*)(QString , int , int , controlbox );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sigDeviceStatus_door)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeviceManage::*)(QString , int , int , controlbox );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sigDeviceStatus_Lift)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeviceManage::*)(QString , int , int , controlbox );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sigDeviceStatus_charge)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceManage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DeviceManage.data,
    qt_meta_data_DeviceManage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceManage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeviceManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void DeviceManage::sig_LiftTaskStatus(LiftTask _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceManage::sigDeviceStatus_station(QString _t1, int _t2, int _t3, controlbox _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeviceManage::sigDeviceStatus_door(QString _t1, int _t2, int _t3, controlbox _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DeviceManage::sigDeviceStatus_Lift(QString _t1, int _t2, int _t3, controlbox _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DeviceManage::sigDeviceStatus_charge(QString _t1, int _t2, int _t3, controlbox _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
