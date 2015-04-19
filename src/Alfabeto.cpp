#include "Alfabeto.h"
#include <allegro.h>
#include <stdlib.h>
#include <string.h>


void Alfabeto::setNombre(){
    strcpy(this->nombre,this->n);
}
char* Alfabeto::getNombre(){
    return this->nombre;
}
void Alfabeto::setTecla(bool x){
    this->tecla=x;
}
bool Alfabeto::getTecla(){
    return this->tecla;
}

void Alfabeto::VerificarTeclas(){
    if (key[KEY_A]){strcat(this->nombre,"a");this->tecla=false;}
    else if (key[KEY_B]){strcat(this->nombre,"b");this->tecla=false;}
    else if (key[KEY_C]){strcat(this->nombre,"c");this->tecla=false;}
    else if (key[KEY_D]){strcat(this->nombre,"d");this->tecla=false;}
    else if (key[KEY_E]){strcat(this->nombre,"e");this->tecla=false;}
    else if (key[KEY_F]){strcat(this->nombre,"f");this->tecla=false;}
    else if (key[KEY_G]){strcat(this->nombre,"g");this->tecla=false;}
    else if (key[KEY_H]){strcat(this->nombre,"h");this->tecla=false;}
    else if (key[KEY_I]){strcat(this->nombre,"i");this->tecla=false;}
    else if (key[KEY_J]){strcat(this->nombre,"j");this->tecla=false;}
    else if (key[KEY_K]){strcat(this->nombre,"k");this->tecla=false;}
    else if (key[KEY_L]){strcat(this->nombre,"l");this->tecla=false;}
    else if (key[KEY_M]){strcat(this->nombre,"m");this->tecla=false;}
    else if (key[KEY_N]){strcat(this->nombre,"n");this->tecla=false;}
    else if (key[KEY_O]){strcat(this->nombre,"o");this->tecla=false;}
    else if (key[KEY_P]){strcat(this->nombre,"p");this->tecla=false;}
    else if (key[KEY_Q]){strcat(this->nombre,"q");this->tecla=false;}
    else if (key[KEY_R]){strcat(this->nombre,"r");this->tecla=false;}
    else if (key[KEY_S]){strcat(this->nombre,"s");this->tecla=false;}
    else if (key[KEY_T]){strcat(this->nombre,"t");this->tecla=false;}
    else if (key[KEY_U]){strcat(this->nombre,"u");this->tecla=false;}
    else if (key[KEY_V]){strcat(this->nombre,"v");this->tecla=false;}
    else if (key[KEY_W]){strcat(this->nombre,"w");this->tecla=false;}
    else if (key[KEY_X]){strcat(this->nombre,"x");this->tecla=false;}
    else if (key[KEY_Y]){strcat(this->nombre,"y");this->tecla=false;}
    else if (key[KEY_Z]){strcat(this->nombre,"z");this->tecla=false;}
    else if (key[KEY_BACKSPACE]){strcpy(this->nombre,this->n);this->tecla=false;}

}

Alfabeto::~Alfabeto()
{
    //dtor
}
