/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** function that switch a char * into an int
*/

#include "lib.h"
#include "asm.h"

int my_atoi(char *str)
{
    int nb = 0;
    bool isneg = false;

    if (str[0] == '-' ) {
        str++;
        isneg = true;
    }
    if (str == NULL || str[0] == 0 || !(str[0] >= '0' && str[0] <= '9'))
        return -1;
    for (int i = 0; str[i] != 0 && str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return isneg == true ? - nb : nb;
}
