#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"arduino.h"
#include<QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void update_label();
 // void update_console();
    void on_pb_mdpoublie_clicked();

private:
    Ui::MainWindow *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
