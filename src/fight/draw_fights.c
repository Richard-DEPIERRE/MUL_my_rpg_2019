/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** draw_fights
*/

#include "rpg.h"

void display_rect(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    sfRectangleShape_setPosition(fight->inventory.show,
    (sfVector2f) {((fight->player.weapon - 1) * 110) + 603, 935});
    sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
}

void display_enns(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 0; i < fight->nb_enn && rpg->status != 10; i++)
        if (fight->enns[i].in_live) {
            if (fight->enns[i].life < 100) {
                sfRenderWindow_drawSprite(win, fight->enns[i].buttons[0].sprite, NULL);
                sfRenderWindow_drawSprite(win, fight->enns[i].buttons[1].sprite, NULL);
            }
            sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
        }
}

void display_spells(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 0; i < 3; i++)
        if (fight->spell[i].activated == 1)
            sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
}

void draw_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win, sfBlack);
    // sfRectangleShape_setPosition(fight->inventory.show,
    // (sfVector2f) {((fight->player.weapon - 1) * 110) + 603, 935});
    sfRenderWindow_drawSprite(win, fight->buttons[4].sprite, NULL);
    if (rpg->status == 10)
        sfRenderWindow_drawSprite(win, fight->buttons[9].sprite, NULL);
    display_enns(fight, win, rpg);
    // for (int i = 0; i < fight->nb_enn && rpg->status != 10; i++)
    //     if (fight->enns[i].in_live) {
    //         if (fight->enns[i].life < 100) {
    //             sfRenderWindow_drawSprite(win, fight->enns[i].buttons[0].sprite, NULL);
    //             sfRenderWindow_drawSprite(win, fight->enns[i].buttons[1].sprite, NULL);
    //         }
    //         sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
    //     }
    sfRenderWindow_drawSprite(win, fight->player.player, NULL);
    display_spells(fight, win, rpg);
    // for (int i = 0; i < 3; i++)
    //     if (fight->spell[i].activated == 1)
    //         sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[3].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->inventory.sprite, NULL);
    // sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
    display_rect(fight, win, rpg);
    sfRenderWindow_drawSprite(win, fight->buttons[5].sprite, NULL);
    for (int i = 6; i <= 8; i += 1)
        sfRenderWindow_drawSprite(win, fight->buttons[i].sprite, NULL);
    sfRenderWindow_display(win);
}
