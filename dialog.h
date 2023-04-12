#ifndef DIALOG_H
#define DIALOG_H
#include "employe.h"
#include"chatbot.h"
#include"widget.h"
#include"dumessangerconnectiondialog.h"
#include <QDialog>
#include<QSqlTableModel>
#include <QtCharts/QChartView>
#include <memory>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_clicked();


    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    //void on_le_mail_textChanged(const QString &arg1);

    //void on_le_mail_textEdited(const QString &arg1);

    void on_tab_employe_clicked(const QModelIndex &index);

    void on_pb_mod_clicked();

    void on_LineChercher_textChanged();

    void on_pb_PDF_clicked();

    void on_pb_statistique_clicked();

   // void on_pb_send_message_clicked();

    void on_BoutonTrier_clicked();

    void on_pb_tri_nom_clicked();

    void on_pb_tri_diplome_clicked();

    void on_pb_chat_clicked();

    void on_pb_send_clicked();

    void on_pb_bind_clicked();

private:
    Ui::Dialog *ui;
    Employe E;
     //Widget *widget;
    static const int ID_COLUMN_INDEX = 0;
    int selected_service =-1;
    QChartView* m_chartView;
    std::unique_ptr<DuartaCorporation::DuMessangerConnectionDialog> mDialog;
    QTcpSocket *mSocket;

    /* Chatbot *m_chatbot;
     Employe *m_employee1;
        Employe *m_employee2;*/
    //void afficherChat(Employe* employeDest);
};

#endif // DIALOG_H
