import QtQuick 2.15

Rectangle{
    id: root
    width: parent.width
    height: parent.height
    border.color: "black"
    border.width: 2
    color: "white"

    signal myClicked()
    property string titleApp: ""
    property string imageAppNormal: ""
    property var listMyText


    Rectangle{
        id: title
        width: parent.width
        height: 100
        color: "transparent"
        anchors.top: parent.top

        Text {
            text: titleApp
            font.bold: true
            font.pixelSize: 50
            color:  "black"

            anchors{
                bottom: parent.bottom
                horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Rectangle{
        id: image
        width:  parent.width / 1.5
        height: 300
        color: namesong.visible ? "#48CFCB": "transparent"

        anchors{
            top: title.bottom
            horizontalCenter: parent.horizontalCenter
        }

        Image {
            id: icon
            width: 230
            height: 230
            visible: imageAppNormal !== "Unknown"
            source: "file://" + imageAppNormal
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }

        Text {
            id: namesong
            visible: !icon.visible
            text:  listMyText[0]
            color: "white"
            font.bold: true
            font.pixelSize: 30
            wrapMode: Text.Wrap
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
        }
    }

    Rectangle{
        width: parent.width / 1.2
        height: root.height - title.height - image.height
        color: "transparent"

        anchors{
            top: image.bottom
            horizontalCenter: parent.horizontalCenter
        }

        MyScrollingText {
            id: infor1
            width: parent.width
            height: parent.height / 2
            anchors.top: parent.top

            myText: listMyText[0]

            isRunning: {
                if(infor1.isConditionRun === true){
                    infor1.isRunning = true
                }
                else if(infor2.isConditionRun === true){
                    infor2.isRunning = true
                }
                else{
                    infor1.isRunning = false
                }
            }

            onMyFinished: {
                infor1.isRunning = false

                if(infor2.isConditionRun == true){
                    infor2.isRunning = true
                }
                else{
                    infor1.isRunning = true
                }
            }
        }

        MyScrollingText {
            id: infor2
            width: parent.width
            height: parent.height / 2
            anchors.bottom: parent.bottom

            myText: listMyText[1]
            isRunning: false

            onMyFinished: {
                infor2.isRunning = false

                if(infor1.isConditionRun == true){
                    infor1.isRunning = true
                }
                else{
                    infor2.isRunning = true
                }
            }
        }
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            myClicked()
        }

        onEntered: {
            icon.width = icon.height = 250
        }

        onExited: {
            icon.width = icon.height = 230
        }
    }
}
