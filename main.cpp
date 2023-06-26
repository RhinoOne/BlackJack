#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>
#include <QQuickView>
#include <WindowsManager/windowsmanager.h>
#include <QQmlContext>

Q_IMPORT_QML_PLUGIN(LayoutPlugin)
Q_IMPORT_QML_PLUGIN(WindowsManagerPlugin)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/BlackJack/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    WindowsManager::CreateViewInstance();
    return app.exec();
}
