/****************************************************************************
** Meta object code from reading C++ file 'prenotazioni_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../View/prenotazioni_view.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prenotazioni_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS = QtMocHelpers::stringData(
    "prenotazioni_view",
    "indietro_signal",
    "",
    "aggiungi_signal",
    "rimuovi_signal",
    "aggiungi_pren"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[18];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[15];
    char stringdata5[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS_t qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "prenotazioni_view"
        QT_MOC_LITERAL(18, 15),  // "indietro_signal"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 15),  // "aggiungi_signal"
        QT_MOC_LITERAL(51, 14),  // "rimuovi_signal"
        QT_MOC_LITERAL(66, 13)   // "aggiungi_pren"
    },
    "prenotazioni_view",
    "indietro_signal",
    "",
    "aggiungi_signal",
    "rimuovi_signal",
    "aggiungi_pren"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSprenotazioni_viewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x106,    1 /* Public | MethodIsConst  */,
       3,    6,   39,    2, 0x06,    2 /* Public */,
       4,    1,   52,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   55,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QDate, QMetaType::QTime, QMetaType::QTime, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject prenotazioni_view::staticMetaObject = { {
    QMetaObject::SuperData::link<View::staticMetaObject>(),
    qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSprenotazioni_viewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<prenotazioni_view, std::true_type>,
        // method 'indietro_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aggiungi_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'rimuovi_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'aggiungi_pren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void prenotazioni_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<prenotazioni_view *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->indietro_signal(); break;
        case 1: _t->aggiungi_signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 2: _t->rimuovi_signal((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 3: _t->aggiungi_pren(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (prenotazioni_view::*)() const;
            if (_t _q_method = &prenotazioni_view::indietro_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (prenotazioni_view::*)(const int & , const QDate & , const QTime & , const QTime & , const QString & , const QString & );
            if (_t _q_method = &prenotazioni_view::aggiungi_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (prenotazioni_view::*)(uint );
            if (_t _q_method = &prenotazioni_view::rimuovi_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *prenotazioni_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *prenotazioni_view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSprenotazioni_viewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return View::qt_metacast(_clname);
}

int prenotazioni_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = View::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void prenotazioni_view::indietro_signal()const
{
    QMetaObject::activate(const_cast< prenotazioni_view *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void prenotazioni_view::aggiungi_signal(const int & _t1, const QDate & _t2, const QTime & _t3, const QTime & _t4, const QString & _t5, const QString & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void prenotazioni_view::rimuovi_signal(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP