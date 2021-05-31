/*
** EPITECH PROJECT, 2021
** my_array_len
** File description:
** strlen for char **
*/

int array_len(char **array)
{
    int len = 0;

    for (; array[len]; len += 1);
    return len;
}
