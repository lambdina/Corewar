/*
** EPITECH PROJECT, 2020
** tabint_functions
** File description:
** function that handles tab int
*/

#include "asm.h"

int *append_int(int *tab, int to_add)
{
    int len = my_intlen(tab);
    int *dest = my_memset(0, len + 1, sizeof(int));
    int i = 0;

    if (len == 0) {
        dest[0] = to_add;
        dest[1] = -1;
    }
    for (; i < len; i++)
        dest[i] = tab[i];
    dest[i] = to_add;
    dest[i + 1] = -1;
    return dest;
}

int *intconcat(int *tab1, int *tab2)
{
    int size1 = my_intlen(tab1);
    int size2 = my_intlen(tab2);
    int *dest = NULL;
    int i = 0;

    if (tab1 == NULL)
        return tab2;
    if (tab2 == NULL)
        return tab1;
    dest = my_memset(0, size1 + size2, sizeof(int));
    for (; i < size1; dest[i] = tab1[i], i++);
    for (int j = 0; j < size2; dest[i] = tab2[j], i++, j++);
    dest[i] = -1;
    return dest;
}

char *int_2_str(int nb)
{
    int size = 0;
    char *dest = 0;

    for (int i = nb; i > 0; i /= 10, size++);
    if (nb == 0)
        size = 1;
    dest = malloc(sizeof(char) * (size + 1));
    for (int i = size - 1; i >= 0; i--, nb /= 10)
        dest[i] = nb % 10 + '0';
    dest[size] = 0;
    return dest;
}
