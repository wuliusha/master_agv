/****************************************************************************
** Meta object code from reading C++ file 'taskmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../taskmanager/taskmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_taskManager_t {
    QByteArrayData data[15];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_taskManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_taskManager_t qt_meta_stringdata_taskManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "taskManager"
QT_MOC_LITERAL(1, 12, 26), // "sig_deleteSAPExcelInfoTask"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(4, 53, 18), // "seletSAPExcelInfoI"
QT_MOC_LITERAL(5, 72, 19), // "ON_taskManagerTimer"
QT_MOC_LITERAL(6, 92, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(7, 111, 3), // "row"
QT_MOC_LITERAL(8, 115, 6), // "column"
QT_MOC_LITERAL(9, 122, 24), // "on_Delete_Button_clicked"
QT_MOC_LITERAL(10, 147, 22), // "on_Qury_Button_clicked"
QT_MOC_LITERAL(11, 170, 24), // "on_Cancel_Button_clicked"
QT_MOC_LITERAL(12, 195, 19), // "on_unbundle_clicked"
QT_MOC_LITERAL(13, 215, 19), // "on_rebundle_clicked"
QT_MOC_LITERAL(14, 235, 23) // "on_unbundle_ess_clicked"

    },
    "taskManager\0sig_deleteSAPExcelInfoTask\0"
    "\0SAPExcelInfo\0seletSAPExcelInfoI\0"
    "ON_taskManagerTimer\0SlotsetCurrentItem\0"
    "row\0column\0on_Delete_Button_clicked\0"
    "on_Qury_Button_clicked\0on_Cancel_Button_clicked\0"
    "on_unbundle_clicked\0on_rebundle_clicked\0"
    "on_unbundle_ess_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_taskManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       6,    2,   63,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void taskManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<taskManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_deleteSAPExcelInfoTask((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 1: _t->ON_taskManagerTimer(); break;
        case 2: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_Delete_Button_clicked(); break;
        case 4: _t->on_Qury_Button_clicked(); break;
        case 5: _t->on_Cancel_Button_clicked(); break;
        case 6: _t->on_unbundle_clicked(); break;
        case 7: _t->on_rebundle_clicked(); break;
        case 8: _t->on_unbundle_ess_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (taskManager::*)(SAPExcelInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManager::sig_deleteSAPExcelInfoTask)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject taskManager::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_taskManager.data,
    qt_meta_data_taskManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *taskManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *taskManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_taskManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int taskManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void taskManager::sig_deleteSAPExcelInfoTask(SAPExcelInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
