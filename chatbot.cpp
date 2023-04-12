#include "chatbot.h"

Chatbot::Chatbot(QObject *parent) : QObject(parent)
{
    // Initialiser ici les données nécessaires pour le chatbot
}

QString Chatbot::handleMessage(const QString& message)
{
    // Implémenter ici la logique pour gérer les messages et renvoyer une réponse
    return "Bonjour, comment puis-je vous aider ?";
}
