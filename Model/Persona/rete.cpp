#include "rete.h"

Rete::Rete(const QString& a){ utenti.insert(a);}

Rete::Rete(QSet<QString>& a): utenti(a){}

QList<QString> Rete::getUtenti() const{ return utenti.toList();}

void Rete::insert(const QString& a){ if(utenti.contains("")) deleteUtente(""); utenti.insert(a); }

void Rete::insert(const QSet<QString>& a){ if(utenti.contains("")) deleteUtente(""); utenti.unite(a);}

bool Rete::deleteUtente(const QString& a){ return utenti.remove(a);}

bool Rete::contains(const QString& key) const{return utenti.contains(key);}

bool Rete::isEmpty() const{ return utenti.isEmpty(); }

Rete::rete_iterator Rete::begin(){
    return utenti.begin();
}

Rete::rete_iterator Rete::end(){
    return utenti.end();
}

Rete::rete_const_iterator Rete::begin() const{
    return utenti.begin();
}

Rete::rete_const_iterator Rete::end() const{
    return utenti.end();
}

Rete Rete::readRete(QXmlStreamReader& xmlReader)
{
    Rete u;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="Rete"))
    {
        if(xmlReader.isStartElement())
            if(xmlReader.name()=="contatto")
                    u.insert(xmlReader.readElementText());
        xmlReader.readNext();
    }
    return u;
}
