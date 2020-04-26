/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fireball
*/

#include "rpg.h"

//0 ne bouge pas, 1 monte, 2 monte à droite, 3 à droite, 4 descends à droite, 5 descends, 6 descends à gauche, 7 à gauche, 8 monte à gauche

void pos_rotat(sfVector2f *pos, sfVector2f player_pos, int rad, sfSprite *sprt)
{
    if (rad == 90) {
        pos->y = player_pos.y + 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    } else if (rad == 270) {
        pos->y = player_pos.y - 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    } else if (rad == 0) {
        pos->y = player_pos.y;
        pos->x = player_pos.x + 300;
        sfSprite_setRotation(sprt, rad);
    } else if (rad == 180) {
        pos->y = player_pos.y;
        pos->x = player_pos.x - 300;
        sfSprite_setRotation(sprt, rad);
    }
}

void launch_first_fireball(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};
    WEAPONS current = fight->player.weapon;

    if (fight->player.direct == 0 || fight->player.direct == 5) {
        pos_rotat(&final_pos, player_pos, 90, fight->spell[0].sprite);
    } else if (fight->player.direct == 1) {
        pos_rotat(&final_pos, player_pos, 270, fight->spell[0].sprite);
    } else if (fight->player.direct == 3) {
        pos_rotat(&final_pos, player_pos, 0, fight->spell[0].sprite);
    } else if (fight->player.direct == 7) {
        pos_rotat(&final_pos, player_pos, 180, fight->spell[0].sprite);
    }
    fight->spell[0].pos = player_pos;
    fight->spell[0].direction = fight->player.direct;
    sfSprite_setPosition(fight->spell[0].sprite, fight->spell[0].pos);
    fight->spell[0].final_pos = final_pos;
    fight->spell[0].activated = 1;
}

void change_position_fireball(spell_t *spell, sfVector2f pos)
{
    printf("POS (%f, %f), FINAL_POS (%f, %f)\n", spell->pos.x, spell->pos.y, spell->final_pos.x, spell->final_pos.y);
    // if (spell->final_pos.x != spell->pos.x || spell->final_pos.y != spell->pos.y) {
        // if (spell->protection != 0)
        //     spell->pos = (sfVector2f) {pos.x - 5, pos.y + 10};
        if (spell->direction == 0 || spell->direction == 5)
            spell->pos.y += 5;
        if (spell->direction == 1)
            spell->pos.y -= 5;
        if (spell->direction == 3)
            spell->pos.x += 5;
        if (spell->direction == 7)
            spell->pos.x -= 5;
    // } else
    //     spell->activated = 2;
    sfSprite_setPosition(spell->sprite, spell->pos);
}

void check_touch_ennemie_fireball(fight_t *fight, rpg_t *rpg, spell_t *spell)
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

void set_cooldown(float res, spell_t *spell)
{
    char str[4];

    spell->text.str = "activate";
    spell->text.str = ftoa(res, str, 2);
    sfText_setString(spell->text.text, str);
}

void display_cooldown_fireball(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int cooldown_fireball(spell_t *spell)
{
    static int tmp = 0;

    spell->clock_cd.time = sfClock_getElapsedTime(spell->clock_cd.clock);
    spell->clock_cd.seconds = spell->clock_cd.time.microseconds / 1000000.0;
    if (spell->activated == 1 && tmp == 0) {
        sfClock_restart(spell->clock_cd.clock);
        tmp = 1;
        return (1);
    }
    display_cooldown_fireball(spell->clock_cd.seconds, spell);
    if (spell->clock_cd.seconds >= spell->sec) {
        spell->activated = 0;
        tmp = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}

int update_fireballs(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg)
{
    if (spell->activated == 1) {
        change_position_fireball(spell, pos);
        check_touch_ennemie_fireball(fight, rpg, spell);
        return (cooldown_fireball(spell));
    }
}

void launch_fireball(fight_t *fight, rpg_t *rpg)
{
    // static int tmp = 0;

    if (fight->spell[0].activated == 0 && fight->spell[0].tmp == 0 &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        launch_first_fireball(fight, fight->player.pos);
        fight->spell[0].tmp += 1;
    } /*else if (fight->spell[0].activated > 0 && fight->spell[0].tmp == 1) {
        fight->spell[0].tmp = update_fireballs(&fight->spell[0], fight->player.pos, fight, rpg);
    }*/
}
