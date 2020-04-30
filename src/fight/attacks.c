/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attacks
*/

#include "rpg.h"

spell_t use_spell(spell_t spell, fight_t *fight, int value)
{
    static int test = 0;
    sfTime time;
    static sfVector2f delta = {0, 0};

    if (value == 0) {
        spell.activated = 1;
        spell.pos = fight->boss->pos;
        spell.final_pos = fight->player.pos;
        delta.x = (spell.pos.x - spell.final_pos.x) / 100;
        delta.y = (spell.pos.y - spell.final_pos.y) / 100;
        sfSprite_setPosition(spell.sprite, spell.pos);
        return (spell);
    }
    if (fabs(spell.pos.x - spell.final_pos.x) < fabs(delta.x * 5)
    || fabs(spell.pos.y - spell.final_pos.y) < fabs(delta.y * 5)) {
        spell.pos = spell.final_pos;
        spell.activated = 0;
    }
    else {
        spell.pos.x -= delta.x;
        spell.pos.y -= delta.y;
    }
    sfSprite_setPosition(spell.sprite, spell.pos);
    return (spell);
}

void attack_1(fight_t *fight, float *max)
{
    int value = (*max == 1) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[0].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[0].clock);
    }
    if (anim == 5)
        anim = 0;
    *max = 1;
    fight->boss_spell[0].rect.left = (anim % 5) * 192;
    fight->boss_spell[0] = use_spell(fight->boss_spell[0], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[0].sprite,
    fight->boss_spell[0].rect);
}

void attack_2(fight_t *fight __attribute__((unused)), float *max)
{
    int value = (*max == 2) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[1].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[1].clock);
    }
    if (anim == 5)
        anim = 0;
    fight->boss_spell[1].rect.left = (anim % 5) * 192;
    *max = 2;
    fight->boss_spell[1] = use_spell(fight->boss_spell[1], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[1].sprite,
    fight->boss_spell[1].rect);
}

void attack_3(fight_t *fight __attribute__((unused)), float *max)
{
    int value = (*max == 3) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[2].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[2].clock);
    }
    if (anim == 5)
        anim = 0;
    fight->boss_spell[2].rect.left = (anim % 5) * 192;
    *max = 3;
    fight->boss_spell[2] = use_spell(fight->boss_spell[2], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[2].sprite,
    fight->boss_spell[2].rect);
}