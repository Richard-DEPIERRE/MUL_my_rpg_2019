/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "minishell.h"
#include "my.h"

void menu_destroy(rpg_t *rpg)
{
    for (int i = 0; i < 18; i += 1) {
        sfSprite_destroy(rpg->menu[i].sprite);
        sfTexture_destroy(rpg->menu[i].texture);
    }
    for (int i = 0; i < 3; i += 1)
        sfClock_destroy(rpg->clock[i].clock);
    for (int i = 0; i < 14; i += 1)
        sfText_destroy(rpg->text[i].text);
}