import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    minimumWidth: 1080
    minimumHeight: 720
    visible: true
    title: qsTr("Rose IDE")

    menuBar: MenuBarIDE {}

    RowLayout {
        anchors.fill: parent
        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ScrollBar.horizontal.policy: ScrollBar.AsNeeded
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

            ScrollBar.horizontal.interactive: true
            ScrollBar.vertical.interactive: true

            TextArea {
                textDocument.objectName: "document"
            }
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: 3
            color: "grey"
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: 300
            color: "yellow"
        }
    }
}
