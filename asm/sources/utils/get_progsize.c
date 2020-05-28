/*
** EPITECH PROJECT, 2020
** prog
** File description:
** prog
*/

#include <unistd.h>
#include <stdlib.h>

int *get_progsize(int value)
{
    int *tmp = malloc(sizeof(int) * 5);
    int cursor = 3;
    int bytes = 4;

    for (int i = 0; i < 4; i++)
        tmp[i] = 0;
    tmp[4] = -1;
    if (value == -2) {
        for (int i = 0; i != bytes; i++)
            tmp[cursor - i] = -2;
        return (NULL);
    }
    tmp[cursor] += value;
    for (int j = cursor; j != cursor - bytes; j--)
        while (tmp[j] >= 256) {
            tmp[j] -= 256;
            (tmp[j - 1] == -2) ? tmp[j - 1] = 0 : 0;
            tmp[j - 1]++;
        }
    return (tmp);
}