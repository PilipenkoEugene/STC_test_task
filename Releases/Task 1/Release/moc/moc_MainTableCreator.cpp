/****************************************************************************
** Meta object code from reading C++ file 'MainTableCreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../header/MainTableCreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainTableCreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainTableCreator_t {
    QByteArrayData data[9];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainTableCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainTableCreator_t qt_meta_stringdata_MainTableCreator = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MainTableCreator"
QT_MOC_LITERAL(1, 17, 25), // "OnAllRecordsFilterChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 8), // "new_text"
QT_MOC_LITERAL(4, 53, 25), // "OnPopulationFilterChanged"
QT_MOC_LITERAL(5, 79, 9), // "new_index"
QT_MOC_LITERAL(6, 89, 21), // "OnDeleteButtonClicked"
QT_MOC_LITERAL(7, 111, 19), // "OnEditButtonClicked"
QT_MOC_LITERAL(8, 131, 18) // "OnAddButtonClicked"

    },
    "MainTableCreator\0OnAllRecordsFilterChanged\0"
    "\0new_text\0OnPopulationFilterChanged\0"
    "new_index\0OnDeleteButtonClicked\0"
    "OnEditButtonClicked\0OnAddButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainTableCreator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainTableCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainTableCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnAllRecordsFilterChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->OnPopulationFilterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnDeleteButtonClicked(); break;
        case 3: _t->OnEditButtonClicked(); break;
        case 4: _t->OnAddButtonClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainTableCreator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainTableCreator.data,
    qt_meta_data_MainTableCreator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainTableCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainTableCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainTableCreator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainTableCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
