/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/shared_ptr.h"
#include "program_model.h"
#include "vm.h"
#include "lib.h"

const mdata_t MB_PRG = {
    .copy = prg_copy,
    .destroy = prg_destroy,
    .data_size = sizeof(prg_t)
};

prg_t *prg_create(short int pc, int id, uint_t size)
{
    prg_t *prg = shared_ptr(MB_PRG);
    byte_t reg[REG_NUMBER * REG_SIZE] = {0};

    if (prg == NULL)
        return (NULL);
    prg->reg = mem_copy(reg, sizeof(byte_t) * REG_NUMBER * REG_SIZE);
    prg->size = size;
    prg->name = NULL;
    *(int *)&prg->reg[0] = id;
    revorder(&prg->reg[0], sizeof(int));
    prg->pc = pc;
    prg->org = pc;
    prg->carry = 0x1;
    prg->cycle = 1;
    prg->fid = id;
    return (prg);
}

byte_t *prg_get_reg(prg_t *prg, uint_t idx)
{
    if (prg == NULL || idx >= REG_NUMBER)
        return (NULL);
    return (prg->reg + (REG_SIZE * sizeof(char) * idx));
}

void prg_destroy(void *prg_p)
{
    prg_t *prg = prg_p;

    if (prg == NULL)
        return;
    free(prg->reg);
    if (prg->name != NULL)
        free(prg->name);
}

void *prg_copy(void const *prg_p)
{
    prg_t const *prg = prg_p;
    prg_t *cpy = (prg == NULL) ? NULL : shared_ptr(MB_PRG);

    if (prg == NULL)
        return (NULL);
    cpy->reg = mem_copy(prg->reg, REG_SIZE * REG_NUMBER);
    cpy->pc = prg->pc;
    cpy->name = mem_copy(prg->name, my_strlen(prg->name) + 1);
    cpy->size = prg->size;
    cpy->org = prg->org;
    cpy->carry = prg->carry;
    cpy->fid = prg->fid;
    cpy->cycle = 1;
    return (cpy);
}

void prg_free(prg_t **prg_p)
{
    prg_t *prg = (prg_p == NULL) ? NULL : *prg_p;

    if (prg == NULL || !is_shared(prg))
        return;
    spdestroy(prg);
    (*prg_p) = NULL;
}
