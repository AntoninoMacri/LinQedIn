#include "mansione.h"

mansione::mansione(const QString& t, const QString& d, const QDate& i, const QDate& f, const Luogo& l):
                   titolo(t), descrizione(d), inizio(i), fine(f), localita(l){}

QString mansione::getTitolo() const{ return titolo;}

QString mansione::getDescrizione() const{ return descrizione;}

QString mansione::getRegione() const{ return localita.getRegione();}

QString mansione::getComune() const{ return localita.getComune();}

QDate mansione::dateInizio() const{ return inizio;}

QDate mansione::dateFine() const{ return fine;}

QString mansione::getInizio() const{ return inizio.toString("dd.MM.yyyy");}

QString mansione::getFine() const{ return inizio.toString("dd.MM.yyyy");}



void mansione::setTitolo(const QString & t){ titolo=t; }

void mansione::setDescrizione(const QString & d){ descrizione=d; }

bool mansione::setInizio(const QDate & i){ return inizio.setDate(i.year(),i.month(),i.day()); }



bool mansione::setFine(const QDate & f){ return fine.setDate(f.year(),f.month(),f.day()); }

void mansione::setLuogo(const Luogo& l){ localita.setLuogo(l.getComune(),l.getRegione());}

void mansione::setLuogo(const QString & reg,const QString & com){ localita.setLuogo(reg, com); }

void mansione::setComune(const QString& c){ localita.setComune(c); }

void mansione::setRegione(const QString& r){ localita.setRegione(r); }


int mansione::periodo() const{ return inizio.daysTo(fine); }

bool mansione::equalsInizioFine(const mansione& other) const
{ return (inizio==other.inizio && fine==other.fine); }

bool mansione::equalsPeriodo(const mansione & other) const
{ return inizio.daysTo(fine)==other.inizio.daysTo(other.fine);}



bool mansione::operator ==(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && inizio==other.inizio && fine==other.fine);
}




bool mansione::equals(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()==other.periodo());
}

bool mansione::different(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()!=other.periodo());
}

bool mansione::lower(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()<other.periodo());
}

bool mansione::greater(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()>other.periodo());
}

bool mansione::lowerEquals(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()<=other.periodo());
}

bool mansione::greaterEquals(const mansione& other) const
{
    return (titolo==other.titolo && localita==other.localita
            && periodo()>=other.periodo());
}
