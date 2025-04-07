QT += quick multimedia \
    widgets \
    dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/AppEngine.cpp \
        src/Translation.cpp \
        src/controller/MusicDbusHandler.cpp \
        src/controller/MusicListController.cpp \
        src/controller/MusicPlayerController.cpp \
        src/controller/ScreenController.cpp \
        src/list/MusicListModel.cpp \
        src/list/SongInfo.cpp \
        src/model/BasePlaybackModel.cpp \
        src/model/MusicPlaybackModel.cpp \
        src/model/ScreenModel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    translation.qrc

TRANSLATIONS += \
    AppMusic_en.ts \
    AppMusic_vn.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/AppEngine.h \
    src/StatusBar_Interface.h \
    src/Translation.h \
    src/controller/MusicDbusHandler.h \
    src/controller/MusicListController.h \
    src/controller/MusicPlayerController.h \
    src/controller/ScreenController.h \
    src/list/MusicListModel.h \
    src/list/SongInfo.h \
    src/model/BasePlaybackModel.h \
    src/model/MusicPlaybackModel.h \
    src/model/ScreenModel.h \
    src/common/appdefines.h \
    src/common/loghelper.h




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFHome
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFHome
else:unix: LIBS += -L$$PWD/Libs/ -lFHome

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFVideo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFVideo
else:unix: LIBS += -L$$PWD/Libs/ -lFVideo

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFSetting
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFSetting
else:unix: LIBS += -L$$PWD/Libs/ -lFSetting

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
