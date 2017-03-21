#include "utentegratis.h"

UtenteGratis::UtenteGratis(const QString& cogn, const QString& n, const QString& usr):Utente(cogn,n,usr){}

UtenteGratis::UtenteGratis(const Utente& u): Utente(u){}
