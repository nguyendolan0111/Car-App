import QtQuick 2.15

Rectangle {
    id: rootRect
    width: 50
    height: 50
    color: "transparent"

    property var myFunc: function(){}
    property string sourceImage
    property int sizeImage: rootRect.width

    Image{
        id: image
        width: sizeImage
        height: sizeImage
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        source: sourceImage
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

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
