/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[26];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 14), // "displayHandler"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 18), // "create_listHandler"
QT_MOC_LITERAL(46, 15), // "LinkedList<int>"
QT_MOC_LITERAL(62, 23), // "LinkedList<std::string>"
QT_MOC_LITERAL(86, 18), // "LinkedList<double>"
QT_MOC_LITERAL(105, 16), // "push_backHandler"
QT_MOC_LITERAL(122, 17), // "push_frontHandler"
QT_MOC_LITERAL(140, 16), // "pop_frontHandler"
QT_MOC_LITERAL(157, 18), // "select_sortHandler"
QT_MOC_LITERAL(176, 24), // "remove_duplicatesHandler"
QT_MOC_LITERAL(201, 16) // "copy_listHandler"

    },
    "MainWindow\0displayHandler\0\0"
    "create_listHandler\0LinkedList<int>\0"
    "LinkedList<std::string>\0LinkedList<double>\0"
    "push_backHandler\0push_frontHandler\0"
    "pop_frontHandler\0select_sortHandler\0"
    "remove_duplicatesHandler\0copy_listHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       3,    1,   82,    2, 0x08,    3 /* Private */,
       3,    1,   85,    2, 0x08,    5 /* Private */,
       3,    1,   88,    2, 0x08,    7 /* Private */,
       7,    0,   91,    2, 0x08,    9 /* Private */,
       8,    0,   92,    2, 0x08,   10 /* Private */,
       9,    0,   93,    2, 0x08,   11 /* Private */,
      10,    0,   94,    2, 0x08,   12 /* Private */,
      11,    0,   95,    2, 0x08,   13 /* Private */,
      12,    0,   96,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->displayHandler(); break;
        case 1: _t->create_listHandler(); break;
        case 2: _t->create_listHandler((*reinterpret_cast< std::add_pointer_t<LinkedList<int>>>(_a[1]))); break;
        case 3: _t->create_listHandler((*reinterpret_cast< std::add_pointer_t<LinkedList<std::string>>>(_a[1]))); break;
        case 4: _t->create_listHandler((*reinterpret_cast< std::add_pointer_t<LinkedList<double>>>(_a[1]))); break;
        case 5: _t->push_backHandler(); break;
        case 6: _t->push_frontHandler(); break;
        case 7: _t->pop_frontHandler(); break;
        case 8: _t->select_sortHandler(); break;
        case 9: _t->remove_duplicatesHandler(); break;
        case 10: _t->copy_listHandler(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LinkedList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LinkedList<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LinkedList<double>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
