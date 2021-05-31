/*
** EPITECH PROJECT, 2021
** solver.h
** File description:
** .h of solver
*/

#ifndef SOLVER
#define SOLVER

#include <stdbool.h>

void solve(char **map);
char *open_read(char const *filename);
char **my_str_to_word_array(char *str, char separation);
int array_len(char **array);
bool find_path(char **map, int i, int j);

#endif /* !SOLVER */
