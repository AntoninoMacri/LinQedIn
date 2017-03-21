#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H
#include <Model/Utente/utentepay.h>

class UtenteExecutive:virtual public UtentePay
{
public:
    UtenteExecutive(const QString& ="", const QString& ="", const QString& ="",const QString& ="");
    UtenteExecutive(const Utente&,const QString& ="");

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

#endif // UTENTEEXECUTIVE_H
