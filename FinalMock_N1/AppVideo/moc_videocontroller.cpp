/****************************************************************************
** Meta object code from reading C++ file 'videocontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "videocontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videocontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVideoControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVideoControllerENDCLASS = QtMocHelpers::stringData(
    "VideoController",
    "videoSinkChanged",
    "",
    "videoModelChanged",
    "currentVideoChanged",
    "positionChanged",
    "durationChanged",
    "volumeChanged",
    "isPauseChanged",
    "currentVideoIndexChanged",
    "loopPlayChanged",
    "randomPlayChanged",
    "sourceMediaChanged",
    "setInforVideo",
    "showAppChanged",
    "runAppVideo",
    "currentLanguageChanged",
    "idLang",
    "setVideoSink",
    "QVideoSink*",
    "newVideoSink",
    "playVideo",
    "pauseVideo",
    "nextVideo",
    "periousVideo",
    "playVideoWithIndex",
    "index",
    "searchVideo",
    "str",
    "changePosition",
    "newPosiyion",
    "setRandomPlay",
    "newRandomPlay",
    "setLoopPlay",
    "newLoopPlay",
    "onOpenApp",
    "id",
    "onReturnHome",
    "onPause",
    "isPause",
    "setDateStatusBar",
    "date",
    "setTimeStatusBar",
    "time",
    "handleMediaStatusChanged",
    "QMediaPlayer::MediaStatus",
    "status",
    "handlePositionChanged",
    "position",
    "onSourceChangedSendClient",
    "videoSink",
    "videoModel",
    "VideoModel*",
    "currentVideo",
    "Video*",
    "duration",
    "volume",
    "currentVideoIndex",
    "loopPlay",
    "randomPlay",
    "showApp"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
      11,  271, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  212,    2, 0x06,   12 /* Public */,
       3,    0,  213,    2, 0x06,   13 /* Public */,
       4,    0,  214,    2, 0x06,   14 /* Public */,
       5,    0,  215,    2, 0x06,   15 /* Public */,
       6,    0,  216,    2, 0x06,   16 /* Public */,
       7,    0,  217,    2, 0x06,   17 /* Public */,
       8,    0,  218,    2, 0x06,   18 /* Public */,
       9,    0,  219,    2, 0x06,   19 /* Public */,
      10,    0,  220,    2, 0x06,   20 /* Public */,
      11,    0,  221,    2, 0x06,   21 /* Public */,
      12,    0,  222,    2, 0x06,   22 /* Public */,
      13,    0,  223,    2, 0x06,   23 /* Public */,
      14,    0,  224,    2, 0x06,   24 /* Public */,
      15,    0,  225,    2, 0x06,   25 /* Public */,
      16,    1,  226,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  229,    2, 0x0a,   28 /* Public */,
      21,    0,  232,    2, 0x0a,   30 /* Public */,
      22,    0,  233,    2, 0x0a,   31 /* Public */,
      23,    0,  234,    2, 0x0a,   32 /* Public */,
      24,    0,  235,    2, 0x0a,   33 /* Public */,
      25,    1,  236,    2, 0x0a,   34 /* Public */,
      27,    1,  239,    2, 0x0a,   36 /* Public */,
      29,    1,  242,    2, 0x0a,   38 /* Public */,
      31,    1,  245,    2, 0x0a,   40 /* Public */,
      33,    1,  248,    2, 0x0a,   42 /* Public */,
      35,    1,  251,    2, 0x0a,   44 /* Public */,
      37,    0,  254,    2, 0x0a,   46 /* Public */,
      38,    1,  255,    2, 0x0a,   47 /* Public */,
      40,    1,  258,    2, 0x0a,   49 /* Public */,
      42,    1,  261,    2, 0x0a,   51 /* Public */,
      44,    1,  264,    2, 0x08,   53 /* Private */,
      47,    1,  267,    2, 0x08,   55 /* Private */,
      49,    0,  270,    2, 0x08,   57 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void, QMetaType::LongLong,   48,
    QMetaType::Void,

 // properties: name, type, flags
      50, 0x80000000 | 19, 0x0001590b, uint(0), 0,
      51, 0x80000000 | 52, 0x0001590b, uint(1), 0,
      53, 0x80000000 | 54, 0x0001590b, uint(2), 0,
      48, QMetaType::Int, 0x00015903, uint(3), 0,
      55, QMetaType::Int, 0x00015903, uint(4), 0,
      56, QMetaType::Float, 0x00015903, uint(5), 0,
      39, QMetaType::Bool, 0x00015903, uint(6), 0,
      57, QMetaType::Int, 0x00015903, uint(7), 0,
      58, QMetaType::Bool, 0x00015903, uint(8), 0,
      59, QMetaType::Bool, 0x00015903, uint(9), 0,
      60, QMetaType::Bool, 0x00015903, uint(12), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject VideoController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSVideoControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVideoControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVideoControllerENDCLASS_t,
        // property 'videoSink'
        QtPrivate::TypeAndForceComplete<QVideoSink*, std::true_type>,
        // property 'videoModel'
        QtPrivate::TypeAndForceComplete<VideoModel*, std::true_type>,
        // property 'currentVideo'
        QtPrivate::TypeAndForceComplete<Video*, std::true_type>,
        // property 'position'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'duration'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'volume'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'isPause'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'currentVideoIndex'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'loopPlay'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'randomPlay'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'showApp'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VideoController, std::true_type>,
        // method 'videoSinkChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'videoModelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentVideoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'positionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isPauseChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentVideoIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loopPlayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'randomPlayChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sourceMediaChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setInforVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAppChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'runAppVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentLanguageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setVideoSink'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVideoSink *, std::false_type>,
        // method 'playVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'periousVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playVideoWithIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'searchVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'changePosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setRandomPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setLoopPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onOpenApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onReturnHome'
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
        // method 'handleMediaStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>,
        // method 'handlePositionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onSourceChangedSendClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void VideoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->videoSinkChanged(); break;
        case 1: _t->videoModelChanged(); break;
        case 2: _t->currentVideoChanged(); break;
        case 3: _t->positionChanged(); break;
        case 4: _t->durationChanged(); break;
        case 5: _t->volumeChanged(); break;
        case 6: _t->isPauseChanged(); break;
        case 7: _t->currentVideoIndexChanged(); break;
        case 8: _t->loopPlayChanged(); break;
        case 9: _t->randomPlayChanged(); break;
        case 10: _t->sourceMediaChanged(); break;
        case 11: _t->setInforVideo(); break;
        case 12: _t->showAppChanged(); break;
        case 13: _t->runAppVideo(); break;
        case 14: _t->currentLanguageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->setVideoSink((*reinterpret_cast< std::add_pointer_t<QVideoSink*>>(_a[1]))); break;
        case 16: _t->playVideo(); break;
        case 17: _t->pauseVideo(); break;
        case 18: _t->nextVideo(); break;
        case 19: _t->periousVideo(); break;
        case 20: _t->playVideoWithIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->searchVideo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->changePosition((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->setRandomPlay((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->setLoopPlay((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 25: _t->onOpenApp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->onReturnHome(); break;
        case 27: _t->onPause((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->setDateStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->setTimeStatusBar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->handleMediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 31: _t->handlePositionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 32: _t->onSourceChangedSendClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QVideoSink* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::videoSinkChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::videoModelChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::currentVideoChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::positionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::durationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::volumeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::isPauseChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::currentVideoIndexChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::loopPlayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::randomPlayChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::sourceMediaChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::setInforVideo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::showAppChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (VideoController::*)();
            if (_t _q_method = &VideoController::runAppVideo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (VideoController::*)(const QString & );
            if (_t _q_method = &VideoController::currentLanguageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoSink* >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Video* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VideoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVideoSink**>(_v) = _t->videoSink(); break;
        case 1: *reinterpret_cast< VideoModel**>(_v) = _t->videoModel(); break;
        case 2: *reinterpret_cast< Video**>(_v) = _t->currentVideo(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->position(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->duration(); break;
        case 5: *reinterpret_cast< float*>(_v) = _t->volume(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isPause(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->currentVideoIndex(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->loopPlay(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->randomPlay(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->showApp(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVideoSink(*reinterpret_cast< QVideoSink**>(_v)); break;
        case 1: _t->setVideoModel(*reinterpret_cast< VideoModel**>(_v)); break;
        case 2: _t->setCurrentVideo(*reinterpret_cast< Video**>(_v)); break;
        case 3: _t->setPosition(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setDuration(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setVolume(*reinterpret_cast< float*>(_v)); break;
        case 6: _t->setIsPause(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setCurrentVideoIndex(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setLoopPlay(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setRandomPlay(*reinterpret_cast< bool*>(_v)); break;
        case 10: _t->setShowApp(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *VideoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVideoControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VideoController::videoSinkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoController::videoModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VideoController::currentVideoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VideoController::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VideoController::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VideoController::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VideoController::isPauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VideoController::currentVideoIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VideoController::loopPlayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VideoController::randomPlayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VideoController::sourceMediaChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void VideoController::setInforVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void VideoController::showAppChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void VideoController::runAppVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void VideoController::currentLanguageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
