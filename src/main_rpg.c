/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rafik.h"
#include "rpg.h"

void create_window(rpg_t *rpg)
{
    sfVideoMode mode = {1920, 1080, 32};
    rpg->win = sfRenderWindow_create(mode, "SIRONA RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win, 60);
}

void my_set_sprites(game_obj_t *obj, rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    set_menu_sprites(rpg);
    create_perspec(&rpg->perspec);
    obj->texture = sfTexture_createFromFile("map/Map.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, (sfVector2f) {2, 2});
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {200, 100, 1920, 1080};
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

tuto_t *set_rpg_tuto(tuto_t *tuto)
{
    char path[] = "assets/sprites/friend.png";
    char path2[] = "assets/sprites/tuto.png";

    tuto->action = 0; //pour voir à quel étape on en est du tuto
    tuto->executed = 0; //pour dire si le tuto a déjà été fait ou non
    tuto->friend = sfSprite_create();
    tuto->friend_t = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(tuto->friend, tuto->friend_t, sfTrue);
    tuto->clock = sfClock_create();
    tuto->sprite = sfSprite_create();
    tuto->texture = sfTexture_createFromFile(path2, NULL);
    sfSprite_setTexture(tuto->sprite, tuto->texture, sfTrue);
    tuto->rect.top = 0;
    tuto->rect.height = 0;
    tuto->rect.left = 0;
    tuto->rect.width = 0;
    sfSprite_setTextureRect(tuto->sprite, tuto->rect);
    return (tuto);
}

void my_set_ints(rpg_t *rpg, clock_s *clock)
{
    clock->clock = sfClock_create();
    rpg->status = 0;
    rpg->menu_status = 0;
    rpg->fps = 90;
    rpg->player.direct = 0;
    rpg->sound_volume = 50;
    rpg->music_volume = 50;
    rpg->map = get_map();
    rpg->save = 0;
    //status correspondant au tuto = 7
    set_rpg_tuto(&rpg->tuto);
}

void destroy(game_obj_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

int main_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(struct rpg_s));
    clock_s clock;
    game_obj_t background;


    create_window(rpg);
    init_player(&rpg->player);
    my_set_ints(rpg, &clock);
    my_set_sprites(&background,rpg);
    while (sfRenderWindow_isOpen(rpg->win)) {
        global_event(rpg, &background);
        clock_event(rpg, &clock);
        draw_statue(rpg, rpg->win, &background);
    }
    destroy(&background);
    return (0);
}