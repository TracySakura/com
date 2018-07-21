import QtQuick              2.8
import QtQuick.Controls     2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts      1.3
//import QtGraphicalEffects   1.0

Rectangle {
    id: input
    width: nameTxt.width
    height: nameTxt.height
    color: "lightblue"
    radius: 4
    x:0
    y:0
    visible: true
    border.color: Material.accent; border.width: 2
    property string name: "value"
    Text {
        id: nameTxt
        padding: 10
        text: name
    }
}
