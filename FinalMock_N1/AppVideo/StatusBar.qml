import QtQuick 2.15

Rectangle{
    width: parent.width
    height: parent.height
    color: "red"

    signal myClickedList()
    signal myClickedHome()
    signal myClickedZoom()

    property bool showZoom: true

    Rectangle{
        id: home
        width: 50
        height: 50
        color: "white"

        anchors{
            left: parent.left
            leftMargin: 20
            verticalCenter: parent.verticalCenter
        }

        MouseArea{
            anchors.fill: parent

            onClicked: {
                myClickedHome()
            }
        }
    }


    Rectangle{
        id: list
        width: 50
        height: 50
        color: "white"

        anchors{
            left: home.right
            leftMargin: 20
            verticalCenter: parent.verticalCenter
        }

        MouseArea{
            anchors.fill: parent

            onClicked: {
                myClickedList()
            }
        }
    }


    Rectangle{
        id: zoom
        width: 50
        height: 50
        color: "white"
        visible: showZoom

        anchors{
            left: list.right
            leftMargin: 20
            verticalCenter: parent.verticalCenter
        }

        MouseArea{
            anchors.fill: parent

            onClicked: {
                myClickedZoom()
            }
        }
    }
}
