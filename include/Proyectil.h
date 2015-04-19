#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <allegro.h>
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CLASE PROYECTIL (BALA)              ///
 ///                  SUPERCLASE: DIBUJO                ///
 ///     FUNCIONALIDADES: DIBUJAR DE ABAJO A ARRIBA     ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class Proyectil:public Dibujo
{
    public:
        Proyectil();
        void Dibujar(BITMAP *);
        virtual ~Proyectil();
    protected:
    private:
};

#endif // PROYECTIL_H
