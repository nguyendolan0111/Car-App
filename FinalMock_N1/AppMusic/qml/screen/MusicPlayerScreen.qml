import QtQuick 2.15
import "qrc:/qml/component"
Rectangle{
    width: parent.width
    height: parent.height
    color: "transparent"

    Connections {
        target: PlayerControl

        function onSetInforScreen(){
            btnRandom.image_source = PlayerControl.random ? "qrc:/image/random.png" : "qrc:/image/unrandom.png"
            btnLoop.image_source = PlayerControl.loop ? "qrc:/image/repeat.png" : "qrc:/image/unrepeat.png"
        }
    }

    Rectangle {
        id: rectInfoMusic
        width: parent.width
        height: parent.height*2/3
        anchors.top: parent.top
        anchors.left: parent.left
        color: "transparent"
        Rectangle
        {
            id:rectInforText
            width: parent.width/2
            height: parent.height
            color: "transparent"

            ScrollingTextList {
                id: text_songTitle
                width: parent.width - 100
                height: 50
                anchors.left: parent.left
                anchors.leftMargin: 100
                anchors.top: parent.top
                anchors.topMargin: parent.height/4
                color: "transparent"
                tỉtleText: qsTr("Song Title: ") + MyTranslation.entryString
                textContent: PlayerControl.currentSong.currentSongTitle
                textSize: 30
                isRunning:{
                    if(text_songTitle.isConditionRun === true){
                        text_songTitle.isRunning = true
                    }
                    else if(text_album.isConditionRun === true){
                        text_album.isRunning = true
                    }
                    else if(text_artist.isConditionRun === true){
                        text_artist.isRunning = true
                    }
                    else{
                        text_songTitle.isRunning = false
                    }
                }

                onMyFinish: {
                    text_songTitle.isRunning = false
                    if(text_album.isConditionRun === true){
                        text_album.isRunning = true
                    }
                    else if(text_artist.isConditionRun === true){
                        text_artist.isRunning = true
                    }
                    else{
                        text_songTitle.isRunning = true
                    }
                }
            }

            ScrollingTextList {
                id: text_album
                width: parent.width - 100
                height: 30
                anchors.left: parent.left
                anchors.leftMargin: 100
                anchors.top: text_songTitle.bottom
                anchors.topMargin: 10
                color: "transparent"
                tỉtleText: qsTr("Album: ") + MyTranslation.entryString
                textContent: PlayerControl.currentSong.currentSongAlbum
                textSize: 20
                isRunning: false

                onMyFinish: {
                    text_album.isRunning = false
                    if(text_artist.isConditionRun === true){
                        text_artist.isRunning = true
                    }
                    else if(text_songTitle.isConditionRun === true){
                        text_songTitle.isRunning = true
                    }
                    else{
                        text_album.isRunning = true
                    }
                }
            }

            ScrollingTextList {
                id: text_artist
                width: parent.width - 100
                height: 30
                anchors.left: text_album.left
                anchors.top: text_album.bottom
                anchors.topMargin: 10
                color: "transparent"
                tỉtleText: qsTr("Artist: ") + MyTranslation.entryString
                textContent: PlayerControl.currentSong.currentArtistName
                textSize: 20
                isRunning: false

                onMyFinish: {
                    text_artist.isRunning = false

                    if(text_songTitle.isConditionRun === true){
                        text_songTitle.isRunning = true
                    }
                    else if(text_album.isConditionRun === true){
                        text_album.isRunning = true
                    }
                    else{
                        text_artist.isRunning = true
                    }
                }
            }
        }

        PathViewMusic {
            id: rectPathView
            width: parent.width/2
            height: parent.height
            anchors.left: rectInforText.right
            color: "transparent"
        }
    }

    Rectangle {
        id: rect_playerHandle
        width: parent.width
        height: parent.height/3
        anchors.top: rectInfoMusic.bottom
        anchors.topMargin: 80
        color: "transparent"

        Row {
            id: row_buttonHandle
            width: parent.width
            height: 50
            anchors.left: parent.left
            anchors.leftMargin: 100
            spacing: 30
            MyButtonImage {
                id: btnRandom
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: PlayerControl.random ? "qrc:/image/random.png" : "qrc:/image/unrandom.png"
                onMyClicked: {
                    PlayerControl.random = !PlayerControl.random
                    console.log("radom "+ PlayerControl.random)
                }
            }

            MyButtonImage {
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: "qrc:/image/backward.png"
                onMyClicked: {
                    PlayerControl.requestPrevious()
                }
            }

            MyButtonImage {
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: "qrc:/image/fast-backward.png"
                onMyClicked: {
                    PlayerControl.requestFastBackward()
                    console.log("fast Backward")
                }
            }

            MyButtonImage {
                id: btnPlayPause
                width: 80
                height: 80
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: PlayerControl.currentSong.status === 1? "qrc:/image/pause.png": "qrc:/image/play.png"

                onMyClicked: {
                    console.log(PlayerControl.pause)
                    if (PlayerControl.pause === false) {
                        PlayerControl.requestPause()
                    } else {
                        PlayerControl.requestPlay()
                    }
                }
            }

            MyButtonImage {
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: "qrc:/image/fast-forward.png"
                onMyClicked: {
                    PlayerControl.requestFastForward()
                    console.log("fast Forward")
                }
            }

            MyButtonImage {
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: "qrc:/image/forward.png"
                onMyClicked: {
                    PlayerControl.requestNext()
                }
            }

            MyButtonImage {
                id: btnLoop
                width: 60
                height: 60
                color: "transparent"
                anchors.verticalCenter: parent.verticalCenter
                image_source: PlayerControl.loop ? "qrc:/image/repeat.png" : "qrc:/image/unrepeat.png"
                onMyClicked: {
                    PlayerControl.loop = !PlayerControl.loop
                    console.log("loop " + PlayerControl.loop)
                }
            }
        }

        Text {
            id: txt_position
            text: convertString(parseInt(PlayerControl.currentSong.currentTime/1000/60)) + ":" + convertString(parseInt((PlayerControl.currentSong.currentTime/1000)%60))
            font.pixelSize: 20
            font.bold: true
            anchors.right: music_slider.left
            anchors.rightMargin: 15
            anchors.top: row_buttonHandle.bottom
            anchors.topMargin: 28
        }

        MySlider {
            id:  music_slider
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width-200
            anchors.top: row_buttonHandle.bottom
            height: 10
            anchors.topMargin: 35
            from: 0
            to: parseInt(PlayerControl.currentSong.totalTime/1000)
            value: parseInt((PlayerControl.currentSong.currentTime /1000))

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onPositionChanged: {
                    var value = mouse.x /music_slider.width*PlayerControl.currentSong.totalTime
                    textPos.text = convertString(parseInt((value/1000/60))) + ":" + convertString(parseInt((value/1000)%60))
                    textPos.anchors.leftMargin = mouse.x
                }
                onEntered: {
                    textPos.visible = true
                }
                onExited: {
                    textPos.visible = false
                }
                onPressed: {
                    var value = mouse.x /music_slider.width*PlayerControl.currentSong.totalTime
                    PlayerControl.setPosition(parseInt(value))
                    console.log(value)
                }
            }

            Text {
                id: textPos
                visible: true
                font.pixelSize: 15
                font.bold: true
                color: "white"
                anchors.bottom: music_slider.top
                anchors.bottomMargin: 10
                anchors.left: music_slider.left
            }
        }

        Text {
            id: txt_duration
            text: convertString(parseInt((PlayerControl.currentSong.totalTime/1000/60))) + ":" + convertString(parseInt((PlayerControl.currentSong.totalTime/1000)%60))
            font.pixelSize: 20
            font.bold: true
            anchors.left: music_slider.right
            anchors.leftMargin: 15
            anchors.top: row_buttonHandle.bottom
            anchors.topMargin: 28
        }
    }

    function convertString(i) {
        if (i<10) {
            return "0" + i.toString()
        } else {
            return i.toString()
        }
    }
}
