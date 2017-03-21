#include "persona.h"

Persona::Persona(const QString& cogn, const QString& n):cognome(cogn), nome(n){}

Persona::Persona
(const QString& cogn, const QString& n, const competenze& comp, const Lingue& p,const Residenza& a,
 const Nato& o):cognome(cogn), nome(n), competente(comp), poliglotta(p), abitazione(a), origine(o){}

QString Persona::getCognome() const{ return cognome;}


QString Persona::getNome() const{ return nome;}

competenze Persona::getCompetente() const{ return competente;}

Lingue Persona::getPoliglotta() const{ return poliglotta; }

Residenza Persona::getAbitazione() const{ return abitazione;}

Nato Persona::getOrigine() const{ return origine; }


void Persona::setPersona(const QString& cogn, const QString& n, const competenze& comp,
                         const Lingue& p, const Residenza& a, const Nato& o)
{
    cognome=cogn;
    nome=n;
    competente=comp;
    poliglotta=p;
    abitazione=a;
    origine=o;
}

void Persona::setCognome(const QString& cogn){ cognome=cogn;}

void Persona::setNome(const QString& n){ nome=n;}

void Persona::setCompetente(const competenze& comp){ competente=comp; }

void Persona::setPoliglotta(const Lingue& p){ poliglotta=p; }

void Persona::setAbitazione(const Residenza& a){ abitazione=a; }

void Persona::setOrigine(const Nato& o){ origine=o;}
