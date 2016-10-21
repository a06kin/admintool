#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include "serverinfo.h"
#include <QUdpSocket>
#include <QThread>

class Worker;

class LogHandler: public QObject
{
    Q_OBJECT
public:
    LogHandler(MainWindow *);
    ~LogHandler();
    void createBind(quint16);
    void removeServer(ServerInfo *);
    void addServer(ServerInfo *);
    void createSocket();
    QString szPort;
    bool isBound;
    QHostAddress externalIP;
    QHostAddress internalIP;

signals:
    void setupUPnP(LogHandler *);

private slots:
    void socketReadyRead();
    void socketDisconnected();

public slots:
    void UPnPReady();

private:
    quint16 logPort;
    QUdpSocket *logsocket;
    QList<ServerInfo *> logList;
    MainWindow *pMain;
    QThread workerThread;
    Worker *worker;
};

#endif // LOGHANDLER_H