import QtQuick 2.15

Rectangle{
    id:rect1
    signal click()
    property string textVolume
    width: 50
    height: 50
    radius: 25
    color:"blue"


    Text{
        text:textVolume
        font.family: "Ubuntu"
        font.pixelSize: 50
        anchors.centerIn: parent
        color: "white"
        font.bold: true

    }
    MouseArea{
        anchors.fill:parent
        hoverEnabled: true
        onClicked: {
            rect1.click()
        }

        onEntered: {
            rect1.color = "lightblue"
        }

        onExited: {
            rect1.color = "blue"
        }
    }

}
