#ifndef LINGUE_H
#define LINGUE_H
#include <QString>
#include <QSet>
#include<QXmlStreamReader>

class Lingue
{
public:
    typedef QSet<QString>::iterator lingua_iterator;
    typedef QSet<QString>::const_iterator lingua_const_iterator;

    Lingue(const QString& ="");
    Lingue(QSet<QString>&);

    QList<QString> getLingue() const;//restituisce una list<Qstring> con tutte le lingue


    void insert(const QString&); //inserisce una lingua
    void insert(const QSet<QString> &); //inserisce in lingua tutte le lingue contenute in "a" e non presenti in lingua

    bool deleteLingua(const QString&); //elimina la lingua indicata nel parametro passato

    bool contains(const QString&); //true se contiene la key passata, false altrimenti

    int size() const;


    lingua_iterator begin();
    lingua_iterator end();
    lingua_const_iterator begin() const;
    lingua_const_iterator end() const;

    static Lingue readLingue(QXmlStreamReader&);

private:
    QSet<QString> lingua;
};

#endif // LINGUE_H
