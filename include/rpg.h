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
#include "richard.h"
#include "particule.h"
#include "rafik.h"

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

typedef struct player_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    clock_s clock;
    int direct; //0 ne bouge pas, 1 monte, 2 monte à droite, 3 à droite, 4 descends à droite, 5 descends, 6 descends à gauche, 7 à gauche, 8 monte à gauche
    int life;
} player_t;

typedef struct game_obj_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
} game_obj_t;

typedef struct tuto_s
{
    int executed;
    int action;
    int tmp;

    sfClock *clock;

    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;

    sfSprite *friend;
    sfTexture *friend_t;
    sfIntRect rect_friend;
    sfVector2f pos;
}tuto_t;

typedef struct quest_s
{
    sfTexture *items;

    sfSprite *sprite;
    sfSprite *msg;
    sfTexture *msg_t;
    int act;

    int x;
    int y;
    int message;
    sfVector2f pos;
    sfIntRect rect;
}quest_t;

typedef struct rpg_s
{
    sfRenderWindow *win;
    sfEvent evnt;
    screen_t *screen;

    tuto_t tuto;
    quest_t quest;

    game_obj_R_t *menu;
    text_R_t *text;
    clock_R_t *clock;
    int menu_status;
    int fps;
    int music_volume;
    int sound_volume;
    int **map;



    sfSprite *cop;

    game_obj_t perspec;

    // sfClock *clock;
    // sfTime time;
    // float sec;

    player_t player;

    int status;
    int save;
    // à modifier
    int life;
    //
}rpg_t;



//rafik
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
void global_event(rpg_t *rpg, game_obj_t *);
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
int **get_map(void);
char *get_next_char(int fd, char c);
int init_save(rpg_t *rpg, game_obj_t *obj);

//graphic
void move_right(player_t *player);
void move_left(player_t *player);
void dont_move(player_t *player);
void move_down(player_t *player);
void move_up(player_t *player);
void init_player(player_t *obj);
void clic_status_zero(sfMouseButtonEvent event, sfVector2i mouse, rpg_t *rpg);
void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg, game_obj_t *obj);
void draw_options(rpg_t *rpg, sfRenderWindow *win);
void draw_menu(rpg_t *rpg, sfRenderWindow *win);
int main_rpg(void);
void clock_event(rpg_t *rpg, clock_s *clock);
void create_perspec(game_obj_t *perspec);
void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg);
void keys_handlings(sfEvent event, rpg_t *rpg, game_obj_t *obj);
void handling_items(rpg_t *rpg);

//lib
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char *str);

//menu
void set_menu_sprites(rpg_t *rpg);
void menu_destroy(rpg_t *rpg);
void click_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj);
char *int_to_char(int nb);
game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);
void make_text(text_R_t *text, char *str, char *file);
void set2(rpg_t *rpg, char **name);
void initialize_text(rpg_t *rpg, char **name);
void check_mouse_pos_menu(rpg_t *rpg);
void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse);
void press_button(rpg_t *rpg, BACK_R_t type);
void release_button(rpg_t *rpg, BACK_R_t type);
void click_menu_zero(rpg_t *rpg, sfVector2i mouse);
void click_start_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj);
void click_menu_zero(rpg_t *rpg, sfVector2i mouse);

//tuto
void draw_tuto(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj);
void tuto(rpg_t *rpg, game_obj_t *obj);


#endif /* !RPG_H_ */
