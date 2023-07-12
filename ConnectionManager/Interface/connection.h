#ifndef ICONNECTION_H
#define ICONNECTION_H


class IConnection
{
public:
    IConnection() = default;
    virtual void SetButtonConnection() = 0;
    virtual ~IConnection();
};

#endif // ICONNECTION_H
