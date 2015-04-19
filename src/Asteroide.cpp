#include "Asteroide.h"
#include "sad.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CONSTRUCTOR DEFAULT                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Asteroide::Asteroide()
{
    setDibujo("recursos/aste.bmp");
    this->x=-100;
    this->y=0;
    this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
    this->etiqueta='a';
    this->vidas=1;
    this->vidasiniciales=1;
    this->velocidad=1;
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

void Asteroide::Dibujar(BITMAP *b){
    if (this->Crear){
        if(this->y<620){
            draw_sprite(b,this->dibujo,this->x,this->y);
            this->y+=this->velocidad;
            this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
        }
        else{
            this->vidas=this->vidasiniciales;
            this->x=rand()%700;
            this->y=-1*(rand()% 1 + 600);
            this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
        }
    }
    else{
        this->Crear=true;
        this->vidas=this->vidasiniciales;
        this->x=rand()%700;
        this->y=-1*(rand()% 1 + 600);
        this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                  SETERS Y GETERS                   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


void Asteroide::setVidasIniciales(int x){this->vidasiniciales=x;}
void Asteroide::setVelocidad(float x){this->velocidad=x;}

Asteroide::~Asteroide()
{

}
