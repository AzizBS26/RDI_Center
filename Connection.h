#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
class Connection
{
private:
    QSqlDatabase db;
public :
    Connection();
    bool ouvrirconnection();
    void fermerConnection();
};

#endif // CONNECTION_H
