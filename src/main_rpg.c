/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rpg.h"
#include "minishell.h"

void create_window(rpg_t *rpg)
{
    sfVideoMode mode = {1920, 1080, 32};
    rpg->win = sfRenderWindow_create(mode, "SIRONA RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win, 60);

    rpg->evnt;
}

void my_set_sprites(rpg_t *rpg)
{
    //ici on set tout ce qui est sprite en début de programme
    set_menu_sprites(rpg);
    rpg->delete_me_too = sfTexture_createFromFile("assets/sprites/tilemap.png", NULL);
    rpg->delete_me = sfSprite_create();
    sfSprite_setTexture(rpg->delete_me, rpg->delete_me_too, sfTrue);
}

void my_set_ints(rpg_t *rpg, clock_s *clock)
{
    //ici on set tout ce qui est valeur numérique en début de programme
    clock->clock = sfClock_create();
    rpg->status = 0;
    rpg->menu_status = 0;
    rpg->fps = 90;
    rpg->sound_volume = 50;
    rpg->music_volume = 50;
}

void destroy(rpg_t *rpg)
{
    //ici on va destroy tout à la fin de ce que l'on ouvre
    sfSprite_destroy(rpg->delete_me);
    sfTexture_destroy(rpg->delete_me_too);
    menu_destroy(rpg);
    sfRenderWindow_destroy(rpg->win);
}

int main_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(struct rpg_s));
    clock_s clock;

    create_window(rpg);
    my_set_ints(rpg, &clock);
    my_set_sprites(rpg);
    while (sfRenderWindow_isOpen(rpg->win)) {
        global_event(rpg); //dans cette fonction on récupère tous les events (clavier, souris) et on fait des actions avec
        clock_event(rpg, clock); //dans cette fonction on gère les animations
        draw_statue(rpg, rpg->win); //dans cette fonction on update les éléments du graphique et on affiche tout
    }
    destroy(rpg);
    return (0);
}