/****************************************************************************
** Meta object code from reading C++ file 'MusicDbusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/controller/MusicDbusHandler.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicDbusHandler.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMusicDbusHandlerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMusicDbusHandlerENDCLASS = QtMocHelpers::stringData(
    "MusicDbusHandler",
    "openApp",
    "",
    "app",
    "pauseApp",
    "isPause",
    "volumeChangedSetting",
    "volume",
    "currentLanguage",
    "idLanguage",
    "dateTimeChangedSetting",
    "time",
    "date",
    "onMessageRecevied",
    "msg",
    "setShowApp",
    "idApp",
    "onMusicInfo",
    "onRunAppHome",
    "onRunAppVideo",
    "onRunAppSetting",
    "onOpenApp",
    "requestPauseVideo",
    "inforVideo",
    "infor",
    "volumeChanged",
    "languageChanged",
    "dateTimeChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMusicDbusHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       4,    1,  119,    2, 0x06,    3 /* Public */,
       6,    1,  122,    2, 0x06,    5 /* Public */,
       8,    1,  125,    2, 0x06,    7 /* Public */,
      10,    2,  128,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  133,    2, 0x0a,   12 /* Public */,
      15,    1,  136,    2, 0x0a,   14 /* Public */,
      17,    0,  139,    2, 0x0a,   16 /* Public */,
      18,    0,  140,    2, 0x0a,   17 /* Public */,
      19,    0,  141,    2, 0x0a,   18 /* Public */,
      20,    0,  142,    2, 0x0a,   19 /* Public */,
      21,    1,  143,    2, 0x0a,   20 /* Public */,
      22,    1,  146,    2, 0x0a,   22 /* Public */,
      23,    1,  149,    2, 0x0a,   24 /* Public */,
      25,    1,  152,    2, 0x0a,   26 /* Public */,
      26,    1,  155,    2, 0x0a,   28 /* Public */,
      27,    2,  158,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicDbusHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMusicDbusHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMusicDbusHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMusicDbusHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicDbusHandler, std::true_type>,
        // method 'openApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'pauseApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'volumeChangedSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'setShowApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onMusicInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRunAppSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'requestPauseVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'inforVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'languageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'dateTimeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MusicDbusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicDbusHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openApp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->pauseApp((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->volumeChangedSetting((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->currentLanguage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->dateTimeChangedSetting((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->onMessageRecevied((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->setShowApp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->onMusicInfo(); break;
        case 8: _t->onRunAppHome(); break;
        case 9: _t->onRunAppVideo(); break;
        case 10: _t->onRunAppSetting(); break;
        case 11: _t->onOpenApp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->requestPauseVideo((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->inforVideo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->languageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->dateTimeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicDbusHandler::*)(int );
            if (_t _q_method = &MusicDbusHandler::openApp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicDbusHandler::*)(bool );
            if (_t _q_method = &MusicDbusHandler::pauseApp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicDbusHandler::*)(int );
            if (_t _q_method = &MusicDbusHandler::volumeChangedSetting; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicDbusHandler::*)(const QString & );
            if (_t _q_method = &MusicDbusHandler::currentLanguage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MusicDbusHandler::*)(const QString & , const QString & );
            if (_t _q_method = &MusicDbusHandler::dateTimeChangedSetting; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *MusicDbusHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicDbusHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMusicDbusHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IFHomeServiceListener"))
        return static_cast< IFHomeServiceListener*>(this);
    if (!strcmp(_clname, "IFVideoServiceListener"))
        return static_cast< IFVideoServiceListener*>(this);
    if (!strcmp(_clname, "IFSettingServiceListener"))
        return static_cast< IFSettingServiceListener*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicDbusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MusicDbusHandler::openApp(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicDbusHandler::pauseApp(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicDbusHandler::volumeChangedSetting(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MusicDbusHandler::currentLanguage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MusicDbusHandler::dateTimeChangedSetting(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
