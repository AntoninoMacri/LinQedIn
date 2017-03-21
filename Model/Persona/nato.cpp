#include "nato.h"

Nato::Nato(int g, int m, int a, const QString& c, const QString& r):QDate(a,m,g),Luogo(c,r){}



void Nato::setData(const QDate& d){ setDate(d.year(),d.month(),d.day());}

void Nato::setLuogo(const Luogo& l){ Luogo::setLuogo(l.getRegione(),l.getComune());}

Nato Nato::readNato(QXmlStreamReader& xmlReader)
{
    QString data_string="00.00.0000";
    QString c="";
    QString r="";
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="Nato"))
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="gg.mm.aaaa") data_string=xmlReader.readElementText();
            if(xmlReader.name()=="comune") c=xmlReader.readElementText();
            if(xmlReader.name()=="regione") r=xmlReader.readElementText();

        }
        xmlReader.readNext();
    }
    QDate date(QDate::fromString(data_string,"dd.MM.yyyy"));
    return (Nato(date.day(),date.month(),date.year(),c,r));
}
