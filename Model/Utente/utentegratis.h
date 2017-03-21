#ifndef UTENTEGRATIS_H
#define UTENTEGRATIS_H
#include <Model/Utente/utente.h>

class UtenteGratis: public Utente
{
public:
    UtenteGratis (const QString& ="", const QString& ="", const QString& ="");
    UtenteGratis(const Utente&);
};

#endif // UTENTEGRATIS_H
