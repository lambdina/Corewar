/*
** EPITECH PROJECT, 2020
** get_label_pos2
** File description:
** pos
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int get_nb_bytes_line(func *list, int i)
{
    int nb_bytes = (i > 0) ? list[i - 1].cur_bsize : 0;

    return nb_bytes;
}

int *compute_byte_shift(func *list, int pos_struct, int line_def)
{
    int *dest = NULL;
    int nb_bytes_call = get_nb_bytes_line(list, pos_struct);
    int nb_bytes_def = get_nb_bytes_line(list, line_def);
    int value = nb_bytes_def - nb_bytes_call;
    int size = 0;
    int i = 0;

    for (; list[pos_struct].parameters->args[i] >= 0; i++);
    for (; list[pos_struct].parameters->args[i] < 0
    && list[pos_struct].parameters->args[i] != -1; i++, size++);
    if (size == IND_SIZE)
        dest = set_indirect(value, size);
    else dest = set_dir(value, size);
    return dest;
}
