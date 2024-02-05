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

void NOVOJG() {
    //Na funcao novo jogo, cria-se um novo usuario que associado a ele tem uma pontuacao

    al_draw_bitmap(IMG_NOVOJG, 0, 0, 0);
    al_draw_text(GAMEFONT, al_map_rgb(255, 49, 173), 310, 350, 0, nome);
}

void MENU_NOVOJG(ALLEGRO_EVENT event, int c, int aa) {
    switch (event.keyboard.keycode) {
    case ALLEGRO_KEY_ENTER:
        if (c > 0) {
            strcpy(u[aa].nomes, nome);
            ETAPA = 4;
            disp_init();
        }
        break;
    case ALLEGRO_KEY_BACKSPACE:
        c--;
        if (c < 0) c = 0;
        nome[c] = ' ';
        break;
    case ALLEGRO_KEY_ESCAPE:
        ETAPA = 0;
        break;
    default:
        for (int i = 1; i <= 26; i++)
        {
            if (event.keyboard.keycode == i) {
                if (c > -1 && c < 6) nome[c] = i + '@';
                c++;
                if (c > 6) c = 6;
            }
        }

        break;
    }
}

