/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_atoi, test_if_atoi)
{
    char *test1 = my_strdup("mdr");
    char *test2 = my_strdup("-12");

    cr_assert_eq(my_atoi(test1), -1);
    cr_assert_eq(my_atoi(test2), -12);
    test2++;
    cr_assert_eq(my_atoi(test2), 12);
}

Test(intconcat, test_if_concat)
{
    int *tab1 = my_memset(0, 2, sizeof(int));
    int *tab2 = my_memset(1, 1, sizeof(int));
    int *result = intconcat(tab1, tab2);

    cr_assert_eq(result[0], 0);
    cr_assert_eq(result[1], 0);
    cr_assert_eq(result[2], 1);
    cr_assert_eq(result[3], -1);
    tab2 = NULL;
    result = intconcat(tab1, tab2);
    cr_assert_eq(result[0], 0);
    cr_assert_eq(result[1], 0);
    cr_assert_eq(result[2], -1);
    tab2 = my_memset(0, 1, sizeof(int));
    tab1 = NULL;
    cr_assert_eq(result[0], 0);
}

Test(int_2_str, test_if_int_to_str)
{
    cr_assert_str_eq(int_2_str(10), "10");
    cr_assert_str_eq(int_2_str(0), "0");
}

Test(append_int, test_if_append_int)
{
    int *test = my_memset(0, 1, sizeof(int));
    int *result = append_int(test, 2);

    cr_assert_eq(result[0], 0);
    cr_assert_eq(result[1], 2);
    cr_assert_eq(result[2], -1);
}

Test(get_label_def, test_if_get_label_def)
{
    char **tab = malloc(sizeof(char *) * 4);
    char **result = NULL;

    tab[0] = NULL;
    tab[1] = NULL;
    tab[2] = my_strdup("lol:");
    tab[3] = NULL;
    result = get_label_def(tab);
    cr_assert_str_eq(result[0], "lol");
}