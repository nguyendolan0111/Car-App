import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls 2.15
import MyStatusBarPlugin 1.0
import "Common"

Window {
    width: 1200
    height: 800
    visible: setting.showApp
    title: qsTr("App Setting")

    ListModel{
        id: modelListButtonStatusbar

        ListElement {
            image : "qrc:/image/back.png";
            visibleBtn: true
            func : function() {
                if (listScreenModel.count > 1) {
                    listScreenModel.remove(listScreenModel.count -1)
                }

                if(listScreenModel.get(listScreenModel.count - 1).index === 4){
                     popup.open()
                }
            }
        }

        ListElement {
            image : "qrc:/image/home.png";
            visibleBtn: true
            func : function() {
                setting.onReturnHome()
            }
        }
    }

    ListModel {
        id: listScreenModel
        ListElement{
            sourceLoader: ""
            index: -1
        }
    }

    MyStatusBar {
        id: statusBar
        width: parent.width
        height: 80
        anchors.top: parent.top
        textDirect: qsTr("Setting")
        modelList: modelListButtonStatusbar
    }

    ListView{
        id: listview
        spacing: 4
        width: parent.width/3
        height: 694
        currentIndex: -1
        anchors{
            left: parent.left
            leftMargin: 5
            top:statusBar.bottom
            topMargin: 3
        }

        model:ListModel{
            id: modeListView
            ListElement{title:qsTr("Language");src:"LanguageSetting.qml";color:"transparent"}
            ListElement{title:qsTr("Volume");src:"VolumeSetting.qml";color:"transparent"}
            ListElement{title:qsTr("Date/Time");src:"DateSetting.qml";color:"transparent"}
            ListElement{title:qsTr("System Information");src:"SystemInformation.qml";color:"transparent"}
            ListElement{title:qsTr("Reset");src:"ResetSetting.qml";color:"transparent"}
        }
        delegate: TitleRect{
            id:rectTitle
            width: listview.width
            height: listview.height/5 - 4
            titleText: model.title
            colorTitleRect: listScreenModel.get(listScreenModel.count - 1).index === index ? "lightblue" : "transparent"
            colorTitleText: listScreenModel.get(listScreenModel.count - 1).index === index ? "blue" : "gray"
            onClicked: {

                listScreenModel.append({sourceLoader: modeListView.get(index).src, index: index})
                listview.currentIndex = index
                if (index == 4) {
                    console.log("Opening popup...")
                    popup.open()
                }
            }
        }

    }

    Rectangle{
        id:rect
        visible: /*((listview.currentIndex >=0) &&(listview.currentIndex <= 4))
                 ||*/ listScreenModel.get(listScreenModel.count - 1).index !== -1 ? false : true
        width: parent.width*2/3
        height: parent.height - statusBar.height
        anchors{
            left:listview.right
            leftMargin: 50
            top:statusBar.bottom
            topMargin: 50
        }

        Image {
            id: settingImage
            width: 150
            height: 150
            source: "qrc:/image/settings.png"
        }
        Text{
            text: qsTr("Please select the function you need")
            font.pixelSize: 30
            anchors{
                left: settingImage.right
                leftMargin: 30
                verticalCenter: settingImage.verticalCenter
            }

            font.bold:true
            font.family: "Ubuntu"
            color:"gray"
        }

    }

    Loader{
        id:loader
        source: listScreenModel.get(listScreenModel.count-1).sourceLoader
        anchors{
            top:statusBar.bottom
            topMargin: 10
            left: listview.right
            leftMargin: 50
        }

    }


    Dialog{
        id:popup
        title: qsTr("Reset")
        font.pixelSize: 20
        modal: true
        width: 600
        height: 300
        anchors.centerIn: parent

        Rectangle{
            id:rectPopup
            width: parent.width
            height: parent.height
            border.width: 1

            Rectangle{
                id:i
                width: 60
                height: 60
                radius: i.width/2
                border.color:"blue"
                border.width: 3
                anchors{
                    top:rectPopup.top
                    topMargin: 10
                    left: rectPopup.left
                    leftMargin: rectPopup.width/3 - 30
                }
                Text{
                    text:"i"
                    anchors.centerIn: parent
                    font.pixelSize: 40
                    font.bold: true
                    font.family: "Ubuntu"
                }

            }

            Text{
                text: qsTr("Please confirm that all settings will be reset to default")
                font.pixelSize: 20
                font.family: "Ubuntu"
                color:"gray"
                font.bold: true
                width: parent.width *2/3 - 30
                wrapMode: Text.WordWrap
                anchors{
                    verticalCenter: rectPopup.verticalCenter
                    left: rectPopup.left
                    leftMargin: 20

                }
            }

            ColumnLayout{
                width: parent.width/3
                height: parent.height
                anchors.right: rectPopup.right
                Rectangle{
                    id:rectYes
                    width: parent.width
                    height: parent.height/2 - 20
                    border.width: 2
                    Text{
                        id:textYes
                        text: qsTr("Yes")
                        font.family: "Ubuntu"
                        font.bold: true
                        font.pixelSize: 25
                        anchors.centerIn: parent
                        color:"gray"
                    }
                    MouseArea{
                        hoverEnabled: true
                        anchors.fill:parent
                        onClicked: {
                            popup.close()
                            setting.setLanguage("English")
                            setting.setCurrentVolume(7)
                            setting.toggleCustomFormat(false)
                        }

                        onEntered: {
                            rectYes.color = "lightblue"
                            textYes.color = "blue"

                        }

                        onExited: {
                            rectYes.color = "transparent"
                            textYes.color = "gray"
                        }
                    }
                }

                Rectangle{
                    id:rectNo
                    width: parent.width
                    height: parent.height/2 - 20
                    border.width: 2
                    Text{
                        id:textNo
                        text: qsTr("No")
                        font.bold: true
                        font.pixelSize: 25
                        anchors.centerIn: parent
                        color:"gray"
                    }
                    MouseArea{
                        hoverEnabled: true
                        anchors.fill:parent
                        onClicked: {
                            popup.close()
                        }
                        onEntered: {
                            rectNo.color = "lightblue"
                            textNo.color = "blue"
                        }

                        onExited: {
                            rectNo.color = "transparent"
                            textNo.color = "gray"

                        }
                    }
                }

            }
        }

    }

}
