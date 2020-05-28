/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdio.h>
#include "mnemonics.h"
#include "op.h"
#include "vm.h"
#include "program_model.h"

int mn_and(prg_t *prg, oper_t const *op)
{
    byte_t type;
    int vals[3] = {0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    for (int i = 0; i < 2; i++) {
        vals[i] = oper_arg(op, i, &type);
        if (type == BYTE_IS_IND)
            vm_nread(prg->pc + vals[i], &vals[i], IND_SIZE);
        if (type == BYTE_IS_REG) {
            reg = (int *)prg_reg(prg, vals[i]);
            if (reg == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            vals[i] = *(int *)reg;
        }
    }
    if (prg_set_reg(prg, oper_arg(op, 2, NULL) - 1, vals[0] & vals[1]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), ins_offset(op));
}

int mn_or(prg_t *prg, oper_t const *op)
{
    byte_t type;
    int vals[3] = {0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    for (int i = 0; i < 2; i++) {
        vals[i] = oper_arg(op, i, &type);
        if (type == BYTE_IS_IND)
            vm_nread(prg->pc + vals[i], &vals[i], IND_SIZE);
        if (type == BYTE_IS_REG) {
            reg = (int *)prg_reg(prg, vals[i]);
            if (reg == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            vals[i] = *(int *)reg;
        }
    }
    if (prg_set_reg(prg, oper_arg(op, 2, NULL) - 1, vals[0] | vals[1]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), ins_offset(op));
}

int mn_xor(prg_t *prg, oper_t const *op)
{
    byte_t type;
    int vals[3] = {0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    for (int i = 0; i < 2; i++) {
        vals[i] = oper_arg(op, i, &type);
        if (type == BYTE_IS_IND)
            vm_nread(prg->pc + vals[i], &vals[i], IND_SIZE);
        if (type == BYTE_IS_REG) {
            reg = (int *)prg_reg(prg, vals[i]);
            if (reg == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            vals[i] = *(int *)reg;
        }
    }
    if (prg_set_reg(prg, oper_arg(op, 2, NULL) - 1, vals[0] ^ vals[1]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), ins_offset(op));
}

int mn_zjmp(prg_t *prg, oper_t const *op)
{
    byte_t *arg = NULL;
    boper_t bop;

    if (prg == NULL || op == NULL)
        return (-1);
    prg_get_oper(prg, (oper_t *)&bop);
    arg = &bop.args[0];
    revorder(arg, sizeof(short int));
    if (prg->carry == 0)
        return (0);
    return (*(short int *)arg % IDX_MOD);
}

int mn_ldi(prg_t *prg, oper_t const *op)
{
    int values[3] = {0, 0, 0};
    int *reg = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    if (extract_ldi_args(prg, op, values) != 0)
        return (-1);
    reg = (int *)prg_reg(prg, values[2]);
    if (reg == NULL)
        return (prg_set_carry(prg, FALSE), -1);
    vm_nread(prg->pc + (values[0] + values[1]) % IDX_MOD, reg, REG_SIZE);
    return (prg_set_carry(prg, TRUE), iins_offset(op));
}
