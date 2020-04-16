/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_tuto
*/

#include "rpg.h"

void draw_tuto(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj)
{
    sfRenderWindow_clear(win, sfBlack);

    sfRenderWindow_drawSprite(win, obj->sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->menu[18].sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->perspec.sprite, NULL);

    for (size_t index = 0; index != PARICULE_MAX; index++)
                display_particle(win, &rpg->screen->particle[index], \
                rpg->screen->particle_environment.circle_shape);

    sfRenderWindow_display(win);
}