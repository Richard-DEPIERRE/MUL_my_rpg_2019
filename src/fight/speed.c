/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** speed
*/

#include "rpg.h"

void animation_speed(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    // printf("seconds:%f\n", second);
    if (second > 0.09) {
        if (spell->rect.left < 240 - 60) {
            spell->rect.left += 60;
        } else {
            spell->rect.left = 0;
            (spell->rect.top < 300 - 60) ? (spell->rect.top += 60) :
            (spell->rect.top = 0);
        }
        sfClock_restart(spell->clock);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}

void launch_first_speed(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    fight->spell[4].pos.x = player_pos.x + 50;
    fight->spell[4].pos.x = player_pos.y + 50;
    sfSprite_setPosition(fight->spell[4].sprite, fight->spell[4].pos);
    fight->spell[4].final_pos = final_pos;
    fight->spell[4].activated = 1;
    sfClock_restart(fight->spell[4].clock_cd.clock);
}

void set_cooldown_speed(float res, spell_t *spell)
{
    /*char str[4];

    spell->text.str = "activate";
    ftoa(res, str, 2);
    sfText_setString(spell->text.text, str);*/
    char *str = ftoa(res, 2);
    sfText_setString(spell->text.text, str);
    spell->text.str = "activate";
}

void display_cooldown_speed(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_speed(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_speed(spell_t *spell)
{
    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && spell->clock_cd.seconds > 3.5 && spell->tmp2 == 0) {
        // sfClock_restart(spell->clock_cd.clock);
        spell->activated = 2;
        spell->tmp2 = 1;
        return (1);
    }
    if (spell->activated == 2)
        display_cooldown_speed(spell->clock_cd.seconds, spell);
    if (spell->activated == 2 && spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        spell->tmp2 = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}

void change_position_speed(spell_t *spell, sfVector2f pos)
{
    static int test = 0;
    sfTime time;

    if (spell->protection != 0 && spell->activated == 1 && test == 0) { //je crois que ça ne sert à rien
        test = 1; //je crois que ça ne sert à rien
        sfClock_restart(spell->clock); //je crois que ça ne sert à rien
    } //je crois que ça ne sert à rien
    if (test == 1) { //je crois que ça ne sert à rien
        time = sfClock_getElapsedTime(spell->clock); //je crois que ça ne sert à rien
        if (time.microseconds / 1000000 > 1) { //je crois que ça ne sert à rien
            spell->activated = 2; //je crois que ça ne sert à rien
            test = 0; //je crois que ça ne sert à rien
        } //je crois que ça ne sert à rien
    } //je crois que ça ne sert à rien
    spell->pos = (sfVector2f) {pos.x - 5, pos.y + 10};
    sfSprite_setPosition(spell->sprite, spell->pos);
}

int update_speed(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    animation_speed(spell);
    change_position_speed(spell, pos);
    return (cooldown_speed(spell));
}

void launch_speed(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[4].activated == 0
    && fight->spell[4].tmp == 0) {
        launch_first_speed(fight, fight->player.pos);
        fight->spell[4].tmp += 1;
        sfSound_play(rpg->snd_speed);
    }
}


