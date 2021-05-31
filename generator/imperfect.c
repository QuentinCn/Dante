/*
** EPITECH PROJECT, 2021
** imperfect.c
** File description:
** manage imperfect labyrinth
*/

#include <stdlib.h>
#include "generator.h"

static int change_char_in_imperfect_map(char **map, int i, int j,
        info_map_t *info)
{
    int star_around = 0;

    if (i < 0 || j < 0)
        return 0;
    if (!map[i] || map[0][j] == '\0')
        return 0;
    if (map[i][j] == 'X') {
        star_around = count_star_around(map, i, j, info);
        if (star_around == 1 || star_around == 2) {
            map[i][j] = '*';
            return 1;
        }
    }
    return 0;
}

static void do_switch_for_imperfect(int *i, int *j, char **map,
        info_map_t *info)
{
    switch(info->random) {
    case (0):
        *j += change_char_in_imperfect_map(map, *i, *j + 1, info);
        break;
    case (1):
        *i += change_char_in_imperfect_map(map, *i + 1, *j, info);
        break;
    case (2):
        *j -= change_char_in_imperfect_map(map, *i, *j - 1, info);
        break;
    case (3):
        *i -= change_char_in_imperfect_map(map, *i - 1, *j, info);
        break;
    default:
        break;
    }
}

void do_imperfect(char **map, int *i, int *j, info_map_t *info)
{
    info->random = rand() % 4;
    do_switch_for_imperfect(i, j, map, info);
    if (info->len_map_i - *i < 3 && info->len_map_j - *j < 3 &&
        map[info->len_map_i - 1][info->len_map_j - 1] != '*')
        go_to_end(map, i, j);
    if (!is_pos_valid(map, *i, *j, info))
        return;
    do_imperfect(map, i, j, info);
}
