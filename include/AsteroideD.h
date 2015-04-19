#ifndef ASTEROIDED_H
#define ASTEROIDED_H
#include "Asteroide.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///        CLASE ASTEROIDED (ASTEROIDE DERECHA)        ///
 ///               SUPERCLASE: ASTEROIDE                ///
 ///   FUNCIONALIDADES: DIBUJAR DE DERECHA A IZQUIERDA  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


class AsteroideD:public Asteroide
{
    public:
        AsteroideD();
        void Dibujar(BITMAP *);
        virtual ~AsteroideD();
    protected:
    private:
};

#endif // ASTEROIDED_H
