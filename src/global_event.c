/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"

int player_deplacement(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (sfKeyboard_isKeyPressed(sfKeyD))
            printf("haut droite\n");
        else if (sfKeyboard_isKeyPressed(sfKeyQ))
            printf("haut gauche\n");
        else
            move_up(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (sfKeyboard_isKeyPressed(sfKeyD))
            printf("bas droite\n");
        else if (sfKeyboard_isKeyPressed(sfKeyQ))
            printf("bas gauche\n");
        else
            move_down(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_left(&rpg->player);
    else if (sfKeyboard_isKeyPressed(sfKeyD))
        move_right(&rpg->player);
    else {
        dont_move(&rpg->player);
    }
    return (0);
}

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
        // printf("tap -> %c\n", rpg->evnt.key.code);
    }
}

void global_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg);
    }
    player_deplacement(rpg);
}