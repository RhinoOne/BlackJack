#include "connectionmanager.h"
#include "../Interface/connection.h"
#include "../ConnectionManager/MainWindowConnection/mwcreatorconnection.h"
#include "../GlobalData/data.h"

ConnectionManager::ConnectionManager()
{

}

void ConnectionManager::makeConnection(WindowsManager::TypeWindow type)
{
    if(WindowsManager::TypeWindow::MainWindow == type)
    {
        m_connection = QSharedPointer<IConnection>(new MWCreatorConnection());
        if(m_connection != nullptr)
        {
            m_connection->InitializeButtonConnectionModel();
            m_connection->CreateConnection();
        }
    }
}

