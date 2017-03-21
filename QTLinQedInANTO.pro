#-------------------------------------------------
#
# Project created by QtCreator 2015-08-27T20:30:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTLinQedInANTO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/DataBase/admin.cpp \
    Model/DataBase/client.cpp \
    Model/DataBase/database.cpp \
    Model/Persona/competenze.cpp \
    Model/Persona/lingue.cpp \
    Model/Persona/luogo.cpp \
    Model/Persona/mansione.cpp \
    Model/Persona/nato.cpp \
    Model/Persona/persona.cpp \
    Model/Persona/residenza.cpp \
    Model/Persona/rete.cpp \
    Model/Persona/ricerca.cpp \
    Model/Utente/smartchangetype.cpp \
    Model/Utente/smartutente.cpp \
    Model/Utente/utente.cpp \
    Model/Utente/utentebasic.cpp \
    Model/Utente/utentebusiness.cpp \
    Model/Utente/utenteexecutive.cpp \
    Model/Utente/utentegratis.cpp \
    Model/Utente/utentepay.cpp \
    View/adminview.cpp \
    Controller/admincontrol.cpp \
    View/clientview.cpp \
    Controller/clientcontrol.cpp

HEADERS  += mainwindow.h \
    Model/DataBase/admin.h \
    Model/DataBase/client.h \
    Model/DataBase/database.h \
    Model/Persona/competenze.h \
    Model/Persona/lingue.h \
    Model/Persona/luogo.h \
    Model/Persona/mansione.h \
    Model/Persona/nato.h \
    Model/Persona/persona.h \
    Model/Persona/residenza.h \
    Model/Persona/rete.h \
    Model/Persona/ricerca.h \
    Model/Utente/smartchangetype.h \
    Model/Utente/smartutente.h \
    Model/Utente/utente.h \
    Model/Utente/utentebasic.h \
    Model/Utente/utentebusiness.h \
    Model/Utente/utenteexecutive.h \
    Model/Utente/utentegratis.h \
    Model/Utente/utentepay.h \
    View/adminview.h \
    Controller/admincontrol.h \
    View/clientview.h \
    Controller/clientcontrol.h

FORMS    += mainwindow.ui
