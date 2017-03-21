#ifndef LUOGO_H
#define LUOGO_H

#include <QString>

class Luogo
{
public:
    Luogo(const QString& ="", const QString& ="");

    QString getComune() const;
    QString getRegione() const;

    void setComune(const QString& ="non definito");
    void setRegione(const QString& ="non definito");
    void setLuogo(const QString& ="non definito",const QString& ="non definito");

    bool contains(const QString&);

    bool operator ==(const Luogo&) const;
private:
    QString comune;
    QString regione;
};

#endif // LUOGO_H
