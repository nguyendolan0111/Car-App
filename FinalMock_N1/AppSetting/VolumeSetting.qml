import QtQuick 2.15
import "Common"
import QtQuick.Controls 2.0

Rectangle{
    id:rootRectVolume
    width: 700
    height: 600
    ButtonVolume{
        id:sub
        textVolume: "-"
        anchors{
            left: rootRectVolume.left
            leftMargin: 15
            top:rootRectVolume.top
            topMargin: 150
        }
        onClick: {
            setting.decreaseVolume()
            control.value = control.value - 1
            console.log(setting.getCurrentVolume())
        }
    }

    ButtonVolume{
        id:add
        textVolume: "+"
        anchors{
            right: rootRectVolume.right
            rightMargin: 15
            top:rootRectVolume.top
            topMargin: 150
        }

        onClick: {
            setting.increaseVolume()
            control.value = control.value + 1
            console.log(volumeLevel.text)
            console.log(setting.getCurrentVolume())
        }

    }

    Slider{
        id:control
        from: 0 // giá trị đầu tiên
        to: 10 // giá trị cuối cùng
        value: setting.getCurrentVolume()
        width: 540
        stepSize: 1

        onValueChanged: {
            setting.setCurrentVolume(control.value)
            volumeLevel.text = Math.round(control.value); // Cập nhật text hiển thị
            console.log(setting.getCurrentVolume())
        }

        handle: Rectangle {

            width: 40
            height: 40
            radius: 20 // Dấu tròn
            color: "lightblue"
            border.color: "blue"
            anchors.verticalCenter: parent.verticalCenter
            x: (control.value - control.from) / (control.to - control.from) * (control.width - width)
            Text{
                id:volumeLevel
                text:setting.getCurrentVolume()
                anchors.centerIn: parent
                font.pixelSize: 15
                font.family: "Ubuntu"
                font.bold:true
                color:"blue"

            }
        }

        background: Rectangle {
            // implicitWidth: 540
            implicitHeight: 20
            border.width: 1
            border.color:"blue"
            Rectangle {
                width: control.visualPosition * parent.width
                height: parent.height
                color: "lightblue"
                radius: 1
                border.width: 1
                border.color: "blue"
            }
        }
        anchors{
            right: rootRectVolume.right
            rightMargin: 80
            verticalCenter: add.verticalCenter
        }
    }

    Text{
        text: qsTr("Use the slider or two buttons to adjust the system volume")
        font.pixelSize: 30
        wrapMode: Text.WordWrap
        width: 600
        font.family: "Ubuntu"
        color:"gray"
        font.bold:true
        anchors{
            top:control.bottom
            topMargin: 200
            horizontalCenter: control.horizontalCenter
        }

    }

}
