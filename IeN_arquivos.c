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
#include "IeN_arquivos.h"

FILE* nome_pont;

void ABRIR_ARQ_R(int aa) {
    nome_pont = fopen("nomes_pont.txt", "r");
    if (nome_pont == NULL)
    {
        printf("Could not open file");
        exit(1);
    }
    for (int i = 0; i < 48; i++) {
        fscanf(nome_pont, "%s %d", &u[i].nomes, &u[i].pont);
        if (u[i].pont == 0) aa = i;
    }
    fclose(nome_pont);
}

void ABRIR_ARQ_W() {
    nome_pont = fopen("nomes_pont.txt", "w");
    if (nome_pont == NULL)
    {
        printf("Could not open file");
        exit(1);
    }
    for (int i = 0; i < 48; i++)
    {
        if (u[i].pont != 0) fprintf(nome_pont, "%s %d\n", u[i].nomes, u[i].pont);
    }
    fclose(nome_pont);
}
