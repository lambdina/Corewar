/*
** EPITECH PROJECT, 2020
** tests_inst
** File description:
** criterion tests for isntructions folder.
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_param_ind, test_if_param_is_indirect)
{
    int size_params = 2;
    int idx_param = 0;
    int op_tab_line = 1;

    cr_assert_eq(is_param_ind(op_tab_line, size_params, idx_param), true);
    idx_param++;
    cr_assert_eq(is_param_ind(op_tab_line, size_params, idx_param), false);
}

Test(is_param_dir, test_if_param_is_direct)
{
    int size_params = 4;
    int idx_param = 0;
    int op_tab_line = 1;

    cr_assert_eq(is_param_dir(op_tab_line, size_params, idx_param), true);
    idx_param++;
    cr_assert_eq(is_param_dir(op_tab_line, size_params, idx_param), false);
}