/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** keys_handlings
*/

#include "rpg.h"

void keys_handlings(sfEvent event, rpg_t *rpg, game_obj_t *obj)
{
    if (rpg->status == 7 && rpg->tuto.action == 2) {
        if ((int) event.key.code == 57 || (int) event.key.code == 58) {
            // printf("SKIP\n");
            rpg->tuto.rect.top += 1080; // changer valeur
            sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
        }
        if (rpg->tuto.rect.top > 4320)
            rpg->tuto.action = 3;
        if ((int) event.key.code == 60) {
            // printf("BACK\n");
            if (rpg->tuto.rect.top > 0)
                rpg->tuto.rect.top -= 1080; // changer valeur
            sfSprite_setTextureRect(rpg->tuto.sprite, rpg->tuto.rect);
        }
    }
}