//TRABALHO ALGORITMOS E ESTRUTURAS DE DADOS I
//Alunas: Nicole Liecheski e Isabella Oliveira da Silva
//Turma de Engenharia de Software 2023

//a gameplay desse jogo é do tipo Space Invaders (mais informacoes: https://en.wikipedia.org/wiki/Space_Invaders)

//Os créditos da lógica de jogo e dos sprites do jogo são da comunidade Allegro,
//mas as partes do menu inicial, o menu de novo jogo, o menu de continuar jogo,
//o placar, a criação de novos usuários, a gravação de arquivo, a adaptação de
//todas as funcionalidades para TADs e demais partes do código são de TOTAL autoria
//do nosso grupo

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <string.h>
#include "IeN_basics.h"
#include "IeN_display.h"
#include "IeN_keyboard.h"
#include "IeN_sprites.h"
#include "IeN_audio.h"
#include "IeN_fx.h"
#include "IeN_ship.h"
#include "IeN_aliens.h"
#include "IeN_stars.h"
#include "IeN_hud.h"
#include "IeN_menu.h"
#include "IeN_novojg.h"
#include "IeN_continuarjg.h"
#include "IeN_placar.h"
#include "IeN_jogo.h"
#include "IeN_arquivos.h"

ALLEGRO_DISPLAY* dit;

bool done = false;

float C1y, C1x;

int c, aa, bb;

int comp(struct usuario* elem1, struct usuario* elem2)
{
    int f = ((int)elem1->pont);
    int s = ((int)elem2->pont);
    if (f < s) return  1;
    if (f > s) return -1;
    return 0;
}

int main()
{
    ETAPA = 0;

    ABRIR_ARQ_R(aa); //abrindo o arquivo para ler as pontuações e usuarios ja gravados

    qsort(u, sizeof(u) / sizeof(*u), sizeof(*u), comp);

    //addons padroes da biblioteca allegro
    
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); // definindo o jogo como 60fps
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    dit = al_create_display(1100, 675); //criando o display nas proporcoes de 1100x675
    must_init(dit, "dit");

    audio_init();

    must_init(al_init_ttf_addon(), "ttf addon");

    must_init(al_init_image_addon(), "image");
    sprites_init();

    hud_init();

    must_init(al_init_primitives_addon(), "primitives");

    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    //assets do menu

    TITULO_COMPLETO = al_load_bitmap("TITULO_COMPLETO.png");
    must_init(TITULO_COMPLETO, "TITULO_COMPLETO");
    MENU_NOVO = al_load_bitmap("MENU_NOVO.png");
    must_init(MENU_NOVO, "MENU_NOVO");
    MENU_CONTINUAR = al_load_bitmap("MENU_CONTINUAR.png");
    must_init(MENU_CONTINUAR, "MENU_CONTINUAR");
    MENU_PLACAR = al_load_bitmap("MENU_PLACAR.png");
    must_init(MENU_PLACAR, "MENU_PLACAR");
    MENU_SAIR = al_load_bitmap("MENU_SAIR.png");
    must_init(MENU_SAIR, "MENU_SAIR");
    CURSOR_CORACAO = al_load_bitmap("CURSOR_CORACAO.png");
    must_init(CURSOR_CORACAO, "CURSOR_CORACAO");

    //assets do NOVOJG
    IMG_NOVOJG = al_load_bitmap("IMG_NOVOJG.png");
    must_init(IMG_NOVOJG, "IMG_NOVOJG");
    GAMEFONT = al_load_ttf_font("GAMEFONT.ttf", 80, 0);
    must_init(GAMEFONT, "GAMEFONT");

    //assets do PLACAR
    IMG_PLACAR = al_load_bitmap("IMG_PLACAR.png");
    must_init(IMG_PLACAR, "IMG_PLACAR");
    GAMEFONTm = al_load_ttf_font("GAMEFONT.ttf", 40, 0);
    must_init(GAMEFONTm, "GAMEFONTm");

    //assets do CONTINUARJG
    IMG_CONTINUARJG = al_load_bitmap("IMG_CONTINUARJG.png");
    must_init(IMG_CONTINUARJG, "IMG_CONTINUARJG");
    GAMEFONTmn = al_load_ttf_font("GAMEFONT.ttf", 40, 0);
    must_init(GAMEFONTmn, "GAMEFONTmn");
    CURSOR_CJG = al_load_bitmap("CURSOR_CJG.png");
    must_init(CURSOR_CJG, "CURSOR_CJG");

    //inicializacao da fila, do timer e demais

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(dit));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    keyboard_init();
    fx_init();
    shots_init();
    ship_init();
    aliens_init();
    stars_init();

    frames = 0;
    score = 0;

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type) // esse teste ocorre cada vez que há um evento, 
        {                   // o que ocorre 60 vezes a cada segundo ja que nosso jogo roda a 60fps
        case ALLEGRO_EVENT_TIMER:
            if (ETAPA == 0) CONTROLE_MENU();
            else if (ETAPA == 3) CONTROLE_PLACAR();
            else if (ETAPA == 4) JOGO();

            if (key[ALLEGRO_KEY_ESCAPE] && ETAPA == 4) { //momento que saí do jogo
                u[aa].pont = score_display;
                ABRIR_ARQ_W(); //gravando as pontuaçoes no arquivo
                disp_deinit();
            }

            redraw = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;

        case ALLEGRO_EVENT_KEY_CHAR:
            if (ETAPA == 1) {
                MENU_NOVOJG(event, c, aa);
            }
            if (ETAPA == 2) {
                aa = CONTROLE_CONTINUARJG(event, &C1x, &C1y, bb);
            }
     
             break;
        }

        if (done)
            break;

        if (ETAPA == 5)
            break;

        if (ETAPA == 4) keyboard_update(&event);

        if (redraw && al_is_event_queue_empty(queue))   // o display é redesenhado toda vez que ocorre a mudanca de frame,
        {                                               // ou seja, 60 vezes por seg
            if (ETAPA == 0) VISUAL_MENU();
            else if (ETAPA == 1) NOVOJG();
            else if (ETAPA == 2) CONTINUARJG(C1x, C1y);
            else if (ETAPA == 3) PLACAR();
            else if (ETAPA == 4) JOGO_IMGS();

            if (ETAPA != 4) al_flip_display();

            redraw = false;
        }
    }

    //limpando a memoria

    al_destroy_bitmap(TITULO_COMPLETO);
    al_destroy_bitmap(MENU_NOVO);
    al_destroy_bitmap(MENU_CONTINUAR);
    al_destroy_bitmap(MENU_PLACAR);
    al_destroy_bitmap(MENU_SAIR);
    al_destroy_bitmap(CURSOR_CORACAO);
    al_destroy_bitmap(IMG_NOVOJG);
    al_destroy_font(font);
    al_destroy_font(GAMEFONT);
    al_destroy_font(GAMEFONTm);
    al_destroy_font(GAMEFONTmn);
    al_destroy_display(dit);
    al_destroy_bitmap(IMG_PLACAR);
    al_destroy_bitmap(PLACAR_BARBIE);
    al_destroy_bitmap(IMG_CONTINUARJG);
    sprites_deinit(); 
    hud_deinit();
    disp_deinit();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);


    return 0;
}