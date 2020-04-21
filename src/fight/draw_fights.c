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
    sfRectangleShape_setPosition(fight->inventory.show,
    (sfVector2f) {((fight->player.weapon) * 110) + 603, 935});
    sfRenderWindow_drawSprite(win, fight->background, NULL);
    for (int i = 0; i < fight->nb_enn; i++)
        if (fight->enns[i].in_live)
            sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
    sfRenderWindow_drawSprite(win, fight->inventory.sprite, NULL);
    sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
    sfRenderWindow_drawSprite(win, fight->player.player, NULL);
    for (int i = 0; i < 3; i++)
        if (fight->spell[i].activated == 1)
            sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
    sfRenderWindow_display(win);
}
