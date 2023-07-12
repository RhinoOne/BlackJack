#include "windowsmanager.h"

SPView WindowsManager::m_window = nullptr;
QString WindowsManager::m_url = "";

bool WindowsManager::changeDisplayed(const QString& url)
{
    if(!url.isNull())
    {
        m_window->setSource(url);
        m_url = url;
        return true;
    }

    return false;
}

void WindowsManager::setupPropertyWindow(QRect rect, const QString &title)
{
    m_window->setTitle(title);
    QRect rectDesktop = QGuiApplication::primaryScreen()->geometry();
    rect.moveCenter(QPoint(rectDesktop.width()/2, rectDesktop.height()/2));
    m_window->setGeometry(rect);
    m_window->show();
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

SPView WindowsManager::GetViewInstance()
{
    return m_window;
}
