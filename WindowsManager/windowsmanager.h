#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H
#include <QObject>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QSharedPointer>

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
    Q_INVOKABLE bool changeDisplayed(const QString& url);
    Q_INVOKABLE void setupPropertyWindow(const int height, const int width, const QString& title) const;

public:

    WindowsManager();
    static bool IsValid();
    static void CreateViewInstance();

    QString GetUrl(){return m_url;}
    void SetUrl(const QString& str);

    ~WindowsManager()= default;
private:

    QString m_url;
    static SPView m_window;
};



#endif // WINDOWSMANAGERS_H
