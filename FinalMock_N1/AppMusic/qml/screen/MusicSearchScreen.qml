import QtQuick 2.15
import QtQuick.Controls
import "qrc:/qml/component"
Item {
    width: parent.width
    height: parent.height
    Rectangle {
        id: rectSearch
        width: parent.width/2
        height: parent.height
        color: "transparent"
        TextField {
            id: textSearch
            width: parent.width - 40
            height: 50
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 25
            color: "black"
            focus: true
            background: Rectangle {
                id: background_search
                anchors.fill: parent
                border.color: "black"
            }
            onTextChanged: {
                PlayerControl.SearchSong(textSearch.text)
            }
        }
        MyButton {
            id: btn_search
            width: 150
            height: 50
            textContent: qsTr("Search")
            textSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: textSearch.bottom
            anchors.topMargin: 30
        }
    }

    Rectangle {
        id: rectList
        width: parent.width/2
        height: parent.height
        color: "transparent"
        anchors.left: rectSearch.right
        border.width: 1
        ListView {
            id: listview
            width: rectList.width
            height: rectList.height
            clip: true
            currentIndex: PlayerControl.currentIndex
            model: SearchModel
            delegate: Rectangle{
                width: rectList.width
                height: 100
                border.width: 1
                color: "transparent"

                AnimatedImage {
                    id: coverImage
                    width: 80
                    height: 80
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    source: PlayerControl.currentIndex === songID ? "qrc:/image/run.gif" : coverArt
                }

                ScrollingTextList {
                    width: parent.width -coverImage.width - 20
                    height: 80
                    textContent: fileName
                    color: "transparent"
                    textSize: 20
                    anchors.left: coverImage.right
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    isRunning: listview.currentIndex === index
                    textX: if (listview.currentIndex !==index) return 0
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    enabled: listview.currentIndex !== index
                    onClicked: {
                        listview.currentIndex = index
                        PlayerControl.setPlaySong(songID)
                    }
                    onEntered: {
                            parent.color = "white"
                    }
                    onExited:{
                            parent.color = "transparent"
                    }

                }
            }

        }
    }
}
