#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(const QString& cogn, const QString& n,
                                 const QString& usr, const QString& cc):UtentePay(cogn,n,usr,cc){}


UtenteExecutive::UtenteExecutive(const Utente& u, const QString& cc): UtentePay(u,cc){}



double UtenteExecutive::rata=60;

double UtenteExecutive::getAbbonamento() const{ return rata;}

void UtenteExecutive::setAbbonamento(const double r){ rata=r;}

Utente* UtenteExecutive::clone() const{ return new UtenteExecutive(*this);}

QString UtenteExecutive::typeUtente() const{ return "Executive";}

bool UtenteExecutive::ricerca(const SmartUtente& sm, const QString& s) const
{
    if(
       sm->getUsername().contains(s, Qt::CaseInsensitive) ||
       sm->getCognome().contains(s, Qt::CaseInsensitive) ||
       sm->getNome().contains(s, Qt::CaseInsensitive) ||
       sm->getCompetente().contains(s) ||
       sm->getPoliglotta().contains(s) ||
       sm->getAbitazione().contains(s) ||
       sm->getOrigine().contains(s) ||
       sm->containsRete(s)
      )
            return true;
    return false;
}

void UtenteExecutive::writeTipo(QXmlStreamWriter& xmlWriter) const
{
    xmlWriter.writeTextElement("tipo","Executive");
    xmlWriter.writeTextElement("credit_card", getCredit_Card());
}
