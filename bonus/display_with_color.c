/*
** EPITECH PROJECT, 2021
** display_map_with_color.c
** File description:
** display the map with color
*/

#include <stdio.h>

void display_map_with_color(char **map)
{
    for (int i = 0; map[i]; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == 'o')
                printf("\033[00m\033[33mo\033[00m");
            else if (map[i][j] == '*')
                printf("*");
            else
                printf("X");
        }
        if (map[i + 1])
            printf("\n");
    }
}
