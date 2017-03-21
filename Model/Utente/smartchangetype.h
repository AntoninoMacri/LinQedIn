#ifndef SMARTCHANGETYPE_H
#define SMARTCHANGETYPE_H
#include <Model/Utente/utentebasic.h>
#include <Model/Utente/utentebusiness.h>
#include <Model/Utente/utenteexecutive.h>
#include <Model/Utente/smartutente.h>

class SmartChangeType: public SmartUtente //cambio il tipo di utente dentro SmartUtente
{
public:
    SmartChangeType();
    SmartChangeType(const SmartUtente&);
    SmartChangeType(Utente*);

    bool changeType(const QString&, const QString& ="");
};

#endif // SMARTCHANGETYPE_H
