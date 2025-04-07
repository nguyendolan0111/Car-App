QT += qml quick

TEMPLATE = lib
DEFINES += STATUSBAR_PLUGIN_LIBRARY
TARGET = MyStatusBar

CONFIG += plugin c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    statusbar_plugin.cpp

HEADERS += \
    StatusBar_Interface.h \
    statusbar_plugin.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc
