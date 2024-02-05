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

void JOGO() {
    fx_update();
    shots_update();
    stars_update();
    ship_update();
    aliens_update();
    hud_update();

    frames++;
}

void JOGO_IMGS() {

    disp_pre_draw();
    al_clear_to_color(al_map_rgb(0, 0, 0));

    stars_draw();
    aliens_draw();
    shots_draw();
    fx_draw();
    ship_draw();

    hud_draw();

    disp_post_draw();
}