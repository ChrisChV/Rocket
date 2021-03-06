#include "AsteroideD.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CONSTRUCTOR DEFAULT                 ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

AsteroideD::AsteroideD()
{
    setDibujo("recursos/asteamarillo.bmp");
    this->x=-100;
    this->y=0;
    this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
    this->etiqueta='a';
    this->vidas=1;
    this->vidasiniciales=1;
    this->velocidad=1.8;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION DIBUJAR                     ///
 ///        DATO DE ENTRADA: EL BUFFER                  ///
 ///    FUNCIONALIDAD:  DIBAJAR SI ESTA DENTRO DE LA    ///
 ///                    PANTALLA DE DERECHA A IZQUIERDA.///
 ///                    CUANDO SALGA DE ESTA, VOLVER A  ///
 ///                    DIBUJARLA EN POSICION RANDOM    ///
 ///                    EN LA DERECHA.                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


void AsteroideD::Dibujar(BITMAP *b){
    if (this->Crear){
        if(this->x>-400){
            draw_sprite(b,this->dibujo,this->x,this->y);
            this->x-=this->velocidad;
            this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
        }
        else{
            this->vidas=this->vidasiniciales;
            this->x=rand()%1 + 1500;
            this->y=rand()%500;
            this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
        }
    }
    else{
        this->Crear=true;
        this->vidas=this->vidasiniciales;
        this->x=rand()%1 + 1500;
        this->y=rand()%500;
        this->Marco->setCuadro(this->x-50,this->x+30,this->y,this->y+100);
    }
}

AsteroideD::~AsteroideD()
{
}
