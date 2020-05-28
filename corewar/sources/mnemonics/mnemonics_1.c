/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "program_model.h"
#include "mnemonics.h"
#include "vm.h"
#include "op.h"
#include "istl/common_types.h"
#include "lib.h"
#include <stdio.h>

const int OFFSET_LIVE = 5;
const int OFFSET_FORK = 3;
const int OFFSET_LFORK = 3;
const int OFFSET_ZJMP = 3;
const int OFFSET_AFF = 2;

const op_function_t MNEMONICS[] = {
    mn_live,
    mn_ld,
    mn_st,
    mn_add,
    mn_sub,
    mn_and,
    mn_or,
    mn_xor,
    mn_zjmp,
    mn_ldi,
    mn_sti,
    mn_fork,
    mn_lld,
    mn_lldi,
    mn_lfork,
    mn_aff
};

int mn_live(prg_t *prg, oper_t const *op)
{
    int arg;

    if (prg == NULL || op == NULL)
        return (-1);
    vm_nread(prg->pc + 1, &arg, sizeof(int));
    my_putstr("The player ");
    my_putnbr(arg);
    my_putstr("(");
    my_putstr(prg->name);
    my_putstr(")is alive.\n");
    vm_current_alive();
    return (OFFSET_LIVE);
}

int mn_ld(prg_t *prg, oper_t const *op)
{
    byte_t type = 0;
    int values[2] = {0, 0};

    if (prg == NULL || op == NULL)
        return (-1);
    values[0] = oper_arg(op, 0, &type);
    if (type == BYTE_IS_IND)
        vm_nread(prg->pc + values[0] % IDX_MOD, &values[0], IND_SIZE);
    values[1] = oper_arg(op, 1, NULL) - 1;
    if (prg_set_reg(prg, values[1], values[0]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), ins_offset(op));
}

int mn_st(prg_t *prg, oper_t const *op)
{
    byte_t byte_type = 0;
    int values[2] = {0, 0};
    int *reg;

    if (prg == NULL || op == NULL)
        return (-1);
    reg = (int *)prg_reg(prg, oper_arg(op, 0, NULL) - 1);
    if (reg == NULL) {
        prg->carry = FALSE;
        return (ins_offset(op));
    }
    values[0] = *(int *)reg;
    values[1] = oper_arg(op, 1, &byte_type);
    if (byte_type == BYTE_IS_REG)
        if (prg_set_reg(prg, values[1], values[0]) != 0)
            return (prg_set_carry(prg, FALSE), -1);
    vm_nwrite(prg->pc + values[1] % IDX_MOD, &values[0], sizeof(int));
    return (ins_offset(op));
}

int mn_add(prg_t *prg, oper_t const *op)
{
    byte_t type;
    int vals[3] = {0, 0, 0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    for (short int i = 0; i < 2; i++) {
        vals[i] = oper_arg(op, i, &type);
        if (type == BYTE_IS_REG) {
            reg = (int *)prg_reg(prg, vals[i]);
            if (reg == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            vals[i] = *(int *)reg;
        }
    }
    vals[2] = oper_arg(op, 2, NULL) - 1;
    if (prg_set_reg(prg, vals[2], vals[0] + vals[1]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    prg_set_carry(prg, TRUE);
    return (ins_offset(op));
}

int mn_sub(prg_t *prg, oper_t const *op)
{
    byte_t type;
    int vals[3] = {0, 0, 0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    for (short int i = 0; i < 2; i++) {
        vals[i] = oper_arg(op, i, &type);
        if (type == BYTE_IS_REG) {
            reg = (int *)prg_reg(prg, vals[i]);
            if (reg == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            vals[i] = *(int *)reg;
        }
    }
    vals[2] = oper_arg(op, 2, NULL) - 1;
    if (prg_set_reg(prg, vals[2], vals[0] - vals[1]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    prg_set_carry(prg, TRUE);
    return (ins_offset(op));
}
