#include "windowsmanager.h"
#include <QGuiApplication>


SPView WindowsManager::m_window = nullptr;
QString WindowsManager::m_url = "";
QMap<WindowsManager::TypeWindow, SPView> WindowsManager::m_viewers = QMap<WindowsManager::TypeWindow, SPView>();
QMap<WindowsManager::TypeWindow, QUrl> WindowsManager::m_urlViewers =  QMap<WindowsManager::TypeWindow, QUrl>();

WindowsManager::WindowsManager()
{

}

bool WindowsManager::IsValid()
{
    return m_window.isNull();
}

SPView WindowsManager::GetViewInstance()
{
    return m_window;
}

void WindowsManager::CreateViewInstance()
{
    if(IsValid())
        m_window = QSharedPointer<QQuickView>(new QQuickView);
}

void WindowsManager::CreateUrlList()
{
    m_urlViewers.insert(WindowsManager::MainWindow, QUrl(u"qrc:/BlackJack/MainWindow/main.qml"_qs));
}

void WindowsManager::CreateViewersList()
{
   if(!(m_urlViewers.empty()))
   {
        auto bIterUlrViewers = m_urlViewers.cbegin();
        auto eIterUrlViewers = m_urlViewers.cend();

        for(; bIterUlrViewers != eIterUrlViewers; bIterUlrViewers++)
        {
            m_viewers.insert(bIterUlrViewers.key(),SPView(new QQuickView));
        }
   }
}

//Integration methods with QML
void WindowsManager::setupPropertyWindow(QRect rect, const QString &title, WindowsManager::TypeWindow typeWindow)
{
    auto viewerIter = m_viewers.find(typeWindow);

    assert(*viewerIter);
    viewerIter.value()->setTitle(title);

    QRect rectDesktop = QGuiApplication::primaryScreen()->geometry();
    rect.moveCenter(QPoint(rectDesktop.width()/2, rectDesktop.height()/2));

    viewerIter.value()->setGeometry(rect);
}

void WindowsManager::changeDisplayed(TypeWindow type)
{

    if(type != TypeWindow::None)
    {
        m_window = *m_viewers.find(type);
        m_window->show();
        assert(m_window);
    }
    assert(true);
}

void WindowsManager::createCurrentWindowType(TypeWindow type)
{
    if(type != WindowsManager::None)
    {
        const QUrl url = *m_urlViewers.find(type);
        m_viewers.find(type).value()->setSource(url);
    }
    assert(true);
}
