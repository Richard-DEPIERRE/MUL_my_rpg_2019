/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"

void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 200 && mouse.y < 309.2)
        press_button(rpg, PLAY);
    else
        release_button(rpg, PLAY);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 400 && mouse.y < 509.2)
        press_button(rpg, CONTINUE);
    else
        release_button(rpg, CONTINUE);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 600 && mouse.y < 709.2)
        press_button(rpg, OPTIONS);
    else
        release_button(rpg, OPTIONS);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 800 && mouse.y < 909.2)
        press_button(rpg, QUIT);
    else
        release_button(rpg, QUIT);
}