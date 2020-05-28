/*
** EPITECH PROJECT, 2020
** attribute_str
** File description:
** function that returns the string surrounded by \"
*/

#include "asm.h"
#include "lib.h"

char *attribute_str(char *str, int size)
{
    char *dest = malloc(sizeof(char) * (size));
    int i = 0;
    int j = 0;
    int cols = 0;

    for (; str[i] != 0 && str[i] != '\"'; i++);
    i++;
    if (str[i] == 0)
        return NULL;
    cols = my_strlen_until(&str[i], '\"') + 1;
    if (str[cols + 2] != 0)
        write_error(HEADER_SIZE, str);
    for (; i <= cols && i < size; i++, j++)
        dest[j] = str[i];
    for (; j < size; j++)
        dest[j] = 0;
    return dest;
}
