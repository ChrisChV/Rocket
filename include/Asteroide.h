#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                  CLASE ASTEROIDE                   ///
 ///                SUPERCLASE: DIBUJO                  ///
 ///   FUNCIONALIDADES: DIBUJAR DE ARRIBA HACIA ABAJO   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


class Asteroide:public Dibujo
{
    public:
        Asteroide();
        virtual void Dibujar(BITMAP *);
        void setAstesiguiente(Asteroide *);
        void setVidasIniciales (int);
        void setVelocidad(float);
        void setAsteatras(Asteroide *);
        virtual ~Asteroide();
    protected:
        int vidasiniciales;
    private:

};

#endif // ASTEROIDE_H
