import QtQuick 2.15
import QtQuick.Controls 2.15
import MyStatusBarPlugin 1.0
import QtQuick.Window 2.15
import "Common"

ApplicationWindow {
    width: 1200
    height: 800
    visible: MyController.showApp
    title: qsTr("App Home")

    Connections{
        target: MyController

        function onInforVideoChanged(){
            loader1.setSource("qrc:/Page1.qml");
        }

        function onInforMusicChanged(){
            loader1.setSource("qrc:/Page1.qml");
        }
    }

    ListModel{
        id: modelListButtonStatusbar
        ListElement {
            image : "qrc:/IconApp/home.png";
            visibleBtn: false
            func : function() {
                swipeView.currentIndex = 0
            }
        }
    }

    MyStatusBar {
        id: statusBar
        width: parent.width
        height: 80
        anchors.top: parent.top
        textDirect: ""
        modelList: modelListButtonStatusbar
    }

    SwipeView {
        id: swipeView
        width: parent.width
        height: parent.height - statusBar.height
        anchors.top: statusBar.bottom

        Item {
            Loader {
                id: loader1
                anchors.fill: parent
                source: "qrc:/Page1.qml"
            }
        }

        Item {
            Loader {
                id: loader2
                anchors.fill: parent
                source: "qrc:/Page2.qml"
            }
        }

        onCurrentIndexChanged: {
            console.log("Current Page Index:", currentIndex);
            if (currentIndex === 0) {
                modelListButtonStatusbar.setProperty(0, "visibleBtn", false)
                MyController.myModelApp.currentPage = 1
                console.log("Page 1 is loaded");
            } else if (currentIndex === 1) {
                modelListButtonStatusbar.setProperty(0, "visibleBtn", true)
                MyController.myModelApp.currentPage = 2
                console.log("Page 2 is loaded");
            }
        }
    }

    Row {
        id: customPageIndicator
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Repeater {
            model: swipeView.count

            Rectangle {
                width: 50
                height: 15
                color: swipeView.currentIndex === index ? "#06D001" : "white"
                border.color: "black"
                border.width: 1
            }
        }
    }

    Component.onCompleted: {
        MyController.myModelApp.currentPage = 1;
    }
}

