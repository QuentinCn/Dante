/*
** EPITECH PROJECT, 2021
** tests_generator.c
** File description:
** tests for the generator's functions
*/

#include <criterion/criterion.h>
#include "generator.h"

Test(count_star_around, normal_test_count_star)
{
    char *map[] = {"**X", "X*X", "X**", NULL};

    cr_assert_eq(count_star_around(map, 0, 1, &(info_map_t){3, 3, 0, 0}), 2);
    cr_assert_eq(count_star_around(map, 2, 2, &(info_map_t){3, 3, 0, 0}), 2);
    cr_assert_eq(count_star_around(map, 0, 2, &(info_map_t){3, 3, 0, 0}), 1);
    cr_assert_eq(count_star_around(map, 1, 0, &(info_map_t){3, 3, 0, 0}), 2);
    cr_assert_eq(count_star_around(map, 0, 0, &(info_map_t){3, 3, 0, 0}), 2);
    cr_assert_eq(count_star_around(map, 1, 2, &(info_map_t){3, 3, 0, 0}), 2);
    cr_assert_eq(count_star_around(map, 2, 0, &(info_map_t){3, 3, 0, 0}), 1);
}

Test(is_pos_valid, normal_test_pos_valid)
{
    char *map1[] = {"*XX", "XXX", "XXX", NULL};
    char *map2[] = {"**X", "X*X", "XXX", NULL};
    char *map3[] = {"***", "XX*", "XX*", NULL};
    char *map4[] = {"****", "XXX*", "X*X*", "X***", NULL};

    cr_assert_eq(is_pos_valid(map1, 0, 1, &(info_map_t){3, 3, 0, 0}), true);
    cr_assert_eq(is_pos_valid(map1, 1, 0, &(info_map_t){3, 3, 0, 0}), true);
    cr_assert_eq(is_pos_valid(map2, 0, 2, &(info_map_t){3, 3, 0, 0}), true);
    cr_assert_eq(is_pos_valid(map2, 1, 2, &(info_map_t){3, 3, 0, 0}), true);
    cr_assert_eq(is_pos_valid(map2, 2, 1, &(info_map_t){3, 3, 0, 0}), true);
    cr_assert_eq(is_pos_valid(map3, 1, 1, &(info_map_t){3, 3, 0, 0}), false);
    cr_assert_eq(is_pos_valid(map4, 2, 0, &(info_map_t){4, 4, 0, 0}), true);
}

Test(get_new_entry, normal_test_get_new_entry)
{
    char **map = malloc(sizeof(char *) * 4);
    info_map_t info = {3, 3, 0, 0};
    int i = 0;
    int j = 0;

    map[0] = strdup("*XX");
    map[1] = strdup("XXX");
    map[2] = strdup("XXX");
    map[3] = NULL;
    cr_assert_eq(get_new_entry(map, &i, &j, &info), 0);
    info.last_i = 0;
    i = 0;
    j = 0;
    map[0] = strdup("***");
    map[1] = strdup("X*X");
    map[2] = strdup("***");
    map[3] = NULL;
    cr_assert_eq(get_new_entry(map, &i, &j, &info), -1);
}

Test(create_map_with_x, normal_test_create_map)
{
    char **new = create_map_with_x(3, 3);
    char *expected[] = {"XXX", "XXX", "XXX", NULL};

    for (int i = 0; expected[i] && new[i]; i += 1)
        cr_assert_str_eq(expected[i], new[i]);
}

Test(array_len, normal_test_array_len)
{
    cr_assert_eq(array_len((char *[]){"XXX", "XXX", "XXX", NULL}), 3);
}

Test(go_to_end, normal_test_go_to_end)
{
    char **map = malloc(sizeof(char *) * 4);
    char *expected[] = {"*XX", "*XX", "***", NULL};
    int i = 0;
    int j = 0;

    map[0] = strdup("*XX");
    map[1] = strdup("XXX");
    map[2] = strdup("XXX");
    map[3] = NULL;
    go_to_end(map, &i, &j);
    for (int k = 0; expected[k] && map[k]; k += 1)
        cr_assert_str_eq(expected[k], map[k]);
}
