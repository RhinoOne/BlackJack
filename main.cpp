#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>
#include <QQuickView>
#include <QQmlContext>

#include "WindowsManager/windowsmanager.h"


Q_IMPORT_QML_PLUGIN(LayoutPlugin)
Q_IMPORT_QML_PLUGIN(ConnectionManagerPlugin)

int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);

   WindowsManager* kilo = new WindowsManager;
   kilo->CreateInstance();
   WindowsManager::GetWindowsManagerInstance()->createCurrentWindowType(GlobalEnumData::MainWindow);

    return app.exec();
}
