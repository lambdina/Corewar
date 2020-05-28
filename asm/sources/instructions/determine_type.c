/*
** EPITECH PROJECT, 2020
** get_type
** File description:
** function that get_type
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

bool is_param_ind(int op_tab_line, int size_params, int i)
{
    if ((op_tab[op_tab_line].type[i] & T_IND) == T_IND
    && size_params == IND_SIZE)
        return true;
    return false;
}

bool is_param_dir(int op_tab_line, int size_params, int i)
{
    if ((op_tab[op_tab_line].type[i] & T_DIR) == T_DIR
    && size_params == DIR_SIZE)
        return true;
    return false;
}

bool is_param_reg(int op_tab_line, int size_params, int i)
{
    if ((op_tab[op_tab_line].type[i] & T_REG) == T_REG
    && size_params == 1)
        return true;
    return false;
}

bool check_type(int *size_params, int op_tab_line)
{
    bool find = false;

    for (int i = 0; i < op_tab[op_tab_line].nbr_args; i++, find = false) {
        if (is_param_ind(op_tab_line, size_params[i], i))
            find = true;
        if (is_param_dir(op_tab_line, size_params[i], i))
            find = true;
        if (is_param_reg(op_tab_line, size_params[i], i))
            find = true;
        if (find == false)
            return false;
    }
    return true;
}

char *determine_type(int size_param)
{
    if (size_param == 1)
        return my_strdup("01");
    else if (size_param == DIR_SIZE)
        return my_strdup("10");
    else return my_strdup("11");
}