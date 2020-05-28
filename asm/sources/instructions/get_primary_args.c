/*
** EPITECH PROJECT, 2020
** get_primary_args
** File description:
** function that extracts the primary args
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int *set_offset_label(int size, char *args)
{
    int *dest = my_memset(UNSET, size, sizeof(int));

    get_lbl_order(args);
    return dest;
}

int *set_reg(int value)
{
    int *dest = my_memset(0, 1, sizeof(int));

    if (value <= 0 || value > REG_NUMBER)
        write_error(BAD_REG_SIZE, NULL);
    dest[0] = value;
    return dest;
}

int *set_indirect(int value, int size)
{
    int *dest = my_memset(0, size, sizeof(int));
    int *tmp = NULL;

    if (value < 0) {
        free(dest);
        return set_negative(value, size);
    }
    else {
        dest[size - 1] = value % (0xff + 1);
        dest[size - 2] = value / (0xff + 1);
    }
    return dest;
}

int *set_dir(int nb, int size)
{
    int *dest = NULL;
    int tmp = nb;

    if (nb < 0)
        return set_negative(nb, size);
    dest = my_memset(0, size, sizeof(int));
    if (size >= 4 && nb > 0xffffff) {
        dest[size - 4] = (tmp / (0xffffff + 1));
        tmp %= (0xffffff + 1);
    }
    if (size >= 3 && nb > 0xffff) {
        dest[size - 3] = (tmp / (0xffff + 1));
        tmp %= (0xffff + 1);
    }
    if (size >= 2 && nb > 0xff) {
        dest[size - 2] = (tmp / (0xff + 1));
        tmp %= (0xff + 1);
    }
    dest[size - 1] = tmp;
    return dest;
}

int *get_primary_args(char *line, int size, bool is_indir_func)
{
    int len_arg = my_strlen_until(line, SEPARATOR_CHAR);
    char *args = my_strtrunc(line, len_arg);
    int *dest = NULL;

    args = (args[0] == DIRECT_CHAR) ? args + 1 : args;
    if (size == DIR_SIZE && is_indir_func == true)
        size = IND_SIZE;
    if (size == 1)
        dest = set_reg(my_atoi(&args[1]));
    if (size == IND_SIZE) {
        if (args[0] == LABEL_CHARS)
            dest = set_offset_label(size, &args[1]);
        else dest = set_indirect(my_atoi(args), size);
    }
    if (size == DIR_SIZE) {
        if (args[0] == LABEL_CHARS)
            dest = set_offset_label(size, &args[1]);
        else dest = set_dir(my_atoi(args), size);
    }
    return dest;
}
