#ifndef MANSIONE_H
#define MANSIONE_H
#include <Model/Persona/luogo.h>
#include <QDate>
#include <QString>

//Evito di inserire un campo per i voti poiche' con titoli intendo lavori, o qualifiche,
//o corsi con attestati che non hanno voto.
//1.Se si vogliono inseririre voti o simili e' possibile comunque farlo nella descrizione.
//2.Evito il campo voti anche perchè per essere il più generale possibile dovrebbe essere un campo QString.
//Perciò non avrebbe valore un campo dove comunque non ho modo di effettuare generiche funzioni di confronto
//fra voti di utenti diversi che siano valide per tutti i modi in cui può essere data una valutazione.

class mansione //qualsiasi attività svolta che ha portato al conseguimento di un attestato(scolastico, qualifiche, ecc.) o un qualche tipo di competenza lavorativa
{
public:
    mansione(const QString& ="",const QString& ="",const QDate& =QDate(),const QDate& =QDate(),const Luogo& =Luogo());

    QString getTitolo() const;
    QString getDescrizione() const;
    QString getInizio() const;
    QString getFine() const;
    QString getComune() const;
    QString getRegione() const;

    QDate dateInizio() const;
    QDate dateFine() const;

    void setTitolo(const QString&);
    void setDescrizione(const QString&);
    bool setInizio(const QDate&); //true se la data è valida, false viceversa
    bool setFine(const QDate&);  //true se la data è valida, false viceversa
    void setLuogo(const Luogo&);
    void setLuogo(const QString&,const QString&); //comune, regione
    void setComune(const QString&);
    void setRegione(const QString&);

    int periodo() const; //numero di gioni della mansione svolta
    bool equalsInizioFine(const mansione&) const;//true se data inizio e fine della data d e di quella di *this coincidono, false viceversa
    bool equalsPeriodo(const mansione&) const;

    bool operator ==(const mansione&) const; //2 mansioni identiche(tranne che per la descrizione)

    bool equals(const mansione&) const; //true se le 2 mansioni( other e *this) hanno stesso nome,luogo e durata in giorni(anche se in date diverse), false viceversa
    bool different(const mansione&) const;//true se le 2 mansioni( other e *this) hanno stesso nome,luogo e *this.periodo()<other.periodo(), false viceversa
    bool lower(const mansione&) const;
    bool greater(const mansione&) const;
    bool lowerEquals(const mansione&) const;
    bool greaterEquals(const mansione&) const;

private:
    QString titolo;
    QString descrizione;
    QDate inizio;
    QDate fine;
    Luogo localita;
};

#endif // MANSIONE_H

