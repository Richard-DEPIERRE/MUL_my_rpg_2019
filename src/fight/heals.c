/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal
*/

#include "rpg.h"

void update_heals(fight_t *fight)
{

}

void launch_first_heals(fight_t *fight, sfVector2f player_pos)
{
    fight->spell[3].activated = 1;
}

void launch_heals(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[3].activated == 0) {
        launch_first_heals(fight, fight->player.pos);
    } else {
        update_heals(fight);
    }
}

