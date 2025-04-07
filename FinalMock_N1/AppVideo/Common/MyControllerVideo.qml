import QtQuick 2.15

Rectangle{
    id: controlVideo
    width: parent.width
    height: 100
    color: "transparent"

    Row{
        spacing: 45
        anchors.centerIn: parent

        MyButton{
            id: btnRandom
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"

            sourceImage: "qrc:/Icon/unrandom.png"

            onMyClicked: {
                console.log("Random Play: ", videoController.randomPlay)
                if(videoController.randomPlay === true){
                    videoController.setRandomPlay(false);
                    btnRandom.sourceImage = "qrc:/Icon/unrandom.png"
                }
                else{
                    videoController.setRandomPlay(true);
                    btnRandom.sourceImage = "qrc:/Icon/random.png"
                }
                console.log("Random Play: ", videoController.randomPlay)
            }
        }

        MyButton{
            id: btnPrevious
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"

            sourceImage: "qrc:/Icon/previous.png"

            onMyClicked: {
                console.log("Previous Song")
                videoController.setVideoSink(videoOutput.videoSink)
                videoController.periousVideo();
            }
        }

        MyButton{
            id: btnPlayPause
            width: 80
            height: 80
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"

            sourceImage: "qrc:/Icon/play.png"
            sizeImage: 70

            onMyClicked: {
                if(videoController.isPause === true){
                    console.log("Play Song")
                    btnPlayPause.sourceImage = "qrc:/Icon/pause.png"
                    videoController.setVideoSink(videoOutput.videoSink)
                    videoController.playVideo();
                }
                else{
                    console.log("Pause Song")

                    btnPlayPause.sourceImage = "qrc:/Icon/play.png"
                    videoController.pauseVideo()
                }
            }
        }

        MyButton{
            id: btnNext
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"

            sourceImage: "qrc:/Icon/next.png"

            onMyClicked: {
                console.log("Next Song")
                videoController.setVideoSink(videoOutput.videoSink)
                videoController.nextVideo();
            }
        }

        MyButton{
            id: btnRepeat
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"

            sourceImage: "qrc:/Icon/unrepeat.png"

            onMyClicked: {
                console.log("Repeat Play: ", videoController.loopPlay)
                if(videoController.loopPlay === true){
                    videoController.setLoopPlay(false);
                    btnRepeat.sourceImage = "qrc:/Icon/unrepeat.png"
                }
                else{
                    videoController.setLoopPlay(true);
                    btnRepeat.sourceImage = "qrc:/Icon/repeat.png"
                }
                console.log("Repeat Play: ", videoController.loopPlay)
            }
        }
    }

    Connections {
        target: videoController

        function onSetInforVideo() {
            console.log("Information for video set");
            if (videoController.isPause === true)
                btnPlayPause.sourceImage = "qrc:/Icon/play.png";
            else
                btnPlayPause.sourceImage = "qrc:/Icon/pause.png";

            btnRepeat.sourceImage = videoController.loopPlay ? "qrc:/Icon/repeat.png" : "qrc:/Icon/unrepeat.png";
            btnRandom.sourceImage = videoController.randomPlay ? "qrc:/Icon/random.png" : "qrc:/Icon/unrandom.png";
        }

        function onIsPauseChanged(){
            if (videoController.isPause === true)
                btnPlayPause.sourceImage = "qrc:/Icon/play.png";
            else
                btnPlayPause.sourceImage = "qrc:/Icon/pause.png";
        }
    }
}
