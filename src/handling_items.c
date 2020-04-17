/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** handling_items
*/

#include "rpg.h"

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
        sfSprite_setTextureRect(rpg->quest.sprite, rpg->quest.rect);
        sfSprite_setPosition(rpg->quest.sprite, (sfVector2f) {0, 0});
    }
}

void handling_items(rpg_t *rpg)
{
    sfVector2f pos;
    pos.x = (rpg->quest.pos.x - rpg->quest.x) * 2;
    pos.y = (rpg->quest.pos.y - rpg->quest.y) * 2;

    printf("%f %f\n", (rpg->quest.pos.x - rpg->quest.x) * 2, (rpg->quest.pos.y - rpg->quest.y) * 2);
    printf("%d %d\n\n\n", rpg->quest.x, rpg->quest.y);
    if (rpg->player.pos.x > pos.x - 20 && rpg->player.pos.x < pos.x + 40 &&
    rpg->player.pos.y > pos.y - 20 && rpg->player.pos.y < pos.y + 40) {
        rpg->quest.message = 1;
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            change_item(rpg);
    } else {
        rpg->quest.message = 0;
    }
}