#include "PowerUps.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///               CONSTRUCTOR DEFAULT                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

PowerUps::PowerUps(int x,int y)
{
    this->Crear=false;
    this->x3=x;
    this->y3=y;
    this->Marco->setCuadro(this->x-50,this->x+this->x3,this->y,this->y+this->y3);
    this->vidas=1;
    this->vidasiniciales=1;
    this->velocidad=1;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION DIBUJAR                     ///
 ///         DATO DE ENTRADA: EL BUFFER                 ///
 ///   FUNCIONALIDAD: DIBUJAR DE ABAJO HACIA ARRIBA     ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void PowerUps::Dibujar(BITMAP *b){
    if (this->Crear){
        if(this->y<620){
            draw_sprite(b,this->dibujo,this->x,this->y);
            this->y+=this->velocidad;
            this->Marco->setCuadro(this->x-50,this->x+this->x3,this->y,this->y+this->y3);
        }
        else{
            this->vidas=this->vidasiniciales;
            this->x=rand()%700;
            this->y=-1*(rand()% 1 + 600);
            this->Marco->setCuadro(this->x-50,this->x+this->x3,this->y,this->y+this->y3);
        }
    }
    else{
        this->vidas=this->vidasiniciales;
        this->x=rand()%700;
        this->y=-1*(rand()% 1 + 600);
        this->Marco->setCuadro(this->x-50,this->x+this->x3,this->y,this->y+this->y3);
    }


}

PowerUps::~PowerUps()
{
}
