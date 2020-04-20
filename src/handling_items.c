/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handling_items
*/

#include "rpg.h"

float angle(rpg_t *rpg, sfVector2f pos)
{
    double diff_x = (960 - pos.x);
    double diff_y =  (540 - pos.y);
    float angle = atan2f(diff_y, diff_x) * (180.0 / M_PI) - 90;

    return (angle);
}

void change_item(rpg_t *rpg)
{
    if (rpg->quest.act == 1) {
        rpg->quest.act = 2;
        rpg->quest.rect.left = 30;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 2080;
        rpg->quest.pos.y = 1706;
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
    } else if (rpg->quest.act == 2) {
        rpg->quest.act = 3;
        rpg->quest.rect.left = 60;
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        rpg->quest.pos.x = 232;
        rpg->quest.pos.y = 717;
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
    } else if (rpg->quest.act == 3) {
        rpg->quest.rect.width = 0;
        rpg->quest.act = 0;
        rpg->quest.pos = (sfVector2f) {527, 1867};
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        sfSprite_setPosition(rpg->quest.sprite, rpg->quest.pos);
    }
}

void handling_items(rpg_t *rpg)
{
    sfVector2f pos;
    pos.x = (rpg->quest.pos.x - rpg->quest.x) * 2;
    pos.y = (rpg->quest.pos.y - rpg->quest.y) * 2;
    // printf("x : %f | y : %f\n", pos.x, pos.y);
    if (rpg->player.pos.x > pos.x - 20 && rpg->player.pos.x < pos.x + 40 &&
    rpg->player.pos.y > pos.y - 20 && rpg->player.pos.y < pos.y + 40) {
        rpg->quest.message = 1;
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            change_item(rpg);
    } else {
        rpg->quest.message = 0;
    }
    sfSprite_setRotation(rpg->quest.arrow, angle(rpg, pos));
}