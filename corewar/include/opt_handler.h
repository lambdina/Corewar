/*
** EPITECH PROJECT, 2020
** opt_handler.h
** File description:
** opthandler function header
*/

#ifndef OPTHANDER_H
#define OPTHANDLER_H

#include <unistd.h>
#include <stdbool.h>

typedef struct opt_s opt_t;
typedef struct opt_s
{
    void *(*function)(void *data, char *arg);
    bool expect_optarg;
    char short_option;
    char *long_option;
} opt_t;

// opthandler_main.c
int my_getopt(int ac, char **av, void *data);

#endif /* OPT_HANDLER */
