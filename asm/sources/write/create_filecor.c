/*
** EPITECH PROJECT, 2020
** create_filecor
** File description:
** function that creates a file .cor
*/

#include "asm.h"
#include "lib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int create_filecor(char *filename)
{
    int fd = 0;
    int cor = my_strlen_until(filename, '.');
    filename = concat(my_strtrunc(filename, cor), ".cor");

    fd = open(filename, O_TRUNC | O_RDWR);
    if (fd == -1) {
        fd = open(filename, O_CREAT | O_APPEND | O_TRUNC | O_RDWR, 0666);
    }
    return fd;
}
