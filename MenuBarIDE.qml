import QtQuick.Controls 2.15

MenuBar {
    Menu {
        title: qsTr("File")
        Action {
            text: qsTr("New...")
            shortcut: StandardKey.New
        }
        Action {
            text: qsTr("Open...")
            shortcut: StandardKey.Open
        }
        Action {
            text: qsTr("Save")
            shortcut: StandardKey.Save
        }
        Action {
            text: qsTr("Save As...")
            shortcut: StandardKey.SaveAs
        }
        MenuSeparator {}
        Action {
            text: qsTr("Quit")
            shortcut: StandardKey.Quit
        }
    }
    Menu {
        title: qsTr("Edit")
        Action {
            text: qsTr("Cut")
            shortcut: StandardKey.Cut
        }
        Action {
            text: qsTr("Copy")
            shortcut: StandardKey.Copy
        }
        Action {
            text: qsTr("Paste")
            shortcut: StandardKey.Paste
        }
    }
    Menu {
        title: qsTr("Help")
        Action {
            text: qsTr("About")
        }
    }
}
