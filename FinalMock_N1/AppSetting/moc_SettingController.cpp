/****************************************************************************
** Meta object code from reading C++ file 'SettingController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SettingController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSettingControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSettingControllerENDCLASS = QtMocHelpers::stringData(
    "SettingController",
    "showAppChanged",
    "",
    "runAppSetting",
    "timeChanged",
    "currentLanguageChanged",
    "idLang",
    "onOpenApp",
    "id",
    "onReturnHome",
    "setDateStatusBar",
    "date",
    "setTimeStatusBar",
    "time",
    "getCurrentLanguage",
    "setLanguage",
    "newLanguage",
    "increaseVolume",
    "decreaseVolume",
    "setCurrentVolume",
    "newVolume",
    "getCurrentVolume",
    "is24hFormat",
    "isCustomFormat",
    "toggle24hFormat",
    "is24h",
    "toggleCustomFormat",
    "isCustom",
    "updateTime",
    "hour",
    "minute",
    "second",
    "day",
    "month",
    "year",
    "getHour",
    "setHour",
    "getMinute",
    "setMinute",
    "getSecond",
    "setSecond",
    "getDay",
    "setDay",
    "getMonth",
    "setMonth",
    "getYear",
    "setYear",
    "showApp"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       1,  271, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  200,    2, 0x06,    2 /* Public */,
       3,    0,  201,    2, 0x06,    3 /* Public */,
       4,    0,  202,    2, 0x06,    4 /* Public */,
       5,    1,  203,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  206,    2, 0x0a,    7 /* Public */,
       9,    0,  209,    2, 0x0a,    9 /* Public */,
      10,    1,  210,    2, 0x0a,   10 /* Public */,
      12,    1,  213,    2, 0x0a,   12 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  216,    2, 0x02,   14 /* Public */,
      15,    1,  217,    2, 0x02,   15 /* Public */,
      17,    0,  220,    2, 0x02,   17 /* Public */,
      18,    0,  221,    2, 0x02,   18 /* Public */,
      19,    1,  222,    2, 0x02,   19 /* Public */,
      21,    0,  225,    2, 0x102,   21 /* Public | MethodIsConst  */,
      22,    0,  226,    2, 0x02,   22 /* Public */,
      23,    0,  227,    2, 0x02,   23 /* Public */,
      24,    1,  228,    2, 0x02,   24 /* Public */,
      26,    1,  231,    2, 0x02,   26 /* Public */,
      28,    6,  234,    2, 0x02,   28 /* Public */,
      35,    0,  247,    2, 0x02,   35 /* Public */,
      36,    1,  248,    2, 0x02,   36 /* Public */,
      37,    0,  251,    2, 0x02,   38 /* Public */,
      38,    1,  252,    2, 0x02,   39 /* Public */,
      39,    0,  255,    2, 0x02,   41 /* Public */,
      40,    1,  256,    2, 0x02,   42 /* Public */,
      41,    0,  259,    2, 0x02,   44 /* Public */,
      42,    1,  260,    2, 0x02,   45 /* Public */,
      43,    0,  263,    2, 0x02,   47 /* Public */,
      44,    1,  264,    2, 0x02,   48 /* Public */,
      45,    0,  267,    2, 0x02,   50 /* Public */,
      46,    1,  268,    2, 0x02,   51 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   29,   30,   31,   32,   33,   34,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   34,

 // properties: name, type, flags
      47, QMetaType::Bool, 0x00015903, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingControllerENDCLASS_t,
        // property 'showApp'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingController, std::true_type>,
        // method 'showAppChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'runAppSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentLanguageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onOpenApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onReturnHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setDateStatusBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setTimeStatusBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getCurrentLanguage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setLanguage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'increaseVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'decreaseVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCurrentVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getCurrentVolume'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'is24hFormat'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'isCustomFormat'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'toggle24hFormat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'toggleCustomFormat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getHour'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setHour'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getMinute'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMinute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getSecond'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSecond'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getDay'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setDay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getMonth'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMonth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getYear'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setYear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SettingController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showAppChanged(); break;
        case 1: _t->runAppSetting(); break;
        case 2: _t->timeChanged(); break;
        case 3: _t->currentLanguageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->onOpenApp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onReturnHome(); break;
        case 6: _t->setDateStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setTimeStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: { QString _r = _t->getCurrentLanguage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setLanguage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->increaseVolume(); break;
        case 11: _t->decreaseVolume(); break;
        case 12: _t->setCurrentVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: { int _r = _t->getCurrentVolume();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->is24hFormat();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->isCustomFormat();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->toggle24hFormat((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->toggleCustomFormat((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->updateTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 19: { int _r = _t->getHour();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->setHour((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: { int _r = _t->getMinute();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->setMinute((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: { int _r = _t->getSecond();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->setSecond((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: { int _r = _t->getDay();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->setDay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: { int _r = _t->getMonth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->setMonth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: { int _r = _t->getYear();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->setYear((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingController::*)();
            if (_t _q_method = &SettingController::showAppChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SettingController::*)();
            if (_t _q_method = &SettingController::runAppSetting; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SettingController::*)();
            if (_t _q_method = &SettingController::timeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SettingController::*)(const QString & );
            if (_t _q_method = &SettingController::currentLanguageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SettingController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->showApp(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SettingController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowApp(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SettingController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SettingController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SettingController::showAppChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SettingController::runAppSetting()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SettingController::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SettingController::currentLanguageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
