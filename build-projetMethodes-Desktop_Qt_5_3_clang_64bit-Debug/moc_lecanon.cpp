/****************************************************************************
** Meta object code from reading C++ file 'lecanon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ProjetMethode/lecanon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecanon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_leCanon_t {
    QByteArrayData data[10];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_leCanon_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_leCanon_t qt_meta_stringdata_leCanon = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 7),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 20),
QT_MOC_LITERAL(4, 38, 23),
QT_MOC_LITERAL(5, 62, 4),
QT_MOC_LITERAL(6, 67, 1),
QT_MOC_LITERAL(7, 69, 4),
QT_MOC_LITERAL(8, 74, 4),
QT_MOC_LITERAL(9, 79, 7)
    },
    "leCanon\0updatez\0\0on_pushButtonclicked\0"
    "on_pushButton_2_clicked\0setI\0a\0setN\0"
    "setM\0setNbob"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_leCanon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void leCanon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        leCanon *_t = static_cast<leCanon *>(_o);
        switch (_id) {
        case 0: _t->updatez(); break;
        case 1: _t->on_pushButtonclicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->setI((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setN((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setM((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setNbob((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject leCanon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_leCanon.data,
      qt_meta_data_leCanon,  qt_static_metacall, 0, 0}
};


const QMetaObject *leCanon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *leCanon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_leCanon.stringdata))
        return static_cast<void*>(const_cast< leCanon*>(this));
    return QWidget::qt_metacast(_clname);
}

int leCanon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
