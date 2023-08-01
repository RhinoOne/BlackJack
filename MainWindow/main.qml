import QtQuick 2.6
import Layout 1.0
import QtQuick.Layouts
import QtQuick.Controls 2.3
import WindowsManager 1.0
import ConnectionManager 1.0

Item
{
    anchors.fill: parent

    ConnectionManager
    {
        id: connManager
    }

    Component.onCompleted:
    {
        Qt.callLater(WindowsManager.setupPropertyWindow,Qt.rect(0,0,1280,720), qsTr("BlackJack"), WindowsManager.MainWindow)
        Qt.callLater(connManager.makeConnection, WindowsManager.MainWindow)

        WindowsManager.changeDisplayed(WindowsManager.MainWindow)
    }

    GridLayoutUtil
    {
        anchors.fill: parent
        column: 20
        row:2

        //Container left menu
        Item
        {
            id: container_left_menu
            Layout.column: 0
            Layout.row: 0
            Layout.rowSpan: 2

            GridLayoutUtil
            {
                id: layout_left_menu
                anchors.fill: container_left_menu
                Layout.margins: 20
                row:12
                column: 3
                color : "#204b0082"

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 0

                    Button
                    {
                        objectName: qsTr("btnSweep")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Sweep")
                    }
                }

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 1

                    Button
                    {
                        objectName: qsTr("btnIcon")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Icon")
                    }
                }


                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 2

                    Button
                    {
                        objectName: qsTr("btnMode1")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Mode 1")
                    }
                }


                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 3

                    Button
                    {
                        objectName: qsTr("btnMode2")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Mode 2")
                    }
                }

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 4

                    Button
                    {
                        objectName: qsTr("btnSetting")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Setting")
                    }
                }
            }

        }

        // Hidden content for left menu container
        Item
        {
            id: container_left_menu_hidden
            Layout.column: 1
            Layout.columnSpan: 3
            Layout.row: 0
            Layout.rowSpan: 2

            GridLayoutUtil
            {
                id: layout_left_menu_hidden
                anchors.fill: container_left_menu_hidden
                Layout.margins: 20
                row:12
                column: 3
                color : "#204b0082"

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 0

                    Button
                    {
                        objectName: qsTr("btnSweepH")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Sweep Hidden")
                    }
                }

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 1

                    Button
                    {
                        objectName: qsTr("btnIconH")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Icon Hidden")
                    }
                }


                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 2

                    Button
                    {
                        objectName: qsTr("btnMode1H")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Mode 1 Hidden")
                    }
                }


                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 3

                    Button
                    {
                        objectName: qsTr("btnMode2H")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Mode 2 Hidden")
                    }
                }

                Item
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 4

                    Button
                    {
                        objectName: qsTr("btnSettingH")
                        anchors.fill: parent
                        anchors.margins: 5
                        text: qsTr("Setting")
                    }
                }
            }

        }
    }
}



