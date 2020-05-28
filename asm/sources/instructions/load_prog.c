/*
** EPITECH PROJECT, 2020
** core_prog
** File description:
** function that fill the func structure.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

func *init_struct(char **buf)
{
    int lines = my_tablen((char const **)buf);
    func *instructions = malloc(sizeof(*instructions) * (lines + 1));

    for (int i = 0; i < lines; i++) {
        instructions[i].cur_bsize = 0;
        instructions[i].instruction_id = 0;
    }
    instructions[lines].cur_bsize = -1;
    return instructions;
}

int load_instructions(func *inst, int j, char *args)
{
    int tab_line = 0;

    tab_line = get_tab_line(args);
    inst[j].instruction_id = op_tab[tab_line].code;
    inst[j].parameters = get_params(args, tab_line);
    inst[j].cur_bsize = prog_size(inst, j, *inst[j].parameters);
    return 0;
}

static char *get_args(char *line)
{
    return del_fore_spaces(line);
}

bool load_prog(char **buf, func *inst)
{
    int i = 0;
    int tab_line = 0;
    char *args = NULL;

    if (is_label_pttrn(buf[i]) && valid_label(buf[i]))
        i++;
    for (int j = 0, prm_start = 0; buf[i] != NULL; i++, j++) {
        prm_start = 0;
        if (is_label_pttrn(buf[i]) && valid_label(buf[i])) {
            prm_start = my_strlen_until(buf[i], LABEL_CHARS) + 1;
            if (buf[i][prm_start] == 0 || buf[i][prm_start + 1] == 0) {
                i++;
                prm_start = 0;
            }
            if (buf[i] == NULL)
                return true;
        }
        args = get_args(my_strdup(&buf[i][prm_start]));
        load_instructions(inst, j, args);
    }
    return true;
}
