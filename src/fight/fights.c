/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fights
*/

#include "rpg.h"

void reset_ennemies(fight_t *fight)
{
    fight->nb_enn = generate_random(2, 5);
    for (int i = 0; i < 5; i++) {
        fight->enns[i].in_live = 1;
        fight->enns[i].life = 1;
        fight->enns[i].tmp = 0;
        fight->enns[i].pos.x = generate_random(100, 1820);
        fight->enns[i].pos.y = generate_random(100, 980);
        fight->enns[i].velocity = generate_random(50, 100) / 10;
        fight->enns[i].velocity /= 10;
    }
}

void check_end_fight(fight_t *fight, rpg_t *rpg)
{
    int count = 0;

    if (fight->player.life == 0) {
        reset_ennemies(fight);
        rpg->status = 9; // ce status correspondra à l'écran de game over
    }
    for (int i = 0; i < fight->nb_enn; i++) {
        if (fight->enns[i].in_live == 0) {
            count += 1;
        }
    }
    if (count == fight->nb_enn) {
        reset_ennemies(fight);
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