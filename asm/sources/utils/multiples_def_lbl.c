/*
** EPITECH PROJECT, 2020
** multiples_def_lbl
** File description:
** function that check if there are several definitions of a label.
*/

#include "asm.h"
#include "lib.h"
#include "macros.h"

bool tab_cmp(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = i + 1; tab[j] != NULL; j++) {
            if (!my_strcmp(tab[i], tab[j]))
                return true;
        }
    }
    return false;
}

char **get_label_def(char **buf)
{
    char **labels = NULL;
    int col_until = 0;

    if (labels == NULL) {
        for (int lines = 2; buf[lines] != 0; lines++) {
            if (is_label_pttrn(buf[lines])) {
                col_until = my_strlen_until(buf[lines], LABEL_CHARS);
                labels = append_str(labels, my_strtrunc(buf[lines], col_until));
            }
        }
    }
    return labels;
}

void multiples_def_lbl(char **buf)
{
    char **labels = get_label_def(buf);
    int col_until = 0;

    if (my_tablen((char const **)labels) <= 1) {
        free_tab((void **)labels);
        return;
    }
    if (tab_cmp(labels)) {
        free_tab((void **)labels);
        write_error(LABEL_CONFLICT_DEFINE, NULL);
    }
    free_tab((void **)labels);
}
