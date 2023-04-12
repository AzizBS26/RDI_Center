#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

//#include"employe.h"
 #include"utilisateur.h"
class Authentification
{
public:
    Authentification();
    bool verifierIdentifiants(Utilisateur utilisateur);
    bool authentifier(QString nom, QString motdepasse);
private:
    QString nom;
    QString motdepasse;
};

#endif // AUTHENTIFICATION_H
