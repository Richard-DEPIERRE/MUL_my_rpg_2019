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
    sfImage *icon = sfImage_createFromFile("assets/sprites/menu/logo.png");
    sfVideoMode mode = {1920, 1080, 32};
    rpg->win = sfRenderWindow_create(mode, "SIDONA RPG (0fps)", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win, 60);
    sfRenderWindow_setIcon(rpg->win, 200, 200, sfImage_getPixelsPtr(icon));
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
    rpg->delete_me_too = sfTexture_createFromFile("assets/maps/map_with_spawns.png", NULL);
    rpg->delete_me = sfSprite_create();
    sfSprite_setTexture(rpg->delete_me, rpg->delete_me_too, sfTrue);
    sfSprite_setScale(rpg->delete_me, (sfVector2f) {2, 2});
    obj->texture = sfTexture_createFromFile("assets/maps/map_with_spawns.png", NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, (sfVector2f) {2, 2});
    obj->pos = (sfVector2f) {0, 0};
    obj->rect = (sfIntRect) {200, 100, 1920, 1080};
    rpg->quest.x = obj->rect.left;
    rpg->quest.y = obj->rect.top;
    sfSprite_setTextureRect(obj->sprite, obj->rect);

    set_seconds_quests(&rpg->quest.scd_quest);
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
    char path3[] = "assets/sprites/inventory_sheet.png";

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
    quest->tmp = 0; //richard doit save cette donnée
    quest->message = 0;
    sfSprite_setTexture(quest->sprite, quest->items, sfTrue);
    sfSprite_setTextureRect(quest->sprite, quest->rect);
    create_arrow(quest);
    quest->invent_s = sfSprite_create();
    quest->invent_t = sfTexture_createFromFile(path3, NULL);
    quest->invent_rect = (sfIntRect) {0, 0, 1920, 1080};
    sfSprite_setTexture(quest->invent_s, quest->invent_t, sfTrue);
    sfSprite_setScale(quest->invent_s, (sfVector2f) {0.5, 0.5});
    // sfSprite_setTextureRect(quest->invent_s, quest->invent_rect);
    sfSprite_setPosition(quest->invent_s, (sfVector2f) {950, 10});
}

void set_volume(rpg_t *rpg)
{
    sfSound_setVolume(rpg->snd_win, rpg->music_volume);
    sfSound_setVolume(rpg->snd_loose, rpg->music_volume);
    sfSound_setVolume(rpg->snd_clic, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_menu, rpg->music_volume);
    sfSound_setVolume(rpg->snd_tuto, rpg->music_volume);
    sfSound_setVolume(rpg->snd_main_music, rpg->music_volume);
    sfSound_setVolume(rpg->snd_main_music_fight, rpg->music_volume);
    sfSound_setVolume(rpg->snd_fireball, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_shield, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_black_hole, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_heal, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_speed, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_win_fight, rpg->sound_volume);
    sfSound_setVolume(rpg->snd_end, rpg->music_volume);
}

void stop_all_music(rpg_t *rpg)
{
    sfSound_stop(rpg->snd_win);
    sfSound_stop(rpg->snd_loose);
    sfSound_stop(rpg->snd_clic);
    sfSound_stop(rpg->snd_menu);
    sfSound_stop(rpg->snd_tuto);
    sfSound_stop(rpg->snd_main_music);
    sfSound_stop(rpg->snd_main_music_fight);
    sfSound_stop(rpg->snd_fireball);
    sfSound_stop(rpg->snd_shield);
    sfSound_stop(rpg->snd_black_hole);
    sfSound_stop(rpg->snd_heal);
    sfSound_stop(rpg->snd_speed);
    sfSound_stop(rpg->snd_win_fight);
    sfSound_stop(rpg->snd_end);
}

void set_music_loop(rpg_t *rpg)
{
    sfSound_setLoop(rpg->snd_menu, sfTrue);
    sfSound_setLoop(rpg->snd_tuto, sfTrue);
    sfSound_setLoop(rpg->snd_main_music, sfTrue);
    sfSound_setLoop(rpg->snd_main_music_fight, sfTrue);
}

sfSound *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, soundbuffer);
    return (sound);
}

void set_musics(rpg_t *rpg)
{
    rpg->snd_win = create_sound("assets/music/sound_effect_win.ogg");
    rpg->snd_loose = create_sound("assets/music/music_death.ogg");
    rpg->snd_clic = create_sound("assets/music/sound_effect_click.ogg");
    rpg->snd_menu = create_sound("assets/music/music_menu.ogg");
    rpg->snd_tuto = create_sound("assets/music/music_tuto.ogg");
    rpg->snd_main_music = create_sound("assets/music/music_quest.ogg");
    rpg->snd_main_music_fight = create_sound("assets/music/music_fight.ogg");
    rpg->snd_fireball = create_sound("assets/music/sound_effect_fire.ogg");
    rpg->snd_shield = create_sound("assets/music/sound_effect_shield.ogg");
    rpg->snd_black_hole = create_sound("assets/music/sound_effect_black_hole.ogg");
    rpg->snd_heal = create_sound("assets/music/sound_effect_heal.ogg");
    rpg->snd_speed = create_sound("assets/music/sound_effect_speed.ogg");
    rpg->snd_win_fight = create_sound("assets/music/sound_effect_win_fight.ogg");
    rpg->snd_end = create_sound("assets/music/end.ogg");
    set_music_loop(rpg);
    set_volume(rpg);
    sfSound_play(rpg->snd_menu);
}

void create_and_set(sfSprite *sprite, sfTexture *texture, char *path)
{
    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
}

void create_backgrounds_end_script(end_script_t *end)
{
    end->bg = sfSprite_create();
    end->bg_t = sfTexture_createFromFile("assets/sprites/end/bg.png", NULL);
    sfSprite_setTexture(end->bg, end->bg_t, sfTrue);
    sfSprite_setScale(end->bg, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(end->bg, (sfVector2f) {170, 35});

    end->bg2 = sfSprite_create();
    end->bg2_t = sfTexture_createFromFile("assets/sprites/end/bg_2.png", NULL);
    sfSprite_setTexture(end->bg2, end->bg2_t, sfTrue);
    sfSprite_setScale(end->bg2, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(end->bg2, (sfVector2f) {170, 35});
}

void create_msg_and_txt_end_script(end_script_t *end)
{
    char path[] = "assets/fonts/good_font.ttf";

    end->msg = sfSprite_create();
    end->msg_t = sfTexture_createFromFile("assets/sprites/end/msg.png", NULL);
    sfSprite_setTexture(end->msg, end->msg_t, sfTrue);
    end->msg_rect = (sfIntRect) {0, 0, 1920, 1080};
    sfSprite_setTextureRect(end->msg, end->msg_rect);
    sfSprite_setScale(end->msg, (sfVector2f) {0.7, 0.7});
    sfSprite_setPosition(end->msg, (sfVector2f) {270, 350});

    end->text = malloc(sizeof(*end->text));
    end->text->pos = (sfVector2f) {520, 570};
    end->text->size = 20;
    make_text(end->text, "Thanks for playing\n\n\n\t\t\t\t\tCreated by \
Richard Habimana, Alexandre Juan, Rafik Merzouk and Tom Seiguin", path);
    sfText_setCharacterSize(end->text->text, 20);
}

void create_gf_and_circle(end_script_t *end)
{
    end->gf = sfSprite_create();
    end->gf_t = sfTexture_createFromFile("assets/sprites/end/girl.png", NULL);
    sfSprite_setTexture(end->gf, end->gf_t, sfTrue);
    end->gf_rect = (sfIntRect) {50, 0, 50, 73};
    sfSprite_setTextureRect(end->gf, end->gf_rect);

    end->cinematic = sfCircleShape_create();
    sfCircleShape_setPosition(end->cinematic, (sfVector2f) {960, 750});
    end->cinematic_size = (sfVector2f) {0, 0};
    end->cinematic_radius = 1;
    sfCircleShape_setOrigin(end->cinematic, (sfVector2f) {1, 1});
    sfCircleShape_setRadius(end->cinematic, end->cinematic_radius);
    sfCircleShape_setFillColor(end->cinematic, sfBlack);
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
}

void init_end_script(end_script_t *end)
{
    end->clock.clock = sfClock_create();

    end->tmp = 0;
    end->act = 0;
    create_backgrounds_end_script(end);
    create_msg_and_txt_end_script(end);
    create_gf_and_circle(end);
}

void my_set_ints(rpg_t *rpg, clock_s *clock)
{
    clock->clock = sfClock_create();
    rpg->status = 11;
    rpg->menu_status = 0;
    rpg->fps = 90;
    rpg->player.direct = 0;
    rpg->sound_volume = 20;
    rpg->music_volume = 20;
    rpg->map = get_map();
    rpg->save = 0;
    rpg->level = 22;
    //status correspondant au tuto = 7
    set_rpg_tuto(&rpg->tuto);
    init_end_script(&rpg->end);
    set_quest(&rpg->quest);
    set_musics(rpg);
}

void destroy(game_obj_t *obj, rpg_t *rpg)
{
    sfClock_destroy(rpg->clock->clock);

    for (int i = 0; i < 140; i++)
        free(rpg->map[i]);
    free(rpg->map);

    sfSprite_destroy(rpg->delete_me);
    sfTexture_destroy(rpg->delete_me_too);

    for (int i = 0; i < 10; i += 1) {
        sfSprite_destroy(rpg->fight->buttons[i].sprite);
    sfTexture_destroy(rpg->fight->buttons[i].texture);
    }
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(rpg->menu->sprite);

    sfSprite_destroy(rpg->quest.msg);
    sfSprite_destroy(rpg->quest.sprite);
    sfSprite_destroy(rpg->quest.arrow);
    sfTexture_destroy(rpg->quest.arr_t);
    sfTexture_destroy(rpg->quest.invent_t);
    sfTexture_destroy(rpg->quest.msg_t);
    sfSprite_destroy(rpg->quest.invent_s);

    sfSprite_destroy(rpg->fight->background);
    sfSprite_destroy(rpg->fight->player.player);
    sfTexture_destroy(rpg->fight->player.player_texture);
    sfClock_destroy(rpg->fight->player.clock2.clock);
    sfClock_destroy(rpg->fight->player.clock.clock);
    for (int i = 0; i < 10; i++) {
        sfClock_destroy(rpg->fight->enns[i].clock.clock);
        sfTexture_destroy(rpg->fight->enns[i].enn_texture);
        sfSprite_destroy(rpg->fight->enns[i].enn);
    }
    sfSprite_destroy(rpg->fight->inventory.sprite);
    sfTexture_destroy(rpg->fight->inventory.texture);
    for (int i = 0; i < 3; i++) { //faut changer i < x -> x étant le nb de sort
        sfSprite_destroy(rpg->fight->spell[i].sprite);
        sfTexture_destroy(rpg->fight->spell[i].texture);
        sfClock_destroy(rpg->fight->spell[i].clock);
    }

    sfSprite_destroy(rpg->tuto.sprite);
    sfTexture_destroy(rpg->tuto.texture);
    sfSprite_destroy(rpg->tuto.friend);
    sfTexture_destroy(rpg->tuto.friend_t);
    sfClock_destroy(rpg->tuto.clock);

    sfSprite_destroy(rpg->player.sprite);
    sfTexture_destroy(rpg->player.texture);
    sfClock_destroy(rpg->player.clock.clock);

    sfSound_destroy(rpg->snd_win);
    sfSound_destroy(rpg->snd_loose);
    sfSound_destroy(rpg->snd_clic);
    sfSound_destroy(rpg->snd_menu);
    sfSound_destroy(rpg->snd_tuto);
    sfSound_destroy(rpg->snd_main_music);
    sfSound_destroy(rpg->snd_main_music_fight);
    sfSound_destroy(rpg->snd_fireball);
    sfSound_destroy(rpg->snd_shield);
    sfSound_destroy(rpg->snd_black_hole);
    sfSound_destroy(rpg->snd_heal);
    sfSound_destroy(rpg->snd_speed);
    sfSound_destroy(rpg->snd_win_fight);

    sfClock_destroy(rpg->end.clock.clock);
    sfSprite_destroy(rpg->end.msg);

    //il faut destroy le game obj sachant que je ne connais pas la limite du game obj
}

int main_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(struct rpg_s));
    clock_s clock;
    game_obj_t background;
    sfMusic* music;

    create_window(rpg);
    init_player(&rpg->player);
    my_set_ints(rpg, &clock);
    my_set_sprites(&background,rpg);
    for (int i = 0; i < PARICULE_MAX; i += 1)
        rpg->screen->particle[i].living = false;
    rpg->fight->boss = init_boss();
    rpg->fight->boss_spell = init_boss_spell();
    while (sfRenderWindow_isOpen(rpg->win)) {
        global_event(rpg, &background);
        clock_event(rpg, &clock);
        draw_statue(rpg, rpg->win, &background);
    }
    destroy(&background, rpg);
    return (0);
}