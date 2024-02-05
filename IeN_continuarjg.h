#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

float Cx, Cy;

ALLEGRO_BITMAP* IMG_CONTINUARJG;
ALLEGRO_FONT* GAMEFONTmn;
ALLEGRO_BITMAP* CURSOR_CJG;

void CONTINUARJG(int Cx, int Cy);

int CONTROLE_CONTINUARJG(ALLEGRO_EVENT event, float *C1x, float *C1y, int bb);
