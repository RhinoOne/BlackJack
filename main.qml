import QtQuick 2.6
import Layout 1.0
import QtQuick.Layouts
import QtQuick.Controls 2.3
import WindowsManager 1.0


ApplicationWindow
{
    height: 720
    width: 1280
    title: qsTr("Black Jack")
    visible: true

    GridLayoutUtil
    {
        anchors.fill: parent
        column: 20
        row:2

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
                    Layout.row: 1

                    Rectangle
                    {
                        anchors.fill: parent
                        anchors.margins: 20
                        color: "blue"
                    }
                }


                Text
                {
                    Layout.column: 0
                    Layout.columnSpan: 3
                    Layout.row: 2
                }
            }
        }
    }
}



