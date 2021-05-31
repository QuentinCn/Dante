/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main of the generator
*/

#include "generator.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char const * av[])
{
    if (handle_error(ac, av) == -1)
        return 84;
    generate_map(atoi(av[1]), atoi(av[2]), (av[3] == NULL)?0:1);
    return 0;
}
