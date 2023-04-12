#include "authentification.h"

#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
Authentification::Authentification()
{

}

bool Authentification::verifierIdentifiants(Utilisateur utilisateur)
{
    //if (employe.getidemploye() == idemploye && employe.getmotdepasse() == motdepasse)
    if(utilisateur.getNom() == nom && utilisateur.getMotDePasse() == motdepasse)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Authentification::authentifier(QString nom, QString motdepasse) {
    QSqlQuery query;
    //query.prepare("SELECT nom, motdepasse FROM utilisateur WHERE nom = :nom AND motdepasse = :motdepasse");
    //query.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE idemploye = :idemploye AND motdepasse = :motdepasse");
    query.prepare("SELECT COUNT(*) FROM utilisateur WHERE nom = :nom AND motdepasse = :motdepasse");
    query.bindValue(":nom", nom);
    query.bindValue(":motdepasse", motdepasse);
    if (query.exec() && query.next()) {
       // return true;
        int count = query.value(0).toInt();

                return count > 0;
    }
    return false;
}

