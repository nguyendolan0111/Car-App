/****************************************************************************
** Meta object code from reading C++ file 'MusicPlayerController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/controller/MusicPlayerController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicPlayerController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMusicPlayerControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMusicPlayerControllerENDCLASS = QtMocHelpers::stringData(
    "MusicPlayerController",
    "D-bus Interface",
    "com.music.MusicServiceInterface",
    "currentSongChanged",
    "",
    "currentSongIndexChanged",
    "index",
    "currentIndexChanged",
    "radomChanged",
    "loopChanged",
    "volumnChanged",
    "pauseChanged",
    "setInforScreen",
    "currentLanguageChanged",
    "idLang",
    "getModel",
    "MusicListModel*",
    "SearchSong",
    "searchString",
    "getSearchModel",
    "requestPlay",
    "requestPause",
    "requestStop",
    "requestNext",
    "requestPrevious",
    "requestFastForward",
    "requestFastBackward",
    "setPosition",
    "position",
    "changePosition",
    "StatusChanged",
    "QMediaPlayer::MediaStatus",
    "status",
    "StatusPlayChange",
    "QMediaPlayer::PlaybackState",
    "setPlaySong",
    "sendMusicInfoToHome",
    "onPause",
    "isPause",
    "setDateStatusBar",
    "date",
    "setTimeStatusBar",
    "time",
    "saveSetting",
    "setVolumn",
    "newVolumn",
    "currentSong",
    "MusicPlaybackModel*",
    "currentIndex",
    "random",
    "loop",
    "volumn",
    "pause"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMusicPlayerControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      30,   16, // methods
       6,  250, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  196,    4, 0x06,    7 /* Public */,
       5,    1,  197,    4, 0x06,    8 /* Public */,
       7,    0,  200,    4, 0x06,   10 /* Public */,
       8,    0,  201,    4, 0x06,   11 /* Public */,
       9,    0,  202,    4, 0x06,   12 /* Public */,
      10,    0,  203,    4, 0x06,   13 /* Public */,
      11,    0,  204,    4, 0x06,   14 /* Public */,
      12,    0,  205,    4, 0x06,   15 /* Public */,
      13,    1,  206,    4, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  209,    4, 0x0a,   18 /* Public */,
      17,    1,  210,    4, 0x0a,   19 /* Public */,
      19,    0,  213,    4, 0x0a,   21 /* Public */,
      20,    0,  214,    4, 0x0a,   22 /* Public */,
      21,    0,  215,    4, 0x0a,   23 /* Public */,
      22,    0,  216,    4, 0x0a,   24 /* Public */,
      23,    0,  217,    4, 0x0a,   25 /* Public */,
      24,    0,  218,    4, 0x0a,   26 /* Public */,
      25,    0,  219,    4, 0x0a,   27 /* Public */,
      26,    0,  220,    4, 0x0a,   28 /* Public */,
      27,    1,  221,    4, 0x0a,   29 /* Public */,
      29,    1,  224,    4, 0x0a,   31 /* Public */,
      30,    1,  227,    4, 0x0a,   33 /* Public */,
      33,    1,  230,    4, 0x0a,   35 /* Public */,
      35,    1,  233,    4, 0x0a,   37 /* Public */,
      36,    0,  236,    4, 0x0a,   39 /* Public */,
      37,    1,  237,    4, 0x0a,   40 /* Public */,
      39,    1,  240,    4, 0x0a,   42 /* Public */,
      41,    1,  243,    4, 0x0a,   44 /* Public */,
      43,    0,  246,    4, 0x0a,   46 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      44,    1,  247,    4, 0x02,   47 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    0x80000000 | 16,
    QMetaType::Void, QMetaType::QString,   18,
    0x80000000 | 16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::LongLong,   28,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 34,   32,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Float,   45,

 // properties: name, type, flags
      46, 0x80000000 | 47, 0x0001590b, uint(0), 0,
      48, QMetaType::Int, 0x00015903, uint(2), 0,
      49, QMetaType::Bool, 0x00015903, uint(3), 0,
      50, QMetaType::Bool, 0x00015903, uint(4), 0,
      51, QMetaType::Float, 0x00015903, uint(5), 0,
      52, QMetaType::Bool, 0x00015903, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicPlayerController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMusicPlayerControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMusicPlayerControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMusicPlayerControllerENDCLASS_t,
        // property 'currentSong'
        QtPrivate::TypeAndForceComplete<MusicPlaybackModel*, std::true_type>,
        // property 'currentIndex'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'random'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'loop'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'volumn'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'pause'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicPlayerController, std::true_type>,
        // method 'currentSongChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentSongIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'radomChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loopChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'volumnChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setInforScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentLanguageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getModel'
        QtPrivate::TypeAndForceComplete<MusicListModel *, std::false_type>,
        // method 'SearchSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getSearchModel'
        QtPrivate::TypeAndForceComplete<MusicListModel *, std::false_type>,
        // method 'requestPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestNext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestPrevious'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestFastForward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestFastBackward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changePosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'StatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>,
        // method 'StatusPlayChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::PlaybackState, std::false_type>,
        // method 'setPlaySong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendMusicInfoToHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setDateStatusBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setTimeStatusBar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'saveSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVolumn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void MusicPlayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicPlayerController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentSongChanged(); break;
        case 1: _t->currentSongIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->currentIndexChanged(); break;
        case 3: _t->radomChanged(); break;
        case 4: _t->loopChanged(); break;
        case 5: _t->volumnChanged(); break;
        case 6: _t->pauseChanged(); break;
        case 7: _t->setInforScreen(); break;
        case 8: _t->currentLanguageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { MusicListModel* _r = _t->getModel();
            if (_a[0]) *reinterpret_cast< MusicListModel**>(_a[0]) = std::move(_r); }  break;
        case 10: _t->SearchSong((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: { MusicListModel* _r = _t->getSearchModel();
            if (_a[0]) *reinterpret_cast< MusicListModel**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->requestPlay(); break;
        case 13: _t->requestPause(); break;
        case 14: _t->requestStop(); break;
        case 15: _t->requestNext(); break;
        case 16: _t->requestPrevious(); break;
        case 17: _t->requestFastForward(); break;
        case 18: _t->requestFastBackward(); break;
        case 19: _t->setPosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->changePosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 21: _t->StatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 22: _t->StatusPlayChange((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        case 23: _t->setPlaySong((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->sendMusicInfoToHome(); break;
        case 25: _t->onPause((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 26: _t->setDateStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->setTimeStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->saveSetting(); break;
        case 29: _t->setVolumn((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::currentSongChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)(int );
            if (_t _q_method = &MusicPlayerController::currentSongIndexChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::currentIndexChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::radomChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::loopChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::volumnChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::pauseChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)();
            if (_t _q_method = &MusicPlayerController::setInforScreen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MusicPlayerController::*)(const QString & );
            if (_t _q_method = &MusicPlayerController::currentLanguageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MusicPlaybackModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MusicPlayerController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< MusicPlaybackModel**>(_v) = _t->currentSong(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->curentIndex(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->random(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->loop(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->volumn(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->pause(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MusicPlayerController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentSong(*reinterpret_cast< MusicPlaybackModel**>(_v)); break;
        case 1: _t->setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setRandom(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setLoop(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setVolumn(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setPause(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *MusicPlayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMusicPlayerControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicPlayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MusicPlayerController::currentSongChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicPlayerController::currentSongIndexChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicPlayerController::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicPlayerController::radomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MusicPlayerController::loopChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MusicPlayerController::volumnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MusicPlayerController::pauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MusicPlayerController::setInforScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MusicPlayerController::currentLanguageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
