/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** .h of generator
*/

#ifndef GENERATOR
#define GENERATOR

#include <stdbool.h>

typedef struct info_map_s
{
    int len_map_i;
    int len_map_j;
    int last_i;
    int random;
}info_map_t;

int handle_error(int ac, char const * av[]);
void generate_map(int x, int y, bool status);
int get_new_entry(char **map, int *i, int *j, info_map_t *info);
int array_len(char **array);
void complete_map(char **map, bool status);
char **create_map_with_x(int x, int y);
bool is_in_angle(int i, int j, info_map_t *info);
int count_star_around(char **map, int i, int j, info_map_t *info);
void go_to_end(char **map, int *i, int *j);
bool is_pos_valid(char **map, int i, int j, info_map_t *info);
void display_map_with_color(char **map);
void do_imperfect(char **map, int *i, int *j, info_map_t *info);
void do_perfect(char **map, int *i, int *j, info_map_t *info);

#endif /* !GENERATOR */
