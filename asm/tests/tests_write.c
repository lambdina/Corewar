/*
** EPITECH PROJECT, 2020
** tests_write
** File description:
** function that tests if it writes.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

Test(set_size, test_if_set_size)
{
    func *instruction = malloc(sizeof(func) * 4);

    for (int i = 0; i < 3; i++)
        instruction[i].cur_bsize = i;
    instruction[3].cur_bsize = -1;
}
