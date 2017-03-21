#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QTableWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QFormLayout>
#include <QComboBox>
#include <QMessageBox>
#include <QDateEdit>
#include<QScrollArea>

#include <QtCore>
#include <Model/DataBase/client.h>

class ClientView:public QWidget
{    
    Q_OBJECT

public:
    explicit ClientView(QWidget *parent = 0);

    void getClient(const QString& cogn ="",const QString& nm ="",const QDate& dt_nasc =QDate(),
                   const QString& c_nasc ="",const QString& r_nasc ="",const QString& i_res ="",
                   const QString& c_res ="",const QString& r_res ="");

    void stampaTypeTitolo(const QString& tit ="", const QString& tp ="");

    void buildLingua(Lingue::lingua_const_iterator &inizio,Lingue::lingua_const_iterator &fine);
    void clearTableLingue();

    void buildCompetenze(competenze::competenze_const_iterator &inizio, competenze::competenze_const_iterator &fine);
    void clearTableCompetenze();

    void buildSearch(const QList<const SmartChangeType*> &lista);
    void clearSearch();

    void buildRete(Rete::rete_const_iterator &inizio,Rete::rete_const_iterator &fine);

    void readMode() const;

signals:
    void sendEditingIn(const QString& cogn ="",const QString& nm ="",const QDate& dt_nasc =QDate(),
                       const QString& c_nasc ="",const QString& r_nasc ="",const QString& i_res ="",
                       const QString& c_res ="",const QString& r_res ="");
    void competenzeOut(const QString& titolo,const QString& com ="",const QString& reg ="",
                       const QDate& ini =QDate(),const QDate& fin =QDate(),const QString& desc ="");

    void sendLingua(const QString& lng);

    void sendRemoveLingua(const QString& lng);

    void sendRemoveCompetenza(const QString& Comp);

    void sendRemoveRete(const QString& u);

    void sendsearchUser(const QString& u);

    void sendAddContatto(const QString& u);

    void seeRete();

public slots:

    void searchUser(const QString &u);

    void clearCompetenze();

private slots:
    void selectCompetenza(int row);
    void selectLingua(int row);
    void selectContatto(int row);

    void removeLinguaOut();
    void removeCompetenzaOut();
    void addContattoOut();

    void removeReteOut();

    void enabledDisableAccetta();
    void clearDatiPersonali();

    void editingIn();

    void datiPersonaliEnable();
    void datiPersonaliDisable();

    void competenzeIn();
    void linguaIn();

    void enableDisableLingua();

    void descrioneOut(int row);

    void enabledDisableCancella();

    void enabledDisableRimuovi();

    void enabledDisableElimina();

    void modificaCompetenza(int row);

private:
    QString lingua_selezionata;
    QString Competenza_selezionata;
    QString user_selezionata;

    QGroupBox *GroupBox_tot;

    QHBoxLayout* layout_dxsx;
//parte sx
    QLabel *username_title;
    QLabel *type_account_l;
    QLabel *type_accountl;
    QScrollArea* scroll_area;
    QGroupBox *temp;

    QHBoxLayout* layout_disconnetti_esci;
    QPushButton *disconnetti;//DA implementare
    QPushButton *esci;
    //lingue
    QPushButton *inserisci;
    QPushButton *rimuovi;

    QLineEdit *inserisci_lingua;

    QHBoxLayout* layout_inserisci_aggiungi;
    QVBoxLayout* layout_lingue;

    QTableWidget* table_lingue;
    QGroupBox *GroupBox_lingue;

    //competenze
    QLabel *titolo_l;
    QLabel *comune_l;
    QLabel *regione_l;
    QLabel *inizio_l;
    QLabel *fine_l;
    QLabel *descrizione_l;

    QLineEdit *titolo;
    QLineEdit *comune;
    QLineEdit *regione;

    QDateEdit *inizio;
    QDateEdit *fine;

    QTextEdit* descrizione;

    QPushButton *clear;
    QPushButton *accetta;
    QHBoxLayout *clear_accetta_layout;

    QFormLayout *competenze_form;
    QGroupBox *GroupBox_competenze;

    //dati personali
    QLabel *cognome_l;
    QLabel *nome_l;
    QLabel *data_nascita_l;
    QLabel *comune_nasc_l;
    QLabel *regione_nasc_l;
    QLabel *indirizzo_res_l;
    QLabel *comune_res_l;
    QLabel *regione_res_l;

    QLineEdit *cognome;
    QLineEdit *nome;
    QLineEdit *comune_nasc;
    QLineEdit *regione_nasc;
    QLineEdit *indirizzo_res;
    QLineEdit *comune_res;
    QLineEdit *regione_res;

    QDateEdit *data_nascita;

    QPushButton *annulla;
    QPushButton *modifica_applica;

    QFormLayout *layout_nascita;
    QFormLayout *layout_residenza;
    QFormLayout *dati_form;
    QGroupBox *GroupBox_nascita;
    QGroupBox *GroupBox_residenza;
    QGroupBox *GroupBox_dati;

    QHBoxLayout *layout_modifica_applica;
    QHBoxLayout* layout_typeAccount;
    QVBoxLayout* layout_sx; //layout parte sx
//Parte dx
   //community
    //ricerca
    QLineEdit *ricerca;

    QPushButton *aggiungi;

    QVBoxLayout* layout_ricerca;
    QGroupBox *GroupBox_ricerca;

    //rete
    QPushButton *mostra;
    QPushButton *elimina;

    QHBoxLayout* layout_rete;
    QGroupBox *GroupBox_rete;

    QVBoxLayout* layout_ric_rete;//ricerca-rete layout

    QLabel *label_community;

    QTableWidget* table_rete_ricerca;

    QHBoxLayout* layout_community;//community-layout

  //competenze
    QLabel *label_competenze;

    QTableWidget* table_competenze;
    QPushButton *cancella;

    QVBoxLayout* layout_dx; //layout parte dx

};

#endif // CLIENTVIEW_H
