#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
#include <Model/Persona/competenze.h>
#include <Model/Persona/lingue.h>
#include <Model/Persona/residenza.h>
#include <Model/Persona/nato.h>

class Persona
{
public:
    Persona(const QString&, const QString&);
    Persona(const QString&, const QString&, const competenze&, const Lingue&, const Residenza&, const Nato&);

    QString getCognome() const;
    QString getNome() const;
    competenze getCompetente() const;
    Lingue getPoliglotta() const;
    Residenza getAbitazione() const;
    Nato getOrigine() const;

    void setPersona(const QString&,const QString&,const competenze&,const Lingue&,const Residenza&,const Nato&);
    void setCognome(const QString&);
    void setNome(const QString&);
    void setCompetente(const competenze&);
    void setPoliglotta(const Lingue&);
    void setAbitazione(const Residenza&);
    void setOrigine(const Nato&);

private:
    QString cognome;
    QString nome;
    competenze competente;
    Lingue poliglotta;
    Residenza abitazione;
    Nato origine;
};

#endif // PERSONA_H
