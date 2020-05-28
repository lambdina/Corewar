/*
** EPITECH PROJECT, 2020
** set_negative
** File description:
** function that sets a negative instructions
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int *set_negative(int value, int size)
{
    int *dest = my_memset(0xff, size, sizeof(int));
    int div = 0;

    value = value * (- 1);
    value--;
    div = value / (0xff + 1);
    dest[size - 2] -= div;
    dest[size - 1] -= value % (0xff + 1);
    return dest;
}
