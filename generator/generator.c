/*
** EPITECH PROJECT, 2021
** generator.c
** File description:
** manage the generator
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "generator.h"

void go_to_end(char **map, int *i, int *j)
{
    for (; map[*i + 1]; *i += 1)
        map[*i][*j] = '*';
    for (; map[*i][*j] != '\0'; *j += 1)
        map[*i][*j] = '*';
}

void generate_map(int x, int y, bool status)
{
    char **map = create_map_with_x(x, y);

    complete_map(map, status);
    for (int i = 0; map[i]; i += 1) {
        write(1, map[i], strlen(map[i]));
        if (map[i + 1])
            write(1, "\n", 1);
    }
    for (int i = 0; map[i]; i += 1)
        free(map[i]);
    free(map);
}
