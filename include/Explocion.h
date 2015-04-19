#ifndef EXPLOCION_H
#define EXPLOCION_H
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CLASE EXPLOCION                     ///
 ///               SUPERCLASE: DIBUJO                   ///
 ///     FUNCIONALIDAD: DIBUJAR EN POSICION X,Y HASTA   ///
 ///                    QUE EL TEMPORIZADOR LLEGUE A 0  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class Explocion:public Dibujo
{
    public:
        Explocion();
        void Dibujar(BITMAP *);
        void setTemporizador(int);
        int getTemporizador();
        virtual ~Explocion();
    protected:
    private:
        int temporizador;
};

#endif // EXPLOCION_H
