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

void hud_init()
{
    font = al_create_builtin_font();
    must_init(font, "font");

    score_display = 0;
}

void hud_deinit()
{
    al_destroy_font(font);
}

void hud_update()
{
    if (frames % 2)
        return;

    for (long i = 5; i > 0; i--)
    {
        long diff = 1 << i;
        if (score_display <= (score - diff))
            score_display += diff;
    }
}

void hud_draw()
{
    al_draw_text(
        font,
        al_map_rgb_f(1, 1, 1),
        1, 1,
        0,
        nome
    );
    al_draw_textf(
        font,
        al_map_rgb_f(1, 1, 1),
        1, 10,
        0,
        "%06ld",
        score_display
    );

    int spacing = LIFE_W + 1;
    for (int i = 0; i < ship.lives; i++)
        al_draw_bitmap(sprites.life, 1 + (i * spacing), 20, 0);

    if (ship.lives < 0) {
        al_draw_text(
            font,
            al_map_rgb_f(1, 1, 1),
            BUFFER_W / 2, BUFFER_H / 2,
            ALLEGRO_ALIGN_CENTER,
            "G A M E  O V E R"
        );
    }
}