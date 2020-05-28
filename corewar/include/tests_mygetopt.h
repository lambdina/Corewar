/*
** EPITECH PROJECT, 2020
** tests_mygetopt.h
** File description:
** used for tests opthandler function header
*/

#include "opt_handler.h"

#ifndef TESTS_OPT_H
#define TESTS_OPT_H

void *modify_bool(void *, char *);
void *display_bool(void *, char *);
void *success_msg(void *, char *);
void *modify_int(void *, char *);

typedef struct tests_opt_s
{
    bool test_bool;
    int value;
} test_opt_t;

static opt_t tests[] =
{
    {&modify_int, true, 'i', "-int"},
    {&modify_bool, false, 'b', "-bool"},
    {&success_msg, false, 0, "-success"},
    {NULL, false, 0, NULL}
};

#endif /* TESTS_OPT_H */