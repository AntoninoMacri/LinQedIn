#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H
#include <Model/Utente/utentegratis.h>

class UtenteBasic: public UtenteGratis
{
public:
    UtenteBasic(const QString& ="", const QString& ="", const QString& ="");
    UtenteBasic(const Utente&);

    QString typeUtente() const;
    bool ricerca(const SmartUtente&, const QString&) const;
    Utente* clone() const;

    void writeTipo(QXmlStreamWriter&) const;

};

#endif // UTENTEBASIC_H
