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

//conversion_toolbox.c
Test(my_getnbr_base, gnbase)
{
    cr_assert_str_eq(my_getnbr_base(12, "01234567"), "14");
    cr_assert_str_eq(my_getnbr_base(10, "01"), "1010");
    cr_assert_str_eq(my_getnbr_base(236, "0123456789abcdef"), "ec");
    cr_assert_str_eq(my_getnbr_base(12, "0123456789ABCDEF"), "C");
    cr_assert_eq(my_getnbr_base(12, (void *)0), 0);
}

Test(my_getnbr, gnbr)
{
    cr_assert_eq(my_getnbr((void *)0), 0);
    cr_assert_eq(my_getnbr("17"), 17);
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr(""), 0);
    cr_assert_eq(my_getnbr("asd123"), 0);
    cr_assert_eq(my_getnbr("123asc"), 123);
    cr_assert_eq(my_getnbr("---12"), -12);
    cr_assert_eq(my_getnbr("432823748324"), 0);
}

//tabgen.c
Test(tabgen, tbgn)
{
    char **tab = tabgen((void *)0, '\n');
    char **tab2 = tabgen("lol i love this game", ' ');

    cr_assert_eq(tab, 0);
    cr_assert_str_eq(tab2[0], "lol");
    free_tab((void **)tab2);
}

//copy_toolbox.c
Test(my_strcpy, strcp)
{
    char *result = malloc(sizeof(char) * 6);

    cr_assert_str_eq(my_strcpy(result, "hello"), "hello");
    cr_assert_eq(my_strcpy(result, (void *)0), 0);
    free(result);
}

Test(my_strncpy, strncp)
{
    char *result = malloc(sizeof(char) * 8);

    cr_assert_str_eq(my_strncpy(result, "hello world !", 5), "hello");
    cr_assert_eq(my_strncpy(result, (void *)0, 12), 0);
    cr_assert_eq(my_strncpy(result, "hello world !", -1), 0);
    free(result);
}