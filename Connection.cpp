#include "Connection.h"
#include <QSqlDatabase>
Connection::Connection(){}


bool Connection::ouvrirconnection( )


{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false ;

    db.setDatabaseName("projet1233");
    db.setUserName("fares");
    db.setPassword("fares");

    if(db.open()) test=true ;

    return test ;
}
void Connection::fermerConnection(){db.close(); }
