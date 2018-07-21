import QtQuick                   2.8
import QtQuick.Controls          2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts           1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: main
    visible: true
    title: "Compiler"
    property int margin: 11
    property string path: ""
    width: mainLayout.implicitWidth + 2 * margin
    height: mainLayout.implicitHeight + 2 * margin
    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin
    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: margin
        Layout.minimumWidth: 600
        Layout.minimumHeight: 200
        GroupBox {
            id: pathToOnnxBox
            title: "Onnx model"
            Layout.fillWidth: true

            RowLayout {
                id: pathToOnnx
                anchors.fill: parent
                Button {
                    text: "Select"
                    onClicked: {
                        onnxs.open()
                    }
                }
                TextField {//TODO: select
                    objectName: "onnxPathStr"
                    id: onnxPathStr
                    placeholderText: "Path to the onnx model"
                    Layout.fillWidth: true
                }
                Button {
                    id:viewBtn
                    text: "View"
                    onClicked: {
                        //TODO: validate the path
                        path = onnxPathStr.text;
                        var component = Qt.createComponent("Viewer.qml");
                        var view = component.createObject(main);
                        view.show();
                    }
                }
                FileDialog {
                    id:onnxs
                    title: "select"
                    folder: shortcuts.desktop
                    selectExisting: true
                    selectFolder: false
                    selectMultiple: false
                    nameFilters: ["onnx files (*.onnx)"]
                    onAccepted: {
                        //TODO: modify the path (without file:)
                        onnxPathStr.text = onnxs.fileUrl;
                        console.log("You chose: " + onnxs.fileUrl);
                    }
                    onRejected: {
                        onnxPathStr.text = "";
                    }
                }
            }
        }

        GroupBox {
            id: pathToConfigBox
            title: "Configuration file"
            Layout.fillWidth: true

            RowLayout {
                id: pathToConfig
                anchors.fill: parent
                Button {
                    text: "Select"
                    onClicked: {
                        configs.open()
                    }
                }
                TextField {
                    id:configPathStr
                    placeholderText: "Path to the configuration file"
                    Layout.fillWidth: true
                }
                FileDialog {
                    id:configs
                    title: "select"
                    folder: shortcuts.desktop
                    selectExisting: true
                    selectFolder: false
                    selectMultiple: false
                    nameFilters: ["All files (*.*)"]
                    onAccepted: {
                        configPathStr.text = configs.fileUrl;
                        console.log("You chose: " + configs.fileUrl);
                    }
                    onRejected: {
                        configPathStr.text = "";
                    }
                }
            }
        }

        GroupBox {
            id: parameters
            title: "Parameter setting"
            Layout.fillWidth: true

            GridLayout {
                id: gridLayout
                rows: 2
                flow: GridLayout.TopToBottom
                anchors.fill: parent

                Label { text: "Shared_SRAM:" }
                Label { text: "Local_SRAM:" }

                TextField {placeholderText: "0-255" }
                TextField {placeholderText: "0-255" }
            }
        }
        Button{
            id: submitBtn
            text: "Submit"
            onClicked: {

            }
        }
    }
//    ApplicationWindow {
//        visible: false
//        id: viewer
//        width: 1280; height: 720    // MPEG - 2 HD 720p - 1280 x 720 16:9
//        title: "Onnx Viewer"
//        property string path: ""
//        Label{
//            id: l
//            text: "bee"
//        }
//    }
//    Connections{
//        target: viewBtn
//        onClicked: {
//            viewer.path = onnxPathStr.text;
//            l.text = viewer.path;
//            viewer.visible = true;
//        }
//    }
}
