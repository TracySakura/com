import QtQuick 2.0
import QtQuick.Controls          2.1

ListView {
    id: list_area
    anchors.fill: parent
    orientation : ListView.Vertical
    Frame {
        anchors.fill: parent
        opacity: 0.8
        padding: 0
        Pane {
            anchors.fill: parent
        }
    }
    ScrollBar.vertical: ScrollBar {
        id: scrollBar
        onActiveChanged: {
            active = true;
        }
        Component.onCompleted: {
            scrollBar.handle.color = "#686A70";
            scrollBar.active = true;
            scrollBar.handle.width = 10;
        }
    }
}
