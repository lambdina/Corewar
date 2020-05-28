/*
** EPITECH PROJECT, 2020
** malloc_toolbox
** File description:
** any function used to malloc a string
*/

#include "lib.h"
#include <stdlib.h>
#include <stdbool.h>

char *my_strdup(const char *s)
{
    int len_string = my_strlen(s);
    char *result = (void *)0;

    if (len_string == 0)
        return ((void *)0);
    result = malloc(sizeof(char) * (len_string + 1));
    for (int i = 0; s[i] != '\0'; i++)
        result[i] = s[i];
    result[len_string] = '\0';
    return (result);
}

char *my_strcat(const char *s1, const char *s2)
{
    int len_string = 0;
    char *result = (void *)0;
    int ctr = 0;

    if (s2 == (void *)0 || s2[0] == 0)
        return (my_strdup(s1));
    else if (s1 == (void *)0 || s1[0] == 0)
        return (my_strdup(s2));
    len_string = my_strlen(s1) + my_strlen(s2) + 1;
    if (len_string == 1)
        return ((void *)0);
    result = malloc(sizeof(char) * (len_string + 1));
    for (; s1[ctr] != '\0'; ctr++)
        result[ctr] = s1[ctr];
    for (int ctr2 = 0; s2[ctr2] != '\0'; ctr2++)
        result[ctr + ctr2] = s2[ctr2];
    result[len_string] = '\0';
    return (result);
}

char *my_itoa(int nb)
{
    int nb_len = my_nblen(nb);
    char *result = (void *)0;
    bool is_negative = nb < 0 ? true : false;

    if (nb == 0)
        return (my_strdup("0"));
    result = malloc(sizeof(char) * (nb_len + 1));
    nb = is_negative == true ? nb * -1 : nb;
    result[nb_len] = '\0';
    for (int i = nb_len - 1; i > -1; i--) {
        result[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return (is_negative == true ? my_strcat("-", result) : result);
}
