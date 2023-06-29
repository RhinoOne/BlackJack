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
        column: 3

        GridLayoutUtil
        {
            row:10
            column: 3
            Layout.column: 0
            Layout.row: 0
            Layout.rowSpan: 10
            color : "#204b0082"

            GridLayoutUtil
            {
                row: 10
                column: 3

                RowLayout
                {
                    Layout.column: 1
                    Layout.row: 0
                    Button
                    {
                        Layout.minimumHeight: 50
                        Layout.minimumWidth: 50
                        text:qsTr("Test\n Test")
                    }
                }

                RowLayout
                {
                    Layout.column: 1
                    Layout.row: 1
                    Button
                    {
                        text:qsTr("Test\n Test")
                    }
                }

                RowLayout
                {
                    Layout.column: 1
                    Layout.row: 2
                    Button
                    {
                        text:qsTr("Test\n Test")
                    }
                }
            }
        }
    }
}



