#include "Estrella.h"
#include <allegro.h>
#include <cstdlib>

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CONSTRUCTOR DEFAULT                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Estrella::Estrella()
{
    setDibujo("recursos/estrellita.bmp");
    this->etiqueta='e';
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION DIBUJAR                     ///
 ///        DATO DE ENTRADA: EL BUFFER                  ///
 ///    FUNCIONALIDAD:  DIBAJAR SI ESTA DENTRO DE LA    ///
 ///                    PANTALLA DE ARRIBA A ABAJO.     ///
 ///                    CUANDO SALGA DE ESTA, VOLVER A  ///
 ///                    DIBUJARLA EN POSICION RANDOM    ///
 ///                    ARRIBA.                         ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Estrella::Dibujar(BITMAP * b){
    if(this->y<620){
        draw_sprite(b,this->dibujo,this->x,this->y);
        this->y+=1.5;
    }
    else{
        this->x=rand()%800;
        this->y=-40;
    }
}
Estrella::~Estrella()
{

}
