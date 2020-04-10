/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fights
*/

#include "rpg.h"

void display_fights(fight_t *fight, sfRenderWindow *win)
{
    update_fights(fight);
    draw_fights(fight, win);
}