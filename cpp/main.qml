import QtQuick                   2.8
import QtQuick.Controls          2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts           1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: main
    visible: true
    title: "Compiler"
    width:  100
    height: 100
    Label{
        text: "re"
        x:60
        y:60
    }

//    Button{
//        x:0
//        y:0
//        width: 50
//        height:50
//        text: "ss"
//        onClicked: {
//            var component = Qt.createComponent("cpp_sample.qml");
//            var view = component.createObject(main);
//            view.show();
//        }
//    }
}

