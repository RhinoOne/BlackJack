#include "windowsmanager.h"

SPView WindowsManager::m_window = nullptr;
QString WindowsManager::m_url = "";
QVector<SPView> WindowsManager::m_viewers = QVector<SPView>();
QVector<QUrl> WindowsManager::m_urlViewers =  QVector<QUrl>();

WindowsManager::WindowsManager()
{

}
bool WindowsManager::changeDisplayed(TypeWindow type)
{
    if(type != TypeWindow::None)
    {
        m_window = m_viewers[(int)type];
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

void WindowsManager::CreateUrlList()
{
    m_urlViewers.push_back(QUrl(u"qrc:/BlackJack/MainWindow/main.qml"_qs));
    m_urlViewers.push_back(QUrl(u"qrc:/BlackJack/MainWindow/test.qml"_qs));
}

void WindowsManager::CreateViewersList()
{
   const int countUrlWindowsApp =  m_urlViewers.size();
   if(!(countUrlWindowsApp <= 0))
   {
        for(int key = 0; key != countUrlWindowsApp; key ++)
        {
            QUrl tempCurrentUrlWindow = m_urlViewers[key];
            SPView tempCurrentViewWindow = SPView(new QQuickView);
            tempCurrentViewWindow->setSource(tempCurrentUrlWindow);
            m_viewers.push_back(SPView(tempCurrentViewWindow));
            tempCurrentViewWindow.clear();
        }
   }
}
