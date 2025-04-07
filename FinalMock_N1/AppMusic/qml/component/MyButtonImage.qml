import QtQuick 2.15

Rectangle {
    id: root
    width: 50
    height: 50
    color: "transparent"

    property string image_source: ""
    property variant bFunction: null
    property int sizeImage: root.width
    signal myClicked()


    Image {
        id: image_button
        width: parent.width
        height: parent.height
        source: image_source
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            myClicked()
        }

        onEntered: {
            image_button.width = sizeImage + 10
            image_button.height = sizeImage + 10
        }

        onExited: {
            image_button.width = sizeImage
            image_button.height = sizeImage
        }
    }
}
