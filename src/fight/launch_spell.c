/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** launch_spell
*/

#include "rpg.h"

void launch_spell(fight_t *fight, rpg_t *rpg)
{
    if (fight->player.weapon == SPELL_ONE) {
        // printf("lance la boule de feu\n");
        launch_fireball(fight, rpg);
    } else if (fight->player.weapon == SPELL_TWO) {
        printf("lance le shield\n");
        launch_shield(fight, rpg);
    } else if (fight->player.weapon == SPELL_THREE) {
        printf("lance le black hole\n");
        launch_black_hole(fight, rpg);
    } else if (fight->player.weapon == SPELL_FOUR) {
        printf("lance le soin\n");
        launch_heals(fight, rpg);
    } else if (fight->player.weapon == SPELL_FIVE) {
        printf("lance le bonus de vitesse\n");
        launch_speed(fight, rpg);
    }
}