#include "windowsmanager.h"
#include <QGuiApplication>

QSharedPointer<WindowsManager> WindowsManager::m_instance = nullptr;
QSharedPointer<QQuickView> WindowsManager::m_window = nullptr;



WindowsManager::WindowsManager()
{

}

WindowsManager *WindowsManager::create(QQmlEngine *qmlEngine, QJSEngine *jsEngine)
{
    if(m_instance == nullptr)
    {
        m_instance = QSharedPointer<WindowsManager>(new WindowsManager);
        jsEngine->setObjectOwnership(m_instance.data(), QJSEngine::CppOwnership);

        m_instance->CreateViewInstance();
        m_instance->CreateUrlList();
    }

    return m_instance.data();
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
    m_urlViewers.insert(WindowsManager::MainWindow, QUrl(u"qrc:/BlackJack/MainWindow/main.qml"_qs));
}

SPView WindowsManager::GetViewInstance()
{
    return (m_window != nullptr) ? m_window : nullptr;
}

void WindowsManager::ChangeDisplayView(QQuickView* view)
{
    m_window = QSharedPointer<QQuickView>(view);
}

WindowsManager::~WindowsManager()
{

}

//Integration methods with QML

void WindowsManager::setupPropertyWindow(QRect rect, const QString &title, WindowsManager::TypeWindow typeWindow)
{
    m_window->setTitle(title);
    QRect rectDesktop = QGuiApplication::primaryScreen()->geometry();
    rect.moveCenter(QPoint(rectDesktop.width()/2, rectDesktop.height()/2));
    m_window->setGeometry(rect);
}

void WindowsManager::createCurrentWindowType(TypeWindow type)
{
    if(type != WindowsManager::None)
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

        m_qml_eng_app.load(url);
    }
}

