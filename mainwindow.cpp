#include <QMessageBox>
#include<QSqlQuery>
#include <QDebug>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabclient->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{   int id_client=ui->id_client->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse=ui->adresse->text();
    QString typerecherche=ui->typerecherche->text();

    Client C(id_client,nom,prenom,adresse,typerecherche);

   bool test=C.ajouter();
            if(test)
    {
            QMessageBox::information(0,QObject::tr("OK"),
                               QObject::tr("Ajout effecuté \n"
                                           "Click Cancel to exist ."), QMessageBox::Cancel);
            }
            else
                QMessageBox::critical(0,QObject::tr(" not OK"),
                                   QObject::tr("Ajout non effecuté \n"
                                               "Click Cancel to exist ."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1 ; C1.setid_client(ui->id_clientsupp->text().toInt());
    bool test=C1.supprimer(C1.getid_client());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression avec succee.");}
    else
        msgBox.setText("echec de suppression .");

msgBox.exec();
}

/*void MainWindow::on_pb_modifier_clicked()
{
    int id_client=ui->id_client->text().toInt();

    //int id_client=ui->id_client->text().toInt();
       QString nom=ui->nom->text();
       QString prenom=ui->prenom->text();
       QString adresse=ui->adresse->text();
       QString typerecherche=ui->typerecherche->text();
   QString id_string=QString::number(id_client);



       QSqlQuery quer;
           quer.prepare("update client set id_client='"+id_string+"', nom='"+nom+"',prenom='"+prenom+"',adresse='"+adresse+"',typerecherche='"+typerecherche+"' WHERE id_client='"+id_client+"'");
           if(quer.exec())
           {
              //ui->->setModel(C.afficher());

               QMessageBox::information(nullptr,QObject::tr("OK"), QObject::tr("modification effectué \n""Click Cancel to exit."),QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr,QObject::tr("not OK"),  QObject::tr("modification non effectué \n"  "Click Cancel to exit."),QMessageBox::Cancel);
}*/
