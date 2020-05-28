/*
** EPITECH PROJECT, 2020
** string_functions
** File description:
** string_functions.c
*/

#include "asm.h"

char *my_strtrunc(char *str, int n)
{
    char *dest = NULL;
    int len = my_strlen(str);

    if (str == NULL || str[0] == 0 || n <= 0)
        return NULL;
    if (n > len)
        return str;
    dest = my_strdup(str);
    dest[n] = 0;
    return dest;
}

char *concat(char *s1, char *s2)
{
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);
    char *dest = NULL;
    int i = 0;

    if (size1 == 0 || s1[0] == 0)
        return s2;
    if (size2 == 0 || s2[0] == 0)
        return s1;
    dest = malloc(sizeof(char) * (size1 + size2 + 1));
    for (; i < size1; dest[i] = s1[i], i++);
    for (int j = 0; j < size2; dest[i] = s2[j], i++, j++);
    dest[i] = 0;
    return dest;
}
