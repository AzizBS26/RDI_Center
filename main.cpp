#include "mainwindow.h"
#include "employe.h"
#include "connection.h"
#include "dialog.h"
//#include "DuMessangerServer.h"
//#include"dumessangersocket.h"
#include <QMessageBox>
#include <QApplication>

//using namespace DuarteCorporation;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Connection c;
    bool test=c.createconnect();

    MainWindow w;
   // Dialog d;

   // Employe E;
    // E.show();
    //w.show();

    if(test)
    {
        /*DuMessangerServer Server;
        if(!Server.startServer(3333)){
            qDebug() <<"Error:" << Server.errorString();
            return 1;
        }
        qDebug() <<"Server started...";*/
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    //return a.exec();



    return a.exec();
}
