#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>
Client::Client()
{
id_client=0; nom=" ";prenom=" ";adresse=" ";typerecherche=" ";

}
Client::Client(int id_client,QString nom,QString prenom,QString adresse,QString typerecherche)
{this->id_client=id_client; this->nom=nom;this->prenom=prenom;this->adresse=adresse;this->typerecherche=typerecherche;}
int Client::getid_client(){return id_client;}
QString Client::getnom(){return nom;}
QString Client::getprenom(){return prenom;}
QString Client::getadresse(){return adresse;}
QString Client::gettyperecherche(){return typerecherche;}

void Client::setid_client(int id_client){this->id_client=id_client;}
void Client::setnom(QString nom ){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
void Client::setadresse(QString adresse){this->adresse=adresse;}
void Client::settyperecherche(QString typerecherche){this->typerecherche=typerecherche;}
bool Client::ajouter()
{


    QSqlQuery query;
    QString id_client_string=QString::number(id_client);
    query.prepare("insert into client (id_client, nom, prenom,adresse,typerecherche) "
                  "values (:id, :nom, :prenom, :adresse ,:typerecherche )");
    query.bindValue(0, id_client_string);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
    query.bindValue(3, adresse);
    query.bindValue(4, typerecherche);
  return   query.exec();

}
bool Client::supprimer(int id_client )
{
    QSqlQuery query;
    QString res=QString::number(id_client);
    query.prepare("Delete from client where id_client= :id_client");
    query.bindValue(0,id_client);
    return query.exec();
}
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM client");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("typerecherche"));



    return model;


}
/*bool Client::modifier()
{
    QSqlQuery query;

       QString res= QString::number(id_client);
       query.prepare("UPDATE client SET id_client=:res,nom=:nom,prenom=:prenom,salaire=:salaire,adresse=:adresse WHERE id_client=:id_client");
       query.bindValue(":id", res);
       query.bindValue(":nom", nom);
       query.bindValue(":prenom", prenom);
       query.bindValue(":adresse", adresse);
       query.bindValue(":typerecherche", typerecherche);

          return    query.exec();

}*/
