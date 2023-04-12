#ifndef UTILISATEUR_H
#define UTILISATEUR_H


#include <QString>
#include<QSqlQueryModel>
#include<QItemDelegate>
#include<QPushButton>
#include<QTableWidget>
#include <QSqlRecord>
#include <QPainter>
#include <QFileDialog>
/*class Utilisateur {
public:
   // Utilisateur();
    Utilisateur(const QString& nom, const QString& motdepasse);
    QString getNomUtilisateur() const;
    QString getMotDePasse() const;
    bool estValide() const;

    bool authentifierUtilisateur(QString nom, QString motdepasse);
private:
    QString nom;
    QString motdepasse;
};
*/

class Utilisateur
{
public:
    Utilisateur();
    Utilisateur(int idutilisateur, QString nom, QString motdepasse, QString email);

    int getId() const;
    QString getNom() const;
    QString getMotDePasse() const;
     QString getEmail() const;

     void setId(int idutilisateur);
      void setNom(QString nom);
      void setEmail(QString email);
      void setMotdepasse(QString motdepasse);

  //  bool verifierNomUtilisateur(QString nomUtilisateur) const;
    //bool verifierMotdepasse(QString motdepasse) const;
    // a prendre
     QString getMotDePasse(QString username);

   // QString recupererMotDePasse(QString email) const;


     /* QString prendEmail(const QString& username) ;
      QString generateNewPassword();
      bool updateMotDePasse(QString username, QString new_password);*/
private:
    int idutilisatuer;
    QString nom;
    QString motdepasse,email;
};
#endif // UTILISATEUR_H
