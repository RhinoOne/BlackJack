#ifndef DATA_H
#define DATA_H

#include <QtQuick/QQuickItem>
#include <QVector>

#ifndef Q_MOC_RUN
    #define BTN_SLOT_TAG
#endif

struct ConnectionModelData
{
    QQuickItem* Object;
    QVector<const char*> Signals;
    QVector<const char*> Slots;
};

class GlobalEnumData : public QObject
{
    Q_OBJECT

public:
    enum TypeWindow
    {
        None,
        MainWindow,
        SettingWindow,
        TestWindow,
    };

    Q_ENUM(TypeWindow)

public:
    static void DeclareEnum();

protected:
    GlobalEnumData() = default;
    ~GlobalEnumData() = default;

private:
};

#endif // DATA_H
