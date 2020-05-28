/*
** EPITECH PROJECT, 2020
** opthandler_main.c
** File description:
** opthandler main function
*/

#include "options.h"
#include "lib.h"
#include "program_model.h"
#include "vm.h"

const opt_t OPTIONS[] = {
    {&edit_nbr_cycles,  true,   0,      "dump"},
    {&edit_prog_number, true,   'n',    NULL},
    {&load_address,     true,   'a',    NULL},
    {NULL,              false,  0,      NULL}
};

static int opt_error(char *arg, char *error_msg)
{
    my_puterror("error:");
    my_puterror(arg);
    my_puterror(error_msg);
    return -1;
}

static int check_if_flag(char *arg)
{
    int arg_len = 0;

    if (arg == NULL || arg[0] == 0 || arg[0] != '-')
        return (-1);
    arg_len = my_strlen(arg);
    for (int i = 0; OPTIONS[i].function != NULL; i++) {
        if (arg_len == 2 && arg[1] == OPTIONS[i].short_option)
            return (i);
        else if (my_strcmp(&arg[1], OPTIONS[i].long_option) == 0)
            return (i);
    }
    return (-1);
}

static int update_i(int i, int flag)
{
    if (flag == -1)
        return (i + 1);
    return (OPTIONS[flag].expect_optarg == true ? i + 1 : i);
}

static bool is_valid_argument(int ac, char **args, int i)
{
    if (i + 1 == ac)
        return (false);
    return (args[i + 1][0] == '-' ? false : true);
}

int my_getopt(int ac, char **av, void *data)
{
    int flag = 0;

    for (int i = 1; i < ac; i++) {
        flag = check_if_flag(av[i]);
        if (av[i][0] == '-' && flag == -1) {
            return (opt_error(av[i], "is not a known flag.\n"));
        } else if (flag != -1 &&
        OPTIONS[flag].expect_optarg && !is_valid_argument(ac, av, i)) {
            return (opt_error(av[i], "expects an argument.\n"));
        } else data = flag == -1 ? data : OPTIONS[flag].function(data,
        OPTIONS[flag].expect_optarg == true ? av[i + 1] : NULL);
        if (is_corewar_file(av[i])) {
            vm_open(av[i]);
            continue;
        }
        i = update_i(i, flag);
    }
    return (0);
}
