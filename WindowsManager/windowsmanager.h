#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QSharedPointer>
#include <QGuiApplication>
#include "../GloabalData/data.h"

typedef QSharedPointer<QQuickView> SPView;

class WindowsManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QString url READ GetUrl WRITE SetUrl NOTIFY urlChanged)

signals:
    void urlChanged();

public:
    Q_INVOKABLE static bool changeDisplayed(TypeWindow type);
    Q_INVOKABLE static void setupPropertyWindow(QRect rect, const QString& title);

public:

    WindowsManager();
    static bool IsValid();
    static void CreateViewInstance();
    static SPView GetViewInstance();
    static void CreateUrlList();
    static void CreateViewersList();

    QString GetUrl(){return m_url;}
    void SetUrl(const QString& str);

    ~WindowsManager()= default;

private:

    static QString m_url;
    static SPView m_window;
    static QVector<SPView> m_viewers;
    static QVector<QUrl> m_urlViewers;

};

#endif // WINDOWSMANAGERS_H
