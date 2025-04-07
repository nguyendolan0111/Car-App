import QtQuick 2.15
import QtQuick.Controls 2.15
import "Common"
Rectangle{
    id:rectRoot
    width: 700
    height: 600

    MyRadioButton{
        id:radioEng
        check: setting.getCurrentLanguage() === "English" ? true : false
        visibleRadio: radioEng.check === true ? true:false
        textLanguage: qsTr("English")
        anchors.top:rectRoot.top
        anchors.topMargin: 100
        colorTextTitle: radioEng.check ? "blue" : "gray"
        onClick: {
            if(radioEng.check === true){}
            else{
                setting.setLanguage("English")
                radioEng.check = true
                radioVietNam.check = false
                console.log(setting.getCurrentLanguage())

            }
        }
    }

    MyRadioButton{
        id:radioVietNam
        check: setting.getCurrentLanguage() === "Vietnamese" ? true : false
        visibleRadio: radioVietNam.check === true ? true:false
        textLanguage: qsTr("Vietnamese")
        anchors.top:radioEng.top
        anchors.topMargin: 100
        colorTextTitle: radioVietNam.check ? "blue" : "gray"
        onClick: {
            if(radioVietNam.check == true){}
            else{
                setting.setLanguage("Vietnamese")
                radioVietNam.check = true
                radioEng.check = false
                console.log(setting.getCurrentLanguage())
            }
        }
    }

    Text{
        id:text1
        font.family: "Ubuntu"
        text: qsTr("Radio shows the current language being applied")
        font.pixelSize: 30
        font.bold: true
        color:"gray"
        anchors{
            bottom: rectRoot.bottom
            bottomMargin: 200
        }
    }


}
