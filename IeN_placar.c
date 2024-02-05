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

void PLACAR() {
    //Na funcao placar, será exibido os usuarios com as 10 maiores pontuacoes
    al_draw_bitmap(IMG_PLACAR, 0, 0, 0);

    for (int i = 0; i < 10; i++)
    {
        char c[3];
        char p[12];
        sprintf(c, "%d", i + 1);
        sprintf(p, "%d", u[i].pont);
        int len = 30;
        al_draw_text(GAMEFONTm, al_map_rgb(255, 255, 255), len, 120 + (55 * i), 0, c);
        len += al_get_text_width(GAMEFONTm, c) + 10;
        al_draw_text(GAMEFONTm, al_map_rgb(255, 49, 173), len, 120 + (55 * i), 0, u[i].nomes);
        al_draw_text(GAMEFONTm, al_map_rgb(255, 255, 255), 400, 120 + (55 * i), 0, p);

    }
}

void CONTROLE_PLACAR() {
    al_get_keyboard_state(&ks);

    if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE)) {
        ETAPA = 0;
    }
}
