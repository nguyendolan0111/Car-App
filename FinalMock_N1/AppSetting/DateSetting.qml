import QtQuick 2.15
import "Common"

Rectangle{
    id:rectDate
    width: 700
    height: 600
    property int monthValue

    Component.onCompleted: {
        console.log()
        hour.interactive1 = setting.isCustomFormat()
        minute.interactive1 = setting.isCustomFormat()
        second.interactive1 = setting.isCustomFormat()
        day.interactive1 = setting.isCustomFormat()
        month.interactive1 = setting.isCustomFormat()
        year.interactive1 = setting.isCustomFormat()

        if(setting.isCustomFormat() === true){
            checkBoxCustom.colorTextCheckBox = "blue"
            dateTimeRect.opacity = 1
        }
        else{
            checkBoxCustom.colorTextCheckBox = "gray"
            dateTimeRect.opacity = 0.5
        }
    }

    Connections{
        target: setting

        function onTimeChanged(){
            if(!setting.isCustomFormat()){
                hour.currentIndexValue = setting.getHour()
                minute.currentIndexValue = setting.getMinute()
                second.currentIndexValue = setting.getSecond()
                day.currentIndexValue = setting.getDay() - 1
                month.currentIndexValue = setting.getMonth() - 1
                year.currentIndexValue = setting.getYear()
            }
        }
    }

    CheckBoxDate{
        id:checkBox24
        anchors.top:rectDate.top
        anchors.topMargin: 50
        textCheckBox: qsTr("Display 24h format")
        check: setting.is24hFormat()

        colorTextCheckBox: checkBox24.check ? "blue" : "gray"
        width: rectDate.width
        height: rectDate.height * 0.08
        onClick: {
            if(setting.is24hFormat() === true){
                checkBox24.colorTextCheckBox = "gray"
                setting.toggle24hFormat(false)
                console.log(setting.is24hFormat())
            }
            else{
                setting.toggle24hFormat(true)
                checkBox24.colorTextCheckBox = "blue"
                console.log(setting.is24hFormat())

            }
        }
    }

    CheckBoxDate{
        id:checkBoxCustom
        check: setting.isCustomFormat()
        colorTextCheckBox: checkBoxCustom.check ? "blue" : "gray"
        width: rectDate.width
        height: rectDate.height * 0.08
        anchors{
            top: checkBox24.bottom
            topMargin: 50
        }
        textCheckBox: qsTr("Customize time")
        onClick: {
            interactivePathView();
            if(setting.isCustomFormat() === true){
                setting.toggleCustomFormat(false)

                checkBoxCustom.colorTextCheckBox = "gray"
                dateTimeRect.opacity = 0.5
                console.log(setting.isCustomFormat())
            }
            else{
                setting.toggleCustomFormat(true)
                checkBoxCustom.colorTextCheckBox = "blue"
                dateTimeRect.opacity = 1
                console.log(setting.isCustomFormat())
            }
        }
    }

    Rectangle{
        id:dateTimeRect
        width: parent.width * 0.7
        height:parent.height * 0.5
        border.width:2
        border.color:"gray"
        opacity: 0.5

        anchors{
            top:checkBoxCustom.bottom
            topMargin: 100
            horizontalCenter: parent.horizontalCenter
        }

        Row{
            width: 400
            height: 230
            anchors{
                centerIn: parent
            }
            spacing: 20
            PathViewDate{
                pathModel: 24
                id:hour
                currentIndexValue: setting.getHour()
                onCurrentIndexChange: {
                    updateTimeCustom()
                }
            }
            PathViewDate{
                pathModel: 60
                id:minute
                currentIndexValue: setting.getMinute()
                onCurrentIndexChange: {
                    updateTimeCustom()
                }
            }
            PathViewDate{
                pathModel: 60
                id:second
                currentIndexValue: setting.getSecond()
                onCurrentIndexChange: {
                    updateTimeCustom()
                }
            }
            PathViewDate{
                pathModel:{
                    if((year.currentIndexValue) % 4 === 0 && (month.currentIndexValue+1) === 2){
                        return 29
                    }
                    else if((month.currentIndexValue+1) === 2){
                        return 28
                    }
                    else if((month.currentIndexValue+1) === 1 ||
                            (month.currentIndexValue+1) === 3 ||
                            (month.currentIndexValue+1) === 5 ||
                            (month.currentIndexValue+1) === 7 ||
                            (month.currentIndexValue+1) === 9 ||
                            (month.currentIndexValue+1) === 11 ){
                        return 31
                    }
                    else{
                        return 30
                    }

                }
                id:day
                currentIndexValue: setting.getDay() - 1
                onCurrentIndexChange: {
                    updateTimeCustom()
                }
            }
            PathViewDate{
                id:month
                pathModel: 12
                currentIndexValue: setting.getMonth() - 1
                onCurrentIndexChange: {
                    updateTimeCustom()
                }
            }
            PathViewDate {
                id: year
                pathModel: 2050
                currentIndexValue: setting.getYear()

                onCurrentIndexChange: {
                    updateTimeCustom()
                }

            }

        }

    }

    function updateTimeCustom(){
        if(setting.isCustomFormat()){
            setting.updateTime(hour.currentIndexValue, minute.currentIndexValue,
                               second.currentIndexValue, day.currentIndexValue + 1,
                               month.currentIndexValue + 1, year.currentIndexValue)
        }
    }

    function interactivePathView(){
        if(setting.isCustomFormat() === true){
            hour.interactive1 = false
            minute.interactive1 = false
            second.interactive1 = false
            day.interactive1 = false
            month.interactive1 = false
            year.interactive1 = false
        }
        else{
            setting.updateTime(hour.currentIndexValue, minute.currentIndexValue,
                               second.currentIndexValue, day.currentIndexValue + 1,
                               month.currentIndexValue + 1, year.currentIndexValue)
            hour.interactive1 = true
            minute.interactive1 = true
            second.interactive1 = true
            day.interactive1 = true
            month.interactive1 = true
            year.interactive1 = true
        }
    }
}
