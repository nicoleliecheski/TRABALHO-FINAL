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

void CONTINUARJG(int Cx, int Cy) {
    //Na funcao continuar jogo, é dada a opcao de se escolher entre os varios usuarios existentes 
    al_draw_bitmap(IMG_CONTINUARJG, 0, 0, 0);
    int j = 0;
    for (int i = 0; i < 48; i++)
    {
        al_draw_text(GAMEFONTmn, al_map_rgb(255, 49, 173), 45 + (260 * j), (110 + (45 * (i % 12))), 0, u[i].nomes);
        if ((i + 1) % 12 == 0 && i != 0) {
            j += 1;
        }
    }
    al_draw_bitmap(CURSOR_CJG, Cx, Cy, 0);
}

int CONTROLE_CONTINUARJG(ALLEGRO_EVENT event, float *C1x, float *C1y, int bb) {
    switch (event.keyboard.keycode) {
    case ALLEGRO_KEY_UP:
        *C1y -= 45;
        if (*C1y < 0) *C1y = 0;
        break;

    case ALLEGRO_KEY_DOWN:
        *C1y += 45;
        if (*C1y > 495) *C1y = 495;
        break;

    case ALLEGRO_KEY_LEFT:
        *C1x -= 260;
        if (*C1x < 0) *C1x = 0;
        break;

    case ALLEGRO_KEY_RIGHT:
        *C1x += 260;
        if (*C1x > 780) *C1x = 780;
        break;

    case ALLEGRO_KEY_ENTER:
        bb = (*C1y / 45) + ((*C1x / 260) * 12);
        strcpy(nome, u[bb].nomes);
        score_display = u[bb].pont;
        score = u[bb].pont;
        ETAPA = 4;
        disp_init();
        break;

    case ALLEGRO_KEY_ESCAPE:
        ETAPA = 0;
        break;

    }

    return bb;
}
