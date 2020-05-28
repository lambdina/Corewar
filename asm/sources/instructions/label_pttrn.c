/*
** EPITECH PROJECT, 2020
** label_pttrn
** File description:
** function that returns true or false depending on if it recognizes label.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

bool valid_label(char *str)
{
    int *type_error = NULL;

    for (int i = 0; str[i] != 0 && str[i] != LABEL_CHARS; i++)
        if (char_count(LABEL_VALID_CHARS, str[i]) == 0) {
            write_error(WRONG_LBL_CHAR, str);
        }
    return true;
}

bool is_label_pttrn(char *str)
{
    int i = my_strlen_until(str, ' ');

    if (i > 0 && str[i - 1] == LABEL_CHARS)
        return true;
    return false;
}
