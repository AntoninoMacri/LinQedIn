#include "smartchangetype.h"

SmartChangeType::SmartChangeType():SmartUtente(){}

SmartChangeType::SmartChangeType(Utente* p): SmartUtente(p){}

SmartChangeType::SmartChangeType(const SmartUtente& sm): SmartUtente(sm){}

bool SmartChangeType::changeType(const QString& tp, const QString& cc)
{
    bool flag=false;
    if(getPointer()!=0)
    {
        int tipo; //i valori prima di 100 possono riguardare eventuali livelli ulteriori di UtenteGratis ed UtentePay
        if(tp.contains("Basic", Qt::CaseInsensitive)) tipo=101; //100 UtenteGratis
        if(tp.contains("Business", Qt::CaseInsensitive)) tipo=201;//200 UtentePay
        if(tp.contains("Executive", Qt::CaseInsensitive)) tipo=202;
        switch(tipo)
        {
        case 101:
            {
             UtenteBasic* new_ptr=new UtenteBasic(*getPointer());
             setPointer(new_ptr);
             flag=true;
            };
            break;
        case 201:
            {
             UtenteBusiness* new_ptr=new UtenteBusiness(*getPointer());
             //se e' una promozione dall'UtenteGratis ci aggiungo la creditCard
             if(dynamic_cast<UtenteGratis*>(getPointer())) { new_ptr->setCredit_Card(cc); }
             else
                 if(dynamic_cast<UtentePay*>(getPointer())->getCredit_Card().contains(""))
                    new_ptr->setCredit_Card(cc);
                else
                    new_ptr->setCredit_Card(dynamic_cast<UtentePay*>(getPointer())->getCredit_Card());
             setPointer(new_ptr);
             flag=true;
            };
            break;
        case 202:
            {
             UtenteExecutive* new_ptr=new UtenteExecutive(*getPointer());
             //se e' una promozione dall'UtenteGratis ci aggiungo la creditCard
             if(dynamic_cast<UtenteGratis*>(getPointer())) { new_ptr->setCredit_Card(cc); }
             else
                 if(dynamic_cast<UtentePay*>(getPointer())->getCredit_Card().contains(""))
                    new_ptr->setCredit_Card(cc);
                 else
                     new_ptr->setCredit_Card(dynamic_cast<UtentePay*>(getPointer())->getCredit_Card());
             setPointer(new_ptr);
             flag=true;
            };
            break;
        }
    }
    return flag;
}
