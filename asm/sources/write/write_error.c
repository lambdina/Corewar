/*
** EPITECH PROJECT, 2020
** write_error
** File description:
** function that writes errors.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

void write_error(int type_error, char *line)
{
    int i = type_error;
    char c = '\n';

    if (line != NULL)
        write(2, line, my_strlen(line));
    write(2, ERR_MSG[i].err_msg, my_strlen(ERR_MSG[i].err_msg));
    write(2, &c, 1);
    exit(84);
}
