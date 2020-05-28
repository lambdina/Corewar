/*
** EPITECH PROJECT, 2020
** get_instruct
** File description:
** function that get the instructions
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int get_tab_line(char *line)
{
    for (int i = 0; op_tab[i].mnemonique != (void *)0; i++) {
        if (!my_strncmp(op_tab[i].mnemonique, line,
        my_strlen_until(line, ' ')))
            return i;
    }
    write_error(INSTRUCTION_NOT_FOUND, line);
}
