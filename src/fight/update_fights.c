/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_fights
*/

#include "rpg.h"

float get_distance(sfVector2f p1, sfVector2f p2)
{
    const float dx = (p2.x) - p1.x;
    const float dy = (p2.y)- p1.y;

    return (sqrt(dx * dx + dy * dy));
}

void where_to_move(ennemies_t *ennemies, float truc1, float truc2)
{
    if (fabs(truc1) >= fabs(truc2))
        if (truc1 >= 0)
            ennemies->rect.top = 76;
        else
            ennemies->rect.top = 146;
    else
        if (truc2 >= 0)
            ennemies->rect.top = 216;
        else
            ennemies->rect.top = 6;
}

void animate_enemy(ennemies_t *ennemies)
{
    ennemies->clock.time = sfClock_getElapsedTime(ennemies->clock.clock);
    ennemies->clock.second = ennemies->clock.time.microseconds / 1000000.0;
    if (ennemies->clock.second > 0.5) {
        if (ennemies->tmp == 0 || ennemies->tmp == 1)
            ennemies->rect.left += 54;
        else {
            ennemies->rect.left -= 104;
            ennemies->tmp = -1;
        }
    }
    ennemies->tmp += 1;
}

void ennemies_deplacements(fight_t *fight)
{
    for (int i = 0; i < fight->nb_enn; i++) {
        float distance = get_distance(fight->enns[i].pos, fight->player.pos);
        float x = fight->enns[i].pos.x - fight->player.pos.x;
        float y = fight->enns[i].pos.y - fight->player.pos.y;

        float truc1 = (x / distance) * 0.7;
        float truc2 = (y / distance) * 0.7;

        fight->enns[i].pos.x -= truc1;
        fight->enns[i].pos.y -= truc2;
        where_to_move(&fight->enns[i], truc1, truc2);
        animate_enemy(&fight->enns[i]);
        sfSprite_setTextureRect(fight->enns[i].enn, fight->enns[i].rect);
        sfSprite_setPosition(fight->enns[i].enn, fight->enns[i].pos);
    }
}

void update_fights(fight_t *fight)
{
    ennemies_deplacements(fight);
    //ici on va s'occuper de faire bouger les ennemies, de faire bouger le perso, de faire la hitbox
    //en fait de tout pour le fight mise à part le draw
}