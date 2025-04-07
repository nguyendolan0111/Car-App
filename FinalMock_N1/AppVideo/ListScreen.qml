import QtQuick 2.15
import "Common"

Rectangle{
    id: root
    width: parent.width
    height: parent.height
    color: "lightgray"

    Rectangle{
        id: recSearch
        width: parent.width /2
        height: 80
        color: "white"
        border.color: "black"
        border.width: 2
        radius: 40

        anchors{
            top: parent.top
            topMargin: 15
            horizontalCenter: parent.horizontalCenter
        }

        TextInput{
            id: txtInput
            width: recSearch.width - 100
            height: 40
            font.pixelSize: 30
            clip: true

            anchors{
                left: parent.left
                leftMargin: 15
                verticalCenter: parent.verticalCenter
            }

            Text {
                id: name
                width: recSearch.width - 100
                height: 40
                font.pixelSize: 30
                text: qsTr("Mời nhập thông tin video tìm kiếm")
                visible: txtInput.text === ""

                anchors{
                    left: parent.left
                    leftMargin: 15
                    verticalCenter: parent.verticalCenter
                }
            }

            onTextChanged: {
                if(txtInput.text === ""){
                    videoController.videoModel.userSearchList = false
                }
                else{
                    videoController.videoModel.userSearchList = true
                    videoController.searchVideo(txtInput.text)
                }
            }
        }

        Image {
            id: image
            width: 40
            height: 40
            source: "qrc:/Icon/search.png"
            fillMode: Image.PreserveAspectFit

            anchors{
                right: parent.right
                rightMargin: 20
                verticalCenter: parent.verticalCenter
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    if(txtInput.text === ""){
                        videoController.videoModel.userSearchList = false
                    }
                    else{
                        videoController.videoModel.userSearchList = true
                        videoController.searchVideo(txtInput.text)
                    }
                }

                onEntered: {
                    image.width = 50
                    image.height = 50
                }
                onExited: {
                    image.width = 40
                    image.height = 40
                }
            }
        }
    }

    ListView{
        id: listview
        width: parent.width - 50
        height: parent.height - recSearch.height - 50
        clip: true

        anchors{
            top: recSearch.bottom
            topMargin: 15
            horizontalCenter: parent.horizontalCenter
        }

        model: videoController.videoModel

        delegate: Rectangle{
            property bool isTmp: videoController.currentVideoIndex === index
            id: recInfor
            width: listview.width
            height: 100
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
                        color: videoController.currentVideoIndex === index ? "#06D001" : "black"
                        anchors.centerIn: parent
                    }
                }

                AnimatedImage{
                    id: gifMusic
                    width: 100
                    height: 100
                    visible: videoController.currentVideoIndex === index
                    source: "qrc:/Icon/run.gif"
                }

                MyScrollingText{
                    id: txtFileName
                    width: gifMusic.visible ? 450 : 510
                    height: 100
                    myText: TheFileName
                    currentIndexSong: videoController.currentVideoIndex
                    indexListView: index
                    pixelSizeText: 25
                    isRunning: {
                        if(videoController.currentVideoIndex === index){
                            if(txtFileName.isConditionRun === true){
                                txtFileName.isRunning = true
                            }
                            else if(txtFilePath.isConditionRun === true){
                                txtFilePath.isRunning = true
                            }
                            else{
                                txtFileName.isRunning = false
                            }
                        }
                        else{
                            txtFileName.isRunning = false
                        }
                    }

                    onMyFinished: {
                        txtFileName.isRunning = false

                        if(txtFilePath.isConditionRun === true){
                            txtFilePath.isRunning = true
                        }
                        else{
                            txtFileName.isRunning = true
                        }
                    }
                }

                MyScrollingText{
                    id: txtFilePath
                    width: gifMusic.visible ? 450 : 510
                    height: 100
                    myText: TheFilePath
                    currentIndexSong: videoController.currentVideoIndex
                    indexListView: index
                    pixelSizeText: 25
                    isRunning: false

                    onMyFinished: {
                        txtFilePath.isRunning = false

                        if(txtFileName.isConditionRun == true){
                            txtFileName.isRunning = true
                        }
                        else{
                            txtFilePath.isRunning = true
                        }
                    }
                }
            }

            onIsTmpChanged: {
                if(isTmp == false){
                    txtFilePath.onScrollingTextPos()
                    txtFilePath.isRunning = false
                    txtFileName.onScrollingTextPos()
                    txtFileName.isRunning = false
                }
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                z: 10
                onClicked: {
                    listview.currentIndex = index
                    videoController.playVideoWithIndex(index)

                    {
                        if(txtFileName.isConditionRun === true){
                            txtFileName.isRunning = true
                        }
                        else if(txtFilePath.isConditionRun === true){
                            txtFilePath.isRunning = true
                        }
                        else{
                            txtFileName.isRunning = false
                        }
                    }
                }

                onEntered: {
                    recInfor.color = "lightgray"

                    if(txtFileName.isConditionRun == true || videoController.currentVideoIndex === index && txtFilePath.isRunning == false){
                        txtFileName.isRunning = true
                        txtFilePath.isRunning = false
                    }
                    else{
                        if(txtFilePath.isConditionRun === true || videoController.currentVideoIndex === index && txtFileName.isRunning == false){
                            txtFilePath.isRunning = true
                            txtFileName.isRunning = false
                        }
                    }
                }

                onExited: {
                    recInfor.color = "white"
                    if(videoController.currentVideoIndex !== index){
                        txtFileName.isRunning = false
                        txtFilePath.isRunning = false
                    }

                    if(isTmp == false){
                        txtFilePath.onScrollingTextPos()
                        txtFilePath.isRunning = false
                        txtFileName.onScrollingTextPos()
                        txtFileName.isRunning = false
                    }
                }
            }
        }
    }
}
