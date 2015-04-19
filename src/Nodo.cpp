#include "Nodo.h"
#include "Lista.h"
void Nodo::Dibujar(BITMAP* x){}
bool Nodo::getDisparo(){return false;}
Nodo* Nodo::getAtras(){return this->atras;}
Nodo* Nodo::getSiguiente(){return this->siguiente;}
Nodo::~Nodo()
{
    //dtor
}
