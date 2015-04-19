#ifndef NODO_H
#define NODO_H
#include "Lista.h"
#include <allegro.h>
#include <iostream>
class Nodo
{
    public:
        Nodo(){this->siguiente=NULL,this->atras=NULL;}
        void Dibujar(BITMAP*);
        bool getDisparo();
        Nodo* getSiguiente();
        Nodo* getAtras();
        friend class Lista;
        virtual ~Nodo();
    protected:
        Nodo *siguiente,*atras;

};

#endif // NODO_H
