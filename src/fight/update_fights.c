/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_fights
*/

#include "rpg.h"

float get_distance(sfVector2f p1, sfVector2f p2)
{
    const float dx = (p2.x) - p1.x;
    const float dy = (p2.y)- p1.y;

    return (sqrt(dx * dx + dy * dy));
}

void where_to_move(ennemies_t *ennemies, float truc1, float truc2)
{
    if (fabs(truc1) >= fabs(truc2))
        if (truc1 >= 0)
            ennemies->rect.top = 76;
        else
            ennemies->rect.top = 146;
    else
        if (truc2 >= 0)
            ennemies->rect.top = 216;
        else
            ennemies->rect.top = 6;
}

void animate_enemy(ennemies_t *ennemies)
{
    // printf("rect : LEFT %d | TOP %d\n", ennemies->rect.left, ennemies->rect.top);
    ennemies->clock.time = sfClock_getElapsedTime(ennemies->clock.clock);
    ennemies->clock.second = ennemies->clock.time.microseconds / 1000000.0;
    if (ennemies->clock.second > 0.2) {
        //printf("ennemies->tmp : %d\n", ennemies->tmp);
        if (ennemies->tmp == 0 || ennemies->tmp == 1) {
            ennemies->rect.left += 50;
            ennemies->tmp += 1;
        } else {
            ennemies->rect.left -= 100;
            ennemies->tmp = 0;
        }
        // printf("top : %d | left : %d\n", ennemies->rect.top, ennemies->rect.left);
        sfClock_restart(ennemies->clock.clock);
    }
}

int dont_move_touch(player_fight_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 0)
        player->rect.left = 0;
    player->direct = 0;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_down_touch(player_fight_t *player)
{
    player->rect.top = 8 * 64;
    if (player->direct != 1)
        player->rect.left = 0;
    player->direct = 1;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_up_touch(player_fight_t *player)
{
    player->rect.top = 10 * 64;
    if (player->direct != 5)
        player->rect.left = 0;
    player->direct = 5;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_left_touch(player_fight_t *player)
{
    player->rect.top = 11 * 64;
    if (player->direct != 3)
        player->rect.left = 0;
    player->direct = 3;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}

int move_right_touch(player_fight_t *player)
{
    player->rect.top = 9 * 64;
    if (player->direct != 7)
        player->rect.left = 0;
    player->direct = 7;
    sfSprite_setTextureRect(player->player, player->rect);
    return (1);
}


int pos_zombie(player_fight_t *player, float truc1, float truc2, int tmp2)
{
    static int tmp = 5;
    if (tmp < 30) {
        if (truc1 >= truc2 && truc1 >= 0 && player->pos.x > 10) {
            player->pos.x -= 5;
            return (move_left_touch(player));
        }
        if (truc1 >= truc2 && truc1 < 0 && player->pos.x < 1910) {
            player->pos.x += 5;
            return (move_right_touch(player));
        }
        if (truc1 < truc2 && truc1 >= 0 && player->pos.y > 10) {
            player->pos.y -= 5;
            return (move_up_touch(player));
        }
        if (truc1 < truc2 && truc1 < 0 && player->pos.y < 1040) {
            player->pos.y += 5;
            return (move_down_touch(player));
        }
        tmp += 5;
    }
    if (tmp2 == 1) {
        tmp = 0;
    }
    return (0);
}

void knock_back(player_fight_t *player, clock_s *clock, float truc1, float truc2, int tmp)
{
    if (pos_zombie(player, truc1, truc2, tmp) == 0) {
        player->rect.left = 0;
        sfSprite_setTextureRect(player->player, player->rect);
        return;
    }
    int direct = player->direct;
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;
    if (clock->second > 0.06) {
        if (direct == 1 || direct == 3 || direct == 5 || direct == 7) {
            if (player->rect.left < 64 * 7 + 32) {
                player->rect.left += 64;
            } else
                player->rect.left = 64;
        }
        sfSprite_setTextureRect(player->player, player->rect);
        sfClock_restart(clock->clock);
    }
    sfSprite_setPosition(player->player, player->pos);
}

void ennemies_deplacements(fight_t *fight)
{
    static int tmp = 0;
    float truc1 = 0;
    float truc2 = 0;
    for (int i = 0; i < fight->nb_enn; i++) {
        if (fight->enns[i].in_live == 1) {
            float distance = get_distance(fight->enns[i].pos, fight->player.pos);
            float x = fight->enns[i].pos.x - fight->player.pos.x;
            float y = fight->enns[i].pos.y - fight->player.pos.y;

            truc1 = (x / distance) * fight->enns[i].velocity;
            truc2 = (y / distance) * fight->enns[i].velocity; //0.7

            fight->enns[i].pos.x -= truc1;
            fight->enns[i].pos.y -= truc2;
            where_to_move(&fight->enns[i], truc1, truc2);
            animate_enemy(&fight->enns[i]);
            sfSprite_setTextureRect(fight->enns[i].enn, fight->enns[i].rect);
            sfSprite_setPosition(fight->enns[i].enn, fight->enns[i].pos);
            fight->enns[i].buttons[1].pos.x = fight->enns[i].pos.x - 50;
            fight->enns[i].buttons[1].pos.y = fight->enns[i].pos.y - 51;
            sfSprite_setPosition(fight->enns[i].buttons[1].sprite, fight->enns[i].buttons[1].pos);
            fight->enns[i].buttons[0].pos.x = fight->enns[i].pos.x - 50;
            fight->enns[i].buttons[0].pos.y = fight->enns[i].pos.y - 51;
            sfSprite_setPosition(fight->enns[i].buttons[0].sprite, fight->enns[i].buttons[1].pos);
            if (fight->enns[i].pos.x > fight->player.pos.x - 25 &&
            fight->enns[i].pos.x < fight->player.pos.x + 25 &&
            fight->enns[i].pos.y > fight->player.pos.y - 35 &&
            fight->enns[i].pos.y < fight->player.pos.y + 35)
                tmp = 1;
        }
        if (tmp >= 1) {
            knock_back(&fight->player, &fight->player.clock, truc1, truc2, tmp);
            if (tmp < 2 && (fight->spell[fight->player.weapon - 1].protection == 0
            || fight->spell[fight->player.weapon - 1].activated != 1)) {
                fight->player.life -= 1;
                fight->buttons[3].rect.width = fight->player.life * 2 + 4;
                sfSprite_setTextureRect(fight->buttons[3].sprite, fight->buttons[3].rect);
            }
            tmp +=  1;
        }
    }
    tmp = 0;
}

void update_weapons(fight_t *fight)
{
    int r = 0;

    for (int i = 0; i < 3; i += 1)
        if (fight->spell[i].activated == 1)
            r += 1;
    if (r != 0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        fight->player.weapon = SPELL_ONE;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        fight->player.weapon = SPELL_TWO;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        fight->player.weapon = SPELL_THREE;
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        fight->player.weapon = SPELL_FOUR;
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
        fight->player.weapon = SPELL_FOUR;
    if (sfKeyboard_isKeyPressed(sfKeyNum6))
        fight->player.weapon = SPELL_FOUR;
}

void update_fights(fight_t *fight, rpg_t *rpg)
{
    if (rpg->status != 10) {
        for (int i = 0; i < fight->nb_enn; i++) {
            if (fight->enns[i].in_live == 1 && fight->enns[i].life <= 0)
                fight->enns[i].in_live = 0;
        }
        ennemies_deplacements(fight);
    }
    player_deplacements(&fight->player);
    launch_spell(fight);
    update_spell(fight, rpg);
    update_weapons(fight);
    //ici on va s'occuper de faire bouger les ennemies, de faire bouger le perso, de faire la hitbox
    //en fait de tout pour le fight mise à part le draw
}