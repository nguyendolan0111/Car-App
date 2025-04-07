import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    width: 50
    height: 230
    visible: true
    signal currentIndexChange()
    property int pathModel
    property alias currentIndexValue: pathView.currentIndex
    property bool interactive1

    PathView {
        id: pathView
        anchors.fill: parent
        model: pathModel
        interactive :interactive1
        delegate: Rectangle {
            id: wrapper
            property real rotX: PathView.itemAngle

            visible: PathView.onPath

            width: 64
            height: 56
            scale: PathView.itemScale
            z: PathView.itemZ
            border.width: pathView.currentIndex === index ? 2: 0
            border.color: pathView.currentIndex === index ? "blue": "transparent"
            radius: pathView.currentIndex === index ? 10: 0

            antialiasing: true

            gradient: Gradient {
                GradientStop { position: 0.0; color: "transparent" }
                GradientStop { position: 1.0; color: "transparent" }
            }

            transform: Rotation {
                axis { x: 1; y: 0; z: 0 }
                angle: wrapper.rotX
                origin { x: 32; y: 32; }
            }
            Text {
                id: text1
                font.pixelSize: pathView.currentIndex === index ? 23: 20
                anchors.centerIn: parent
                text:{
                    if(pathView.model === 12 || pathView.model === 28
                            || pathView.model === 29
                            || pathView.model === 30
                            || pathView.model === 31
                            ){
                        if(pathView.currentIndex === index){
                            return pathView.currentIndex + 1;
                        }else{
                            return index+1;
                        }
                    }

                    if(pathView.currentIndex === index ){
                        return pathView.currentIndex;
                    }else{
                        return index;
                    }
                }



            }
        }

        path: Path {
            startX: root.width / 2
            startY: 0


            PathAttribute { name: "itemZ"; value: 0 }
            PathAttribute { name: "itemAngle"; value: -30.0; }
            PathAttribute { name: "itemScale"; value: 0.7; }
            PathLine { x: root.width / 2; y: root.height * 0.4; }
            PathPercent { value: 0.48; }
            PathLine { x: root.width / 2; y: root.height * 0.5; }
            PathAttribute { name: "itemAngle"; value: 0.0; }
            PathAttribute { name: "itemScale"; value: 1.0; }
            PathAttribute { name: "itemZ"; value: 100 }
            PathLine { x: root.width / 2; y: root.height * 0.7; }
            PathPercent { value: 0.52; }
            PathLine { x: root.width / 2; y: root.height; }
            PathAttribute { name: "itemAngle"; value: 30.0; }
            PathAttribute { name: "itemScale"; value: 0.7; }
            PathAttribute { name: "itemZ"; value: 0 }
        }

        onFlickEnded: {
            root.currentIndexChange()

        }

        pathItemCount: 5

        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
    }

}


