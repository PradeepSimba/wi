#include "networkthread.h"

#include "fakeinput.h"
#include "abstractedserver.h"
#include "abstractedsocket.h"
#include "encryptutils.h"
#include <QFile>
#include<QString>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include <QDateTime>
#include <QAbstractSocket>
#include <QHostInfo>

QString serverVersion = "2";

/****************************************
 ****************************************
 **
 ** Listen for connections & verify clients
 **
 ****************************************
 ****************************************/


void appa(QString b){
    QFile file("app.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << "could not open file!";
        qCritical() << file.errorString();
        return;
    }

    QString a = b;

    qInfo() << "writing file...";
    file.write(a.toUtf8());
    file.flush();

    file.close();

}


void processa(QString b){
    QFile file("process.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << "could not open file!";
        qCritical() << file.errorString();
        return;
    }

    QString a = b;

    qInfo() << "writing file...";
    file.write(a.toUtf8());
    file.flush();

    file.close();

}

void cpua(QString b){
    QFile file("cpu.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << "could not open file!";
        qCritical() << file.errorString();
        return;
    }

    QString a = b;

    qInfo() << "writing file...";
    file.write(a.toUtf8());
    file.flush();

    file.close();

}

void rama(QString b){
    QFile file("ram.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << "could not open file!";
        qCritical() << file.errorString();
        return;
    }

    QString a = b;

    qInfo() << "writing file...";
    file.write(a.toUtf8());
    file.flush();

    file.close();

}

void NetworkThread::run()
{
    startInputLoop();
   AbstractedServer server;

//   FakeInput::initFakeInput();

   int count = 0;
   while(!isInterruptionRequested()) {

       qInfo() << "Listening for connection... " << ++count;
       server.listenWithTimeout(1000);

       AbstractedSocket *socket = server.nextPendingConnection();
       if(socket == 0)
           continue;

       if(true) {
         

           qInfo() << "Client verified\n";
           startInputLoop();
       }
       else
           qInfo() << "Could not verify client";

       delete socket;
   }

 //  FakeInput::freeFakeInput();
}

/****************************************
 ****************************************
 **
 ** Input loop entered once client is verified
 **
 ****************************************
 ****************************************/

void specialKeyCombo(QString comboString) {
    QStringList keyList = comboString.split(" ");

    for(int i=0; i<keyList.length(); i++)
        FakeInput::keyDown(keyList.at(i));
    for(int i=keyList.length()-1; i>=0; i--)
        FakeInput::keyUp(keyList.at(i));
}

void NetworkThread::startInputLoop()
{
    int pingCount = 0;
    while(!isInterruptionRequested()) {


     processa(FakeInput::getProcesses());
     rama(FakeInput::getRamUsage());
     processa(FakeInput::getProcesses());
     appa(FakeInput::getApplicationNames()+"result");
        

    }
}
