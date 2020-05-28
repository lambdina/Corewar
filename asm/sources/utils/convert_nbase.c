/*
** EPITECH PROJECT, 2020
** convert_nbase
** File description:
** function that converts an number into another.
*/

#include "asm.h"
#include "lib.h"

int my_pow(int nb, int pow)
{
    int tmp = nb;

    if (pow == 0)
        return 1;
    else if (pow == 1)
        return nb;
    for (; pow > 1; pow--)
        nb *= tmp;
    return nb;
}

int atoi_base(char *str, int base)
{
    int len_message = my_strlen(str) - 1;
    int decimal = 0;

    if (str == NULL)
        return decimal;
    for (int pos = 0; str[pos] != 0; len_message--, pos++)
        decimal += (str[pos] - '0') * my_pow(base, len_message);
    return decimal;
}
