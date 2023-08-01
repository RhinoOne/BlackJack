#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QObject>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QSharedPointer>

typedef QSharedPointer<QQuickView> SPView;

class WindowsManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:

    enum TypeWindow
    {
        None,
        MainWindow,
        SettingWindow,
        TestWindow,
    };

    Q_ENUM(TypeWindow)

    Q_INVOKABLE static void setupPropertyWindow(QRect rect, const QString& title, WindowsManager::TypeWindow typeWindow);
    Q_INVOKABLE static void changeDisplayed(WindowsManager::TypeWindow type);
    Q_INVOKABLE static void createCurrentWindowType(WindowsManager::TypeWindow type);

public:

    WindowsManager();
    static bool IsValid();
    static SPView GetViewInstance();

    static void CreateViewInstance();
    static void CreateUrlList();
    static void CreateViewersList();

    ~WindowsManager()= default;

private:

    static QString m_url;
    static SPView m_window;
    static QMap<WindowsManager::TypeWindow, SPView> m_viewers;
    static QMap<WindowsManager::TypeWindow, QUrl> m_urlViewers;
};

#endif // WINDOWSMANAGERS_H
