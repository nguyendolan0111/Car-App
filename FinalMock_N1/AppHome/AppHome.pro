QT += quick dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Translation.cpp \
        dbushandler.cpp \
        main.cpp \
        mycontroller.cpp \
        myhomeapp.cpp \
        mymodelhomeapp.cpp

RESOURCES += qml.qrc \
    translation.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    StatusBar_Interface.h \
    Translation.h \
    dbushandler.h \
    mycontroller.h \
    myhomeapp.h \
    mymodelhomeapp.h


TRANSLATIONS += AppHome_en.ts\
                AppHome_vn.ts


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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Libs/release/ -lFSetting
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Libs/debug/ -lFSetting
else:unix: LIBS += -L$$PWD/Libs/ -lFSetting

INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include
