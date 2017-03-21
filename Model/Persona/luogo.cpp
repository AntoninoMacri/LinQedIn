#include "luogo.h"

Luogo::Luogo(const QString& com, const QString& reg): comune(com),regione(reg){}

QString Luogo::getComune() const{ return comune;}

QString Luogo::getRegione() const{ return regione;}

void Luogo::setComune(const QString& com){ comune=com;}

void Luogo::setRegione(const QString &reg){ regione=reg;}

void Luogo::setLuogo(const QString &com, const QString &reg){comune=com; regione=reg;}

bool Luogo::operator ==(const Luogo& other) const
{ return (regione==other.regione && comune==other.comune); }

bool Luogo::contains(const QString& s)
{ return (comune.contains(s,Qt::CaseInsensitive) || regione.contains(s,Qt::CaseInsensitive)); }
