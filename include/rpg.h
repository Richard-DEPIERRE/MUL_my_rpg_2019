/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

typedef struct player_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int direct; //0 ne bouge pas, 1 monte, 2 monte à droite, 3 à droite, 4 descends à droite, 5 descends, 6 descends à gauche, 7 à gauche, 8 monte à gauche
    int life;
} player_t;

typedef struct rpg_s
{
    sfRenderWindow *win;
    sfEvent evnt;

    sfSprite *cop;

    sfSprite *delete_me;
    sfTexture *delete_me_too;

    // sfClock *clock;
    // sfTime time;
    // float sec;

    player_t player;

    int status;
}rpg_t;

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

//graphic
void move_right(player_t *player);
void move_left(player_t *player);
void dont_move(player_t *player);
void move_down(player_t *player);
void move_up(player_t *player);
void init_player(player_t *obj);
void clic_status_zero(sfMouseButtonEvent event, sfVector2i mouse, rpg_t *rpg);
void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg);
void draw_options(rpg_t *rpg, sfRenderWindow *win);
void draw_menu(rpg_t *rpg, sfRenderWindow *win);
int main_rpg(void);
void global_event(rpg_t *rpg);
void draw_statue(rpg_t *rpg, sfRenderWindow *win);
void clock_event(rpg_t *rpg, clock_s *clock);

//lib
int my_strlen(char const *str);
int my_putstr(char const *str);

#endif /* !RPG_H_ */
