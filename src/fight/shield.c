/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shield
*/

#include "rpg.h"

void update_shield(fight_t *fight)
{

}

void launch_first_shield(fight_t *fight, sfVector2f player_pos)
{
    fight->spell[1].activated = 1;
}

void launch_shield(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[1].activated == 0) {
        launch_first_shield(fight, fight->player.pos);
    } else {
        update_shield(fight);
    }
}

