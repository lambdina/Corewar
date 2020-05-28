/*
** EPITECH PROJECT, 2020
** prog_size
** File description:
** compute the prog size.
*/

#include "asm.h"
#include "lib.h"

int char_count(char *str, char c)
{
    int occurence = 0;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            occurence++;
    return occurence;
}

int prog_size(func *inst, int i, params_t params)
{
    int current_size = my_intlen(params.type) + my_intlen(params.args) + 1;

    if (i > 0)
        current_size += inst[i - 1].cur_bsize;
    return current_size;
}
