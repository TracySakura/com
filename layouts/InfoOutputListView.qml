import QtQuick 2.8

ListView {
    property int margin: 6
    property int minHei: 100
    Component{
        id:outputDel
        Column{
            width: 300
            Text {
                text: name
            }
            Text {
                anchors.right: parent.right
                text: type
            }
            Text {
                anchors.right: parent.right
                text: values
            }
        }
    }
    implicitWidth: contentItem.childrenRect.width
    implicitHeight: (contentItem.childrenRect.height<minHei)?contentItem.childrenRect.height:minHei
    boundsBehavior: Flickable.StopAtBounds
    clip: true
    model: outputModel
    spacing: 4
    flickableDirection: Flickable.VerticalFlick
    delegate:outputDel
}
