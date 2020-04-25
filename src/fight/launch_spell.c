/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** launch_spell
*/

#include "rpg.h"

void launch_spell(fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        // printf("ici\n");
        fireball(fight, fight->player.pos);
    }
}