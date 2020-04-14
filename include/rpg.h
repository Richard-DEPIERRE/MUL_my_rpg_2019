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

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

typedef enum WEAPONS
{
    SHOVEL,
    SPELL_ONE,
    SPELL_TWO,
    SPELL_THREE,
    SPELL_FOUR
} WEAPONS;

typedef struct player_fight_s
{
    sfSprite *player;
    sfTexture *player_texture;
    clock_s clock;
    sfIntRect rect;
    sfVector2f pos;
    int direct; //0 ne bouge pas, 1 monte, 2 monte à droite, 3 à droite, 4 descends à droite, 5 descends, 6 descends à gauche, 7 à gauche, 8 monte à gauche
    int life;
    WEAPONS weapon;
} player_fight_t;

typedef struct ennemies
{
    sfSprite *enn;
    sfTexture *enn_texture;

    clock_s clock;

    sfIntRect rect;
    sfVector2f pos;
    int life;
    int in_live;
    float velocity;
    int tmp;
}ennemies_t;

typedef struct fight_s
{
    sfSprite *background;
    sfTexture *background_texture;

    player_fight_t player;
    ennemies_t *enns;
    int nb_enn;
}fight_t;

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

typedef struct rpg_s
{
    sfRenderWindow *win;
    sfEvent evnt;
    screen_t *screen;
    fight_t *fight;

    game_obj_R_t *menu;
    text_R_t *text;
    clock_R_t *clock;
    int menu_status;
    int fps;
    int music_volume;
    int sound_volume;
    int **map;

    sfSprite *cop;

    sfSprite *delete_me;
    sfTexture *delete_me_too;

    player_t player;

    int status;
}rpg_t;


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
void clock_event(rpg_t *rpg, clock_s *clock);

//lib
int my_strlen(char const *str);
int my_putstr(char const *str);
int generate_random(int l, int r);

//menu
void init_variables_for_particules(rpg_t *rpg);
fight_t *init_variables_for_fights(fight_t *fight);
void set_menu_sprites(rpg_t *rpg);
void menu_destroy(rpg_t *rpg);
void click_menu(rpg_t *rpg, sfVector2i mouse);
char *int_to_char(int nb);
game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);
void make_text(text_R_t *text, char *str, char *file);
void set2(rpg_t *rpg, char **name);
void initialize_text(rpg_t *rpg, char **name);
void check_mouse_pos_menu(rpg_t *rpg);
void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse);

//fight
void display_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg);
void update_fights(fight_t *fight);
void draw_fights(fight_t *fight, sfRenderWindow *win);
void player_deplacements(player_fight_t *player);
int dont_move_fight(player_fight_t *player);
int move_down_fight(player_fight_t *player);
int move_up_fight(player_fight_t *player);
int move_left_fight(player_fight_t *player);
int move_right_fight(player_fight_t *player);

#endif /* !RPG_H_ */
