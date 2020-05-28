/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main file
*/

#include "macros.h"
#include "lib.h"
#include "asm.h"
#include "struct.h"
#include "istl/list.h"
#include "istl/astar.h"

int help(int return_value)
{
    write(2, "USAGE\n./asm file_name[.s]\nDESCRIPTION\n", 38);
    write(2, "file_name file in assembly language to be converted into", 57);
    write(2, "file_name.cor, an executable in the Virtual Machine.\n", 53);
    return return_value;
}

static int exit_success(char **buff, func *fortnite)
{
    free_tab((void **)buff);
    for (int i = 0; fortnite[i].cur_bsize > 0; i++) {
        free(fortnite[i].parameters->args);
        free(fortnite[i].parameters->size_per_param);
        free(fortnite[i].parameters->type);
        free(fortnite[i].parameters);
    }
    free(fortnite);
    return 0;
}

int main(int argc, char **argv)
{
    char **buf = NULL;
    header_t head;
    func *instruct = NULL;
    int fd = 0;

    if (argc != 2)
        return help(84);
    else if (!my_strcmp(argv[1], "-h"))
        return help(0);
    buf = open_and_read(argv[1], &check_filename_pttrn);
    if (buf == NULL)
        return help(84);
    init_header(&head, buf);
    multiples_def_lbl(buf);
    instruct = init_struct(&buf[2]);
    load_prog(&buf[2], instruct);
    instruct = get_label_pos(&buf[2], instruct);
    write_core(argv[1], head, instruct, my_tablen((char const **)&buf[2]));
    return (exit_success(buf, instruct));
}
