/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_particules
*/

#include "rpg.h"

int generate_random(int l, int r)
{
    return ((rand() % (r - l + 1)) + l);
}

ennemies_t set_enn(int i)
{
    ennemies_t enn;
    char path[] = "assets/sprites/ennemies.png";

    enn.enn_texture = sfTexture_createFromFile(path, NULL);
    enn.enn = sfSprite_create();
    sfSprite_setTexture(enn.enn, enn.enn_texture, sfTrue);
    enn.rect.width = 50;
    enn.rect.height = 70;
    enn.rect.top = 6;
    enn.life = 1;
    if (i % 2 == 0) {
        enn.rect.left = 0;
    } else
        enn.rect.left = 150;
    sfSprite_setTextureRect(enn.enn, enn.rect);
    enn.pos.x = generate_random(100, 1820);
    enn.pos.y = generate_random(100, 980);
    enn.tmp = 0;
    enn.in_live = 1;
    enn.clock.clock = sfClock_create();
    sfSprite_setPosition(enn.enn, enn.pos);
    sfSprite_setOrigin(enn.enn, (sfVector2f) {25, 35});
    return (enn);
}

void init_variables_for_particules(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
}

fight_t *init_variables_for_fights(fight_t *fight)
{
    fight = malloc(sizeof(fight_t));
    fight->enns = malloc(sizeof(ennemies_t) * 5);
    fight->background_texture = sfTexture_createFromFile("assets/maps/fight_map.png", NULL);
    fight->background = sfSprite_create();
    sfSprite_setPosition(fight->background, (sfVector2f){0, 0});
    sfSprite_setTexture(fight->background, fight->background_texture, sfTrue);
    sfSprite_setTextureRect(fight->background, (sfIntRect){52, 0, 1920, 1080});
    fight->player.player_texture = sfTexture_createFromFile("assets/sprites/character.png", NULL);
    fight->player.player = sfSprite_create();
    fight->player.rect = (sfIntRect) {0, 0, 64, 64};
    fight->player.pos.x = (1920 / 2) - (64 / 2);
    fight->player.pos.y = (1080 / 2) - (64 / 2);
    fight->player.life = 3;
    sfSprite_setOrigin(fight->player.player, (sfVector2f) {32, 32});
    sfSprite_setTexture(fight->player.player, fight->player.player_texture, sfTrue);
    sfSprite_setTextureRect(fight->player.player, fight->player.rect);
    sfSprite_setPosition(fight->player.player, fight->player.pos);
    fight->nb_enn = 5;
    srand(time(0));
    for (int i = 0; i < 5; i++)
        fight->enns[i] = set_enn(i);
    return (fight);
}