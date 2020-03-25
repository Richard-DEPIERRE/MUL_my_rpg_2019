/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_statue
*/

#include "my.h"
#include "rpg.h"
#include "minishell.h"

void draw_statue(rpg_t *rpg, sfRenderWindow *win)
{
    if (rpg->status == 0)
        draw_menu(rpg, win);
    if (rpg->status == 1)
        draw_options(rpg, win);
    //et tu rajoutes chaque partie du programme genre le jeu, ensuite le menu des sauvegardes etc.
}