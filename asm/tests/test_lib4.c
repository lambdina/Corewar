/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <stddef.h>

Test(my_strlen, test_my_strlen)
{
    cr_assert_eq(my_strlen("test"), 4);
    cr_assert_eq(my_strlen((void *)0), 0);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen("fortnite\n"), 9);
}

Test(my_tablen, test_my_tablen)
{
    char **tab1 = tabgen("this is a test.", ' ');

    cr_assert_eq(my_tablen((char const **)tab1), 4);
    free_tab((void **)tab1);
    cr_assert_eq(my_tablen((void *)0), 0);
}

//malloc_toolbox.c
Test(my_strdup, test_strdup)
{
    char *asd = my_strdup("asdfortnite");
    char *lol = my_strdup((void *)0);

    cr_assert_str_eq("asdfortnite", asd);
    cr_assert_eq(0, lol);
    free(asd);
}

Test(my_strcat, test_strcat)
{
    char *asd = my_strcat("this is", " a test");
    char *a = my_strcat("this is", (void *)0);
    char *s = my_strcat((void *)0, " a test");

    cr_assert_str_eq("this is a test", asd);
    cr_assert_str_eq(a, "this is");
    cr_assert_str_eq(s, " a test");
    free(asd);
    free(a);
    free(s);
}

Test(my_itoa, test_itoa)
{
    cr_assert_str_eq(my_itoa(15), "15");
    cr_assert_str_eq(my_itoa(0), "0");
    cr_assert_str_eq(my_itoa(-666), "-666");
    cr_assert_str_eq(my_itoa(-7), "-7");
}