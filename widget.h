#ifndef WIDGET_H
#define WIDGET_H

//#include <QDialog>
#include <QWidget>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTcpSocket;

namespace DuartaCorporation {
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
     void functionThatExpectsQDialog(QDialog *dialog);
private slots:
    void on_pb_send_clicked();

    void on_pb_bind_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};
}// end namespace DuartaCorporation
#endif // WIDGET_H
