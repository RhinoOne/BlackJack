#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlInfo>
#include <QMetaMethod>
#include <QMap>
#include "../WindowsManager/windowsmanager.h"
#include <QQuickItem>

class MainWindow : public QObject
{
    Q_OBJECT
public:

    MainWindow() = default;
    QMap<QObject*, QMetaMethod> GetObjectsMap(){return objectsMap;};

private:
    QMap<QObject*, QMetaMethod> objectsMap;
};

#endif // MAINWINDOW_H
