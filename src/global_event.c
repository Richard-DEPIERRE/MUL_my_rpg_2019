/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "minishell.h"

void analyse_event(rpg_t *rpg)
{
    if (rpg->evnt.type == sfEvtClosed || (rpg->evnt.type == sfEvtKeyPressed \
    && rpg->evnt.key.code == sfKeyEscape)) {
        sfRenderWindow_close(rpg->win);
    }
    if (rpg->evnt.type == sfEvtMouseButtonPressed) {
        clics_handlings(rpg->evnt.mouseButton, rpg);
        printf("clic\n");
    }
    if (rpg->evnt.type == sfEvtTextEntered) {
        printf("tap -> %c\n", rpg->evnt.key.code);
    }
}

void global_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg);
    }
    if (rpg->status == 0)
        check_mouse_pos_menu(rpg);
}