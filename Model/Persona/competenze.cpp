#include "competenze.h"

competenze::competenze(const mansione& value){ titoli.insert(value.getTitolo(),value); }

competenze::competenze(QMap<QString,mansione>& t):titoli(t)
{ /*if(titoli.isEmpty()) titoli.insert(mansione().getTitolo(),mansione());*/} //contiene almeno un elemento vuoto



QList<QString> competenze::getKeys() const{ return titoli.keys(); }

QList<mansione> competenze::getValues() const{ return titoli.values(); }

QMap<QString, mansione> competenze::getMansioni() const{ return titoli; }


bool competenze::contains (const QString& key) const{ return titoli.contains(key); }

int competenze::size() const{ return titoli.size(); }


void competenze::insert(const mansione& value){titoli.insert(value.getTitolo(),value);  if(contains("")) remove("");  }

void competenze::insert(const QMap<QString,mansione>& other){ titoli.unite(other); if(contains("")) remove(""); }


int competenze::remove(const QString& key){ return titoli.remove(key); }

competenze::competenze_iterator competenze::begin(){
    return titoli.begin();
}

competenze::competenze_iterator competenze::end(){
    return titoli.end();
}

competenze::competenze_const_iterator competenze::begin() const{
    return titoli.begin();
}

competenze::competenze_const_iterator competenze::end() const{
    return titoli.end();
}

competenze competenze::readCompetenze(QXmlStreamReader& xmlReader)
{
    competenze t;
    mansione man;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="Competenze"))
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="Mansione")
                man=mansione();
            else if(xmlReader.name()=="titolo")
                man.setTitolo(xmlReader.readElementText());
            else if(xmlReader.name()=="descrizione")
                man.setDescrizione(xmlReader.readElementText());
            else if(xmlReader.name()=="inizio")
                man.setInizio(QDate(QDate::fromString(xmlReader.readElementText(),"dd.MM.yyyy")));
            else if(xmlReader.name()=="fine")
                man.setFine(QDate(QDate::fromString(xmlReader.readElementText(),"dd.MM.yyyy")));
            else if(xmlReader.name()=="comune")
                man.setComune(xmlReader.readElementText());
            else if(xmlReader.name()=="regione")
                man.setRegione(xmlReader.readElementText());
        }
        else if(xmlReader.isEndElement() && xmlReader.name()=="Mansione")
            t.insert(man);
        xmlReader.readNext();
    }
    return t;
}
