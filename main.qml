import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: 100
        height: 100
        color: "orange"
        objectName: "test"
        Text {
            id: thetext
            anchors.centerIn: parent
            text: "placeholder"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: print('parent objectName: ' + parent.objectName)
        }

    }

    Connections {
        target: theworker
        onStarted: {
            print('worker thread started')
        }

        onDataChanged: {
            print('data changed to: ' + theworker.getData() );
            thetext.text = theworker.getData();
        }
    }

    Component.onDestruction: theworker.terminate();
}
