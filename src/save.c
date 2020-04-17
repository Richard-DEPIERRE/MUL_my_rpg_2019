/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_rects
*/

#include "rpg.h"
#include "rafik.h"
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int count = 0;
    int i = 0;
    char *res = NULL;

    count = my_strlen(dest) ;
    res = malloc(sizeof(char) * (count + my_strlen(src) + 1));
    while (dest[i] != '\0' && dest != NULL) {
        res[i] = dest[i];
        i += 1;
    }
    for (int j = 0; src[j]; j += 1) {
        res[i] = src[j];
        i += 1;
    }
    res[i] = '\0';
    return (res);
}

void get_init(rpg_t *rpg, char *str, game_obj_t *obj)
{
    int size = 0;
    int size_tmp = 0;
    int left = 0;
    int top = 0;
    int i = 0;
    char *tmp = NULL;

    for (size = size_tmp; str[size] != ':' && str[size]; size += 1);
    tmp = malloc(sizeof(char) * (size + 1));
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1)
        tmp[i++] = str[size];
    tmp[i] = '\0';
    size_tmp = ++size;
    i = 0;
    rpg->life = my_getnbr(tmp);
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1);
    free(tmp);
    tmp = malloc(sizeof(char) * (size + 1));
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1)
        tmp[i++] = str[size];
    tmp[i] = '\0';
    size_tmp = ++size;
    i = 0;
    top = my_getnbr(tmp);
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1);
    free(tmp);
    tmp = malloc(sizeof(char) * (size + 1));
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1)
        tmp[i++] = str[size];
    tmp[i] = '\0';
    size_tmp = ++size;
    i = 0;
    left = my_getnbr(tmp);
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1);
    free(tmp);
    tmp = malloc(sizeof(char) * (size + 1));
    for (size = size_tmp; str[size] != ':' && str[size]; size += 1)
        tmp[i++] = str[size];
    tmp[i] = '\0';
    size_tmp = ++size;
    i = 0;
    rpg->status = my_getnbr(tmp);
    free(tmp);
    obj->rect = (sfIntRect){top, left,  1920, 1080};
    rpg->perspec.rect = obj->rect;
    rpg->quest.x = obj->rect.left;
    rpg->quest.y = obj->rect.top;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

int init_save(rpg_t *rpg, game_obj_t *obj)
{
    char *str = malloc(sizeof(char) * 2);
    struct stat fileStat;
    int fd = 0;

    str[0] = rpg->save + 48;
    str[1] = '\0';
    fd = open(my_strcat(my_strcat("assets/", str), "save.txt"), O_RDONLY);
    if (fd == 84)
        return (84);
    if (stat(my_strcat(my_strcat("assets/", str), "save.txt"), &fileStat) < 0)
        return (84);
    str = malloc(sizeof(char) * (fileStat.st_size));
    int a = read(fd, str, fileStat.st_size);
    str[fileStat.st_size - 1] = '\0';
    if (a == -1) {
        write(2, "read failed\n", 13);
        return (84);
    }
    get_init(rpg, str, obj);
    rpg->save = 0;
    return (0);
}