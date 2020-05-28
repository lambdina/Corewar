/*
** EPITECH PROJECT, 2020
** write_bytes
** File description:
** function that write bytes.
*/

#include "asm.h"
#include "lib.h"

void write_single_byte(int byte, int fd)
{
    write(fd, &byte, 1);
}

void write_bytes(int *line, int fd)
{
    if (line == NULL)
        return;
    for (int i = 0; line[i] != -1; i++)
        write(fd, &line[i], 1);
    return;
}
