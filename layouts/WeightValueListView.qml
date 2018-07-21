import QtQuick 2.8
import QtQuick.Controls          2.1
import MyModule             1.0

ListView {
    Component{
        id:weightValueDel
        Row{
            Text {
                text: values
                font.pixelSize: 14
                font.wordSpacing: 2
            }
        }
    }
    property int margin: 6
    property int minWid: 250
    property int maxHei: 200
    id:weightList
    implicitWidth: (contentItem.childrenRect.width>minWid-2*margin)?contentItem.childrenRect.width:minWid-2*margin
    implicitHeight: (contentItem.childrenRect.height<maxHei)?contentItem.childrenRect.heigh:maxHei
    boundsBehavior: Flickable.StopAtBounds
    clip: true
    model: weightValueModel
    spacing: 4
    flickableDirection: Flickable.VerticalFlick
    delegate:weightValueDel
}
