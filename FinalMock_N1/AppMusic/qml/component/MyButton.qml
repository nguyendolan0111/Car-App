import QtQuick

Rectangle {
    width: 100
    height: 50
    border.color: "black"
    property alias textContent: txt.text
    property alias textSize: txt.font.pixelSize

    Text {
        id: txt
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.scale = 1.1
            parent.opacity = 0.6
        }
        onExited: {
            parent.scale = 1.0
            parent.opacity = 1.0
        }
    }
}
