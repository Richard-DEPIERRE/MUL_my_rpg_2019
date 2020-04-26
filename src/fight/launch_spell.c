/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** launch_spell
*/

#include "rpg.h"

void updates_spells(fight_t *fight, rpg_t *rpg)
{
    if (fight->spell[0].activated > 0 && fight->spell[0].tmp == 1)
        fight->spell[0].tmp = update_fireballs(&fight->spell[0], fight->player.pos, fight, rpg);
    if (fight->spell[1].activated > 0 && fight->spell[1].tmp == 1)
        fight->spell[1].tmp = update_shield(&fight->spell[1], fight->player.pos, fight, rpg);
    if (fight->spell[2].activated > 0 && fight->spell[2].tmp == 1)
        fight->spell[2].tmp = update_black_holes(&fight->spell[2], fight->player.pos, fight, rpg);
}

void launch_spell(fight_t *fight, rpg_t *rpg)
{
    if (fight->player.weapon == SPELL_ONE) {
        // printf("lance la boule de feu\n");
        launch_fireball(fight, rpg);
    } else if (fight->player.weapon == SPELL_TWO) {
        // printf("lance le shield\n");
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
    updates_spells(fight, rpg);
}