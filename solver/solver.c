/*
** EPITECH PROJECT, 2021
** solve.c
** File description:
** solve a labyrinth
*/

#include "solver.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void solve(char **map)
{
    if (map[array_len(map) - 1][(int)strlen(map[0]) - 1] == 'X' || map[0][0] !=
        '*') {
        printf("no solution found\n");
        return;
    }
    map[0][0] = 'o';
    find_path(map, 0, 0);
    if (map[0][0] != 'o') {
        printf("no solution found\n");
        return;
    }
    for (int i = 0; map[i]; i += 1) {
        write(1, map[i], strlen(map[i]));
        if (map[i + 1])
            write(1, "\n", 1);
    }
}
