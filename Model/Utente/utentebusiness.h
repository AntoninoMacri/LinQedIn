#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H
#include <Model/Utente/utentepay.h>

class UtenteBusiness:virtual public UtentePay
{
public:
    UtenteBusiness(const QString& ="", const QString& ="", const QString& ="",const QString& ="");
    UtenteBusiness(const Utente&,const QString& ="");

    //Virtual
    bool ricerca(const SmartUtente&, const QString&) const;
    double getAbbonamento() const;
    void setAbbonamento(const double);
    QString typeUtente() const;
    Utente* clone() const;

    void writeTipo(QXmlStreamWriter&) const;
private:
    static double rata;
};

#endif // UTENTEBUSINESS_H
