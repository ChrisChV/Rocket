#ifndef POWERUPS_H
#define POWERUPS_H
#include <allegro.h>
#include "Asteroide.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                  CLASE POWERUPS                    ///
 ///                SUPERCLASE: ASTEROIDE               ///
 ///   FUNCIONALIDAD: DIBUJAR DE ARRIBA HACIA ABAJO     ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


class PowerUps:public Asteroide
{
    public:
        PowerUps(int,int);
        void Dibujar(BITMAP *);
        virtual ~PowerUps();
    protected:
    private:
        int x3,y3;
};

#endif // POWERUPS_H
