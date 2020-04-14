/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_statue
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj)
{
    if (rpg->status == 0)
        draw_menu(rpg, win);
    if (rpg->status == 1)
        draw_options(rpg, win);
    if (rpg->status == 3) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, obj->sprite, NULL);
        sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
        sfRenderWindow_drawSprite(win, rpg->menu[18].sprite, NULL);
        for (size_t index = 0; index != PARICULE_MAX; index++)
                display_particle(win, &rpg->screen->particle[index], \
                rpg->screen->particle_environment.circle_shape);
        sfRenderWindow_display(win);
    }
}