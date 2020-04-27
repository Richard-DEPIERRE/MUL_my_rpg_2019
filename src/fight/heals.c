/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal
*/

#include "rpg.h"

void animation_health(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    printf("seconds:%f\n", second);
    if (second > 0.09) {
        if (spell->rect.left < 240 - 60) {
            spell->rect.left += 60;
        } else {
            spell->rect.left = 0;
            if (spell->rect.top < 300 - 60)
                spell->rect.top += 60;
            else
                spell->rect.top = 0;
        }
        sfClock_restart(spell->clock);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}

void launch_first_health(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    fight->spell[3].pos.x = player_pos.x + 50;
    fight->spell[3].pos.x = player_pos.y + 50;
    sfSprite_setPosition(fight->spell[3].sprite, fight->spell[3].pos);
    fight->spell[3].final_pos = final_pos;
    fight->spell[3].activated = 1;
    sfClock_restart(fight->spell[3].clock_cd.clock);
    fight->spell[3].calc = (int)((fight->player.life * 0.4) / 12);
    printf("CALC:%d\n", fight->spell[3].calc);
}

void set_cooldown_health(float res, spell_t *spell)
{
    /*char str[4];

    spell->text.str = "activate";
    ftoa(res, str, 2);
    sfText_setString(spell->text.text, str);*/
    char *str = ftoa(res, 2);
    sfText_setString(spell->text.text, str);
    spell->text.str = "activate";
}

void display_cooldown_health(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_health(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_health(spell_t *spell, fight_t *fight)
{
    static int tmp = 0;

    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && spell->clock_cd.seconds > 3 && tmp == 0) {
        // sfClock_restart(spell->clock_cd.clock);
        spell->activated = 2;
        tmp = 1;
        return (1);
    }
    if (spell->activated == 2)
        display_cooldown_health(spell->clock_cd.seconds, spell);
    if (spell->activated == 2 && spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        tmp = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}

void change_position_health(spell_t *spell, sfVector2f pos)
{
    static int test = 0;
    sfTime time;

    if (spell->protection != 0 && spell->activated == 1 && test == 0) {
        test = 1;
        sfClock_restart(spell->clock);
    }
    if (test == 1) {
        time = sfClock_getElapsedTime(spell->clock);
        if (time.microseconds / 1000000 > 1) {
            spell->activated = 2;
            test = 0;
        }
    }
    spell->pos = (sfVector2f) {pos.x - 5, pos.y + 10};
    sfSprite_setPosition(spell->sprite, spell->pos);
}

void heal_up(spell_t *spell, fight_t *fight)
{
    sfTime time = sfClock_getElapsedTime(spell->health);
    float second = time.microseconds / 1000000.0;

    if (second > 0.25) {
        fight->player.life += spell->calc;
        fight->buttons[3].rect.width = fight->player.life * 2 + 4;
        sfSprite_setTextureRect(fight->buttons[3].sprite, fight->buttons[3].rect);
        sfClock_restart(spell->health);
    }
}

int update_health(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    if (fight->player.life < 100 && spell->activated == 1)
        heal_up(spell, fight);
    animation_health(spell);
    change_position_health(spell, pos);
    return (cooldown_health(spell, fight));
}

void launch_heals(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[3].activated == 0
    && fight->spell[3].tmp == 0) {
        launch_first_health(fight, fight->player.pos);
        fight->spell[3].tmp += 1;
        sfSound_play(rpg->snd_heal);
    }
}

