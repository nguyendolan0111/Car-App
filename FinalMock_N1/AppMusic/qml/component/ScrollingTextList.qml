import QtQuick 2.15

Rectangle {
    id: recText
    width: parent.width
    height: parent.height/3
    color: "transparent"
    clip: true

    signal myFinish();

    property string textContent: ""
    property string tỉtleText: ""
    property bool isRunning: false
    property int textSize: 15
    property int posX: 0
    property bool isConditionRun: scrollingText.implicitWidth >= recText.width

    Text {
        id: scrollingText
        text: tỉtleText + textContent
        font.bold: true
        x: posX
        font.pixelSize: textSize
        color: "black"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: isConditionRun ? undefined : parent.left
        width: isRunning ? scrollingText.implicitWidth : recText.width
        elide: isRunning ? Text.ElideNone : Text.ElideRight
    }

    SequentialAnimation {
        running: isRunning

        alwaysRunToEnd: true

        NumberAnimation {
            id: animationNumber
            target: scrollingText
            property: "x"
            from: 30
            to: -scrollingText.width
            duration: 6000
        }

        onFinished: {
            myFinish()
            scrollingText.x = 0
        }
    }
}
