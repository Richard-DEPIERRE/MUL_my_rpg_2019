/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_statue
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

void display_item(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->quest.act != 0) {
        sfVector2f pos;
        pos.x = (rpg->quest.pos.x - rpg->quest.x) * 2;
        pos.y = (rpg->quest.pos.y - rpg->quest.y) * 2;
        sfSprite_setPosition(rpg->quest.sprite, pos);
        sfRenderWindow_drawSprite(win, rpg->quest.sprite, NULL);
    }
}

void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj)
{
    if (rpg->status == 0)
        draw_menu(rpg, win);
    if (rpg->status == 1)
        draw_options(rpg, win);
    if (rpg->status == 3) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, obj->sprite, NULL);
        display_item(win, rpg, obj);
        sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
        sfRenderWindow_drawSprite(win, rpg->perspec.sprite, NULL);
        sfRenderWindow_drawSprite(win, rpg->menu[18].sprite, NULL);
        sfRenderWindow_drawSprite(win, rpg->quest.arrow, NULL);
        if (rpg->quest.message == 1)
            sfRenderWindow_drawSprite(win, rpg->quest.msg, NULL);
        for (size_t index = 0; index < PARICULE_MAX; index++)
                display_particle(win, &rpg->screen->particle[index], \
                rpg->screen->particle_environment.circle_shape);
        sfRenderWindow_display(win);
    }
    if (rpg->status == 7) {
        draw_tuto(win, rpg, obj);
    }
}