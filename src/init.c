/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_particules
*/

#include "rpg.h"

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);

void set_int_seconds_quests(scd_quest_t *quest)
{
    quest->nb_win = 0;
    quest->nb_kills = 0;

    quest->pos1 = (sfVector2f) {50, 300};
    quest->pos2 = (sfVector2f) {1600, 300};
    quest->pos3 = quest->pos2;
    for (int i = 0; i < 3; i++)
        quest->text[i].size = 20;
    quest->text[0].pos.x = quest->pos1.x + 30;
    quest->text[0].pos.y = quest->pos1.y + 70;

    quest->text[1].pos.x = quest->pos2.x + 30;
    quest->text[1].pos.y = quest->pos2.y + 70;

    quest->text[2].pos.x = quest->pos2.x + 30;
    quest->text[2].pos.y = quest->pos2.y + 70;
}

void set_seconds_quests(scd_quest_t *quest)
{
    char path[] = "assets/fonts/good_font.ttf";
    quest->text = malloc(sizeof(*quest->text) * 3);
    quest->sprite = sfSprite_create();
    quest->texture = sfTexture_createFromFile("./assets/sprites/scd_quest.png",\
    NULL);
    sfSprite_setTexture(quest->sprite, quest->texture, sfTrue);

    set_int_seconds_quests(quest);
    make_text(&quest->text[0], "  Win 3 fights\n\nto unlock a heal\n\n     \
 spell\n\n\n\n  fights won : ", path);
    make_text(&quest->text[1], " Kill 15 ennemies\n\nto unlock a speed\n\n\
      spell\n\n\n\n     ennemies\n\n    killed : ", path);
    make_text(&quest->text[2], " Kill 30 ennemies\n\n   to unlock a\n\n black \
hole  spell\n\n\n\n     ennemies\n\n    killed : ", path);
}

void set_basics_for_fight(fight_t *fight, char *path, sfIntRect rect,
sfVector2f pos)
{
    fight->player.player_texture = sfTexture_createFromFile(path, NULL);
    fight->player.player = sfSprite_create();
    fight->player.rect = rect;
    fight->player.pos = pos;
    fight->player.life = 100;
    fight->player.weapon = SPELL_ONE;
    fight->player.clock.clock = sfClock_create();
    fight->player.clock2.clock = sfClock_create();
    sfSprite_setOrigin(fight->player.player, (sfVector2f) {32, 32});
    sfSprite_setTexture(fight->player.player, fight->player.player_texture,
    sfTrue);
    sfSprite_setTextureRect(fight->player.player, fight->player.rect);
    sfSprite_setPosition(fight->player.player, fight->player.pos);
    fight->nb_enn = 5;
}

void set_enn2(ennemies_t *enn)
{
    enn->rect.width = 50;
    enn->rect.height = 70;
    enn->rect.top = 6;
    enn->life = 100;
    enn->velocity = generate_random(50, 100) / 10;
    enn->velocity /= 10;
    enn->tmp = 0;
    enn->in_live = 1;
    enn->buttons = malloc(sizeof(game_obj_t) * 2);
    enn->buttons[0] = create_object_fight("assets/sprites/red_enn_life.png", 
    (sfVector2f){40, 40}, (sfIntRect){0, 0, 102, 14}, BACK);
    enn->buttons[1] = create_object_fight("assets/sprites/green_enn_life.png", 
    (sfVector2f){40, 40}, (sfIntRect){0, 0, 102, 14}, BACK);
}

ennemies_t set_enn(int i)
{
    ennemies_t enn;
    char path[] = "assets/sprites/ennemies.png";

    enn.enn_texture = sfTexture_createFromFile(path, NULL);
    enn.enn = sfSprite_create();
    sfSprite_setTexture(enn.enn, enn.enn_texture, sfTrue);
    set_enn2(&enn);
    if (i % 2 == 0) {
        enn.rect.left = 0;
    } else
        enn.rect.left = 150;
    sfSprite_setTextureRect(enn.enn, enn.rect);
    enn.pos.x = generate_random(100, 1820);
    enn.pos.y = generate_random(100, 980);
    enn.clock.clock = sfClock_create();
    sfSprite_setPosition(enn.enn, enn.pos);
    sfSprite_setOrigin(enn.enn, (sfVector2f) {25, 35});
    return (enn);
}

void init_variables_for_particules(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t));
    init_particle_environment(&rpg->screen->particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
}

void create_and_set_background(fight_t *fight)
{
    // fight->defaultt = sfTexture_createFromFile(\
    //     "assets/sprites/arena/arenas.png", NULL);
    fight->rect.top = 0;
    fight->rect.left = 0;
    fight->rect.width = 1920;
    fight->rect.height = 1080;
    // fight->condom = sfTexture_createFromFile("assets/sprites/arena/condom.png",\
    // NULL);
    // fight->corona = sfTexture_createFromFile("assets/sprites/arena/corona.png",\
    // NULL);
    // fight->gel = sfTexture_createFromFile("assets/sprites/arena/gel.png", NULL);
    // fight->boss = sfTexture_createFromFile("assets/sprites/arena/boss.png",\
    // NULL);
//     sfSprite_setTexture(fight->background, fight->defaultt, sfTrue);
//     sfSprite_setTextureRect(fight->background, fight->rect);
}

game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type)
{
    game_obj_R_t object;

    object.texture = sfTexture_createFromFile(filepath, NULL);
    object.sprite = sfSprite_create();
    sfSprite_setPosition(object.sprite, pos);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, rect);
    object.rect = rect;
    object.pos = pos;
    object.type = type;
    return (object);
}

fight_t *init_variables_for_fights(fight_t *fight)
{
    fight = malloc(sizeof(fight_t));
    fight->enns = malloc(sizeof(ennemies_t) * 5);
    fight->background = sfSprite_create();
    fight->inventory.sprite = sfSprite_create();
    fight->inventory.texture = sfTexture_createFromFile("assets/sprites/inventory.png", NULL);
    fight->inventory.show = sfRectangleShape_create();
    sfRectangleShape_setSize(fight->inventory.show, (sfVector2f) {110 - 12, 90 - 22});
    sfRectangleShape_setOutlineThickness(fight->inventory.show, 6);
    sfRectangleShape_setFillColor(fight->inventory.show, sfColor_fromRGBA(0, 0, 0, 0));
    sfRectangleShape_setOutlineColor(fight->inventory.show, sfColor_fromRGBA(50, 50, 50, 255));
    sfSprite_setTexture(fight->inventory.sprite, fight->inventory.texture, sfTrue);
    sfSprite_setPosition(fight->inventory.sprite, (sfVector2f) {577, 926});
    sfSprite_setPosition(fight->background, (sfVector2f) {0, 0});
    fight->spell = malloc(sizeof(spell_t) * (3));
    fight->spell[0] = init_spell("assets/sprites/spells/fireball.png", FIREBALL, (sfIntRect) {0, 0, 56, 31});
    fight->spell[1] = init_spell("assets/sprites/spells/spell2.png", SHIELD, (sfIntRect) {0, 0, 56, 42});
    fight->spell[2] = init_spell("assets/sprites/spells/spell3.png", BLACK_HOLE, (sfIntRect) {0, 0, 57, 49});
    create_and_set_background(fight);
    sfSprite_setTextureRect(fight->background, (sfIntRect){0, 0, 1920, 1080});
    fight->buttons = malloc(sizeof(game_obj_t) * 10);
    fight->buttons[0] = create_object_fight("assets/sprites/life_fight.png", 
    (sfVector2f){20, 20}, (sfIntRect){0, 0, 168, 28}, BACK);
    fight->buttons[1] = create_object_fight("assets/sprites/you_are_dead.png", 
    (sfVector2f){530, 485}, (sfIntRect){0, 0, 870, 120}, BACK);
    fight->buttons[2] = create_object_fight("assets/sprites/red_life.png", 
    (sfVector2f){1676, 40}, (sfIntRect){0, 0, 204, 28}, BACK);
    fight->buttons[3] = create_object_fight("assets/sprites/green_life.png", 
    (sfVector2f){1676, 40}, (sfIntRect){0, 0, 204, 28}, BACK);
    fight->buttons[4] = create_object_fight("assets/sprites/arena/arenas.png", 
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080}, BACK);
    fight->buttons[5] = create_object_fight("assets/sprites/menu/pause.png",
    (sfVector2f){20, 20}, (sfIntRect){0, 0, 100, 100}, BACK);
    fight->buttons[6] = create_object_fight("assets/sprites/fire.png",
    (sfVector2f){630, 957}, (sfIntRect){0, 0, 45, 31}, BACK);
    fight->buttons[7] = create_object_fight("assets/sprites/shield.png",
    (sfVector2f){738, 952}, (sfIntRect){0, 0, 42, 42}, BACK);
    fight->buttons[8] = create_object_fight("assets/sprites/black_hole.png",
    (sfVector2f){850, 948}, (sfIntRect){0, 0, 49, 49}, BACK);
    fight->buttons[9] = create_object_fight("assets/sprites/arrow_fight.png",
    (sfVector2f){1570, 370}, (sfIntRect){0, 0, 330, 340}, BACK);
    set_basics_for_fight(fight, "assets/sprites/character.png",
    (sfIntRect) {0, 0, 64, 64}, (sfVector2f) {(1920 / 2) - (64 / 2),
    (1080 / 2) - (64 / 2)});
    srand(time(0));
    for (int i = 0; i < 5; i++)
        fight->enns[i] = set_enn(i);
    return (fight);
}