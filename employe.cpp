#include "employe.h"
#include "ui_employe.h"
//#include <QMainWindow>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QPushButton>
#include<QTableWidget>
#include <QPrinter>
//#include<QMessageBox>
//#include<QIntValidator>
#include <QTime>

/*Employe::Employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employe)
{
    ui->setupUi(this);
}*/

/*Employe::~Employe()
{
    delete ui;
}*/

Employe::Employe()
{
    idemploye=0;
    nom=" ";
    prenom=" ";
    mail=" ";
    adresse=" ";
    numtelephone="";
    diplomeacquis=" ";
    salaire=0;
    //motdepasse="";

}

Employe::Employe(int idemploye,QString nom,QString prenom ,QString mail,QString adresse,QString numtelephone,QString diplomeacquis , int salaire)
{
    this->idemploye=idemploye;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->adresse=adresse;
    this->numtelephone=numtelephone;
    this->diplomeacquis=diplomeacquis;
    this->salaire=salaire;
    //this->motdepasse=motdepasse;

}

int Employe::getidemploye()
{
    return idemploye;
}
int Employe::getsalaire()
{
    return salaire;
}
QString Employe::getnom()
{
    return nom;
}
QString Employe::getprenom()
{
    return prenom;
}
QString Employe::getmail()
{
    return  mail;
}
QString Employe::getadresse()
{
    return adresse;
}
QString Employe::getnum()
{
    return numtelephone;
}
QString Employe::getdiplome()
{
    return diplomeacquis;
}
/*QString Employe::getmotdepasse()
{
    return motdepasse;
}*/
void Employe::setidemploye(int idemploye)
{
    this->idemploye= idemploye;
}
void Employe::setsalaire(int salaire)
{
    this->salaire= salaire;
}
void Employe::setnom(QString nom)
{
    this->nom=nom;
}
void Employe::setprenom(QString prenom)
{
   this->prenom=prenom;
}

void Employe::setmail(QString mail)
{
    this->mail=mail;
}
void Employe::setadresse(QString adresse)
{
   this->adresse=adresse;
}
void Employe::setnum(QString numtelephone)
{
    this->numtelephone= numtelephone;
}
void Employe::setdiplome(QString diplomeacquis)
{
   this->diplomeacquis=diplomeacquis;
}
/*void Employe::setmotdepasse(QString motdepasse)
{
   this->motdepasse=motdepasse;
}*/
bool Employe::ajouter()
{

    QSqlQuery query;
    QString id_string = QString::number(idemploye);
    //QString num_string = QString::number(numtelephone);

          query.prepare("INSERT INTO EMPLOYES (idemploye, nom, prenom, mail, adresse, numtelephone, diplomeacquis, salaire) "
                        "VALUES (:idemploye, :nom, :prenom, :mail, :adresse, :numtelephone, :diplomeacquis , :salaire)");
          query.bindValue(":idemploye", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":mail", mail);
          query.bindValue(":adresse", adresse);
          query.bindValue(":numtelephone", numtelephone);
          query.bindValue(":diplomeacquis", diplomeacquis);
          query.bindValue(":salaire", salaire);
          //query.bindValue(":motdepasse", motdepasse);
          return  query.exec();
}

/*void Employe::on_pb_ajouter_clicked()
{
    int idemploye=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    int numtelephone=ui->le_num->text().toInt();
    QString diplomeacquis=ui->le_diplome->text();
    Employe E(idemploye,nom,prenom,mail,adresse,numtelephone,diplomeacquis);

    bool test=E.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr , QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n ""Click Cancel to exit."), QMessageBox::Cancel);
    //ui->tab_etudiant->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n" " Click Cancel to exit."), QMessageBox::Cancel);

}
*/

QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYES ORDER BY idemploye ASC ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Diplome"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("salaire"));


    return model;
}

bool Employe::supprimer(int idemploye)
{
    QSqlQuery query;
     QString id_string = QString::number(idemploye);
          query.prepare(" Delete from EMPLOYES where idemploye=:idemploye ");
          query.bindValue(":idemploye", id_string);

          return  query.exec();
}
bool Employe::modifier(int idemploye,QString nom,QString prenom ,QString mail,QString adresse,QString numtelephone,QString diplomeacquis , int salaire )
{
    //QVariant myVariant = QVariant::fromValue<long>(numtelephone);
    QSqlQuery query;
     //QString id_string = QString::number(id);
     query.prepare("update EMPLOYES SET nom= :nom,prenom= :prenom,mail= :mail,adresse= :adresse,numtelephone= :numtelephone,diplomeacquis= :diplomeacquis , salaire= :salaire where idemploye= :idemploye");
      //query.bindValue(":id", this->id);
     query.bindValue(":idemploye", idemploye);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":mail", mail);
     query.bindValue(":adresse", adresse);
     query.bindValue(":numtelephone", numtelephone);
     query.bindValue(":diplomeacquis", diplomeacquis);
     query.bindValue(":salaire", salaire);
      //query.bindValue(":motdepasse", motdepasse);

     return query.exec();
}

QSqlQueryModel* Employe::rechercheEtTriDynamique(QString recherche)//, QString tri)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYES WHERE idemploye LIKE '%" + recherche + "%' OR nom LIKE '%" + recherche + "%' OR prenom LIKE '%" + recherche + "%' OR mail LIKE '%" + recherche + "%' OR adresse LIKE '%" + recherche + "%' OR numtelephone LIKE '%" + recherche + "%' OR diplomeacquis LIKE '%" + recherche + "%'  ORDER BY idemploye ASC");
    return model;
}
QSqlQueryModel * Employe::TriParId()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYES ORDER BY idemploye DESC");
        return model;
}
QSqlQueryModel * Employe::TriParNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYES ORDER BY nom DESC");
        return model;
}
QSqlQueryModel * Employe::TriParDiplome()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYES ORDER BY diplomeacquis DESC");
        return model;
}

bool Employe::fonctionPdf()
{
       QSqlQuery query("SELECT * FROM EMPLOYES ORDER BY idemploye ASC");
       QStringList headers;
       QList<QStringList> rows;
       QSqlRecord record = query.record();
       for (int i = 0; i < record.count(); i++) {
           headers << record.fieldName(i);
       }
       while (query.next()) {
           QStringList row;
           for (int i = 0; i < record.count(); i++) {
               row << query.value(i).toString();
           }
           rows << row;
       }
         QPrinter printer(QPrinter::HighResolution);

         printer.setPageSize(QPageSize(QPageSize::A4));
         //printer.setOrientation(QPageLayout::Portrait);
         printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);
         printer.setColorMode(QPrinter::Color);

         QString exportFilename = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "*.pdf");
         if (exportFilename.isEmpty()) {
             return 0;
         }


}

QSqlQueryModel* Employe::getTopPrefixesTelephone()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT COUNT(idemploye) AS total, SUBSTR(numtelephone, 1, 2) AS prefixe FROM EMPLOYES GROUP BY SUBSTR(numtelephone, 1, 2) ORDER BY total DESC  ");
    return model;
}

/*QString Employe::getMotDePasse(int idemploye) {
    QSqlQuery query;
     QString id_string = QString::number(idemploye);
    query.prepare("SELECT motdepasse FROM EMPLOYES WHERE idemploye = :idemploye");
    query.bindValue(":idemploye", id_string);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error getting password for user" << idemploye;
        return "";
    }
    return query.value(0).toString();
}*/

/*QString Employe::getNomComplet() const {
    return nom + " " + prenom;
}
QString Employe::generateRandomResponse()
{
    srand(QDateTime::currentDateTime().toTime_t() + idemploye);

       QStringList reponses;
       reponses << "Je ne sais pas, pouvez-vous reformuler votre question s'il vous plaît ?";
       reponses << "Je suis désolé, je ne suis pas en mesure de répondre à cette question.";
       reponses << "Je vais devoir vérifier cela, je vous reviendrai dès que possible.";
       reponses << "C'est une excellente question, laissez-moi chercher cela pour vous.";

       int index = qrand() % reponses.size();
       return reponses.at(index);
}
*/
