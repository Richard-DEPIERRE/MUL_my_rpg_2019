/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock_event
*/

#include "my.h"
#include "rpg.h"

//9

void animation_player(player_t *player)
{
    // printf("left : %d | top : %d\n", player->rect.left, player->rect.top);
    int direct = player->direct;
    if (direct == 1 || direct == 3 || direct == 5 || direct == 7) {
        if (player->rect.left < 64 * 7 + 32) {
            player->rect.left += 64;
        } else
            player->rect.left = 64;
    }
    // if (player->direct == 5) {
    //     if (player->rect.left < 64 * 7 + 32) {
    //         player->rect.left += 64;
    //     } else
    //         player->rect.left = 64;
    // }
    // printf("left : %d | top : %d\n", player->rect.left, player->rect.top);
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void clock_event(rpg_t *rpg, clock_s *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;

    if (clock->second > 0.06) {
        // printf("compte\n");
        if (rpg->player.direct != 0) {
            // printf("yolo\n");
            animation_player(&rpg->player);
            // printf("left : %d | top : %d\n\n\n", rpg->player.rect.left, rpg->player.rect.top);

        }
        //tu fais tes animations ici
        //si t'as besoin, tu changes la vitesse de la clock en changeant le 0.06

        sfClock_restart(clock->clock);
    }
}