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

Test(free_tab, test_free_tab)
{
    char **tab = tabgen("i love being alive", ' ');
    int **inttab = malloc(sizeof(int *) * 3);
    char **lol = (void *)0;

    inttab[0] = malloc(sizeof(int) * 2);
    inttab[0][0] = 1;
    inttab[0][1] = 15;
    inttab[1] = malloc(sizeof(int) * 1);
    inttab[1][0] = 17;
    inttab[2] = (void *)0;
    free_tab((void **)tab);
    free_tab((void **)inttab);
    free_tab((void **)lol);
}

Test(swap, testswap, .init = redirect_all)
{
    int asd = 15;
    int lol = 13;

    swap(&asd, &lol);
    cr_assert_eq(lol, 15);
    cr_assert_eq(asd, 13);
}

Test(swap_array, testswaparray)
{
    char *asd = my_strdup("asd");
    char *lol = my_strdup("lol");

    swap_array((void **)&asd, (void **)&lol);
    cr_assert_str_eq(asd, "lol");
    cr_assert_str_eq(lol, "asd");
    free(asd);
    free(lol);
}

Test(swapc, swapchar, .init = redirect_all)
{
    char a = 'a';
    char b = 'b';

    swapc(&a, &b);
    my_putchar(a);
    my_putchar(b);
    cr_assert_stdout_eq_str("ba");
}

//check_string_toolbox.c
Test(is_num, testisnum)
{
    cr_assert_eq(is_num("-14"), true);
    cr_assert_eq(is_num("asd"), false);
    cr_assert_eq(is_num((void *)0), false);
    cr_assert_eq(is_num("1235"), true);
}