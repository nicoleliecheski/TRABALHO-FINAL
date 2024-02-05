#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

struct usuario
{
    char nomes[7];
    int pont; //pontuações dos usuarios
};

struct usuario u[50]; //o limite de usuarios é 48;

int ETAPA;  // 0 = MENU
            // 1 = NOVO JOGO
            // 2 = CONTINUAR JOGO
            // 3 = PLACAR 
            // 4 = JOGO
            // 5 = SAIR
            // (Varialvel pra controlar a mudanca do Menu para o Jogo)


ALLEGRO_KEYBOARD_STATE ks;

ALLEGRO_BITMAP* TITULO_COMPLETO;
ALLEGRO_BITMAP* MENU_NOVO;
ALLEGRO_BITMAP* MENU_CONTINUAR;
ALLEGRO_BITMAP* MENU_PLACAR;
ALLEGRO_BITMAP* MENU_SAIR;
ALLEGRO_BITMAP* CURSOR_CORACAO;

static float Cx, Cy;
Cx = 0;
Cy = 0;

void VISUAL_MENU();

void CONTROLE_MENU();