#include "database.h"

QString DataBase::filename="DataBase.xml";

DataBase::DataBase()
{
   this->load();
}

DataBase::~DataBase()
{
    this->save();
    for(db_const_iterator it=db.begin(); it!=db.end(); ++it)
        delete getSmartChangeType((*it.value())->getUsername());
}

//Iterator
DataBase::db_iterator DataBase::begin(){
    return  db.begin();
}

DataBase::db_iterator DataBase::end(){
    return  db.end();
}

DataBase::db_const_iterator DataBase::begin() const{
    return db.begin();
}

DataBase::db_const_iterator DataBase::end() const{
    return db.end();
}


//Get
SmartChangeType* DataBase::getSmartChangeType(const QString& u) const
{
    if(db.find(u)!=end()) return db.find(u).value();
    return 0;
}

Utente* DataBase::getPointerUtente(const QString& u)
{
    SmartChangeType* sct=getSmartChangeType(u);
    return (sct!=0)? sct->getPointer():0;
}

QList<SmartChangeType*> DataBase::getDatabase() const{ return db.values(); }

QList<QString> DataBase::getKeys() const{ return db.keys();}


//Insert & Remove
bool DataBase::insertUtente(const SmartChangeType& sct)
{
    if(sct.getPointer()==0) return false;
    db.insert(sct->getUsername(),new SmartChangeType(sct));
    return true;
}

void DataBase::removeUtente(const QString& u)
{
   // removeAllReti(u); //possibilità di togliere un utente eliminato dal database anche dalla lista della rete
    delete getSmartChangeType(u);
    db.remove(u);
}

void DataBase::removeAllReti(const QString& u)
{
    for(DataBase::db_iterator it=begin(); it!=end(); it++)
        if(it.value()->getPointer()->containsRete(u)) it.value()->getPointer()->removeRete(u);
}

void DataBase::removeAllReti(const SmartChangeType& sct)
{
    for(DataBase::db_iterator it=begin(); it!=end(); it++)
        if(it.value()->getPointer()->containsRete(sct->getUsername())) it.value()->getPointer()->removeRete(sct->getUsername());
}

//Contains
int DataBase::size() const{ return db.size(); }

bool DataBase::isEmpty() const{ return db.isEmpty(); }

bool DataBase::containsUtente(const QString& u) const
{
   bool b=false;
   if(db.find(u)!=end()) b=true;
   return b;
}

bool DataBase::exists(const QString& u) const
{
    bool b=true;
    if(isEmpty()) b=false;
    if(b)
    {
        if(!containsUtente(u)) b=false;
        if(!b)
            for(DataBase::db_const_iterator it=begin(); !b && it!=end(); ++it)
                if((*it.value())->getCognome().contains(u) || (*it.value())->getNome().contains(u))
                    b=true;
    }
    return b;

}

bool DataBase::utenteChangeType(const QString& u,const QString& tp, const QString& cc)
{
    bool b=false;
    SmartChangeType* sct=getSmartChangeType(u);
    if(sct!=0) b=sct->changeType(tp,cc);
    return b;
}


bool DataBase::utenteChangeType(SmartChangeType& sct,const QString& tp, const QString& cc)
{
    return utenteChangeType(sct->getUsername(),tp,cc);
}

void DataBase::save()
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("database");

    db_const_iterator it=db.begin();
    for(; it!=end(); ++it)
    {
        xmlWriter.writeStartElement("SmartChangeType");

        xmlWriter.writeStartElement("Utente");

        xmlWriter.writeTextElement("username", (*it.value())->getUsername());

        (*it.value())->writeTipo(xmlWriter);  //scrittura polimorfica di typeUtente;

        xmlWriter.writeTextElement("cognome",(*it.value())->getCognome());

        xmlWriter.writeTextElement("nome",(*it.value())->getNome());

        //Competenze
        xmlWriter.writeStartElement("Competenze");
        competenze comp=(*it.value())->getCompetente();
        competenze::competenze_const_iterator it_comp=comp.begin();
        for(; it_comp!=comp.end(); ++it_comp)
        {
            xmlWriter.writeStartElement("Mansione");
            xmlWriter.writeTextElement("titolo", (*it_comp).getTitolo());
            xmlWriter.writeTextElement("descrizione", (*it_comp).getDescrizione());
            xmlWriter.writeTextElement("inizio", (*it_comp).getInizio());
            xmlWriter.writeTextElement("fine", (*it_comp).getFine());
            xmlWriter.writeTextElement("comune", (*it_comp).getComune());
            xmlWriter.writeTextElement("regione", (*it_comp).getRegione());
            xmlWriter.writeEndElement(); //Mansione
        }
        xmlWriter.writeEndElement(); //Competenze

        //Lingue
        xmlWriter.writeStartElement("Lingue");
        Lingue lng=(*it.value())->getPoliglotta();
        Lingue::lingua_const_iterator it_lng=lng.begin();
        for(; it_lng!=lng.end(); ++it_lng)
            xmlWriter.writeTextElement("lingua", (*it_lng) );
        xmlWriter.writeEndElement(); //Lingue

        //Residenza
        xmlWriter.writeStartElement("Residenza");
        xmlWriter.writeTextElement("comune",(*it.value())->getAbitazione().getComune());
        xmlWriter.writeTextElement("regione",(*it.value())->getAbitazione().getRegione());
        xmlWriter.writeTextElement("indirizzo",(*it.value())->getAbitazione().getIndirizzo());
        xmlWriter.writeEndElement(); //Residenza

        //Nato
        xmlWriter.writeStartElement("Nato");
        xmlWriter.writeTextElement("gg.mm.aaaa",(*it.value())->getOrigine().toString("dd.MM.yyyy"));
        xmlWriter.writeTextElement("comune",(*it.value())->getOrigine().getComune());
        xmlWriter.writeTextElement("regione",(*it.value())->getOrigine().getRegione());
        xmlWriter.writeEndElement(); //Nato

        //Rete
        xmlWriter.writeStartElement("Rete");
        Rete rt=(*it.value())->getRete();
        Rete::rete_const_iterator it_rt=rt.begin();
        for(; it_rt != rt.end(); ++it_rt)
            xmlWriter.writeTextElement("contatto", (*it_rt) );
        xmlWriter.writeEndElement(); //Rete

        xmlWriter.writeEndElement();//utente
        xmlWriter.writeEndElement();//SmartChangeType
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();  // database
    file.close();
}

void DataBase::load()
{
    //Variabili di appoggio
    QString username="";
    QString tipeUtente="";
    QString credit_card="";
    QString cognome="";
    QString nome="";
    competenze comp;
    Lingue lng;
    Residenza abitazione;
    Nato origine;
    Rete rt;


    QFile file_CLient("DataBase2.xml");
    QFile file_Admin(filename);

    QString name_file;

    QFileInfo file_Info_client(file_CLient);
    QFileInfo file_Info_Admin(file_Admin);
    if(file_Info_client.lastModified()>file_Info_Admin.lastModified())
        name_file=file_Info_client.fileName();
    else
        name_file=file_Info_Admin.fileName();

    QFile file(name_file);

    if (!file.open(QFile::ReadOnly | QFile::Text)){
       //visualizza errore di lettura file su terminale
    }
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())  //legge apertura Tag
        {
            if(xmlReader.name()=="database" || xmlReader.name()=="SmartChangeType" || xmlReader.name()=="utente")
                xmlReader.readNext();
            else if(xmlReader.name()=="username") //leggo la username
                    username=xmlReader.readElementText();
            else if(xmlReader.name()=="tipo")
                    tipeUtente=xmlReader.readElementText();
            else if(xmlReader.name()=="credit_card")
                credit_card=xmlReader.readElementText();
            else if(xmlReader.name()=="cognome")
                cognome=xmlReader.readElementText();
            else if(xmlReader.name()=="nome")
                nome=xmlReader.readElementText();
            else if(xmlReader.name()=="Competenze")
                comp=competenze::readCompetenze(xmlReader);
            else if(xmlReader.name()=="Lingue")
                lng=Lingue::readLingue(xmlReader);
            else if(xmlReader.name()=="Residenza")
                abitazione=Residenza::readResidenza(xmlReader);
            else if(xmlReader.name()=="Nato")
                origine=Nato::readNato(xmlReader);
            else if(xmlReader.name()=="Rete")
                rt=Rete::readRete(xmlReader);
        }
        else
            if(xmlReader.isEndElement() && xmlReader.name()=="SmartChangeType") //leggo </SmartChangeType> //costruisco SmartChangeType
            {
                int tipo; //i valori prima di 100 possono riguardare eventuali livelli ulteriori di UtenteGratis ed UtentePay
                if(tipeUtente.contains("Basic", Qt::CaseInsensitive)) tipo=101; //100 UtenteGratis
                if(tipeUtente.contains("Business", Qt::CaseInsensitive)) tipo=201;//200 UtentePay
                if(tipeUtente.contains("Executive", Qt::CaseInsensitive)) tipo=202;
                Utente* ut;
                switch(tipo)
                {
                case 101:
                    {
                     ut=new UtenteBasic(cognome,nome,username);
                    };
                    break;
                case 201:
                    {
                     ut=new UtenteBusiness(cognome,nome,username,credit_card);
                    };
                    break;
                case 202:
                    {
                     ut=new UtenteExecutive(cognome,nome,username,credit_card);
                    };
                    break;
                }
                ut->setCompetente(comp);
                ut->setPoliglotta(lng);
                ut->setAbitazione(abitazione);
                ut->setOrigine(origine);
                ut->setRete(rt);

                SmartChangeType sct(ut);
                insertUtente(sct);

                username="";
                tipeUtente="";
                credit_card="";
                cognome="";
                nome="";
            }
                xmlReader.readNext();

    }
    file.close();
}

void DataBase::save_const() const
{
    QFile file("DataBase2.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("database");

    db_const_iterator it=db.begin();
    for(; it!=end(); ++it)
    {
        xmlWriter.writeStartElement("SmartChangeType");

        xmlWriter.writeStartElement("Utente");

        xmlWriter.writeTextElement("username", (*it.value())->getUsername());

        (*it.value())->writeTipo(xmlWriter);  //scrittura polimorfica di typeUtente;

        xmlWriter.writeTextElement("cognome",(*it.value())->getCognome());

        xmlWriter.writeTextElement("nome",(*it.value())->getNome());

        //Competenze
        xmlWriter.writeStartElement("Competenze");
        competenze comp=(*it.value())->getCompetente();
        competenze::competenze_const_iterator it_comp=comp.begin();
        for(; it_comp!=comp.end(); ++it_comp)
        {
            xmlWriter.writeStartElement("Mansione");
            xmlWriter.writeTextElement("titolo", (*it_comp).getTitolo());
            xmlWriter.writeTextElement("descrizione", (*it_comp).getDescrizione());
            xmlWriter.writeTextElement("inizio", (*it_comp).getInizio());
            xmlWriter.writeTextElement("fine", (*it_comp).getFine());
            xmlWriter.writeTextElement("comune", (*it_comp).getComune());
            xmlWriter.writeTextElement("regione", (*it_comp).getRegione());
            xmlWriter.writeEndElement(); //Mansione
        }
        xmlWriter.writeEndElement(); //Competenze

        //Lingue
        xmlWriter.writeStartElement("Lingue");
        Lingue lng=(*it.value())->getPoliglotta();
        Lingue::lingua_const_iterator it_lng=lng.begin();
        for(; it_lng!=lng.end(); ++it_lng)
            xmlWriter.writeTextElement("lingua", (*it_lng) );
        xmlWriter.writeEndElement(); //Lingue

        //Residenza
        xmlWriter.writeStartElement("Residenza");
        xmlWriter.writeTextElement("comune",(*it.value())->getAbitazione().getComune());
        xmlWriter.writeTextElement("regione",(*it.value())->getAbitazione().getRegione());
        xmlWriter.writeTextElement("indirizzo",(*it.value())->getAbitazione().getIndirizzo());
        xmlWriter.writeEndElement(); //Residenza

        //Nato
        xmlWriter.writeStartElement("Nato");
        xmlWriter.writeTextElement("gg.mm.aaaa",(*it.value())->getOrigine().toString("dd.MM.yyyy"));
        xmlWriter.writeTextElement("comune",(*it.value())->getOrigine().getComune());
        xmlWriter.writeTextElement("regione",(*it.value())->getOrigine().getRegione());
        xmlWriter.writeEndElement(); //Nato

        //Rete
        xmlWriter.writeStartElement("Rete");
        Rete rt=(*it.value())->getRete();
        Rete::rete_const_iterator it_rt=rt.begin();
        for(; it_rt != rt.end(); ++it_rt)
            xmlWriter.writeTextElement("contatto", (*it_rt) );
        xmlWriter.writeEndElement(); //Rete

        xmlWriter.writeEndElement();//utente
        xmlWriter.writeEndElement();//SmartChangeType
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();  // database
    file.close();
}
