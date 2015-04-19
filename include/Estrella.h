#ifndef ESTRELLA_H
#define ESTRELLA_H
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                   CLASE ESTRELLA                   ///
 ///                 SUPERCLASE: DIBUJO                 ///
 ///   FUNCIONALIDADES: DIBUJAR DE ARRIBA HACIA ABAJO   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class Estrella:public Dibujo
{
    public:
        Estrella();
        void Dibujar(BITMAP *);
        virtual ~Estrella();
    protected:
    private:
};

#endif // ESTRELLA_H
