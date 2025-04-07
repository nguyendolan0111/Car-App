import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle{
    id:rectRoot
    property string textCheckBox
    property bool check
    property string colorTextCheckBox

    signal click()
    CheckBox{
        id:checkbox
        indicator: Rectangle {
                width: 30 // Tăng kích thước của dấu tròn
                height: 30
                border.color: "darkblue"
                border.width: 2

                Text {
                    font.family: "Ubuntu"
                    visible: checkbox.checked ? true:false
                    text: "✓" // Dấu tích
                    font.pixelSize: 50 // Kích thước của dấu tích
                    color: "blue" // Màu của dấu tích
                    anchors.centerIn: parent // Căn giữa trong hộp checkbox
                }
            }
        checked: check
        width: 30
        height: 30
        anchors{
            top:rectRoot.top
            topMargin: 20
        }
        onClicked: {
            rectRoot.click()
        }
    }

    Text{
        anchors{
            left: checkbox.right
            leftMargin: 15
            verticalCenter: checkbox.verticalCenter
        }
        text:textCheckBox
        font.family: "Ubuntu"
        font.pixelSize: 35
        font.bold: true
        color: colorTextCheckBox
    }
}
