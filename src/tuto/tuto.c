/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tuto
*/

#include "rpg.h"

void action_two(rpg_t *rpg, game_obj_t *background)
{
    rpg->status = 3;
}

void action_one(rpg_t *rpg, game_obj_t *background)
{
    printf("tmp : %d\n", rpg->tuto->tmp);
    if (rpg->tuto->tmp < 125) {
        background->rect.top += 1;
        rpg->perspec.rect = background->rect;
        sfSprite_setTextureRect(background->sprite, background->rect);
        sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
        move_down(&rpg->player);
        rpg->tuto->tmp += 1;
    } else {
        dont_move(&rpg->player);

        rpg->tuto->action = 2;
        rpg->tuto->tmp = 0;
    }
}

void set_tuto(rpg_t *rpg, game_obj_t *background)
{
    rpg->tuto->tmp = 0;
    background->rect.top = 880;
    background->rect.left = 1280;
    rpg->perspec.rect = background->rect;
    sfSprite_setTextureRect(background->sprite, background->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

void tuto(rpg_t *rpg, game_obj_t *background)
{
    sfTime time = sfClock_getElapsedTime(rpg->tuto->clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.09) {
        if (rpg->tuto->action == 0) {
            set_tuto(rpg, background);
            rpg->tuto->action = 1;
        } else if (rpg->tuto->action == 1) {
            action_one(rpg, background);
        } else if (rpg->tuto->action == 2) {
            action_two(rpg, background);
        }
        sfClock_restart(rpg->tuto->clock);
    }
}