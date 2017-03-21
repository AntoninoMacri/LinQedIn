#include "lingue.h"

Lingue::Lingue(const QString &a){ lingua.insert(a); }

Lingue::Lingue(QSet<QString>& a): lingua(a){ /*if(a.isEmpty()) lingua.insert("");*/ }//Lingue non ha isEmpty() //ha almeno un elemento vuoto

QList<QString> Lingue::getLingue() const{ return lingua.toList();}

void Lingue::insert(const QString &a){ if(lingua.contains("")) deleteLingua(""); lingua.insert(a); }

void Lingue::insert(const QSet<QString>& a){ if(lingua.contains("")) deleteLingua(""); lingua.unite(a); }

bool Lingue::deleteLingua(const QString &a){ return lingua.remove(a); }

bool Lingue::contains(const QString& key){ return lingua.contains(key); }

int Lingue::size() const{ return lingua.size();}

Lingue::lingua_iterator Lingue::begin(){
    return lingua.begin();
}

Lingue::lingua_iterator Lingue::end(){
    return lingua.end();
}

Lingue::lingua_const_iterator Lingue::begin() const{
    return lingua.begin();
}

Lingue::lingua_const_iterator Lingue::end() const{
    return lingua.end();
}


Lingue Lingue::readLingue(QXmlStreamReader& xmlReader)
{
    Lingue lng;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="Lingue"))
    {
        if(xmlReader.isStartElement())
            if(xmlReader.name()=="lingua")
                    lng.insert(xmlReader.readElementText());
        xmlReader.readNext();
    }
    return lng;
}
