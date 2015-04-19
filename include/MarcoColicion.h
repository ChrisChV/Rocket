#ifndef MARCOCOLICION_H
#define MARCOCOLICION_H

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///                CLASE MARCO DE COLICIÓN             ///
 ///                   SUPERCLASE: NONE                 ///
 ///    FUNCIONALIDADES: ALMACENAR LAS 4 COORDENADAS    ///
 ///                     NECESARIAS PARA VERIFICAR LA   ///
 ///                     COLICION                       ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

class MarcoColicion
{
    public:
        MarcoColicion();
        void setCuadro(int,int,int,int);
        int getX1();
        int getX2();
        int getY1();
        int getY2();
        virtual ~MarcoColicion();
    protected:
        int x1;
        int x2;
        int y1;
        int y2;
    private:
};

#endif // MARCOCOLICION_H
