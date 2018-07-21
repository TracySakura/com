import QtQuick 2.8
import QtQuick.Controls          2.1
import MyModule             1.0
ListView {
    property int margin: 6
    property int minHei: 100
    GraphCreator{
        id: creator
    }
    Component{
        id:weightDel
        Column{
            width: 300
            Text {
                id:nameStr
                text: name
            }
            Text {
                anchors.right: parent.right
                text: type
            }
            Button{
                anchors.right: parent.right
                width: 300
                height: 20
                onClicked: {
                    creator.setWeightValue(nameStr.text)
                }
            }
        }
    }
    implicitWidth: contentItem.childrenRect.width
    implicitHeight: (contentItem.childrenRect.height<minHei)?contentItem.childrenRect.height:minHei
    boundsBehavior: Flickable.StopAtBounds
    clip: true
    model: weightModel
    spacing: 4
    flickableDirection: Flickable.VerticalFlick
    delegate:weightDel
    Component.onDestruction: {
        console.log("weight destroy!");
        creator.weightValueRelease();
    }
}
