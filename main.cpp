#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>
#include <QQuickView>
#include <WindowsManager/windowsmanager.h>
#include <MainWindow/mainwindow.h>
#include <QQmlContext>

Q_IMPORT_QML_PLUGIN(LayoutPlugin)
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
    WindowsManager::changeDisplayed(u"qrc:/BlackJack/MainWindow/main.qml"_qs);
    WindowsManager::setupPropertyWindow(QRect(0,0,1280, 720), "BlackJack");

    return app.exec();
}
