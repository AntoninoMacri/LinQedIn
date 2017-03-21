#include "smartutente.h"

SmartUtente::SmartUtente():ptr(0){}

SmartUtente::SmartUtente(Utente* p):ptr(p){}

SmartUtente::SmartUtente(const SmartUtente& sm):ptr(sm.ptr->clone()){}  //aggiungo un metodo virtuale clone() per permettere questa operazione

SmartUtente::~SmartUtente(){ delete ptr;}

SmartUtente& SmartUtente::operator =(const SmartUtente& sm)
{ if(this!=&sm){ delete ptr;  ptr=sm.ptr;  } return *this; }

Utente* SmartUtente::getPointer() const{ return ptr;}

void SmartUtente::setPointer(Utente* u)
{ if(ptr!=u){ delete ptr; ptr=u; } }

Utente& SmartUtente::operator *() const{ return *ptr;}

Utente* SmartUtente::operator ->() const{ return ptr;}

