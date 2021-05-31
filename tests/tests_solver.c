/*
** EPITECH PROJECT, 2021
** tests_solver.c
** File description:
** tests for the solver's functions
*/

#include <criterion/criterion.h>
#include "solver.h"

Test(find_path, normal_tests_find_path)
{
    char *expected[] = {
        "ooXooooooX",
        "XoooX*XXoo",
        "*X*X*X**Xo",
        "*X****X*Xo",
        "**X*X*X*Xo",
        "*X**X*X*Xo",
        "*X*X**X**o",
        "**X**X**Xo",
        "X*X*XX*X*o",
    "****X***Xo"};
    char **map = malloc(sizeof(char *) * 11);

    map[0] = strdup("o*X******X");
    map[1] = strdup("X***X*XX**");
    map[2] = strdup("*X*X*X**X*");
    map[3] = strdup("*X****X*X*");
    map[4] = strdup("**X*X*X*X*");
    map[5] = strdup("*X**X*X*X*");
    map[6] = strdup("*X*X**X***");
    map[7] = strdup("**X**X**X*");
    map[8] = strdup("X*X*XX*X**");
    map[9] = strdup("****X***X*");
    map[10] = NULL;
    find_path(map, 0, 0);
    for (int i = 0; map[i] && expected[i]; i += 1)
        cr_assert_str_eq(expected[i], map[i]);
}
