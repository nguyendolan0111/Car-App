QT += quick dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        LanguageModel.cpp \
        SettingController.cpp \
        TimeSettingModel.cpp \
        Translation.cpp \
        VolumeModel.cpp \
        dbushandler.cpp \
        main.cpp

RESOURCES += qml.qrc \
    translation.qrc

TRANSLATIONS += AppSetting_en.ts\
                AppSetting_vn.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    LanguageModel.h \
    SettingController.h \
    StatusBar_Interface.h \
    TimeSettingModel.h \
    Translation.h \
    VolumeModel.h \
    dbushandler.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFHome
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFHome
else:unix: LIBS += -L$$PWD/Libs/ -lFHome

INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFVideo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFVideo
else:unix: LIBS += -L$$PWD/Libs/ -lFVideo

INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFMusic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFMusic
else:unix: LIBS += -L$$PWD/Libs/ -lFMusic

INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include
