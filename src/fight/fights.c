/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fights
*/

#include "rpg.h"

void check_end_fight(fight_t *fight, rpg_t *rpg)
{
    int count = 0;

    if (fight->player.life == 0) {
        printf("Player est mort\nGo Afficher écran de Game Over\n");
        rpg->status = 0; // ce status correspondra à l'écran de game over
    }
    for (int i = 0; i < fight->nb_enn; i++) {
        if (fight->enns[i].in_live == 0) {
            count += 1;
        }
    }
    if (count == fight->nb_enn) {
        printf("Player a bien gagné son combat\n");
        rpg->status = 3; //le joueur revient au jeu
    }
}

void display_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    check_end_fight(fight, rpg);
    update_fights(fight);
    draw_fights(fight, win);
}