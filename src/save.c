/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

char *stock_info2(char *str, char *tmp, int *size_tmp)
{
    int size = 0;
    for (size = *size_tmp; str[size] && str[size] != ':'; size += 1);
    tmp = malloc(sizeof(char) * (size - *size_tmp + 1));
    tmp[size - *size_tmp] = '\0';
    for (size = *size_tmp; str[size] && str[size] != ':'; size += 1)
        tmp[size - *size_tmp] = str[size];
    if (str[size])
        *size_tmp = size + 1;
    return (tmp);
}

void get_str2(char *str, rpg_t *rpg, game_obj_t *obj)
{
    int size_tmp = 0;
    char *tmp = NULL;

    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->status = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    obj->rect.left = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    obj->rect.top = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.act = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->life = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->tuto.executed = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.x = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.y = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->level = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fps = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.tmp = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.scd_quest.nb_kills = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->quest.scd_quest.nb_win = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fight->player.pos.x = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fight->player.pos.y = my_getnbr(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fight->player.life = my_getnbr(tmp);
    for (int i = 0; i < 5; i += 1) {
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->spell[i].sec = stof(tmp);
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->spell[i].damage = my_getnbr(tmp);
    }
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fight->enns[0].velocity = stof(tmp);
    tmp = stock_info2(str, tmp, &size_tmp);
    rpg->fight->nb_enn = my_getnbr(tmp);
    for (int i = 0; i < rpg->fight->nb_enn; i += 1) {
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->enns[i].life = my_getnbr(tmp);
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->enns[i].pos.x = my_getnbr(tmp);
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->enns[i].pos.y = my_getnbr(tmp);
        tmp = stock_info2(str, tmp, &size_tmp);
        rpg->fight->enns[i].tmp = my_getnbr(tmp);
    }
}

void get_init(rpg_t *rpg, char *str, game_obj_t *obj)
{
    get_str2(str, rpg, obj);
    rpg->perspec.rect = obj->rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

int init_save(rpg_t *rpg, game_obj_t *obj)
{
    struct stat fileStat;
    char *str = NULL;
    int fd = 0;


    if (rpg->save == 1) {
        fd = open("assets/save/First", O_RDONLY);
        if (fd == 84)
            return (84);
        if (stat("assets/save/First", &fileStat) < 0)
            return (84);
    }
    if (rpg->save == 2) {
        fd = open("assets/save/Second", O_RDONLY);
        if (fd == 84)
            return (84);
        if (stat("assets/save/Second", &fileStat) < 0)
            return (84);
    }
    if (rpg->save == 3) {
        fd = open("assets/save/Third", O_RDONLY);
        if (fd == 84)
            return (84);
        if (stat("assets/save/Third", &fileStat) < 0)
            return (84);
    }
    str = malloc(sizeof(char) * (fileStat.st_size));
    int a = read(fd, str, fileStat.st_size);
    str[fileStat.st_size - 1] = '\0';
    if (a == -1) {
        write(2, "read failed\n", 13);
        return (84);
    }
    get_init(rpg, str, obj);
    return (0);
}