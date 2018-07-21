#ifndef OPERATIONNODEQO_H
#define OPERATIONNODEQO_H

#include <QObject>
using namespace std;
class OperationNodeQO : public QObject
{
    Q_OBJECT
private:
    QString pp;
public:
    OperationNodeQO(QObject *parent = 0):QObject(parent){}
    OperationNodeQO(QString p, QObject *parent = 0):QObject(parent),pp(p){}
    Q_INVOKABLE QString title();
    Q_INVOKABLE QString getPP();
};

#endif // OPERATIONNODEQO_H
