/****************************************************************************
** Meta object code from reading C++ file 'managerinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../managerinfo/managerinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManagerInfo_t {
    QByteArrayData data[14];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManagerInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManagerInfo_t qt_meta_stringdata_ManagerInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ManagerInfo"
QT_MOC_LITERAL(1, 12, 15), // "ON_ManagerTimer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "on_Qury_Button_clicked"
QT_MOC_LITERAL(4, 52, 24), // "on_Cancel_Button_clicked"
QT_MOC_LITERAL(5, 77, 26), // "on_Cancel_Button_2_clicked"
QT_MOC_LITERAL(6, 104, 25), // "on_logInfo_Button_clicked"
QT_MOC_LITERAL(7, 130, 26), // "on_Binchage_Button_clicked"
QT_MOC_LITERAL(8, 157, 25), // "on_Network_Button_clicked"
QT_MOC_LITERAL(9, 183, 22), // "on_stop_Button_clicked"
QT_MOC_LITERAL(10, 206, 23), // "on_clear_Button_clicked"
QT_MOC_LITERAL(11, 230, 26), // "on_sureLead_Button_clicked"
QT_MOC_LITERAL(12, 257, 10), // "ON_Pressed"
QT_MOC_LITERAL(13, 268, 11) // "ON_Released"

    },
    "ManagerInfo\0ON_ManagerTimer\0\0"
    "on_Qury_Button_clicked\0on_Cancel_Button_clicked\0"
    "on_Cancel_Button_2_clicked\0"
    "on_logInfo_Button_clicked\0"
    "on_Binchage_Button_clicked\0"
    "on_Network_Button_clicked\0"
    "on_stop_Button_clicked\0on_clear_Button_clicked\0"
    "on_sureLead_Button_clicked\0ON_Pressed\0"
    "ON_Released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManagerInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManagerInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManagerInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ON_ManagerTimer(); break;
        case 1: _t->on_Qury_Button_clicked(); break;
        case 2: _t->on_Cancel_Button_clicked(); break;
        case 3: _t->on_Cancel_Button_2_clicked(); break;
        case 4: _t->on_logInfo_Button_clicked(); break;
        case 5: _t->on_Binchage_Button_clicked(); break;
        case 6: _t->on_Network_Button_clicked(); break;
        case 7: _t->on_stop_Button_clicked(); break;
        case 8: _t->on_clear_Button_clicked(); break;
        case 9: _t->on_sureLead_Button_clicked(); break;
        case 10: _t->ON_Pressed(); break;
        case 11: _t->ON_Released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ManagerInfo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ManagerInfo.data,
    qt_meta_data_ManagerInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManagerInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManagerInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManagerInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ManagerInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
