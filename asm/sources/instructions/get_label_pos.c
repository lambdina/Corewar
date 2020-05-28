/*
** EPITECH PROJECT, 2020
** pos
** File description:
** pos
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

char **get_lbl_def_idx(char **buf)
{
    char **dest = NULL;
    int line = 0;

    for (int i = 0; buf[i]; i++, line++) {
        if (is_label_pttrn(buf[i])) {
            dest = append_str(dest,
            my_strtrunc(buf[i], my_strlen_until(buf[i], LABEL_CHARS)));
            dest = append_str(dest, int_2_str(line));
            buf[i][my_strlen_until(buf[i], LABEL_CHARS) + 1] == 0 ?
            line-- : line;
        }
    }
    return dest;
}

int find_line_def(char *call, char **dico_label)
{
    int len = my_tablen((char const **)dico_label);

    for (int i = 0; i < len; i += 2)
        if (!my_strcmp(just_clean(call), just_clean(dico_label[i])))
            return my_atoi(dico_label[i + 1]);
    return -1;
}

func *get_label_pos(char **buf, func *list)
{
    char **dico_label = get_lbl_def_idx(buf);
    char **calls_label = get_lbl_order(NULL);
    int size = 0;
    int line_def = 0;
    int *dest = NULL;

    for (int i = 0, j = 0; list[i].cur_bsize > 0; i++) {
        for (j = 0, size = 0; list[i].parameters->args[j] >= 0; j++);
        for (; list[i].parameters->args[j] == UNSET; j++, size++);
        if (size != 0) {
            line_def = find_line_def(calls_label[0], dico_label);
            if (line_def == -1)
                write_error(LABEL_NEVER_DEFINE, calls_label[0]);
            dest = compute_byte_shift(list, i, line_def);
            for (int k = 0; dest[k] != -1; j++, k++)
                list[i].parameters->args[j - size] = dest[k];
            calls_label++;
        }
    }
    return free_tab((void **)dico_label), list;
}
