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
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/BlackJack/MainWindow/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    WindowsManager::CreateViewInstance();
    WindowsManager::CreateUrlList();
    WindowsManager::CreateViewersList();

    WindowsManager::createCurrentWindowType(WindowsManager::MainWindow);

    return app.exec();
}
