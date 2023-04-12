#ifndef DUMESSANGERSOCKET_H
#define DUMESSANGERSOCKET_H


#include<QTcpSocket>
namespace DuarteCorporation {
class DuMessangerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DuMessangerSocket(qintptr handle, QObject *parent=nullptr);

signals:
    void DuReadyRead(DuMessangerSocket *);
    void DuStateChanged(DuMessangerSocket *,int);
};
} // namespace DuarteCorporation
#endif // DUMESSANGERSOCKET_H

