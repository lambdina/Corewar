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

Test(my_putnbr_base, testputnbrbase, .init = redirect_all)
{
    my_putnbr_base(12, "01234567");
    cr_assert_stdout_eq_str("14");
}

//modify_strings.c
Test(set_to_lowercase, settolower)
{
    char *t = my_strdup("Paris Saint-Germain fucking SUCKS");
    char *d = my_strdup("LOL");
    char *f = (void *)0;

    cr_assert_str_eq(set_to_lowercase(t), "paris saint-germain fucking sucks");
    cr_assert_str_eq(set_to_lowercase(d), "lol");
    cr_assert_eq(set_to_lowercase(f), 0);
}

Test(set_to_uppercase, settoupper)
{
    char *t = my_strdup("Paris Saint-Germain fucking SUCKS");
    char *d = my_strdup("lol");
    char *f = (void *)0;

    cr_assert_str_eq(set_to_uppercase(t), "PARIS SAINT-GERMAIN FUCKING SUCKS");
    cr_assert_str_eq(set_to_uppercase(d), "LOL");
    cr_assert_eq(set_to_uppercase(f), 0);
}

Test(my_revstr, testrevstr)
{
    char *y = my_strdup("yes");
    char *f = my_strdup("fortnite");

    cr_assert_str_eq(my_revstr(y), "sey");
    cr_assert_str_eq(my_revstr(f), "etintrof");
    cr_assert_eq(my_revstr((void *)0), 0);
}

//do_op.c
Test(do_op, doop)
{
    cr_assert_eq(do_op(5, 12, '+'), 17);
    cr_assert_eq(do_op(5, 17, '-'), -12);
    cr_assert_eq(do_op(3, 5, '*'), 15);
    cr_assert_eq(do_op(15, 3, '/'), 5);
    cr_assert_eq(do_op(12, 5, '%'), 2);
}