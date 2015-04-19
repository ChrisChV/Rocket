#ifndef DIBUJO_H
#define DIBUJO_H
#include "MarcoColicion.h"
#include <allegro.h>


 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                    CLASE DIBUJO                    ///
 ///                  SUPERCLASE: NONE                  ///
 ///       FUNCIONALIDADES: DIBUJAR                     ///
 ///                        VERIFICAR COLICIONES        ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class MarcoColicion;

class Dibujo
{
    public:
        Dibujo();
        Dibujo(char x);
        BITMAP* getBITMAP();
        MarcoColicion * getMarco();
        virtual void Dibujar(BITMAP*);
        int getX();
        int getY();
        int getVidas();
        bool Colicion(Dibujo*);
        bool getCrear();
        virtual void setX(int x);
        virtual void setY(int y);
        void setDibujo(const char *);
        void setCrear(bool);
        void setVidas(int);
        void setPuntos(int);
        void setEtiqueta(char);
        friend class Game;
        virtual ~Dibujo();
    protected:
        BITMAP *dibujo;
        float x;
        float y;
        float velocidad;
        int vidas;
        int puntos;
        int posicion;
        char etiqueta;
        bool Crear;
        Dibujo *siguiente;
        Dibujo *atras;
        Dibujo *mismosiguiente;
        Dibujo *mismoatras;
        MarcoColicion *Marco;
    private:
};

#endif // DIBUJO_H

