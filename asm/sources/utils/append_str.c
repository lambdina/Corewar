/*
** EPITECH PROJECT, 2020
** append_str
** File description:
** function that append a string into a char **.
*/

#include "asm.h"
#include "macros.h"

char **append_str(char **tab, char *str)
{
    int lines = my_tablen((char const **)tab);
    char **dest = NULL;
    int i = 0;

    if (str == NULL || str[0] == 0)
        return tab;
    if (tab == NULL || tab[0] == NULL || tab[0][0] == 0) {
        dest = malloc(sizeof(char *) * 2);
        dest[0] = my_strdup(str);
        dest[1] = NULL;
        return dest;
    }
    dest = malloc(sizeof(char *) * (lines + 2));
    for (; i < lines; dest[i] = my_strdup(tab[i]), i++);
    dest[i] = my_strdup(str);
    dest[i + 1] = NULL;
    free_tab((void **)tab);
    return dest;
}
