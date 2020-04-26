/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** launch_spell
*/

#include "rpg.h"

// In file included from ./include/rpg.h:42:0,
//                  from src/clics_handlings.c:8:
// ./include/fight.h:91:35: error: unknown type name ‘rpg_t’; did you mean ‘fpos_t’?
//  void launch_spell(fight_t *fight, rpg_t *rpg);
//                                    ^~~~~
//                                    fpos_t


void launch_spell(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (fight->player.weapon == SPELL_ONE) {
            printf("lance la boule de feu\n");
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
}