/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_if_only_one_sep, only_one_sep)
{
    char *test1 = my_strdup("je  m'aime    mdr");
    char *test2 = my_strdup("covide 19");

    cr_assert_str_eq(only_one_sep(test1), "je m'aime mdr");
    cr_assert_str_eq(only_one_sep(test2), "covide 19");
    free(test1);
    free(test2);
}

Test(if_cleans, very_clean)
{
    char *test1 = my_strdup("je suis frais");
    char *test2 = my_strdup("  lol  \t\t  mdr\n   ");

    cr_assert_str_eq(very_clean(test1), "je suis frais");
    cr_assert_str_eq(very_clean(test2), "lol mdr");
    free(test1);
    free(test2);
}

Test(test_trunc, my_strtrunc)
{
    char *test1 = my_strdup("le meilleur rappeur est booba");
    char *unvalid_test1 = NULL;

    cr_assert_str_eq(my_strtrunc(test1, 3), "le ");
    cr_assert_eq(my_strtrunc(unvalid_test1, 3), 0);
    cr_assert_str_eq(my_strtrunc(test1, 1000000), test1);
    cr_assert_eq(my_strtrunc(test1, -2), 0);
    free(test1);
}

Test(my_pow, tests_if_pow)
{
    cr_assert_eq(my_pow(2, 2), 4);
    cr_assert_eq(my_pow(1, 0), 1);
    cr_assert_eq(my_pow(34, 1), 34);
}

Test(atoi_base, test_if_atoi_base)
{
    char *test = my_strdup("11");

    cr_assert_eq(atoi_base(test, 2), 3);
    cr_assert_eq(atoi_base(NULL, 3), 0);
}