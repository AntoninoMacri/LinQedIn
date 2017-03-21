#include "utente.h"

Utente::Utente(const QString& cogn, const QString& n, const QString& usr): Persona(cogn,n), username(usr){}

Utente::Utente(const QString& cogn, const QString& n, const QString& usr,
               const competenze& comp, const Lingue& p, const Residenza& a,
               const Nato& o, const Rete& rt): Persona(cogn,n,comp,p,a,o),username(usr),contatti(rt){}

Utente::~Utente(){}

QString Utente::getUsername() const{ return username; }

void Utente::setUsername(const QString& usr){ username=usr;}

bool Utente::containsRete(const QString& u) const{ return contatti.contains(u);}

QList<QString> Utente::getContatti() const{ return contatti.getUtenti(); }

Rete Utente::getRete() const{ return contatti; }

void Utente::insertRete(const QString& u){ contatti.insert(u); }

void Utente::removeRete(const QString& u){ contatti.deleteUtente(u);}

void Utente::setRete(const Rete& rt){ contatti=rt; }

bool Utente::reteIsEmpty() const{ return contatti.isEmpty(); }
