#include "clientcontrol.h"

ClientControl::ClientControl(QObject *parent, Client *m, ClientView *v, bool b,bool d):QObject(parent), model(m), view(v)
{
    if(b)
    {
    setClientViewDati();
    view->stampaTypeTitolo(model->getClientUtente()->getUsername(),model->getTypeUser());

    buildLinguaOut(model->getClientUtente()->getPoliglotta());
    buildCompetenzaOut(model->getClientUtente()->getCompetente());


    Rete rt=model->getClientUtente()->getRete();
    buildReteOut(rt);

    //connect
    connect(view,SIGNAL(sendEditingIn(QString,QString,QDate,QString,QString,QString,QString,QString)),
            this,SLOT(editingOut(QString,QString,QDate,QString,QString,QString,QString,QString)));

    connect(view,SIGNAL(competenzeOut(QString,QString,QString,QDate,QDate,QString)),
            this,SLOT(insertCompetenza(QString,QString,QString,QDate,QDate,QString)));

    connect(view,SIGNAL(sendLingua(QString)),this,SLOT(receiveLingua(QString)));

   connect(view,SIGNAL(sendRemoveLingua(QString)),this,SLOT(receiveRemoveLingua(QString)));

   connect(view,SIGNAL(sendRemoveCompetenza(QString)),this,SLOT(receiveRemoveCompetenza(QString)));

   connect(view,SIGNAL(sendsearchUser(QString)),this,SLOT(receiveSearchUser(QString)));

   connect(view,SIGNAL(sendAddContatto(QString)),this,SLOT(receiveAddContatto(QString)));

   connect(view,SIGNAL(seeRete()),this,SLOT(seeReteOut()));

   connect(view,SIGNAL(sendRemoveRete(QString)),this,SLOT(receiveRemoveRete(QString)));

   //viewReadMode();
    view->show();
    }
    if(d) quick_exit(0);
}

void ClientControl::viewReadMode() const
{
    view->readMode();
}

void ClientControl::receiveRemoveRete(const QString &u)
{
    Rete rt=model->getClientUtente()->getRete();
    if(rt.contains(u))
    {
        rt.deleteUtente(u);
        (*model->getClientUtentePunt())->setRete(rt);
        buildReteOut(rt);
    }
}

void ClientControl::seeReteOut()
{
    Rete rt=model->getClientUtente()->getRete();
    buildReteOut(rt);
}

void ClientControl::receiveAddContatto(const QString &u)
{
    if(!(u.isEmpty()))
    {
        Rete rt=model->getClientUtente()->getRete();
        if(!(rt.contains(u)))
        {
          rt.insert(u);
          (*model->getClientUtentePunt())->setRete(rt);
          buildReteOut(rt);
        }
    }
}

void ClientControl::buildReteOut(const Rete &rt)
{
    if(!(rt.isEmpty()))
    {
        Rete::rete_const_iterator inizio=rt.begin();
        Rete::rete_const_iterator fine=rt.end();
        view->buildRete(inizio,fine);
    }

}

void ClientControl::receiveSearchUser(const QString &u)
{
    if(!(u.isEmpty()))
    {
        QList<const SmartChangeType*> lista=model->search(u);
        if(!(lista.isEmpty()))
            view->buildSearch(lista);
        else
            view->clearSearch();
    }
}


void ClientControl::receiveRemoveCompetenza(const QString &comp)
{
    competenze c=model->getClientUtente()->getCompetente();
    if(c.contains(comp))
    {
        c.remove(comp);
        (*model->getClientUtentePunt())->setCompetente(c);
        buildCompetenzaOut(c);
    }
}

void ClientControl::receiveRemoveLingua(const QString &lng)
{
    Lingue lg=model->getClientUtente()->getPoliglotta();
    if(lg.contains(lng))
    {
        lg.deleteLingua(lng);
        (*model->getClientUtentePunt())->setPoliglotta(lg);
        buildLinguaOut(lg);
    }
}

void ClientControl::receiveLingua(const QString &lng)
{
    Lingue lg=model->getClientUtente()->getPoliglotta();
    if(!(lg.contains(lng)))
    {
        lg.insert(lng);
        (*model->getClientUtentePunt())->setPoliglotta(lg);
        buildLinguaOut(lg);
    }

}

void ClientControl::buildCompetenzaOut(const competenze& comp)
{
    if(comp.size())
    {
        competenze::competenze_const_iterator inizio=comp.begin();
        competenze::competenze_const_iterator fine=comp.end();
        view->buildCompetenze(inizio,fine);
    }

}

void ClientControl::buildLinguaOut(const Lingue& lg)
{
    if(lg.size())
    {
        Lingue::lingua_const_iterator inizio=lg.begin();
        Lingue::lingua_const_iterator fine=lg.end();
        view->buildLingua(inizio,fine);
    }
}

void ClientControl::insertCompetenza(const QString &titolo, const QString &com,const QString &reg,
                                     const QDate &ini, const QDate &fin,const QString &desc)
{
    Luogo lg(com,reg);
    mansione man(titolo,desc,ini,fin,lg);
    competenze comp=model->getClientUtente()->getCompetente();
    comp.insert(man);

    (*model->getClientUtentePunt())->setCompetente(comp);

    buildCompetenzaOut(model->getClientUtente()->getCompetente());
}

void ClientControl::editingOut(const QString& cogn,const QString& nm,const QDate& dt_nasc,
                               const QString& c_nasc,const QString& r_nasc,const QString& i_res,
                               const QString& c_res,const QString& r_res)
{
    Nato o(dt_nasc.day(),dt_nasc.month(),dt_nasc.year(),c_nasc,r_nasc);
    Residenza a(c_res,r_res,i_res);

    competenze comp=model->getClientUtente()->getCompetente();
    Lingue p=model->getClientUtente()->getPoliglotta();
    Rete rt=model->getClientUtente()->getRete();

    model->setClient(cogn,nm,comp,p,a,o,rt);

    setClientViewDati();
}

void ClientControl::setClientViewDati()
{
    view->getClient(model->getClientUtente()->getCognome(),model->getClientUtente()->getNome(),
                    model->getClientUtente()->getOrigine(),model->getClientUtente()->getOrigine().getComune(),
                    model->getClientUtente()->getOrigine().getRegione(),
                    model->getClientUtente()->getAbitazione().getIndirizzo(),
                    model->getClientUtente()->getAbitazione().getComune(),
                    model->getClientUtente()->getAbitazione().getRegione()
                    );
}
