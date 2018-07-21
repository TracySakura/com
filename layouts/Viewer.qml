import QtQuick                   2.8
import QtQuick.Controls          2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts           1.3
import QtQuick.Shapes 1.0

import QuickQanava          2.0 as Qan
import "qrc:/QuickQanava"   as Qan
import MyModule             1.0        // Our custom topology is defined in MyModule

ApplicationWindow {
    id: window
    visible: true
    width: 1280; height: 720    // MPEG - 2 HD 720p - 1280 x 720 16:9
    title: "Onnx Viewer"
    property string path: "ll"
    property int margin: 6
    property int minWid: 250
    property int minHei: 70
    property int maxHei: 300
    property int textPadding: 3
    GraphCreator{
        id: creator
    }
    Label{
        id: l
        text:path
    }
    Qan.GraphView {
        id: graphView
        anchors.fill: parent
        navigable   : true
        graph : CustomGraph {
            id: topology
            objectName: "graph"
            anchors.fill: parent
            clip: true
            //enableConnectorDropNode: true
            Component.onCompleted: {
                path = main.path;
                creator.createGraph(topology, path, weightValues);
                //defaultEdgeStyle.lineType = Qan.EdgeStyle.Curved;
                //topology.selectionPolicy = Qan.Graph.NoSelection
            }
            onNodeClicked:{
                console.log("clicked");
                infoList.visible = false;
                //delete former info
                for(var i=2;i<mainLayout.children.length;i++){
                    console.log("delete");
                    creator.deleteItem(mainLayout.children[i]);
                }
                creator.showNodeInfo(infoList,node.item.objectName);
            }
            onNodeRightClicked: { }
            onEdgeRightClicked: { }
        } // Qan.Graph: graph
    }

//    ListModel {
//         id: attrModel
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//         ListElement {
//             name: "Apple"
//             cost: 2.45
//         }
//    }
    Component {
        id:attrDel
        Row{
            Text {
                text: name+" /("+type+") : " +values
                padding: textPadding
            }
        }
    }

    Item {
        id: infoList
        objectName: "properties"
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        width: mainLayout.implicitWidth + 2*margin
        height: (mainLayout.implicitHeight + 2*margin >= minHei)?mainLayout.implicitHeight + 2*margin : minHei
        visible: false
        Frame {
            anchors.fill: parent
            opacity: 0.8
            padding: 0
            Pane {
                anchors.fill: parent
            }
        } // Background
        ColumnLayout {
            objectName: "mainLayout"
            id:mainLayout
            anchors.fill: parent
            anchors.margins: margin
            Label {
                objectName: "typeStr"
                Layout.margins: 3
                text: "CONV"
                font.bold: true
                horizontalAlignment: Text.AlignLeft
            }
            Text {
                objectName: "nodeName"
                text: qsTr("text")
                padding: textPadding
            }
        }
    }
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
    Item {
        id : weightValues
        objectName: "weightValues"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        width: (valueLayout.implicitWidth + 2*margin >= minWid)?valueLayout.implicitWidth + 2*margin : minWid
        height: (valueLayout.implicitHeight + 2*margin >= minHei)?valueLayout.implicitHeight + 2*margin : minHei
        visible: false
        Frame {
            anchors.fill: parent
            opacity: 0.8
            padding: 0
            Pane {
                anchors.fill: parent
            }
        } // Background
        ColumnLayout {
            objectName: "valueLayout"
            id:valueLayout
            anchors.fill: parent
            anchors.margins: margin
            ListView {
                id:weightList
                implicitWidth: (contentItem.childrenRect.width>minWid-2*margin)?contentItem.childrenRect.width:minWid-2*margin
                implicitHeight: (contentItem.childrenRect.height<maxHei)?contentItem.childrenRect.height:maxHei
                boundsBehavior: Flickable.StopAtBounds
                clip: true
                model: weightValueModel
                spacing: 4
                flickableDirection: Flickable.VerticalFlick
                delegate:weightValueDel
            }
        }
    }
    Item {
        id : colorMap
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 15
        width: colorsLayout.implicitWidth + 2 * margin
        height: colorsLayout.implicitHeight + 2 * margin
        visible: true
        Frame {
            anchors.fill: parent
            opacity: 0.8
            padding: 0
            Pane {
                anchors.fill: parent
            }
        } // Background
        ColumnLayout {
            objectName: "valueLayout"
            id:colorsLayout
            anchors.fill: parent
            anchors.margins: margin
            Row {
                Layout.fillWidth: true
                Label{
                    text: "Conv"
                }
                Rectangle{
                    width: 40
                    height: 10
                    color: "red"
                }
            }
            Row {
                Layout.fillWidth: true
                Label{
                    text: "Conv"
                }
                Rectangle{
                    width: 40
                    height: 10
                    color: "red"
                }
            }
        }
    }
    Component.onDestruction: {
        console.log("destroy!!!");
        creator.release();
    }
    onClosing: {
        console.log("close");
        //delete info first
        for(var i=2;i<mainLayout.children.length;i++){
            console.log("delete");
            creator.deleteItem(mainLayout.children[i]);
        }
        window.destroy();
    }
}
