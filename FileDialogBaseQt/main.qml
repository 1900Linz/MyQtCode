import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtCode 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("FileDialog")

    Row {
        anchors.centerIn: parent
        spacing: 12
        Button {
            text: "file"
            onClicked: file.open()
        }
        Button {
            text: "files"
            onClicked: files.open()
        }
        Button {
            text: "save"
            onClicked: {
                save.selectUrl(save.desktopUrl() + "/default.txt")
                save.open()
            }
        }
    }

    FileDialog_ {
        id: file
        dialogMode: FileDialog_.ByFile
        onAccepted: {
            console.log('file accepted', file.currentFiles)
        }
    }
    FileDialog_ {
        id: files
        dialogMode: FileDialog_.ByFiles
        onAccepted: {
            console.log('files accepted', files.currentFiles)
        }
    }
    FileDialog_ {
        id: save
        dialogMode: FileDialog_.ToSave
        onAccepted: {
            console.log('save accepted', save.currentFiles)
        }
    }
}
