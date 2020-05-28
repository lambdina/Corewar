/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_param_reg, test_if_param_is_reg)
{
    int size_params = 2;
    int idx_param = 1;
    int op_tab_line = 2;

    cr_assert_eq(is_param_ind(op_tab_line, size_params, idx_param), true);
    idx_param--;
    cr_assert_eq(is_param_ind(op_tab_line, size_params, idx_param), false);
}

Test(check_type, test_if_check_type)
{
    int *size_params = my_memset(0, 2, sizeof(int));
    int op_tab_line = 1;

    size_params[0] = 2;
    size_params[1] = 1;
    cr_assert_eq(check_type(size_params, op_tab_line), true);
    size_params[1] = 2;
    cr_assert_eq(check_type(size_params, op_tab_line), false);
}

Test(determine_type, test_if_determines_type)
{
    cr_assert_str_eq(determine_type(1), "01");
    cr_assert_str_eq(determine_type(2), "11");
    cr_assert_str_eq(determine_type(4), "10");
}

Test(get_bsize, tests_if_gets_b_size)
{
    char *line = my_strdup("ld %1, r1");
    int *result_1 = get_bsize(line);

    cr_assert_eq(result_1[0], 4);
    cr_assert_eq(result_1[1], 1);
    cr_assert_eq(result_1[2], -1);
    line = my_strdup("zjmp %:mdr");
    result_1 = get_bsize(line);
    cr_assert_eq(result_1[0], 2);
    cr_assert_eq(result_1[1], -1);
}

Test(get_nb_bytes_line, tests_if_get_nb_bytes_line)
{
    func *inst_1 = malloc(sizeof(func));
    func *inst_2 = malloc(sizeof(func) * 3);

    inst_1->cur_bsize = 2312;
    inst_2[0].cur_bsize = 7;
    inst_2[1].cur_bsize = 14;
    inst_2[2].cur_bsize = -1;
    cr_assert_eq(get_nb_bytes_line(inst_1, 0), 0);
    cr_assert_eq(get_nb_bytes_line(inst_2, 1), 7);
}