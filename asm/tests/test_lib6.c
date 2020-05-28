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

Test(is_in_string, testisinstring)
{
    cr_assert_eq(is_in_string("test", 's'), 2);
    cr_assert_eq(is_in_string("fortnite", 'z'), -1);
    cr_assert_eq(is_in_string((void *)0, 's'), -1);
}

Test(is_alphabetic, testisalpha)
{
    cr_assert_eq(is_alphabetic("isalphabetic"), true);
    cr_assert_eq(is_alphabetic("is not alpha"), false);
    cr_assert_eq(is_alphabetic((void *)0), false);
}

Test(is_a_letter, testisaletter)
{
    cr_assert_eq(is_a_letter('c', true), true);
    cr_assert_eq(is_a_letter('D', false), false);
    cr_assert_eq(is_a_letter('D', false), false);
    cr_assert_eq(is_a_letter('\n', false), false);
}

Test(get_last_occurence_of, testlastocc)
{
    char *test = my_strdup("/home/$USER/work/github/perso/teklib");
    char *test2 = (void *)0;
    char *test3 = my_strdup("no occurences !");

    cr_assert_str_eq(get_last_occurence_of(test, '/'), "teklib");
    cr_assert_str_eq(get_last_occurence_of(test3, '/'), "no occurences !");
    cr_assert_eq(get_last_occurence_of(test2, '3'), 0);
}

//number_toolbox.c
Test(my_putnbr, testputnbr, .init = redirect_all)
{
    my_putnbr(-12353);
    cr_assert_stdout_eq_str("-12353");
}