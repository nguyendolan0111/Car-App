import QtQuick

Rectangle {
    width: 100
    height: 100
    clip: true
    property alias textContent: txt.text
    property alias textSize: txt.font.pixelSize
    Text {
        id: txt
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
    }
}
