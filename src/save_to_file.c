/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

void my_putchar2(char c, int fd)
{
    write(fd, &c, 1);
}

void put_in_file(int nb, int fd)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar2('-', fd);
    }
    if (nb >= 10)
        put_in_file(nb / 10, fd);
    nb = nb % 10;
    my_putchar2(nb + 48, fd);
}

int save_to_file(rpg_t *rpg, game_obj_t *obj)
{
    int fd = 0;

    if (rpg->save == 1)
        fd = open("assets/save/First", O_WRONLY | O_TRUNC);
    if (rpg->save == 2)
        fd = open("assets/save/Second", O_WRONLY | O_TRUNC);
    if (rpg->save == 3)
        fd = open("assets/save/Third", O_WRONLY | O_TRUNC);
    put_in_file(rpg->status, fd);
    write(fd, ":", 1);
    put_in_file(obj->rect.left, fd);
    write(fd, ":", 1);
    put_in_file(obj->rect.top, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.act, fd);
    write(fd, ":", 1);
    put_in_file(rpg->life, fd);
    write(fd, ":", 1);
    put_in_file(rpg->tuto.executed, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.x, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.y, fd);
    write(fd, ":", 1);
    put_in_file(rpg->level, fd);
    write(fd, ":", 1);
    put_in_file(rpg->fps, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.tmp, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.scd_quest.nb_kills, fd);
    write(fd, ":", 1);
    put_in_file(rpg->quest.scd_quest.nb_win, fd);
    write(fd, ":", 1);
    put_in_file(rpg->fight->player.pos.x, fd);
    write(fd, ":", 1);
    put_in_file(rpg->fight->player.pos.y, fd);
    write(fd, ":", 1);
    put_in_file(rpg->fight->player.life, fd);
    write(fd, ":", 1);
    put_in_file(rpg->fight->nb_enn, fd);
    write(fd, ":", 1);
    for (int i = 0; i < rpg->fight->nb_enn; i += 1) {
        put_in_file(rpg->fight->enns[i].life, fd);
        write(fd, ":", 1);
        put_in_file(rpg->fight->enns[i].pos.x, fd);
        write(fd, ":", 1);
        put_in_file(rpg->fight->enns[i].pos.y, fd);
        write(fd, ":", 1);
        put_in_file(rpg->fight->enns[i].tmp, fd);
        write(fd, ":", 1);
    }
    rpg->save = 0;
    return (0);
}