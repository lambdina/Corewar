/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "op.h"
#include "mnemonics.h"
#include "program_model.h"
#include <unistd.h>
#include "istl/common_types.h"
#include <stdio.h>

int mn_aff(prg_t *prg, oper_t const *op)
{
    byte_t to_display = 0;

    if (prg == NULL || op == NULL)
        return (-1);
    to_display = prg->pc + 1;
    write(1, &to_display, 1);
    return (OFFSET_AFF);
}

int ins_args(oper_t const *op)
{
    byte_t mask = 0b11000000;
    byte_t val;
    int counter = 0;

    if (op == NULL)
        return (-1);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        val = op->cbyte & mask;
        mask = mask >> 2;
        if (val == 0)
            break;
        counter += 1;
    }
    return (counter);
}

int ins_offset(oper_t const *op)
{
    byte_t mask = 0b11000000;
    byte_t val;
    int counter = 2;

    if (op == NULL)
        return (-1);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        val = op->cbyte & mask;
        mask = mask >> 2;
        val = val >> (6 - i * 2);
        if (val == 0 || op->cbyte == 0)
            break;
        counter += (val == 1) ? 1 : 0;
        counter += (val == 2) ? DIR_SIZE : 0;
        counter += (val == 3) ? IND_SIZE : 0;
    }
    return (counter);
}

int iins_offset(oper_t const *op)
{
    byte_t mask = 0b11000000;
    byte_t val;
    int counter = 2;

    if (op == NULL)
        return (-1);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        val = op->cbyte & mask;
        mask = mask >> 2;
        val = val >> (6 - i * 2);
        if (val == 0 || op->cbyte == 0)
            break;
        counter += (val == 1) ? 1 : 0;
        counter += (val == 2) ? 2 : 0;
        counter += (val == 3) ? 2 : 0;
    }
    return (counter);
}

inline bool_t check_if_direct(byte_t byte)
{
    return (byte & 0b10000000 == 0b0000000 ? FALSE : TRUE);
}
