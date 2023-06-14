#include "windowsmanagers.h"

QSharedPointer<WindowsManagers> WindowsManagers::Instance  = nullptr;

QSharedPointer<WindowsManagers> WindowsManagers::GetInstancePtr()
{
    if(Instance == nullptr)
    {
        QSharedPointer<WindowsManagers> TempManager (new WindowsManagers);
        Instance = TempManager;
    }

    return Instance;
}

WindowsManagers::WindowsManagers()
{

}


