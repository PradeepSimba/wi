#include "networkthread.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include<QString>
#include <QTextStream>
#include <iostream>
#include "fakeinput.h"
#include <QFile>

void app(QString b){
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


void process(QString b){
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

void cpu(QString b){
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

void ram(QString b){
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    

    NetworkThread networkThread;


    networkThread.start();
    int result = a.exec();

    networkThread.requestInterruption();
    networkThread.exit();
    networkThread.wait(2000);

    return result;
}
