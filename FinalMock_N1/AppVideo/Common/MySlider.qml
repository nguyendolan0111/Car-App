import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle{
    id: root
    width: parent.width
    height: 50
    color: "transparent"

    property int myValue: 1
    property double myStepSize: 0.01
    property int myTo: 1
    property int myWidth: 250
    property bool isFull: false

    signal myMove(int currentValue);

    Connections{
        target: videoController

        function onPositionChanged(){
            txtPositionTime.text = formatTime(videoController.position);
        }

        function setInforVideo(){
            txtDuration.text = formatTime(videoController.duration);
            slider.to = videoController.duration
            slider.value = videoController.position
        }
    }

    Text {
        id: txtPositionTime
        text: formatTime(myValue)
        font.bold: true
        font.pixelSize: 20
        color: isFull ? "#06D001" : "black"

        anchors{
            right: slider.left
            rightMargin: 20
            verticalCenter: parent.verticalCenter
        }
    }

    Slider {
        id: slider
        width: myWidth
        height: 10
        from: 0
        to: myTo
        value: myValue
        stepSize: myStepSize
        anchors.centerIn: parent

        background: Rectangle {
            implicitWidth: slider.width
            implicitHeight: 15
            radius: 5
            color: "gray"

            Rectangle {
                width: slider.visualPosition * parent.width
                height: parent.height
                radius: parent.radius
                color: "#06D001"

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true

                    onPositionChanged: {
                        var mouseValue = slider.from + (slider.to - slider.from) * mouseX / width;
                        textPos.text = formatTime(mouseValue);
                        textPos.x = mouseX - textPos.width / 2;
                        textPos.y = -textPos.height - 5;
                    }

                    onEntered: {
                        controlSlider.visible = true
                    }

                    onExited: {
                        controlSlider.visible = false
                    }
                }
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true

                onPositionChanged: {
                    var mouseValue = slider.from + (slider.to - slider.from) * mouseX / width;
                    textPos.text = formatTime(Math.round(mouseValue));
                    textPos.x = mouseX - textPos.width / 2;
                    textPos.y = -textPos.height - 5;
                }

                onEntered: {
                    controlSlider.visible = true
                }

                onExited: {
                    controlSlider.visible = false
                }
            }
        }

        handle: Rectangle {
            id: controlSlider
            width: 30
            height: 30
            radius: 15
            visible: false
            color: "white"
            border.color: "black"
            border.width: 2

            x: slider.width * (slider.value - slider.from) / (slider.to - slider.from) - width / 2
            y: (slider.height - height) / 2
        }


        Text {
            id: textPos
            visible: controlSlider.visible
            text: formatTime(slider.value)
            font.pixelSize: 20
            font.bold: true
            color: isFull ? "#06D001" : "black"

            anchors{
                bottom: slider.top
                bottomMargin: 5
            }
        }

        onMoved: {
            myMove(slider.value);
            txtPositionTime.text = formatTime(slider.value)
        }
    }

    Text {
        id: txtDuration
        text: formatTime(myTo)
        font.bold: true
        font.pixelSize: 20
        color: isFull ? "#06D001" : "black"

        anchors{
            left: slider.right
            leftMargin: 20
            verticalCenter: parent.verticalCenter
        }
    }

    function formatTime(seconds) {
        var minutes = Math.floor(seconds / 60);
        var remainingSeconds = seconds % 60;

        return (minutes < 10 ? '0' : '') + minutes + ':' + (remainingSeconds < 10 ? '0' : '') + remainingSeconds;
    }
}
