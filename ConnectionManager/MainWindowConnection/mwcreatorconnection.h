#ifndef MWCREATORCONNECTION_H
#define MWCREATORCONNECTION_H
#include <QObject>
#include <QSharedPointer>

#include "../Interface/connection.h"
#include "../GlobalData/data.h"

class MWCreatorConnection : public QObject,
                            public IConnection
{
    Q_OBJECT

    QQuickItem* GetRootObject() override;
    QMap<QString, QQuickItem*> GetUIObject(const QRegularExpression& filter,const QQuickItem* rootObject) override;

    void InitializeButtonConnectionModel() override;
    void CreateConnection() override;

public slots:
    BTN_SLOT_TAG void TestClick(){qDebug() << "TestClick";}
    BTN_SLOT_TAG void TestToggled(){qDebug() << "TestTooggled";}

public:
    MWCreatorConnection();
    virtual ~MWCreatorConnection();

private:
    QVector<ConnectionModelData> m_main_cmd;
};


#endif // MWCREATORCONNECTION_H
