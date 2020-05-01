/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end_script
*/

#include "rpg.h"

void fourth_act(rpg_t *rpg, end_script_t *end)
{
    rpg->end.tmp = 1;
}

void fivth_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 0.07) {
        end->cinematic_size.x += 22;
        end->cinematic_size.y += 22;
        sfClock_restart(end->clock.clock);
    }
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
    if (end->cinematic_size.x  > 1200) {
        end->act = 6;
        end->tmp = 2;
        sfClock_restart(end->clock.clock);
    }

}

int final_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 6) {
        end->tmp = 0;
        rpg->status = 0;
        rpg->menu_status = 0;
        stop_all_music(rpg);
        sfSound_play(rpg->snd_menu);
        return (1);
    }
    return (0);
}

void set_end_script(rpg_t *rpg, end_script_t *end)
{
    end->tmp = 0;
    end->act = 1;
    rpg->player.pos = (sfVector2f) {743, 940};
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    sfSprite_setPosition(end->gf, (sfVector2f) {917, 720});
    end->cinematic_size = (sfVector2f) {0, 0};
    end->msg_rect = (sfIntRect) {0, 0, 1920, 1080};
    end->cinematic_radius = 1;
    end->cinematic_size = (sfVector2f) {0, 0};
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
}

void end_script(rpg_t *rpg, end_script_t *end)
{
    static int i = 0;

    if (i == 0) {
        set_end_script(rpg, end);
        i++;
    } else if (i == 1) {
        if (end->act == 1)
            first_act(rpg, end);
        if (end->act == 2)
            second_act(rpg, end);
        if (end->act == 3)
            third_act(rpg, end);
        if (end->act == 4)
            fourth_act(rpg, end);
        if (end->act == 5)
            fivth_act(rpg, end);
        if (end->act == 6)
            if (final_act(rpg, end))
                i = 0;
    }
    return;
}

