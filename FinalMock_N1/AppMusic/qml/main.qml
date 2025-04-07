import QtQuick 2.15
import QtQuick.Controls 2.15
import MyStatusBarPlugin 1.0
import QtQuick.Window 2.15
import "./screen"
Window {
    id: root
    width: 1200
    height: 800
    visible: SCREEN_CTRL.isShowApp
    title: qsTr("App Music")

    function reloadScreen(screenName) {
        if (screenName === "qrc:/qml/screen/MusicPlayerScreen.qml") {
            playScreen.visible = true
            loader.source = ""
        } else {
            loader.source = screenName
        }
    }

    ListModel {
        id: listTextDirection
        ListElement {txt: qsTr("Music>Play")}
    }

    ListModel{
        id: modelListButtonStatusbar
        ListElement {
            image : "qrc:/image/back.png";
            visibleBtn: true
            func : function() {
                SCREEN_CTRL.popScreen()
                if (listTextDirection.count > 1) {
                    listTextDirection.remove(listTextDirection.count -1)
                }
                if(listTextDirection.get(listTextDirection.count - 1).txt === "Music>Play"){
                    modelListButtonStatusbar.setProperty(2, "visibleBtn", true)
                    modelListButtonStatusbar.setProperty(3, "visibleBtn", true)
                }
            }
        }

        ListElement {
            image : "qrc:/image/home.png";
            visibleBtn: true
            func : function() {
                SCREEN_CTRL.onReturnHome()
            }
        }

        ListElement {
            image : "qrc:/image/list.png";
            visibleBtn: true
            func : function() {
                modelListButtonStatusbar.setProperty(2, "visibleBtn", false)
                modelListButtonStatusbar.setProperty(3, "visibleBtn", true)
                SCREEN_CTRL.pushScreen(1)
                listTextDirection.append({txt: qsTr("Music>List")})
                playScreen.visible = false
            }
        }

        ListElement {
            image : "qrc:/image/search.png";
            visibleBtn: true
            func : function() {
                modelListButtonStatusbar.setProperty(2, "visibleBtn", true)
                modelListButtonStatusbar.setProperty(3, "visibleBtn", false)
                SCREEN_CTRL.pushScreen(2)
                listTextDirection.append({txt: qsTr("Music>Search")})
                playScreen.visible = false
            }
        }
    }

    MyStatusBar {
        id: rect_statusBar
        width: parent.width
        height: 80
        anchors.top: parent.top
        textDirect: listTextDirection.get(listTextDirection.count-1).txt + MyTranslation.entryString
        modelList: modelListButtonStatusbar
    }

    Rectangle {
        width: parent.width
        height: parent.height - rect_statusBar.height
        color: "lightgray"
        anchors.top: rect_statusBar.bottom

        MusicPlayerScreen{
            id: playScreen
            width: parent.width
            height: parent.height

            Item {
                id: keyboard
                anchors.fill: parent
                focus: true

                Keys.onPressed: (event) => handleKeyPress(event)

                function handleKeyPress(event) {
                    switch (event.key) {
                    case Qt.Key_Left:
                        PlayerControl.requestFastBackward()
                        event.accepted = true;
                        forceActiveFocus();
                        break;
                    case Qt.Key_Right:
                        PlayerControl.requestFastForward()
                        event.accepted = true;
                        forceActiveFocus();
                        break;
                    case Qt.Key_Space:
                        if (PlayerControl.pause === false) {
                            PlayerControl.requestPause()
                        } else {
                            PlayerControl.requestPlay()
                        }
                        event.accepted = true;
                        forceActiveFocus();
                        break;
                    }
                }
            }
        }

        Loader{
            id: loader
            //anchors.fill: parent
            width: parent.width
            height: parent.height
            source: "./screen/MusicPlayerScreen.qml"
        }
    }
}
