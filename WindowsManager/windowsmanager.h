#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QSharedPointer>
#include <QGuiApplication>

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

public:
    Q_INVOKABLE void setupPropertyWindow(QRect rect, const QString& title, WindowsManager::TypeWindow typeWindow);
    Q_INVOKABLE void createCurrentWindowType(WindowsManager::TypeWindow type);

    static WindowsManager *create(QQmlEngine *qmlEngine, QJSEngine *jsEngine);
    static SPView GetViewInstance();

public:
    void ChangeDisplayView(QQuickView* view);

    ~WindowsManager();

protected:
    WindowsManager();

private:
    void CreateViewInstance();
    void CreateUrlList();

private:
    QString m_url;
    QMap<WindowsManager::TypeWindow, QUrl> m_urlViewers;
    QQmlApplicationEngine m_qml_eng_app;

    static SPView m_window;
    static QSharedPointer<WindowsManager> m_instance;
};

#endif // WINDOWSMANAGERS_H
