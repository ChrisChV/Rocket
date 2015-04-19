#ifndef INICIA_H_INCLUDED
#define INICIA_H_INCLUDED
#include <allegro.h>
class Inicia{
private:
    BITMAP *buffer = create_bitmap(800, 600);
public:
    Inicia();
    void inicia_allegro(int,int);
    int inicia_audio(int,int);
    void clear_color();
    void destroy();
    BITMAP* getBITMAP();
};
#endif // INICIA_H_INCLUDED
