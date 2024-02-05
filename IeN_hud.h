#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>


ALLEGRO_FONT* font;
long score_display;

char nome[7]; //o limite de caracteres de usuario é 6

void hud_init();

void hud_deinit();

void hud_update();

void hud_draw();