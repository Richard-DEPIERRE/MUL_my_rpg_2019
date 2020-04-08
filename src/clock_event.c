/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock_event
*/

#include "my.h"
#include "rpg.h"

void last_check(rpg_t *rpg)
{
    if (rpg->menu[17].rect.left < 4104)
        rpg->menu[17].rect.left += 1026;
    else if (rpg->menu[17].rect.left == 4104) {
        rpg->menu[17].rect.top = 0;
        rpg->menu[17].rect.left = 5130;
    }
}

void change_background_menu_rect(rpg_t *rpg)
{
    if (rpg->menu[17].rect.top < 4494 && rpg->menu[17].rect.left < 5132)
        if (rpg->menu[17].rect.left < 4104)
            rpg->menu[17].rect.left += 1026;
        else {
            rpg->menu[17].rect.top += 642;
            rpg->menu[17].rect.left = 0;
        }
    else if (rpg->menu[17].rect.left == 5130)
        if (rpg->menu[17].rect.top < 1284)
            rpg->menu[17].rect.top += 642;
        else {
            rpg->menu[17].rect.top = 0;
            rpg->menu[17].rect.left = 0;
        }
    else
        last_check(rpg);
    sfSprite_setTextureRect(rpg->menu[17].sprite, rpg->menu[17].rect);
}

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
    rpg->player.clock.time = sfClock_getElapsedTime(rpg->player.clock.clock);
    rpg->player.clock.second = rpg->player.clock.time.microseconds / 1000000.0;

    if (rpg->player.clock.second > 0.06) {
        // printf("compte\n");
        if (rpg->player.direct != 0) {
            // printf("yolo\n");
            animation_player(&rpg->player);
            // printf("left : %d | top : %d\n\n\n", rpg->player.rect.left, rpg->player.rect.top);
        }
        sfClock_restart(rpg->player.clock.clock);
    }

    if (clock->second > 0.09) {
        change_background_menu_rect(rpg);
        sfClock_restart(clock->clock);
        //tu fais tes animations ici
        //si t'as besoin, tu changes la vitesse de la clock en changeant le 0.06
        sfClock_restart(clock->clock);
    }
    sfRenderWindow_setFramerateLimit(rpg->win, rpg->fps);

}