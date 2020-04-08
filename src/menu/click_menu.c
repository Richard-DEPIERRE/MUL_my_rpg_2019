/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "my.h"

void check_plus_minus(rpg_t *rpg, sfVector2i mouse)
{
    if (rpg->music_volume > 100)
        rpg->music_volume = 100;
    if (rpg->music_volume < 0)
        rpg->music_volume = 0;
    if (rpg->sound_volume > 100)
        rpg->sound_volume = 100;
    if (rpg->sound_volume < 0)
        rpg->sound_volume = 0;
    if (rpg->fps < 30)
        rpg->fps = 30;
    if (rpg->fps > 120)
        rpg->fps = 120;
    sfText_setString(rpg->text[8].text, int_to_char(rpg->fps));
    sfText_setString(rpg->text[11].text, int_to_char(rpg->music_volume));
    sfText_setString(rpg->text[13].text, int_to_char(rpg->sound_volume));
}

void click_menu_one(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2)
        rpg->menu_status = 2;
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2)
        rpg->menu_status = 3;
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2)
        rpg->menu_status = 0;
}

void click_menu_two(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 400 && mouse.y < 480)
        rpg->fps += 30;
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 400 && mouse.y < 480)
        rpg->fps -= 30;
    if (mouse.x > 1510 && mouse.x < 1920 &&
    mouse.y > 910 && mouse.y < 1080)
        rpg->menu_status = 1;
}

void click_menu_three(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 700 && mouse.y < 780)
        rpg->sound_volume += 1;
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 700 && mouse.y < 780)
        rpg->sound_volume -= 1;
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 300 && mouse.y < 380)
        rpg->music_volume += 1;
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 300 && mouse.y < 380)
        rpg->music_volume -= 1;
    if (mouse.x > 1510 && mouse.x < 1920 &&
    mouse.y > 910 && mouse.y < 1080)
        rpg->menu_status = 1;
}

void click_menu(rpg_t *rpg, sfVector2i mouse)
{
    if (rpg->menu_status == 0) {
        if (mouse.x > 152 && mouse.x < 534 &&
        mouse.y > 200 && mouse.y < 309.2)
            rpg->status = 3;
        if (mouse.x > 152 && mouse.x < 534 &&
        mouse.y > 400 && mouse.y < 509.2)
            rpg->status = 2;
        if (mouse.x > 152 && mouse.x < 534 &&
        mouse.y > 600 && mouse.y < 709.2)
            rpg->menu_status = 1;
        if (mouse.x > 152 && mouse.x < 534 &&
        mouse.y > 800 && mouse.y < 909.2)
            sfRenderWindow_close(rpg->win);
    } else if (rpg->menu_status == 1)
        click_menu_one(rpg, mouse);
    else
        if (rpg->menu_status == 2)
            click_menu_two(rpg, mouse);
        else if (rpg->menu_status == 3)
            click_menu_three(rpg, mouse);
    check_plus_minus(rpg, mouse);
}