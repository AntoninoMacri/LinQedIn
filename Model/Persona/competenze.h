#ifndef COMPETENZE_H
#define COMPETENZE_H
#include <QMap>
#include <QString>
#include <Model/Persona/mansione.h>
#include<QXmlStreamReader>

class competenze //titoli di studio, esperienze lavorative o semplice abilità che si attesta di avere
{
public:
    typedef QMap<QString,mansione>::iterator competenze_iterator;
    typedef QMap<QString,mansione>::const_iterator competenze_const_iterator;

    competenze(const mansione& =mansione()); // ="Nessuna Competenza Riportata"
    competenze(QMap<QString,mansione>&);


    QList<QString> getKeys() const;
    QList<mansione> getValues () const;
    QMap<QString,mansione> getMansioni() const;


    bool contains (const QString&) const;
    int size() const;


    void insert(const mansione&); //fa anche da modifica
    void insert(const QMap<QString,mansione>&); //NOTA: dalle Api QT:come risultato può contenere più titoli con stessa key
    int remove(const QString&);//elimina il titolo o i titoli(con la key indicata)

    competenze_iterator begin();
    competenze_iterator end();
    competenze_const_iterator begin() const;
    competenze_const_iterator end() const;

    static competenze readCompetenze(QXmlStreamReader&);

private:
    QMap<QString,mansione> titoli; //key=Qstring titolo; values=mansione dettagli
};

#endif // COMPETENZE_H
