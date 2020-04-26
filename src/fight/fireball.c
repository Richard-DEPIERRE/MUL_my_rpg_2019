/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fireball
*/

#include "rpg.h"

void launch_first_fireball(fight_t *fight)
{
    // if (fight->player.direct == 0 || fight->player.direct == 5) {
    //         pos_rotat(&final_pos, player_pos, 90, fight->spell[0].sprite);
    //     } else if (fight->player.direct == 1) {
    //         pos_rotat(&final_pos, player_pos, 270, fight->spell[0].sprite);
    //     } else if (fight->player.direct == 3) {
    //         pos_rotat(&final_pos, player_pos, 0, fight->spell[0].sprite);
    //     } else if (fight->player.direct == 7) {
    //         pos_rotat(&final_pos, player_pos, 180, fight->spell[0].sprite);
    //     }
    //     fight->spell[0].pos = player_pos;
    //     fight->spell[0].direction = fight->player.direct;
    //     sfSprite_setPosition(fight->spell[0].sprite, fight->spell[0].pos);
    //     fight->spell[0].final_pos = final_pos;
    //     fight->spell[0].activated = 1;
}

void launch_fireball(fight_t *fight)
{
    // static int current = 0;

    // if (current == 0) {
    //     launch_first_fireball();
    //     current = 1;
    // } else {
    //     update_fireball();
    //     if (cas_special)
    //         current = 0;
    // }
}
