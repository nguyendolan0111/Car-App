import QtQuick 2.15

Rectangle{
    id: button
    width: 60
    height: 60
    color: "gray"
    opacity: 0.9
    radius: 30

    property string sourceImage: ""
    property int sizeImage: 40
    property double valueOpacity: 1
    signal myClicked()


    Image {
        id: image
        width: sizeImage
        height: sizeImage
        source: sourceImage
        opacity: valueOpacity
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            button.myClicked()
        }

        onEntered: {
            image.width = sizeImage + 10
            image.height = sizeImage + 10
        }

        onExited: {
            image.width = sizeImage
            image.height = sizeImage
        }
    }
}
