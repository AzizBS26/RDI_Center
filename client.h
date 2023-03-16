#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString);
    int getid_client();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString gettyperecherche();

    void setid_client(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void settyperecherche(QString);
    bool ajouter();
    bool supprimer(int);
   // bool modifier();
    QSqlQueryModel* afficher();




private:
int id_client;
QString nom, prenom, adresse, typerecherche;
};

#endif // CLIENT_H
