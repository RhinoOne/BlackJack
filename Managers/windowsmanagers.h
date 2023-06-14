#ifndef WINDOWSMANAGERS_H
#define WINDOWSMANAGERS_H
#include <qobject.h>
#include <QSharedPointer>
#include <QQmlApplicationEngine>

class WindowsManagers : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
    static QSharedPointer<WindowsManagers> GetInstancePtr();
    WindowsManagers(WindowsManagers& obj) = delete;

protected:

private:
    static QSharedPointer<WindowsManagers> Instance;
    WindowsManagers();
};

#endif // WINDOWSMANAGERS_H
