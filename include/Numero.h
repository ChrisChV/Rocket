#ifndef NUMERO_H
#define NUMERO_H
#include "Dibujo.h"

class Numero:public Dibujo
{
    public:
        Numero(char x);
        virtual ~Numero();
    protected:
    private:
        int numero;
};

#endif // NUMERO_H
