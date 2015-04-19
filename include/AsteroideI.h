#ifndef ASTEROIDEI_H
#define ASTEROIDEI_H
#include "Asteroide.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///        CLASE ASTEROIDEI (ASTEROIDE IZQUIERDA)      ///
 ///                SUPERCLASE: ASTERODIE               ///
 ///   FUNCIONALIDADES: DIBUJAR DE IZQUIERDA A DERECHA  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


class AsteroideI:public Asteroide
{
    public:
        AsteroideI();
        void Dibujar(BITMAP *);
        virtual ~AsteroideI();
    protected:
    private:
};

#endif // ASTEROIDEI_H
