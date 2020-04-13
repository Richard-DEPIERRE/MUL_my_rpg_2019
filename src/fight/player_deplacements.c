/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_deplacements
*/

#include "rpg.h"

void player_deplacements(fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) && fight->player.pos.x > 10) {
        fight->player.pos.x -= 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && fight->player.pos.x < 1910) {
        fight->player.pos.x += 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && fight->player.pos.y > 10) {
        fight->player.pos.y -= 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && fight->player.pos.y < 1040) {
        fight->player.pos.y += 2;
    }
    sfSprite_setPosition(fight->player.player, fight->player.pos);
}