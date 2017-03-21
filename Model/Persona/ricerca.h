#ifndef RICERCA_H
#define RICERCA_H
#include <QString>
#include <QDate>

class Ricerca //Classe dedicata aggiungere filtri alla ricerca //non implementata
{
public:
    Ricerca(const QString& ="");
    Ricerca(const QString&,const QString& ="",const QString& ="",const QString& ="",const QString& ="",
            const QString& ="",const QString& ="",const QDate& =QDate(),const QString& ="",const QString& ="",
            const QString& ="");

    QString getGenerica() const;
    QString getCognome() const;
    QString getNome() const;
    QString getcompetenza() const;
    QString getLingua() const;
    QString getNato_regione() const;
    QString getNato_comune() const;
    QDate getNato_date() const;
    QString getResidenza_regione() const;
    QString getResidenza_comune() const;
    QString getResidenza_indirizzo() const;

    QString getGenerica() const;
    void setCognome(const QString&);
    void setNome(const QString&);
    void setcompetenza(const QString&);
    void setLingua(const QString&);
    void setNato_regione(const QString&);
    void setNato_comune(const QString&);
    void setNato_date(const QDate&);
    void setResidenza_regione(const QString&);
    void setResidenza_comune(const QString&);
    void setResidenza_indirizzo(const QString&);

private:
    QString generica;
    QString serch_cognome;
    QString serch_nome;
    QString serch_competenza;
    QString serch_lingua;
    QString serch_nato_regione;
    QString serch_nato_comune;
    QDate serch_nato_date;
    QString serch_residenza_regione;
    QString serch_residenza_comune;
    QString serch_residenza_indirizzo;

};

#endif // RICERCA_H
