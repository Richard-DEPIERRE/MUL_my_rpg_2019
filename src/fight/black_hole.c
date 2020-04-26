/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** black_hole
*/

#include "rpg.h"

void update_black_hole(fight_t *fight)
{

}

void launch_first_black_hole(fight_t *fight, sfVector2f player_pos)
{
    fight->spell[2].activated = 1;
}

void launch_black_hole(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[2].activated == 0) {
        launch_first_black_hole(fight, fight->player.pos);
    } else {
        update_black_hole(fight);
    }
}
