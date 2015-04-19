#include "Dibujo.h"
#include "sad.h"


 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 CONSTRUCTOR DEFAULT                ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


Dibujo::Dibujo()
{
    this->x=0;
    this->y=0;
    this->siguiente=NULL;
    this->atras=NULL;
    this->Marco =new MarcoColicion();
    this->Crear=true;
    this->etiqueta='i';
    this->mismoatras=NULL;
    this->mismosiguiente=NULL;
    this->puntos=10;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///         CONSTRUCTOR CAMBIA LA ETIQUETA             ///
 ///      DATO DE ENTRADA: ETIQUETA EN FORMA DE CHAR    ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Dibujo::Dibujo(char x){
    this->x=0;
    this->y=0;
    this->siguiente=NULL;
    this->atras=NULL;
    Marco =new MarcoColicion();
    this->Crear=true;
    this->etiqueta=x;
    this->mismoatras=NULL;
    this->mismosiguiente=NULL;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 FUNCION DIBUJAR                    ///
 ///            DATO DE ENTRADA: EL BUFFER              ///
 ///   FUNCIONALIDAD: DIBUJA EN SUS COORDDENADAS X, Y   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Dibujo::Dibujar(BITMAP* b){
    if (this->Crear){
        draw_sprite(b,this->dibujo,this->x,this->y);
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION COLICIÓN                    ///
 ///               VERIFICA COLICIONES                  ///
 ///    DATO DE ENTRADA: DIBUJO CON EL QUE COLICIONA    ///
 ///    DATO DE SALIDA: BOOLEANO TRUE/FALSE             ///
 ///    FUNCIONALIDAD: COMPARA LAS 4 COORDENADAS DEL    ///
 ///                   MARCO DE COLICIÓN                ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


bool Dibujo::Colicion(Dibujo* d){
    if (((this->Marco->getY1()<d->getMarco()->getY2() && this->Marco->getX1()<d->getMarco()->getX2())
        &&(this->Marco->getY1()<d->getMarco()->getY2() && this->Marco->getX2()>d->getMarco()->getX1())
        &&(this->Marco->getY2()>d->getMarco()->getY1() && this->Marco->getX2()>d->getMarco()->getX1())
        &&(this->Marco->getY2()>d->getMarco()->getY1() && this->Marco->getX1()<d->getMarco()->getX2())))
        {
            return true;
        }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 SETERS Y GETERS                    ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////



BITMAP* Dibujo::getBITMAP(){return this->dibujo;}
MarcoColicion* Dibujo::getMarco(){return this->Marco;}
int Dibujo::getX(){return this->x;}
int Dibujo::getY(){return this->y;}
int Dibujo::getVidas(){return this->vidas;}
bool Dibujo::getCrear(){return this->Crear;}
void Dibujo::setCrear(bool x){this->Crear=x;}
void Dibujo::setX(int v){this->x=v;}
void Dibujo::setY(int v){this->y=v;}
void Dibujo::setVidas(int x){this->vidas=x;}
void Dibujo::setPuntos(int x){this->puntos=x;}
void Dibujo::setEtiqueta(char x) {this->etiqueta=x;}
void Dibujo::setDibujo(const char *c){this->dibujo=load_bitmap(c,NULL);}


 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                    DESTRUCTOR                      ///
 ///        DESTRUYE SU BITMAP CORRESPONDIENTE          ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


Dibujo::~Dibujo()
{
    destroy_bitmap(this->dibujo);
}
