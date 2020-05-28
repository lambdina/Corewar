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
#include <stdlib.h>
#include "istl/common_types.h"
#include <stdio.h>
#include "vm.h"

int extract_ldi_args(prg_t *prg, oper_t const *op, int values[3])
{
    byte_t type;

    for (int i = 0; i < 2; i++) {
        values[i] = operi_arg(op, i, &type);
        if (type == BYTE_IS_IND && i != 1)
            vm_nread(prg->pc + values[i], &values[i], IND_SIZE);
        if (type == BYTE_IS_REG) {
            if (prg_reg(prg, values[i]) == NULL)
                return (prg_set_carry(prg, FALSE), -1);
            values[i] = *(int *)prg_reg(prg, values[i]);
        }
    }
}
