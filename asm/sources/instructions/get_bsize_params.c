/*
** EPITECH PROJECT, 2020
** get_bsize_params
** File description:
** function that fill an int * about params bytes size.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int *multi_params_func(char *line, int param_start, int *dest, int len)
{
    char *tmp = NULL;

    while (param_start < len) {
        tmp = my_strdup(del_fore_spaces(&line[param_start]));
        if (tmp[0] == DIRECT_CHAR)
            dest = append_int(dest, DIR_SIZE);
        if (tmp[0] == 'r')
            dest = append_int(dest, 1);
        if ((tmp[0] == '-' && tmp[1] >= '0' && tmp[1] <= '9') ||
        (tmp[0] >= '0' && tmp[0] <= '9') || tmp[0] == LABEL_CHARS)
            dest = append_int(dest, IND_SIZE);
        param_start += my_strlen_until(&line[param_start], SEPARATOR_CHAR) + 1;
    }
    return dest;
}

int *get_bsize(char *line)
{
    int *dest = NULL;
    int param_start = my_strlen_until(line, ' ') + 1;
    char *function = my_strtrunc(line, param_start - 1);
    int len = my_strlen(line);

    if (!my_strcmp(function, "zjmp") ||
    !my_strcmp(function, "fork") || !my_strcmp(function, "lfork"))
        dest = my_memset(IND_SIZE, 1, sizeof(int));
    else dest = multi_params_func(line, param_start, dest, len);
    return dest;
}
