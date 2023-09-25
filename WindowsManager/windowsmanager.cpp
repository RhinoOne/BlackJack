#include "windowsmanager.h"
#include <QGuiApplication>
#include "qqmlcontext.h"

WindowsManager* WindowsManager::m_instance = nullptr;
QSharedPointer<QQuickView> WindowsManager::m_window = nullptr;

WindowsManager::WindowsManager(QObject *parent)
    : QObject (parent)
{

}

void WindowsManager::CreateViewInstance()
{
    if(m_window != nullptr)
    {
        m_window = QSharedPointer<QQuickView>(new QQuickView);
    }
}

void WindowsManager::CreateUrlList()
{
    m_urlViewers.insert(GlobalEnumData::MainWindow, QUrl(u"qrc:/BlackJack/MainWindow/main.qml"_qs));
}

SPView WindowsManager::GetViewInstance()
{
    return (m_window != nullptr) ? m_window : nullptr;
}

WindowsManager* WindowsManager::GetWindowsManagerInstance()
{
    return m_instance != nullptr ? m_instance : nullptr;
}

void WindowsManager::CreateInstance()
{
    m_instance = new WindowsManager(&m_qml_eng_app);

    if(m_instance != nullptr)
    {
        m_instance->CreateViewInstance();
        m_instance->CreateUrlList();

        GlobalEnumData::DeclareEnum();
    }
}

void WindowsManager::ChangeDisplayView(QQuickView* view)
{
    m_window = QSharedPointer<QQuickView>(view);
}

WindowsManager::~WindowsManager()
{

}

//Integration methods with QML

void WindowsManager::setupPropertyWindow(QRect rect, const QString &title, GlobalEnumData::TypeWindow typeWindow)
{
    m_window->setTitle(title);
    QRect rectDesktop = QGuiApplication::primaryScreen()->geometry();
    rect.moveCenter(QPoint(rectDesktop.width()/2, rectDesktop.height()/2));
    m_window->setGeometry(rect);
}

void WindowsManager::createCurrentWindowType(GlobalEnumData::TypeWindow type)
{
    if(type != GlobalEnumData::None)
    {
        const QUrl url = *m_urlViewers.find(type);
        QObject* objView = nullptr;

        QMetaObject::Connection conn = QObject::connect(&m_qml_eng_app, &QQmlApplicationEngine::objectCreated,  [url](QObject *obj, const QUrl &objUrl) mutable {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
                else
                {
                    m_window = SPView(static_cast<QQuickView*>(obj));
                }
        });

        m_qml_eng_app.rootContext()->setContextProperty(QStringLiteral("WindowsManager"), WindowsManager::GetWindowsManagerInstance());
        m_qml_eng_app.load(url);
    }
}



