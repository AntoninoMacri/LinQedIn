#include "client.h"

Client::Client(const QString& u, DataBase* db_pointer)
{
    p_db=db_pointer;
    p_utente=p_db->getSmartChangeType(u);
}

//GET
QString Client::getTypeUser() const{ return (*p_utente)->typeUtente(); }

SmartChangeType Client::getUtente(const QString& u) const{ return *(p_db->getSmartChangeType(u));}

SmartChangeType Client::getClientUtente() const{ return *p_utente; }

SmartChangeType* Client::getClientUtentePunt() const{ return p_utente;}

//CONTAINS
bool Client::containsUtente(const QString& u) const{ return p_db->containsUtente(u); }

bool Client::exists(const QString& u) const{ return p_db->exists(u); }

QList<const SmartChangeType*> Client::search(const QString& s) const
{
    QList<const SmartChangeType*> found;
    for(DataBase::db_const_iterator it=p_db->begin(); it!=p_db->end(); ++it)
            if(  (*p_utente)->getUsername()!=(*it.value())->getUsername() &&
                 (*p_utente)->ricerca(*it.value(),s)
              )
                found.push_back(it.value());
    return found;

}



//SET
void Client::setClient(const QString& cogn, const QString& n,
                       const competenze& comp, const Lingue& p, const Residenza& a,
                       const Nato& o, const Rete& rt)
{
    (*p_utente)->setCognome(cogn);
    (*p_utente)->setNome(n);
    (*p_utente)->setCompetente(comp);
    (*p_utente)->setPoliglotta(p);
    (*p_utente)->setAbitazione(a);
    (*p_utente)->setOrigine(o);
    (*p_utente)->setRete(rt);
}



//RETE
void Client::addRete(const QString& u) //non posso mettermi amico di me stesso -.-" e controllo se l'utente esiste
{ if( !(getClientUtente()->getUsername().contains(u)) && p_db->containsUtente(u)) {(*p_utente)->insertRete(u);} }

void Client::removeRete(const QString& u){ (*p_utente)->removeRete(u); }

bool Client::reteIsEmpty() const{ return (*p_utente)->reteIsEmpty();  }


//ITERATOR
Rete::rete_iterator Client::beginRete(){ return (*p_utente)->getRete().begin(); }

Rete::rete_iterator Client::endRete(){ return (*p_utente)->getRete().end();}

Rete::rete_const_iterator Client::beginRete() const{ return (*p_utente)->getRete().begin(); }

Rete::rete_const_iterator Client::endRete() const{ return (*p_utente)->getRete().end(); }


void Client::save() const { p_db->save_const(); }
