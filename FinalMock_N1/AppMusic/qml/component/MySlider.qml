import QtQuick
import QtQuick.Controls.Fusion

Slider {
    id: slider
    property alias backgroundColor: backgroundRec.color
    property alias valueColor: rect_value.color
    property alias backgroundOpacity: backgroundRec.opacity
    property alias backgroundWidth: backgroundRec.implicitWidth
    property alias backgroundHeight: backgroundRec.implicitHeight

    background: Rectangle {
        id: backgroundRec
        implicitWidth: 120
        implicitHeight: 8
        radius: 10
        color: "blue"
        opacity: 0.4
        border.color: "blue"
        border.width: 1
    }

    handle: Rectangle {
        implicitWidth: 8
        implicitHeight: 8
        color: "transparent"
    }

    Rectangle {
        id: rect_value
        width: slider.visualPosition * slider.availableWidth
        height: 8
        color: "blue"
        radius: 10
    }

    onValueChanged: {
        console.log(value)
    }
}
