/*
** EPITECH PROJECT, 2020
** input_handling.h
** File description:
** input_handling module header
*/

#include <unistd.h>
#include "common_types.h"

#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

typedef struct status_s
{
    int load_address;
    int program_nbr;
    int nbr_cycles;
} stats_t;

// convert_base.c
char *convert_base(char *, cchar_t, cchar_t);

// functions_arg_handling.c
bool is_corewar_file(char *filename);
void *edit_nbr_cycles(void *, char *arg);
void *edit_prog_number(void *, char *arg);
void *load_address(void *, char *arg);

#endif /* INPUT_HANDLING_H */
