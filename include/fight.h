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

typedef enum WEAPONS
{
    SHOVEL,
    SPELL_ONE,
    SPELL_TWO,
    SPELL_THREE,
    SPELL_FOUR,
    SPELL_FIVE,
    SPELL_SIX
} WEAPONS;

typedef enum spells_names_s {
    FIREBALL,
    SHIELD,
    BLACK_HOLE,
    HEALTH,
    SPEEDS
} spells_names_t;

typedef struct player_fight_s
{
    sfSprite *player;
    sfTexture *player_texture;
    clock_s clock;
    clock_s clock2;
    sfIntRect rect;
    sfVector2f pos;
    int direct; //0 ne bouge pas, 1 monte, 2 monte à droite, 3 à droite, 4 descends à droite, 5 descends, 6 descends à gauche, 7 à gauche, 8 monte à gauche
    int life;
    WEAPONS weapon;
} player_fight_t;


typedef struct spell_s {
    int tmp;
    int tmp2;
    text_R_t text;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int damage;
    int velocity;
    int protection;
    int activated;
    int direction;
    sfVector2f final_pos;
    sfClock *clock;
    sfClock *health;
    clock_R_t clock_cd;
    spells_names_t type;
    float sec;
    int calc;
}  spell_t;

typedef struct inventory_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *show;
    sfVector2f pos;
} inventory_t;

typedef struct fight_s
{
    game_obj_R_t *buttons;
    sfSprite *background;
    sfTexture *defaultt;
    sfIntRect rect;
    // sfTexture *condom;
    // sfTexture *corona;
    // sfTexture *gel;
    // sfTexture *boss;
    player_fight_t player;
    spell_t *spell;
    ennemies_t *enns;
    inventory_t inventory;
    int nb_enn;
    /*sfSound *snd_main_music;
    sfSound *snd_fireball;
    sfSound *snd_shield;
    sfSound *snd_black_hole;
    sfSound *snd_heal;
    sfSound *snd_speed;
    sfSound *snd_win_fight;*/
}fight_t;

spell_t init_spell(char *path, spells_names_t type, sfIntRect rect);
void fireball(fight_t *fight, sfVector2f player_pos);

#endif /* !FIGHT_H_ */
