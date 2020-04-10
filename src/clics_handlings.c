/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "my.h"

void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    if (rpg->status == 0) {
        click_menu(rpg, mouse);
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle, \
        35, (sfVector2f){mouse.x, mouse.y});
    }
    //et là tu rajoutes tous les clics pour chacun des status avec pleins de conditions
}