#ifndef DATABASE_H
#define DATABASE_H
#include <Model/Utente/utentebasic.h>
#include <Model/Utente/utentebusiness.h>
#include <Model/Utente/utenteexecutive.h>
#include <Model/Utente/smartchangetype.h>
#include <QString>
#include <QMap>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
 #include <QFileInfo>

class DataBase
{
public:
    typedef QMap<QString, SmartChangeType*>::iterator db_iterator;
    typedef QMap<QString, SmartChangeType*>::const_iterator db_const_iterator;

     DataBase();
    ~DataBase();

    //Iterator
    db_iterator begin();
    db_iterator end();
    db_const_iterator begin() const;
    db_const_iterator end() const;

    //Get
    SmartChangeType* getSmartChangeType(const QString&) const;
    Utente* getPointerUtente(const QString&);
    QList<QString> getKeys() const;
    QList<SmartChangeType*> getDatabase() const; //=getValues() const;

    //Insert & Remove
    bool insertUtente(const SmartChangeType&);
    //bool insertUtente(const QString&,const QString&); //usarname,tipo
    void removeUtente(const QString&);
    void removeAllReti(const QString& ); //rimuove l'utente da tutte le reti
    void removeAllReti(const SmartChangeType&); //rimuove l'utente da tutte le reti

    //Contains
    int size() const;
    bool isEmpty() const;
    bool containsUtente(const QString&) const;
    bool exists(const QString&) const;

    //Change utenteType
    bool utenteChangeType(SmartChangeType &, const QString&, const QString &);
    bool utenteChangeType(const QString&, const QString&, const QString&);

    //File
    void load();
    void save();
    void save_const() const;

private:
    static QString filename;
    QMap<QString,SmartChangeType*> db;
};

#endif // DATABASE_H

