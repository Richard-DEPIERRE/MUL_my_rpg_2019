/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

int player_deplacement(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_up(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_down(&rpg->player);
        return (0);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_left(&rpg->player);
    else if (sfKeyboard_isKeyPressed(sfKeyD))
        move_right(&rpg->player);
    else {
        dont_move(&rpg->player);
    }
    return (0);
}

void analyse_event(rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->evnt.type == sfEvtClosed || (rpg->evnt.type == sfEvtKeyPressed \
    && rpg->evnt.key.code == sfKeyEscape)) {
        sfRenderWindow_close(rpg->win);
    }
    if (rpg->evnt.type == sfEvtMouseButtonPressed) {
        clics_handlings(rpg->evnt.mouseButton, rpg, obj);
    }
    if (rpg->evnt.type == sfEvtKeyPressed) {
        keys_handlings(rpg->evnt, rpg, obj);
    }
}

void move_x(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.x -= 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x + 1 < 140 && rpg->map[pos.y][pos.x + 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    } else {
        pos.x += 16;
        pos.x /= 32;
        pos.y /= 32;
        if (pos.x > 0 && rpg->map[pos.y][pos.x - 1]) {
            obj->rect.left += offset;
            rpg->quest.x += offset;
        }
    }
}

void move_y(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset)
{
    if (offset > 0) {
        pos.y -= 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y + 1 < 140 && rpg->map[pos.y + 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    } else {
        pos.y += 16;
        pos.y /= 32;
        pos.x /= 32;
        if (pos.y > 0 && rpg->map[pos.y - 1][pos.x]) {
            obj->rect.top += offset;
            rpg->quest.y += offset;
        }
    }
}

void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg)
{
    sfVector2i pos = {((obj->rect.left) + 480 - 16),
    ((obj->rect.top) + 270 - 16)};

    pos.x *= 2;
    pos.y *= 2;
    if (mouvement.x != 0)
        move_x(pos, obj, rpg, mouvement.x);
    if (mouvement.y != 0)
        move_y(pos, obj, rpg, mouvement.y);
    pos.x /= 32;
    pos.y /= 32;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    rpg->perspec.rect = obj->rect;
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

float speed(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) //cheat code, à enlever
        return (5);
    return (1);
}

void enns_loop(float speed, ennemies_t *enns)
{
    for (int i = 0; i < 10; i++) {
        enns[i].velocity = generate_random(speed, speed + 50) / 10;
        enns[i].velocity /= 10;
    }
}

void upgrade_ennemies(ennemies_t *enns, int act, fight_t *fight)
{
    if (act == 1) {
        enns_loop(50, enns);
        fight->max_enn = 5;
        return;
    }
    if (act == 2) {
        enns_loop(65, enns);
        fight->max_enn = 7;
    } else if (act == 3) {
        enns_loop(80, enns);
        fight->max_enn = 8;
    } else {
        enns_loop(90, enns);
        fight->max_enn = 10;
    }
}

void global_event_statue_three(rpg_t *rpg, game_obj_t *background)
{
    if (rpg->status == 3) {
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            move_rect(background, (sfVector2f) {-speed(), 0}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_rect(background, (sfVector2f) {speed(), 0}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            move_rect(background, (sfVector2f) {0, -speed()}, rpg);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            move_rect(background, (sfVector2f) {0, speed()}, rpg);
        player_deplacement(rpg);
        fights_spawns(rpg, background);
        handling_items(rpg);
        upgrade_ennemies(rpg->fight->enns, rpg->quest.act, rpg->fight);
        generic_function_bg_quest(rpg);
        //change_item(rpg); //hfioefheifhioefhef
    }
}

void display_fps(rpg_t *rpg)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    static char *str = NULL;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        str = my_strcat("SIDONA RPG (", int_to_char(fps));
        str = my_strcat(str, "fps)");
        sfRenderWindow_setTitle(rpg->win, str);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

void rect_pause(sfVector2i mouse, rpg_t *rpg)
{
    if (mouse.x > 20 && mouse.x < 20 && mouse.y > 20 && mouse.y < 120) {
        rpg->menu[18].rect.left = rpg->menu[18].rect.width;
        rpg->fight->buttons[5].rect.left = rpg->fight->buttons[5].rect.width;
    } else {
        rpg->menu[18].rect.left = 0;
        rpg->fight->buttons[5].rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->menu[18].sprite, rpg->menu[18].rect);
    sfSprite_setTextureRect(rpg->fight->buttons[5].sprite, rpg->fight->buttons[5].rect);
}

void global_event(rpg_t *rpg, game_obj_t *background)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg, background);
    }
    display_fps(rpg);
    if (rpg->status == 0)
        set_volume(rpg);
    rect_pause(mouse, rpg);
    global_event_statue_three(rpg, background);
    if (rpg->status == 8)
        script_death(rpg, background);
    if (rpg->status == 7)
        tuto(rpg, background);
    if (rpg->status == 0)
        check_mouse_pos_menu(rpg);
    if (rpg->status == 10 || rpg->status == 11)
        player_deplacement(rpg);
}