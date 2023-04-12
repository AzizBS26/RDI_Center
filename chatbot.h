#ifndef CHATBOT_H
#define CHATBOT_H


#include <QObject>
#include <QString>

class Chatbot : public QObject
{
    Q_OBJECT

public:
    explicit Chatbot(QObject *parent = nullptr);

    QString handleMessage(const QString& message);

private:
    // Ajouter ici les données et méthodes nécessaires pour le chatbot
};
#endif // CHATBOT_H
