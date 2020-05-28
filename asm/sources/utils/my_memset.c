/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** function that acts like memset
*/

#include "lib.h"
#include <stdlib.h>

int my_intlen(int *tab)
{
    char *tmp = (char *)tab;
    int i = 0;

    if (tmp == NULL)
        return 0;
    for (; tab[i] != -1; i++);
    return i;
}

void *my_memset(int value, int nb_cols, int size_bytes)
{
    int i = 0;
    int *dest = malloc(size_bytes * (nb_cols + 1));

    for (; i < nb_cols; dest[i] = value, i++);
    dest[i] = -1;
    return (void *)dest;
}
