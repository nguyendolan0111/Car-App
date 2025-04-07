import QtQuick 2.15
import QtQuick.Controls 2.15
Rectangle{
    id:rectRoot
    property bool check
    property string textLanguage
    property bool visibleRadio
    property string colorTextTitle
    signal click()
    width: 400
    height: 100
    RadioButton{
        id:radio
        indicator: Rectangle {
            width: 40 // Kích thước rộng của hộp
            height: 40 // Kích thước cao của hộp
            radius: 20
            border.color: "gray"
            border.width: 2

            Rectangle{
                width: 20
                height: 20
                radius: 10
                border.color: "gray"
                border.width: 2
                anchors.centerIn: parent
                color: "blue"
                visible: visibleRadio
            }


        }
        checked: check
        anchors{
            left: rectRoot.left
            leftMargin: 50
        }

        onClicked: {
            rectRoot.click()

        }

    }
    Text {
        id: text
        text: textLanguage
        font.pixelSize: 35
        font.bold: true
        font.family: "Ubuntu"
        color:colorTextTitle

        anchors{
            left: radio.right
            leftMargin: 50
        }
    }
}

