/*
** EPITECH PROJECT, 2020
** tests_utils
** File description:
** criterions tests for 'utils' folder.
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_append_str, append_str)
{
    char **unvalid_tab1 = NULL;
    char *unvalid_str1 = NULL;
    char *valid_str = my_strdup("lol");
    char **test = append_str(unvalid_tab1, valid_str);

    cr_assert_str_eq(test[0], valid_str);
    cr_assert_eq(test[1], 0);
    unvalid_tab1 = malloc(sizeof(char *));
    unvalid_tab1[0] = NULL;
    test = append_str(unvalid_tab1, valid_str);
    cr_assert_str_eq(test[0], valid_str);
    cr_assert_eq(test[1], 0);
    unvalid_tab1[0] = malloc(sizeof(char) * 1);
    unvalid_tab1[0][0] = 0;
    test = append_str(unvalid_tab1, valid_str);
    cr_assert_str_eq(test[0], valid_str);
    test = append_str(test, unvalid_str1);
    cr_assert_str_eq(test[0], "lol");
    cr_assert_eq(test[1], 0);
    free_tab((void **)unvalid_tab1), free_tab((void **)test);
    free(valid_str);
}

Test(test_sep, all_sep_must_be_spaces)
{
    char *test1 = my_strdup("test");
    char *test2 = my_strdup("this is a test");
    char *test3 = my_strdup("this\t\tis a test\n");

    cr_assert_str_eq(all_sep_must_be_spaces(test1), "test");
    cr_assert_str_eq(all_sep_must_be_spaces(test2), "this is a test");
    cr_assert_str_eq(all_sep_must_be_spaces(test3), "this  is a test ");
    free(test1);
    free(test2);
    free(test3);
}

Test(test_front_spaces, del_fore_spaces)
{
    char *test1 = my_strdup("this is a test");
    char *test2 = my_strdup("  test");

    cr_assert_str_eq(del_fore_spaces(test1), "this is a test");
    cr_assert_str_eq(del_fore_spaces(test2), "test");
    free(test1);
    free(test2);
}

Test(test_end_spaces, del_end_spaces)
{
    char *test1 = my_strdup("big butt    ");
    char *test2 = my_strdup("but little boobs");

    cr_assert_str_eq(del_end_spaces(test1), "big butt");
    cr_assert_str_eq(del_end_spaces(test2), "but little boobs");
    free(test1);
    free(test2);
}

Test(test_if_delete_comments, delete_comments)
{
    char *test1 = my_strdup("mdr#lol");
    char *test2 = my_strdup("lol");

    cr_assert_str_eq(delete_comments(test1), "mdr");
    cr_assert_str_eq(delete_comments(test2), "lol");
    free(test1);
    free(test2);
}
