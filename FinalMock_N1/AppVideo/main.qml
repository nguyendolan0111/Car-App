import QtQuick 2.15
import QtQuick.Window 2.15
import MyStatusBarPlugin 1.0

Window {
    id: root
    width: 1200
    height: 800
    visible: videoController.showApp
    title: qsTr("App Video")

    Item {
        id: keyboard
        anchors.fill: parent
        focus: true

        Keys.onPressed: (event) => handleKeyPress(event)

        function handleKeyPress(event) {
            switch (event.key) {
            case Qt.Key_Left:
                moveLeft();
                event.accepted = true;
                forceActiveFocus();
                break;
            case Qt.Key_Right:
                moveRight();
                event.accepted = true;
                forceActiveFocus();
                break;
            case Qt.Key_Space:
                togglePlayPause();
                event.accepted = true;
                forceActiveFocus();
                break;
            case Qt.Key_Escape:
                videoScreen.isFullScreen = false
                if (root.visibility === Window.FullScreen) {
                    root.visibility = Window.Windowed
                }
                event.accepted = true;
                forceActiveFocus();
                break;
            case Qt.Key_F:
                videoScreen.isFullScreen = true
                if (root.visibility !== Window.FullScreen) {
                    root.visibility = Window.FullScreen
                }
                event.accepted = true;
                forceActiveFocus();
                break;
            }
        }
    }

    ListModel {
        id: listTextDirection
        ListElement {txt: qsTr("Video>Play")}
    }


    ListModel {
        id: screenStatus
        ListElement { videoScreenVisible: true; listScreenVisible: false}
    }

    ListModel{
        id: modelListButtonStatusbar
        ListElement {
            image : "qrc:/Icon/back.png";
            visibleBtn: true
            func : function() {
                if (listTextDirection.count > 1) {
                    listTextDirection.remove(listTextDirection.count - 1)
                    screenStatus.remove(screenStatus.count - 1)
                    if(screenStatus.get(screenStatus.count - 1).videoScreenVisible === true){
                        keyboard.focus = true
                    }
                    else{
                        keyboard.focus = false
                    }

                    modelListButtonStatusbar.setProperty(2, "visibleBtn", true)
                    modelListButtonStatusbar.setProperty(3, "visibleBtn", true)
                }
            }
        }

        ListElement {
            image : "qrc:/Icon/home.png";
            visibleBtn: true
            func : function() {
                videoController.onReturnHome()
            }
        }

        ListElement {
            image : "qrc:/Icon/zoomOut.png";
            visibleBtn: true
            func : function() {
                videoScreen.isFullScreen = true
                fullScreen()
            }
        }

        ListElement {
            image : "qrc:/Icon/list.png";
            visibleBtn: true
            func : function() {
                keyboard.focus = false
                listTextDirection.append({txt: qsTr("Video>List")})
                screenStatus.append({ videoScreenVisible: false, listScreenVisible: true})
                modelListButtonStatusbar.setProperty(2, "visibleBtn", false)
                modelListButtonStatusbar.setProperty(3, "visibleBtn", false)
            }
        }
    }

    MyStatusBar {
        id: statusBar
        width: parent.width
        height: 80
        anchors.top: parent.top
        textDirect: listTextDirection.get(listTextDirection.count-1).txt
        modelList: modelListButtonStatusbar
    }

    VideoScreen{
        id: videoScreen
        width: parent.width
        height: isFullScreen ? parent.height : (parent.height - statusBar.height)
        visible: screenStatus.get(screenStatus.count - 1).videoScreenVisible
        isFullScreen: false

        anchors.top: isFullScreen ? parent.top : statusBar.bottom

        onToggleFullScreen: {
            fullScreen()
        }
    }

    ListScreen{
        id: listScreen
        width: parent.width
        height: parent.height - statusBar.height
        visible: screenStatus.get(screenStatus.count - 1).listScreenVisible

        anchors{
            top: statusBar.bottom
            horizontalCenter: parent.horizontalCenter
        }
    }

    function fullScreen(){
        if (root.visibility === Window.FullScreen) {
            root.visibility = Window.Windowed
        } else {
            root.visibility = Window.FullScreen
        }
    }

    function moveLeft() {
        console.log("move left");
        if(videoController.position !== 0){
            videoController.changePosition(videoController.position - 1);
        }
    }

    function moveRight() {
        console.log("move right");
        videoController.changePosition(videoController.position + 1);
    }

    function togglePlayPause() {
        if (videoController.isPause) {
            videoController.playVideo();
        } else {
            videoController.pauseVideo();
        }
    }
}
