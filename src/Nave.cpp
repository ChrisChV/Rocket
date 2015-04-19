#include "Nave.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CONSTRUCTOR DEFAULT                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Nave::Nave()
{
    setDibujo("recursos/nave.bmp");
    this->x=400;
    this->y=300;
    this->vidas=3;
    this->Marco->setCuadro(this->x-20,this->x+50,this->y+35,this->y+100);
    this->etiqueta='n';
    this->velocidad=1;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///              FUNCIONES DIBUJAR <TECLA>             ///
 ///    FUNCIONALIDAD: CAMBIAR LAS CORDENADA SEGUN LA   ///
 ///                   TECLA PRECIONADA                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Nave::dibujarAbajo(){
    if (this->y<500){
        this->y+=this->velocidad;
    this->Marco->setCuadro(this->x-20,this->x+50,this->y+35,this->y+100);
    }
}
void Nave::dibujarArriba(){
    if (this->y>0){
        this->y-=this->velocidad;
            this->Marco->setCuadro(this->x-20,this->x+50,this->y+35,this->y+100);
    }
}
void Nave::dibujarDerecha(){
    if (this->x<690){
        this->x+=this->velocidad;
            this->Marco->setCuadro(this->x-20,this->x+50,this->y+35,this->y+100);
    }
}
void Nave::dibujarIzquierda(){
    if (this->x>-40){
        this->x-=this->velocidad;
            this->Marco->setCuadro(this->x-20,this->x+50,this->y+35,this->y+100);
    }
}

Nave::~Nave()
{

}
