/*
** EPITECH PROJECT, 2020
** write_magic_nb
** File description:
** function that writes magic number.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

void write_magic_number(int fd)
{
    int magic = 0;
    int tmp = 0;
    char c = 0;

    magic = COREWAR_EXEC_MAGIC;
    write(fd, &c, 1);
    tmp = (magic & 0xFF0000) >> 16;
    write(fd, &tmp, 1);
    tmp = (magic & 0xFF00) >> 8;
    write(fd, &tmp, 1);
    tmp = (magic & 0xFF);
    write(fd, &tmp, 1);
}
