#ifndef MWCREATORCONNECTION_H
#define MWCREATORCONNECTION_H
#include <QObject>
#include <QSharedPointer>
#include "../Interface/connection.h"
#include "../MainWindow/mainwindow.h"

class MWCreatorConnection : public IConnection
{

public:
    MWCreatorConnection() =  default;
    void Main();

private:
   QSharedPointer<MainWindow> mainWindowPtr;
};

#endif // MWCREATORCONNECTION_H
