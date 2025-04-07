import QtQuick

Rectangle {
    id: rectRoot
    width: 900; height: 600
    // color: "grey"
    property alias pathModel: pathView.model
    property alias pathCurrentIndex: pathView.currentIndex
    signal changedMusic()
    PathView {
        id: pathView
        anchors.fill: parent
        model: MusicModel
        delegate: myDelegate
        dragMargin: 300
        pathItemCount: 3
        currentIndex: PlayerControl.currentIndex
        snapMode: PathView.SnapToItem
        maximumFlickVelocity: width*2

        preferredHighlightBegin:0.5
        preferredHighlightEnd:0.5

        clip: true

        path: Path {
            id:flowViewPath

            readonly property real yCoord: pathView.height/2

            startX: 0
            startY: flowViewPath.yCoord
            //p1
            PathAttribute{name:"elementZ"; value: 0}
            PathAttribute{name:"elementScale"; value: 0.3}
            PathAttribute { name: "opacity"; value: 0.5}
            //p2
            PathLine {
                x: pathView.width*0.25
                y: flowViewPath.yCoord
            }
            PathPercent {
                value: 0.25
            }

            PathAttribute{name:"elementZ";value:50}
            PathAttribute{name:"elementScale";value:0.6}
            PathAttribute { name: "opacity"; value: 0.7 }
            //p3
            PathQuad {
                x: pathView.width*0.5
                y: flowViewPath.yCoord
                controlX: pathView.width*0.375
                controlY: flowViewPath.yCoord + 10
            }
            PathPercent {
                value: 0.5
            }
            PathAttribute{name:"elementZ";value:100}
            PathAttribute{name:"elementScale";value:1.0}
            PathAttribute { name: "opacity"; value: 1.0 }
            //p4
            PathQuad {
                x: pathView.width*0.75
                y: flowViewPath.yCoord
                controlX: pathView.width*0.625
                controlY: flowViewPath.yCoord + 10
            }
            PathPercent {
                value: 0.75
            }
            PathAttribute{name:"elementZ";value:50}
            PathAttribute{name:"elementScale";value:0.6}
            PathAttribute { name: "opacity"; value: 0.7}
            //p5
            PathLine {
                x: pathView.width
                y: flowViewPath.yCoord
            }
            PathAttribute{name:"elementZ";value:0}
            PathAttribute{name:"elementScale";value:0.3}
            PathAttribute { name: "opacity"; value: 0.5 }
        }

        onFlickEnded: {
            console.log("Current index:", currentIndex)
            changedMusic()
            PlayerControl.setPlaySong(pathView.currentIndex)
        }
    }


    Component {
        id: myDelegate
        Rectangle {
            width: rectRoot.width/2
            height: rectRoot.height-30

            color: namesong.visible ? "#48CFCB": "transparent"

            scale: PathView.elementScale
            z: PathView.elementZ
            opacity: PathView.opacity

            Text {
                id: namesong
                visible: !image.visible
                text: titleName
                color: "white"
                font.bold: true
                font.pixelSize: 30
                elide: Text.ElideRight
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
            Image {
                id: image
                visible: coverArt !== "Unknown"
                width: parent.width
                height: parent.height
                source: "file://" + coverArt
                fillMode: Image.PreserveAspectCrop
            }
        }
    }

}
