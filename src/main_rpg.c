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
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    set_menu_sprites(rpg);
    create_perspec(&rpg->perspec);
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
    rpg->quest.x = obj->rect.left;
    rpg->quest.y = obj->rect.top;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void set_rpg_tuto(tuto_t *tuto)
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
}

void create_arrow(quest_t *quest)
{
    char path[] = "assets/sprites/arrow.png";
    sfVector2f pos = {935, 950};

    quest->arrow = sfSprite_create();
    quest->arr_t = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(quest->arrow, quest->arr_t, sfTrue);
    sfSprite_setPosition(quest->arrow, pos);
    sfSprite_setOrigin(quest->arrow, (sfVector2f) {165, 170});
    sfSprite_setScale(quest->arrow, (sfVector2f) {0.45, 0.45});
}

void set_quest(quest_t *quest)
{
    char path[] = "assets/sprites/items.png";
    char path2[] = "assets/sprites/msg.png";

    quest->sprite = sfSprite_create();
    quest->items = sfTexture_createFromFile(path, NULL);
    quest->msg = sfSprite_create();
    quest->msg_t = sfTexture_createFromFile(path2, NULL);
    sfSprite_setTexture(quest->msg, quest->msg_t, sfTrue);
    quest->pos.x = 195;
    quest->pos.y = 84;
    quest->rect.height = 30;
    quest->rect.width = 30;
    quest->rect.left = 0;
    quest->rect.top = 0;
    quest->act = 1;
    quest->message = 0;
    sfSprite_setTexture(quest->sprite, quest->items, sfTrue);
    sfSprite_setTextureRect(quest->sprite, quest->rect);
    create_arrow(quest);
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
    rpg->save = 0;
    //status correspondant au tuto = 7
    set_rpg_tuto(&rpg->tuto);
    set_quest(&rpg->quest);
}

void destroy(game_obj_t *obj, rpg_t *rpg)
{
    sfSprite_destroy(rpg->fight->buttons[0].sprite);
    sfTexture_destroy(rpg->fight->buttons[0].texture);
    sfSprite_destroy(rpg->fight->buttons[1].sprite);
    sfTexture_destroy(rpg->fight->buttons[1].texture);
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
    sfMusic* music;
    // music = sfMusic_createFromFile("assets/music/music1.ogg");
    // sfMusic_play(music);
    while (sfRenderWindow_isOpen(rpg->win)) {
        global_event(rpg, &background);
        clock_event(rpg, &clock);
        // sfMusic_setVolume(music, (float)(rpg->music_volume));
        draw_statue(rpg, rpg->win, &background);
    }
    destroy(&background, rpg);
    return (0);
}