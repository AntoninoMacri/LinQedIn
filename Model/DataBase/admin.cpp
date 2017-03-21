#include "admin.h"

Admin::Admin(DataBase* db)
{
    p_db=db;
}

//GET
SmartChangeType Admin::getUtente(const QString& u) const{ return *(p_db->getSmartChangeType(u));}

SmartChangeType* Admin::getSmartChangeType(const QString& u) const{ return p_db->getSmartChangeType(u);}

Utente* Admin::getPointerUtente(const QString& u) const{ return p_db->getPointerUtente(u); }


//REMOVE
void Admin::removeUtente(const QString &u){ p_db->removeUtente(u); }

void Admin::removeAllReti(const QString& u){ p_db->removeAllReti(u); }

void Admin::removeAllReti(const SmartChangeType& sct){ p_db->removeAllReti(sct); }


//INSERT
void Admin::createUtente(const QString& cogn, const QString& n,
                         const QString& u,const QString& cc,const QString& tp)
{
    int tipo; //i valori prima di 100 possono riguardare eventuali livelli ulteriori di UtenteGratis ed UtentePay
    if(tp.contains("Basic", Qt::CaseInsensitive)) tipo=101; //100 UtenteGratis
    if(tp.contains("Business", Qt::CaseInsensitive)) tipo=201;//200 UtentePay
    if(tp.contains("Executive", Qt::CaseInsensitive)) tipo=202;
    Utente* ut;
    switch(tipo)
    {
    case 101:
        {
         ut=new UtenteBasic(cogn,n,u);
        };
        break;
    case 201:
        {
         ut=new UtenteBusiness(cogn,n,u,cc);
        };
        break;
    case 202:
        {
         ut=new UtenteExecutive(cogn,n,u,cc);
        };
        break;
    }
    SmartChangeType sct(ut);
    p_db->insertUtente(sct);
}

void Admin::insertUtente(const SmartChangeType& sct){ p_db->insertUtente(sct); }

//SET UTENTE
bool Admin::utenteChangeType(const QString& u,const QString& tp, const QString& cc)
{
    return p_db->utenteChangeType(u,tp,cc);
}


bool Admin::utenteChangeType(SmartChangeType& sct,const QString& tp, const QString& cc)
{
    return p_db->utenteChangeType(sct,tp,cc);
}


//CONTAINS
bool Admin::containsUtente(const QString& u) const{ return p_db->containsUtente(u); }

bool Admin::isEmpty() const{ return p_db->isEmpty(); }

bool Admin::exists(const QString& u) const{ return p_db->exists(u); }

QList<const SmartChangeType*> Admin::search(const QString& s) const
{
    QList<const SmartChangeType*> found;
    SmartChangeType temp(new UtenteBasic());
    for(DataBase::db_const_iterator it=p_db->begin(); it!=p_db->end(); ++it)
        if(temp->ricerca(*it.value(),s))
            found.push_back(it.value());
    return found;
}

//FILE::SAVE
void Admin::save(){ p_db->save(); }

//ITERATOR
DataBase::db_iterator Admin::begin(){ return p_db->begin(); }

DataBase::db_iterator Admin::end(){
    return  p_db->end();
}

DataBase::db_const_iterator Admin::begin() const{
    return p_db->begin();
}

DataBase::db_const_iterator Admin::end() const{
    return p_db->end();
}
