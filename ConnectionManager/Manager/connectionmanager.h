#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QtQml>

#include "../GlobalData/data.h"
#include "../WindowsManager/windowsmanager.h"

struct ConnectionModelData;

class IConnection;

class ConnectionManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:

    ConnectionManager();
    ~ConnectionManager();

    Q_INVOKABLE void makeConnection(GlobalEnumData::TypeWindow type);

private:
    QSharedPointer<IConnection> m_connection;
    QVector<ConnectionModelData*> m_con_model_data;
};

#endif // CONNECTIONMANAGER_H
