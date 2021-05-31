/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** handle errors for the generator
*/

int handle_error(int ac, char const * av[])
{
    if (ac != 3 && ac != 4)
        return -1;
    for (int i = 0; av[1][i] != '\0'; i += 1)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return -1;
    for (int i = 0; av[2][i] != '\0'; i += 1)
        if (!(av[2][i] >= '0' && av[2][i] <= '9'))
            return -1;
    return 0;
}
