#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(const QString& cogn, const QString& n,
                               const QString& usr, const QString& cc):UtentePay(cogn,n,usr,cc){}

UtenteBusiness::UtenteBusiness(const Utente& u, const QString& cc): UtentePay(u,cc){}

double UtenteBusiness::rata=35;

double UtenteBusiness::getAbbonamento() const{ return rata;}


void UtenteBusiness::setAbbonamento(const double r){ rata=r; }

Utente* UtenteBusiness::clone() const{ return new UtenteBusiness(*this); }

QString UtenteBusiness::typeUtente() const{ return "Business"; }


bool UtenteBusiness::ricerca(const SmartUtente& sm, const QString& s) const
{
    if(
       sm->getUsername().contains(s, Qt::CaseInsensitive) ||
       sm->getCognome().contains(s, Qt::CaseInsensitive) ||
       sm->getNome().contains(s, Qt::CaseInsensitive) ||
       sm->getCompetente().contains(s) ||
       sm->getPoliglotta().contains(s) ||
       sm->getAbitazione().contains(s) ||
       sm->getOrigine().contains(s)
      )
            return true;
    return false;
}

void UtenteBusiness::writeTipo(QXmlStreamWriter& xmlWriter) const
{
    xmlWriter.writeTextElement("tipo","Business");
    xmlWriter.writeTextElement("credit_card", getCredit_Card());
}
