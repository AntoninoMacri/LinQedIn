#include "utentepay.h"

UtentePay::UtentePay(const QString& cc): credit_card(cc){}

UtentePay::UtentePay(const QString& cogn, const QString& n,
                     const QString& usr, const QString& cc): Utente(cogn,n,usr), credit_card(cc){}

UtentePay::UtentePay(const Utente& u, const QString& cc): Utente(u), credit_card(cc){}


QString UtentePay::getCredit_Card() const{ return credit_card; }

void UtentePay::setCredit_Card(const QString& cc){ credit_card=cc; }
