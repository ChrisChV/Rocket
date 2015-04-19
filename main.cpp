 #include "sad.h"

using namespace std;

 /// //////////////////////////////////////////////////////
 ///                                                    ///
 ///       JUEGO DE NAVES EN LA LIBRERIA ALLEGRO        ///
 ///     HECHO POR CHRISTOFER FABIÁN CHÁVEZ CARAZAS     ///
 ///                                                    ///
 /// //////////////////////////////////////////////////////

int TemporizadorBala=0;
int main()
{
    /// //////////////////////////////////////////////////////
    ///                                                    ///
    ///                   INICIAR ALLEGRO                  ///
    ///            INSTALAR EL TECLADO Y EL MOUSE          ///
    ///             CREAR LA PANTALLA DE 800x600           ///
    ///                                                    ///
    /// //////////////////////////////////////////////////////


    srand (time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(140,140);

    /// //////////////////////////////////////////////////////
    ///                                                    ///
    ///          CREAR TODAS LAS VARIABLES A USAR          ///
    ///     BITMAP:buffer      SAMPLES:laser,gameover      ///
    ///         BOOLEANOS: menus y dificultades            ///
    ///          FONT (TIPO DE LETRA): myfont              ///
    ///                                                    ///
    /// //////////////////////////////////////////////////////


    BITMAP *buffer = create_bitmap(800, 600);
    clear_to_color(buffer, 0x999999);
    SAMPLE *sonidobala =load_wav("recursos/laser.wav");
    SAMPLE *pac = load_wav("recursos/gameover.wav");
    bool program=true,menu=true, menudificultad=true,game=true,gameover=true,nombre=true;
    bool facil=false,medio=false,dificil=true;
    FONT * myfont=load_font("myfont.pcx",default_palette,NULL);

    /// //////////////////////////////////////////////////////
    ///                                                    ///
    ///             COMIENZO DEL WHILE PROGRAMA            ///
    ///      FUNCIONALIDAD: ITERAR HASTA QUE EL BOOLEANO   ///
    ///                     program SEA FALSO              ///
    ///                     CONTROLA TODOS LOS FOTOGRAMAS  ///
    ///                     DEL JUEGO                      ///
    ///                                                    ///
    /// //////////////////////////////////////////////////////


    while(program){

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///           INICIALIZADOR DE TEMPORIZADORES          ///
        ///    FUNCIONALIDADES: CONTROLAR LOS TIEMPOS DE       ///
        ///                     OBJETOS                        ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////



        int TemporizadorAsteroideVerde=6000;
        int TemporizadorAsteroideMorado=4000;
        int TemporizadorAsteroideRojo=8000;
        int TemporizadorAsteroideAmarillo=12000;
        int TemporizadorAsteroideVerdeI=6000;
        int TemporizadorAsteroideMoradoI=4000;
        int TemporizadorAsteroideRojoI=8000;
        int TemporizadorAsteroideAmarilloI=12000;
        int TemporizadorVida=8000;
        int TemporizadorVelNave=10000;
        int TemporizadorVelBala=4300;
        int TemporizadorVerificar=4000;
        int TemporizadorColiciones=40;
        int TemporizadorTecla=0;

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///              INICIALIZADOR DE VARIABLES            ///
        ///     FUNCIONALIDADES: REGULAR LA DIFICULTAD         ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        bool rojo=true,amarillo=true;
        float velocidadverde=2,velocidadmorado=1.0,velocidadrojo=0.5;
        int vidasrojo=3;

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///             CREACION DE UN OBJETO GAME             ///
        ///     OTRAS CREACIONES: DIBUJO: fondo                ///
        ///                       NAVE: nave                   ///
        ///     INSERCIONES: fondo                             ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        Game *juego=new Game();
        Dibujo *fondo=new Dibujo();
        fondo->setDibujo("recursos/estrellas.bmp");
        Nave *nave=new Nave();
        juego->insertar(fondo);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///             FOR EN EL RANGO 0 A 29                 ///
        ///  FUNCIONALIDAD: CREAR E INSERTAR OBJETOS ESTRELLA  ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////


        for(int i=0;i<30;i++){
            Estrella *estrella=new Estrella();
            estrella->setX(rand()%800);
            estrella->setY(rand()%600 + 1);
            juego->insertar(estrella);
        }

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///           CRACION E INSERCION DE DIBUJOS           ///
        ///     FUNCIONALIDADES: DIBUJOS DEL MENU PRINCIPAL    ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        Dibujo *titulo= new Dibujo();titulo->setX(100);titulo->setY(50);titulo->setDibujo("recursos/rocket.bmp");
        Dibujo *logo= new Dibujo();logo->setX(0);logo->setY(450);logo->setDibujo("recursos/logo.bmp");
        Dibujo *inicio = new Dibujo();inicio->setX(250);inicio->setY(300);inicio->getMarco()->setCuadro(250,570,300,386);inicio->setDibujo("recursos/iniciarblanco.bmp");
        Dibujo *inicio2 = new Dibujo();inicio2->setX(250);inicio2->setY(300);inicio2->setDibujo("recursos/iniciar.bmp");
        Dibujo *puntero = new Dibujo();puntero->setX(300);puntero->setY(500);puntero->getMarco()->setCuadro(300,305,500,505);puntero->setDibujo("recursos/puntero.bmp");
        juego->insertar(titulo);
        juego->insertar(logo);
        juego->insertar(inicio);
        juego->insertar(inicio2);
        juego->insertar(puntero);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///               INICIO DEL WHILE MENU                ///
        ///    FUNCIONALIDAD: MENU PRINCIPAL                   ///
        ///                   BOTON INICIO                     ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////


        while(menu){
            blit(buffer,screen,0,0,0,0,800,600);
            clear (buffer);
            inicio2->setCrear(false);
            puntero->setX(mouse_x);
            puntero->setY(mouse_y);
            puntero->getMarco()->setCuadro(puntero->getX(),puntero->getX()+5,puntero->getY(),puntero->getY()+6);
            juego->Dibujar(buffer);
            if(puntero->Colicion(inicio)){
                inicio2->setCrear(true);
                juego->Dibujar(buffer);
                if(mouse_b & 1){
                    menu=false;
                }
            }
        }

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///                 FIN DEL WHILE MENU                 ///
        ///     ELIMINACIÓN DE DIBUJOS DEL MENU PRINCIPAL      ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////


        juego->Eliminar(titulo);
        juego->Eliminar(logo);
        juego->Eliminar(inicio);
        juego->Eliminar(inicio2);
        juego->Eliminar(puntero);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///             CRACION E INSERCION DE DIBUJOS         ///
        ///    FUNCIONALIDADES: DIBUJOS DEL MENU DIFICULTAD    ///
        ///    NOTA: EL REST DEL FINAL SIRVE PARA DETENER      ///
        ///          LA ANIMACIÓN POR 200 MILISEGUNDOS         ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////


        Dibujo *puntero1 = new Dibujo();puntero1->setX(300);puntero1->setY(500);puntero1->getMarco()->setCuadro(300,310,500,510);puntero1->setDibujo("recursos/puntero.bmp");
        Dibujo *asteverde = new Dibujo();asteverde->setX(150);asteverde->setY(200);asteverde->setDibujo("recursos/aste.bmp");
        Dibujo *astemorado = new Dibujo();astemorado->setX(350);astemorado->setY(200);astemorado->setDibujo("recursos/astemoradito.bmp");
        Dibujo *asterojo = new Dibujo();asterojo->setX(550);asterojo->setY(200);asterojo->setDibujo("recursos/asterojito.bmp");
        Dibujo *facil1 =new Dibujo();facil1->setX(130);facil1->setY(350);facil1->getMarco()->setCuadro(140,270,350,400);facil1->setDibujo("recursos/facil1.bmp");
        Dibujo *facil2 = new Dibujo();facil2->setX(130);facil2->setY(350);facil2->setDibujo("recursos/facil2.bmp");
        Dibujo *medio1 = new Dibujo();medio1->setX(310);medio1->setY(350);medio1->getMarco()->setCuadro(320,500,350,400);medio1->setDibujo("recursos/medio1.bmp");
        Dibujo *medio2 = new Dibujo();medio2->setX(310);medio2->setY(350);medio2->setDibujo("recursos/medio2.bmp");
        Dibujo *dificil1 =new Dibujo();dificil1->setX(530);dificil1->setY(350); dificil1->getMarco()->setCuadro(540,710,350,400);dificil1->setDibujo("recursos/dificil1.bmp");
        Dibujo *dificil2 =new Dibujo();dificil2->setX(530);dificil2->setY(350); dificil2->setDibujo("recursos/dificil2.bmp");
        juego->insertar(asteverde);
        juego->insertar(astemorado);
        juego->insertar(asterojo);
        juego->insertar(facil1);
        juego->insertar(facil2);
        juego->insertar(medio1);
        juego->insertar(medio2);
        juego->insertar(dificil1);
        juego->insertar(dificil2);
        juego->insertar(puntero1);
        rest(200);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///          INICIO DEL WHILE MENU DIFICULTAD          ///
        ///   FUNCIONALIDADES: BOTON: facil                    ///
        ///                           medio                    ///
        ///                           dificil                  ///
        ///                     CAMBIA BOOLEANES SEGUN EL BOTON///
        ///                     PRESIONADO                     ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////


        while(menudificultad){
            blit(buffer,screen,0,0,0,0,800,600);
            clear (buffer);
            facil2->setCrear(false);
            medio2->setCrear(false);
            dificil2->setCrear(false);
            puntero1->setX(mouse_x);
            puntero1->setY(mouse_y);
            puntero1->getMarco()->setCuadro(puntero1->getX(),puntero1->getX()+10,puntero1->getY(),puntero1->getY()+10);
            juego->Dibujar(buffer);
            if (puntero1->Colicion(dificil1)){
                dificil2->setCrear(true);
                juego->Dibujar(buffer);
                if(mouse_b & 1){
                    menudificultad=false;
                    dificil=true;
                }
            }
            if (puntero1->Colicion(facil1)){
                facil2->setCrear(true);
                juego->Dibujar(buffer);
                if (mouse_b & 1){
                    menudificultad=false;
                    facil=true;
                }
            }
            if (puntero1->Colicion(medio1)){
                medio2->setCrear(true);
                juego->Dibujar(buffer);
                if (mouse_b & 1){
                    menudificultad=false;
                    medio=true;
                }
            }
        }

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///             FIN DEL WHILE MENU DIFICULTAD          ///
        ///    CAMBIAR VAROLES PARA REGULAR LA DIFICULTAD      ///
        ///    ELIMINACIÓN DE DIBUJOS DEL MENU DIFICULTAD      ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        if(facil){
            rojo=false;
            amarillo=false;
            velocidadverde=1;
            velocidadmorado=1.8;
            TemporizadorAsteroideVerde=5000;
            TemporizadorAsteroideVerdeI=5000;
            TemporizadorAsteroideMorado=5000;
            TemporizadorAsteroideMoradoI=5000;
            juego->setVelBala(120);
        }
        if(medio){
            amarillo=false;
            velocidadverde=1.5;
            velocidadmorado=1;
            velocidadrojo=1.3;
            TemporizadorAsteroideVerde=5000;
            TemporizadorAsteroideVerde=5000;
            TemporizadorAsteroideRojo=9000;
            vidasrojo=2;
            juego->setVelBala(160);
        }
        if(dificil){
            velocidadverde=2;
        }
        juego->Eliminar(asteverde);
        juego->Eliminar(astemorado);
        juego->Eliminar(asterojo);
        juego->Eliminar(facil1);
        juego->Eliminar(facil2);
        juego->Eliminar(medio1);
        juego->Eliminar(medio2);
        juego->Eliminar(dificil1);
        juego->Eliminar(dificil2);
        juego->Eliminar(puntero1);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///                 MENUS AUXILIARES                   ///
        ///  FUNCIONALIDADES: MOSTRAR INFORMACION AL USUSARIO  ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        Dibujo *asteverde2 = new Dibujo();asteverde2->setX(120);asteverde2->setY(200);asteverde2->setDibujo("recursos/aste.bmp");
        Dibujo *astemorado2 = new Dibujo();astemorado2->setX(610);astemorado2->setY(200);astemorado2->setDibujo("recursos/astemoradito.bmp");
        Dibujo *asterojo2 = new Dibujo();asterojo2->setX(340);asterojo2->setY(330);asterojo2->setDibujo("recursos/asterojito.bmp");
        Dibujo *asteamarillo2= new Dibujo(); asteamarillo2->setX(340);asteamarillo2->setY(50);asteamarillo2->setDibujo("recursos/asteamarillo.bmp");

        juego->insertar(asteverde2);
        juego->insertar(astemorado2);


        while(!key[KEY_ENTER]){
            blit(buffer,screen,0,0,0,0,800,600);
            clear (buffer);
            juego->Dibujar(buffer);
            textout(buffer,myfont,"10 Puntos",80,330,palette_color[12]);
            textout(buffer,myfont,"20 Puntos",570,330,palette_color[12]);
            textout(buffer,myfont,"Presione Enter para continuar",100,550,palette_color[12]);
            if(rojo){
                asterojo2->Dibujar(buffer);
                textout(buffer,myfont,"50 Puntos",300,450,palette_color[12]);
            }
            if(amarillo){
                asteamarillo2->Dibujar(buffer);
                textout(buffer,myfont,"30 Puntos",300,170,palette_color[12]);
            }
        }


        juego->Eliminar(asteverde2);
        juego->Eliminar(astemorado2);
        delete (asterojo2);
        delete (asteamarillo2);
        rest(200);

        Dibujo *corazon= new Dibujo();corazon->setX(150);corazon->setY(200);corazon->setDibujo("recursos/vidap.bmp");
        Dibujo *rayo=new Dibujo();rayo->setX(350);rayo->setY(200);rayo->setDibujo("recursos/rayo.bmp");
        Dibujo *sol = new Dibujo();sol->setX(550);sol->setY(200);sol->setDibujo("recursos/sol.bmp");
        juego->insertar(corazon);
        juego->insertar(rayo);
        juego->insertar(sol);

        while(!key[KEY_ENTER]){
            blit(buffer,screen,0,0,0,0,800,600);
            clear (buffer);
            juego->Dibujar(buffer);
            textout(buffer,myfont,"Aumenta",120,330,palette_color[12]);
            textout(buffer,myfont,"Una Vida",115,370,palette_color[12]);
            textout(buffer,myfont,"Aumenta",330,330,palette_color[12]);
            textout(buffer,myfont,"Vel. Nave",315,370,palette_color[12]);
            textout(buffer,myfont,"Aumenta",530,330,palette_color[12]);
            textout(buffer,myfont,"Vel. Bala",530,370,palette_color[12]);
            textout(buffer,myfont,"Presione Enter para continuar",100,550,palette_color[12]);
        }

        juego->Eliminar(corazon);
        juego->Eliminar(rayo);
        juego->Eliminar(sol);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///      CREACION E INSERCION DE DIBUJOS DEL JUEGO     ///
        ///     BOOLEANO: pausa  USADO PARA PAUSAR EL JUEGO    ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        Asteroide *aste=new Asteroide();
        aste->setVelocidad(velocidadverde);
        juego->insertar(nave);

        juego->insertar(aste);
        Dibujo *vida1=new Dibujo('v3');vida1->setDibujo("recursos/vida.bmp");vida1->setX(100);juego->insertar(vida1);
        Dibujo *vida2=new Dibujo('v2');vida2->setDibujo("recursos/vida.bmp");vida2->setX(50);juego->insertar(vida2);
        Dibujo *vida3=new Dibujo('v1');vida3->setDibujo("recursos/vida.bmp");vida3->setX(0);juego->insertar(vida3);
        juego->setVida1(vida3);
        juego->setVida2(vida2);
        juego->setVida3(vida1);
        PowerUps *vidaaste = new PowerUps(30,70);vidaaste->setEtiqueta('av');vidaaste->setDibujo("recursos/vidap.bmp");
        PowerUps *velnave= new PowerUps(30,70);velnave->setEtiqueta('vn');velnave->setDibujo("recursos/rayo.bmp");
        PowerUps *velbala= new PowerUps(30,70);velbala->setEtiqueta('vb');velbala->setDibujo("recursos/sol.bmp");
        Dibujo *Trans = new Dibujo();Trans->setDibujo("recursos/trans.bmp");Trans->setX(-100);
        juego->setVida(vidaaste);
        juego->insertar(vidaaste);
        juego->setVelocidadNave(velnave);
        juego->insertar(velnave);
        juego->setVelocidadBala(velbala);
        juego->insertar(velbala);
        juego->setNave(nave);
        bool pausa;

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///                INICIO DEL WHILE GAME               ///
        ///    FUNCIONALIDAD: CUERPO DEL JUEGO                 ///
        ///                   PAUSAR JUEGO                     ///
        ///                   DIBUJAR LA LISTA JEUGO           ///
        ///                   MOVER LA NAVE                    ///
        ///                   TEMPORIZADORES                   ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        while(game) {
            pausa=true;
            blit(buffer,screen,0,0,0,0,800,600);
            clear (buffer);
            if (key[KEY_ESC]){
                while(pausa){
                    if(key[KEY_ENTER]){
                        pausa=false;
                    }

                }
            }
            juego->Dibujar(buffer);
            textprintf(buffer,myfont,700,0,palette_color[12],"%d",juego->getPuntaje());
            juego->VerificarBalas();

            if (TemporizadorColiciones!=0){
                TemporizadorColiciones--;
            }
            else if (TemporizadorColiciones==0){
                juego->VerificarColiciones();
                TemporizadorColiciones=15;
            }
            if (key[KEY_SPACE]&&TemporizadorBala==0){
                play_sample(sonidobala,100,210,1000,0);
                TemporizadorBala=juego->getVelBala();
                Proyectil *disparo=new Proyectil;
                disparo->setCrear(true);
                disparo->setX(nave->getX());
                disparo->setY(nave->getY());
                juego->insertar(disparo);
            }
            if (TemporizadorAsteroideVerde!=0){
                TemporizadorAsteroideVerde--;
            }
            else{
                Asteroide *newaste1 = new Asteroide();
                newaste1->setVelocidad(velocidadverde);
                juego->insertar(newaste1);
                TemporizadorAsteroideVerde=TemporizadorAsteroideVerdeI;
            }

            if (TemporizadorAsteroideMorado!=0){
                TemporizadorAsteroideMorado--;
            }
            else{
                Asteroide *newaste2 = new Asteroide();
                newaste2->setDibujo("recursos/astemoradito.bmp");
                newaste2->setVelocidad(velocidadmorado);
                newaste2->setPuntos(20);
                juego->insertar(newaste2);
                TemporizadorAsteroideMorado=TemporizadorAsteroideMoradoI;
            }
            if(rojo){
                if (TemporizadorAsteroideRojo!=0){
                    TemporizadorAsteroideRojo--;
                }
                else{
                    Asteroide *newaste3 = new Asteroide();
                    newaste3->setDibujo("recursos/asterojito.bmp");
                    newaste3->setVelocidad(velocidadrojo);
                    newaste3->setVidas(vidasrojo);
                    newaste3->setVidasIniciales(vidasrojo);
                    newaste3->setPuntos(50);
                    juego->insertar(newaste3);
                    TemporizadorAsteroideRojo=TemporizadorAsteroideRojoI;
                }
            }
            if(amarillo){
                if (TemporizadorAsteroideAmarillo!=0){
                    TemporizadorAsteroideAmarillo--;
                }
                else{
                    AsteroideI *newaste4 = new AsteroideI();
                    newaste4->setPuntos(30);
                    juego->insertar(newaste4);
                    TemporizadorAsteroideAmarillo=TemporizadorAsteroideAmarilloI;
                }
            }
            if (TemporizadorVida!=0){
                TemporizadorVida--;
            }
            else{
                vidaaste->setCrear(true);
                TemporizadorVida=8000;
            }
            if (TemporizadorVelBala!=0){
                TemporizadorVelBala--;
            }
            else{
                velbala->setCrear(true);
                TemporizadorVelBala=4300;
            }
            if (TemporizadorVelNave!=0){
                TemporizadorVelNave--;
            }
            else{
                velnave->setCrear(true);
                TemporizadorVelNave=10000;
            }
            if(TemporizadorVerificar!=0){
                TemporizadorVerificar--;
            }
            else{
                juego->Verificar();
                TemporizadorVerificar=4000;
            }

            if (key[KEY_DOWN]&&nave->getCrear()==true){nave->dibujarAbajo();}
            if (key[KEY_UP]&&nave->getCrear()==true){nave->dibujarArriba();}
            if (key[KEY_RIGHT]&&nave->getCrear()==true){nave->dibujarDerecha();}
            if (key[KEY_LEFT]&&nave->getCrear()==true){nave->dibujarIzquierda();}
            if (TemporizadorBala!=0){TemporizadorBala--;}
            if (nave->getVidas()==0){
                game=false;
                juego->Eliminar(nave);
                juego->Verificar();
                play_sample(pac,200,127,1000,0);
            }
        }

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///         CREACION E INSERCION DE DIBUJOS            ///
        ///     FUNCIONALIDAD: DIBUJOS PARA EL MENU GAMEOVER   ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        Dibujo *over = new Dibujo(); over->setX(100);over->setY(50);over->setDibujo("recursos/gameover.bmp");
        Dibujo *menu1 =new Dibujo();menu1->setX(70);menu1->setY(400);menu1->getMarco()->setCuadro(80,230,400,450);menu1->setDibujo("recursos/menu1.bmp");
        Dibujo *menu2= new Dibujo();menu2->setX(70);menu2->setY(400);menu2->setDibujo("recursos/menu2.bmp");
        Dibujo *retry1=new Dibujo(); retry1->setX(270);retry1->setY(400); retry1->getMarco()->setCuadro(280,570,400,450) ;retry1->setDibujo("recursos/retry1.bmp");
        Dibujo *retry2=new Dibujo(); retry2->setX(270);retry2->setY(400);retry2->setDibujo("recursos/retry2.bmp");
        Dibujo *salir1=new Dibujo(); salir1->setX(600),salir1->setY(400);salir1->getMarco()->setCuadro(600,730,400,450);salir1->setDibujo("recursos/salir1.bmp");
        Dibujo *salir2=new Dibujo();salir2->setX(600),salir2->setY(400);salir2->setDibujo("recursos/salir2.bmp");
        Dibujo *puntero2 = new Dibujo();puntero2->setX(300);puntero2->setY(500);puntero2->getMarco()->setCuadro(300,310,500,510);puntero2->setDibujo("recursos/puntero.bmp");


        juego->insertar(over);
        juego->insertar(menu1);
        juego->insertar(menu2);
        juego->insertar(retry1);
        juego->insertar(retry2);
        juego->insertar(salir1);
        juego->insertar(salir2);
        juego->insertar(puntero2);

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///             INICIO DE LWHILE GAMEOVER              ///
        ///    FUNCIONALIDAD: BOTON: menu                      ///
        ///                          reinicia                  ///
        ///                          salir                     ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        while(gameover){
            blit(buffer,screen,0,0,0,0,800,600);
            clear(buffer);
            salir2->setCrear(false);
            menu2->setCrear(false);
            retry2->setCrear(false);
            puntero2->setX(mouse_x);
            puntero2->setY(mouse_y);
            puntero2->getMarco()->setCuadro(puntero2->getX(),puntero2->getX()+10,puntero2->getY(),puntero2->getY()+10);
            juego->Dibujar(buffer);
            textprintf(buffer,myfont,250,250,palette_color[12],"Tu puntaje es: %d",juego->getPuntaje());
            if (puntero2->Colicion(menu1)){
                menu2->setCrear(true);
                juego->Dibujar(buffer);
                textprintf(buffer,myfont,250,250,palette_color[12],"Tu puntaje es: %d",juego->getPuntaje());
                if (mouse_b & 1){
                    gameover=false;
                    menu=true;
                    menudificultad=true;
                    game=true;
                    nombre=true;
                    facil=false;
                    medio=false;
                    dificil=false;
                }
            }
            if (puntero2->Colicion(retry1)){
                retry2->setCrear(true);
                juego->Dibujar(buffer);
                textprintf(buffer,myfont,250,250,palette_color[12],"Tu puntaje es: %d",juego->getPuntaje());
                if (mouse_b & 1){
                    gameover=false;
                    game=true;
                    nombre=true;
                }
            }
            if (puntero2->Colicion(salir1)){
                salir2->setCrear(true);
                juego->Dibujar(buffer);
                textprintf(buffer,myfont,250,250,palette_color[12],"Tu puntaje es: %d",juego->getPuntaje());
                if (mouse_b & 1){
                    gameover=false;
                    program=false;
                }
            }
        }

        /// //////////////////////////////////////////////////////
        ///                                                    ///
        ///     ELIMINACION DE LOS DIBUJOS DEL MENU GAMEOVER   ///
        ///             ELIMINACION DEL OBJETO JUEGO           ///
        ///                                                    ///
        /// //////////////////////////////////////////////////////

        gameover=true;

        juego->Eliminar(over);
        juego->Eliminar(menu1);
        juego->Eliminar(menu2);
        juego->Eliminar(retry1);
        juego->Eliminar(retry2);
        juego->Eliminar(salir1);
        juego->Eliminar(salir2);
        juego->Eliminar(puntero2);
        juego->EliminarLista();
        delete(juego);
    }

    /// //////////////////////////////////////////////////////
    ///                                                    ///
    ///         DESTRUCCION DEL BUFFER Y LOS SAMPLES       ///
    ///                                                    ///
    /// //////////////////////////////////////////////////////

    destroy_sample(sonidobala);
    destroy_sample(pac);
    destroy_bitmap(buffer);
    return 0;
}
END_OF_MAIN();   ///FIN =D
