/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_boss
*/

#include "rpg.h"

static const attack_t attacks[] = {
    {attack_1},
    {attack_2},
    {attack_3}
};

void boss_attack(fight_t *fight)
{
    static int i = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss->clock.clock);
    float seconds = time.microseconds / 1000000;

    if (seconds >= 2) {
        i = generate_random(0, 2);
        sfClock_restart(fight->boss->clock.clock);
    }
    attacks[i].attack(fight);
}

void boss_anim(fight_t *fight)
{
    static int i = 0;
    static sfClock *clock = NULL;
    sfTime time;
    float seconds = 0;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000;
    if (seconds > 0.05) {
        i += 1;
        sfClock_restart(clock);
    }
    if (i == 7)
        i = 0;
    fight->boss->rect =
    (sfIntRect) {(i % 3) * 1164, (i / 3) * 1116, 1164, 1116};
    sfSprite_setTextureRect(fight->boss->enn, fight->boss->rect);
}

void move_boss(fight_t *fight)
{
    static int tmp = 0;
    float truc1 = 0;
    float truc2 = 0;
    float distance = get_distance(fight->boss->pos, fight->player.pos);
    float x = fight->boss->pos.x - fight->player.pos.x;
    float y = fight->boss->pos.y - fight->player.pos.y;

    truc1 = (x / distance) * fight->boss->velocity;
    truc2 = (y / distance) * fight->boss->velocity;
    fight->boss->pos.x -= truc1;
    fight->boss->pos.y -= truc2;
    where_to_move(fight->boss, truc1, truc2);
    sfSprite_setPosition(fight->boss->enn, fight->boss->pos);
    if (fight->boss->pos.x > fight->player.pos.x - 25 &&
    fight->boss->pos.x < fight->player.pos.x + 25 &&
    fight->boss->pos.y > fight->player.pos.y - 35 &&
    fight->boss->pos.y < fight->player.pos.y + 35)
        tmp = 1;
    boss_attack(fight);
    boss_anim(fight);
}

ennemies_t *init_boss(void)
{
    ennemies_t *obj = malloc(sizeof(ennemies_t));

    obj->enn = sfSprite_create();
    obj->enn_texture =
    sfTexture_createFromFile("assets/sprites/boss.png", NULL);
    obj->clock.clock = sfClock_create();
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {0, 0, 1164, 1116};
    obj->velocity = 0.01;
    sfSprite_setTexture(obj->enn, obj->enn_texture, sfTrue);
    sfSprite_setPosition(obj->enn, obj->pos);
    sfSprite_setTextureRect(obj->enn, obj->rect);
    sfSprite_setScale(obj->enn, (sfVector2f) {0.4, 0.4});
    sfSprite_setOrigin(obj->enn, (sfVector2f)
    {obj->rect.left + (obj->rect.width / 2),
    obj->rect.top + (obj->rect.height / 2)});
    return (obj);
}