import QtQuick 2.15

Rectangle {
    id: recText
    width: parent.width
    height: parent.height/3
    color: "transparent"
    clip: true

    signal myClicked();
    signal myFinished();

    property string myText
    property double pixelSizeText
    property int currentIndexSong: 1
    property int indexListView: 0
    property bool isRunning: false
    property int posX: 0
    property bool isConditionRun: scrollingText.implicitWidth >= recText.width

    Text {
        id: scrollingText
        text: myText
        font.bold: true
        x: posX
        font.pixelSize: pixelSizeText
        color: currentIndexSong === indexListView ? "#06D001" : "black"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: isConditionRun ? undefined : parent.left
        width: isRunning ? scrollingText.implicitWidth : recText.width
        elide: isRunning ? Text.ElideNone : Text.ElideRight
    }

    MouseArea{
        anchors.fill: parent

        onClicked: {
            myClicked()
        }
    }

    SequentialAnimation {
        running: isRunning

        NumberAnimation {
            id: animationNumber
            target: scrollingText
            property: "x"
            from: 30
            to: -scrollingText.width
            duration: 6000
        }

        onFinished: {
            myFinished()
            scrollingText.x = 0
        }
    }

    function onScrollingTextPos(){
        scrollingText.x = 0
    }
}
