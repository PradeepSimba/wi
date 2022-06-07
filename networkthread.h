#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QThread>
#include <QString>

#include "abstractedsocket.h"

class NetworkThread : public QThread
{
public:
    void run();

private:
    QByteArray getPassword();
    bool verifyClient(AbstractedSocket *socket);
    void startInputLoop();
    void updateClientIp(QString ip);
};

#endif // NETWORKTHREAD_H
