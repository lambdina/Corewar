/*
** EPITECH PROJECT, 2020
** write_str
** File description:
** functio that writes trings.
*/

#include "asm.h"
#include "lib.h"

void write_str(int fd, char *str, int size)
{
    write(fd, str, size);
}
