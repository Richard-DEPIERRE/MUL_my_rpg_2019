/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
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

void analyse_event(rpg_t *rpg)
{
    if (rpg->evnt.type == sfEvtClosed || (rpg->evnt.type == sfEvtKeyPressed \
    && rpg->evnt.key.code == sfKeyEscape)) {
        sfRenderWindow_close(rpg->win);
    }
    if (rpg->evnt.type == sfEvtMouseButtonPressed) {
        clics_handlings(rpg->evnt.mouseButton, rpg);
        printf("clic\n");
    }
}

void move_x(sfVector2i pos, game_obj_t *obj, int **map, int offset)
{
    if (offset > 0) {
        if (pos.x + 1 < 140 && map[pos.y][pos.x + 1])
            obj->rect.left += offset;
    } else {
        if (pos.x > 0 && map[pos.y][pos.x - 1])
            obj->rect.left += offset;
    }
}

void move_y(sfVector2i pos, game_obj_t *obj, int **map, int offset)
{
    if (offset > 0) {
        if (pos.y + 1 < 140 && map[pos.y + 1][pos.x])
            obj->rect.top += offset;
    } else {
        if (pos.y > 0 && map[pos.y - 1][pos.x])
            obj->rect.top += offset;
    }
}

void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg)
{
    // static int **map = NULL;
    sfVector2i pos = {(((obj->rect.left) + 450) / 14),
    (((obj->rect.top) + 240) / 14)};
    //je pense que c'est 29.etc et pas 16 puisque la map d'origine est scale *2 pour la zoomer
    //donc la taille de la collision augmente -> au lieu que ce soit 16 pixels par colision
    //c'est 29 et quelques car l'image fait 2033x2033 (la dernière version) ainsi, 2033 * 2 -> 4066
    //et 4066 % 140 -> 29.0428

    // pos.x += 1;
    // pos.y += 1;
    printf("\n\npos x : %d | pos y : %d\n", pos.x, pos.y);
    printf("\n\nleft : %d | witdh : %d | top : %d | heigth : %d\n", obj->rect.left, obj->rect.width / 2, obj->rect.top, obj->rect.height / 2);
    if (mouvement.x != 0)
        move_x(pos, obj, rpg->map, mouvement.x);
    if (mouvement.y != 0)
        move_y(pos, obj, rpg->map, mouvement.y);
    // for (int i = 0; i < 140; i++) {
    //     for (int j = 0; j < 140; j++) {
    //         if (i == pos.y && j == pos.x)
    //             printf("P");
    //         else
    //             printf("%d", rpg->map[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void global_event(rpg_t *rpg, game_obj_t *background)
{
    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_rect(background, (sfVector2f) {-1, 0}, rpg);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_rect(background, (sfVector2f) {1, 0}, rpg);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_rect(background, (sfVector2f) {0, -1}, rpg);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_rect(background, (sfVector2f) {0, 1}, rpg);
    if (rpg->status == 0)
        check_mouse_pos_menu(rpg);
    player_deplacement(rpg);
}