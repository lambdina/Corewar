/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdio.h>
#include "program_model.h"
#include "mnemonics.h"
#include "vm.h"
#include "op.h"
#include "istl/common_types.h"

int mn_sti(prg_t *prg, oper_t const *op)
{
    int values[4] = {0};
    byte_t type;

    values[0] = operi_arg(op, 0, NULL) - 1;
    for (short int i = 1; i < 3; i++) {
        values[i] = operi_arg(op, i, &type);
        if (type == BYTE_IS_IND && i != 2)
            vm_nread(prg->pc + values[i], &values[i], IND_SIZE);
        if (type == BYTE_IS_REG) {
            if (prg_reg(prg, values[i] - 1) == NULL)
                return (-1);
            values[i] = *(int *)prg_reg(prg, values[i] - 1);
        }
    }
    values[3] = (prg->pc + (values[1] + values[2]) % IDX_MOD) % MEM_SIZE;
    if (vm_nwrite(values[3], prg_reg(prg, values[0]), REG_SIZE) != 0)
        return (-1);
    return (iins_offset(op));
}

int mn_fork(prg_t *prg, oper_t const *op)
{
    prg_t *cpy = NULL;
    short int arg;
    byte_t *code = NULL;

    cpy = prg_copy(prg);
    vm_nread(prg->pc + 1, &arg, sizeof(short int));
    code = malloc(sizeof(byte_t) * prg_size(prg));
    if (code == NULL)
        return (-1);
    vm_nread(prg->org, code, prg_size(prg));
    revorder(code, prg_size(prg));
    cpy->org = prg->org + prg_size(prg);
    cpy->pc = (prg->pc + prg_size(prg) + arg % IDX_MOD) % MEM_SIZE;
    vm_nwrite(cpy->org, code, prg_size(prg));
    vm_add_prg(cpy);
    free(code);
    return (OFFSET_FORK);
}

int mn_lld(prg_t *prg, oper_t const *op)
{
    byte_t type = 0;
    int values[2] = {0, 0};

    values[0] = oper_arg(op, 0, &type);
    if (type == BYTE_IS_IND)
        vm_nread(prg->pc + values[0], &values[0], IND_SIZE);
    values[1] = oper_arg(op, 1, NULL) - 1;
    if (prg_set_reg(prg, values[1], values[0]) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), ins_offset(op));
}

int mn_lldi(prg_t *prg, oper_t const *op)
{
    int values[3] = {0, 0, 0};
    int s = 0;
    byte_t type;

    values[2] = operi_arg(op, 2, NULL) - 1;
    for (int i = 0; i < 2; i++) {
        values[i] = operi_arg(op, i, &type);
        if (type == BYTE_IS_IND && i != 1)
            vm_nread(prg->pc + values[i], &values[i], IND_SIZE);
        if (type == BYTE_IS_REG)
            values[i] = prg->reg[REG_SIZE * values[i]];
    }
    s = values[0] + values[1];
    if (vm_nread(prg->pc + s, prg_reg(prg, values[2]), REG_SIZE) != 0)
        return (prg_set_carry(prg, FALSE), -1);
    return (prg_set_carry(prg, TRUE), iins_offset(op));
}

int mn_lfork(prg_t *prg, oper_t const *op)
{
    prg_t *cpy = NULL;
    short int arg;
    byte_t *code = NULL;

    if (prg == NULL || op == NULL)
        return (-1);
    cpy = prg_copy(prg);
    vm_nread(prg->pc + 1, &arg, sizeof(short int));
    revorder(&arg, sizeof(short int));
    code = malloc(sizeof(byte_t) * (prg_size(prg) + 1));
    if (code == NULL)
        return (-1);
    vm_nread(prg->org, code, prg_size(prg));
    revorder(code, prg_size(prg));
    vm_nwrite(prg->org + prg_size(prg), code, prg_size(prg));
    cpy->pc = (prg->pc + prg_size(prg) + arg) % MEM_SIZE;
    vm_add_prg(cpy);
    free(code);
    return (OFFSET_FORK);
}
