/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rafik
*/

#ifndef RAFIK_H_
#define RAFIK_H_

#include "rpg.h"

typedef struct game_obj_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
} game_obj_t;

void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
void global_event(rpg_t *rpg, game_obj_t *);
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
int **get_map(void);
char *get_next_char(int fd, char c);

#endif /* !RAFIK_H_ */