#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H
#include <QObject>
#include <Model/DataBase/client.h>
#include <View/clientview.h>
#include <QApplication>

class ClientControl: public QObject
{
    Q_OBJECT

public:
    ClientControl(QObject *parent = 0, Client* m=0, ClientView* v =0,bool b =false,bool d=true);
    void viewReadMode() const;

signals:

public slots:
    void editingOut(const QString& cogn ="",const QString& nm ="",const QDate& dt_nasc =QDate(),
                           const QString& c_nasc ="",const QString& r_nasc ="",const QString& i_res ="",
                           const QString& c_res ="",const QString& r_res ="");
    void insertCompetenza(const QString& titolo,const QString& com ="",const QString& reg ="",
                          const QDate& ini =QDate(),const QDate& fin =QDate(),const QString& desc ="");
    void receiveLingua(const QString& lng);

    void receiveRemoveLingua(const QString& lng);

    void receiveRemoveCompetenza(const QString &comp);

    void receiveSearchUser(const QString& u);

    void receiveAddContatto(const QString& u);

    void seeReteOut();

    void receiveRemoveRete(const QString &u);

private:
    void setClientViewDati();
    void buildLinguaOut(const Lingue& lg);
    void buildCompetenzaOut(const competenze& comp);
    void buildReteOut(const Rete& rt);

    Client *model;
    ClientView *view;
};

#endif // CLIENTCONTROL_H
