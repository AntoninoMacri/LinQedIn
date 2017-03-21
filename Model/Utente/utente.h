#ifndef UTENTE_H
#define UTENTE_H
#include <Model/Persona/persona.h>
#include <Model/Persona/rete.h>
#include <Model/Utente/smartutente.h>
//#include <ricerca.h>
#include<QXmlStreamWriter>

class SmartUtente;
class Utente:public Persona
{
public:
    Utente(const QString& ="", const QString& ="", const QString& ="");
    Utente(const QString&,const QString&, const QString&,
           const competenze&, const Lingue&, const Residenza&,
           const Nato&,const Rete&);
    virtual ~Utente();

    QString getUsername() const;
    void setUsername(const QString&);

    QList<QString> getContatti() const;
    Rete getRete() const;
    bool containsRete(const QString&) const;
    void insertRete(const QString&);
    void removeRete(const QString&);
    void setRete(const Rete&);
    bool reteIsEmpty() const;

    virtual QString typeUtente() const =0;
    virtual bool ricerca(const SmartUtente&, const QString&) const =0;
    virtual Utente* clone() const =0;

    virtual void writeTipo(QXmlStreamWriter& xmlWriter) const =0;
    //virtual bool ricerca(const Utente* u, const Ricerca& r,int tipo_ricerca =0) const =0;

private:
    QString username;
    Rete contatti;
};

#endif // UTENTE_H
