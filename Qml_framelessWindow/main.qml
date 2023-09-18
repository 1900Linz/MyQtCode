import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {

    property bool isMoveWindow: false
    property point rootWindowTitleMousePos: Qt.point(x,y)

    id : rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    flags: Qt.Window | Qt.FramelessWindowHint

    onTitleChanged: rootWindowTitleBarTitleText.text = title

    Rectangle {

        id : rootWindowTitleBar
        width: rootWindow.width
        height: 40

        border.color: "red"
        color: "black"

        Text {
            id: rootWindowTitleBarTitleText
            text: rootWindow.title
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
        }

        // 为窗口标题栏添加鼠标事件
        MouseArea {

            anchors.fill: rootWindowTitleBar
            // 只处理鼠标左键
            acceptedButtons: Qt.LeftButton
            // 接收鼠标按下事件
            onPressed: {

                rootWindow.rootWindowTitleMousePos = Qt.point(mouseX,mouseY)
                rootWindow.isMoveWindow = true
//                mouse.accepted = false; //鼠标穿透 事件响应区域可能叠加
            }

            // 鼠标释放，关闭窗口移动flag
            onReleased: {

                if(mouse.button === Qt.LeftButton){

                    rootWindow.isMoveWindow = false
                }
            }

            //
            onMouseXChanged: {

                if(rootWindow.isMoveWindow){

                    rootWindow.x += mouseX - rootWindow.rootWindowTitleMousePos.x;
                }
            }
            onMouseYChanged: {

                rootWindow.y += mouseY - rootWindow.rootWindowTitleMousePos.y;
            }

        }
    }
}
