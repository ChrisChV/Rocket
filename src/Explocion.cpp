#include "Explocion.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CONSTRUCTOR DEFAULT                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Explocion::Explocion()
{
    setDibujo("recursos/boom.bmp");
    temporizador=200;
    this->etiqueta='b';
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION DIBUJAR                     ///
 ///        DATO DE ENTRADA: EL BUFFER                  ///
 ///    FUNCIONALIDAD:  DIBAJAR EN LA POSICION X,Y      ///
 ///                    HASTA QUE EL TEMPORIZADOR       ///
 ///                    LLEGUE A 0.                     ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Explocion::Dibujar(BITMAP *b){
    if (this->Crear){
        if(this->temporizador!=0){
            draw_sprite(b,this->dibujo,this->x,this->y);
            this->temporizador--;
        }
        else {this->Crear=false;}
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 SETERS Y GETERS                    ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

int Explocion::getTemporizador(){return this->temporizador;}
void Explocion::setTemporizador(int x){
    if (temporizador==0){
        this->temporizador=x;
    }
}

Explocion::~Explocion()
{

}
