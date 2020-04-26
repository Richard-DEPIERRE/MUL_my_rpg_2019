/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** speed
*/

#include "rpg.h"

void update_speed(fight_t *fight)
{

}

void launch_first_speed(fight_t *fight, sfVector2f player_pos)
{
    fight->spell[4].activated = 1;
}

void launch_speed(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[4].activated == 0) {
        launch_first_speed(fight, fight->player.pos);
    } else {
        update_speed(fight);
    }
}
