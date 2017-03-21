#ifndef ADMIN_H
#define ADMIN_H
#include <Model/DataBase/database.h>

class Admin
{
public:
    Admin(DataBase* db);
    //~Admin(){ save(); }

    //iteratore
    DataBase::db_iterator begin();
    DataBase::db_iterator end();
    DataBase::db_const_iterator begin() const;
    DataBase::db_const_iterator end() const;

    void removeUtente(const QString&);
    void removeAllReti(const QString& );
    void removeAllReti(const SmartChangeType&);
    void insertUtente(const SmartChangeType&);
    void createUtente(const QString& cogn, const QString& n,const QString& u,const QString& cc ="",const QString& tp="Basic");
    bool utenteChangeType(SmartChangeType &, const QString&, const QString &);
    bool utenteChangeType(const QString&, const QString&, const QString&);

    SmartChangeType getUtente(const QString&) const;
    SmartChangeType* getSmartChangeType(const QString&) const;
    Utente* getPointerUtente(const QString&) const;
    bool containsUtente(const QString&) const;
    bool exists(const QString&) const; //se esiste username,cognome o nome,
    bool isEmpty() const;

    QList<const SmartChangeType*> search(const QString&) const;
    void save();
private:
    DataBase* p_db;
};

#endif // ADMIN_H

