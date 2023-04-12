#include "widget.h"
#include "ui_widget.h"

#include"dumessangerconnectiondialog.h"
//#include<QTcpSocket>
namespace DuartaCorporation {
/*Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{*/
   //ui->setupUi(this);
   /*DuartaCorporation::Widget myWidget;
   functionThatExpectsQDialog(dynamic_cast<QDialog*>(&myWidget));*/


    /*mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });*/
//}

Widget::~Widget()
{
    delete ui;
}

/*void Widget::functionThatExpectsQDialog(QDialog *dialog) {
    // Do something with the dialog
    dialog->show();
}
void Widget::on_pb_send_clicked()
{
   QTextStream T(mSocket);
   T<< ui->nickname->text() <<":"<<ui->message->text();
   mSocket->flush();
   ui->message->clear();
}

void Widget::on_pb_bind_clicked()
{
     //DuartaCorporation::DuMessangerConnectionDialog D(this);
     DuMessangerConnectionDialog D(this);
    if(D.exec() == QDialog::Rejected){
        return;
    }
    mSocket->connectToHost(D.hostname(),D.port());
}*/
} // end namespace DuartaCorporation

