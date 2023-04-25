#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include"employe.h"
#include"authentification.h"
//#include<QTimer>
#include<QMessageBox>
#include <QDialog>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->le_password->installEventFilter(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
   // connect(this, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(handleKeyPress(QKeyEvent*)));
   // connect(this, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(handleKeyPress(QKeyEvent*)));
    //QObject::connect(this, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(handleKeyPress(QKeyEvent*)));
  /* QObject::connect(ui->le_password, &QLineEdit::returnPressed, this, &MainWindow::lineEditReturnPressed);
    QObject::connect(this, &MainWindow::keyPressed, this, &MainWindow::handleKeyPress);*/
    //QObject::connect(ui->le_password, &QLineEdit::returnPressed, this, &MainWindow::lineEditReturnPressed);
    //QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_console()));

}

MainWindow::~MainWindow()
{
    delete ui;
    A.close_arduino();
}

void MainWindow::update_label()
{
data=A.read_from_arduino();

 ui->le_password->setText(ui->le_password->text()+data);
}
/*void MainWindow::keyPressed(QKeyEvent *event)
{
    // Récupérer le code de la touche appuyée
    int key = event->key();

    // Vérifier si la touche est la touche "Entrée"
    if (key == Qt::Key_Return || key == Qt::Key_Enter)
    {
        // Récupérer le texte du QLineEdit
        QString text = ui->le_password->text();

        // Utiliser le texte pour effectuer une action, par exemple l'afficher dans la console
        qDebug() << "Texte saisi : " << text;

        // Effacer le contenu du QLineEdit
        ui->le_password->clear();
    }
}*/


void MainWindow::on_pushButton_clicked()
{
    //QString nom = ui->le_username->text();
    // QByteArray data = A.read_from_arduino();
     QByteArray data = A.read_keypad();
    QString nom=ui->le_idlog->text();
       QString motdepasse = ui->le_password->text();

       // Ajouter ces deux lignes pour activer la saisie de texte dans un QLineEdit nommé "lineEdit"
       //ui->le_password->setFocus();
       //ui->le_password->clear();

      Authentification auth;
       //if ((auth.authentifier(nom, motdepasse)) && (data == motdepasse.toUtf8()) )
            if (auth.authentifier(nom, motdepasse) )
       {
           QMessageBox::information(this, "Connexion réussie", "Vous êtes connecté.");
           Dialog *mw = new Dialog();
                   mw->show();
                   this->close();

                   //QString nom=ui->le_idlog->text();
                   /* QSqlQuery test ;
                      test.prepare("SELECT nom  FROM Clients WHERE cin= :cin");
                      test.bindValue(":cin",cin);*/
                    //QString query = ("SELECT nom FROM Clients WHERE cin= :cin");
                    QString user;
                    QSqlQuery query;
                    query.prepare("SELECT nom FROM utilisateur WHERE motdepasse= :motdepasse"); // prépare la requête SQL
                    query.bindValue(":motdepasse", motdepasse); // lie la valeur de l'ID du client
                    if (query.exec() && query.next()) { // exécute la requête et vérifie s'il y a une ligne de résultats
                        user = query.value(0).toString(); // récupère la valeur de la première colonne (nom) et la convertit en QString
                      }
                A.write_to_arduino("0");
              //  QString j=ui->recherche2->text();
                A.writeString(user);
       }
            else
            {
           QMessageBox::warning(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrect.");
            A.write_to_arduino("1");
       }
      /*if (data == motdepasse.toUtf8()) {
              qDebug() << "Mot de passe correct !";
          } else {
              qDebug() << "Mot de passe incorrect !";
          }*/
}

void MainWindow::on_pb_mdpoublie_clicked()
{
        QString idlogin = ui->le_idlog->text();
         //QString id_string = QString::number(idlogin);

            Utilisateur utilisateur;

        if (idlogin.isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer votre nom d'utilisateur.");
            return;
        }

        //QString id_string = QString::number(utilisateur.getidemploye());
        QString password = utilisateur.getMotDePasse(idlogin);


          if (!password.isEmpty()) {
              QMessageBox::information(this, tr("Mot de passe oublié"), tr("Votre mot de passe est : %1").arg(password));
          } else {
              QMessageBox::warning(this, tr("Mot de passe oublié"), tr("Nom d'utilisateur incorrect"));
          }

}
/*void MainWindow::update_console() {
    QByteArray data = A.getserial()->readAll();
    qDebug() << data;
}
*/



