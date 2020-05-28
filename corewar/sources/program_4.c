/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "istl/shared_ptr.h"
#include "program_model.h"
#include "vm.h"
#include "lib.h"

#include <stdio.h>

int prg_fid(prg_t const *prg)
{
    if (prg == NULL)
        return (0);
    return (prg->fid);
}

short int operi_arg(oper_t const *op, uint_t idx, byte_t *type)
{
    uint_t offset = 0;
    byte_t cbyte;
    short int res = 0xFFFF;

    if (op == NULL)
        return (0);
    for (uint_t i = 0; i < idx; i++) {
        cbyte = op->cbyte >> (6 - i * 2);
        cbyte &= 0b00000011;
        offset += (cbyte == 1) ? 1 : 0;
        offset += (cbyte > 1) ? IND_SIZE : 0;
    }
    cbyte = (op->cbyte >> (6 - idx * 2)) & 0x03;
    if (type != NULL)
        (*type) = cbyte;
    res = (cbyte == 1) ? res & (*(op->args + offset)) : res;
    res = (cbyte > 1) ? res & (*(short int *)(op->args + offset)) : res;
    return (revorder(&res, (cbyte == 1) ? 1 : IND_SIZE), res);
}

byte_t *prg_reg(prg_t *prg, uint_t idx)
{
    if (prg == NULL || idx >= REG_NUMBER)
        return (NULL);
    return (&prg->reg[REG_SIZE * idx]);
}

int prg_set_reg(prg_t *prg, uint_t idx, int val)
{
    int *reg = NULL;

    if (prg == NULL)
        return (-1);
    reg = (int *)prg_reg(prg, idx);
    if (reg == NULL)
        return (-1);
    *reg = val;
    return (0);
}

void prg_set_carry(prg_t *prg, bool_t carry)
{
    if (prg == NULL)
        return;
    prg->carry = carry;
}
