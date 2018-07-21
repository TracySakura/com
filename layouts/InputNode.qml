import QtQuick              2.8
import QtQuick.Controls     2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts      1.3
import QtGraphicalEffects   1.0

import QuickQanava 2.0 as Qan
import MyModule             1.0
Qan.NodeItem {
    id: inputNode
    width: background.width
    height: background.height
    property string nameStr
    minimumSize: Qt.size(20,20)
    x: 15;      y: 15
    Rectangle{
        id: background
        border.color: Material.accent; border.width: 2
        radius: 4
        height: nameText.height
        width: nameText.width
        Text {
            id: nameText
            text: nameStr
            padding: 6
        }
    }
}
