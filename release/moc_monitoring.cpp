/****************************************************************************
** Meta object code from reading C++ file 'monitoring.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Monitoring/monitoring.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitoring.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_monitoring_t {
    QByteArrayData data[19];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_monitoring_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_monitoring_t qt_meta_stringdata_monitoring = {
    {
QT_MOC_LITERAL(0, 0, 10), // "monitoring"
QT_MOC_LITERAL(1, 11, 14), // "sigAGVMoveTask"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "AGVIP"
QT_MOC_LITERAL(4, 33, 12), // "StartQRPoint"
QT_MOC_LITERAL(5, 46, 10), // "EndQRPoint"
QT_MOC_LITERAL(6, 57, 9), // "AGVAction"
QT_MOC_LITERAL(7, 67, 3), // "tye"
QT_MOC_LITERAL(8, 71, 12), // "agvORderTask"
QT_MOC_LITERAL(9, 84, 13), // "agvORderTaskI"
QT_MOC_LITERAL(10, 98, 14), // "newAGVMoveTask"
QT_MOC_LITERAL(11, 113, 8), // "taskType"
QT_MOC_LITERAL(12, 122, 14), // "AGVCurrentTask"
QT_MOC_LITERAL(13, 137, 15), // "AGVCurrentTaskI"
QT_MOC_LITERAL(14, 153, 17), // "monitoringTimeout"
QT_MOC_LITERAL(15, 171, 14), // "ON_signalPoint"
QT_MOC_LITERAL(16, 186, 10), // "mousePoint"
QT_MOC_LITERAL(17, 197, 4), // "Type"
QT_MOC_LITERAL(18, 202, 15) // "sigAgvItemClick"

    },
    "monitoring\0sigAGVMoveTask\0\0AGVIP\0"
    "StartQRPoint\0EndQRPoint\0AGVAction\0tye\0"
    "agvORderTask\0agvORderTaskI\0newAGVMoveTask\0"
    "taskType\0AGVCurrentTask\0AGVCurrentTaskI\0"
    "monitoringTimeout\0ON_signalPoint\0"
    "mousePoint\0Type\0sigAgvItemClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_monitoring[] = {

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
       1,    6,   39,    2, 0x06 /* Public */,
      10,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   59,    2, 0x0a /* Public */,
      15,    2,   60,    2, 0x0a /* Public */,
      18,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    3,    4,    5,    6,    7,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 12,    3,   11,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QString,   16,   17,
    QMetaType::Void,

       0        // eod
};

void monitoring::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<monitoring *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< agvORderTask(*)>(_a[6]))); break;
        case 1: _t->newAGVMoveTask((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< AGVCurrentTask(*)>(_a[3]))); break;
        case 2: _t->monitoringTimeout(); break;
        case 3: _t->ON_signalPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->sigAgvItemClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (monitoring::*)(QString , quint32 , quint32 , int , int , agvORderTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&monitoring::sigAGVMoveTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (monitoring::*)(QString , QString , AGVCurrentTask );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&monitoring::newAGVMoveTask)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject monitoring::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_monitoring.data,
    qt_meta_data_monitoring,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *monitoring::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *monitoring::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_monitoring.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int monitoring::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void monitoring::sigAGVMoveTask(QString _t1, quint32 _t2, quint32 _t3, int _t4, int _t5, agvORderTask _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void monitoring::newAGVMoveTask(QString _t1, QString _t2, AGVCurrentTask _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
