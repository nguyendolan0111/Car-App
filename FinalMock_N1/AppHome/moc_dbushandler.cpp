/****************************************************************************
** Meta object code from reading C++ file 'dbushandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dbushandler.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbushandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSDbusHandlerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDbusHandlerENDCLASS = QtMocHelpers::stringData(
    "DbusHandler",
    "returnHome",
    "",
    "inforVideoChanged",
    "infor",
    "inforMusicChanged",
    "currentLanguage",
    "idLanguage",
    "dateTimeChangedSetting",
    "time",
    "date",
    "onMessageRecevied",
    "msg",
    "callMethod",
    "nameMethod",
    "listParam",
    "onReturnHome",
    "onRunAppVideo",
    "onRunAppSetting",
    "onRunAppMusic",
    "inforVideo",
    "requestPauseVideo",
    "isPause",
    "volumeChanged",
    "volume",
    "languageChanged",
    "dateTimeChanged",
    "inforMusic",
    "requestPauseMusic"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDbusHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x06,    1 /* Public */,
       3,    1,  123,    2, 0x06,    2 /* Public */,
       5,    1,  126,    2, 0x06,    4 /* Public */,
       6,    1,  129,    2, 0x06,    6 /* Public */,
       8,    2,  132,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  137,    2, 0x0a,   11 /* Public */,
      13,    2,  140,    2, 0x0a,   13 /* Public */,
      16,    0,  145,    2, 0x0a,   16 /* Public */,
      17,    0,  146,    2, 0x0a,   17 /* Public */,
      18,    0,  147,    2, 0x0a,   18 /* Public */,
      19,    0,  148,    2, 0x0a,   19 /* Public */,
      20,    1,  149,    2, 0x0a,   20 /* Public */,
      21,    1,  152,    2, 0x0a,   22 /* Public */,
      23,    1,  155,    2, 0x0a,   24 /* Public */,
      25,    1,  158,    2, 0x0a,   26 /* Public */,
      26,    2,  161,    2, 0x0a,   28 /* Public */,
      27,    1,  166,    2, 0x0a,   31 /* Public */,
      28,    1,  169,    2, 0x0a,   33 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantList,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject DbusHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDbusHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDbusHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDbusHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DbusHandler, std::true_type>,
        // method 'returnHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inforVideoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'inforMusicChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'currentLanguage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dateTimeChangedSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onMessageRecevied'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'callMethod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QVariant> &, std::false_type>,
        // method 'onReturnHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inforVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestPauseVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'languageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dateTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'inforMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'requestPauseMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void DbusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DbusHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->returnHome(); break;
        case 1: _t->inforVideoChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->inforMusicChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->currentLanguage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->dateTimeChangedSetting((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->onMessageRecevied((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->callMethod((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QVariant>>>(_a[2]))); break;
        case 7: _t->onReturnHome(); break;
        case 8: _t->onRunAppVideo(); break;
        case 9: _t->onRunAppSetting(); break;
        case 10: _t->onRunAppMusic(); break;
        case 11: _t->inforVideo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->requestPauseVideo((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->languageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->dateTimeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->inforMusic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->requestPauseMusic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DbusHandler::*)();
            if (_t _q_method = &DbusHandler::returnHome; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DbusHandler::*)(const QString & );
            if (_t _q_method = &DbusHandler::inforVideoChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DbusHandler::*)(const QString & );
            if (_t _q_method = &DbusHandler::inforMusicChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DbusHandler::*)(const QString & );
            if (_t _q_method = &DbusHandler::currentLanguage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DbusHandler::*)(const QString & , const QString & );
            if (_t _q_method = &DbusHandler::dateTimeChangedSetting; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *DbusHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbusHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDbusHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IFVideoServiceListener"))
        return static_cast< IFVideoServiceListener*>(this);
    if (!strcmp(_clname, "IFSettingServiceListener"))
        return static_cast< IFSettingServiceListener*>(this);
    if (!strcmp(_clname, "IFMusicServiceListener"))
        return static_cast< IFMusicServiceListener*>(this);
    return QObject::qt_metacast(_clname);
}

int DbusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void DbusHandler::returnHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DbusHandler::inforVideoChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DbusHandler::inforMusicChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DbusHandler::currentLanguage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DbusHandler::dateTimeChangedSetting(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
