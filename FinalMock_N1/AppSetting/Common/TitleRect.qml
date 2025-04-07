import QtQuick 2.15

Rectangle{
    id:rootTitle
    property string titleText
    property string colorTitleRect
    property string colorTitleText
    signal clicked()
    border.width: 4
    border.color:"gray"
    color:colorTitleRect
    Text{
        id:text
        text:titleText
        font.pixelSize: 25
        font.bold: true
        font.family: "Ubuntu"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        color:colorTitleText

    }
    MouseArea{
        anchors.fill:parent
        hoverEnabled: true
        onClicked: {
            rootTitle.clicked()
        }
    }
}
