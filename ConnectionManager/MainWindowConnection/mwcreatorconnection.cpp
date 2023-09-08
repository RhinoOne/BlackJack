#include "mwcreatorconnection.h"
#include "../../WindowsManager/windowsmanager.h"

MWCreatorConnection::MWCreatorConnection()
{

}

QMap<QString, QQuickItem*> MWCreatorConnection::GetUIObject(const QRegularExpression &filter)
{
    const QQuickView* rootWindowObject = WindowsManager::GetViewInstance().data();
    QVector<QQuickItem*> UIItems = rootWindowObject->findChildren<QQuickItem*>(filter, Qt::FindChildrenRecursively);

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

    QMap<QString, QQuickItem*> btnObjects = GetUIObject(reg);

    m_main_cmd.push_back(ConnectionModelData{*btnObjects.find("btnSweep"),
                         QVector<const char*>{SIGNAL(clicked())},
                         QVector<const char*>{SLOT(ActivationSidePanel())}
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

void MWCreatorConnection::ActivationSidePanel()
{
    const QRegularExpression reg ("leftSidePanel");
    QMap<QString, QQuickItem*> sidePanels = GetUIObject(reg);
    QQuickItem* item = sidePanels.find("leftSidePanel").value();

    if(item->state() != "Hidden")
    {
        item->setState("Hidden");
    }
    else
    {
        item->setState("Show");
    }
}

MWCreatorConnection::~MWCreatorConnection()
{

}




