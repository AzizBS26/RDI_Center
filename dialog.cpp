#include "dialog.h"
#include "ui_dialog.h"
//#include"employe.h"

#include<QSqlQuery>
/*#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>*/
#include <QLayout>
#include<QMessageBox>
#include<QIntValidator>
#include<QModelIndex>
#include <QSqlRecord>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QtSql>
/*#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>*/
//#include <QChartView>
#include <QtCharts/QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QLineSeries>
#include <memory>
//QT_CHARTS_USE_NAMESPACE
//#include"widget.h"
//#include"dumessangerconnectiondialog.h"
using namespace DuartaCorporation;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
    //m_chatbot(new Chatbot(this))
{
    ui->setupUi(this);


    ui->le_id->setValidator( new QIntValidator(0, 99999, this));
    //ui->le_num->setValidator( new QIntValidator(20000000, 99999999 , this));
    ui->le_num->setValidator(new QRegExpValidator(QRegExp("^\\d{8}$"), this));
   // ui->le_mail->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"), this));
    ui->tab_employe->setModel(E.afficher());

   // ui->Employer->setCurrentWidget(ui->page_statistique);

    /*m_chartView = new QChartView(this);
        m_chartView->setRenderHint(QPainter::Antialiasing);
        ui->Employer->stat->addWidget(m_chartView);*/

  /*  QChart* chart = new QChart();
       m_chartView = new QChartView(chart, this);
       ui->graphicsView->setChart(chart);
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);*/

    mSocket = new QTcpSocket(this);
        connect(mSocket, &QTcpSocket::readyRead,[&](){
            QTextStream T(mSocket);
            auto text = T.readAll();
            ui->textEdit->append(text);
        });



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    int idemploye=ui->le_id->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    QString numtelephone=ui->le_num->text();
    QString diplomeacquis=ui->le_diplome->text();
    //QString motdepasse=ui->le_passeword->text();
    Employe E(idemploye,nom,prenom,mail,adresse,numtelephone,diplomeacquis, salaire);

       QRegularExpression re("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
       QRegularExpressionMatch match = re.match(mail);

       // QString num_string = QString::number(numtelephone);
            QRegularExpression re1("^(2|3|4|5|7)\\d{7}$");
           QRegularExpressionMatch match1 = re1.match(numtelephone);

           QRegularExpression re2("^[A-Za-z\\s]{1,20}$");
           QRegularExpressionMatch match2 = re2.match(nom);
           QRegularExpressionMatch match3 = re2.match(prenom);

       if ((!match.hasMatch()) || (!match1.hasMatch()) || (!match2.hasMatch()) || (!match3.hasMatch())) {
           if(!match.hasMatch())
           QMessageBox::critical(this, "Error", "Invalid email format.");
           else if(!match1.hasMatch())
           QMessageBox::critical(this, "Error", "Invalid numero telephone");
           else if((!match2.hasMatch()))
               QMessageBox::critical(this, "Error", "Invalid Nom format.");
           else if((!match3.hasMatch()))
               QMessageBox::critical(this, "Error", "Invalid Prenom format.");

       }
       else
       {
            bool test=E.ajouter();
            if(test)
            {
                QMessageBox::information(nullptr , QObject::tr("OK"),
                                         QObject::tr("Ajout effectué\n ""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tab_employe->setModel(E.afficher());

                ui->le_id->setText("");
                ui->le_nom->setText("");
                ui->le_prenom->setText("");
                ui->le_mail->setText("");
                ui->le_adresse->setText("");
                ui->le_num->setText("");
                ui->le_diplome->setText("");
                ui->le_salaire->setText("");
               // ui->le_passeword->setText("");



            }
            else
                QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                                      QObject::tr("Ajout non effectué.\n" " Click Cancel to exit."), QMessageBox::Cancel);
           // The email input is valid. Proceed with the confirmation.
       }





}

void Dialog::on_pb_supprimer_clicked()
{
   /* Employe E1;
    E1.setidemploye(ui->le_id_sup->text().toInt());
    bool test=E1.supprimer(E1.getidemploye());
    if(test)
    {
        QMessageBox::information(nullptr , QObject::tr("OK"),
                                 QObject::tr("Suppression effectué\n ""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employe->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectué.\n" " Click Cancel to exit."), QMessageBox::Cancel);-*/

    if(selected_service == -1)
        {
            QMessageBox::warning(this, "Error", "Nothing is selected!");
            return;
        }

        int id = ui->tab_employe->model()->index(selected_service,0).data().toInt();

        if(E.supprimer(id))
        {
            QMessageBox::information(this, "Success", "Service deleted successfull");
            selected_service=-1;
            ui->tab_employe->setModel(E.afficher());
        }
        else
        {
            QMessageBox::warning(this, "Error", "Error while deleting equipmnt");
        }
}

void Dialog::on_pb_modifier_clicked()
{
    int idemploye=ui->le_id->text().toInt();
    int salaire=ui->le_salaire->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    QString adresse=ui->le_adresse->text();
    QString numtelephone=ui->le_num->text();
    QString diplomeacquis=ui->le_diplome->text();
   // QString motdepasse=ui->le_passeword->text();

    QRegularExpression re("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = re.match(mail);

    // QString num_string = QString::number(numtelephone);
         QRegularExpression re1("^(2|3|4|5|7)\\d{7}$");
        QRegularExpressionMatch match1 = re1.match(numtelephone);


        QRegularExpression re2("^[A-Za-z\\s]{1,20}$");
        QRegularExpressionMatch match2 = re2.match(nom);
        QRegularExpressionMatch match3 = re2.match(prenom);

    if ((!match.hasMatch()) || (!match1.hasMatch()) || (!match2.hasMatch()) || (!match3.hasMatch())) {
        if(!match.hasMatch())
        QMessageBox::critical(this, "Error", "Invalid email format.");
        else if(!match1.hasMatch())
        QMessageBox::critical(this, "Error", "Invalid numero telephone");
        else if((!match2.hasMatch()))
            QMessageBox::critical(this, "Error", "Invalid Nom format.");
        else if((!match3.hasMatch()))
            QMessageBox::critical(this, "Error", "Invalid Prenom format.");

    }
    else
    {

    bool test=E.modifier(idemploye,nom, prenom, mail , adresse,numtelephone ,diplomeacquis,salaire);
    if(test)
    {
        QMessageBox::information(nullptr , QObject::tr("OK"),
                                 QObject::tr("Modification effectué\n ""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employe->setModel(E.afficher());

        ui->le_id->setText("");
        ui->le_nom->setText("");
        ui->le_prenom->setText("");
        ui->le_mail->setText("");
        ui->le_adresse->setText("");
        ui->le_num->setText("");
        ui->le_diplome->setText("");
        ui->le_salaire->setText("");
       // ui->le_passeword->setText("");

    }
    else
        QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                              QObject::tr("Modification non effectué.\n" " Click Cancel to exit."), QMessageBox::Cancel);
    }

}

/*void Dialog::on_le_mail_textChanged(const QString &mail)
{
    QRegularExpression re("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        QRegularExpressionMatch match = re.match(mail);
        if (!match.hasMatch()) {
            //ui->errorLabel->setText("Invalid email format.");
            QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                                  QObject::tr("Mail incorrect.\n" " Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            ui->errorLabel->clear();
        }

}
*/
/*void Dialog::on_le_mail_textEdited(const QString &mail)
{
    QRegularExpression re("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        QRegularExpressionMatch match = re.match(mail);
        if (!match.hasMatch()) {
            //ui->errorLabel->setText("Invalid email format.");
            QMessageBox::critical(nullptr , QObject::tr("Not OK"),
                                  QObject::tr("Mail incorrect.\n" " Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            ui->errorLabel->clear();
        }

}
*/

void Dialog::on_tab_employe_clicked(const QModelIndex &index)
{
    selected_service = index.row();
}

void Dialog::on_pb_mod_clicked()
{
    if(selected_service == -1)
       {
           QMessageBox::warning(this, "Error", "Nothing is selected!");
           return;
       }
    // long numtelephone=ui->le_num->text().toInt();
       ui->le_id->setText(ui->tab_employe->model()->index(selected_service,0).data().toString());
       ui->le_nom->setText(ui->tab_employe->model()->index(selected_service,1).data().toString());
       ui->le_prenom->setText(ui->tab_employe->model()->index(selected_service,2).data().toString());
       ui->le_mail->setText(ui->tab_employe->model()->index(selected_service,3).data().toString());
       ui->le_adresse->setText(ui->tab_employe->model()->index(selected_service,4).data().toString());
       ui->le_num->setText(ui->tab_employe->model()->index(selected_service,5).data().toString());
       ui->le_diplome->setText(ui->tab_employe->model()->index(selected_service,6).data().toString());
       ui->le_salaire->setText(ui->tab_employe->model()->index(selected_service,7).data().toString());
        //ui->le_passeword->setText(ui->tab_employe->model()->index(selected_service,7).data().toString());

       //ui->stackedWidget->setCurrentIndex(2);
       ui->Employer->setCurrentWidget(ui->Ajouter);
}

void Dialog::on_LineChercher_textChanged()
{
    QString rech=ui->LineChercher->text();
    //QString tri=ui->recherche->text();
    ui->tab_employe->setModel(E.rechercheEtTriDynamique(rech));
}

void Dialog::on_pb_PDF_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QString(), "*.pdf");
    if (filename.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    QPdfWriter pdfWriter(printer.outputFileName());
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageOrientation(QPageLayout::Portrait);

    QTextDocument document;

    QString html = "<html><body>";
     html += "<div style='text-align:center'>";
     html += "<h1>Liste des EMPLOYES</h1>";
     html += "<br>";
     html += "<table  border='1' width='100%' style='margin: 0 auto; text-align: center;'>";
     html += "<tr>";
     for (int i = 0; i < ui->tab_employe->model()->columnCount(); i++) {
         html += "<th>" + ui->tab_employe->model()->headerData(i, Qt::Horizontal).toString() + "</th>";
     }
     html += "</tr>";
     for (int i = 0; i < ui->tab_employe->model()->rowCount(); i++) {
         html += "<tr>";
         for (int j = 0; j < ui->tab_employe->model()->columnCount(); j++) {
             html += "<td style='text-align:center'>" + ui->tab_employe->model()->data(ui->tab_employe->model()->index(i, j)).toString() + "</td>";
         }
         html += "</tr>";
     }
     html += "</table>";
     html += "</div>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<br>";
     html += "<div style='text-align:center'>";
     html += "<br><img src='C:/Users/lenovo/Desktop/projet c++/ph4.jfif' width='800' height='400' align='bottom' ></br>";
     html += "</div>";
     html += "</body></html>";
     document.setHtml(html);

     document.print(&pdfWriter);

}

void Dialog::on_pb_statistique_clicked()
{
     /* QSqlQueryModel* prefixesModel = E.getTopPrefixesTelephone();


      QBarSet* prefixesSet = new QBarSet("Nombre d'employés");
      QStringList categories;
      for(int i=0; i<prefixesModel->rowCount() && i <3; ++i) {
          QString prefixe = prefixesModel->record(i).value("prefixe").toString();
          int nombreEmployes = prefixesModel->record(i).value("total").toInt();
          *prefixesSet << nombreEmployes;
          categories << prefixe;
           series << QPointF(i+1, nombreEmployes);
      }
     QBarSeries* prefixesSerie = new QBarSeries();
      prefixesSerie->append(prefixesSet);

      // creation du chart
      QChart* prefixesChart = new QChart();
      prefixesChart->addSeries(prefixesSerie);
      prefixesChart->setTitle("Top 3 des préfixes de numéro de téléphone");
      prefixesChart->setAnimationOptions(QChart::SeriesAnimations);

      //configuration de la l'axe x

     QBarCategoryAxis* axis = new QBarCategoryAxis();
      axis->append(categories);
      prefixesChart->createDefaultAxes();
      prefixesChart->setAxisX(axis, prefixesSerie);



    //QVBoxLayout* pageLayout = new QVBoxLayout(ui->page_statistique);
      QVBoxLayout* pageLayout = new QVBoxLayout(ui->graphicsView);

      QChartView* chartView = new QChartView(prefixesChart, ui->page_statistique);

      pageLayout->addWidget(chartView);



     ui->Employer->setCurrentWidget(ui->page_statistique);


       delete prefixesModel;*/
    //ui->stackedWidget_2->setCurrentIndex(1);
              QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("select * from EMPLOYES where salaire < 1000 ");
              float place1=model->rowCount();
              model->setQuery("select * from EMPLOYES where salaire  between 1000 and 3000 ");
              float place2=model->rowCount();
              model->setQuery("select * from EMPLOYES where salaire > 3000 ");
              float place3=model->rowCount();
              float total=place1+place2+place3;

              QString a=QString("Salaire inferieure a 1000dt."+QString::number((place1*100)/total,'f',2)+"%" );
              QString b=QString("Salaire entre 1000dt et 3000dt."+QString::number((place2*100)/total,'f',2)+"%" );
              QString c=QString("Salaire superieure a 3000dt."+QString::number((place3*100)/total,'f',2)+"%" );

              QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
              series->append(a,place1);
              series->append(b,place2);//concatiner 2 chaines
              series->append(c,place3);
              if (place1!=0)
              {QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
                  slice->setLabelVisible();
                  slice->setPen(QPen(Qt::red));}
              if ( place2!=0)
              {
                  // Add label, explode and define brush for 2nd slice
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
              }
              if(place3!=0)
              {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
              }
              // Create the chart widget
              QChart *chart = new QChart();
              // Add data to chart with title and hide legend
              chart->addSeries(series); // widget
              chart->setTitle("Les Salaires Des employes"+ QString::number(total));
              chart->legend()->hide();
              // Used to display the chart
              QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
              chartView->setRenderHint(QPainter::Antialiasing);
              chartView->resize(1000,500);
              chartView->show();


}


/*void Dialog::afficherChat(Employe* employeDest) {
    // Créer une nouvelle fenêtre de chat pour l'employé de destination
    ChatWindow* chatWindow = new ChatWindow(m_employeConnecte, employeDest);

    // Ajouter la fenêtre de chat à la liste des fenêtres ouvertes
    m_fenetresOuvertes.append(chatWindow);

    // Connecter le signal de fermeture de la fenêtre de chat à la fonction de suppression de la liste
    connect(chatWindow, &ChatWindow::closed, this, &Dialog::supprimerFenetreOuverte);

    // Afficher la fenêtre de chat
    chatWindow->show();
}*/
//void Dialog::on_pb_send_message_clicked()
//{
   // Chatbot chatbot;
  /*  QString message = ui->le_message->text();
       QString response = m_chatbot->handleMessage(message);
       ui->te_conversation->append("Vous : " + message);
       ui->te_conversation->append("Bot : " + response);
       ui->le_message->clear();*/
    // Récupérer le texte saisi dans le champ de saisie
     /* QString message = ui->le_message->text();

      // Ajouter le message à la zone de conversation avec le nom de l'employé expéditeur
      ui->te_conversation->append("Vous : " + message);

      // TODO : envoyer le message à l'autre employé via le chatbot
      // Ajouter le message à la zone de conversation avec le nom de l'employé destinataire
         ui->te_conversation->append("Employé 2 : " + message);

         ui->te_conversation->append("Vous êtes connecté avec l'employé 2. Posez une question pour commencer.");

           ui->te_conversation->append("Conversation terminée.");*/

    /*QString message = ui->le_message->text();


       ui->te_conversation->append("Employé 1 : " + message);

       QString response = m_employee2->generateRandomResponse();

       ui->te_conversation->append("Employé 2 : " + response);

       ui->le_message->clear();*/

//}

void Dialog::on_BoutonTrier_clicked()
{
    Employe E;
                ui->tab_employe->setModel(E.TriParId());
}

void Dialog::on_pb_tri_nom_clicked()
{
    Employe E;
                ui->tab_employe->setModel(E.TriParNom());
}

void Dialog::on_pb_tri_diplome_clicked()
{
    Employe E;
                ui->tab_employe->setModel(E.TriParDiplome());
}

void Dialog::on_pb_chat_clicked()
{
   /*DuartaCorporation::Widget *widget = new DuartaCorporation::Widget(this);
   //Widget *widget = new Widget(this);
      widget->show();

      // Close this QDialog
     this->close();*/
    ui->Employer->setCurrentWidget(ui->chat);

}



void Dialog::on_pb_bind_clicked()
{

    //DuartaCorporation::DuMessangerConnectionDialog D(this);
  // DuartaCorporation::DuMessangerConnectionDialog D(this);
    //DuartaCorporation::DuMessangerConnectionDialog* D = new DuartaCorporation::DuMessangerConnectionDialog(this);
    /*std::unique_ptr<DuartaCorporation::DuMessangerConnectionDialog> D(new DuartaCorporation::DuMessangerConnectionDialog(this));

   if(D->exec() == QDialog::Rejected){
         mSocket->connectToHost((*D).hostname(), (*D).port());
         QTcpSocket *mSocket = new QTcpSocket(this);

           connect(mSocket, &QTcpSocket::readyRead,[&](){
               QTextStream T(mSocket);
               auto text = T.readAll();
               ui->textEdit->append(text);
           });


       return;
   }*/
   /*if(D.exec() == QDialog::Rejected)
   {
        mSocket->connectToHost(D.hostname(),D.port());
       return;
   }*/
    /*std::unique_ptr<DuartaCorporation::DuMessangerConnectionDialog> D(new DuartaCorporation::DuMessangerConnectionDialog(this));

    // Vérifie si l'utilisateur a rejeté la boîte de dialogue
    if(D->exec() == QDialog::Rejected){

        mSocket->connectToHost((*D).hostname(), (*D).port());
    }

    // Crée l'objet mSocket en dehors du bloc if
    QTcpSocket *mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });

    return;*/
    /*std::unique_ptr<DuartaCorporation::DuMessangerConnectionDialog> D(new DuartaCorporation::DuMessangerConnectionDialog(this));

       if(D->exec() == QDialog::Rejected){
             mSocket = new QTcpSocket(this);
             mSocket->connectToHost((*D).hostname(), (*D).port());

             connect(mSocket, &QTcpSocket::readyRead,[&](){
                   QTextStream T(mSocket);
                   auto text = T.readAll();
                   ui->textEdit->append(text);
             });

           return;
       }*/
        mDialog = std::unique_ptr<DuartaCorporation::DuMessangerConnectionDialog>(new DuartaCorporation::DuMessangerConnectionDialog(this));
          if(mDialog->exec() == QDialog::Rejected){

              return;
          }
          mSocket->connectToHost(mDialog->hostname(), mDialog->port());

//delete D;


}
void Dialog::on_pb_send_clicked()
{

   // QTcpSocket *mSocket = new QTcpSocket(this);
    QTextStream T(mSocket);
    T<< ui->nickname->text() <<":"<<ui->message->text();
    mSocket->flush();
    ui->message->clear();
}
