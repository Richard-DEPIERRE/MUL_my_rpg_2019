/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"

void press_button(rpg_t *rpg, BACK_R_t type)
{
    for (int i = 0; i < 17; i += 1)
        if (rpg->menu[i].type == type)
            rpg->menu[i].rect.left = rpg->menu[i].rect.width;
}

void release_button(rpg_t *rpg, BACK_R_t type)
{
    for (int i = 0; i < 17; i += 1)
        if (rpg->menu[i].type == type)
            rpg->menu[i].rect.left = 0;
}

void check_mouse_menu_one(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2)
        press_button(rpg, FPS);
    else
        release_button(rpg, FPS);
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2)
        press_button(rpg, SOUND);
    else
        release_button(rpg, SOUND);
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2)
        press_button(rpg, BACK);
    else
        release_button(rpg, BACK);
}

void check_mouse_menu_two(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 400 && mouse.y < 480)
        press_button(rpg, PLUS_FPS);
    else
        release_button(rpg, PLUS_FPS);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 400 && mouse.y < 480)
        press_button(rpg, MINUS_FPS);
    else
        release_button(rpg, MINUS_FPS);
}

void check_mouse_menu_three(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 700 && mouse.y < 780)
        press_button(rpg, PLUS_MUSIC);
    else
        release_button(rpg, PLUS_MUSIC);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 700 && mouse.y < 780)
        press_button(rpg, MINUS_MUSIC);
    else
        release_button(rpg, MINUS_MUSIC);
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 300 && mouse.y < 380)
        press_button(rpg, PLUS_EFFECT);
    else
        release_button(rpg, PLUS_EFFECT);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 300 && mouse.y < 380)
        press_button(rpg, MINUS_EFFECT);
    else
        release_button(rpg, MINUS_EFFECT);
}

void check_mouse_pos_menu(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    if (rpg->menu_status == 0)
        check_mouse_menu_zero(rpg, mouse);
    else if (rpg->menu_status == 1)
        check_mouse_menu_one(rpg, mouse);
    else
        if (rpg->menu_status == 2)
            check_mouse_menu_two(rpg, mouse);
        else if (rpg->menu_status == 3)
            check_mouse_menu_three(rpg, mouse);
    for (int i = 0; i < 17; i += 1)
        sfSprite_setTextureRect(rpg->menu[i].sprite, rpg->menu[i].rect);
}