#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>
#include "Managers/windowsmanagers.h"
#include <QQuickView>

Q_IMPORT_QML_PLUGIN(SpecificLayoutPlugin)

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
//    QQuickView *view = new QQuickView;
//    view->setSource(QUrl(u"qrc:/BlackJack/main.qml"_qs));
//    view->show();
//    engine.load(url);
    return app.exec();
}
