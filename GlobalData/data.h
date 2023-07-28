#ifndef DATA_H
#define DATA_H

#include <QtQuick/QQuickItem>
#include <QVector>

#ifndef Q_MOC_RUN
    #define BTN_SLOT_TAG
#endif

struct ConnectionModelData
{
    QQuickItem* Obejct;
    QVector<QMetaMethod> Signals;
    QVector<QMetaMethod> Slots;
};

#endif // DATA_H
