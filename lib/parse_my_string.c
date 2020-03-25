/*
** EPITECH PROJECT, 2020
** parse_mmy_string
** File description:
** parses my string
*/

#include "minishell.h"

int count_arguments(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i += 1)
        if (str[i] == c)
            count += 1;
    return (count);
}

char **parse_string2(parse_t *p, char *str, char c)
{
    for (int i = 0; str[i]; i += 1) {
        while (str[i] == c || str[i] == '\t')
            i += 1;
        for (p->j = 0; str[p->j + i] != c && str[p->j + i]
        && str[i] != '\n'; p->j += 1)
            p->table[p->count] = malloc(sizeof(char) * (p->j + 2));
        for (p->j = 0; str[p->j + i] != c && str[p->j + i]
        && str[i] != '\n'; p->j += 1)
            p->table[p->count][p->j] = str[p->j + i];
        p->table[p->count++][p->j--] = '\0';
        i += p->j;
    }
    return (p->table);
}

char **parse_string(char *str, char c)
{
    parse_t parsing;
    parsing.count = 0;
    parsing.j = 0;

    str = clean_string(str);
    parsing.count = count_arguments(str, c);
    parsing.table = malloc(sizeof(char *) * (parsing.count + 2));
    parsing.table[parsing.count + 1] = NULL;
    parsing.count = 0;
    return (parse_string2(&parsing, str, c));
}