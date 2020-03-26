/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

int man(void)
{
    my_putstr("hello, i'm the -h\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 2) {
        write(2, "Too much arguments.\n", 20);
        write(2, av[0], my_strlen(av[0]));
        write(2, " -h for help", 12);
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (man());
    else if (ac == 2) {
        write(2, "Invalid argument.\n", 20);
        write(2, av[0], my_strlen(av[0]));
        write(2, " -h for help", 12);
        return (84);
    }
    return (main_rpg());
}