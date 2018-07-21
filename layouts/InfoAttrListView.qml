import QtQuick 2.8
import QtQuick.Layouts           1.3

ListView {
    property int margin: 6
    property int minHei: 100
    Component {
        id:attrDel
        Column{
            width: 300
            Text {
                text: name+" : " +values
            }
            Text {
                anchors.right: parent.right
                text: type
            }
        }
    }
    implicitWidth: contentItem.childrenRect.width
    implicitHeight: (contentItem.childrenRect.height<minHei)?contentItem.childrenRect.height:minHei
    boundsBehavior: Flickable.StopAtBounds
    clip: true
    model: attrModel
    spacing: 4
    flickableDirection: Flickable.VerticalFlick
    delegate:attrDel
}
