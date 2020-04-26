/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "my.h"

char *get_str(rpg_t *rpg, char *str, game_obj_t *obj)
{
    str[0] = rpg->life / 100 + 48;
    str[1] = rpg->life / 10 % 10 + 48;
    str[2] = rpg->life % 10 + 48;
    str[3] = ':';
    str[4] = obj->rect.top / 1000 + 48;
    str[5] = obj->rect.top / 100 % 10 + 48;
    str[6] = obj->rect.top / 10 % 10 + 48;
    str[7] = obj->rect.top % 10 + 48;
    str[8] = ':';
    str[9] = obj->rect.left / 1000 + 48;
    str[10] = obj->rect.left / 100 % 10 + 48;
    str[11] = obj->rect.left / 10 % 10 + 48;
    str[12] = obj->rect.left % 10 + 48;
    str[13] = ':';
    str[14] = rpg->status % 10 + 48;
    str[15] = ':';
    str[16] = '9';
    str[17] = '2';
    str[18] = '8';
    str[19] = ':';
    str[20] = '5';
    str[21] = '0';
    str[22] = '8';
    str[23] = ':';
    return (str);
}

int stock_info(rpg_t *rpg, game_obj_t *obj)
{
    char *str = malloc(sizeof(char) * 24);
    int fd = 0;
    int a = 0;

    str[23] = '\0';
    str = get_str(rpg, str, obj);
    fd = open("assets/3save.txt", O_WRONLY);
    if (fd == 84)
        return (84);
    a = write(fd, str, 24);
    if (a == -1) {
        write(2, "write failed\n", 13);
        return (84);
    }
    return (0);
}

void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg, game_obj_t *obj)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    printf("%d, %d\n", mouse.x, mouse.y);
    if (rpg->status == 0) {
        click_menu(rpg, mouse, obj);
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle,
        35, (sfVector2f){mouse.x, mouse.y});
    }
    if (rpg->status == 3 || rpg->status == 4 || rpg->status == 7 || rpg->status == 10) {
        if (mouse.x > 20 && mouse.x < 220 && mouse.y > 20 && mouse.y < 220) {
            save_to_file(rpg, obj);
            rpg->status = 0;
            rpg->menu_status = 6;
        }
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle,
        35, (sfVector2f){mouse.x, mouse.y});
    }
    //et là tu rajoutes tous les clics pour chacun des status avec pleins de conditions
}