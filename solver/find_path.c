/*
** EPITECH PROJECT, 2021
** find_path.c
** File description:
** find the path of a labyrinth
*/

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "solver.h"

static bool go_right(char **map, int i, int j, bool lock)
{
    if (!map[i] || map[0][j + 1] == '\0' || lock)
        return false;
    else if (map[i][j + 1] == '*') {
        map[i][j + 1] = 'o';
        return true;
    } else
        return false;
}

static bool go_down(char **map, int i, int j, bool lock)
{
    if (!map[i + 1] || map[0][j] == '\0' || lock)
        return false;
    else if (map[i + 1][j] == '*') {
        map[i + 1][j] = 'o';
        return true;
    } else
        return false;
}

static bool go_left(char **map, int i, int j, bool lock)
{
    if (!map[i] || j <= 0 || lock)
        return false;
    else if (map[i][j - 1] == '*') {
        map[i][j - 1] = 'o';
        return true;
    } else
        return false;
}

static bool go_up(char **map, int i, int j, bool lock)
{
    if (i <= 0 || map[0][j + 1] == '\0' || lock)
        return false;
    else if (map[i - 1][j] == '*') {
        map[i - 1][j] = 'o';
        return true;
    } else
        return false;
}

bool find_path(char **map, int i, int j)
{
    bool lock = false;

    if (!map[i + 1] && map[0][j + 1] == '\0')
        return true;
    if (go_right(map, i, j, lock))
        lock = find_path(map, i, j + 1);
    if (go_down(map, i, j, lock))
        lock = find_path(map, i + 1, j);
    if (go_left(map, i, j, lock))
        lock = find_path(map, i, j - 1);
    if (go_up(map, i, j, lock))
        lock = find_path(map, i - 1, j);
    if (!lock)
        map[i][j] = '*';
    return lock;
}