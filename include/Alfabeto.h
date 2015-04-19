#ifndef ALFABETO_H
#define ALFABETO_H


class Alfabeto
{
    public:
        void VerificarTeclas();
        void setNombre();
        void setTecla(bool);
        bool getTecla();
        char* getNombre();
        virtual ~Alfabeto();
    protected:
    private:
        char nombre[20]="",n[20]="";
        bool tecla=true;
};

#endif // ALFABETO_H
