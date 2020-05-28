/*
** EPITECH PROJECT, 2020
** tests_lib2.c
** File description:
** unit tests for lib
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lib.h"
#include "macros.h"
#include <stddef.h>
#include <stdlib.h>
#include "tests_mygetopt.h"

void redirect_all(void);

void *modify_bool(void *value, UNUSED char *arg)
{
    test_opt_t *structure = (test_opt_t *)value;

    structure->test_bool = true;
    return ((void *)structure);
}

void *modify_int(void *value, char *arg)
{
    test_opt_t *structure = (test_opt_t *)value;

    structure->value = my_getnbr(arg);
    return ((void *)structure);
}

void *success_msg(void *value, UNUSED char *arg)
{
    test_opt_t *structure = (test_opt_t *)value;

    my_putstr("Success\n");
    return ((void *)structure);
}

Test(simple_arg_handling, simplearg, .init = redirect_all)
{
    char **av = tabgen("./bin -b --success", ' ');
    int ac = my_tablen((char const **)av);
    test_opt_t *test = malloc(sizeof(test_opt_t));

    test->value = 0;
    test->test_bool = false;
    cr_assert_eq(my_getopt(ac, av, tests, (void *)test), 0);
    cr_assert_stdout_eq_str("Success\n");
    cr_assert_eq(test->test_bool, true);
    free_tab((void **)av);
    free(test);
}

Test(one_arg_handling, onearg, .init = redirect_all)
{
    char **av = tabgen("./bin -i 15 --success", ' ');
    int ac = my_tablen((char const **)av);
    test_opt_t *test = malloc(sizeof(test_opt_t));

    test->value = 0;
    test->test_bool = false;
    cr_assert_eq(my_getopt(ac, av, tests, (void *)test), 0);
    cr_assert_stdout_eq_str("Success\n");
    cr_assert_eq(test->value, 15);
    free_tab((void **)av);
    free(test);
}

Test(missing_arg, missingarg, .init = redirect_all)
{
    char **av = tabgen("./bin -i --success", ' ');
    int ac = my_tablen((char const **)av);
    test_opt_t *test = malloc(sizeof(test_opt_t));

    test->value = 0;
    test->test_bool = false;
    cr_assert_eq(my_getopt(ac, av, tests, (void *)test), -1);
    cr_assert_eq(test->value, 0);
    free_tab((void **)av);
    free(test);
}

Test(unknown_flag, unknown_flag, .init = redirect_all)
{
    char **av = tabgen("./bin -f --success", ' ');
    int ac = my_tablen((char const **)av);
    test_opt_t *test = malloc(sizeof(test_opt_t));

    test->value = 0;
    test->test_bool = false;
    cr_assert_eq(my_getopt(ac, av, tests, (void *)test), -1);
    cr_assert_eq(test->value, 0);
    free_tab((void **)av);
    free(test);
}

Test(multiple_args, mult_args, .init = redirect_all)
{
    char **av = tabgen("./bin -i 15 file argument", ' ');
    int ac = my_tablen((char const **)av);
    test_opt_t *test = malloc(sizeof(test_opt_t));

    test->value = 0;
    test->test_bool = false;
    cr_assert_eq(my_getopt(ac, av, tests, (void *)test), 0);
    cr_assert_eq(test->value, 15);
    free_tab((void **)av);
    free(test);
}