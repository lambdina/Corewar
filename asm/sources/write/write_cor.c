/*
** EPITECH PROJECT, 2020
** write_cor
** File description:
** function that write the corewar in a file.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int set_size(func *instruction)
{
    int i;

    for (i = 0; instruction[i].cur_bsize > 0; i++);
    return (instruction[i - 1].cur_bsize);
}

int *get_prog_size(int value)
{
    int *tmp = my_memset(0, 4, sizeof(int));

    if (value == -2) {
        for (int i = 0; i != 4; i++)
            tmp[3 - i] = -2;
        return (0);
    }
    tmp[3] += value;
    for (int j = 3; j != -1; j--)
        while (tmp[j] >= 256) {
            tmp[j] -= 256;
            (tmp[j - 1] == -2) ? tmp[j - 1] = 0 : 0;
            tmp[j - 1]++;
        }
    return (tmp);
}

void write_core(char *file_s, header_t header, func *instruction, int size)
{
    int fd = create_filecor(file_s);
    int *progsize;

    write_magic_number(fd);
    write_str(fd, header.prog_name, PROG_NAME_LENGTH + 4);
    progsize = get_prog_size(set_size(instruction));
    write_bytes(progsize, fd);
    write_str(fd, header.comment, COMMENT_LENGTH + 4);
    for (int i = 0; instruction[i].cur_bsize != 0
    && instruction[i].cur_bsize != -1; i++) {
        write_single_byte(instruction[i].instruction_id, fd);
        write_bytes(instruction[i].parameters->type, fd);
        write_bytes(instruction[i].parameters->args, fd);
    }
    close(fd);
}
