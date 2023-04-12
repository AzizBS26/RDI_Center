#include <QCoreApplication>
//#include<QApplication>
//include<QMessageBox>
#include "DuMessangerServer.h"
#include"dumessangersocket.h"

using namespace DuarteCorporation;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DuMessangerServer Server;
    if(!Server.startServer(3333)){
        qDebug() <<"Error:" << Server.errorString();
        return 1;
    }
    qDebug() <<"Server started...";
    return a.exec();
}
