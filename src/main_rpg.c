/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rpg.h"

void create_window(rpg_t *rpg)
{
    sfVideoMode mode = {1920, 1080, 32};
    rpg->win = sfRenderWindow_create(mode, "SIRONA RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win, 60);
}

void my_set_sprites(game_obj_t *obj, rpg_t *rpg)
{
    init_variables_for_particules(rpg);
    rpg->fight = init_variables_for_fights(rpg->fight);
    set_menu_sprites(rpg);
    rpg->delete_me_too = sfTexture_createFromFile("assets/sprites/tilemap.png", NULL);
    rpg->delete_me_too = sfTexture_createFromFile("map/Map.png", NULL);
    rpg->delete_me = sfSprite_create();
    sfSprite_setTexture(rpg->delete_me, rpg->delete_me_too, sfTrue);
    sfSprite_setScale(rpg->delete_me, (sfVector2f) {2, 2});
    obj->texture = sfTexture_createFromFile("map/Map.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, (sfVector2f) {2, 2});
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {200, 100, 1920, 1080};
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void my_set_ints(rpg_t *rpg, clock_s *clock)
{
    clock->clock = sfClock_create();
    rpg->status = 4;
    rpg->menu_status = 0;
    rpg->fps = 90;
    rpg->player.direct = 0;
    rpg->sound_volume = 50;
    rpg->music_volume = 50;
    rpg->map = get_map();
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