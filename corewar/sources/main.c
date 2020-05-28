/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file
*/

#include "lib.h"
#include "op.h"
#include "macros.h"
#include "options.h"
#include "input_handling.h"
#include "program_model.h"
#include "vm.h"

static int display_usage(char *bin_name)
{
    my_putstr("USAGE\n./");
    my_putstr(bin_name);
    my_putstr(" [-dump nbr_cycle] [[-n prog_number] [-a load_address]");
    my_putstr(" prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the");
    my_putstr(" memory after the nbr_cycle execution (if the round is");
    my_putstr("n't already over) with the following format: 32 bytes/line ");
    my_putstr("in hexadecimal (AOBCDEFE1DD3...)\n-n prog_number sets the ");
    my_putstr("next program's number. By default, the first free number in");
    my_putstr(" parameter order\n-a load_address sets the next program's ");
    my_putstr("loading address. When no address is specified, optimize the");
    my_putstr(" addresses so that the processes are as far away from each");
    my_putstr("other as possible. The adresses are MEM_size modulo.\n");
    return (0);
}

int main(int ac, char **av)
{
    stats_t status = {
        .load_address = 0,
        .program_nbr = ac,
        .nbr_cycles = -1
    };

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_usage(av[0]));
    else if (my_getopt(ac, av, &status) != 0)
        return (84);
    if (status.nbr_cycles > 0)
        vm_start(status.nbr_cycles, (uint_t)status.load_address);
    else vm_start(0, (uint_t)status.load_address);
    return (0);
}
