/*
** EPITECH PROJECT, 2020
** magic_number
** File description:
** functions relatives to magic number.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int *extract_magic_nb(void)
{
    int nb = COREWAR_EXEC_MAGIC;

    return (split_in_bytes(nb, 4));
}
