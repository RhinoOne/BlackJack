#include "mwcreatorconnection.h"
#include "../../WindowsManager/windowsmanager.h"

MWCreatorConnection::MWCreatorConnection()
{

}

QQuickItem *MWCreatorConnection::GetRootObject()
{
    QSharedPointer<QQuickView> tempViewWindow = WindowsManager::GetViewInstance();
    if(!tempViewWindow.isNull())
        return tempViewWindow->rootObject();

    return nullptr;
}

QMap<QString, QQuickItem*> MWCreatorConnection::GetUIObject(const QRegularExpression &filter,const QQuickItem* rootObject)
{
    assert(rootObject);
    QVector<QQuickItem*> UIItems = rootObject->findChildren<QQuickItem*>(filter, Qt::FindChildrenRecursively);

    const int countUIObjects = UIItems.size();
    QMap<QString, QQuickItem*> UIObjects;

    for(int keyInitMap = 0; keyInitMap != countUIObjects; keyInitMap++)
    {
        QQuickItem* tempUIItem = UIItems.at(keyInitMap);
        UIObjects.insert(tempUIItem->objectName(), tempUIItem);
    }

    return UIObjects;
}

void MWCreatorConnection::InitializeButtonConnectionModel()
{
    const QRegularExpression reg ("btn");
    const QQuickItem* rootWindowObject = GetRootObject();

    QMap<QString, QQuickItem*> btnObjects = GetUIObject(reg, rootWindowObject);

    m_main_cmd.push_back(ConnectionModelData{*btnObjects.find("btnSweep"),
                         QVector<const char*>{SIGNAL(clicked()), SIGNAL(toggled())},
                         QVector<const char*>{SLOT(TestClick()), SLOT(TestToggled())}
                         });

    m_main_cmd.push_back(ConnectionModelData{*btnObjects.find("btnIcon"),
                         QVector<const char*>{SIGNAL(released())},
                         QVector<const char*>{SLOT(TestToggled())}
                         });
}

void MWCreatorConnection::CreateConnection()
{
    for(const ConnectionModelData &tempObjConn : qAsConst(m_main_cmd))
    {
        QQuickItem* currentItem = tempObjConn.Object;
        QVector<const char*> currentSignals = tempObjConn.Signals;
        QVector<const char*> currentSlots = tempObjConn.Slots;

        const int currenntCountConnection = currentSignals.size();

        for(int keyCreateConn = 0; keyCreateConn != currenntCountConnection; keyCreateConn++)
        {
            connect(currentItem, currentSignals.at(keyCreateConn), this, currentSlots.at(keyCreateConn));
        }
    }
}

MWCreatorConnection::~MWCreatorConnection()
{

}




