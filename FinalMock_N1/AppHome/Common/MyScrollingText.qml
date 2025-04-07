import QtQuick 2.15

Rectangle {
    property string myText
    property bool isRunning: false
    property bool isConditionRun: scrollingText.implicitWidth >= recText.width

    signal myFinished();

    id: recText
    color: "transparent"
    clip: true

    Text {
        id: scrollingText
        width: isRunning ? scrollingText.implicitWidth : recText.width
        elide: isRunning ? Text.ElideNone : Text.ElideRight
        anchors.left: isConditionRun ? undefined : parent.left
        horizontalAlignment: !isConditionRun ? Text.AlignHCenter : undefined
        text: myText
        font.bold: true
        font.pixelSize: 25
        color: "black"
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
            scrollingText.x = 0
            myFinished()
        }
    }
}
