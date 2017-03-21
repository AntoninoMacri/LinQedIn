#ifndef NATO_H
#define NATO_H
#include<QXmlStreamReader>
#include <QDate>
#include <Model/Persona/luogo.h>

class Nato: virtual public QDate, virtual public Luogo
{
public:
    Nato(int =0,int =0,int =0,const QString& ="",const QString& =""); //se la data non è valida isValid(), ereditata da Qdate, ritorna false.

    void setData(const QDate&);
    void setLuogo(const Luogo&);

    static Nato readNato(QXmlStreamReader&);
};

#endif // NATO_H
