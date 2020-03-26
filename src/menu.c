/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

void draw_menu(rpg_t *rpg, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    //ici tu peux par exemple faire des updates des éléments dans ton status genre par exemple update du mouvement des ennemies (qui bougent tout seuls)
    sfRenderWindow_drawSprite(win, rpg->delete_me, NULL);
    //là tu draws tes sprites

    sfRenderWindow_display(win);
}