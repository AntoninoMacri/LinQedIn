#ifndef RESIDENZA_H
#define RESIDENZA_H
#include<QXmlStreamReader>
#include "luogo.h"

class Residenza:public Luogo
{
public:
    Residenza(const QString& ="", const QString& ="",const QString& ="");

    QString getIndirizzo() const;
    Luogo getLuogo() const;
    void setIndirizzo(const QString& ="");
    void setResidenza(const QString& ="",const QString& ="",const QString& ="");

    bool contains(const QString&);

    static Residenza readResidenza(QXmlStreamReader& );

private:
    QString indirizzo;
};

#endif // RESIDENZA_H
