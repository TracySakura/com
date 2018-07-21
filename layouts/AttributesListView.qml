import QtQuick 2.8
import QtQuick.Layouts      1.3
ListView{
    Component {
        id:mydel
        Row{
            Text {
                text: name
                padding: 3
            }
            Text {
                text: qsTr("=")
                padding:3
            }
            Text {
                text: values
                padding: 3
            }
        }
    }
    implicitWidth: contentItem.childrenRect.width
    implicitHeight: contentItem.childrenRect.height
    id:attr
    Layout.fillHeight: true
    Layout.fillWidth: true
    delegate: mydel
    objectName: "attr"
    model:myModel
    interactive: false
}
