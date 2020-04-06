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

    printf("mouse -> x : %d | y : %d\n", mouse.x, mouse.y);
    if (rpg->status == 0) {
        //les clics pour les menus
        clic_status_zero(event, mouse, rpg);
    }
    if (rpg->status == 0)
        click_menu(rpg, mouse);
    //et là tu rajoutes tous les clics pour chacun des status avec pleins de conditions
}