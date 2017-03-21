#ifndef CLIENT_H
#define CLIENT_H
#include <Model/DataBase/database.h>

class Client
{
public:
    Client(const QString&, DataBase*);
    //~Client(){ save(); }

    QList<const SmartChangeType*> search(const QString&) const;
    SmartChangeType getUtente(const QString&) const;
    SmartChangeType getClientUtente() const;
    SmartChangeType* getClientUtentePunt() const;
    bool containsUtente(const QString&) const;
    bool exists(const QString&) const; //se esiste username,cognome o nome,

    QString getTypeUser() const;
    void addRete(const QString& user);
    void removeRete(const QString& user);
    bool reteIsEmpty() const;
    void setClient(const QString&,const QString&,
                   const competenze&, const Lingue&, const Residenza&,
                   const Nato&,const Rete&);

    Rete::rete_iterator beginRete();
    Rete::rete_iterator endRete();
    Rete::rete_const_iterator beginRete() const;
    Rete::rete_const_iterator endRete() const;

    void save() const;

private:
    SmartChangeType* p_utente;
    const DataBase* p_db;
};

#endif // CLIENT_H
