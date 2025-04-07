import QtQuick 2.15
import QtQuick.Controls.Fusion
import QtQuick.Controls 2.15
import QtMultimedia
import "Common"

Rectangle{
    id: root
    width: parent.width
    height: parent.height
    color: "lightgray"

    property bool isFullScreen: false
    signal toggleFullScreen();

    Rectangle{
        id: videoScreen
        width: isFullScreen ? parent.width : parent.width - 400
        height: isFullScreen ? parent.height : parent.height - 200
        border.color: "black"
        border.width: 2

        anchors{
            top: root.top
            topMargin: isFullScreen ? 0 : 20
            horizontalCenter: parent.horizontalCenter
        }


        MediaPlayer {
            id: player
            videoOutput: videoOutput
            audioOutput: AudioOutput
        }

        VideoOutput {
            id: videoOutput
            anchors.fill: parent

            TapHandler {
                id: tapHandler
                onTapped: {
                    console.log("single")
                    if(videoController.isPause === true){
                        videoController.setVideoSink(videoOutput.videoSink)
                        videoController.playVideo()
                    }
                    else {
                        videoController.pauseVideo()
                    }
                }

                onDoubleTapped: {
                    root.isFullScreen = !root.isFullScreen
                    toggleFullScreen()
                }
            }
        }
    }


    MySlider{
        id: mySlider
        myWidth: parent.width - 150
        myTo: videoController.duration
        myValue: videoController.position
        myStepSize: 1
        isFull: isFullScreen

        anchors{
            bottom: isFullScreen ? parent.bottom : controlVideo.top
            horizontalCenter: parent.horizontalCenter
        }

        onMyMove: {
            console.log(currentValue)
            videoController.changePosition(currentValue)
        }
    }

    MyControllerVideo{
        id: controlVideo
        width: parent.width
        height: 100
        color: "transparent"
        visible: !isFullScreen

        anchors{
            bottom: parent.bottom
            bottomMargin: 10
        }
    }

    Connections {
        target: videoController

        function onSourceMediaChanged() {
            console.log("Media source changed");
            videoController.setVideoSink(videoOutput.videoSink);
        }
    }
}
