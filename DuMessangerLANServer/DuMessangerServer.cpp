#include "DuMessangerServer.h"
#include"dumessangersocket.h"
#include<QTextStream>
#include<QDebug>
namespace DuarteCorporation {
DuMessangerServer::DuMessangerServer(QObject *parent)
    :QTcpServer(parent)
{

}
bool DuMessangerServer::startServer(quint16 port)
{
   return listen(QHostAddress::Any,port);
}
void DuMessangerServer::incomingConnection(qintptr handle)
{
    qDebug() <<"Employe connected with handle:"<< handle;
  auto socket = new DuMessangerSocket(handle, this);
  mSockets<<socket;

  for (auto i : mSockets ){
      QTextStream T(i);
      T<<"Server: connected:"<< handle;
      i->flush();
  }

  connect(socket, &DuMessangerSocket::DuReadyRead , [&](DuMessangerSocket *S)
  {
      qDebug() <<"DuReadyRead";
     QTextStream T(S);
     auto text = T.readAll();

     for(auto i : mSockets){
         QTextStream K(i);
         K<< text;
         i->flush();
     }
  });

  connect(socket, &DuMessangerSocket::DuStateChanged,
          [&](DuMessangerSocket *S,int ST){
      qDebug() << "DuStateChanged with handle:"
               <<S->socketDescriptor();
      if(ST == QTcpSocket::UnconnectedState){
            qDebug() <<"Unconnected State wich h"
                       "andle:"<< S->socketDescriptor();
          mSockets.removeOne(S);
          for(auto i : mSockets){
              QTextStream K(i);
              K<< "serveur: le Employe"
               <<S->socketDescriptor()
              <<" Deconnected...";
              i->flush();

          }

      }
  });
}
}//namespace DuarteCorporation

