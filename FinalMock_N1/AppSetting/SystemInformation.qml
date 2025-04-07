import QtQuick 2.15

Rectangle{
    id:rectInformation
    width: 800
    height: 400
    Image {
        id: imageInfor
        anchors{
            left: rectInformation.left
            leftMargin: 10
            top: rectInformation.top
            topMargin: 10
        }
        width: 250
        height: 250
        source: "qrc:/image/information.jpg"
    }

    Text{
        text: qsTr("Please using mobile phone to check Qr code")
        font.pixelSize: 20
        font.bold: true
        color:"gray"
        font.family: "Ubuntu"
        anchors{
            left:imageInfor.right
            leftMargin: 15
            verticalCenter: imageInfor.verticalCenter
        }
    }

}
