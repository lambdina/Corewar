/*
** EPITECH PROJECT, 2020
** get_labels
** File description:
** function that loads label
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

char **get_lbl_order(char *add_str)
{
    static char **lbl_order = NULL;

    if (add_str == NULL)
        return lbl_order;
    else lbl_order = append_str(lbl_order, add_str);
    return lbl_order;
}
