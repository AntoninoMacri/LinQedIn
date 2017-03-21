#include "admincontrol.h"

AdminControl::AdminControl(QObject *parent, Admin* m, AdminView* v,bool b, bool d):QObject(parent), model(m), view(v)
{
    if(b)
    {
    if(!(model->isEmpty()))
    {
        DataBase::db_const_iterator inizio=model->begin();
        DataBase::db_const_iterator fine=model->end();
        view->buildTable(inizio,fine);
    }
    view->show();

    connect(view,SIGNAL(insertUtente(QString,QString,QString,QString)),this,SLOT(insertUser(QString,QString,QString,QString)));
    connect(this,SIGNAL(existingUser(QString)),view,SLOT(existingUserOut(QString)));
    connect(view,SIGNAL(searchUserChosen(QString)),this,SLOT(searchUser(QString)));
    connect(view,SIGNAL(removeUserChosen(QString)),this,SLOT(removeUser(QString)));
    connect(view,SIGNAL(changeType(QString,QString,QString)),this,SLOT(setTypeUser(QString,QString,QString)));
}
    if(d) quick_exit(0);
}

void AdminControl::setTypeUser(const QString &u, const QString &tp, const QString &cc)
{
    if(model->containsUtente(u))
    {
        model->utenteChangeType(u,tp,cc);
        DataBase::db_const_iterator inizio=model->begin();
        DataBase::db_const_iterator fine=model->end();
        view->buildTable(inizio,fine);
    }
}

void AdminControl::removeUser(const QString &u)
{
    if(model->containsUtente(u))
    {
        model->removeUtente(u);
        DataBase::db_const_iterator inizio=model->begin();
        DataBase::db_const_iterator fine=model->end();
        view->buildTable(inizio,fine);
    }
}

void AdminControl::searchUser(const QString &s)
{
    if(model->exists(s))
    {
        QList<const SmartChangeType*> lista=model->search(s);
        view->buildSearch(lista);
    }
    else
        view->clearTable();

}


void AdminControl::insertUser(const QString &user, const QString &cogn, const QString &nm, const QString &tp)
{
    if(!model->containsUtente(user))
    {
        model->createUtente(cogn,nm,user,"",tp);
        DataBase::db_const_iterator inizio=model->begin();
        DataBase::db_const_iterator fine=model->end();
        view->buildTable(inizio,fine);
    }
    else
        emit existingUser(user);
}

AdminView* AdminControl::getPuntView() const{ return view; }
