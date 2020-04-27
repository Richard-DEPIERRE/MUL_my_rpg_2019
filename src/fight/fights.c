/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fights
*/

#include "rpg.h"

void init_values_before_fight(fight_t *fight)
{
    for (int i = 0; i < 5; i++) {
        fight->spell[i].activated = 0;
        sfClock_restart(fight->spell[i].clock);
        fight->spell[i].text.str = NULL;
        fight->spell[i].tmp = 0;
        fight->spell[i].tmp2 = 0;
    }
}

void reset_ennemies(fight_t *fight)
{
    fight->nb_enn = generate_random(2, 5);
    for (int i = 0; i < 5; i++) {
        fight->enns[i].in_live = 1;
        fight->enns[i].life = 100;
        fight->enns[i].tmp = 0;
        fight->enns[i].pos.x = generate_random(100, 1820);
        fight->enns[i].pos.y = generate_random(100, 980);
        fight->enns[i].velocity = generate_random(50, 100) / 10;
        fight->enns[i].velocity /= 10;
        if (i % 2 == 0) {
            fight->enns[i].rect.left = 0;
        } else
            fight->enns[i].rect.left = 150;
        sfSprite_setTextureRect(fight->enns[i].enn, fight->enns[i].rect);
    }
}

void check_end_fight(fight_t *fight, rpg_t *rpg)
{
    int count = 0;

    if (fight->player.life <= 0) {
        reset_ennemies(fight);
        stop_all_music(rpg);
        sfSound_play(rpg->snd_loose);
        rpg->status = 9; // ce status correspondra à l'écran de game over
        fight->player.life = 100;
        fight->buttons[3].rect.width = fight->player.life * 2 + 4;
        sfSprite_setTextureRect(fight->buttons[3].sprite, fight->buttons[3].rect);
        fight->player.pos = (sfVector2f){1920 / 2, 1080 / 2};
        sfSprite_setPosition(fight->player.player, fight->player.pos);
    }
    for (int i = 0; i < fight->nb_enn; i++)
        if (fight->enns[i].in_live == 0)
            count += 1;
    if (count == fight->nb_enn) {
        reset_ennemies(fight);
        sfSound_play(rpg->snd_win_fight);
        printf("Player a bien gagné son combat\n");
        rpg->quest.scd_quest.nb_win += 1;
        rpg->status = 10; //le joueur revient au jeu
    }
    if (rpg->status == 10 && fight->player.pos.x >= 1880) {
        fight->player.pos = (sfVector2f){1920 / 2, 1080 / 2};
        sfSprite_setPosition(fight->player.player, fight->player.pos);
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
    }
}

void display_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    check_end_fight(fight, rpg);
    update_fights(fight, rpg);
    draw_fights(fight, win, rpg);
}