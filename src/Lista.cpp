#include "Lista.h"
#include "sad.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///               CONTRUCTOR DEFAULT                   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


Game::Game(){
    this->elementos=0;
    this->balaactual=NULL;
    this->balainicio=NULL;
    this->temporal=NULL;
    this->puntaje=0;
    this->decena=0;
    this->centena=0;
    this->milesima=0;
    this->primerdecena=true;
    this->primercentena=true;
    this->primermilesima=true;
    this->asteinicio=NULL;
    this->vida=new Dibujo();
    this->velbala=200;
    this->sonidoexplocion=load_wav("recursos/explocion.wav");
    this->zelda=load_wav("recursos/zelda.wav");
}


 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 FUNCION INSERTAR                   ///
 ///       DATO DE ENTRADA: DIBUJO A INSERTAR           ///
 ///      FUNCIONALIDAD: INGRESA EL DIBUJO AL FINAL     ///
 ///                     DE LA LISTA.                   ///
 ///      FUNCIONES QUE LLAMA: INSERTAR ASTEROIDE       ///
 ///                           INSERTAR BALA            ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


void Game::insertar(Dibujo *nuevo){
    if (this->elementos==0){
        this->inicio=nuevo;
        this->actual=nuevo;
        this->elementos++;
        nuevo->posicion=this->elementos;
    }
    else{
        this->actual->siguiente=nuevo;
        nuevo->atras=this->actual;
        this->actual=nuevo;
        this->elementos++;
        nuevo->posicion=this->elementos;
        if(nuevo->etiqueta=='a'){
            this->InsertarAsteroide(nuevo);
        }
        if(nuevo->etiqueta=='p'){
            this->InsertarBala(nuevo);
        }
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///            FUNCION INSERTAR ASTEROIDE              ///
 ///        DATO DE ENTRADA: DIBUJO (ASTEROIDE)         ///
 ///    FUNCIONALIDAD: ENLAZAR EL ASTEROIDE INSERTADO   ///
 ///                   CON EL ASTEROIDE ANTERIOR A EL   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::InsertarAsteroide(Dibujo *aste){
    if(this->asteinicio==NULL){
        this->asteinicio=aste;
        this->asteactual=aste;
    }
    else{
        aste->mismoatras=this->asteactual;
        this->asteactual->mismosiguiente=aste;
        this->asteactual=aste;
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///            FUNCION INSERTAR BALA                   ///
 ///        DATO DE ENTRADA: DIBUJO (BALA)              ///
 ///    FUNCIONALIDAD: ENLAZAR LA BALA INSERTADA        ///
 ///                   CON LA BALA ANTERIOR A EL        ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


void Game::InsertarBala(Dibujo *bala){
    if(this->balainicio==NULL){
        this->balainicio=bala;
        this->balaactual=bala;
    }
    else{
        bala->mismoatras=this->balaactual;
        this->balaactual->mismosiguiente=bala;
        this->balaactual=bala;
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 FUNCION DIBUJAR                    ///
 ///            DATO DE ENTRADA: EL BUFFER              ///
 ///     FUNCIONALIDAD: LLAMA LA FUNCION DIBUJAR DE     ///
 ///                    TODOS LOS OBJETOS DIBUJO        ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::Dibujar(BITMAP *b){
    Dibujo *temp=this->inicio;
    while(temp){
        temp->Dibujar(b);
        temp=temp->siguiente;
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///             FUNCION ELIMINAR LISTA                 ///
 ///       FUNCIONALIDAD: ELIMINA TODOS LOS DIBUJOS     ///
 ///                      DE LA LISTA                   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::EliminarLista(){
    Dibujo *elem=this->inicio;
    while(elem){
        temporal=elem;
        elem=elem->siguiente;
        delete temporal;
    }
    temporal=NULL;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION ELIMINAR                    ///
 ///        DATO DE ENTRADA: DIBUJO A ELIMINAR          ///
 ///    FUNCIONALIDAD: ELIMINA EL DIBUJO DE LA LISTA    ///
 ///                   Y DE LA MEMORIA                  ///
 ///    FUNCIONES QUE LLAMA: ELIMINAR BALA              ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::Eliminar(Dibujo * x){
    if (x->etiqueta=='p'){
       this->EliminarBala(x);
    }
    if (this->inicio==x){
        this->inicio=x->siguiente;
    }
    if (this->actual==x){
        this->actual=this->actual->atras;
        this->actual->siguiente=NULL;
    }
    else{
        x->atras->siguiente=x->siguiente;
        x->siguiente->atras=x->atras;
    }
    this->elementos--;
    delete x;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                FUNCION ELIMINAR BALA               ///
 ///            DATO DE ENTRADA: DIBUJO (BALA)          ///
 ///       FUNCIONALIDAD: DESCENLAZAR LAS BALAS QUE     ///
 ///                      ESTAN ENLAZADAS AL DATO DE    ///
 ///                      ENTRADA                       ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::EliminarBala(Dibujo * x){
    if (this->balainicio==x){
        this->balainicio=x->mismosiguiente;
    }
    else if (this->balaactual==x){
        this->balaactual=this->balaactual->mismoatras;
        this->balaactual->mismosiguiente=NULL;
    }
    else{
        x->mismoatras->mismosiguiente=x->mismosiguiente;
        x->mismosiguiente->mismoatras=x->mismoatras;
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///              FUNCION VERIFICAR BALAS               ///
 ///     FUNCIONALIDAD: VERIFICA SI ALGUNA BALA DE LA   ///
 ///                    LISTA DEBE DE SER ELIMINADA     ///
 ///     FUNCIONES QUE LLAMA: ELIMINAR                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::VerificarBalas(){
    Dibujo *elem=this->balainicio;
    while(elem){
        if(elem->Crear==false){
            temporal=elem;
            elem=elem->mismosiguiente;
            this->Eliminar(temporal);
        }
        else{elem=elem->mismosiguiente;}
    }
    temporal=NULL;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                 FUNCION VERIFICAR                  ///
 ///     FUNCIONALIDAD: VERIFA SI ALGUN DIBUJO DEBE DE  ///
 ///                    SER ELIMINADO                   ///
 ///     FUNCIONES QUE LLAMA: ELIMINAR                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::Verificar(){
    Dibujo *elem=this->inicio;
    while(elem){
        if(elem->Crear==false && elem!=this->vida1 && elem!=this->vida2 && elem!=this->vida3 && elem!=this->vida && elem!=this->velocidadbala && elem!=this->velocidadnave){
            temporal=elem;
            elem=elem->siguiente;
            this->Eliminar(temporal);
        }
        else{elem=elem->siguiente;}
    }
    temporal=NULL;
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///           FUNCION VERIFICAR COLICIONES             ///
 ///      FUNCIONALIDAD: VERIFICA SI LA NAVE COLICIONA  ///
 ///                     CON ALGUN OBJETO.              ///
 ///                     VERIFICA SI ALGUNA BALA        ///
 ///                     COLICIONA CON ALGUN ASTEROIDE. ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////


void Game::VerificarColiciones(){
    //Dibujo *nave=this->Buscar('n',1);
    Dibujo *aste=this->asteinicio;
    if(nave->Colicion(this->vida)){
        play_sample(this->zelda,200,127,1000,0);
        this->vida->Crear=false;
        switch (nave->vidas){
            case 3: break;
            case 2: this->vida3->Crear=true;nave->vidas+=1;break;
            case 1: this->vida2->Crear=true;nave->vidas+=1;break;
        }
    }
    if(nave->Colicion(this->velocidadbala)){
        play_sample(this->zelda,200,127,1000,0);
        this->velocidadbala->Crear=false;
        if(velbala>10){
            this->velbala-=10;
        }
    }
    if(nave->Colicion(this->velocidadnave)){
        play_sample(this->zelda,200,127,1000,0);
        this->velocidadnave->Crear=false;
        nave->velocidad+=0.5;
    }
    while(aste){
        if(nave->Colicion(aste)){
            play_sample(this->sonidoexplocion,200,127,1000,0);
            Explocion *boom= new Explocion();
            boom->Crear=true;
            boom->setX(aste->getX());
            boom->setY(aste->getY());

            aste->Crear=false;
            insertar(boom);
            nave->vidas=nave->vidas -1;
            switch(nave->vidas){
                case 0: nave->setCrear(false);this->vida1->Crear=false;break;
                case 1: this->vida2->Crear=false;break;
                case 2: this->vida3->Crear=false;break;
            }
        }
        aste=aste->mismosiguiente;
    }
    Dibujo *aste2=this->asteinicio;
    Dibujo *bala=this->balainicio;
    while(aste2){
        while(bala){
            if(aste2->Colicion(bala)){
                play_sample(this->sonidoexplocion,200,30,1000,0);
                Explocion *explocion=new Explocion;
                explocion->setX(aste2->getX());
                explocion->setY(aste2->getY());
                insertar(explocion);
                aste2->vidas=aste2->vidas - 1;
                if(aste2->vidas==0){aste2->Crear=false;this->puntaje+=aste2->puntos;}
                bala->Crear=false;
            }
            bala=bala->mismosiguiente;
        }
        aste2=aste2->mismosiguiente;
        bala=this->balainicio;
    }
}

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                   SETERS Y GETTES                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

void Game::setPuntaje(int x){this->puntaje=x;}
int Game::getPuntaje(){return puntaje;}
void Game::setDecena(int x){this->decena=x;}
int Game::getDecena(){return this->decena;}
void Game::setCentena(int x){this->centena=x;}
int Game::getCentena(){return this->centena;}
void Game::setMilesima(int x){this->milesima=x;}
int Game::getMilesima(){return this->milesima;}
bool Game::getPrimerDecena(){return this->primerdecena;}
bool Game::getPrimerCentena(){return this->primercentena;}
bool Game::getPrimerMilesima(){return this->primermilesima;}
void Game::setVida(Dibujo *x){this->vida=x;}
void Game::setVelocidadNave(Dibujo *x){this->velocidadnave=x;}
void Game::setVelocidadBala(Dibujo *x){this->velocidadbala=x;}
void Game::setVelBala(int x){this->velbala=x;}
void Game::setNave(Dibujo *x){this->nave=x;}
void Game::setVida1(Dibujo *x){this->vida1=x;}
void Game::setVida2(Dibujo *x){this->vida2=x;}
void Game::setVida3(Dibujo *x){this->vida3=x;}
int Game::getVelBala(){return velbala;}


 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                    DESTRUCTOR                      ///
 ///   DESTRUYE LOS SALMPLES SONIDO EXPLOCION Y ZELDA   ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

Game::~Game()
{
    destroy_sample(this->sonidoexplocion);
    destroy_sample(this->zelda);
}
