/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compares 2 strings
*/

#include "minishell.h"

int my_strcmp(char *str, char *str2)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] != str2[i])
            return (-1);
    return (0);
}

int my_strcmp_mod(char *str, char *str2, char c)
{
    for (int i = 0; str[i] && str[i] != c; i += 1)
        if (str[i] != str2[i])
            return (-1);
    return (0);
}