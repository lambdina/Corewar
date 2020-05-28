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

uint_t prg_size(prg_t const *prg)
{
    if (prg == NULL)
        return (0);
    return (prg->size);
}

static byte_t *read_code_section(int fd, int size)
{
    byte_t *buff = NULL;

    buff = malloc(sizeof(byte_t) * size);
    if (buff == NULL)
        return (NULL);
    read(fd, buff, size);
    return (buff);
}

bool_t prg_carry(prg_t const *prg)
{
    if (prg == NULL)
        return (FALSE);
    return (prg->carry);
}

int prg_step(prg_t *prg)
{
    oper_t op;
    op_t found;
    op_function_t f = NULL;
    int res;

    if (prg == NULL)
        return (-1);
    prg_get_oper(prg, &op);
    if (op.code == 0 || op.code > 0x10)
        return (-1);
    found = op_tab[op.code - 1];
    f = MNEMONICS[op.code - 1];
    if (prg->cycle == found.nbr_cycles) {
        prg->cycle = 1;
        res = f(prg, &op);
        if (res == -1)
            return (-1);
        prg->pc += res;
    } else prg->cycle += 1;
    return (0);
}

int prg_read_code(int fd, byte_t **buff, char *nbuff)
{
    header_t header;
    int res;

    if (buff == NULL)
        return (-1);
    if (read(fd, &header, sizeof(header)) != sizeof(header))
        return (-1);
    revorder(&header.prog_size, sizeof(header.prog_size));
    if (*buff == NULL)
        (*buff) = malloc(sizeof(byte_t) * header.prog_size);
    if (*buff == NULL)
        return (-1);
    res = read(fd, (*buff), header.prog_size);
    if (res != header.prog_size)
        return (-1);
    my_strcpy(nbuff, header.prog_name);
    lseek(fd, 0, SEEK_SET);
    return (res);
}
