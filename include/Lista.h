#ifndef LISTA_H
#define LISTA_H
#include "Dibujo.h"

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///        CLASE GAME (LISTA DOBLEMENTE ENLAZADA)      ///
 ///                SUPERCLASE: NONE                    ///
 ///    FUNCIONALIDADES: ALMACENAR TODOS LOS DIBUJOS    ///
 ///                     LLAMAR A LA FUNCION DIBUJAR DE ///
 ///                     DICHOS OBJETOS                 ///
 ///                     ELLIMINAR OBJETOS              ///
 ///                     ENLAZAR ASTEROIDES             ///
 ///                     ENLAZAR BALAS                  ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class Dibujo;

class Game
{
    public:
        Game();
        int getPuntaje();
        int getDecena();
        int getCentena();
        int getMilesima();
        int getVelBala();
        bool getPrimerDecena();
        bool getPrimerCentena();
        bool getPrimerMilesima();
        void insertar(Dibujo *);
        void Eliminar(Dibujo *);
        void Dibujar(BITMAP *);
        void Verificar();
        void setPuntaje(int);
        void setDecena(int);
        void setCentena(int);
        void setMilesima(int);
        void VerificarColiciones();
        void InsertarAsteroide(Dibujo *);
        void InsertarBala(Dibujo *);
        void EliminarBala(Dibujo *);
        void EliminarLista();
        void EliminarAsteroides();
        void setVida(Dibujo *);
        void setVelocidadNave(Dibujo *);
        void setVelocidadBala(Dibujo *);
        void setVelBala(int);
        void setNave(Dibujo *);
        void setVida1(Dibujo *);
        void setVida2(Dibujo *);
        void setVida3(Dibujo *);
        void VerificarBalas();
        virtual ~Game();
    protected:
    private:
        Dibujo *inicio;
        Dibujo *actual;
        Dibujo *asteinicio;
        Dibujo *asteactual;
        Dibujo *balainicio;
        Dibujo *balaactual;
        Dibujo *vida;
        Dibujo *velocidadnave;
        Dibujo *velocidadbala;
        Dibujo *nave;
        Dibujo *temporal;
        Dibujo *vida1;
        Dibujo *vida2;
        Dibujo *vida3;
        int elementos;
        int puntaje;
        int decena;
        int centena;
        int milesima;
        int velbala;
        bool primerdecena;
        bool primercentena;
        bool primermilesima;
        SAMPLE *sonidoexplocion;
        SAMPLE *zelda;
};

#endif // LISTA_H
