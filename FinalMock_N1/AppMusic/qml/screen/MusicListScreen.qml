import QtQuick 2.15
import "qrc:/qml/component"

Rectangle {
    id: rootRect
    width: parent.width
    height: parent.height
    color: "transparent"

    ListView {
        id: listViewMusic
        width: rootRect.width
        height: rootRect.height
        model: MusicModel
        clip: true

        delegate:         Rectangle {
            property bool isTmp: PlayerControl.currentIndex === index
            id: recInfor
            width: rootRect.width
            height: 100
            color: "transparent"
            border.color: "black"

            Row{
                spacing: 20

                Rectangle{
                    width: 50
                    height: 100
                    color: "transparent"
                    Text {
                        text: index + 1
                        font.bold: true
                        font.pixelSize: 25
                        color: PlayerControl.currentIndex === index ? "#06D001" : "black"
                        anchors.centerIn: parent
                    }
                }

                AnimatedImage{
                    id: gifMusic
                    width: 100
                    height: 100
                    visible: PlayerControl.currentIndex === index
                    source: "qrc:/image/run.gif"
                }

                ScrollingText{
                    id: txtFileName
                    width: gifMusic.visible ? 450 : 510
                    height: 100
                    myText: fileName
                    currentIndexSong: PlayerControl.currentIndex
                    indexListView: index
                    pixelSizeText: 25
                    isRunning:{
                        if(PlayerControl.currentIndex === index){
                            if(txtFileName.isConditionRun === true){
                                txtFileName.isRunning = true
                            }
                            else if(txtSongName.isConditionRun === true){
                                txtSongName.isRunning = true
                            }
                            else if(txtArtistName.isConditionRun === true){
                                txtArtistName.isRunning = true
                            }
                            else{
                                txtFileName.isRunning =  false
                            }
                        }
                        else{
                            txtFileName.isRunning = false
                        }
                    }

                    onMyFinished: {
                        txtFileName.isRunning = false

                        if(txtSongName.isConditionRun === true){
                            txtSongName.isRunning = true
                        }
                        else if(txtArtistName.isConditionRun === true){
                            txtArtistName.isRunning = true
                        }
                        else{
                            txtFileName.isRunning = true
                        }
                    }
                }

                ScrollingText{
                    id: txtSongName
                    width: gifMusic.visible ? 300 : 350
                    height: 100
                    myText: titleName
                    currentIndexSong: PlayerControl.currentIndex
                    indexListView: index
                    pixelSizeText: 25
                    isRunning: false

                    onMyFinished: {
                        txtSongName.isRunning = false

                        if(txtArtistName.isConditionRun === true){
                            txtArtistName.isRunning = true
                        }
                        else{
                            if(txtFileName.isConditionRun === true){
                                txtFileName.isRunning = true
                            }
                            else{
                                txtSongName.isRunning = true
                            }
                        }
                    }
                }

                ScrollingText{
                    id: txtArtistName
                    width: gifMusic.visible ? 200 : 250
                    height: 100
                    myText: artistName
                    currentIndexSong: PlayerControl.currentIndex
                    indexListView: index
                    pixelSizeText: 25
                    isRunning: false

                    onMyFinished: {
                        txtArtistName.isRunning = false

                        if(txtFileName.isConditionRun === true){
                            txtFileName.isRunning = true
                        }
                        else{
                            if(txtSongName.isConditionRun === true){
                                txtSongName.isRunning = true
                            }
                            else{
                                txtArtistName.isRunning = true
                            }
                        }
                    }
                }
            }

            onIsTmpChanged: {
                if(isTmp == false){
                    txtArtistName.onScrollingTextPos()
                    txtArtistName.isRunning = false
                    txtSongName.onScrollingTextPos()
                    txtSongName.isRunning = false
                    txtFileName.onScrollingTextPos()
                    txtFileName.isRunning = false
                }
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewMusic.currentIndex = index
                    PlayerControl.setPlaySong(listViewMusic.currentIndex)

                    {
                        if(PlayerControl.currentIndex === index){
                            if(txtFileName.isConditionRun === true){
                                txtFileName.isRunning = true
                            }
                            else if(txtSongName.isConditionRun === true){
                                txtSongName.isRunning = true
                            }
                            else if(txtArtistName.isConditionRun === true){
                                txtArtistName.isRunning = true
                            }
                            else{
                                txtFileName.isRunning =  false
                            }
                        }
                        else{
                            txtFileName.isRunning = false
                        }
                    }
                }

                onEntered: {
                    recInfor.color = "gray"
                }

                onExited: {
                    recInfor.color = "transparent"
                }
            }
        }
    }

    function resetListView(){
        listViewMusic.forceLayout()
    }
}
