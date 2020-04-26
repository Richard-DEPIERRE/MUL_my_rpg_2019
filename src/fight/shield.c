/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shield
*/

#include "rpg.h"

// void animation_spell(spell_t *spell)
// {
//     sfTime time = sfClock_getElapsedTime(spell->clock);
//     float second = time.microseconds / 1000000.0;
//     printf("seconds:%f\n", second);
//     if (second > 0.09) {
//         if (spell->rect.left < 393) {
//             spell->rect.left += 56.125;
//         } else {
//             spell->rect.left = 0;
//         }
//         sfClock_restart(spell->clock);
//     }
//     sfSprite_setTextureRect(spell->sprite, spell->rect);
//     return (spell);
// }

void launch_first_shield(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    fight->spell[1].pos.x = player_pos.x + 50;
    fight->spell[1].pos.x = player_pos.y + 50;
    sfSprite_setPosition(fight->spell[1].sprite, fight->spell[1].pos);
    fight->spell[1].final_pos = final_pos;
    fight->spell[1].activated = 1;
}

void check_touch_ennemie_shield(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    for (int i = 0; i < fight->nb_enn; i++) {
        if (fight->enns[i].in_live == 1)
            if (spell->pos.x > fight->enns[i].pos.x - 25 &&
            spell->pos.x < fight->enns[i].pos.x + 25 &&
            spell->pos.y > fight->enns[i].pos.y - 35 &&
            spell->pos.y < fight->enns[i].pos.y + 35) {
                fight->enns[i].life -= spell->damage;
                if (fight->enns[i].life <= 0)
                    rpg->quest.scd_quest.nb_kills += 1;
            }
        fight->enns[i].buttons[1].rect.width = fight->enns[i].life + 2;
        sfSprite_setTextureRect(fight->enns[i].buttons[1].sprite, fight->enns[i].buttons[1].rect);
    }
}

void set_cooldown_shield(float res, spell_t *spell)
{
    char str[4];

    spell->text.str = "activate";
    ftoa(res, str, 2);
    sfText_setString(spell->text.text, str);
}

void display_cooldown_shield(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_shield(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_shield(spell_t *spell)
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
        display_cooldown_shield(spell->clock_cd.seconds, spell);
    if (spell->activated == 2 && spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        tmp = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}

void change_position_shield(spell_t *spell, sfVector2f pos)
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

int update_shield(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    // animation_spell(spell);
    change_position_shield(spell, pos);
    check_touch_ennemie_shield(fight, rpg, spell);
    return (cooldown_shield(spell));
}

void launch_shield(fight_t *fight, rpg_t *rpg)
{
    // static int tmp = 0;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[1].activated == 0
    && fight->spell[1].tmp == 0) {
        launch_first_shield(fight, fight->player.pos);
        fight->spell[1].tmp += 1;
    } /*else if (fight->spell[1].activated > 0 && fight->spell[1].tmp == 1){
        fight->spell[1].tmp = update_shield(&fight->spell[1], fight->player.pos, fight, rpg);
        }
    }*/
}
