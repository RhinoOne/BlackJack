#include "connectionmanager.h"
#include "../Interface/connection.h"
#include "../ConnectionManager/MainWindowConnection/mwcreatorconnection.h"


ConnectionManager::ConnectionManager()
{

}

void ConnectionManager::makeConnection(GlobalEnumData::TypeWindow type)
{
    if(GlobalEnumData::MainWindow == type)
    {
        m_connection = QSharedPointer<IConnection>(new MWCreatorConnection());
        if(m_connection != nullptr)
        {
            m_connection->InitializeButtonConnectionModel();
            m_connection->CreateConnection();
        }
    }
}

ConnectionManager::~ConnectionManager()
{

}
