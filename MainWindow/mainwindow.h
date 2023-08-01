#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlInfo>
#include <QMetaMethod>
#include <QMap>
#include <QQuickItem>

class MainWindow : public QObject
{
    Q_OBJECT
public:

    MainWindow();

private:
    QMap<QObject*, QMetaMethod> m_objectsMap;
};

#endif // MAINWINDOW_H
