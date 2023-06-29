import QtQuick 2.0
import QtQuick.Layouts 1.3

Item
{
    id: layoutGrid

    property int column: 1
    property int row: 1
    property string color: "#00000000"

    onChildrenChanged: updatePreferredSizes()
    onWidthChanged: updatePreferredSizes()
    onHeightChanged: updatePreferredSizes()
    onColumnChanged: updatePreferredSizes()
    onRowChanged: updatePreferredSizes()

    function updatePreferredSizes()
    {
        var cellWidth = layoutGrid.width / column
        var cellHeight = layoutGrid.height / row
        var lenghtGhildrenLayout = Object.keys(layoutGrid.children).length


        if( lenghtGhildrenLayout === 0 || lenghtGhildrenLayout === undefined )
        {
          return;
        }

        for(var keyWhile = 0; keyWhile !== lenghtGhildrenLayout; keyWhile++)
        {
          var obj = layoutGrid.children[keyWhile]
          if(obj !== undefined)
          {
              var tempColumnValue = obj.Layout.column
              var tempRowValue = obj.Layout.row
              var tempColumnSpan = obj.Layout.columnSpan
              var tempRowSpan = obj.Layout.rowSpan

              obj.x = tempColumnValue * cellWidth
              obj.y = tempRowValue * cellHeight
              obj.height = tempRowSpan * cellHeight
              obj.width = tempColumnSpan * cellWidth
          }

        }
    }

    Rectangle
    {
        color: layoutGrid.color
    }
}
