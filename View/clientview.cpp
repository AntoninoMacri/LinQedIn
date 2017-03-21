#include "clientview.h"

ClientView::ClientView(QWidget *parent):QWidget(parent)
{
    lingua_selezionata="";
    Competenza_selezionata="";
    user_selezionata="";

    //Parte sx
    username_title=new QLabel("");
    username_title->setFont(QFont("Helvetica [Cronyx]", 30, QFont::Bold));
    username_title->setStyleSheet("font-variant: small-caps");
    type_account_l=new QLabel("Type account:");
    type_account_l->setFont(QFont("Helvetica [Cronyx]", 17, QFont::Bold));
    type_account_l->setStyleSheet("font-variant: small-caps");
    type_account_l->setStyleSheet("color: #808080;");
    type_accountl=new QLabel("");
    type_accountl->setFont(QFont("Helvetica [Cronyx]", 17, QFont::Bold));
    layout_typeAccount=new QHBoxLayout();
    layout_typeAccount->addWidget(type_account_l);
    layout_typeAccount->addWidget(type_accountl);

    disconnetti=new QPushButton("Disconnetti");
    disconnetti->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Bold));
    disconnetti->setToolTip("torna ad Home");
    disconnetti->setHidden(true);
    esci=new QPushButton("Esci");
    esci->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Bold));
    esci->setToolTip("Chiudi programma");

    layout_disconnetti_esci=new QHBoxLayout();
    layout_disconnetti_esci->addWidget(disconnetti);
    layout_disconnetti_esci->addWidget(esci);

    //lingue
    inserisci=new QPushButton("Inserisci");
    inserisci->setDisabled(true);
    rimuovi=new QPushButton("Rimuovi");
    rimuovi->setDisabled(true);

    inserisci_lingua=new QLineEdit();

    layout_inserisci_aggiungi=new QHBoxLayout();
    layout_inserisci_aggiungi->addWidget(inserisci_lingua);
    layout_inserisci_aggiungi->addWidget(inserisci);
    layout_inserisci_aggiungi->addWidget(rimuovi);


    table_lingue=new QTableWidget();
    table_lingue->setColumnCount(1);
    QStringList tabHeader3;
    tabHeader3<<"Lingue";
    table_lingue->setHorizontalHeaderLabels(tabHeader3);
    table_lingue->setMinimumWidth(90);
    table_lingue->setMinimumHeight(105);
    table_lingue->setStyleSheet("font-weight: bold; border: 1px solid grey");

    layout_lingue=new QVBoxLayout();
    layout_lingue->addWidget(table_lingue);
    layout_lingue->addLayout(layout_inserisci_aggiungi);

    GroupBox_lingue=new QGroupBox();
    GroupBox_lingue->setLayout(layout_lingue);
    GroupBox_lingue->setStyleSheet("background-color: #C4C2D0;");


    //Competenze
    titolo_l=new QLabel("Titolo:");
    titolo_l->setStyleSheet("color: #808080;");
    comune_l=new QLabel("Comune");
    comune_l->setStyleSheet("color: #808080;");
    regione_l=new QLabel("Regione");
    regione_l->setStyleSheet("color: #808080;");
    inizio_l=new QLabel("Inizio");
    inizio_l->setStyleSheet("color: #808080;");
    fine_l=new QLabel("Fine");
    fine_l->setStyleSheet("color: #808080;");
    descrizione_l=new QLabel("Descrizione");
    descrizione_l->setStyleSheet("color: #808080;");

    titolo=new QLineEdit();
    comune=new QLineEdit();
    regione=new QLineEdit();
    inizio=new QDateEdit();
    fine=new QDateEdit();
    descrizione=new QTextEdit();
    descrizione->setStyleSheet("font-weight: bold; border: 1px solid grey");

    clear=new QPushButton("Clear");
    accetta=new QPushButton("Conferma");
    accetta->setDisabled(true);
    clear_accetta_layout=new QHBoxLayout();
    clear_accetta_layout->addWidget(clear);
    clear_accetta_layout->addWidget(accetta);

    GroupBox_competenze= new QGroupBox(tr("Inserisci Competenza"));
    competenze_form= new QFormLayout;
    competenze_form->addRow(titolo_l, titolo);
    competenze_form->addRow(comune_l,comune);
    competenze_form->addRow(regione_l, regione);
    competenze_form->addRow(inizio_l,inizio);
    competenze_form->addRow(fine_l,fine);
    competenze_form->addRow(descrizione_l,descrizione);
    competenze_form->addRow(clear_accetta_layout);
    GroupBox_competenze->setLayout(competenze_form);
    GroupBox_competenze->setStyleSheet("background-color: #C4C2D0;");

    //dati personali
    cognome_l=new QLabel("Cognome");
    cognome_l->setStyleSheet("color: #808080;");
    nome_l=new QLabel("Nome");
    nome_l->setStyleSheet("color: #808080;");
    data_nascita_l=new QLabel("Data_nascita");
    data_nascita_l->setStyleSheet("color: #808080;");
    comune_nasc_l=new QLabel("Comune");
    comune_nasc_l->setStyleSheet("color: #808080;");
    regione_nasc_l=new QLabel("Regione");
    regione_nasc_l->setStyleSheet("color: #808080;");
    indirizzo_res_l=new QLabel("Indirizzo");
    indirizzo_res_l->setStyleSheet("color: #808080;");
    comune_res_l=new QLabel("Comune");
    comune_res_l->setStyleSheet("color: #808080;");
    regione_res_l=new QLabel("Regione");
    regione_res_l->setStyleSheet("color: #808080;");

    cognome=new QLineEdit();
    nome=new QLineEdit();
    comune_nasc=new QLineEdit();
    regione_nasc=new QLineEdit();
    indirizzo_res=new QLineEdit();
    comune_res=new QLineEdit();
    regione_res=new QLineEdit();

    data_nascita=new QDateEdit();
    data_nascita->setMaximumDate(QDate::currentDate());

    annulla=new QPushButton("Annulla");    
    annulla->setToolTip("Annulla le modifiche");
    modifica_applica=new QPushButton("Modifica");
    layout_modifica_applica=new QHBoxLayout();
    layout_modifica_applica->addWidget(annulla);
    layout_modifica_applica->addWidget(modifica_applica);

    GroupBox_nascita= new QGroupBox(tr("Nascita"));
    layout_nascita= new QFormLayout;
    layout_nascita->addRow(comune_nasc_l, comune_nasc);
    layout_nascita->addRow(regione_nasc_l,regione_nasc);
    GroupBox_nascita->setLayout(layout_nascita);
    GroupBox_nascita->setStyleSheet("background-color: #C4C2D0; color: #646060;");

    GroupBox_residenza= new QGroupBox(tr("Residenza"));
    layout_residenza= new QFormLayout;
    layout_residenza->addRow(indirizzo_res_l,indirizzo_res);
    layout_residenza->addRow(comune_res_l, comune_res);
    layout_residenza->addRow(regione_res_l,regione_res);
    GroupBox_residenza->setLayout(layout_residenza);
    GroupBox_residenza->setStyleSheet("background-color: #C4C2D0;  color: #646060; ");

    GroupBox_dati= new QGroupBox(tr("Dati Personali"));
    dati_form= new QFormLayout;
    dati_form->addRow(cognome_l,cognome);
    dati_form->addRow(nome_l, nome);
    dati_form->addRow(data_nascita_l,data_nascita);
    dati_form->addRow(GroupBox_nascita);
    dati_form->addRow(GroupBox_residenza);
    dati_form->addRow(layout_modifica_applica);
    GroupBox_dati->setLayout(dati_form);
    GroupBox_dati->setStyleSheet("background-color: #C4C2D0;");

    layout_sx=new QVBoxLayout();
    layout_sx->addWidget(username_title);
    layout_sx->addLayout(layout_typeAccount);
    layout_sx->addWidget(GroupBox_dati);
    layout_sx->addWidget(GroupBox_competenze);
    layout_sx->addWidget(GroupBox_lingue);
    layout_sx->addLayout(layout_disconnetti_esci);

    GroupBox_tot= new QGroupBox();
    GroupBox_tot->setLayout(layout_sx);

    scroll_area=new QScrollArea();
    scroll_area->setWidget(GroupBox_tot);
    scroll_area->setWidgetResizable(true);
    scroll_area->setAlignment(Qt::AlignHCenter);
    scroll_area->adjustSize();
    scroll_area->setMinimumWidth(400);
    scroll_area->setMinimumHeight(700);

    //Parte dx
    ricerca=new QLineEdit();
    ricerca->setPlaceholderText("Basata sul tuo tipo di account");
    ricerca->setMinimumWidth(250);
    aggiungi=new QPushButton("Aggiungi");
    aggiungi->setDisabled(true);

    layout_ricerca=new QVBoxLayout();
    layout_ricerca->addWidget(ricerca);
    layout_ricerca->addWidget(aggiungi,0,Qt::AlignLeft);

    GroupBox_ricerca= new QGroupBox(tr("Ricerca"));
    GroupBox_ricerca->setLayout(layout_ricerca);
    GroupBox_ricerca->setStyleSheet("background-color: #C4C2D0;");
    GroupBox_ricerca->setMaximumHeight(120);
    GroupBox_ricerca->setMinimumWidth(120);


    mostra=new QPushButton("Mostra");
    elimina=new QPushButton("Elimina");
    elimina->setDisabled(true);

    layout_rete=new QHBoxLayout();
    layout_rete->addWidget(mostra);
    layout_rete->addWidget(elimina);
    GroupBox_rete= new QGroupBox(tr("Rete"));
    GroupBox_rete->setLayout(layout_rete);
    GroupBox_rete->setStyleSheet("background-color: #C4C2D0;");
    GroupBox_rete->setMaximumHeight(80);
    GroupBox_rete->setMinimumWidth(120);

    layout_ric_rete=new QVBoxLayout();
    layout_ric_rete->addWidget(GroupBox_ricerca);
    layout_ric_rete->addWidget(GroupBox_rete);


    table_rete_ricerca=new QTableWidget();
    table_rete_ricerca->setColumnCount(3);    
    table_rete_ricerca->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table_rete_ricerca->setSelectionMode(QAbstractItemView::SingleSelection);
    table_rete_ricerca->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList tabHeader;
    tabHeader<<"Username";
    tabHeader<<"Cognome";
    tabHeader<<"Nome";
    table_rete_ricerca->setHorizontalHeaderLabels(tabHeader);
    table_rete_ricerca->setMinimumWidth(320);

    layout_community=new QHBoxLayout();
    layout_community->addWidget(table_rete_ricerca);
    layout_community->addLayout(layout_ric_rete);

    label_community=new QLabel("COMMUNITY");
    label_community->setFont(QFont("Helvetica [Cronyx]", 18, QFont::Bold));
    label_community->setStyleSheet("font-variant: small-caps");

    cancella=new QPushButton("Cancella");
    cancella->setDisabled(true);

    table_competenze=new QTableWidget();
    table_competenze->setColumnCount(6);
    table_competenze->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table_competenze->setSelectionMode(QAbstractItemView::SingleSelection);
    table_competenze->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList tabHeader2;
    tabHeader2<<"Titolo";
    tabHeader2<<"Comune";
    tabHeader2<<"Regione";
    tabHeader2<<"Inizio";
    tabHeader2<<"Fine";
    tabHeader2<<"Descrizione";
    table_competenze->setHorizontalHeaderLabels(tabHeader2);
    table_competenze->setMinimumWidth(320);

    label_competenze=new QLabel("COMPETENZE");
    label_competenze->setFont(QFont("Helvetica [Cronyx]", 18, QFont::Bold));
    label_competenze->setStyleSheet("font-variant: small-caps");

    layout_dx=new QVBoxLayout();
    layout_dx->addWidget(label_competenze,0,Qt::AlignLeft);
    layout_dx->addWidget(table_competenze);
    layout_dx->addWidget(cancella,0,Qt::AlignLeft);
    layout_dx->addWidget(label_community,0,Qt::AlignLeft);
    layout_dx->addLayout(layout_community);
    //Fine Layout dx

    //layout totale
    layout_dxsx=new QHBoxLayout(this);
    layout_dxsx->addWidget(scroll_area);
    layout_dxsx->addLayout(layout_dx);

    //funzioni
    datiPersonaliDisable();

    //connect
    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(clear,SIGNAL(clicked()),this,SLOT(clearCompetenze()));
    connect(modifica_applica,SIGNAL(clicked()),this,SLOT(datiPersonaliEnable()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(clearDatiPersonali()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(datiPersonaliDisable()));    
    connect(titolo,SIGNAL(textChanged(QString)),this,SLOT(enabledDisableAccetta()));
    connect(titolo,SIGNAL(editingFinished()),this,SLOT(enabledDisableAccetta()));
    connect(accetta,SIGNAL(clicked()),this,SLOT(competenzeIn()));
    connect(accetta,SIGNAL(clicked()),this,SLOT(clearCompetenze()));
    connect(inizio,SIGNAL(dateChanged(QDate)),this,SLOT(enabledDisableAccetta()));
    connect(fine,SIGNAL(dateChanged(QDate)),this,SLOT(enabledDisableAccetta()));
    connect(inserisci_lingua,SIGNAL(textChanged(QString)),this,SLOT(enableDisableLingua()));
    connect(inserisci_lingua,SIGNAL(editingFinished()),this,SLOT(enableDisableLingua()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(linguaIn()));
    connect(rimuovi,SIGNAL(clicked()),this,SLOT(removeLinguaOut()));
    connect(table_lingue,SIGNAL(cellClicked(int,int)),this,SLOT(selectLingua(int)));
    connect(table_competenze,SIGNAL(cellClicked(int,int)),this,SLOT(selectCompetenza(int)));
    connect(cancella,SIGNAL(clicked()),this,SLOT(removeCompetenzaOut()));
    connect(table_competenze,SIGNAL(cellDoubleClicked(int,int)),SLOT(descrioneOut(int)));

    connect(ricerca,SIGNAL(textEdited(QString)),this,SLOT(searchUser(QString)));

    connect(table_rete_ricerca,SIGNAL(cellClicked(int,int)),this,SLOT(selectContatto(int)));
    connect(aggiungi,SIGNAL(clicked()),this,SLOT(addContattoOut()));
    connect(mostra,SIGNAL(clicked()),this,SIGNAL(seeRete()));
    connect(elimina,SIGNAL(clicked()),this,SLOT(removeReteOut()));

    connect(table_competenze,SIGNAL(cellClicked(int,int)),this,SLOT(enabledDisableCancella()));
    connect(table_competenze,SIGNAL(cellClicked(int,int)),this,SLOT(modificaCompetenza(int)));

    connect(table_lingue,SIGNAL(cellClicked(int,int)),this,SLOT(enabledDisableRimuovi()));
    connect(table_rete_ricerca,SIGNAL(cellClicked(int,int)),this,SLOT(enabledDisableElimina()));

    this->setMinimumHeight(750);
    this->setMinimumWidth(1150);
}

void ClientView::modificaCompetenza(int row)
{
    titolo->setText(table_competenze->item(row,0)->text());
    comune->setText(table_competenze->item(row,1)->text());
    regione->setText(table_competenze->item(row,2)->text());

    QDate in=QDate::fromString(table_competenze->item(row,3)->text(),"dd/MM/yyyy");
    inizio->setDate(in);

    QDate fin=QDate::fromString(table_competenze->item(row,4)->text(),"dd/MM/yyyy");
    inizio->setDate(fin);

    descrizione->setText(table_competenze->item(row,5)->text());

}

void ClientView::enabledDisableElimina()
{
    if(user_selezionata.isEmpty())
    {
        elimina->setDisabled(true);
        aggiungi->setDisabled(true);
    }
    else
    {
        elimina->setEnabled(true);
        aggiungi->setEnabled(true);
    }
}

void ClientView::enabledDisableRimuovi()
{
    if(lingua_selezionata.isEmpty())
        rimuovi->setDisabled(true);
    else
        rimuovi->setEnabled(true);
}

void ClientView::enabledDisableCancella()
{
    if(Competenza_selezionata.isEmpty())
        cancella->setDisabled(true);
    else
        cancella->setEnabled(true);
}

void ClientView::removeReteOut()
{
    emit sendRemoveRete(user_selezionata);
    elimina->setDisabled(true);
    aggiungi->setDisabled(true);
}

void ClientView::buildRete(Rete::rete_const_iterator &inizio, Rete::rete_const_iterator &fine)
{
    clearSearch();
    int row=0;
    table_rete_ricerca->setColumnCount(1);
    for(Rete::rete_const_iterator it=inizio; it!=fine; ++it)
    {
        table_rete_ricerca->setRowCount(row+1);
        QTableWidgetItem *tit = new QTableWidgetItem(*it);
        table_rete_ricerca->setItem(row,0,tit);
        row++;
    }
}

void ClientView::addContattoOut()
{
    emit sendAddContatto(user_selezionata);
    elimina->setDisabled(true);
    aggiungi->setDisabled(true);
}

void ClientView::selectContatto(int row)
{
    user_selezionata=table_rete_ricerca->item(row,0)->text();
}

void ClientView::clearSearch()
{
    user_selezionata="";
    table_rete_ricerca->clearContents();
    table_rete_ricerca->setRowCount(0);
}

void ClientView::buildSearch(const QList<const SmartChangeType *> &lista)
{
    clearSearch();
    int row=0;
    table_rete_ricerca->setColumnCount(3);
    QStringList tabHeader;
    tabHeader<<"Username";
    tabHeader<<"Cognome";
    tabHeader<<"Nome";
    table_rete_ricerca->setHorizontalHeaderLabels(tabHeader);
    if(!(lista.isEmpty()))
        for(QList<const SmartChangeType*>::ConstIterator it=lista.begin(); it!=lista.end(); ++it)
        {
            table_rete_ricerca->setRowCount(row+1);
            QTableWidgetItem *user = new QTableWidgetItem((*it)->getPointer()->getUsername());
            QTableWidgetItem *cogn = new QTableWidgetItem((*it)->getPointer()->getCognome());
            QTableWidgetItem *nm = new QTableWidgetItem((*it)->getPointer()->getNome());
            table_rete_ricerca->setItem(row,0,user);
            table_rete_ricerca->setItem(row,1,cogn);
            table_rete_ricerca->setItem(row,2,nm);
            row++;
        }
}


void ClientView::searchUser(const QString& u)
{
    emit sendsearchUser(u);
}

void ClientView::removeCompetenzaOut()
{
    emit sendRemoveCompetenza(Competenza_selezionata);
    cancella->setDisabled(true);
}

void ClientView::selectCompetenza(int row)
{
    Competenza_selezionata=table_competenze->item(row,0)->text();
}

void ClientView::clearTableCompetenze()
{
    Competenza_selezionata="";
    table_competenze->clearContents();
    table_competenze->setRowCount(0);
}

void ClientView::buildCompetenze(competenze::competenze_const_iterator &inizio, competenze::competenze_const_iterator &fine)
{
    clearTableCompetenze();
    int row=0;
    for(competenze::competenze_const_iterator it=inizio; it!=fine; ++it)
    {
        table_competenze->setRowCount(row+1);
        QTableWidgetItem *tit = new QTableWidgetItem(it->getTitolo());
        QTableWidgetItem *com = new QTableWidgetItem(it->getComune());
        QTableWidgetItem *reg = new QTableWidgetItem(it->getRegione());
        QTableWidgetItem *ini = new QTableWidgetItem(it->dateInizio().toString("dd/MM/yyyy"));
        QTableWidgetItem *fin = new QTableWidgetItem(it->dateFine().toString("dd/MM/yyyy"));
        QTableWidgetItem *desc = new QTableWidgetItem(it->getDescrizione());
        table_competenze->setItem(row,0,tit);
        table_competenze->setItem(row,1,com);
        table_competenze->setItem(row,2,reg);
        table_competenze->setItem(row,3,ini);
        table_competenze->setItem(row,4,fin);
        table_competenze->setItem(row,5,desc);
        row++;
    }
}

void ClientView::selectLingua(int row)
{
    lingua_selezionata=table_lingue->item(row,0)->text();
}

void ClientView::removeLinguaOut()
{
    emit sendRemoveLingua(lingua_selezionata);
    rimuovi->setDisabled(true);
}

void ClientView::clearTableLingue()
{
    lingua_selezionata="";
    table_lingue->clearContents();
    table_lingue->setRowCount(0);
}

void ClientView::buildLingua(Lingue::lingua_const_iterator &inizio, Lingue::lingua_const_iterator &fine)
{
    clearTableLingue();
    int row=0;
    for(Lingue::lingua_const_iterator it=inizio; it!=fine; ++it)
    {
        table_lingue->setRowCount(row+1);
        QTableWidgetItem *lg = new QTableWidgetItem((*it));
        table_lingue->setItem(row,0,lg);
        row++;
    }
}

void ClientView::linguaIn()
{
    emit sendLingua(inserisci_lingua->text());
    inserisci_lingua->clear();
    rimuovi->setDisabled(true);
}

void ClientView::enableDisableLingua()
{
    if(inserisci_lingua->text().isEmpty())
        inserisci->setDisabled(true);
    else
        inserisci->setEnabled(true);
}

void ClientView::stampaTypeTitolo(const QString &tit, const QString &tp)
{
    username_title->setText(tit);
    type_accountl->setText(tp);
}

void ClientView::competenzeIn()
{
    cancella->setDisabled(true);
    emit competenzeOut(titolo->text(),comune->text(),regione->text(),
                       inizio->date(),fine->date(),descrizione->toPlainText());

}

void ClientView::enabledDisableAccetta()
{
    fine->setMinimumDate(inizio->date());
    if(titolo->text().isEmpty())
        accetta->setDisabled(true);
    else
        accetta->setEnabled(true);
}

void ClientView::clearCompetenze()
{
    titolo->clear();
    comune->clear();
    regione->clear();

    inizio->clear();
    fine->clear();

    descrizione->clear();
}


void ClientView::editingIn()
{
    QString cogn ="";
    QString nm ="";
    QDate dt_nasc =QDate();
    QString c_nasc ="";
    QString r_nasc ="";
    QString i_res ="";
    QString c_res ="";
    QString r_res ="";

    if(!(cognome->text().isEmpty()))
        cogn=cognome->text();
    else
        cogn=cognome->placeholderText();

    if(!(nome->text().isEmpty()))
        nm=nome->text();
    else
        nm=nome->placeholderText();

    dt_nasc=data_nascita->date();

    if(!(comune_nasc->text().isEmpty()))
        c_nasc=comune_nasc->text();
    else
        c_nasc=comune_nasc->placeholderText();

    if(!(regione_nasc->text().isEmpty()))
        r_nasc=regione_nasc->text();
    else
        r_nasc=regione_nasc->placeholderText();

    if(!(indirizzo_res->text().isEmpty()))
        i_res=indirizzo_res->text();
    else
        i_res=indirizzo_res->placeholderText();

    if(!(comune_res->text().isEmpty()))
        c_res=comune_res->text();
    else
        c_res=comune_res->placeholderText();

    if(!(regione_res->text().isEmpty()))
        r_res=regione_res->text();
    else
        r_res=regione_res->placeholderText();
    emit sendEditingIn(cogn,nm,dt_nasc,c_nasc,r_nasc,i_res,c_res,r_res);
}

void ClientView::clearDatiPersonali()
{
    cognome->clear();
    nome->clear();
    comune_nasc->clear();
    regione_nasc->clear();
    indirizzo_res->clear();
    comune_res->clear();
    regione_res->clear();

}

void ClientView::getClient(const QString &cogn, const QString &nm, const QDate &dt_nasc,
                           const QString &c_nasc,const QString &r_nasc, const QString &i_res,
                           const QString &c_res, const QString &r_res)
{
    cognome->setPlaceholderText(cogn);
    nome->setPlaceholderText(nm);
    data_nascita->setDate(dt_nasc);

    comune_nasc->setPlaceholderText(c_nasc);
    regione_nasc->setPlaceholderText(r_nasc);
    indirizzo_res->setPlaceholderText(i_res);
    comune_res->setPlaceholderText(c_res);
    regione_res->setPlaceholderText(r_res);
}


void ClientView::datiPersonaliEnable()
{
    cognome->setEnabled(true);
    nome->setEnabled(true);
    data_nascita->setEnabled(true);
    comune_nasc->setEnabled(true);
    regione_nasc->setEnabled(true);
    indirizzo_res->setEnabled(true);
    comune_res->setEnabled(true);
    regione_res->setEnabled(true);

    annulla->setHidden(false);
    modifica_applica->setText("Applica");

    disconnect(modifica_applica,SIGNAL(clicked()),this,SLOT(datiPersonaliEnable()));
    connect(modifica_applica,SIGNAL(clicked()),this,SLOT(editingIn()));
    connect(modifica_applica,SIGNAL(clicked()),this,SLOT(clearDatiPersonali()));
    connect(modifica_applica,SIGNAL(clicked()),this,SLOT(datiPersonaliDisable()));
}

 void ClientView::datiPersonaliDisable()
 {
     cognome->setDisabled(true);
     nome->setDisabled(true);
     data_nascita->setDisabled(true);
     comune_nasc->setDisabled(true);
     regione_nasc->setDisabled(true);
     indirizzo_res->setDisabled(true);
     comune_res->setDisabled(true);
     regione_res->setDisabled(true);

     annulla->setHidden(true);
     modifica_applica->setText("Modifica");

     disconnect(modifica_applica,SIGNAL(clicked()),this,SLOT(clearDatiPersonali()));
     disconnect(modifica_applica,SIGNAL(clicked()),this,SLOT(datiPersonaliDisable()));
     disconnect(modifica_applica,SIGNAL(clicked()),this,SLOT(editingIn()));
     connect(modifica_applica,SIGNAL(clicked()),this,SLOT(datiPersonaliEnable()));
 }


 void ClientView::descrioneOut(int row)
 {
     QString s="";
     s=table_competenze->item(row,5)->text();
     if(!(s.isEmpty()))
     {
     QMessageBox warning;
     warning.setIcon(QMessageBox::Question);
     warning.setWindowTitle("Descrizione competenza");
     warning.setInformativeText(s);
     warning.setStandardButtons(QMessageBox::Close);
     warning.setDefaultButton(QMessageBox::Cancel);
     warning.exec();
     }
 }

 void ClientView::readMode() const
 {
    disconnetti->setHidden(true);
    esci->setHidden(true);
    modifica_applica->setHidden(true);
    clear->setHidden(true);
    accetta->setHidden(true);
    inserisci->setHidden(true);
    rimuovi->setHidden(true);
    cancella->setHidden(true);
    inserisci_lingua->setHidden(true);

    GroupBox_competenze->setHidden(true);

    GroupBox_rete->setHidden(true);
    GroupBox_ricerca->setHidden(true);
 }
