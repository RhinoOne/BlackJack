#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlInfo>
#include <QMetaMethod>
#include <QMap>

class MainWindow : public QObject
{
    Q_OBJECT

public:

    MainWindow()
    {

    }

    void TestFunc() {qDebug() << "sdasd";}

    void ToggleSidebarItems(QMetaMethod & kilor)
    {
        qDebug() << "ToggleSidebarItems";
    }
private:
    QMap<QObject*, QMetaMethod&> sds;
};

#endif // MAINWINDOW_H
