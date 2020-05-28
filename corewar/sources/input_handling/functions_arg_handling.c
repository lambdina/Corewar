/*
** EPITECH PROJECT, 2020
** functions_arg_handling.c
** File description:
** functions called by my_getopt
*/

#include "input_handling.h"
#include "macros.h"
#include "lib.h"
#include "p_vm.h"

bool is_corewar_file(char *filename)
{
    int len = 0;

    if (filename == NULL || filename[0] == 0)
        return (false);
    len = my_strlen(filename) - 4;
    if (len <= 0)
        return (false);
    else if (my_strcmp(&filename[len], ".cor") == 0)
        return (true);
    return (false);
}

void *edit_nbr_cycles(void *data, char *arg)
{
    stats_t *stats = data;

    if (is_num(arg) == true)
        stats->nbr_cycles = my_getnbr(arg);
    else stats->nbr_cycles = (-1);
    return (data);
}

void *edit_prog_number(void *data, char *arg)
{
    stats_t *stats = data;

    if (is_num(arg) == true)
        stats->program_nbr = my_getnbr(arg);
    else stats->program_nbr = 4;
    return (data);
}

void *load_address(void *data, char *arg)
{
    stats_t *stats = data;
    char *temp_nbr = convert_base(arg, "0123456789", "0123456789ABCDEF");
    int idx = temp_nbr == NULL ? 0 : my_getnbr(temp_nbr);

    FREE(temp_nbr);
    idx %= MEM_SIZE;
    stats->load_address = (idx < 0) ? MEM_SIZE - idx : idx;
    return (data);
}
