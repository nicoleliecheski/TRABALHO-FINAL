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

void VISUAL_MENU() {

    al_clear_to_color(al_map_rgb(254, 151, 222));

    al_draw_bitmap(TITULO_COMPLETO, 0, 0, 0);

    al_draw_bitmap(MENU_NOVO, 0, 0, 0);
    al_draw_bitmap(MENU_CONTINUAR, 0, 0, 0);
    al_draw_bitmap(MENU_PLACAR, 0, 0, 0);
    al_draw_bitmap(MENU_SAIR, 0, 0, 0);

    al_draw_bitmap(CURSOR_CORACAO, Cx, Cy, 0);
}

void CONTROLE_MENU() {

    al_get_keyboard_state(&ks);

    if (al_key_down(&ks, ALLEGRO_KEY_UP))
        Cy = 0;
    if (al_key_down(&ks, ALLEGRO_KEY_DOWN))
        Cy = 149;
    if (al_key_down(&ks, ALLEGRO_KEY_LEFT))
        Cx = 0;
    if (al_key_down(&ks, ALLEGRO_KEY_RIGHT))
        Cx = 252;
    if (al_key_down(&ks, ALLEGRO_KEY_ENTER))
        if (Cx == 0 && Cy == 0) ETAPA = 1;
        else if (Cx == 252 && Cy == 0) ETAPA = 2;
        else if (Cx == 0 && Cy == 149) ETAPA = 3;
        else if (Cx == 252 && Cy == 149) ETAPA = 5; 
}
