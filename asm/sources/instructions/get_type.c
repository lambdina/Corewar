/*
** EPITECH PROJECT, 2020
** get_type
** File description:
** function that get_type
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int *get_type(int *size_params, int op_tab_line, int nb_params)
{
    char *str_type = NULL;
    int *int_type = NULL;

    if (!check_type(size_params, op_tab_line))
        write_error(PARAM_TYPE, NULL);
    for (int i = 0; size_params[i] != -1; i++)
        str_type = concat(str_type, determine_type(size_params[i]));
    for (; nb_params < 4; nb_params++)
        str_type = concat(str_type, "00");
    int_type = my_memset(0, 1, sizeof(int));
    int_type[0] = atoi_base(str_type, 2);
    free(str_type);
    return int_type;
}
