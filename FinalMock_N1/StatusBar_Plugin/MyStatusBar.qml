import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: rootRect
    color: "black"

    property alias modelList: modelButton.model
    property string textDirect: ""

    width: parent.width
    height: 80

    Row{
        id: listButton
        width: 80*modelList.count + textDirection.width
        height: parent.height
        anchors {
            left: parent.left
            leftMargin: 10
        }

        spacing: 15
        Repeater{
            id: modelButton
            width: 80
            model: modelList
            delegate: MyButton{
                id: btn
                sourceImage: image
                visible: visibleBtn
                anchors.verticalCenter: parent.verticalCenter

                myFunc: {
                    func
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        btn.myFunc()
                    }
                }
            }
        }

        Rectangle{
            id:  textDirection
            width: 150
            height: parent.height
            color: "transparent"
            Text {

                anchors.centerIn: parent
                font {
                    bold: true
                    pointSize: 15
                }
                color: "white"
                text: textDirect
            }
        }
    }

    Column{
        anchors.centerIn: parent

        Text {
            id: time
            font {
                pointSize: 25
                bold: true
            }
            color: "white"
            text: MyStatusTime.time === "" ? "XX:XX:XX" : MyStatusTime.time
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: date
            font{
                pointSize: 15
                bold: true
            }
            color: "white"
            text: MyStatusTime.date === "" ? "XX:XX:XXXX" : MyStatusTime.date
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
