/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock_event
*/

#include "my.h"
#include "rpg.h"
#include "minishell.h"

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
    if (rpg->menu[17].rect.top < 4494 && rpg->menu[17].rect.left != 5130)
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

void clock_event(rpg_t *rpg, clock_s clock)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.second = clock.time.microseconds / 1000000.0;

    if (clock.second > 0.09) {
        change_background_menu_rect(rpg);
        sfClock_restart(clock.clock);
    }
    sfRenderWindow_setFramerateLimit(rpg->win, rpg->fps);

}