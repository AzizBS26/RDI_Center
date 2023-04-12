#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQueryModel>
#include<QItemDelegate>
#include<QPushButton>
#include<QTableWidget>
#include <QSqlRecord>
#include <QPainter>
#include <QFileDialog>
//#include <QDialog>
//#include<QRandomGenerator>
/*namespace Ui {
class Employe;
}
*/
class Employe //: public QDialog
{
   // Q_OBJECT

public:
    //explicit Employe(QWidget *parent = nullptr);
    // ~Employe();

    Employe();
    Employe(int,QString,QString,QString,QString,QString,QString,int );

    int getidemploye();
    QString getnom();
    QString getprenom();
    QString getmail();
    QString getadresse();
    QString getnum();
    QString getdiplome();
     int getsalaire();
    //QString getmotdepasse();


    void setidemploye(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setadresse(QString);
    void setnum(QString);
    void setdiplome(QString);
    void setsalaire(int);
   // void setmotdepasse(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,QString,int);

     QSqlQueryModel* rechercheEtTriDynamique(QString recherche);
     QSqlQueryModel * TriParId();
     QSqlQueryModel * TriParNom();
     QSqlQueryModel * TriParDiplome();


     QSqlQueryModel* getTopPrefixesTelephone();

     bool fonctionPdf();

     // QString getMotDePasse(int idemploye);

      /*QString getNomComplet() const;
      QString generateRandomResponse();*/


/*private slots:
    void on_pb_ajouter_clicked();*/

private:
    //Ui::Employe *ui;
    int idemploye, salaire ;
    QString nom , prenom , mail , adresse,numtelephone , diplomeacquis , motdepasse;
    //long  numtelephone;
};

#endif // EMPLOYE_H
