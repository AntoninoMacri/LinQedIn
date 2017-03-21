#include "residenza.h"

Residenza::Residenza(const QString& c, const QString& r, const QString& i): Luogo(c,r),indirizzo(i){}

QString Residenza::getIndirizzo() const{ return indirizzo;}

Luogo Residenza::getLuogo() const{ return Luogo(getComune(), getRegione());}

void Residenza::setIndirizzo(const QString &i){ indirizzo=i;}

void Residenza::setResidenza(const QString& c, const QString& r, const QString& i){ setLuogo(c,r); indirizzo=i; }

bool Residenza::contains(const QString& s)
{ return (indirizzo.contains(s, Qt::CaseInsensitive) || Luogo::contains(s)); }

Residenza Residenza::readResidenza(QXmlStreamReader& xmlReader)
{
    QString i="";
    QString c="";
    QString r="";
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="Residenza"))
    {
       if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="comune")
                c=xmlReader.readElementText();
            if(xmlReader.name()=="regione")
                r=xmlReader.readElementText();
            if(xmlReader.name()=="indirizzo")
                i=xmlReader.readElementText();
        }
        xmlReader.readNext();
    }
    return Residenza(c,r,i);
}
