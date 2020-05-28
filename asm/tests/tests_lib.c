/*
** EPITECH PROJECT, 2019
** test_lib.c
** File description:
** functions testing librairy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include <stddef.h>

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//write_toolbox.c
Test(my_putchar, test_putchar, .init = redirect_all)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putstr, tests_putstr, .init = redirect_all)
{
    my_putstr("this is a string.\n");
    cr_assert_stdout_eq_str("this is a string.\n");
}

Test(my_puterror, test_puterror, .init = redirect_all)
{
    my_puterror("This is a string on the error canal.\n");
    cr_assert_stderr_eq_str("This is a string on the error canal.\n");
}

//get_len_toolbox.c
Test(my_nblen, test_nb_len)
{
    cr_assert_eq(my_nblen(15), 2);
    cr_assert_eq(my_nblen(155), 3);
    cr_assert_eq(my_nblen(-12), 2);
    cr_assert_eq(my_nblen(0), 0);
}
