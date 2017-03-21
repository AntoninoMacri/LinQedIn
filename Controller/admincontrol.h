#ifndef ADMINCONTROL_H
#define ADMINCONTROL_H
#include <QObject>
#include <Model/DataBase/admin.h>
#include <View/adminview.h>


class AdminControl: public QObject
{    
    Q_OBJECT

public:
    explicit AdminControl(QObject *parent = 0, Admin* m =0, AdminView* v =0,bool b =false,bool d =false);

    AdminView *getPuntView() const;
signals:
    void existingUser(const QString& u);

public slots:
    void insertUser(const QString& user, const QString& cogn, const QString& nm,const QString& tp);
    void searchUser(const QString& s);
    void removeUser(const QString& u);
    void setTypeUser(const QString &u,const QString &tp,const QString &cc);

private:
    Admin *model;
    AdminView *view;
};

#endif // ADMINCONTROL_H
