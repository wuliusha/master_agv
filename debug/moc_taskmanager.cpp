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
    QByteArrayData data[24];
    char stringdata0[418];
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
QT_MOC_LITERAL(3, 40, 22), // "QMap<int,SAPExcelInfo>"
QT_MOC_LITERAL(4, 63, 21), // "seletSAPExcelInfoTask"
QT_MOC_LITERAL(5, 85, 22), // "sig_UPSAPExcelInfoTask"
QT_MOC_LITERAL(6, 108, 11), // "ESS_Request"
QT_MOC_LITERAL(7, 120, 12), // "ESS_RequestI"
QT_MOC_LITERAL(8, 133, 8), // "taskType"
QT_MOC_LITERAL(9, 142, 19), // "ON_taskManagerTimer"
QT_MOC_LITERAL(10, 162, 18), // "SlotsetCurrentItem"
QT_MOC_LITERAL(11, 181, 3), // "row"
QT_MOC_LITERAL(12, 185, 6), // "column"
QT_MOC_LITERAL(13, 192, 17), // "ONUP_SAPExcelInfo"
QT_MOC_LITERAL(14, 210, 12), // "SAPExcelInfo"
QT_MOC_LITERAL(15, 223, 13), // "SAPExcelInfoI"
QT_MOC_LITERAL(16, 237, 10), // "ON_Pressed"
QT_MOC_LITERAL(17, 248, 11), // "ON_Released"
QT_MOC_LITERAL(18, 260, 24), // "on_Delete_Button_clicked"
QT_MOC_LITERAL(19, 285, 39), // "on_taskStatusBox_ESS_currentT..."
QT_MOC_LITERAL(20, 325, 4), // "arg1"
QT_MOC_LITERAL(21, 330, 39), // "on_taskStatusBox_AGV_currentT..."
QT_MOC_LITERAL(22, 370, 22), // "on_Qury_Button_clicked"
QT_MOC_LITERAL(23, 393, 24) // "on_Cancel_Button_clicked"

    },
    "taskManager\0sig_deleteSAPExcelInfoTask\0"
    "\0QMap<int,SAPExcelInfo>\0seletSAPExcelInfoTask\0"
    "sig_UPSAPExcelInfoTask\0ESS_Request\0"
    "ESS_RequestI\0taskType\0ON_taskManagerTimer\0"
    "SlotsetCurrentItem\0row\0column\0"
    "ONUP_SAPExcelInfo\0SAPExcelInfo\0"
    "SAPExcelInfoI\0ON_Pressed\0ON_Released\0"
    "on_Delete_Button_clicked\0"
    "on_taskStatusBox_ESS_currentTextChanged\0"
    "arg1\0on_taskStatusBox_AGV_currentTextChanged\0"
    "on_Qury_Button_clicked\0on_Cancel_Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_taskManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    3,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   84,    2, 0x0a /* Public */,
      10,    2,   85,    2, 0x0a /* Public */,
      13,    1,   90,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,
      17,    0,   94,    2, 0x0a /* Public */,
      18,    0,   95,    2, 0x08 /* Private */,
      19,    1,   96,    2, 0x08 /* Private */,
      21,    1,   99,    2, 0x08 /* Private */,
      22,    0,  102,    2, 0x08 /* Private */,
      23,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6, QMetaType::QString,    4,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
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
        case 0: _t->sig_deleteSAPExcelInfoTask((*reinterpret_cast< QMap<int,SAPExcelInfo>(*)>(_a[1]))); break;
        case 1: _t->sig_UPSAPExcelInfoTask((*reinterpret_cast< QMap<int,SAPExcelInfo>(*)>(_a[1])),(*reinterpret_cast< ESS_Request(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->ON_taskManagerTimer(); break;
        case 3: _t->SlotsetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->ONUP_SAPExcelInfo((*reinterpret_cast< SAPExcelInfo(*)>(_a[1]))); break;
        case 5: _t->ON_Pressed(); break;
        case 6: _t->ON_Released(); break;
        case 7: _t->on_Delete_Button_clicked(); break;
        case 8: _t->on_taskStatusBox_ESS_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_taskStatusBox_AGV_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_Qury_Button_clicked(); break;
        case 11: _t->on_Cancel_Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (taskManager::*)(QMap<int,SAPExcelInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManager::sig_deleteSAPExcelInfoTask)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (taskManager::*)(QMap<int,SAPExcelInfo> , ESS_Request , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&taskManager::sig_UPSAPExcelInfoTask)) {
                *result = 1;
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

// SIGNAL 0
void taskManager::sig_deleteSAPExcelInfoTask(QMap<int,SAPExcelInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void taskManager::sig_UPSAPExcelInfoTask(QMap<int,SAPExcelInfo> _t1, ESS_Request _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
