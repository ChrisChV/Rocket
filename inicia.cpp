#include "inicia.h"
#include <allegro.h>

Inicia::Inicia(){}

void Inicia::inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}

int Inicia::inicia_audio(int izquierda, int derecha){
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);
}
void Inicia::clear_color(){
    clear_to_color(this->buffer, 0x999999);
}
void Inicia::destroy(){
    destroy_bitmap(this->buffer);
}
BITMAP* Inicia::getBITMAP(){
    return this->buffer;
}
