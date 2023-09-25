#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QSharedPointer>
#include <QGuiApplication>

#include "../GlobalData/data.h"

typedef QSharedPointer<QQuickView> SPView;

class WindowsManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    //Methods for QML integration
    Q_INVOKABLE void setupPropertyWindow(QRect rect, const QString& title, GlobalEnumData::TypeWindow typeWindow);
    Q_INVOKABLE void createCurrentWindowType(GlobalEnumData::TypeWindow type);

    static SPView GetViewInstance();
    static WindowsManager* GetWindowsManagerInstance();
    static void CreateInstance();

public:
    void ChangeDisplayView(QQuickView* view);

    explicit WindowsManager(QObject *parent = nullptr);
    ~WindowsManager();

private:
    void CreateViewInstance();
    void CreateUrlList();

private:
    QString m_url;
    QMap<GlobalEnumData::TypeWindow, QUrl> m_urlViewers;
    QQmlApplicationEngine m_qml_eng_app;

    static SPView m_window;
    static WindowsManager* m_instance;
};

#endif // WINDOWSMANAGERS_H
