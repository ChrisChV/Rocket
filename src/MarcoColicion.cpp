#include "MarcoColicion.h"

MarcoColicion::MarcoColicion()
{

}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 SETERS Y GETTERS                   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void MarcoColicion::setCuadro(int a,int b,int c,int d){
    this->x1=a;
    this->x2=b;
    this->y1=c;
    this->y2=d;
}

int MarcoColicion::getX1(){return this->x1;}
int MarcoColicion::getX2(){return this->x2;}
int MarcoColicion::getY1(){return this->y1;}
int MarcoColicion::getY2(){return this->y2;}
MarcoColicion::~MarcoColicion()
{
    //dtor
}
