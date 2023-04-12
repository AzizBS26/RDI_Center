#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include"employe.h"
#include"authentification.h"

#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QString nom = ui->le_username->text();
    QString nom=ui->le_idlog->text();
       QString motdepasse = ui->le_password->text();

      Authentification auth;
       if (auth.authentifier(nom, motdepasse))
       {
           QMessageBox::information(this, "Connexion réussie", "Vous êtes connecté.");
           Dialog *mw = new Dialog();
                   mw->show();
                   this->close();
       } else {
           QMessageBox::warning(this, "Erreur de connexion", "Nom d'utilisateur ou mot de passe incorrect.");
       }
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
