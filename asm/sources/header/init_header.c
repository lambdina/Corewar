/*
** EPITECH PROJECT, 2020
** init_header
** File description:
** function that fill the header structure.
*/

#include "asm.h"
#include "op.h"

bool init_name_and_comment(header_t *head, char **buf)
{
    if (my_tablen((char const **)buf) < 2)
        return false;
    if (!my_strncmp(NAME_CMD_STRING, buf[0], my_strlen(NAME_CMD_STRING) - 1)) {
        head->prog_name = attribute_str(&buf[0][my_strlen(NAME_CMD_STRING)],
        PROG_NAME_LENGTH + 4);
        if (my_strlen(head->prog_name) > PROG_NAME_LENGTH)
            return false;
    }
    else return false;
    if (!my_strncmp(COMMENT_CMD_STRING, buf[1],
    my_strlen(COMMENT_CMD_STRING) - 1)) {
        head->comment = attribute_str(&buf[1][my_strlen(COMMENT_CMD_STRING)],
        COMMENT_LENGTH + 4);
        if (my_strlen(head->comment) > COMMENT_LENGTH)
            return false;
        else return true;
    }
    return false;
}

bool init_header(header_t *head, char **buf)
{
    int type_error = SUCCESS;

    if (init_name_and_comment(head, buf) == false) {
        type_error = HEADER_SIZE;
        write_error(type_error, buf[0]);
    }
    return true;
}
