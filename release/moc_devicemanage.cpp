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
    QByteArrayData data[27];
    char stringdata0[379];
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
QT_MOC_LITERAL(5, 52, 24), // "sig_LiftCodeStatus_clear"
QT_MOC_LITERAL(6, 77, 8), // "LiftCode"
QT_MOC_LITERAL(7, 86, 12), // "LiftCodeItem"
QT_MOC_LITERAL(8, 99, 14), // "ON_DeviceTimer"
QT_MOC_LITERAL(9, 114, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(10, 133, 3), // "row"
QT_MOC_LITERAL(11, 137, 6), // "column"
QT_MOC_LITERAL(12, 144, 21), // "ON_DeviceStatusAction"
QT_MOC_LITERAL(13, 166, 8), // "DeviceIP"
QT_MOC_LITERAL(14, 175, 10), // "deviceType"
QT_MOC_LITERAL(15, 186, 9), // "orderType"
QT_MOC_LITERAL(16, 196, 6), // "Action"
QT_MOC_LITERAL(17, 203, 21), // "ON_setLiftactionArray"
QT_MOC_LITERAL(18, 225, 10), // "startFloor"
QT_MOC_LITERAL(19, 236, 9), // "destFloor"
QT_MOC_LITERAL(20, 246, 18), // "ON_LiftStatuschage"
QT_MOC_LITERAL(21, 265, 11), // "ActionArray"
QT_MOC_LITERAL(22, 277, 14), // "ON_LiftCodeMap"
QT_MOC_LITERAL(23, 292, 22), // "QMap<QString,LiftCode>"
QT_MOC_LITERAL(24, 315, 12), // "LiftCodeMap_"
QT_MOC_LITERAL(25, 328, 27), // "on_Sure_Button_Lift_clicked"
QT_MOC_LITERAL(26, 356, 22) // "on_clearButton_clicked"

    },
    "DeviceManage\0sig_LiftTaskStatus\0\0"
    "LiftTask\0LiftTaskI\0sig_LiftCodeStatus_clear\0"
    "LiftCode\0LiftCodeItem\0ON_DeviceTimer\0"
    "SlotsetCurrentItem\0row\0column\0"
    "ON_DeviceStatusAction\0DeviceIP\0"
    "deviceType\0orderType\0Action\0"
    "ON_setLiftactionArray\0startFloor\0"
    "destFloor\0ON_LiftStatuschage\0ActionArray\0"
    "ON_LiftCodeMap\0QMap<QString,LiftCode>\0"
    "LiftCodeMap_\0on_Sure_Button_Lift_clicked\0"
    "on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceManage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   70,    2, 0x0a /* Public */,
       9,    2,   71,    2, 0x0a /* Public */,
      12,    4,   76,    2, 0x0a /* Public */,
      17,    3,   85,    2, 0x0a /* Public */,
      20,    2,   92,    2, 0x0a /* Public */,
      22,    1,   97,    2, 0x0a /* Public */,
      25,    0,  100,    2, 0x08 /* Private */,
      26,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   13,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   13,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_LiftTaskStatus((*reinterpret_cast< LiftTask(*)>(_a[1]))); break;
        case 1: _t->sig_LiftCodeStatus_clear((*reinterpret_cast< LiftCode(*)>(_a[1]))); break;
        case 2: _t->ON_DeviceTimer(); break;
        case 3: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->ON_DeviceStatusAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->ON_setLiftactionArray((*reinterpret_cast< LiftTask(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->ON_LiftStatuschage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 7: _t->ON_LiftCodeMap((*reinterpret_cast< QMap<QString,LiftCode>(*)>(_a[1]))); break;
        case 8: _t->on_Sure_Button_Lift_clicked(); break;
        case 9: _t->on_clearButton_clicked(); break;
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
            using _t = void (DeviceManage::*)(LiftCode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceManage::sig_LiftCodeStatus_clear)) {
                *result = 1;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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
void DeviceManage::sig_LiftCodeStatus_clear(LiftCode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
