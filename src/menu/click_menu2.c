/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

void click_menu_zero(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 152 && mouse.x < 534 &&
    mouse.y > 200 && mouse.y < 309.2)
        rpg->menu_status = 5;
    if (mouse.x > 152 && mouse.x < 534 &&
    mouse.y > 400 && mouse.y < 509.2)
        rpg->menu_status = 4;
    if (mouse.x > 152 && mouse.x < 534 &&
    mouse.y > 600 && mouse.y < 709.2)
        rpg->menu_status = 1;
    if (mouse.x > 152 && mouse.x < 534 &&
    mouse.y > 800 && mouse.y < 909.2)
        sfRenderWindow_close(rpg->win);
}

void click_start_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2) {
        rpg->save = 2;
        rpg->status = 3;
        init_save(rpg, obj);
    }
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2) {
        rpg->save = 3;
        rpg->status = 3;
        init_save(rpg, obj);
    }
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2) {
        rpg->save = 1;
        rpg->status = 3;
        init_save(rpg, obj);
    }
}