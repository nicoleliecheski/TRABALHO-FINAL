#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP* IMG_NOVOJG;
ALLEGRO_FONT* GAMEFONT;

void NOVOJG();

void MENU_NOVOJG(ALLEGRO_EVENT event, int c, int aa);