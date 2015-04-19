#ifndef NAVE_H
#define NAVE_H
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                    CLASE NAVE                      ///
 ///                SUPERCLASE: DIBUJO                  ///
 ///        FUNCIONALIDADES: CAMBIAR SUS CORDENADA      ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class Nave:public Dibujo
{
    public:
        Nave();
        void dibujarDerecha();
        void dibujarIzquierda();
        void dibujarArriba();
        void dibujarAbajo();
        virtual ~Nave();
    protected:
    private:

};

#endif // NAVE_H
