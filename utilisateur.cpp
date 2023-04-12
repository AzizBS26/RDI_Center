#include "utilisateur.h"

#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QPushButton>
#include<QTableWidget>
#include <QPrinter>
#include <cstdlib>
#include <ctime>
#include<QTime>

/*Utilisateur::Utilisateur()
{
    nom="";
    motdepasse="";
}*/
/*Utilisateur::Utilisateur(const QString& nomUtilisateur, const QString& motDePasse) :
    nom(nomUtilisateur),
    motdepasse(motDePasse)
{}

QString Utilisateur::getNomUtilisateur() const {
    return nom;
}

QString Utilisateur::getMotDePasse() const {
    return motdepasse;
}*/

/*bool Utilisateur::estValide() const {
    // Vérification de l'authentification à implémenter ici
    // Pour l'exemple, on considère valide tout utilisateur ayant un nom d'utilisateur et un mot de passe non vides
    return !nom.isEmpty() && !motdepasse.isEmpty();
}*/
//bool Utilisateur::authentifierUtilisateur(QString nom, QString motdepasse)
//{
    // Ouvrir la base de données
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chemin/vers/votre/base/de/donnees.sqlite");
    if (!db.open()) {
        qDebug() << "Impossible d'ouvrir la base de données.";
        return false;
    }
    */
    // Effectuer une requête pour récupérer les informations de l'utilisateur
   /* QSqlQuery query;
    query.prepare("SELECT * FROM utilisateur WHERE nom = :nom AND motdepasse = :motdepasse");
    query.bindValue(":nom", nom);
    query.bindValue(":motdepasse", motdepasse);

    // Vérifier si l'utilisateur existe dans la base de données
    if (query.next()) {
        // L'utilisateur a été trouvé, authentification réussie
        QString role = query.value("role").toString();
        qDebug() << "Authentification réussie pour l'utilisateur" << nom << "avec le rôle" << role;
        return true;
    } else {
        // L'utilisateur n'a pas été trouvé, authentification échouée
        qDebug() << "Authentification échouée pour l'utilisateur" << nom;
        return false;
    }
}*/

Utilisateur::Utilisateur()
{

}

Utilisateur::Utilisateur(int idutilisateur, QString nom, QString motdepasse , QString email)
    //: m_id(idutilisateur), m_nom(nom), m_motDePasse(motdepasse)
{
    this->idutilisatuer=idutilisateur;
    this->nom=nom;
    this->motdepasse=motdepasse;
    this->email=email;
}

int Utilisateur::getId() const
{
    return idutilisatuer;
}

QString Utilisateur::getNom() const
{
    return nom;
}

QString Utilisateur::getMotDePasse() const
{
    return motdepasse;
}
QString Utilisateur::getEmail() const
{
    return email;
}
void Utilisateur::setId(int idutilisateur)
{
    this->idutilisatuer=idutilisateur;
}
 void Utilisateur::setNom(QString nom)
 {
     this->nom=nom;
 }

 void Utilisateur::setEmail(QString email)
 {
     this->email=email;
 }

 void Utilisateur::setMotdepasse(QString motdepasse)
 {
     this->motdepasse=motdepasse;
 }

/*bool Utilisateur::verifierNomUtilisateur(QString nomUtilisateur) const
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM utilisateur WHERE nom=:nom");
    query.bindValue(":nom", nomUtilisateur);
    if(query.exec())
    {
        if(query.next())
        {
            return query.value(0).toInt() > 0;
        }
    }
    return false;
}
bool Utilisateur::verifierMotdepasse(QString motdepasse) const
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM utilisateur WHERE motdepasse=:motdepasse");
    query.bindValue(":motdepasse", motdepasse);
    if(query.exec())
    {
        if(query.next())
        {
            return query.value(0).toInt() > 0;
        }
    }
    return false;
}*/

/*QString Utilisateur::recupererMotDePasse(QString email) const
{
    QSqlQuery query;
    query.prepare("SELECT motdepasse FROM utilisateur WHERE email=:email");
    query.bindValue(":email", email);
    if(query.exec())
    {
        if(query.next())
        {
            return query.value(0).toString();
        }
    }
    return "";
}*/
//a prendre
QString Utilisateur::getMotDePasse(QString username) {
    QSqlQuery query;
    query.prepare("SELECT motdepasse FROM utilisateur WHERE nom = :username");
    query.bindValue(":username", username);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error getting password for user" << username;
        return "";
    }
    return query.value(0).toString();
}



/* QString Utilisateur::prendEmail(const QString& username) {
   //  QString email = "";
     QSqlQuery query;
     query.prepare("SELECT email FROM utilisateur WHERE nom = ?");
     query.addBindValue(username);
     if (query.exec() && query.next()) {
         email = query.value(0).toString();
     }
     return email;
 }

 QString Utilisateur::generateNewPassword()
 {
     QString newPassword;
        QString allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

        qsrand(QTime::currentTime().msec()); // initialiser le générateur de nombres aléatoires avec une graine

        for(int i = 0; i < 8; i++)
        {
            int index = qrand() % allowedChars.length();
            QChar nextChar = allowedChars.at(index);
            newPassword.append(nextChar);
        }

        return newPassword;
 }
*/
// bool Utilisateur::updateMotDePasse(QString username, QString new_password)
 //{
     // Ouverture de la base de données
    /* QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("chemin_vers_la_base_de_donnees");

     if (!db.open()) {
         qDebug() << "Erreur de connexion à la base de données";
         return false;
     }*/

     // Requête SQL pour mettre à jour le mot de passe de l'utilisateur
     /*QSqlQuery query;
     query.prepare("UPDATE utilisateur SET motdepasse = :new_password WHERE nom = :username");
     query.bindValue(":new_password", new_password);
     query.bindValue(":username", username);*/

    /* if (!query.exec()) {
         qDebug() << "Erreur lors de la mise à jour du mot de passe de l'utilisateur" << query.lastError().text();
         return false;
     }
*/
     // Fermeture de la base de données
     //db.close();

     //return true;
 //}
