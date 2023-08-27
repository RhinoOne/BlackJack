#ifndef ICONNECTION_H
#define ICONNECTION_H

#include <QObject>
#include <QQuickItem>
#include <QRegularExpression>

class IConnection
{
public:
    IConnection();
//    Basic methods that give general information about the current window for subsequent work with a Signals/Slots connection
    virtual QMap<QString, QQuickItem*> GetUIObject(const QRegularExpression& filter) = 0;

    //Basic Methods for сonnecting all Signals/Slots
    virtual void InitializeButtonConnectionModel() = 0;
    virtual void CreateConnection() = 0;

    virtual ~IConnection();

};

#endif // ICONNECTION_H
