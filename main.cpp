#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <View/adminview.h>
#include <Model/DataBase/database.h>
#include <Model/DataBase/admin.h>
#include <Controller/admincontrol.h>
#include <View/clientview.h>
#include <Controller/clientcontrol.h>

#include <QInputDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool b=false;//lasciato vuoto chiude il programma
    bool c=false;//crea Admin
    bool d=false;//crea client passato
    DataBase db;
    QString user="";
    while((b+c+d)==0)
    {
        user=QInputDialog::getText(0,"LINQEDIN","SINGLE SIGN-ON");
     if (user.contains("CLOSE",Qt::CaseInsensitive))
         d=true;

     if(user.contains("Admin",Qt::CaseInsensitive))
          c=true;

     if(db.containsUtente(user))
         b=true;
    }
    AdminView adv;
    Admin ad(&db);
    AdminControl adc(0,&ad,&adv,c,d);


     ClientView clv;
     Client cl(user,&db);
     ClientControl clc(0,&cl,&clv,b,d);

    return a.exec();
}
