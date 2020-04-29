/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

void initialise_text(rpg_t *rpg, char **name)
{
    rpg->text[14].size = 50;
    rpg->text[14].pos.x = 803;
    rpg->text[14].pos.y = 278;
    rpg->text[14].type = SAVE;
    rpg->text[15].size = 50;
    rpg->text[15].pos.x = 803;
    rpg->text[15].pos.y = 503;
    rpg->text[15].type = SAVE;
    rpg->text[16].size = 50;
    rpg->text[16].pos.x = 803;
    rpg->text[16].pos.y = 728;
    rpg->text[16].type = SAVE;
    rpg->text[17].size = 50;
    rpg->text[17].pos.x = 803;
    rpg->text[17].pos.y = 728;
    rpg->text[17].type = SAVE;
    for (int i = 4; i < 7; i += 1) {
        rpg->text[i + 14].size = 50;
        rpg->text[i + 14].pos.x = 803;
        rpg->text[i + 14].pos.y = 278 + ((i - 4) * 225);
        rpg->text[i + 14].type = SIDONIA + i;
    }
    for (int i = 22; i < 24; i += 1) {
        rpg->text[i].size = 100;
        rpg->text[i].pos.x = 1520;
        rpg->text[i].pos.y = 940;
        rpg->text[i].type = LEVEL;
    }
}

void initialize_text3(rpg_t *rpg, char **name)
{
    rpg->text[11].size = 75;
    rpg->text[11].pos.x = 900;
    rpg->text[11].pos.y = 300;
    rpg->text[11].type = MUSIC;
    name[11] = int_to_char(rpg->music_volume);
    rpg->text[12].size = 50;
    rpg->text[12].pos.x = 803;
    rpg->text[12].pos.y = 528;
    rpg->text[12].type = SOUND;
    rpg->text[13].size = 75;
    rpg->text[13].pos.x = 900;
    rpg->text[13].pos.y = 700;
    rpg->text[13].type = SOUND;
    name[13] = int_to_char(rpg->sound_volume);
    initialise_text(rpg, name);
}

void initialize_text2(rpg_t *rpg, char **name)
{
    rpg->text[8].size = 75;
    rpg->text[8].pos.x = 900;
    rpg->text[8].pos.y = 400;
    rpg->text[8].type = FPS;
    name[8] = int_to_char(rpg->fps);
    rpg->text[9].size = 100;
    rpg->text[9].pos.x = 1520;
    rpg->text[9].pos.y = 940;
    rpg->text[9].type = BACK;
    rpg->text[10].size = 50;
    rpg->text[10].pos.x = 803;
    rpg->text[10].pos.y = 128;
    rpg->text[10].type = MUSIC;
    initialize_text3(rpg, name);
}

void initialize_text(rpg_t *rpg, char **name)
{
    for (int i = 0; i < 4; i += 1) {
        rpg->text[i].size = 50;
        rpg->text[i].pos.x = 210;
        rpg->text[i].pos.y = 228 + (i * 200);
        rpg->text[i].type = SIDONIA + i;
    }
    for (int i = 4; i < 7; i += 1) {
        rpg->text[i].size = 50;
        rpg->text[i].pos.x = 803;
        rpg->text[i].pos.y = 278 + ((i - 4) * 225);
        rpg->text[i].type = SIDONIA + i;
    }
    rpg->text[21].size = 100;
    rpg->text[21].pos.x = 730;
    rpg->text[21].pos.y = 50;
    rpg->text[21].type = SIDONIA;
    rpg->text[7].size = 50;
    rpg->text[7].pos.x = 803;
    rpg->text[7].pos.y = 228;
    rpg->text[7].type = FPS;
    initialize_text2(rpg, name);
}

void make_saves(rpg_t *rpg, char **name)
{
    make_text(&rpg->text[14], "First", "assets/fonts/virus2.TTF");
    make_text(&rpg->text[15], "Second", "assets/fonts/virus2.TTF");
    make_text(&rpg->text[16], "Third", "assets/fonts/virus2.TTF");
    for (int i = 22; i < 24; i += 1)
        make_text(&rpg->text[i], name[i - 4], "assets/fonts/virus2.TTF");
}

void set3(rpg_t *rpg, char **name)
{
    rpg->menu[14] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 500}, (sfIntRect){0, 0, 310, 78}, SOUND);
    rpg->menu[15] = create_object("assets/sprites/menu/minus.png", //plus.png
    (sfVector2f){680, 700}, (sfIntRect){0, 0, 200, 200}, MINUS_MUSIC); //PLUS_MUSIC
    rpg->menu[16] = create_object("assets/sprites/menu/plus.png", //minus.png
    (sfVector2f){1160, 700}, (sfIntRect){0, 0, 200, 200}, PLUS_MUSIC); //MINUS_MINUS
    rpg->menu[17] = create_object("assets/sprites/menu/background_menu.png",
    (sfVector2f){-10, -10}, (sfIntRect){0, 0, 1026, 642}, BACKGROUND);
    for (int i = 0; i < 14; i += 1)
        make_text(&rpg->text[i], name[i], "assets/fonts/virus2.TTF");
    for (int i = 18; i < 22; i += 1)
        make_text(&rpg->text[i], name[i - 4], "assets/fonts/virus2.TTF");
    make_saves(rpg, name);
    for (int i = 0; i < 3; i += 1)
        rpg->clock[i].clock = sfClock_create();
}

void set2(rpg_t *rpg, char **name)
{
    rpg->menu[8] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 200}, (sfIntRect){0, 0, 310, 78}, FPS);
    rpg->menu[9] = create_object("assets/sprites/menu/minus.png", //plus.png
    (sfVector2f){680, 400}, (sfIntRect){0, 0, 200, 200}, MINUS_FPS); //PLUS_FPS
    rpg->menu[10] = create_object("assets/sprites/menu/plus.png", //minus.png
    (sfVector2f){1160, 400}, (sfIntRect){0, 0, 200, 200}, PLUS_FPS); //MINUS_FPS
    rpg->menu[11] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 100}, (sfIntRect){0, 0, 310, 78}, MUSIC);
    rpg->menu[12] = create_object("assets/sprites/menu/minus.png", //plus.png
    (sfVector2f){680, 300}, (sfIntRect){0, 0, 200, 200}, MINUS_EFFECT); //PLUS_EFFECT
    rpg->menu[13] = create_object("assets/sprites/menu/plus.png", //minus.png
    (sfVector2f){1160, 300}, (sfIntRect){0, 0, 200, 200}, PLUS_EFFECT); //MINUS_EFFECT
    set3(rpg, name);
}