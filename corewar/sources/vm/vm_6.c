/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/shared_ptr.h"
#include "lib.h"

#include "p_vm.h"

void vm_print_winner(void)
{
    vm_t *vm = vm_instance();
    prg_t *prg = NULL;

    prg = it_data(list_begin(vm->pvec));
    if (prg == NULL)
        return;
    my_putstr("The player ");
    my_putnbr(prg->fid);
    my_putstr("(");
    my_putstr(prg->name);
    my_putstr(")has won.\n");
}
