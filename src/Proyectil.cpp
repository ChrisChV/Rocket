#include "Proyectil.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 CONSTRUCTOR DEFAULT                ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


Proyectil::Proyectil()
{
    setDibujo("recursos/proyectil1.bmp");
    this->Marco->setCuadro(this->x+6,this->x+24,this->y+4,this->y+24);
    this->etiqueta='p';
    this->velocidad=200;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 FUNCION DIBUJAR                    ///
 ///           DATO DE ENTRADA: EL BUFFER               ///
 ///    FUNCIONALIDAD: DIBUJAR EL OBJETO DE ABAJO A     ///
 ///                   ARRIBA                           ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Proyectil::Dibujar(BITMAP *b){
    if(this->Crear){
        if(this->y>-20){
            draw_sprite(b,this->dibujo,this->x+60,this->y);
            this->y-=1;
            this->Marco->setCuadro(this->x+6,this->x+24,this->y+4,this->y+24);
        }
        else{this->Crear=false;}
    }
}
Proyectil::~Proyectil()
{

}
