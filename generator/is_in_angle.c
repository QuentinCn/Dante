/*
** EPITECH PROJECT, 2021
** is_in_angle.c
** File description:
** tells if the point is in an angle or not
*/

#include "generator.h"
#include <string.h>

bool is_in_angle(int i, int j, info_map_t *info)
{
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j == info->len_map_j - 1)
        return true;
    if (i == info->len_map_i - 1 && j == 0)
        return true;
    if (i == info->len_map_i - 1 && j == info->len_map_j - 1)
        return true;
    return false;
}
