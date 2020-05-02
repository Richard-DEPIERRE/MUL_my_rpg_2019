/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tuto
*/

#include "rpg.h"

void begin_action_three_two(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.tmp >= 13 && rpg->tuto.tmp < 25) {
        rpg->tuto.rect_friend.top = 216;
        rpg->tuto.pos.y -= 5;
    }
    if (rpg->tuto.tmp >= 25){
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        rpg->tuto.action = 0;
        rpg->tuto.tmp = 0;
    }
}

void begin_action_three(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.tmp < 5) {
        rpg->tuto.rect_friend.top = 216;
        rpg->tuto.pos.y -= 5;
    }
    if (rpg->tuto.tmp >= 5 && rpg->tuto.tmp < 13){
        rpg->tuto.rect_friend.top = 72;
        rpg->tuto.pos.x -= 4;
    }
    begin_action_three_two(rpg, background);
}

void action_three(rpg_t *rpg, game_obj_t *background)
{
    begin_action_three(rpg, background);
    // if (rpg->tuto.tmp < 5) {
    //     rpg->tuto.rect_friend.top = 216;
    //     rpg->tuto.pos.y -= 5;
    // } else if (rpg->tuto.tmp < 13){
    //     rpg->tuto.rect_friend.top = 72;
    //     rpg->tuto.pos.x -= 4;
    // } else if (rpg->tuto.tmp < 25) {
    //     rpg->tuto.rect_friend.top = 216;
    //     rpg->tuto.pos.y -= 5;
    // } else {
    //     stop_all_music(rpg);
    //     sfSound_play(rpg->snd_main_music);
    //     rpg->status = 3;
    //     rpg->tuto.action = 0;
    //     rpg->tuto.tmp = 0;
    // }
    rpg->tuto.rect_friend.left += 50;
    if (rpg->tuto.rect_friend.left > 100)
        rpg->tuto.rect_friend.left = 0;
    rpg->tuto.tmp += 1;
    sfSprite_setPosition(rpg->tuto.friend, rpg->tuto.pos);
    sfSprite_setTextureRect(rpg->tuto.friend, rpg->tuto.rect_friend);
}

void action_two(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.rect.top == 1080) {
        background->rect.top = 1690;
        background->rect.left = 55;
        sfSprite_setTextureRect(background->sprite, background->rect);
    } else {
        background->rect.top = 1006;
        background->rect.left = 1280;
        sfSprite_setTextureRect(background->sprite, background->rect);
    }
}

void action_one_other(rpg_t *rpg, game_obj_t *background)
{
    dont_move(&rpg->player);
    rpg->tuto.action = 2;
    rpg->tuto.tmp = 0;
    rpg->tuto.rect_friend.top = 72;
    rpg->player.rect.top += 64;
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
    sfSprite_setTextureRect(rpg->tuto.friend, rpg->tuto.rect_friend);
    rpg->tuto.rect.width = 1920;
    rpg->tuto.rect.height = 1080;
    sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
}

void action_one(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->tuto.tmp < 56) {
        rpg->tuto.pos.y -= 2;
        background->rect.top += 1;
        rpg->perspec.rect = background->rect;
        sfSprite_setPosition(rpg->tuto.friend, rpg->tuto.pos);
        sfSprite_setTextureRect(background->sprite, background->rect);
        sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
        move_down(&rpg->player);
        rpg->tuto.tmp += 1;
    } else {
        action_one_other(rpg, background);
        // dont_move(&rpg->player);
        // rpg->tuto.action = 2;
        // rpg->tuto.tmp = 0;
        // rpg->tuto.rect_friend.top = 72;
        // rpg->player.rect.top += 64;
        // sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
        // sfSprite_setTextureRect(rpg->tuto.friend, rpg->tuto.rect_friend);
        // rpg->tuto.rect.width = 1920;
        // rpg->tuto.rect.height = 1080;
        // sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
    }
}

void set_tuto(rpg_t *rpg, game_obj_t *background)
{
    rpg->tuto.tmp = 0;
    background->rect.top = 950;
    background->rect.left = 1280;
    rpg->quest.x = background->rect.left;
    rpg->quest.y = background->rect.top;
    // rpg->quest.rect = background->rect; je sais pas pourquoi j'ai mis ça ici du coup je laisse
    rpg->perspec.rect = background->rect;
    sfSprite_setTextureRect(background->sprite, background->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
    rpg->tuto.pos = (sfVector2f) {960, 586};
    rpg->tuto.rect_friend.left = 50;
    rpg->tuto.rect_friend.height = 72;
    rpg->tuto.rect_friend.width = 50;
    rpg->tuto.rect_friend.top = 0;
    sfSprite_setTextureRect(rpg->tuto.friend, rpg->tuto.rect_friend);
    sfSprite_setPosition(rpg->tuto.friend, rpg->tuto.pos);
    rpg->tuto.rect.top = 0;
    sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
}

void tuto(rpg_t *rpg, game_obj_t *background)
{
    sfTime time = sfClock_getElapsedTime(rpg->tuto.clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.09 || rpg->tuto.action == 2) {
        if (rpg->tuto.action == 0) {
            set_tuto(rpg, background);
            rpg->tuto.action = 1;
        } else if (rpg->tuto.action == 1) {
            action_one(rpg, background);
        } else if (rpg->tuto.action == 2) {
            action_two(rpg, background);
        } else if (rpg->tuto.action == 3) {
            action_three(rpg, background);
        }
        sfClock_restart(rpg->tuto.clock);
    }
}