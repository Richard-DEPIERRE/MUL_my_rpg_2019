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
    struct stat fileStat;
    int fd = 0;

    if (rpg->save == 1)
        fd = open("assets/First", O_WRONLY | O_TRUNC);
    if (rpg->save == 2)
        fd = open("assets/Second", O_WRONLY | O_TRUNC);
    if (rpg->save == 3)
        fd = open("assets/Third", O_WRONLY | O_TRUNC);
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
    rpg->save = 0;
    return (0);
}