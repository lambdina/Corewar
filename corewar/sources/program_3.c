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

int cbyteless(byte_t code)
{
    if (code == 0x01)
        return (1);
    if (code == 0x09)
        return (1);
    if (code == 0x0c)
        return (1);
    if (code == 0x0f)
        return (1);
    return (0);
}

int prg_get_oper(prg_t *prg, oper_t *op)
{
    op_t tab;

    if (prg == NULL || op == NULL)
        return (-1);
    vm_nread(prg->pc, op, sizeof(oper_t));
    revorder(op, sizeof(oper_t));
    return (0);
}

int arg_size(byte_t cbyte)
{
    if (cbyte == 1)
        return (1);
    if (cbyte == 2)
        return (DIR_SIZE);
    if (cbyte == 3)
        return (IND_SIZE);
    return (0);
}

int prg_set_name(prg_t *prg, cchar_t nname)
{
    uint_t len = my_strlen(nname);

    if (prg == NULL)
        return (-1);
    if (prg->name != NULL)
        free(prg->name);
    if (len == 0)
        prg->name = NULL;
    else {
        prg->name = malloc(sizeof(char) * (len + 1));
        my_strcpy(prg->name, nname);
    }
    return (0);
}

int oper_arg(oper_t const *op, uint_t idx, byte_t *type)
{
    uint_t offset = 0;
    byte_t cbyte;
    int res = 0xFFFFFFFF;

    if (op == NULL)
        return (0);
    for (uint_t i = 0; i < idx; i++) {
        cbyte = op->cbyte >> (6 - i * 2);
        cbyte &= 0b00000011;
        offset += (cbyte == 1) ? 1 : 0;
        offset += (cbyte == 2) ? DIR_SIZE : 0;
        offset += (cbyte == 3) ? IND_SIZE : 0;
    }
    cbyte = (op->cbyte >> (6 - idx * 2)) & 0x03;
    if (type != NULL)
        (*type) = cbyte;
    res = (cbyte == 1) ? res & (*(op->args + offset)) : res;
    res = (cbyte == 2) ? res & (*(int *)(op->args + offset)) : res;
    res = (cbyte == 3) ? res & (*(short int *)(op->args + offset)) : res;
    return (revorder(&res, arg_size(cbyte)), res);
}
