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

void boss_attack(fight_t *fight, float *max)
{
    static int i = 0;
    int r = 0;
    static sfClock *clock = NULL;
    sfTime time;
    float seconds = 0;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000;
    for (int i = 0; i < 3; i += 1)
        r += fight->boss_spell[i].activated;
    if (r == 0 && seconds > 3) {
        i = generate_random(0, 2);
        sfClock_restart(clock);
        fight->boss_spell[i].activated = 1;
        fight->boss_spell[i].rect.left = 0;
    } else
        attacks[i].attack(fight, max);
}

void boss_anim(fight_t *fight)
{
    sfTime time = sfClock_getElapsedTime(fight->boss->clock.clock);
    float second = time.microseconds / 1000000;

    if (time.microseconds > 85000) {
        fight->boss->rect.left += 800;
        if (fight->boss->rect.left > (7 * 800)) {
            fight->boss->rect.left = 0;
            (fight->boss->rect.top == 0) ? (fight->boss->rect.top = 600) :
            (fight->boss->rect.top = 0);
        }
        sfClock_restart(fight->boss->clock.clock);
    }
    sfSprite_setTextureRect(fight->boss->enn, fight->boss->rect);
}

void move_boss_two(fight_t *fight, float truc1, float truc2)
{
    static float max = 0;
    static int tmp = 0;

    sfSprite_setPosition(fight->boss->enn, fight->boss->pos);
    if (fight->boss->pos.x - 200 <= fight->player.pos.x - 25 &&
    fight->boss->pos.x + 200 >= fight->player.pos.x + 25 &&
    fight->boss->pos.y - 150 <= fight->player.pos.y - 35 &&
    fight->boss->pos.y + 150 >= fight->player.pos.y + 35)
        if ((fight->spell[fight->player.weapon - 1].protection == 0
        || fight->spell[fight->player.weapon - 1].activated != 1)) {
            knock_back(&fight->player, &fight->player.clock, truc1, truc2, tmp);
            fight->player.life -= 1;
            fight->buttons[3].rect.width = fight->player.life * 2 + 4;
            sfSprite_setTextureRect(fight->buttons[3].sprite, fight->buttons[3].rect);
        }
    boss_attack(fight, &max);
    boss_anim(fight);
}

void move_boss(fight_t *fight)
{
    float truc1 = 0;
    float truc2 = 0;
    float x = fight->boss->pos.x - fight->player.pos.x;
    float y = fight->boss->pos.y - fight->player.pos.y;
    float distance = sqrtf(x * x + y * y);

    if (distance > 400) {
        truc1 = (x / distance) * fight->boss->velocity;
        truc2 = (y / distance) * fight->boss->velocity;
        fight->boss->pos.x -= truc1;
        fight->boss->pos.y -= truc2;
    }
    move_boss_two(fight, truc1, truc2);
    // sfSprite_setPosition(fight->boss->enn, fight->boss->pos);
    // if (fight->boss->pos.x - 200 <= fight->player.pos.x - 25 &&
    // fight->boss->pos.x + 200 >= fight->player.pos.x + 25 &&
    // fight->boss->pos.y - 150 <= fight->player.pos.y - 35 &&
    // fight->boss->pos.y + 150 >= fight->player.pos.y + 35)
    //     if ((fight->spell[fight->player.weapon - 1].protection == 0
    //     || fight->spell[fight->player.weapon - 1].activated != 1)) {
    //         knock_back(&fight->player, &fight->player.clock, truc1, truc2, tmp);
    //         fight->player.life -= 1;
    //         fight->buttons[3].rect.width = fight->player.life * 2 + 4;
    //         sfSprite_setTextureRect(fight->buttons[3].sprite, fight->buttons[3].rect);
    //     }
    // boss_attack(fight, &max);
    // boss_anim(fight);
}

ennemies_t *init_boss(void)
{
    ennemies_t *obj = malloc(sizeof(ennemies_t));

    obj->enn = sfSprite_create();
    obj->enn_texture =
    sfTexture_createFromFile("assets/sprites/boss/boss.png", NULL);
    obj->clock.clock = sfClock_create();
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {0, 0, 800, 600};
    obj->velocity = 0.8;
    obj->in_live = 1;
    obj->life = 8000;
    sfSprite_setTexture(obj->enn, obj->enn_texture, sfTrue);
    sfSprite_setPosition(obj->enn, obj->pos);
    sfSprite_setTextureRect(obj->enn, obj->rect);
    sfSprite_setOrigin(obj->enn, (sfVector2f)
    {obj->rect.left + (obj->rect.width / 2),
    obj->rect.top + (obj->rect.height / 2)});
    return (obj);
}

spell_t *init_boss_spell(void)
{
    spell_t *obj = malloc(sizeof(spell_t) * 3);

    for (int i = 0; i < 3; i += 1) {
        obj[i].sprite = sfSprite_create();
        obj[i].texture = sfTexture_createFromFile(
        "assets/sprites/boss/spells.png", NULL);
        obj[i].clock = sfClock_create();
        sfSprite_setTexture(obj[i].sprite, obj[i].texture, sfFalse);
        obj[i].rect = (sfIntRect) {0, 192 * i, 192, 192};
        sfSprite_setOrigin(obj[i].sprite, (sfVector2f) {96, 96});
        if (i == 2)
            obj[i].rect.top = 5 * 192;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
    return (obj);
}