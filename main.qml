import QtQuick 2.6
import Layout 1.0
import QtQuick.Layouts
import QtQuick.Controls 2.3
import WindowsManager 1.0

ApplicationWindow
{
    height: 500
    width: 720
    title: qsTr("Black Jack")
    visible: true

    Item
    {
        anchors.fill: parent

        GridLayoutUtil
        {
            column: 1
            row: 5
        }

        GridLayoutUtil
        {
            column: 3
            row: 2
        }


        GridLayoutUtil
        {
            column: 1
            row: 3
        }
    }
}



