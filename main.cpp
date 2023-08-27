#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>
#include <QQuickView>
#include <QQmlContext>

#include "WindowsManager/windowsmanager.h"


Q_IMPORT_QML_PLUGIN(LayoutPlugin)
Q_IMPORT_QML_PLUGIN(ConnectionManagerPlugin)
Q_IMPORT_QML_PLUGIN(WindowsManagerPlugin)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine qmlEngine;
    QJSEngine jsEngine;

    WindowsManager::create(&qmlEngine, &jsEngine)->createCurrentWindowType(WindowsManager::MainWindow, &app);

    return app.exec();
}
