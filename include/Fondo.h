#ifndef FONDO_H
#define FONDO_H
#include <allegro.h>
#include "Dibujo.h"
class Fondo:public Dibujo
{
    public:
        Fondo();
        BITMAP* getBITMAP();
        virtual ~Fondo();
    protected:
    private:
};

#endif // FONDO_H
