/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include "rpg.h"


typedef struct clock_c clock_s;
typedef struct ennemies ennemies_t;

typedef enum spells_names_s {
    FIREBALL,
    SHIELD,
    BLABLA
}spells_names_t;


typedef struct player_fight_s
{
    sfSprite *player;
    sfTexture *player_texture;

    sfIntRect rect;
    sfVector2f pos;
    int direction;
    int life;
}player_fight_t;

typedef struct spell_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;

    int damage;
    int velocity;
    int protection;
    int activated;

    sfVector2f final_pos;

    clock_s clock;
}spell_t;

typedef struct fight_s
{
    sfSprite *background;
    sfTexture *background_texture;

    player_fight_t player;
    spell_t *spell;
    ennemies_t *enns;
    int nb_enn;
}fight_t;




spell_t init_spell(char *path, enum spells_names_s type);
void launch_spell(fight_t *fight);
void fireball(fight_t *fight, sfVector2f player_pos);

#endif /* !FIGHT_H_ */
