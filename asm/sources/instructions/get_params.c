/*
** EPITECH PROJECT, 2020
** get_params
** File description:
** function that extracts params, loads it.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

bool no_type_func(char *func)
{
    func = my_strtrunc(func, my_strlen_until(func, ' '));

    if (!my_strcmp(func, "live") || !my_strcmp(func, "zjmp") ||
    !my_strcmp(func, "fork") || !my_strcmp(func, "lfork"))
        return true;
    return false;
}

bool is_ind_func(char *func)
{
    func = my_strtrunc(func, my_strlen_until(func, ' '));

    if (!my_strcmp(func, "live"))
        return false;
    if (no_type_func(func))
        return true;
    if (!my_strcmp(func, "sti") || !my_strcmp(func, "lldi")
    || !my_strcmp(func, "ldi"))
        return true;
    return false;
}

void init_params(params_t *params, char *line, int op_tab_line, int nb_params)
{
    params->size_per_param = get_bsize(line);
    params->type = no_type_func(line) ? NULL :
    get_type(params->size_per_param, op_tab_line, nb_params);
    params->args = NULL;
}

params_t *get_params(char *line, int op_tab_line)
{
    char *tmp = my_strdup(line);
    params_t *params = malloc(sizeof(params_t));
    int param_start = my_strlen_until(line, ' ') + 1;
    int nb_params = 1 + char_count(&line[param_start], SEPARATOR_CHAR);

    if (nb_params != op_tab[op_tab_line].nbr_args) {
        write_error((nb_params > op_tab[op_tab_line].nbr_args) ?
        TOO_MUCH_PARAMS : TOO_FEW_PARAMS, line);
    }
    init_params(params, line, op_tab_line, nb_params);
    for (int i = 0; i < nb_params; i++) {
        tmp = del_fore_spaces(&tmp[param_start]);
        params->args = intconcat(params->args, get_primary_args(tmp,
        params->size_per_param[i], is_ind_func(line)));
        param_start = my_strlen_until(tmp, SEPARATOR_CHAR) + 1;
    }
    free(tmp);
    return params;
}
