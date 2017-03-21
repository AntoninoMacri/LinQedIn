#ifndef UTENTEPAY_H
#define UTENTEPAY_H
#include <Model/Utente/utente.h>

class UtentePay: public Utente
{
public:
    UtentePay(const QString& ="");
    UtentePay(const QString& , const QString&, const QString&, const QString& ="");
    UtentePay(const Utente&,const QString& ="");

    QString getCredit_Card() const;

    void setCredit_Card(const QString&);

    virtual double getAbbonamento() const =0;
    virtual void setAbbonamento(const double) =0;

private:
    QString credit_card;
};

#endif // UTENTEPAY_H
