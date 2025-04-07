import QtQuick 2.15
import "Common"

Rectangle{
    width: parent.width
    height: parent.height
    color: "#F5F5F7"

    Rectangle{
        width: parent.width - 200
        height: parent.height - 200
        color: "transparent"
        anchors.centerIn: parent

        ListView{
            id: listView
            width: parent.width
            height: parent.height
            spacing: 20
            interactive: false
            orientation: ListView.Horizontal

            model: MyController.myModelApp

            anchors.fill: parent

            delegate: MyApp{
                width: listView.width / 2 - 20
                height: listView.height

                titleApp: MyTranslation.getStringChangedLang(theNameApp) + MyTranslation.entryString
                imageAppNormal: theImagePathApp
                listMyText: theCurrentInfor

                onMyClicked: {
                    MyController.callApp(theIDApp)
                }
            }
        }
    }
}
