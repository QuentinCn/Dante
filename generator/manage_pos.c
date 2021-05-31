/*
** EPITECH PROJECT, 2021
** manage_pos.c
** File description:
** manage pos
*/

#include <string.h>
#include "generator.h"

int count_star_around(char **map, int i, int j, info_map_t *info)
{
    int somme_around = 0;

    if (is_in_angle(i, j, info) && map[i][j] == '*')
        somme_around += 1;
    if (i > 0 && j < info->len_map_j && i < info->len_map_i && j >= 0)
        if (map[i - 1][j] == '*')
            somme_around += 1;
    if (j > 0 && i < info->len_map_i && j < info->len_map_j && i >= 0)
        if (map[i][j - 1] == '*')
            somme_around += 1;
    if (i + 1 < info->len_map_i && j < info->len_map_j && i >= 0 && j >= 0)
        if (map[i + 1][j] == '*')
            somme_around += 1;
    if (j + 1 < info->len_map_j && i < info->len_map_i && j >= 0 && i >= 0)
        if (map[i][j + 1] == '*')
            somme_around += 1;
    return somme_around;
}

bool is_pos_valid(char **map, int i, int j, info_map_t *info)
{
    if (count_star_around(map, i, j, info) != 1)
        return false;
    if (count_star_around(map, i, j + 1, info) == 1)
        return true;
    if (count_star_around(map, i, j - 1, info) == 1)
        return true;
    if (count_star_around(map, i + 1, j, info) == 1)
        return true;
    if (count_star_around(map, i - 1, j, info) == 1)
        return true;
    return false;
}

static bool is_new_pos_valid(char **map, int i, int j, info_map_t *info)
{
    if (map[i][j] == 'X')
        if (count_star_around(map, i, j, info) == 1)
            return true;
    return false;
}

int get_new_entry(char **map, int *i, int *j, info_map_t *info)
{
    for (int k = info->last_i; map[k]; k += 1)
        for (int l = 0; map[k][l] != '\0'; l += 1)
            if (is_new_pos_valid(map, k, l, info)) {
                *i = k;
                *j = l;
                info->last_i = k;
                map[k][l] = '*';
                return 0;
            }
    return -1;
}
