/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "minishell.h"
#include "my.h"

void draw_menu2(rpg_t *rpg, sfRenderWindow *win)
{
    if (rpg->menu_status == 2) {
        for (int i = 8; i < 11; i += 1)
            sfRenderWindow_drawSprite(win, rpg->menu[i].sprite, NULL);
        sfRenderWindow_drawText(win, rpg->text[7].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[8].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[9].text, NULL);
    }
    if (rpg->menu_status == 3) {
        for (int i = 11; i < 17; i += 1)
            sfRenderWindow_drawSprite(win, rpg->menu[i].sprite, NULL);
        sfRenderWindow_drawText(win, rpg->text[9].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[10].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[11].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[12].text, NULL);
        sfRenderWindow_drawText(win, rpg->text[13].text, NULL);
    }
}

void draw_menu(rpg_t *rpg, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, rpg->menu[17].sprite, NULL);
    if (rpg->menu_status == 0) {
        for (int i = 0; i < 5; i += 1)
            sfRenderWindow_drawSprite(win, rpg->menu[i].sprite, NULL);
        for (int i = 0; i < 4; i += 1)
            sfRenderWindow_drawText(win, rpg->text[i].text, NULL);
    }
    if (rpg->menu_status == 1) {
        for (int i = 5; i < 8; i += 1)
            sfRenderWindow_drawSprite(win, rpg->menu[i].sprite, NULL);
        for (int i = 4; i < 7; i += 1)
            sfRenderWindow_drawText(win, rpg->text[i].text, NULL);
    }
    draw_menu2(rpg, win);
    sfRenderWindow_display(win);
}