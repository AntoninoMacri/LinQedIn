#ifndef RETE_H
#define RETE_H
#include <QString>
#include <QSet>
#include<QXmlStreamReader>
class Rete
{
public:
    typedef QSet<QString>::iterator rete_iterator;
    typedef QSet<QString>::const_iterator rete_const_iterator;

    Rete(const QString& ="");
    Rete(QSet<QString>&);

    QList<QString> getUtenti() const;//restituisce una list<Qstring> con tutti gli utenti

    void insert(const QString&); //inserisce un utente
    void insert(const QSet<QString> &);

    bool deleteUtente(const QString&);

    bool contains(const QString&) const; //true se contiene la key passata, false altrimenti

    bool isEmpty() const;

    rete_iterator begin();
    rete_iterator end();
    rete_const_iterator begin() const;
    rete_const_iterator end() const;

    static Rete readRete(QXmlStreamReader&);

private:
    QSet<QString> utenti;
};

#endif // RETE_H
