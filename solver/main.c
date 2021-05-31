/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of the solver
*/

#include <stdlib.h>
#include <string.h>
#include "solver.h"

static int check_map(char **map)
{
    int len = 0;

    if (!map)
        return -1;
    len = (int)strlen(map[0]);
    for (int i = 0; map[i]; ++i) {
        if ((int)strlen(map[i]) != len)
            return -1;
        for (int j = 0; map[i][j] != '\0'; ++j)
            if (map[i][j] != '\n' && map[i][j] != '*' && map[i][j] != 'X')
                return -1;
    }
    return 0;
}

int main(int ac, char const * const av[])
{
    char *buffer = NULL;
    char **map = NULL;

    if (ac != 2)
        return 84;
    buffer = open_read(av[1]);
    if (!buffer)
        return 84;
    map = my_str_to_word_array(buffer, '\n');
    free(buffer);
    if (check_map(map) == -1)
        return 84;
    solve(map);
    for (int i = 0; map[i] != NULL; i += 1)
        free(map[i]);
    return 0;
}
