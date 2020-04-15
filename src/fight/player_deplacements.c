/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_deplacements
*/

#include "rpg.h"

int keys(player_fight_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->pos.x > 10) {
        player->pos.x -= 2;
        return (move_left_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->pos.x < 1910) {
        player->pos.x += 2;
        return (move_right_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && player->pos.y > 10) {
        player->pos.y -= 2;
        return (move_up_fight(player));
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->pos.y < 1040) {
        player->pos.y += 2;
        return (move_down_fight(player));
    }
    return (dont_move_fight(player));
}

void animation_player_fight(player_fight_t *player, clock_s *clock)
{
    keys(player);
    int direct = player->direct;
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;
    if (clock->second > 0.06) {
        if (direct == 1 || direct == 3 || direct == 5 || direct == 7) {
            if (player->rect.left < 64 * 7 + 32) {
                player->rect.left += 64;
            } else
                player->rect.left = 64;
        }
        sfSprite_setTextureRect(player->player, player->rect);
        sfClock_restart(clock->clock);
    }
}

void player_deplacements(player_fight_t *player)
{
    int a = 0;

    animation_player_fight(player, &player->clock);
    sfSprite_setPosition(player->player, player->pos);
}