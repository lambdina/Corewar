/*
** EPITECH PROJECT, 2020
** tests_lib2.c
** File description:
** unit tests for lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <stddef.h>

void redirect_all(void);

//misc.c
Test(test_if_free, testfree)
{
    char *asd = my_strdup("fortnite");
    char *lol = (void *)0;

    test_if_free(asd);
    test_if_free(lol);
}