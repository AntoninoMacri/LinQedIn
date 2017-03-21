#include "utentebasic.h"

UtenteBasic::UtenteBasic(const QString& cogn, const QString& n, const QString& usr):UtenteGratis(cogn,n,usr){}

UtenteBasic::UtenteBasic(const Utente& u): UtenteGratis(u){}

QString UtenteBasic::typeUtente() const{ return "Basic"; }

bool UtenteBasic::ricerca(const SmartUtente& sm, const QString& s) const
{
    if(sm->getUsername().contains(s, Qt::CaseInsensitive) ||
       sm->getCognome().contains(s, Qt::CaseInsensitive) ||
       sm->getNome().contains(s, Qt::CaseInsensitive) )
            return true;
    return false;
}

Utente* UtenteBasic::clone() const{ return new UtenteBasic(*this);}

void UtenteBasic::writeTipo(QXmlStreamWriter& xmlWriter) const
{
    xmlWriter.writeTextElement("tipo","Basic");
}
