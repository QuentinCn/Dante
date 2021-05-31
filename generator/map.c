/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** manage the map
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generator.h"

char **create_map_with_x(int x, int y)
{
    char **map = malloc(sizeof(char *) * (x + 1));

    for (int i = 0; i < x; i += 1) {
        map[i] = malloc(y + 1);
        for (int j = 0; j < y; j += 1) {
            map[i][j] = 'X';
            map[i][j + 1] = '\0';
        }
        map[i + 1] = NULL;
    }
    return map;
}

void complete_map(char **map, bool status)
{
    int i = 0;
    int j = 0;
    info_map_t info = {array_len(map), (int) strlen(map[0]), 0, 0};

    srand(time(NULL));
    map[i][j] = '*';
    do {
        if (status)
            do_perfect(map, &i, &j, &info);
        else
            do_imperfect(map, &i, &j, &info);
    } while (get_new_entry(map, &i, &j, &info) != -1);
}
