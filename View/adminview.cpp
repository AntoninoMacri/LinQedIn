#include "adminview.h"

AdminView::AdminView(QWidget *parent):QWidget(parent)
{
    selezionato="";
    tipo="Basic";

    //Parte SX della finestra
    title=new QLabel("ADMIN",this);
    title->setFont(QFont("Helvetica [Cronyx]", 70, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps");

    help=new QPushButton("?");
    help->setFont(QFont("Helvetica [Cronyx]", 18, QFont::Bold));
    help->setToolTip("HELP");
//QLabel inserisci
    u=new QLabel("user");
    u->setStyleSheet("color: #808080;");
    cogn=new QLabel("cognome");
    cogn->setStyleSheet("color: #808080;");
    nm=new QLabel("nome");
    nm->setStyleSheet("color: #808080;");
    tp=new QLabel("tipo: ");
    tp->setStyleSheet("color: #808080;");
//QLineEdit inserisci
    user=new QLineEdit();
    cognome=new QLineEdit();
    nome=new QLineEdit();

    basic=new QRadioButton("Basic");
    business=new QRadioButton("Business");
    executive=new QRadioButton("Executive");

    inserisci=new QPushButton("Inserisci");
    inserisci->setDisabled(true);


    layout=new  QVBoxLayout();
    layout->addWidget(basic);
    layout->addWidget(business);
    layout->addWidget(executive);

    crea_utente_GroupBox = new QGroupBox(tr("Crea Utente"));
    crea_utente= new QFormLayout;
    crea_utente->addRow(u, user);
    crea_utente->addRow(cogn, cognome);
    crea_utente->addRow(nm, nome);
    crea_utente->addRow(tp,layout);
    crea_utente->addRow(inserisci);
    crea_utente_GroupBox->setLayout(crea_utente);
    crea_utente_GroupBox->setStyleSheet("background-color: #C4C2D0;");

    ricerca_GroupBox= new QGroupBox(tr("Ricerca"));
    ricerca=new QLineEdit();
    ricerca->setPlaceholderText("cerca tramite username, cognome o nome");
    layoutRic=new QVBoxLayout();
    layoutRic->addWidget(ricerca);
    ricerca_GroupBox->setLayout(layoutRic);
    ricerca_GroupBox->setStyleSheet("background-color: #C4C2D0;");
    ricerca_GroupBox->setMaximumHeight(70);


//form modifica
    ut=new QLabel("Selezionato: ");
    ut->setStyleSheet("color: #808080;");
    sel=new QLabel("");
    //sel->setStyleSheet("color: #808080;");
    sel->setStyleSheet("font-weight: bold; border: 1px solid grey");
    sel->setAlignment(Qt::AlignCenter);
    sel->setMinimumHeight(30);
    cambia_tp=new QLabel("Cambia tipo:");
    cambia_tp->setStyleSheet("color: #808080;");
    cambia_tipo_ComboBox=new QComboBox();
    QStringList typelist;
    typelist<<"Basic"<<"Business"<<"Executive";
    cambia_tipo_ComboBox->addItems(typelist);

    credit_card_label=new QLabel("CreditCard:");
    credit_card_label->setStyleSheet("color: #808080;");
    credit_card_input=new QLineEdit();
    credit_card_input->setDisabled(true);

    info=new QPushButton("info");
    info->setHidden(true);
    info->setDisabled(true);
    del=new QPushButton("Remove");
    del->setDisabled(true);
    info_remove=new QHBoxLayout();
    info_remove->addWidget(info);
    info_remove->addWidget(del,0,Qt::AlignRight);
    conferma=new QPushButton("conferma");
    conferma->setDisabled(true);


    modifica_utente= new QGroupBox(tr("Modifica"));
    layoutModifica= new QFormLayout;
    layoutModifica->addRow(ut, sel);
    layoutModifica->addRow(info_remove);
    layoutModifica->addRow(cambia_tp, cambia_tipo_ComboBox);
    layoutModifica->addRow(credit_card_label,credit_card_input);
    layoutModifica->addRow(conferma);
    modifica_utente->setLayout(layoutModifica);
    modifica_utente->setStyleSheet("background-color: #C4C2D0;");
    //modifica_utente->setMaximumHeight(70);

    disconnetti=new QPushButton("Disconnetti");
    disconnetti->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Bold));
    disconnetti->setToolTip("torna ad Home");
    disconnetti->setHidden(true);
    esci=new QPushButton("Esci");
    esci->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Bold));
    esci->setToolTip("Chiudi programma");

    QHBoxLayout *chiusura=new QHBoxLayout();
    chiusura->addWidget(disconnetti);
    chiusura->addWidget(esci);

    layout2=new QVBoxLayout();
    layout2->addWidget(title);
    layout2->addWidget(help,0,Qt::AlignLeft);
    layout2->addWidget(crea_utente_GroupBox);
    layout2->addWidget(ricerca_GroupBox);
    layout2->addWidget(modifica_utente);
    layout2->addLayout(chiusura);


    //Parte DX della finestra
    database=new QLabel("DATABASE");
    database->setFont(QFont("Helvetica [Cronyx]", 18, QFont::Bold));
    database->setStyleSheet("font-variant: small-caps");

    table=new QTableWidget();
    table->setColumnCount(4);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList tabHeader;
    tabHeader<<"Username";
    tabHeader<<"Cognome";
    tabHeader<<"Nome";
    tabHeader<<"Tipo";
    table->setHorizontalHeaderLabels(tabHeader);

    layout=new QVBoxLayout();
    layout->addWidget(database);
    layout->addWidget(table);

    layout3=new QHBoxLayout(this);
    layout3->addLayout(layout2);
    layout3->addLayout(layout);

    this->setMinimumHeight(730);
    this->setMinimumWidth(900);

    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(del,SIGNAL(clicked()),this,SLOT(removeUser()));
    connect(cambia_tipo_ComboBox,SIGNAL(activated(int)),this,SLOT(enabledDisableCreditCard(int)));

    connect(user,SIGNAL(editingFinished()),this,SLOT(enabledDisableInserisci()));
    connect(cognome,SIGNAL(editingFinished()),this,SLOT(enabledDisableInserisci()));
    connect(nome,SIGNAL(editingFinished()),this,SLOT(enabledDisableInserisci()));

    connect(basic,SIGNAL(clicked()),this,SLOT(enabledDisableInserisci()));
    connect(business,SIGNAL(clicked()),this,SLOT(enabledDisableInserisci()));
    connect(executive,SIGNAL(clicked()),this,SLOT(enabledDisableInserisci()));
    connect(help,SIGNAL(clicked()),this,SLOT(helpOut()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(creaUtente()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(DisableInfoDel()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(enabledDisableInserisci()));
    connect(ricerca,SIGNAL(textEdited(QString)),this,SLOT(searchUser(QString)));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(setSel(int)));
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(setSel(int)));
    connect(conferma,SIGNAL(clicked()),this,SLOT(utenteChangeType()));
    connect(cambia_tipo_ComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(setTipo(QString)));

}

void AdminView::setTipo(const QString &tp)
{
    tipo=tp;
}

void AdminView::utenteChangeType()
{
    emit changeType(selezionato,tipo,credit_card_input->text());
    selezionato="";
    setSelezionato();
    DisableInfoDel();
    tipo="Basic";
}

void AdminView::buildTable(DataBase::db_const_iterator &inizio, DataBase::db_const_iterator &fine)
{
    clearTable();
    int row=0;
    for(DataBase::db_const_iterator it=inizio; it!=fine; ++it)
    {
        table->setRowCount(row+1);
        QTableWidgetItem *user = new QTableWidgetItem((*it)->getPointer()->getUsername());
        QTableWidgetItem *cogn = new QTableWidgetItem((*it)->getPointer()->getCognome());
        QTableWidgetItem *nm = new QTableWidgetItem((*it)->getPointer()->getNome());
        QTableWidgetItem *tp = new QTableWidgetItem((*it)->getPointer()->typeUtente());
        table->setItem(row,0,user);
        table->setItem(row,1,cogn);
        table->setItem(row,2,nm);
        table->setItem(row,3,tp);
        row++;
    }

}

void AdminView::buildSearch(const QList<const SmartChangeType *> &lista)
{
    clearTable();
    int row=0;
    if(!(lista.isEmpty()))
        for(QList<const SmartChangeType*>::ConstIterator it=lista.begin(); it!=lista.end(); ++it)
        {
            table->setRowCount(row+1);
            QTableWidgetItem *user = new QTableWidgetItem((*it)->getPointer()->getUsername());
            QTableWidgetItem *cogn = new QTableWidgetItem((*it)->getPointer()->getCognome());
            QTableWidgetItem *nm = new QTableWidgetItem((*it)->getPointer()->getNome());
            QTableWidgetItem *tp = new QTableWidgetItem((*it)->getPointer()->typeUtente());
            table->setItem(row,0,user);
            table->setItem(row,1,cogn);
            table->setItem(row,2,nm);
            table->setItem(row,3,tp);
            row++;
        }
}

void AdminView::clearTable()
{
    selezionato="";
    setSelezionato();
    table->clearContents();
    table->setRowCount(0);
}

void AdminView::setSel(int row)
{
   selezionato=table->item(row,0)->text();
   enableInfoDel();
   setSelezionato();
}

void AdminView::setSelezionato()
{
    sel->setText(selezionato);
}

void AdminView::searchUser(const QString &u)
{
    emit searchUserChosen(u);
}

void AdminView::enableInfoDel()
{
    info->setEnabled(true);
    del->setEnabled(true);
    conferma->setEnabled(true);
}

void AdminView::DisableInfoDel()
{
    info->setDisabled(true);
    del->setDisabled(true);
    conferma->setDisabled(true);
    credit_card_input->clear();
}

void AdminView::creaUtente()
{
    QString tp="Basic";
    if(business->isChecked())
        tp="Business";
    if(executive->isChecked())
        tp="Executive";
    emit insertUtente(user->text(),cognome->text(),nome->text(), tp);
    table->clearSelection();
    clearInsert();
}


void AdminView::clearInsert()
{
    user->clear();
    cognome->clear();
    nome->clear();

    basic->setChecked(false);
    business->setChecked(false);
    executive->setChecked(false);

    basic->clearFocus();
    business->clearFocus();
    executive->clearFocus();
}

void AdminView::helpOut()
{
    QMessageBox helpMessage;
    helpMessage.setIcon(QMessageBox::Question);
    helpMessage.setWindowTitle("Help");
    helpMessage.setInformativeText("HELP \n\n-L'inserimento è possibile solo compilando tutti i campi \n-L'utente va selezionato dalla tabella mediante un click sulla riga che lo contradistingue. \n-Una volta scelto l'utente comparirà nella casella Selezionato \n-La credit card è inseribile solo per utenti di tipo business ed executive \n\n-Il programma NON ha salvataggio tra operazioni \n-Il salvataggio avviene mediante click di Disconnetti o Esci");
    helpMessage.setStandardButtons(QMessageBox::Close);
    helpMessage.setDefaultButton(QMessageBox::Cancel);
    helpMessage.exec();
}

void AdminView::enabledDisableInserisci()
{
    if(user->text().isEmpty() || cognome->text().isEmpty() || nome->text().isEmpty())
        inserisci->setDisabled(true);
    else
        if(basic->hasFocus() || business->hasFocus() || executive->hasFocus())
            inserisci->setEnabled(true);
  if(user->text().contains(QRegExp("\\Admin+",Qt::CaseInsensitive)))
          inserisci->setDisabled(true);
  if(user->text().contains(QRegExp("\\Close+",Qt::CaseInsensitive)))
          inserisci->setDisabled(true);
}

void AdminView::enabledDisableCreditCard(int n)
{
    if(n==0)
    {
        credit_card_input->setDisabled(true);
        credit_card_input->clear();
    }
    else
        credit_card_input->setEnabled(true);
}

void AdminView::removeUser()
{
    QMessageBox warning;
    warning.setIcon(QMessageBox::Question);
    warning.setWindowTitle("Rimuovi utente");
    warning.setInformativeText("Vuoi veramente eliminare questo utente?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    warning.setDefaultButton(QMessageBox::Cancel);
    int ret = warning.exec();
    if(ret==QMessageBox::Yes) {
        emit removeUserChosen(selezionato);
        DisableInfoDel();
    }
}

void AdminView::existingUserOut(const QString& u)
{
    QMessageBox helpMessage;
    helpMessage.setIcon(QMessageBox::Question);
    helpMessage.setWindowTitle("Utente Esistente");
    helpMessage.setInformativeText("AVVISO: \n-L'utente esiste già. \n-Non è stato creato alcun nuovo utente \n\n-Per inserire un nuovo utente con \nUsername: \""+u+"\" \n1)Eliminare l'utente già presente \n2)rieffettuare l'inserimento");
    helpMessage.setStandardButtons(QMessageBox::Close);
    helpMessage.setDefaultButton(QMessageBox::Cancel);
    helpMessage.exec();
}
