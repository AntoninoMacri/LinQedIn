#ifndef ADMINVIEW_H
#define ADMINVIEW_H
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

#include <QApplication>
#include <Model/DataBase/admin.h>

class AdminView:public QWidget
{
    Q_OBJECT

public:
    explicit AdminView(QWidget *parent = 0);

    void buildSearch(const QList<const SmartChangeType*> &lista);
    void buildTable(DataBase::db_const_iterator &inizio,DataBase::db_const_iterator &fine);

    void clearTable();

signals:
    void removeUserChosen(const QString& user);

    void insertUtente(const QString& user,const QString& cogn,const QString& nm,const QString& tp);

    void searchUserChosen(const QString &u);

    void changeType(const QString &u,const QString &tp,const QString &cc);

public slots:
    void enabledDisableInserisci();
    void removeUser();
    void enabledDisableCreditCard(int n);
    void helpOut();
    void enableInfoDel();
    void DisableInfoDel();

    void creaUtente();
    void existingUserOut(const QString& u);

    void searchUser(const QString& u);

    void setSel(int row);

    void utenteChangeType();

    void setTipo(const QString& tp);

private:
    void clearInsert();
    void setSelezionato();

    QString selezionato;
    QString tipo;

    QLabel *title;
    QLabel *database;
    QLabel* u;
    QLabel* cogn;
    QLabel* nm;
    QLabel* tp;
    QLabel* ut;
    QLabel* sel;
    QLabel* cambia_tp;
    QLabel* credit_card_label;

    QLineEdit *user;
    QLineEdit *cognome;
    QLineEdit *nome;
    QLineEdit *ricerca;
    QLineEdit *credit_card_input;

    QRadioButton *type;
    QRadioButton* basic;
    QRadioButton* business;
    QRadioButton* executive;


    QFormLayout *crea_utente;
    QFormLayout * layoutModifica;
    QGroupBox *crea_utente_GroupBox;
    QGroupBox *ricerca_GroupBox;
    QGroupBox *modifica_utente;

    QTextEdit* text;

    QPushButton* help;
    QPushButton* add;
    QPushButton* disconnetti;//DA implementare
    QPushButton* esci;    
    QPushButton* info;//DA implementare
    QPushButton* del;
    QPushButton *inserisci;
    QPushButton *conferma;

    QTableWidget* table;

    QVBoxLayout* layout;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;
    QVBoxLayout* layoutRic;
    QHBoxLayout* info_remove;

    QComboBox* cambia_tipo_ComboBox;


};

#endif //AdminView_H
