import QtQuick 2.6
import Layout 1.0
import QtQuick.Layouts
import QtQuick.Controls 2.0
import WindowsManager 1.0

Window
{
    height: 200
    width: 200
    visible: true

    GridLayoutUtil
    {

        column: 2
        row:2

        Item
        {
            Layout.column: 1
            Layout.row: 0

            Button
            {
                height: 100
                width: 100
                text: "test"
                onClicked: {

                    WindowsManager.changeDisplayed("BlackJack/UI/Test.qml");
                    WindowsManager.setupPropertyWindow(450, 450, "Test");
                }
            }

        }

        Item
        {
            Layout.column: 1
            Layout.row: 1
            Text
            {
               text: WindowsManager.url
            }
        }

    }
}



