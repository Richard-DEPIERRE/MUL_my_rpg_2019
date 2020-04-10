/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** draw_fights
*/

#include "rpg.h"

void draw_fights(fight_t *fight, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    //ici on draw
    sfRenderWindow_drawSprite(win, fight->background, NULL);
    for (int i = 0; i < fight->nb_enn; i++)
        sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
    sfRenderWindow_drawSprite(win,fight->player.player, NULL);
    sfRenderWindow_display(win);
}
