#include "windowsmanager.h"

SPView WindowsManager::m_window = nullptr;

bool WindowsManager::changeDisplayed(const QString& url)
{
    if(!m_url.isNull())
    {
        m_window->setSource(url);
        m_window->show();
        return true;
    }

    return false;
}

void WindowsManager::setupPropertyWindow(const int height, const int width, const QString &title) const
{
    m_window->setHeight(height);
    m_window->setWidth(width);
    m_window->setTitle(title);
}

WindowsManager::WindowsManager()
{

}

bool WindowsManager::IsValid()
{
    return m_window.isNull();
}

void WindowsManager::SetUrl(const QString &str)
{
    m_url =str;
    emit urlChanged();
}

void WindowsManager::CreateViewInstance()
{
    if(IsValid())
        m_window = QSharedPointer<QQuickView>(new QQuickView);
}
